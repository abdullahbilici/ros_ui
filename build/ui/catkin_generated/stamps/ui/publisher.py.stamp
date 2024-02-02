import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    pub = rospy.Publisher("some_topic", String, queue_size=10)
    rospy.init_node("some_sensor", anonymous=False)
    rate = rospy.Rate(1) # 1 massage per second

    print("Publisher is running!")

    msg = "Hello world "
    num = 0
    while not rospy.is_shutdown():

        pub.publish(msg + str(num))
        rospy.loginfo(msg + str(num))

        num += 1
        rate.sleep()