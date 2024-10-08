#include <rclcpp/rclcpp.hpp>
#include <image_transport/image_transport.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
#include <cmath>

class LineDetectionNode : public rclcpp::Node
{
public:
    LineDetectionNode() : rclcpp::Node("line_detection_node")
    {
        // Declare parameters for input and output topics
        RCLCPP_INFO(this->get_logger(), "CP1");
        this->declare_parameter<std::string>("input_topic", "input_image");
        this->declare_parameter<std::string>("output_topic", "line_detection_image");
        this->declare_parameter<std::string>("line_mask_topic", "line_mask_image");

        // Get parameters
        RCLCPP_INFO(this->get_logger(), "CP2");
        input_topic_ = this->get_parameter("input_topic").as_string();
        output_topic_ = this->get_parameter("output_topic").as_string();
        line_mask_topic_ = this->get_parameter("line_mask_topic").as_string();

        subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
            input_topic_, 10, std::bind(&LineDetectionNode::image_callback, this, std::placeholders::_1));
        
        RCLCPP_INFO(this->get_logger(), "Line Detection Node has started.");
        RCLCPP_INFO(this->get_logger(), "Subscribing to: %s", input_topic_.c_str());
        RCLCPP_INFO(this->get_logger(), "Publishing to: %s", output_topic_.c_str());
        RCLCPP_INFO(this->get_logger(), "Publishing mask to: %s", line_mask_topic_.c_str());
    }
    ~LineDetectionNode()
    {
        // Clean up image_transport and publishers
        RCLCPP_INFO(this->get_logger(), "Shutting down node and cleaning up resources.");
        image_transport_.reset();  // Ensure image transport is cleaned up
        publisher_overlay_.shutdown();  // Shutdown publisher explicitly
    }

private:
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        // Initialize image transport only once after the node is fully constructed
        if (!image_transport_initialized_) {
            RCLCPP_INFO(this->get_logger(), "Initializing image transport");
            image_transport_ = std::make_shared<image_transport::ImageTransport>(shared_from_this());
            publisher_overlay_ = image_transport_->advertise(output_topic_, 10);
            publisher_mask_overlay_ = image_transport_->advertise(line_mask_topic_, 10);
            image_transport_initialized_ = true;
            RCLCPP_INFO(this->get_logger(), "Init success");
        }
        try
        {
            // Convert ROS Image message to OpenCV image
            cv::Mat frame = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8)->image;
            cv::Mat frame_resized;
            cv::resize(frame, frame_resized, cv::Size(320, 320));

            // Find lines in the image
            cv::Mat lines_mask = find_lines(frame_resized);

            // Overlay the mask on the original image
            cv::Mat overlay_image = weighted_img(lines_mask, frame_resized, 0.5, 0.5);

            // Publish the overlay image
            sensor_msgs::msg::Image::SharedPtr overlay_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", overlay_image).toImageMsg();
            publisher_overlay_.publish(overlay_msg);
            sensor_msgs::msg::Image::SharedPtr overlay_mask_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", lines_mask).toImageMsg();
            publisher_mask_overlay_.publish(overlay_mask_msg);
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "Error processing image: %s", e.what());
        }
    }

    cv::Mat find_lines(const cv::Mat &img)
    {
        cv::Mat gray_image;
        cv::cvtColor(img, gray_image, cv::COLOR_BGR2GRAY);
        cv::Mat blurred_image;
        cv::GaussianBlur(gray_image, blurred_image, cv::Size(9, 9), 2);
        cv::Mat edges_image;
        cv::Canny(blurred_image, edges_image, 50, 120);

        double rho_resolution = 1;
        double theta_resolution = CV_PI / 180;
        int threshold = 155;

        std::vector<cv::Vec2f> hough_lines;
        cv::HoughLines(edges_image, hough_lines, rho_resolution, theta_resolution, threshold);

        if (hough_lines.empty())
        {
            return cv::Mat::zeros(img.size(), img.type());
        }

        cv::Mat hough_lines_image = cv::Mat::zeros(img.size(), img.type());
        draw_lines(hough_lines_image, hough_lines);
        return hough_lines_image;
    }

    void draw_lines(cv::Mat &img, const std::vector<cv::Vec2f> &hough_lines, const cv::Scalar &color = cv::Scalar(0, 255, 0), int thickness = 4)
    {
        for (const auto &line : hough_lines)
        {
            float rho = line[0];
            float theta = line[1];
            double a = cos(theta);
            double b = sin(theta);
            double x0 = a * rho;
            double y0 = b * rho;
            cv::Point pt1(cvRound(x0 + 10000 * (-b)), cvRound(y0 + 10000 * (a)));
            cv::Point pt2(cvRound(x0 - 10000 * (-b)), cvRound(y0 - 10000 * (a)));
            cv::line(img, pt1, pt2, color, thickness);
        }
    }

    cv::Mat weighted_img(const cv::Mat &img, const cv::Mat &initial_img, double alpha = 0.8, double beta = 1.0, double gamma = 0.0)
    {
        cv::Mat result;
        cv::addWeighted(initial_img, alpha, img, beta, gamma, result);
        return result;
    }

    
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
    image_transport::Publisher publisher_overlay_;
    image_transport::Publisher publisher_mask_overlay_;
    std::shared_ptr<image_transport::ImageTransport> image_transport_;

    bool image_transport_initialized_;    // Flag to ensure image transport is initialized once

    // Parameters for topics
    std::string input_topic_;
    std::string output_topic_;
    std::string line_mask_topic_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<LineDetectionNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}