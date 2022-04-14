#include "ros/ros.h"
#include "yh_tutorial_4/yh_msg_4.h" 

//작동순서1
ros::Publisher my_pub;

//작동순서3
void msgCallback(const yh_tutorial_4::yh_msg_4::ConstPtr& msg)
{   
    if (msg->data % 5 == 0)
    {
       my_pub.publish(msg); 
    }
}


//메인 함수, 작동순서2
int main(int argc, char **argv)
{
    ros::init(argc, argv, "yh_pub_sub_4");
    ros::NodeHandle nh;

    my_pub = nh.advertise<yh_tutorial_4::yh_msg_4>("yh_topic_44", 100);
    ros::Subscriber my_sub = nh.subscribe("yh_topic_4", 100, msgCallback);
    ros::spin();
    return 0;
}