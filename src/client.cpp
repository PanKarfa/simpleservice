#include "ros/ros.h"
#include "simpleservice/Status.h"
#include <cstdlib>
#include <string>
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "client");
  
  if (argc != 2)
  {
    ROS_INFO("usage: request_status_client X ");
    return 1;
  }

  ros::NodeHandle n;
  
  ros::ServiceClient client = n.serviceClient<simpleservice::Status>("request_status");
 
  simpleservice::Status srv;
 
  srv.request.value = atof(argv[1]);
  
  if (client.call(srv))
  {
    ROS_INFO("STATUS: %s", srv.response.result);
  }
  else
  {
    ROS_ERROR("Failed to call service request_status");
    return 1;
  }

  return 0;
}
