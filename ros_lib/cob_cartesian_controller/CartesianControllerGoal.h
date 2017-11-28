#ifndef _ROS_cob_cartesian_controller_CartesianControllerGoal_h
#define _ROS_cob_cartesian_controller_CartesianControllerGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cob_cartesian_controller/MoveLin.h"
#include "cob_cartesian_controller/MoveCirc.h"

namespace cob_cartesian_controller
{

  class CartesianControllerGoal : public ros::Msg
  {
    public:
      uint8_t move_type;
      cob_cartesian_controller::MoveLin move_lin;
      cob_cartesian_controller::MoveCirc move_circ;
      enum { LIN = 1 };
      enum { CIRC = 2 };

    CartesianControllerGoal():
      move_type(0),
      move_lin(),
      move_circ()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->move_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->move_type);
      offset += this->move_lin.serialize(outbuffer + offset);
      offset += this->move_circ.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->move_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->move_type);
      offset += this->move_lin.deserialize(inbuffer + offset);
      offset += this->move_circ.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_cartesian_controller/CartesianControllerGoal"; };
    const char * getMD5(){ return "d62084e4c3688d65191265b5a3e1f98f"; };

  };

}
#endif