// include/havok/hkxAnimatedVector.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKXANIMATEDVECTOR_H
#define FNV_HAVOK_HKXANIMATEDVECTOR_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxAnimatedVector : public hkReferencedObject
{
  public:
    hkArray<hkVector4> m_kShapeVectorData;  // +0x8
    hkUint8 m_bIsAnimated;         // +0x14 (Hint)
    char pad15[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxAnimatedVector[(sizeof(hkxAnimatedVector) == 0x18) ? 1 : -1];
#endif
