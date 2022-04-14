#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.srv import SetPen  # 거북이 절대좌표
from std_srvs.srv import Empty
import math
import sys

class TurtlePen:
    def __init__(self):
        self.client_pen = rospy.ServiceProxy("turtle1/set_pen", SetPen)      # 서비스이름, 서비스의파일

    def run(self):
        r = int(input("r값:"))
        g = int(input("g값:"))
        b = int(input("b값:"))
        width = int(input("width값:"))
        off = int(input("off값:"))
        self.client_pen(r,g,b,width,off)
        

if __name__ == "__main__":
    rospy.init_node("yh_turtle_pen")
    turtle_pen = TurtlePen()
    while not rospy.is_shutdown():
        turtle_pen.run()