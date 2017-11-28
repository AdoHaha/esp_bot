#ifndef _ROS_dlonurdf_Rekawica_Wib_h
#define _ROS_dlonurdf_Rekawica_Wib_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dlonurdf
{

  class Rekawica_Wib : public ros::Msg
  {
    public:
      uint8_t wib0;
      uint8_t wib1;
      uint8_t wib2;
      uint8_t wib3;
      uint8_t wib4;

    Rekawica_Wib():
      wib0(0),
      wib1(0),
      wib2(0),
      wib3(0),
      wib4(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->wib0 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wib0);
      *(outbuffer + offset + 0) = (this->wib1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wib1);
      *(outbuffer + offset + 0) = (this->wib2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wib2);
      *(outbuffer + offset + 0) = (this->wib3 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wib3);
      *(outbuffer + offset + 0) = (this->wib4 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wib4);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->wib0 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->wib0);
      this->wib1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->wib1);
      this->wib2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->wib2);
      this->wib3 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->wib3);
      this->wib4 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->wib4);
     return offset;
    }

    const char * getType(){ return "dlonurdf/Rekawica_Wib"; };
    const char * getMD5(){ return "14772356812cb8f45a1d648c575e597e"; };

  };

}
#endif