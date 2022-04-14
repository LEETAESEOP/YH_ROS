#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from yh_tutorial_7.srv import yh_srv_7, yh_srv_7Response

def calculation(req):
    # min=min(req.a,req.b)
    # max=max(req.a,req.b)
    rospy.loginfo("request: %d, %d", req.a, req.b)
    rospy.loginfo("response: %d", (req.a - req.b))
    return yh_srv_7Response(abs(req.a-req.b))

def calculate_server():
    rospy.init_node("yh_server_7")
    my_service_server = rospy.Service("my_service", yh_srv_7, calculation)
    rospy.loginfo("Service Server ready.")
    rospy.spin()

if __name__ == "__main__":
    calculate_server()