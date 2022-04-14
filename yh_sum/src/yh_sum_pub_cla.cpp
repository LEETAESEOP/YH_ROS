#include "ros/ros.h" // ROS 헤더파일
#include "yh_sum/yh_sum_msg.h"

class MyClass
{
    public:
        MyClass();
        void run();

    private:
        ros::NodeHandle nh;
        ros::Publisher pub;
        int cnt = 0;
        yh_sum::yh_sum_msg msg;
};

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "yh_sum_pub_cla");
    MyClass my_class;
    ros::Rate loop_rate(1);
    while (ros::ok())
    {
        my_class.run();
        loop_rate.sleep();
    }
    return 0;
}

MyClass::MyClass()
{
    pub = nh.advertise<yh_sum::yh_sum_msg>("yh_sum_topic", 100);
}

void MyClass::run()     //  클래스이름, 함수이름
{
   
        msg.stamp = ros::Time::now();
        msg.data = cnt;
        pub.publish(msg);
        cnt++;
}