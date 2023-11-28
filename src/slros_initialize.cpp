#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "teamcrash";

// For Block teamcrash/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_teamcrash_std_msgs_Float64> Sub_teamcrash_16;

// For Block teamcrash/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_teamcrash_std_msgs_Float64> Sub_teamcrash_17;

// For Block teamcrash/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_teamcrash_std_msgs_Float64> Pub_teamcrash_13;

// For Block teamcrash/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_teamcrash_std_msgs_Float64> Pub_teamcrash_14;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

