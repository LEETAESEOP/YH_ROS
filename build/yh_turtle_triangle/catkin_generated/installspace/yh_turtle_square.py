#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import TeleportAbsolute  # 거북이 절대좌표
from std_srvs.srv import Empty
import math
import sys
from yh_turtle_triangle import TurtleTriangle

    #패키지의 메세지에서 우리가 원하는 Twist 꺼내오기

class TurtleSquare(TurtleTriangle):
    def run(self):
        # length = 6 이라면, x좌표 = 2.5 , y좌표 = 2.5, 방향 0도
        self.client_teleport(5.544445 - self.length/2, 5.544445 - self.length/2, 0)
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
            if cnt % 4 == 0 :
                self.client_clear()

            msg.linear.x = 0
            # 90도 회전
            msg.angular.z = math.pi / 2
            self.pub.publish(msg)
            loop_rate.sleep()

if __name__ == "__main__":
    rospy.init_node("yh_turtle_square")
    try:
        length = float(input("변의 길이를 입력해주세요."))
        turtle_square = TurtleSquare(float(length))
        turtle_square.run()
    except:
        pass