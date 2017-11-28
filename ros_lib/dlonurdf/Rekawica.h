#ifndef _ROS_dlonurdf_Rekawica_h
#define _ROS_dlonurdf_Rekawica_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dlonurdf
{

  class Rekawica : public ros::Msg
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
      uint16_t czujkciuk;
      uint16_t czujwska;
      uint16_t czujsro;
      uint16_t czujser;
      uint16_t czujmal;
      uint16_t czujdlo;

    Rekawica():
      kciuk0(0),
      kciuk1(0),
      palwska0(0),
      palwska1(0),
      palsro0(0),
      palsro1(0),
      palser0(0),
      palser1(0),
      palmal0(0),
      palmal1(0),
      czujkciuk(0),
      czujwska(0),
      czujsro(0),
      czujser(0),
      czujmal(0),
      czujdlo(0)
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
      *(outbuffer + offset + 0) = (this->czujkciuk >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->czujkciuk >> (8 * 1)) & 0xFF;
      offset += sizeof(this->czujkciuk);
      *(outbuffer + offset + 0) = (this->czujwska >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->czujwska >> (8 * 1)) & 0xFF;
      offset += sizeof(this->czujwska);
      *(outbuffer + offset + 0) = (this->czujsro >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->czujsro >> (8 * 1)) & 0xFF;
      offset += sizeof(this->czujsro);
      *(outbuffer + offset + 0) = (this->czujser >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->czujser >> (8 * 1)) & 0xFF;
      offset += sizeof(this->czujser);
      *(outbuffer + offset + 0) = (this->czujmal >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->czujmal >> (8 * 1)) & 0xFF;
      offset += sizeof(this->czujmal);
      *(outbuffer + offset + 0) = (this->czujdlo >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->czujdlo >> (8 * 1)) & 0xFF;
      offset += sizeof(this->czujdlo);
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
      this->czujkciuk =  ((uint16_t) (*(inbuffer + offset)));
      this->czujkciuk |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->czujkciuk);
      this->czujwska =  ((uint16_t) (*(inbuffer + offset)));
      this->czujwska |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->czujwska);
      this->czujsro =  ((uint16_t) (*(inbuffer + offset)));
      this->czujsro |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->czujsro);
      this->czujser =  ((uint16_t) (*(inbuffer + offset)));
      this->czujser |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->czujser);
      this->czujmal =  ((uint16_t) (*(inbuffer + offset)));
      this->czujmal |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->czujmal);
      this->czujdlo =  ((uint16_t) (*(inbuffer + offset)));
      this->czujdlo |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->czujdlo);
     return offset;
    }

    const char * getType(){ return "dlonurdf/Rekawica"; };
    const char * getMD5(){ return "49f03eb42d0c2ab29ee98839874ed0bb"; };

  };

}
#endif