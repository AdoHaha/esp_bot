#ifndef _ROS_dlonurdf_Jamming_pressure_control_h
#define _ROS_dlonurdf_Jamming_pressure_control_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dlonurdf
{

  class Jamming_pressure_control : public ros::Msg
  {
    public:
      uint8_t motorPWM;
      uint8_t airPWM;
      uint8_t vacumPWM;

    Jamming_pressure_control():
      motorPWM(0),
      airPWM(0),
      vacumPWM(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motorPWM >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motorPWM);
      *(outbuffer + offset + 0) = (this->airPWM >> (8 * 0)) & 0xFF;
      offset += sizeof(this->airPWM);
      *(outbuffer + offset + 0) = (this->vacumPWM >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vacumPWM);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->motorPWM =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motorPWM);
      this->airPWM =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->airPWM);
      this->vacumPWM =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vacumPWM);
     return offset;
    }

    const char * getType(){ return "dlonurdf/Jamming_pressure_control"; };
    const char * getMD5(){ return "e3f767163a06737822ec0ffc1d742585"; };

  };

}
#endif