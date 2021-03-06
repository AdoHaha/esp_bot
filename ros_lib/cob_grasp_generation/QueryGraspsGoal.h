#ifndef _ROS_cob_grasp_generation_QueryGraspsGoal_h
#define _ROS_cob_grasp_generation_QueryGraspsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_grasp_generation
{

  class QueryGraspsGoal : public ros::Msg
  {
    public:
      const char* object_name;
      const char* gripper_type;
      uint32_t grasp_id;
      uint32_t num_grasps;
      float threshold;

    QueryGraspsGoal():
      object_name(""),
      gripper_type(""),
      grasp_id(0),
      num_grasps(0),
      threshold(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_object_name = strlen(this->object_name);
      memcpy(outbuffer + offset, &length_object_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->object_name, length_object_name);
      offset += length_object_name;
      uint32_t length_gripper_type = strlen(this->gripper_type);
      memcpy(outbuffer + offset, &length_gripper_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->gripper_type, length_gripper_type);
      offset += length_gripper_type;
      *(outbuffer + offset + 0) = (this->grasp_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->grasp_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->grasp_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->grasp_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->grasp_id);
      *(outbuffer + offset + 0) = (this->num_grasps >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_grasps >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_grasps >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_grasps >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_grasps);
      offset += serializeAvrFloat64(outbuffer + offset, this->threshold);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_object_name;
      memcpy(&length_object_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object_name-1]=0;
      this->object_name = (char *)(inbuffer + offset-1);
      offset += length_object_name;
      uint32_t length_gripper_type;
      memcpy(&length_gripper_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gripper_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gripper_type-1]=0;
      this->gripper_type = (char *)(inbuffer + offset-1);
      offset += length_gripper_type;
      this->grasp_id =  ((uint32_t) (*(inbuffer + offset)));
      this->grasp_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->grasp_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->grasp_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->grasp_id);
      this->num_grasps =  ((uint32_t) (*(inbuffer + offset)));
      this->num_grasps |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_grasps |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_grasps |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_grasps);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->threshold));
     return offset;
    }

    const char * getType(){ return "cob_grasp_generation/QueryGraspsGoal"; };
    const char * getMD5(){ return "7674763145feb2f869f2cac4e80d0e4e"; };

  };

}
#endif