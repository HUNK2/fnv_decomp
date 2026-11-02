// include/havok/hkpVehicleWheelCollide.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKPVEHICLEWHEELCOLLIDE_H
#define FNV_HAVOK_HKPVEHICLEWHEELCOLLIDE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkpVehicleWheelCollide : public hkReferencedObject
{
  public:
    enum WheelCollideType
    {
        INVALID_WHEEL_COLLIDE = 0,
        RAY_CAST_WHEEL_COLLIDE = 1,
        LINEAR_CAST_WHEEL_COLLIDE = 2,
        USER_WHEEL_COLLIDE1 = 3,
        USER_WHEEL_COLLIDE2 = 4,
        USER_WHEEL_COLLIDE3 = 5,
        USER_WHEEL_COLLIDE4 = 6,
        USER_WHEEL_COLLIDE5 = 7
    };
    hkBool m_bWheelCollisionEnabled;  // +0x8
    hkUint8 m_type;                   // +0x9
    char padA[0x2];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleWheelCollide[(sizeof(hkpVehicleWheelCollide) == 0xC) ? 1 : -1];
#endif
