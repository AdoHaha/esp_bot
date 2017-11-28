#ifndef _ROS_SERVICE_getLocation_h
#define _ROS_SERVICE_getLocation_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace services
{

static const char GETLOCATION[] = "services/getLocation";

  class getLocationRequest : public ros::Msg
  {
    public:
      int8_t read;

    getLocationRequest():
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

    const char * getType(){ return GETLOCATION; };
    const char * getMD5(){ return "ef817c1891fac046640fa6901dd1a58d"; };

  };

  class getLocationResponse : public ros::Msg
  {
    public:
      int8_t id;
      float x;
      float y;
      float z;
      float theta;

    getLocationResponse():
      id(0),
      x(0),
      y(0),
      z(0),
      theta(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->z);
      offset += serializeAvrFloat64(outbuffer + offset, this->theta);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id = u_id.real;
      offset += sizeof(this->id);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->theta));
     return offset;
    }

    const char * getType(){ return GETLOCATION; };
    const char * getMD5(){ return "3d673c2541fdc2d564a4f754df285f46"; };

  };

  class getLocation {
    public:
    typedef getLocationRequest Request;
    typedef getLocationResponse Response;
  };

}
#endif
