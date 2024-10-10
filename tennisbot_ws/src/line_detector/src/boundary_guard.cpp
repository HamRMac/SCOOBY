#include <rclcpp/rclcpp.hpp>
#include <image_transport/image_transport.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <opencv2/opencv.hpp>
#include <geometry_msgs/msg/twist.hpp>

class BoundaryGuardNode : public rclcpp::Node
{
public:
    BoundaryGuardNode() : rclcpp::Node("boundary_guard_node")
    {
        // Declare parameters for input topic and twist message publishing
        this->declare_parameter<std::string>("line_mask_topic", "line_mask_image");
        this->declare_parameter<std::string>("cmd_vel_topic", "cmd_vel_boundary_guard");
        this->declare_parameter<int>("bottom_portion_height", 40); // Height of the bottom portion to analyze in pixels

        // Get parameters
        line_mask_topic_ = this->get_parameter("line_mask_topic").as_string();
        cmd_vel_topic_ = this->get_parameter("cmd_vel_topic").as_string();
        bottom_portion_height_ = this->get_parameter("bottom_portion_height").as_int();

        subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
            line_mask_topic_, 10, std::bind(&BoundaryGuardNode::image_callback, this, std::placeholders::_1));

        cmd_vel_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(cmd_vel_topic_, 10);

        RCLCPP_INFO(this->get_logger(), "Boundary Guard Node has started.");
        RCLCPP_INFO(this->get_logger(), "Subscribing to: %s", line_mask_topic_.c_str());
        RCLCPP_INFO(this->get_logger(), "Publishing commands to: %s", cmd_vel_topic_.c_str());
    }

private:
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        try
        {
            // Convert ROS Image message to OpenCV image
            cv::Mat line_mask = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8)->image;

            // Define bottom portion of the image to analyze
            int height = line_mask.rows;
            int width = line_mask.cols;
            int bottom_start = height - bottom_portion_height_;
            if (bottom_start < 0) bottom_start = 0;
            cv::Rect bottom_region(0, bottom_start, width, bottom_portion_height_);
            cv::Mat bottom_image = line_mask(bottom_region);

            // Split the bottom image into left and right halves
            cv::Rect left_region(0, 0, width / 2, bottom_image.rows);
            cv::Rect right_region(width / 2, 0, width / 2, bottom_image.rows);

            cv::Mat left_half = bottom_image(left_region);
            cv::Mat right_half = bottom_image(right_region);

            // Check for green pixels in both halves
            bool green_in_left = check_for_green(left_half);
            bool green_in_right = check_for_green(right_half);

            if (green_in_left || green_in_right)
            {
                geometry_msgs::msg::Twist twist_msg;

                // Determine turning direction based on the presence of green pixels
                if (green_in_left && green_in_right)
                {
                    RCLCPP_INFO(this->get_logger(), "Lines detected in both halves. Turning right.");
                    twist_msg.angular.z = -2.5; // Turn to the right
                }
                else if (green_in_left)
                {
                    RCLCPP_INFO(this->get_logger(), "Line detected in left half. Turning right.");
                    twist_msg.angular.z = -2.5; // Turn to the right
                }
                else if (green_in_right)
                {
                    RCLCPP_INFO(this->get_logger(), "Line detected in right half. Turning left.");
                    twist_msg.angular.z = 2.5; // Turn to the left
                }

                // Publish the twist message
                cmd_vel_publisher_->publish(twist_msg);
            }
            /*else
            {
                RCLCPP_INFO(this->get_logger(), "No green detected. Not sending any command.");
            }*/
        }
        catch (const std::exception &e)
        {
            RCLCPP_ERROR(this->get_logger(), "Error processing image: %s", e.what());
        }
    }

    bool check_for_green(const cv::Mat &img)
    {
        // Check for pure green color (BGR: 0, 255, 0)
        cv::Mat green_mask;
        cv::inRange(img, cv::Scalar(0, 255, 0), cv::Scalar(0, 255, 0), green_mask);

        return cv::countNonZero(green_mask) > 0;
    }

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher_;

    // Parameters for topics and processing
    std::string line_mask_topic_;
    std::string cmd_vel_topic_;
    int bottom_portion_height_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<BoundaryGuardNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}