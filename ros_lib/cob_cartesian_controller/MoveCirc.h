#ifndef _ROS_cob_cartesian_controller_MoveCirc_h
#define _ROS_cob_cartesian_controller_MoveCirc_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "cob_cartesian_controller/Profile.h"

namespace cob_cartesian_controller
{

  class MoveCirc : public ros::Msg
  {
    public:
      geometry_msgs::Pose pose_center;
      const char* frame_id;
      float start_angle;
      float end_angle;
      float radius;
      bool rotate_only;
      cob_cartesian_controller::Profile profile;

    MoveCirc():
      pose_center(),
      frame_id(""),
      start_angle(0),
      end_angle(0),
      radius(0),
      rotate_only(0),
      profile()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose_center.serialize(outbuffer + offset);
      uint32_t length_frame_id = strlen(this->frame_id);
      memcpy(outbuffer + offset, &length_frame_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      offset += serializeAvrFloat64(outbuffer + offset, this->start_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->end_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->radius);
      union {
        bool real;
        uint8_t base;
      } u_rotate_only;
      u_rotate_only.real = this->rotate_only;
      *(outbuffer + offset + 0) = (u_rotate_only.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rotate_only);
      offset += this->profile.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->pose_center.deserialize(inbuffer + offset);
      uint32_t length_frame_id;
      memcpy(&length_frame_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->start_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->end_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->radius));
      union {
        bool real;
        uint8_t base;
      } u_rotate_only;
      u_rotate_only.base = 0;
      u_rotate_only.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rotate_only = u_rotate_only.real;
      offset += sizeof(this->rotate_only);
      offset += this->profile.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "cob_cartesian_controller/MoveCirc"; };
    const char * getMD5(){ return "e8ef6f508c489caab831e3996bca18a9"; };

  };

}
#endif