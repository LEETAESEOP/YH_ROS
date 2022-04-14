#include "ros/ros.h"
#include "yh_tutorial_4/yh_msg_4.h" 

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "yh_pub_4"); 
    ros::NodeHandle nh;

    ros::Publisher my_pub = nh.advertise<yh_tutorial_4::yh_msg_4>("yh_topic_4", 100);
    ros::Rate loop_rate(10);

    yh_tutorial_4::yh_msg_4 msg;
    int cnt = 0;

    while (ros::ok())
    {
        msg.stamp = ros::Time::now(); // 현재 시간을 msg의 stamp에 담는다.
        msg.data = cnt; // cnt의 변수값을 msg의 data에 담는다.
        my_pub.publish(msg); // my_pub이 msg를 퍼블리시한다.
        cnt ++;
        loop_rate.sleep(); // 위에서 정한 주기에 따라 sleep 한다. (잠깐 멈추도록 함)
    }
    
    return 0;
}
