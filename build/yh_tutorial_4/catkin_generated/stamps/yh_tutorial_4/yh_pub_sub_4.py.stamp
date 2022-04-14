#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from yh_tutorial_4.msg import yh_msg_4

pub = rospy.Publisher("yh_topic_44", yh_msg_4, queue_size = 100)

#작동순서3
def msgCallback(msg):
    if msg.data % 5 == 0:
         pub.publish(msg)            # 보내는 부분

#작동순서2
def listener():
    rospy.init_node("yh_pub_sub_4", anonymous=True)
    rospy.Subscriber("yh_topic_4", yh_msg_4, msgCallback)
    rospy.spin()

#작동순서1
if __name__ == "__main__" :
    listener()
