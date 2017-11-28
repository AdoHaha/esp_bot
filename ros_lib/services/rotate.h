#ifndef _ROS_SERVICE_rotate_h
#define _ROS_SERVICE_rotate_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace services
{

static const char ROTATE[] = "services/rotate";

  class rotateRequest : public ros::Msg
  {
    public:
      int8_t rotate;

    rotateRequest():
      rotate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_rotate;
      u_rotate.real = this->rotate;
      *(outbuffer + offset + 0) = (u_rotate.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rotate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_rotate;
      u_rotate.base = 0;
      u_rotate.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rotate = u_rotate.real;
      offset += sizeof(this->rotate);
     return offset;
    }

    const char * getType(){ return ROTATE; };
    const char * getMD5(){ return "f24368bf7a5f7196e9e165e09ada2f32"; };

  };

  class rotateResponse : public ros::Msg
  {
    public:
      int8_t result;

    rotateResponse():
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

    const char * getType(){ return ROTATE; };
    const char * getMD5(){ return "4414c67819626a1b8e0f043a9a0d6c9a"; };

  };

  class rotate {
    public:
    typedef rotateRequest Request;
    typedef rotateResponse Response;
  };

}
#endif
