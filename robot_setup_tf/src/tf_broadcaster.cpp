#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "robot_tf_publisher");
	ros::NodeHandle n;

	ros::Rate r(100);
	//创建TransformBroadcaster对象，用于发布变换关系
	tf::TransformBroadcaster broadcaster;
	//通过TransformBroadcaster来发送转换关系，需要附带5个参数。
	//第1个参数，我们传递了旋转变换，在两个坐标系的发送的任意旋转，
	//都必须通过调用btQuaternion.现在情况下，我们不想旋转，
	//所以我们在调用btQauternion的时候，将pitch,roll,yaw的参数都置0.
	//第2个参数，btVector3，任何变换过程都需要调用它。
	//无论怎样，我们确实需要做一个变换，所以我们调用了btVector3，
	//相应的传感器的x方向距离机体基准偏移10cm，z方向20cm。
	//第3个参数，我们需要给定转换关系携带一个时间戳，我们标记为ros::Time::now()。
	//第4个参数，我们需要传递parent节点的名字。
	//第5个参数，传递的是child节点的名字。 
	while(n.ok()){
		broadcaster.sendTransform(
			tf::StampedTransform(
				tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.16, 0.0, 0.215)),
			ros::Time::now(),"base_link", "camera_link"));
		r.sleep();

	}

}
