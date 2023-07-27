#include "ros/ros.h"
#include "simpleservice/Status.h"
#include "std_msgs/String.h"

bool showStatus(simpleservice::Status::Request  &req,
         simpleservice::Status::Response &res)
{
  
  res.result = "ON";
  ROS_INFO("Request: value= %f", req.value);
  
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("request_status", showStatus);

  ROS_INFO("Ready to show status");
  ros::spin();

  return 0;
}
