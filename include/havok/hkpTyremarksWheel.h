// include/havok/hkpTyremarksWheel.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKPTYREMARKSWHEEL_H
#define FNV_HAVOK_HKPTYREMARKSWHEEL_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpTyremarkPoint;
#pragma pack(push, 1)
class hkpTyremarksWheel : public hkReferencedObject
{
  public:
    hkInt32 m_iCurrentTyremarkIndex;              // +0x8
    hkInt32 m_iPointCount;                        // +0xC
    hkArray<hkpTyremarkPoint> m_kTyremarkPoints;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpTyremarksWheel[(sizeof(hkpTyremarksWheel) == 0x1C) ? 1 : -1];
#endif
