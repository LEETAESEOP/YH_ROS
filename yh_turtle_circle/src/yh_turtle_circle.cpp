#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

// 메인 함수
int main(int argc, char ** argv)
{
    ros::init(argc, argv, "yh_turtle_circle");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);
    ros::Rate loop_rate(10);

    geometry_msgs::Twist msg;
    int r = 3;   // n = 원의 반지름
    msg.angular.z = 6.3;
    msg.linear.x = r*(2*3.14);
    // msg.linear.x = 5;
    //  msg.linear.y = 5;

    while (ros::ok())
    {
        pub.publish(msg); // pub이 msg를 퍼블리시한다.
        loop_rate.sleep();
    }
    
    return 0;
}

