#ifndef _ROS_SERVICE_sendGoal_h
#define _ROS_SERVICE_sendGoal_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace services
{

static const char SENDGOAL[] = "services/sendGoal";

  class sendGoalRequest : public ros::Msg
  {
    public:
      float x;
      float y;
      float theta;
      int8_t rotationAfter;

    sendGoalRequest():
      x(0),
      y(0),
      theta(0),
      rotationAfter(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->theta);
      union {
        int8_t real;
        uint8_t base;
      } u_rotationAfter;
      u_rotationAfter.real = this->rotationAfter;
      *(outbuffer + offset + 0) = (u_rotationAfter.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rotationAfter);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->theta));
      union {
        int8_t real;
        uint8_t base;
      } u_rotationAfter;
      u_rotationAfter.base = 0;
      u_rotationAfter.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rotationAfter = u_rotationAfter.real;
      offset += sizeof(this->rotationAfter);
     return offset;
    }

    const char * getType(){ return SENDGOAL; };
    const char * getMD5(){ return "bd750456f531c92446cbb8d00debd413"; };

  };

  class sendGoalResponse : public ros::Msg
  {
    public:
      int8_t result;

    sendGoalResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return SENDGOAL; };
    const char * getMD5(){ return "4414c67819626a1b8e0f043a9a0d6c9a"; };

  };

  class sendGoal {
    public:
    typedef sendGoalRequest Request;
    typedef sendGoalResponse Response;
  };

}
#endif
