#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from yh_tutorial_7.srv import yh_srv_7
import sys

def calculate_client(a, b):
    rospy.wait_for_service("my_service")
    try:
        my_service_client = rospy.ServiceProxy("my_service", yh_srv_7)
        resp = my_service_client(a, b)
        return resp.result
    except rospy.ServiceException as e:
        rospy.logerr("Service call failed: %s", e)




if __name__ == "__main__":
    rospy.init_node("yh_client_7")
    if len(sys.argv) != 3:
        rospy.loginfo("usage: rosrun yh_tutorial_7 yh_client_7.py a, b")
        rospy.loginfo("a, b: int64 number")
        sys.exit(1)
    a = int(sys.argv[1])
    b = int(sys.argv[2])
    res = calculate_client(a, b)
    rospy.loginfo("send: a=%d, b=%d", a, b)
    rospy.loginfo("receive: result=%d", res)