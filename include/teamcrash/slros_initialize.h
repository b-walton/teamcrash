#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "teamcrash_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block teamcrash/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_teamcrash_std_msgs_Float64> Sub_teamcrash_16;

// For Block teamcrash/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_teamcrash_std_msgs_Float64> Sub_teamcrash_17;

// For Block teamcrash/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_teamcrash_std_msgs_Float64> Pub_teamcrash_13;

// For Block teamcrash/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_teamcrash_std_msgs_Float64> Pub_teamcrash_14;

void slros_node_init(int argc, char** argv);

#endif
