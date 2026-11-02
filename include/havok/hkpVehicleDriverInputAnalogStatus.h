// include/havok/hkpVehicleDriverInputAnalogStatus.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKPVEHICLEDRIVERINPUTANALOGSTATUS_H
#define FNV_HAVOK_HKPVEHICLEDRIVERINPUTANALOGSTATUS_H

#include "hkBase.h"
#include "hkpVehicleDriverInputStatus.h"
#pragma pack(push, 1)
class hkpVehicleDriverInputAnalogStatus : public hkpVehicleDriverInputStatus
{
  public:
    hkReal m_fPositionX;             // +0x8
    hkReal m_fPositionY;             // +0xC
    hkBool m_bFlag;                  // +0x10
    hkBool m_bReverseButtonPressed;  // +0x11
    char pad12[0x2];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpVehicleDriverInputAnalogStatus[(sizeof(hkpVehicleDriverInputAnalogStatus) == 0x14) ? 1 : -1];
#endif
