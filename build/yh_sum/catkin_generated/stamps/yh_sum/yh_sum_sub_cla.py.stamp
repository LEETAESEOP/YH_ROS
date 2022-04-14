#!/usr/bin/python3
#-*- coding: utf-8 -*-

import rospy
from yh_sum.msg import yh_sum_msg

class Myclass:
    def __init__(self):
        self.sub = rospy.Subscriber("yh_sum_topic", yh_sum_msg, self.msgCallback)
        self.old_data = 0

    def msgCallback(self, msg):
        print(self.old_data + msg.data)
        self.old_data = msg.data

def listener():
    rospy.init_node("yh_sum_sub_cla", anonymous=True)
    my_class = Myclass()
    rospy.spin()

if __name__ == "__main__":
    listener()