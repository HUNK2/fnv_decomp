// include/havok/hkpAabbPhantom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xE0.
#ifndef FNV_HAVOK_HKPAABBPHANTOM_H
#define FNV_HAVOK_HKPAABBPHANTOM_H

#include "hkBase.h"
#include "hkAabb.h"
#include "hkpPhantom.h"
#pragma pack(push, 1)
class hkpAabbPhantom : public hkpPhantom
{
  public:
    char padA4[0xC];
    hkAabb m_kBounds;                           // +0xB0
    hkArray<void*> m_ppOverlappingCollidables;  // +0xD0
    hkBool m_bOrderDirty;                       // +0xDC
    char padDD[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpAabbPhantom[(sizeof(hkpAabbPhantom) == 0xE0) ? 1 : -1];
#endif
