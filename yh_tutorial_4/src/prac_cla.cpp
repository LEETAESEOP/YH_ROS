class SubAndPub
{
    public: // SubAndPub.멤버 접근 가능
            // 함수(메소드)
            SubAndPub() // 생성자
            {
                pub = nh.advertise<yh_tutorial_4::yh_msg_4>("yh_topic_44",100);
                sub = nh.subscribe("yh_topic_4", 100, &SubAndPub::msgCallback, this);
            }
            void msgCallback(const yh_tutorial_4::yh_msg_4::ConstPtr& msg)
            {   
                if (msg->data % 5 == 0)
             {
                my_pub.publish(msg); 
             }
            }

    private:    // 직접 접근 불가
                // 변수
                // 예) msg
                yh_tutorial_4::yh_msg_4 msg;
                ros::Publisher pub;
                ros::Subscriber sub;

    
    protected: 

}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "yh_pub_sub_4");
    SubAndPub sub_and_pub;
    ros::spin();
    return 0;
}