#include "ros/ros.h" // ROS 헤더파일
#include "service_tutorial/my_srv.h" // 서비스 헤더 파일
                                     // 빌드 후 생성
#include <cstdlib>  // atoll 함수 사용을 위한 라이브러리

int main(int argc, char **argv) // 메인 함수 (argc=갯수, argv=값, **문자열 리스트라고 생각하면된다)
{
    ros::init(argc, argv, "my_client"); //  노드 이름 초기화

    // rosrun 패키지이름 노드이름 a b
    // argv = {노드이름, a, b}   형태로 들어옴.
    if(argc != 3)
    {
        ROS_INFO("command: rosrun service_tutorial my_client arg1 arg2");
        ROS_INFO("arg1, arg2: int64 number");
        
        return 1;

    }

    ros::NodeHandle nh; // 노드 핸들 선언

    // 서비스 클라이언트 선언
    // 서비스 클라이언트 (my_service_client) 를 선언한다.
    // 서비스 이름은 (my_service)이고 패키지 (service_tutorial) 의 (my_srv) 서비스 파일을 사용한다.
    ros::ServiceClient my_service_client = nh.serviceClient<service_tutorial::my_srv>("my_service");

    service_tutorial::my_srv srv;

    // 서비스 요청 값으로 노드 실행시 입력된 매개변수 a, b에 저장한다.
    srv.request.a = atoll(argv[1]);     // atoll은 문자열을 숫자로 바꿔주는 기능을 함.
    srv.request.b = atoll(argv[2]);

    // 서비스를 요청하고, 응답이 정산적으로 왔을 경우, 값은 표시한다.
    if (my_service_client.call(srv))
    {
        ROS_INFO("send srv, srv.request.a, b: %ld, %ld", srv.request.a, srv.request.b);
        ROS_INFO("receive srv, srv.response.result: %ld", srv.response.result);
        // ROS_INFO("%s", srv.response.error.c_str());      // 문자열 에러 표시할 경우 추가하는 코드임.
    }
    else
    {
        ROS_ERROR("Failed to call server");
        return 1;
    }

    return 0;
}