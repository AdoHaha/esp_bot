#ifndef _ROS_cob_cartesian_controller_CartesianControllerAction_h
#define _ROS_cob_cartesian_controller_CartesianControllerAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_cartesian_controller/CartesianControllerActionGoal.h"
#include "cob_cartesian_controller/CartesianControllerActionResult.h"
#include "cob_cartesian_controller/CartesianControllerActionFeedback.h"

namespace cob_cartesian_controller
{

  class CartesianControllerAction : public ros::Msg
  {
    public:
      cob_cartesian_controller::CartesianControllerActionGoal action_goal;
      cob_cartesian_controller::CartesianControllerActionResult action_result;
      cob_cartesian_controller::CartesianControllerActionFeedback action_feedback;

    CartesianControllerAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_cartesian_controller/CartesianControllerAction"; };
    const char * getMD5(){ return "6ff1ea22824c33d79843a56faeeb9689"; };

  };

}
#endif