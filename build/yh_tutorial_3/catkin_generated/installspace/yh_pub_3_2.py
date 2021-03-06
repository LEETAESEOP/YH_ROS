#!/usr/bin/python3
#-*- coding: utf-8 -*-


import rospy
from yh_tutorial_3.msg import yh_msg_3

def talker():
    pub = rospy.Publisher("yh_topic_3", yh_msg_3, queue_size = 100)
    rospy.init_node("yh_pub_3_2", anonymous = True)
    loop_rate = rospy.Rate(10)
    cnt = 0
    msg = yh_msg_3()

    while not rospy.is_shutdown():
        msg.stamp = rospy.get_rostime()
        msg.data = cnt
        rospy.loginfo("send message: %d", msg.stamp.secs)
        rospy.loginfo("send message: %d", msg.stamp.nsecs)
        rospy.loginfo("send message: %d", msg.data)
        # print(f"{msg.data}나오냐")
        cnt += 2
        pub.publish(msg)
        loop_rate.sleep()

if __name__ == "__main__" :
    try:
        talker()
    except rospy.ROSInterruptException:
        pass


