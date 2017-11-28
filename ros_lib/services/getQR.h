#ifndef _ROS_SERVICE_getQR_h
#define _ROS_SERVICE_getQR_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace services
{

static const char GETQR[] = "services/getQR";

  class getQRRequest : public ros::Msg
  {
    public:
      int8_t read;

    getQRRequest():
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

    const char * getType(){ return GETQR; };
    const char * getMD5(){ return "ef817c1891fac046640fa6901dd1a58d"; };

  };

  class getQRResponse : public ros::Msg
  {
    public:
      int8_t qrcode;

    getQRResponse():
      qrcode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_qrcode;
      u_qrcode.real = this->qrcode;
      *(outbuffer + offset + 0) = (u_qrcode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->qrcode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_qrcode;
      u_qrcode.base = 0;
      u_qrcode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->qrcode = u_qrcode.real;
      offset += sizeof(this->qrcode);
     return offset;
    }

    const char * getType(){ return GETQR; };
    const char * getMD5(){ return "8771f61b098153e0acb23388485981c3"; };

  };

  class getQR {
    public:
    typedef getQRRequest Request;
    typedef getQRResponse Response;
  };

}
#endif
