#include "ros/ros.h"
#include "yh_sum/yh_sum_msg.h"

int A, res, pre_data = 0;

class MyClass
{
    // public 에는 보통 상수가 들어가고, private 에는 보통 변수가 들어감.
    // public 은 외부에서 접근 가능, private는 외부에서 접근 불가.
    public:
        // 아래 MyClass()는 파이썬의 __init__(self): 과 같은 부분임
        MyClass()
        {
            sub = nh.subscribe("yh_sum_topic", 100, &MyClass::msgCallback, this); // this == 자신을 가리키는 포인터
        }

        void msgCallback(const yh_sum::yh_sum_msg::ConstPtr& msg)
        {   
        int res = 0;
        res = msg->data + pre_data;
        pre_data = msg->data;

        ROS_INFO("receive msg = %d", msg->data);
        ROS_INFO("result = %d", res);
        }

    private:
        ros::NodeHandle nh;
        ros::Subscriber sub;
        int old_data = 0;
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "yh_sum_sub");
    MyClass my_class;
    ros::spin();
    return 0;
}