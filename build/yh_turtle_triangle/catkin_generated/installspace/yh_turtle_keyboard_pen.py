#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import SetPen, SetPenRequest
from std_srvs.srv import Empty
import math
import sys

class MyTurtle:
    def __init__(self):
        self.sub = rospy.Subscriber("cmd_vel",Twist, self.msgCallback)      # self.msgCallback == 클래스 안에 정의된msgCallback 함수
        self.pub = rospy.Publisher("/turtle1/cmd_vel",Twist, queue_size = 1)
        self.client_pen = rospy.ServiceProxy("turtle1/set_pen", SetPen)      # 서비스이름, 서비스 타입(6번째줄 임포트해온것 그대로 넣으면된다.)
        self.pen = SetPenRequest()
        self.pen.width = 3
    
    def msgCallback(self, msg) :
        if msg.linear.z > 0 :
            # Change Color
            self.pen.r = int(input("r:"))
            self.pen.g = int(input("g:"))
            self.pen.b = int(input("b:"))
            self.client_pen(self.pen)

            # r = int(input("r:"))
            # g = int(input("g:"))
            # b = int(input("b:"))
            # width = int(input("width값:"))
            # off = int(input("off값:"))
            # self.client_pen(r, g, b, width, off)
 
        elif msg.linear.z < 0:
            # Change width
            self.pen.width = int(input("width:"))
            self.client_pen(self.pen)

        else:
            self.pub.publish(msg)

        
if __name__ == "__main__":
    rospy.init_node("yh_turtle_keyboard_pen")
    turtle_pen = MyTurtle()
    rospy.spin()
