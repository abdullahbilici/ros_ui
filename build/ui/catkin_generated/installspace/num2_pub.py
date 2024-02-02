import rospy
from std_msgs.msg import Int16

from numpy.random import randint

if __name__ == "__main__":
    pub = rospy.Publisher("num2", Int16, queue_size=10) # publisher. first argument is the name of the topic
    rospy.init_node("num2_pub") # node initialized
    rate = rospy.Rate(1) # 1 messages per second

    print("Num2 publisher is running!")

    while not rospy.is_shutdown():
        msg = randint(0,10)
        
        pub.publish(msg) # publish
        
        rate.sleep()