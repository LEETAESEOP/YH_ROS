#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import TeleportAbsolute  # 거북이 절대좌표
from std_srvs.srv import Empty
import math
import sys

    #패키지의 메세지에서 우리가 원하는 Twist 꺼내오기

class TurtleTriangle():
    def __init__(self, length):
        self.pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size = 100)
        self.client_teleport = rospy.ServiceProxy("turtle1/teleport_absolute", TeleportAbsolute)      # 절대좌표 클라이언트 생성
        self.client_clear = rospy.ServiceProxy("/clear", Empty)      # 클리어
        self.length = length

    def run(self):
        self.client_teleport(5.544445 - self.length/2, 5.544445 -(math.sqrt(3) /4 * self.length), 0)

        self.client_clear()

        loop_rate = rospy.Rate(1)
        msg = Twist()
        cnt = 0

        #퍼블리셔의 매소드, 퍼블리셔랑 통신이 연결된 갯수가 몇개인지 카운트한다. (서브스크라이버가 몇개 연결됬는지 카운트)
        while self.pub.get_num_connections() < 1 :
            continue


        while not rospy.is_shutdown():
            msg.linear.x = self.length
            msg.angular.z = 0
            self.pub.publish(msg)
            loop_rate.sleep()
            cnt += 1
            if cnt % 3 == 0 :
                self.client_clear()

            msg.linear.x = 0
            # 120도 회전
            msg.angular.z = math.pi * 2 / 3
            self.pub.publish(msg)
            loop_rate.sleep()


if __name__ == "__main__":
    rospy.init_node("yh_turtle_triangle")
    if len(sys.argv) != 2:
        print("ang erroe")
        sys.exit(1)

    length = float(sys.argv[1])
    turtle_circle = TurtleTriangle(float(sys.argv[1]))
    turtle_circle.run()