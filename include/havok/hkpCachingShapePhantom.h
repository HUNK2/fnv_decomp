// include/havok/hkpCachingShapePhantom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x170.
#ifndef FNV_HAVOK_HKPCACHINGSHAPEPHANTOM_H
#define FNV_HAVOK_HKPCACHINGSHAPEPHANTOM_H

#include "hkBase.h"
#include "hkpShapePhantom.h"
#pragma pack(push, 1)
class hkpCachingShapePhantom : public hkpShapePhantom
{
  public:
    hkArray<char> m_kCollisionDetails;  // +0x160
    hkBool m_bOrderDirty;               // +0x16C
    char pad16D[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCachingShapePhantom[(sizeof(hkpCachingShapePhantom) == 0x170) ? 1 : -1];
#endif
