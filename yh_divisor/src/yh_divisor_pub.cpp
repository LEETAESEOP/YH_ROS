#include "ros/ros.h" // ROS 헤더파일
#include "yh_divisor/yh_divisor_msg.h"

// 메인 함수
int main(int argc, char ** argv)
{
    ros::init(argc, argv, "yh_divisor_pub");
    ros::NodeHandle nh;
    ros::Publisher my_pub = nh.advertise<yh_divisor::yh_divisor_msg>("yh_divisor_topic", 100);
    ros::Rate loop_rate(1);

    yh_divisor::yh_divisor_msg msg;
    int cnt = 0;

    while (ros::ok())
    {
        msg.stamp = ros::Time::now(); // 현재 시간을 msg의 stamp에 담는다.
        msg.data = cnt; // cnt의 변수값을 msg의 data에 담는다.
        ROS_INFO("send msg = %d", msg.data); // data를 표시한다
        cnt ++;
        my_pub.publish(msg); // my_pub이 msg를 퍼블리시한다.
        loop_rate.sleep(); // 위에서 정한 주기에 따라 sleep 한다. (잠깐 멈추도록 함)
    }
    
    return 0;
}

