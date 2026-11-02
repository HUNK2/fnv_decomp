// include/havok/hkpSimpleShapePhantom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x170.
#ifndef FNV_HAVOK_HKPSIMPLESHAPEPHANTOM_H
#define FNV_HAVOK_HKPSIMPLESHAPEPHANTOM_H

#include "hkBase.h"
#include "hkpShapePhantom.h"
class hkpSimpleShapePhantomCollisionDetail;
#pragma pack(push, 1)
class hkpSimpleShapePhantom : public hkpShapePhantom
{
  public:
    hkArray<hkpSimpleShapePhantomCollisionDetail> m_kCollisionDetails;  // +0x160
    hkBool m_bOrderDirty;                                               // +0x16C
    char pad16D[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpSimpleShapePhantom[(sizeof(hkpSimpleShapePhantom) == 0x170) ? 1 : -1];
#endif
