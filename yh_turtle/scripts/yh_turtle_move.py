#!/usr/bin/python
#-*- coding: utf-8 -*-

import turtle
import rospy
from geometry_msgs.msg import Twist
    #패키지의 메세지에서 우리가 원하는 Twist 꺼내오기

def talker():
    rospy.init_node("yh_turtle_move")
    pub = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size = 100)
    msg = Twist()
    msg.linear.x = 4
    loop_rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        pub.publish(msg)
        loop_rate.sleep()

if __name__ == "__main__":
    try:
        talker()
    except rospy.ROSInterruptException:
        pass