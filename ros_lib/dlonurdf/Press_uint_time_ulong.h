#ifndef _ROS_dlonurdf_Press_uint_time_ulong_h
#define _ROS_dlonurdf_Press_uint_time_ulong_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dlonurdf
{

  class Press_uint_time_ulong : public ros::Msg
  {
    public:
      uint16_t pressure;
      uint64_t our_time;

    Press_uint_time_ulong():
      pressure(0),
      our_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pressure >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pressure >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pressure);
      union {
        uint64_t real;
        uint32_t base;
      } u_our_time;
      u_our_time.real = this->our_time;
      *(outbuffer + offset + 0) = (u_our_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_our_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_our_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_our_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->our_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->pressure =  ((uint16_t) (*(inbuffer + offset)));
      this->pressure |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->pressure);
      union {
        uint64_t real;
        uint32_t base;
      } u_our_time;
      u_our_time.base = 0;
      u_our_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_our_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_our_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_our_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->our_time = u_our_time.real;
      offset += sizeof(this->our_time);
     return offset;
    }

    const char * getType(){ return "dlonurdf/Press_uint_time_ulong"; };
    const char * getMD5(){ return "7aff21869d222afce7061840c983c317"; };

  };

}
#endif