// include/havok/hkpShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKPSHAPE_H
#define FNV_HAVOK_HKPSHAPE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkpShape : public hkReferencedObject
{
  public:
    hkUlong m_ulUserData;  // +0x8
    hkUint32 m_type;       // +0xC
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpShape[(sizeof(hkpShape) == 0x10) ? 1 : -1];
#endif
