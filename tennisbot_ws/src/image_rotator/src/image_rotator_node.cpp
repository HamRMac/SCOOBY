#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.hpp>

class ImageRotatorNode : public rclcpp::Node
{
public:
    ImageRotatorNode()
        : Node("image_rotator_node"),
          prev_time_(this->get_clock()->now()),
          last_fps_log_time_(this->get_clock()->now()),
          image_transport_initialized_(false)  // Initialize FPS log time and flag
    {
        // Declare parameters for input and output topics
        RCLCPP_INFO(this->get_logger(), "CP1");
        this->declare_parameter<std::string>("input_topic", "input_image");
        this->declare_parameter<std::string>("output_topic", "rotated_image");

        // Get parameters
        RCLCPP_INFO(this->get_logger(), "CP2");
        input_topic_ = this->get_parameter("input_topic").as_string();
        output_topic_ = this->get_parameter("output_topic").as_string();

        // Subscriber to the input image topic
        RCLCPP_INFO(this->get_logger(), "CP3");
        image_subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
            input_topic_, 10, std::bind(&ImageRotatorNode::image_callback, this, std::placeholders::_1));

        RCLCPP_INFO(this->get_logger(), "Image rotator node has been started.");
        RCLCPP_INFO(this->get_logger(), "Subscribing to: %s", input_topic_.c_str());
        RCLCPP_INFO(this->get_logger(), "Publishing to: %s", output_topic_.c_str());
    }
    ~ImageRotatorNode()
    {
        // Clean up image_transport and publishers
        RCLCPP_INFO(this->get_logger(), "Shutting down node and cleaning up resources.");
        image_transport_.reset();  // Ensure image transport is cleaned up
        compressed_image_publisher_.shutdown();  // Shutdown publisher explicitly
    }

private:
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        // Initialize image transport only once after the node is fully constructed
        if (!image_transport_initialized_) {
            RCLCPP_INFO(this->get_logger(), "Initializing image transport");
            image_transport_ = std::make_shared<image_transport::ImageTransport>(shared_from_this());
            compressed_image_publisher_ = image_transport_->advertise(output_topic_, 10);
            image_transport_initialized_ = true;
            RCLCPP_INFO(this->get_logger(), "Init success");
        }

        // Time measurement for FPS calculation
        rclcpp::Time current_time = this->get_clock()->now();
        double time_diff = (current_time - prev_time_).seconds();
        double fps = 1.0 / time_diff;
        prev_time_ = current_time;

        // Only log FPS every few seconds
        if ((current_time - last_fps_log_time_).seconds() >= 5.0) {
            RCLCPP_INFO(this->get_logger(), "FPS: %.2f", fps);
            last_fps_log_time_ = current_time;
        }

        // Convert the ROS image message to OpenCV image
        cv_bridge::CvImagePtr cv_ptr;
        try
        {
            cv_ptr = cv_bridge::toCvCopy(msg, "bgr8");
        }
        catch (cv_bridge::Exception& e)
        {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
            return;
        }

        // Rotate the image by 180 degrees
        cv::Mat rotated_image;
        cv::rotate(cv_ptr->image, rotated_image, cv::ROTATE_180);

        // Convert the rotated image back to a ROS Image message
        sensor_msgs::msg::Image::SharedPtr rotated_msg = cv_bridge::CvImage(
            msg->header, "bgr8", rotated_image).toImageMsg();

        // Publish the rotated image
        sensor_msgs::msg::Image::SharedPtr compressed_image_msg = cv_bridge::CvImage(
            msg->header, "bgr8", rotated_image).toImageMsg();
        compressed_image_publisher_.publish(*compressed_image_msg);

        //RCLCPP_INFO(this->get_logger(), "Published rotated and compressed images.");
    }

    // Subscribers and Publishers
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscription_;
    image_transport::Publisher compressed_image_publisher_;

    std::shared_ptr<image_transport::ImageTransport> image_transport_;

    // For FPS calculation
    rclcpp::Time prev_time_;              // Tracks the time of the previous frame
    rclcpp::Time last_fps_log_time_;      // Tracks the last time FPS was logged

    bool image_transport_initialized_;    // Flag to ensure image transport is initialized once

    // Parameters for topics
    std::string input_topic_;
    std::string output_topic_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ImageRotatorNode>();

    // Spin the node
    rclcpp::spin(node);
    
    rclcpp::shutdown();
    return 0;
}
