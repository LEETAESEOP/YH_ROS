#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from yh_tutorial_4.msg import yh_msg_4

def msgCallback(msg):
    rospy.loginfo("receive message: %d", msg.stamp.secs)
    rospy.loginfo("receive message: %d", msg.stamp.nsecs)
    rospy.loginfo("receive message: %d", msg.data)

def listener():
    rospy.init_node("yh_sub_4", anonymous=True)
    rospy.Subscriber("yh_topic_44", yh_msg_4, msgCallback)

    rospy.spin()

if __name__ == "__main__":
    listener()
