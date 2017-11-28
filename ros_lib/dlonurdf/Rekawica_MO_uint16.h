#ifndef _ROS_dlonurdf_Rekawica_MO_uint16_h
#define _ROS_dlonurdf_Rekawica_MO_uint16_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dlonurdf
{

  class Rekawica_MO_uint16 : public ros::Msg
  {
    public:
      uint16_t kciuk0;
      uint16_t kciuk1;
      uint16_t palwska0;
      uint16_t palwska1;
      uint16_t palsro0;
      uint16_t palsro1;
      uint16_t palser0;
      uint16_t palser1;
      uint16_t palmal0;
      uint16_t palmal1;

    Rekawica_MO_uint16():
      kciuk0(0),
      kciuk1(0),
      palwska0(0),
      palwska1(0),
      palsro0(0),
      palsro1(0),
      palser0(0),
      palser1(0),
      palmal0(0),
      palmal1(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->kciuk0 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->kciuk0 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->kciuk0);
      *(outbuffer + offset + 0) = (this->kciuk1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->kciuk1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->kciuk1);
      *(outbuffer + offset + 0) = (this->palwska0 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->palwska0 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->palwska0);
      *(outbuffer + offset + 0) = (this->palwska1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->palwska1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->palwska1);
      *(outbuffer + offset + 0) = (this->palsro0 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->palsro0 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->palsro0);
      *(outbuffer + offset + 0) = (this->palsro1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->palsro1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->palsro1);
      *(outbuffer + offset + 0) = (this->palser0 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->palser0 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->palser0);
      *(outbuffer + offset + 0) = (this->palser1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->palser1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->palser1);
      *(outbuffer + offset + 0) = (this->palmal0 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->palmal0 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->palmal0);
      *(outbuffer + offset + 0) = (this->palmal1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->palmal1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->palmal1);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->kciuk0 =  ((uint16_t) (*(inbuffer + offset)));
      this->kciuk0 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->kciuk0);
      this->kciuk1 =  ((uint16_t) (*(inbuffer + offset)));
      this->kciuk1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->kciuk1);
      this->palwska0 =  ((uint16_t) (*(inbuffer + offset)));
      this->palwska0 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->palwska0);
      this->palwska1 =  ((uint16_t) (*(inbuffer + offset)));
      this->palwska1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->palwska1);
      this->palsro0 =  ((uint16_t) (*(inbuffer + offset)));
      this->palsro0 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->palsro0);
      this->palsro1 =  ((uint16_t) (*(inbuffer + offset)));
      this->palsro1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->palsro1);
      this->palser0 =  ((uint16_t) (*(inbuffer + offset)));
      this->palser0 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->palser0);
      this->palser1 =  ((uint16_t) (*(inbuffer + offset)));
      this->palser1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->palser1);
      this->palmal0 =  ((uint16_t) (*(inbuffer + offset)));
      this->palmal0 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->palmal0);
      this->palmal1 =  ((uint16_t) (*(inbuffer + offset)));
      this->palmal1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->palmal1);
     return offset;
    }

    const char * getType(){ return "dlonurdf/Rekawica_MO_uint16"; };
    const char * getMD5(){ return "01819fbf5e28480e1d1c396004ad932c"; };

  };

}
#endif