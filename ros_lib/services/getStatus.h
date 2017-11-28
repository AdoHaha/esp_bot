#ifndef _ROS_SERVICE_getStatus_h
#define _ROS_SERVICE_getStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace services
{

static const char GETSTATUS[] = "services/getStatus";

  class getStatusRequest : public ros::Msg
  {
    public:
      int8_t read;

    getStatusRequest():
      read(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_read;
      u_read.real = this->read;
      *(outbuffer + offset + 0) = (u_read.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->read);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_read;
      u_read.base = 0;
      u_read.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->read = u_read.real;
      offset += sizeof(this->read);
     return offset;
    }

    const char * getType(){ return GETSTATUS; };
    const char * getMD5(){ return "ef817c1891fac046640fa6901dd1a58d"; };

  };

  class getStatusResponse : public ros::Msg
  {
    public:
      int8_t status;

    getStatusResponse():
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    const char * getType(){ return GETSTATUS; };
    const char * getMD5(){ return "581cc55c12abfc219e446416014f6d0e"; };

  };

  class getStatus {
    public:
    typedef getStatusRequest Request;
    typedef getStatusResponse Response;
  };

}
#endif
