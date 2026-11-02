// include/havok/hkpVehicleFrictionDescriptionAxisDescription.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x64.
#ifndef FNV_HAVOK_HKPVEHICLEFRICTIONDESCRIPTIONAXISDESCRIPTION_H
#define FNV_HAVOK_HKPVEHICLEFRICTIONDESCRIPTIONAXISDESCRIPTION_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpVehicleFrictionDescriptionAxisDescription
{
  public:
    hkReal m_afFrictionCurveSamples[16];  // +0x0
    hkReal m_fAxisFrictionTuning1;        // +0x40
    hkReal m_fAxisFrictionTuning2;        // +0x44
    hkReal m_fAxisFrictionTuning3;        // +0x48
    hkReal m_fAxisFrictionTuning4;        // +0x4C
    hkReal m_fAxisFrictionTuning5;        // +0x50
    hkReal m_fAxisFrictionTuning6;        // +0x54
    hkReal m_fAxisFrictionTuning7;        // +0x58
    hkReal m_fAxisFrictionTuning8;        // +0x5C
    hkReal m_fAxisFrictionTuning9;        // +0x60
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpVehicleFrictionDescriptionAxisDescription
    [(sizeof(hkpVehicleFrictionDescriptionAxisDescription) == 0x64) ? 1 : -1];
#endif
