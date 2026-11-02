// include/havok/hkpMassProperties.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPMASSPROPERTIES_H
#define FNV_HAVOK_HKPMASSPROPERTIES_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpMassProperties
{
  public:
    hkReal m_iBufferSize;         // +0x0
    hkReal m_fViscosityFriction;  // +0x4
    char pad8[0x8];
    hkVector4 m_kCenterOfMass1;  // +0x10
    hkMatrix3 m_kInertiaTensor;  // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpMassProperties[(sizeof(hkpMassProperties) == 0x50) ? 1 : -1];
#endif
