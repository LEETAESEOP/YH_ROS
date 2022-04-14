#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

// 메인 함수
int main(int argc, char ** argv)
{
    ros::init(argc, argv, "yh_turtle_triangle");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);
    ros::Rate loop_rate(1);

    geometry_msgs::Twist msg;
    
    // msg.linear.x = 5;
    //  msg.linear.y = 5;

    
    // 사각형
        while (ros::ok())
    {
        msg.linear.x = 0;
        msg.angular.z = 1.575;
        pub.publish(msg); // pub이 msg를 퍼블리시한다.
        loop_rate.sleep();  // 1초에 한번씩 명령

        msg.linear.x = 3;
        msg.angular.z = 0;
        pub.publish(msg); // pub이 msg를 퍼블리시한다.
        loop_rate.sleep();  // 1초에 한번씩 명령

    }

    // 삼각형
    // while (ros::ok())
    // {
    //     msg.linear.x = 3;
    //     msg.angular.z = 0;
    //     pub.publish(msg); // pub이 msg를 퍼블리시한다.
    //     loop_rate.sleep();  // 1초에 한번씩 명령

    //     msg.linear.x = 0;
    //     msg.angular.z = 2.1;
    //     pub.publish(msg); // pub이 msg를 퍼블리시한다.
    //     loop_rate.sleep();  // 1초에 한번씩 명령
    // }

    return 0;
}

