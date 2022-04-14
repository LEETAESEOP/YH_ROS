#include "ros/ros.h"
#include "yh_tutorial_4/yh_msg_4.h"

// 작동순서2
void msgCallback(const yh_tutorial_4::yh_msg_4::ConstPtr& msg)
{   
    ROS_INFO("%d", msg->stamp.sec);
    ROS_INFO("%d", msg->stamp.nsec);
    ROS_INFO("%d", msg->data);
}


//메인 함수, 작동순서1
int main(int argc, char **argv)
{
    ros::init(argc, argv, "yh_sub_4");
    ros::NodeHandle nh;
    ros::Subscriber my_sub = nh.subscribe("yh_topic_44", 100, msgCallback);
    ros::spin();
    return 0;
}