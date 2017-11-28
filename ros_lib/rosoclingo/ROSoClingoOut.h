#ifndef _ROS_rosoclingo_ROSoClingoOut_h
#define _ROS_rosoclingo_ROSoClingoOut_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosoclingo
{

  class ROSoClingoOut : public ros::Msg
  {
    public:
      const char* id;
      const char* action;

    ROSoClingoOut():
      id(""),
      action("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      memcpy(outbuffer + offset, &length_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      uint32_t length_action = strlen(this->action);
      memcpy(outbuffer + offset, &length_action, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->action, length_action);
      offset += length_action;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      memcpy(&length_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint32_t length_action;
      memcpy(&length_action, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_action; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_action-1]=0;
      this->action = (char *)(inbuffer + offset-1);
      offset += length_action;
     return offset;
    }

    const char * getType(){ return "rosoclingo/ROSoClingoOut"; };
    const char * getMD5(){ return "9a51ce6280ae95d37f544ff777ac99c9"; };

  };

}
#endif