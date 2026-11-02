// include/havok/hkpCollidableBoundingVolumeData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x2C.
#ifndef FNV_HAVOK_HKPCOLLIDABLEBOUNDINGVOLUMEDATA_H
#define FNV_HAVOK_HKPCOLLIDABLEBOUNDINGVOLUMEDATA_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpCollidableBoundingVolumeData
{
  public:
    hkUint32 m_kMinimumCorner[3];          // +0x0
    hkUint8 m_ucExpansionMin[3];           // +0xC
    hkUint8 m_ucExpansionShift;            // +0xF
    hkUint32 m_kMaximumCorner[3];          // +0x10
    hkUint8 m_ucExpansionMax[3];           // +0x1C
    hkUint8 m_ucUnknownByte;               // +0x1F
    hkUint16 m_uiNumChildShapeAabbs;       // +0x20
    hkUint16 m_uiCapacityChildShapeAabbs;  // +0x22
    void* m_pChildShapeAabbs;              // +0x24
    void* m_pChildShapeKeys;               // +0x28
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCollidableBoundingVolumeData[(sizeof(hkpCollidableBoundingVolumeData) == 0x2C) ? 1 : -1];
#endif
