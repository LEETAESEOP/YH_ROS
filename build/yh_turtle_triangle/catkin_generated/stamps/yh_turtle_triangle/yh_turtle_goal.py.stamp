#!/usr/bin/python
#-*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math

class MyTurtle:
    def __init__(self):
        self.pub_cmd_vel = rospy.Publisher("/turtle1/cmd_vel", Twist, queue_size = 5)
        self.sub_pose = rospy.Subscriber("/turtle1/pose", Pose, self.update_pose)
        self.pose = Pose()
        self.loop_rate = rospy.Rate(10)

    def update_pose(self, msg):
        self.pose = msg
        self.pose.x = round(self.pose.x, 4)     # 소수점 4째자리까지 표현되도록 반올림.
        self.pose.y = round(self.pose.y, 4)
    
    def euclidean_distance(self, goal_pose):            # 유클리디안 디스턴스 (유클리드 거리)
        # (x1, y1) => (x2, y2)
        # (self.pose) => (goal_pose)
        diff_x = goal_pose.x-self.pose.x        # x2-x1
        diff_y = goal_pose.y-self.pose.y        # y2-y1
        return math.sqrt((diff_x)*(diff_x) + (diff_y)*(diff_y))     # 두 점(목표점, 현재점) 사이의 거리

    def linear_vel(self, goal_pose, constant = 1):    # constant에 값을 안주면 기본적으로 constant에 1.5 값을 주겠다는 의미
        return constant * self.euclidean_distance(goal_pose)
        # 1차함수의 y = ax 로 이해하면 편함. costant = a 로 이해, self.euclidean_distance(goal_pose) 로 x로 이해.
        # 위 return 값이 0이되면 도착했다고 볼 수 있다.

    def steering_angle(self, goal_pose):
        return math.atan2((goal_pose.y - self.pose.y), (goal_pose.x - self.pose.x))
        # 아크탄젠트는 atan1, atan2 두종류가있는데, 결과값은 동일하게 나온다. 보통 atan2 사용함.
        # 아크탄젠트는 각도를 구할때 사용.

    def angular_vel(self, goal_pose, constant = 4):
        return constant * (self.steering_angle(goal_pose) - self.pose.theta)
        # 목표하는 각도 - 현재각도만큼 돌겠다.
        # return 값이 0이되면 더이상 각도 변화가 없어도 된다고 볼 수 있다.
        # 이 부분도 1차함수로 이해하면 편함. constant에 큰값을 줄수록 각도가 빨리돈다고 보면 된다.

    def move2goal(self):
        goal_pose = Pose()
        goal_pose.x = float(input("x좌표 : "))
        goal_pose.y = float(input("y좌표 : "))
        tolerance = float(input("오차: "))
        msg = Twist()   # 실제로 보내는 부분

        # 거리가 tolerance(오차)값 이내로 들어오면, while문을 나간다.
        while self.euclidean_distance(goal_pose) >= tolerance:
            msg.linear.x = self.linear_vel(goal_pose)
            msg.angular.z = self.angular_vel(goal_pose)

            self.pub_cmd_vel.publish(msg)
            self.loop_rate.sleep()
        
        # while문 밖으로 빠져나오면 도착한 상태이니까, 0값을 주고 멈추게 한다.
        msg.linear.x = 0        # 직선이동 속도가 0
        msg.angular.z = 0       # 고개 돌리는 속도가 0
        self.pub_cmd_vel.publish(msg)

        print("goal!")

if __name__ == "__main__":
    rospy.init_node("yh_turtle_goal")
    try:
        my_turtle = MyTurtle()
        my_turtle.move2goal()
    except rospy.ROSInterruptException:
        pass

