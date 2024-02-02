import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    pub = rospy.Publisher("hello_world", String, queue_size=10) # publisher. first argument is the name of the topic
    rospy.init_node("hello_world_pub") # node initialized
    rate = rospy.Rate(1) # 1 massage per second

    print("Hello World publisher is running!")

    msg = "Hello world "
    num = 0
    while not rospy.is_shutdown():

        pub.publish(msg + str(num)) # publish

        num += 1
        rate.sleep()