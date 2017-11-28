#ifndef _ROS_dlonurdf_Pressure_with_time_h
#define _ROS_dlonurdf_Pressure_with_time_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dlonurdf
{

  class Pressure_with_time : public ros::Msg
  {
    public:
      float pressure;
      uint64_t our_time;

    Pressure_with_time():
      pressure(0),
      our_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_pressure;
      u_pressure.real = this->pressure;
      *(outbuffer + offset + 0) = (u_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressure.base >> (8 * 3)) & 0xFF;
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
      union {
        float real;
        uint32_t base;
      } u_pressure;
      u_pressure.base = 0;
      u_pressure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressure = u_pressure.real;
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

    const char * getType(){ return "dlonurdf/Pressure_with_time"; };
    const char * getMD5(){ return "6e87f0c12d4dd1803f2da4ad0aaeaaa5"; };

  };

}
#endif