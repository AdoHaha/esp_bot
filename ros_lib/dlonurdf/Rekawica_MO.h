#ifndef _ROS_dlonurdf_Rekawica_MO_h
#define _ROS_dlonurdf_Rekawica_MO_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dlonurdf
{

  class Rekawica_MO : public ros::Msg
  {
    public:
      uint8_t kciuk0;
      uint8_t kciuk1;
      uint8_t palwska0;
      uint8_t palwska1;
      uint8_t palsro0;
      uint8_t palsro1;
      uint8_t palser0;
      uint8_t palser1;
      uint8_t palmal0;
      uint8_t palmal1;

    Rekawica_MO():
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
      offset += sizeof(this->kciuk0);
      *(outbuffer + offset + 0) = (this->kciuk1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->kciuk1);
      *(outbuffer + offset + 0) = (this->palwska0 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->palwska0);
      *(outbuffer + offset + 0) = (this->palwska1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->palwska1);
      *(outbuffer + offset + 0) = (this->palsro0 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->palsro0);
      *(outbuffer + offset + 0) = (this->palsro1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->palsro1);
      *(outbuffer + offset + 0) = (this->palser0 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->palser0);
      *(outbuffer + offset + 0) = (this->palser1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->palser1);
      *(outbuffer + offset + 0) = (this->palmal0 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->palmal0);
      *(outbuffer + offset + 0) = (this->palmal1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->palmal1);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->kciuk0 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->kciuk0);
      this->kciuk1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->kciuk1);
      this->palwska0 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->palwska0);
      this->palwska1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->palwska1);
      this->palsro0 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->palsro0);
      this->palsro1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->palsro1);
      this->palser0 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->palser0);
      this->palser1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->palser1);
      this->palmal0 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->palmal0);
      this->palmal1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->palmal1);
     return offset;
    }

    const char * getType(){ return "dlonurdf/Rekawica_MO"; };
    const char * getMD5(){ return "ad518aaf32c7aace74b1bd2ef5f43da5"; };

  };

}
#endif