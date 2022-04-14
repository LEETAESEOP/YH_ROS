#include "ros/ros.h" // ROS 헤더 파일
#include "topic_tutorial/my_msg.h" // my_msg 파일 헤더
                                    // 빌드 후 자동 생성
// const는 값을 수정할 수 없음!!!
// 메세지 콜백함수, 서브스크라이버가 메세지를 수신했을 때 동작하는 함수이다.
// 입력메세지로는 패키지 이름 (topic_tutorial)의 메세지 이름 (my_msg)을 받도록 되어있다.
void msgCallback(const topic_tutorial::my_msg::ConstPtr& msg)
{
    ROS_INFO("receive msg = %d", msg->stamp.sec); // stamp.sec를 표시한다.  << *msg.stamp.sec == msg->stamp.sec 이다.>> [[   *. == ->     로 이해하면 된다!!!]]
    ROS_INFO("receive msg = %d", msg->stamp.nsec); // stamp.nsec를 표시한다.   << 포인터를 사용한 것이므로, 그냥 msg값을 불러오면 주소값만 나온다!!! >>
    ROS_INFO("receive msg = %d", msg->data); // stamp.data를 표시한다.
}


//메인 함수
int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_subscriber"); // 노드 이름 초기화
    ros::NodeHandle nh; // ROS 시스템과 통신을 위한 노드 핸들 선언
    //NodeHandle=자료형   nh=변수이름

    // 서브스크라이버 선언
    // 패키지 (topic_tutorial)의 메세지(my_msg)을 이용한 서브스크라이버(my_sub)를 작성한다.
    // 토픽명은 (my_topic)이며, 서브스크라이버큐(queue) 사이즈를 100으로 설정한다.
    // 콜백 함수는 (msgCallback)이다.
    ros::Subscriber my_sub = nh.subscribe("my_topic", 100, msgCallback);
    // Subscriber=자료형 my_sub=변수이름

    // 콜백 함수 호출을 위한 함수, 메세지가 수신되기를 대기
    // 수신되었을 경우 콜백 함수를 호출한다.
    // spin()으로 계속 메세지를 받기게 대기하도록 함. 만약 이 구문이 없으면 return 0 실행되어 프로그램 종료됨으로 주의.
    ros::spin();
    return 0;
}

