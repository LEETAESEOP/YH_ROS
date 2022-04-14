#!/usr/bin/python3
#-*- coding: utf-8 -*-

import rospy
from yh_star.msg import yh_star_msg

def msgCallback(msg):
    n = msg.data
    s = ""
    for i in range(1, n):
        if (n % i == 0) :
            s += str(i)
            s += " "
    print(s)


def listener():
    rospy.init_node("yh_star_sub", anonymous=True)
    rospy.Subscriber("yh_star_topic", yh_star_msg, msgCallback)

    rospy.spin()

if __name__ == "__main__":
    listener()
