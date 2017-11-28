#ifndef _ROS_dlonurdf_Rekawica_filtered_h
#define _ROS_dlonurdf_Rekawica_filtered_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dlonurdf
{

  class Rekawica_filtered : public ros::Msg
  {
    public:
      float kciuk0;
      float kciuk1;
      float palwska0;
      float palwska1;
      float palsro0;
      float palsro1;
      float palser0;
      float palser1;
      float palmal0;
      float palmal1;
      float czujkciuk;
      float czujwska;
      float czujsro;
      float czujser;
      float czujmal;
      float czujdlo;

    Rekawica_filtered():
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
      offset += serializeAvrFloat64(outbuffer + offset, this->kciuk0);
      offset += serializeAvrFloat64(outbuffer + offset, this->kciuk1);
      offset += serializeAvrFloat64(outbuffer + offset, this->palwska0);
      offset += serializeAvrFloat64(outbuffer + offset, this->palwska1);
      offset += serializeAvrFloat64(outbuffer + offset, this->palsro0);
      offset += serializeAvrFloat64(outbuffer + offset, this->palsro1);
      offset += serializeAvrFloat64(outbuffer + offset, this->palser0);
      offset += serializeAvrFloat64(outbuffer + offset, this->palser1);
      offset += serializeAvrFloat64(outbuffer + offset, this->palmal0);
      offset += serializeAvrFloat64(outbuffer + offset, this->palmal1);
      offset += serializeAvrFloat64(outbuffer + offset, this->czujkciuk);
      offset += serializeAvrFloat64(outbuffer + offset, this->czujwska);
      offset += serializeAvrFloat64(outbuffer + offset, this->czujsro);
      offset += serializeAvrFloat64(outbuffer + offset, this->czujser);
      offset += serializeAvrFloat64(outbuffer + offset, this->czujmal);
      offset += serializeAvrFloat64(outbuffer + offset, this->czujdlo);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->kciuk0));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->kciuk1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palwska0));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palwska1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palsro0));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palsro1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palser0));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palser1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palmal0));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palmal1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->czujkciuk));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->czujwska));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->czujsro));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->czujser));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->czujmal));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->czujdlo));
     return offset;
    }

    const char * getType(){ return "dlonurdf/Rekawica_filtered"; };
    const char * getMD5(){ return "d406493beed9d0a8cfcd5b5126c83ef8"; };

  };

}
#endif