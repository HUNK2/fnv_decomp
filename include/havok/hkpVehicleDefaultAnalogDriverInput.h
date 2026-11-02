// include/havok/hkpVehicleDefaultAnalogDriverInput.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKPVEHICLEDEFAULTANALOGDRIVERINPUT_H
#define FNV_HAVOK_HKPVEHICLEDEFAULTANALOGDRIVERINPUT_H

#include "hkBase.h"
#include "hkpVehicleDriverInput.h"
#pragma pack(push, 1)
class hkpVehicleDefaultAnalogDriverInput : public hkpVehicleDriverInput
{
  public:
    hkReal m_fSlopeUp;      // +0x8
    hkReal m_fDeadZone;     // +0xC
    hkReal m_fSlopeDown;    // +0x10
    hkBool m_bAutoReverse;  // +0x14
    char pad15[0x3];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpVehicleDefaultAnalogDriverInput[(sizeof(hkpVehicleDefaultAnalogDriverInput) == 0x18) ? 1 : -1];
#endif
