#include "ros/ros.h" // ROS 헤더 파일
#include "yh_star/yh_star_msg.h"

void msgCallback(const yh_star::yh_star_msg::ConstPtr& msg)
{
    ROS_INFO("receive msg = %d", msg->data);
    if (msg->data %2 == 1)
    {
       for (int i=1; i<= msg->data; i++)
            {
                for(int j = (msg->data-i); j<= (msg->data/2); j++)
                {
                printf("%s", "*");
                }
                printf("\n");
            }

         for (int i=(msg->data)/2; i>=1; i--)
            {
                for(int j = 1; j <= i; j++)
                {
                printf("%s", "*");
                }
                printf("\n");
            }
    }
    else
    {
        for (int i=1; i<= msg->data; i++)
            {
                for(int j = (msg->data-i); j<= (msg->data/2)-1; j++)
                {
                printf("%s", "*");
                }
                printf("\n");
            }

         for (int i=(msg->data)/2; i>=1; i--)
            {
                for(int j = 1; j <= i; j++)
                {
                printf("%s", "*");
                }
                printf("\n");
            }
    }
}

//메인 함수
int main(int argc, char **argv)
{
    ros::init(argc, argv, "yh_star_sub"); // 노드 이름 초기화
    ros::NodeHandle nh;

    ros::Subscriber my_sub = nh.subscribe("yh_star_topic", 100, msgCallback);

    ros::spin();
    return 0;
}