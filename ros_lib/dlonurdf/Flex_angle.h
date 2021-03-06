#ifndef _ROS_dlonurdf_Flex_angle_h
#define _ROS_dlonurdf_Flex_angle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dlonurdf
{

  class Flex_angle : public ros::Msg
  {
    public:
      int32_t thumb;
      int32_t index;

    Flex_angle():
      thumb(0),
      index(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_thumb;
      u_thumb.real = this->thumb;
      *(outbuffer + offset + 0) = (u_thumb.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_thumb.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_thumb.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_thumb.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->thumb);
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_thumb;
      u_thumb.base = 0;
      u_thumb.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_thumb.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_thumb.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_thumb.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->thumb = u_thumb.real;
      offset += sizeof(this->thumb);
      union {
        int32_t real;
        uint32_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->index = u_index.real;
      offset += sizeof(this->index);
     return offset;
    }

    const char * getType(){ return "dlonurdf/Flex_angle"; };
    const char * getMD5(){ return "e235efd3396e4fcc20aff579e3de73cb"; };

  };

}
#endif