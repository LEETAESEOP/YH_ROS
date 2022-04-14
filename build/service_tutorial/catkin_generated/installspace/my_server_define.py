#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from service_tutorial.srv import my_srv, my_srvResponse

PLUS = 1
MINUS = 2
MULTIPLICATION = 3
DIVISION = 4

def calculation(req):
    my_operator = rospy.get_param("calculation_method")
    # error =""         #문자로 에러 표시할 경우
    if my_operator == PLUS:
        res = req.a + req.b
    elif my_operator == MINUS:
        res = req.a - req.b
    elif my_operator == MULTIPLICATION:
        res = req.a * req.b
    elif my_operator == DIVISION:
        if req.b == 0:
            res = 0
            # error = "ERROR"           #문자로 에러 표시할 경우
        else:
            res = req.a / req.b

        rospy.loginfo("request: %d, %d", req.a, req.b)
        rospy.loginfo("response: %d", (res))
        return my_srvResponse(res)
        # return my_srvResponse(res, error)         #문자로 에러 표시할 경우.

def calculate_server():
    rospy.init_node("my_server")
    rospy.set_param("calculation_method", PLUS)

    my_service_server = rospy.Service("my_service", my_srv, calculation)
    rospy.loginfo("Service Server ready.")
    rospy.spin()

if __name__ == "__main__":
    calculate_server()