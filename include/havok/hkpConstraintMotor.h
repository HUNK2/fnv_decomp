// include/havok/hkpConstraintMotor.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKPCONSTRAINTMOTOR_H
#define FNV_HAVOK_HKPCONSTRAINTMOTOR_H
#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkpConstraintMotor : public hkReferencedObject
{
  public:
    enum MotorType
    {
        TYPE_INVALID = 0,
        TYPE_POSITION = 1,
        TYPE_VELOCITY = 2,
        TYPE_SPRING_DAMPER = 3,
        TYPE_CALLBACK = 4,
        TYPE_MAX = 5
    };
    hkInt8 m_type;  // +0x8 (MotorType)
    char pad9[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConstraintMotor[(sizeof(hkpConstraintMotor) == 0xC) ? 1 : -1];
#endif
