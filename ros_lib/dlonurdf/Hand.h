#ifndef _ROS_dlonurdf_Hand_h
#define _ROS_dlonurdf_Hand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dlonurdf
{

  class Hand : public ros::Msg
  {
    public:
      float palec0pods;
      float palec0sro;
      float palec0kon;
      float palec1pods;
      float palec1sro;
      float palec1kon;
      float palec2pods;
      float palec2sro;
      float palec2kon;

    Hand():
      palec0pods(0),
      palec0sro(0),
      palec0kon(0),
      palec1pods(0),
      palec1sro(0),
      palec1kon(0),
      palec2pods(0),
      palec2sro(0),
      palec2kon(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->palec0pods);
      offset += serializeAvrFloat64(outbuffer + offset, this->palec0sro);
      offset += serializeAvrFloat64(outbuffer + offset, this->palec0kon);
      offset += serializeAvrFloat64(outbuffer + offset, this->palec1pods);
      offset += serializeAvrFloat64(outbuffer + offset, this->palec1sro);
      offset += serializeAvrFloat64(outbuffer + offset, this->palec1kon);
      offset += serializeAvrFloat64(outbuffer + offset, this->palec2pods);
      offset += serializeAvrFloat64(outbuffer + offset, this->palec2sro);
      offset += serializeAvrFloat64(outbuffer + offset, this->palec2kon);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palec0pods));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palec0sro));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palec0kon));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palec1pods));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palec1sro));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palec1kon));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palec2pods));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palec2sro));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->palec2kon));
     return offset;
    }

    const char * getType(){ return "dlonurdf/Hand"; };
    const char * getMD5(){ return "1523ed4da084b30aa475e0cc9af56843"; };

  };

}
#endif