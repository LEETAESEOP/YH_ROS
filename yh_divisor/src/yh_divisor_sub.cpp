#include "ros/ros.h" // ROS 헤더 파일
#include "yh_divisor/yh_divisor_msg.h"

void msgCallback(const yh_divisor::yh_divisor_msg::ConstPtr& msg)
{
    ROS_INFO("receive msg = %d", msg->data);
       for (int i=1; i<= msg->data; i++)
            {
                if (msg->data % i == 0)
                    {
                        printf("%d\n", i);
                    }
            }
}

//메인 함수
int main(int argc, char **argv)
{
    ros::init(argc, argv, "yh_divisor_sub"); // 노드 이름 초기화
    ros::NodeHandle nh;

    ros::Subscriber my_sub = nh.subscribe("yh_divisor_topic", 100, msgCallback);

    ros::spin();
    return 0;
}