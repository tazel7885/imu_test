#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Pose2D.h>
#include <tf/tf.h>

sensor_msgs::Imu imu;
geometry_msgs::Pose2D pose;

void ImuCallback(const sensor_msgs::Imu::ConstPtr &msg)
{
	tf::Quaternion q(
        msg->pose.pose.orientation.x,
        msg->pose.pose.orientation.y,
        msg->pose.pose.orientation.z,
        msg->pose.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);

	pose.theta = yaw;
}


int main(int argc, char** argv)
{
	
	ros::init(argc, argv, "imu_test");
	ros::NodeHandle nh;
	ros::Rate loop_rate(250);

	ros::Publisher pose_pub = nh.advertise<geometry_msgs::Pose2D>("/imu_test", 10);

	ros::Subscriber imu_sub = nh.subscribe("/imu/data", 10, ImuCallback);

	while(ros::ok())
	{
		pose_pub.publish(pose);		
		ros::spinOnce();
		loop_rate.sleep();
	}
}