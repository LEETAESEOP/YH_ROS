#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/TeleportAbsolute.h"
#include "std_srvs/Empty.h"
#include <cstdlib>


// 메인 함수
class TurtleCircle
{
    public:
    TurtleCircle(double r)
    {
        pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);
        client_clear = nh.serviceClient<std_srvs::Empty>("/clear");
        client_teleport = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
        radius = r;
    }

    void run(void)
    {
        turtlesim::TeleportAbsolute srv_teleport;
        srv_teleport.request.x = 5.5;
        srv_teleport.request.y = 5.5 - radius;
        srv_teleport.request.theta = 0.;
        client_teleport.call(srv_teleport);

        std_srvs::Empty srv_clear;
        client_clear.call(srv_clear);

        ros::Rate loop_rate(1);
        geometry_msgs::Twist msg;
        msg.linear.x = radius * 3;
        msg.angular.z = 3.;

        while (ros::ok())
        {
            pub.publish(msg);
            loop_rate.sleep();
        }
    }

    private:
        ros::NodeHandle nh;
        ros::Publisher pub;
        ros::ServiceClient client_clear;
        ros::ServiceClient client_teleport;
        double radius;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "yh_turtle_circle");
    double radius = atof(argv[1]);
    TurtleCircle turtle_circle(radius);
    turtle_circle.run();

    return 0;
}
