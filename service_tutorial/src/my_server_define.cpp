#include "ros/ros.h"
#include "service_tutorial/my_srv.h"


#define PLUS 1
#define MINUS 2
#define MULTIPLICATION 3
#define DIVISION 4

int my_operator = PLUS;

bool calculation(service_tutorial::my_srv::Request &req, service_tutorial::my_srv::Response &res)
{
    switch(my_operator)
    {
        case PLUS:
            res.result = req.a + req.b;
            break;
        case MINUS:
            res.result = req.a - req.b;
            break;
        case MULTIPLICATION:
            res.result = req.a * req.b;
            break;
        case DIVISION:
            if (req.b == 0)
            {
                ROS_INFO("NoNo");
                // res.error = "No_No_No!!";
            }
            else
            {
            res.result = req.a / req.b;
            }
            break;
        default:
            res.result = req.a + req.b;
            break;
    }

    ROS_INFO("request: a= %ld, b=%ld", req.a, req.b);
    ROS_INFO("response: %ld", res.result);
    // ROS_INFO(" Don't Pressed 0 !!!: %s", res.error.c_str());
    
    return true;
}

int main(int argc, char** argv) // 메인함수
{
    ros::init(argc, argv, "my_server"); // 노드 이름 초기화
    ros::NodeHandle nh; // 노드 핸들 선언

    nh.setParam("calculation_method", PLUS);    // 매개변수 초기 설정
                                                // "calculation_method"라는 이름으로 파라메터 설정(파라메터 서버에 등록). 초기값은 PLUS

    ros::ServiceServer my_service_server = nh.advertiseService("my_service", calculation);

    ROS_INFO("Service Server Ready.");

    ros::Rate loop_rate(10);
    while (true)
    {
        nh.getParam("calculation_method", my_operator); // 파라메터 서버에서 값을 받아옴.
        ros::spinOnce();                      // 콜백함수 실행 (1회만)
        loop_rate.sleep();
    }
//------------------------------------------
    //★ ros::spin();  == while (true){ros::spinOnce();}
//-------------------------------------------
    return 0;
}