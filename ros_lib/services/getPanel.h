#ifndef _ROS_SERVICE_getPanel_h
#define _ROS_SERVICE_getPanel_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace services
{

static const char GETPANEL[] = "services/getPanel";

  class getPanelRequest : public ros::Msg
  {
    public:
      int8_t read;

    getPanelRequest():
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

    const char * getType(){ return GETPANEL; };
    const char * getMD5(){ return "ef817c1891fac046640fa6901dd1a58d"; };

  };

  class getPanelResponse : public ros::Msg
  {
    public:
      float panel1_x1;
      float panel1_x2;
      float panel1_y1;
      float panel1_y2;
      float panel2_x1;
      float panel2_x2;
      float panel2_y1;
      float panel2_y2;
      float panel3_x1;
      float panel3_x2;
      float panel3_y1;
      float panel3_y2;
      float panel4_x1;
      float panel4_x2;
      float panel4_y1;
      float panel4_y2;
      float panel5_x1;
      float panel5_x2;
      float panel5_y1;
      float panel5_y2;
      float panel6_x1;
      float panel6_x2;
      float panel6_y1;
      float panel6_y2;

    getPanelResponse():
      panel1_x1(0),
      panel1_x2(0),
      panel1_y1(0),
      panel1_y2(0),
      panel2_x1(0),
      panel2_x2(0),
      panel2_y1(0),
      panel2_y2(0),
      panel3_x1(0),
      panel3_x2(0),
      panel3_y1(0),
      panel3_y2(0),
      panel4_x1(0),
      panel4_x2(0),
      panel4_y1(0),
      panel4_y2(0),
      panel5_x1(0),
      panel5_x2(0),
      panel5_y1(0),
      panel5_y2(0),
      panel6_x1(0),
      panel6_x2(0),
      panel6_y1(0),
      panel6_y2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->panel1_x1);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel1_x2);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel1_y1);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel1_y2);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel2_x1);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel2_x2);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel2_y1);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel2_y2);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel3_x1);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel3_x2);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel3_y1);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel3_y2);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel4_x1);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel4_x2);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel4_y1);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel4_y2);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel5_x1);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel5_x2);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel5_y1);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel5_y2);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel6_x1);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel6_x2);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel6_y1);
      offset += serializeAvrFloat64(outbuffer + offset, this->panel6_y2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel1_x1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel1_x2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel1_y1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel1_y2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel2_x1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel2_x2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel2_y1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel2_y2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel3_x1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel3_x2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel3_y1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel3_y2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel4_x1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel4_x2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel4_y1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel4_y2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel5_x1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel5_x2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel5_y1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel5_y2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel6_x1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel6_x2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel6_y1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->panel6_y2));
     return offset;
    }

    const char * getType(){ return GETPANEL; };
    const char * getMD5(){ return "802b116cbe9b61eb3957f2ed8160a0e7"; };

  };

  class getPanel {
    public:
    typedef getPanelRequest Request;
    typedef getPanelResponse Response;
  };

}
#endif
