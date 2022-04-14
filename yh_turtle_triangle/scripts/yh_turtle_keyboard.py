#!/usr/bin/python
#-*- coding: utf-8 -*-

import turtle
import rospy
from geometry_msgs.msg import Twist
    #패키지의 메세지에서 우리가 원하는 Twist 꺼내오기

pub = rospy.Publisher("/turtle1/cmd_vel",Twist, queue_size = 1)
def keyboardCallback(msg):
    pub.publish(msg)

def listener():
    rospy.init_node("yh_turtle_keyboard")
    sub = rospy.Subscriber("/cmd_vel", Twist, keyboardCallback)
    rospy.spin()
    
if __name__ == "__main__":
    listener()