#ifndef _ROS_dlonurdf_Jamming_control_new_h
#define _ROS_dlonurdf_Jamming_control_new_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dlonurdf
{

  class Jamming_control_new : public ros::Msg
  {
    public:
      uint8_t motorPWM;
      uint8_t airPWM;
      uint8_t vacumPWM;
      uint16_t zad_press_uint16;
      uint32_t zad_press_uint32;
      uint64_t zad_press_uint64;
      int16_t zad_press_int16;
      int32_t zad_press_int32;
      int64_t zad_press_int64;
      float zad_press_float32;
      float zad_press_float64;

    Jamming_control_new():
      motorPWM(0),
      airPWM(0),
      vacumPWM(0),
      zad_press_uint16(0),
      zad_press_uint32(0),
      zad_press_uint64(0),
      zad_press_int16(0),
      zad_press_int32(0),
      zad_press_int64(0),
      zad_press_float32(0),
      zad_press_float64(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motorPWM >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motorPWM);
      *(outbuffer + offset + 0) = (this->airPWM >> (8 * 0)) & 0xFF;
      offset += sizeof(this->airPWM);
      *(outbuffer + offset + 0) = (this->vacumPWM >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vacumPWM);
      *(outbuffer + offset + 0) = (this->zad_press_uint16 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->zad_press_uint16 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->zad_press_uint16);
      *(outbuffer + offset + 0) = (this->zad_press_uint32 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->zad_press_uint32 >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->zad_press_uint32 >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->zad_press_uint32 >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zad_press_uint32);
      union {
        uint64_t real;
        uint32_t base;
      } u_zad_press_uint64;
      u_zad_press_uint64.real = this->zad_press_uint64;
      *(outbuffer + offset + 0) = (u_zad_press_uint64.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zad_press_uint64.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zad_press_uint64.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zad_press_uint64.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zad_press_uint64);
      union {
        int16_t real;
        uint16_t base;
      } u_zad_press_int16;
      u_zad_press_int16.real = this->zad_press_int16;
      *(outbuffer + offset + 0) = (u_zad_press_int16.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zad_press_int16.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->zad_press_int16);
      union {
        int32_t real;
        uint32_t base;
      } u_zad_press_int32;
      u_zad_press_int32.real = this->zad_press_int32;
      *(outbuffer + offset + 0) = (u_zad_press_int32.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zad_press_int32.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zad_press_int32.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zad_press_int32.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zad_press_int32);
      union {
        int64_t real;
        uint64_t base;
      } u_zad_press_int64;
      u_zad_press_int64.real = this->zad_press_int64;
      *(outbuffer + offset + 0) = (u_zad_press_int64.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zad_press_int64.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zad_press_int64.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zad_press_int64.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_zad_press_int64.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_zad_press_int64.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_zad_press_int64.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_zad_press_int64.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->zad_press_int64);
      union {
        float real;
        uint32_t base;
      } u_zad_press_float32;
      u_zad_press_float32.real = this->zad_press_float32;
      *(outbuffer + offset + 0) = (u_zad_press_float32.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_zad_press_float32.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_zad_press_float32.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_zad_press_float32.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->zad_press_float32);
      offset += serializeAvrFloat64(outbuffer + offset, this->zad_press_float64);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->motorPWM =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motorPWM);
      this->airPWM =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->airPWM);
      this->vacumPWM =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vacumPWM);
      this->zad_press_uint16 =  ((uint16_t) (*(inbuffer + offset)));
      this->zad_press_uint16 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->zad_press_uint16);
      this->zad_press_uint32 =  ((uint32_t) (*(inbuffer + offset)));
      this->zad_press_uint32 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->zad_press_uint32 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->zad_press_uint32 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->zad_press_uint32);
      union {
        uint64_t real;
        uint32_t base;
      } u_zad_press_uint64;
      u_zad_press_uint64.base = 0;
      u_zad_press_uint64.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zad_press_uint64.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zad_press_uint64.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zad_press_uint64.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->zad_press_uint64 = u_zad_press_uint64.real;
      offset += sizeof(this->zad_press_uint64);
      union {
        int16_t real;
        uint16_t base;
      } u_zad_press_int16;
      u_zad_press_int16.base = 0;
      u_zad_press_int16.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zad_press_int16.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->zad_press_int16 = u_zad_press_int16.real;
      offset += sizeof(this->zad_press_int16);
      union {
        int32_t real;
        uint32_t base;
      } u_zad_press_int32;
      u_zad_press_int32.base = 0;
      u_zad_press_int32.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zad_press_int32.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zad_press_int32.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zad_press_int32.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->zad_press_int32 = u_zad_press_int32.real;
      offset += sizeof(this->zad_press_int32);
      union {
        int64_t real;
        uint64_t base;
      } u_zad_press_int64;
      u_zad_press_int64.base = 0;
      u_zad_press_int64.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zad_press_int64.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zad_press_int64.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zad_press_int64.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_zad_press_int64.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_zad_press_int64.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_zad_press_int64.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_zad_press_int64.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->zad_press_int64 = u_zad_press_int64.real;
      offset += sizeof(this->zad_press_int64);
      union {
        float real;
        uint32_t base;
      } u_zad_press_float32;
      u_zad_press_float32.base = 0;
      u_zad_press_float32.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_zad_press_float32.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_zad_press_float32.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_zad_press_float32.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->zad_press_float32 = u_zad_press_float32.real;
      offset += sizeof(this->zad_press_float32);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->zad_press_float64));
     return offset;
    }

    const char * getType(){ return "dlonurdf/Jamming_control_new"; };
    const char * getMD5(){ return "575df77d5f6a2c10a554cc34496505b7"; };

  };

}
#endif