#ifndef _ROS_cob_cartesian_controller_CartesianControllerActionGoal_h
#define _ROS_cob_cartesian_controller_CartesianControllerActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "cob_cartesian_controller/CartesianControllerGoal.h"

namespace cob_cartesian_controller
{

  class CartesianControllerActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      cob_cartesian_controller::CartesianControllerGoal goal;

    CartesianControllerActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_cartesian_controller/CartesianControllerActionGoal"; };
    const char * getMD5(){ return "b6b451634e7c56ef37b337701ce1f356"; };

  };

}
#endif