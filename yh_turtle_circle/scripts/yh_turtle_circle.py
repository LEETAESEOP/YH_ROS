#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import TeleportAbsolute  # 거북이 절대좌표
from std_srvs.srv import Empty
import math
import sys

    #패키지의 메세지에서 우리가 원하는 Twist 꺼내오기

class TurtleCircle():
    def __init__(self, radius):
        self.pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size = 100)
        self.client_teleport = rospy.ServiceProxy("turtle1/teleport_absolute", TeleportAbsolute)      # 절대좌표 클라이언트 생성
        self.client_clear = rospy.ServiceProxy("/clear", Empty)      # 클리어
        self.radius = radius

    def run(self):
        self.client_teleport(5.5, 5.5 - self.radius, 0)
        self.client_clear()
        msg = Twist()
        
        msg.linear.x = self.radius
        msg.angular.z = 1

        loop_rate = rospy.Rate(1)


        while not rospy.is_shutdown():
         self.pub.publish(msg)
         loop_rate.sleep()

if __name__ == "__main__":
    rospy.init_node("yh_turtle_circle")
    radius = float(sys.argv[1])
    turtle_circle = TurtleCircle(radius)
    turtle_circle.run()