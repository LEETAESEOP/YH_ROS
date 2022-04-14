#include "ros/ros.h" // ROS 헤더파일
#include "yh_sum/yh_sum_msg.h"

int A, res, pre_data = 0;

void msgCallback(const yh_sum::yh_sum_msg::ConstPtr& msg)
{   
    int res = 0;
    // A는 현재 들어온 값, pre_data는 이전에 저장된 값, res는 최종 더한 값.
    // A = msg->data;
    // res = A + pre_data;
    // pre_data = A;
    res = msg->data + pre_data;
    pre_data = msg->data;

    ROS_INFO("receive msg = %d", msg->data);
    ROS_INFO("result = %d", res);
}

//메인 함수
int main(int argc, char **argv)
{
    ros::init(argc, argv, "yh_sum_sub"); // 노드 이름 초기화
    ros::NodeHandle nh;

    ros::Subscriber my_sub = nh.subscribe("yh_sum_topic", 100, msgCallback);

    ros::spin();
    return 0;
}