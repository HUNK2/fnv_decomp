// include/havok/hkxAnimatedMatrix.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKXANIMATEDMATRIX_H
#define FNV_HAVOK_HKXANIMATEDMATRIX_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxAnimatedMatrix : public hkReferencedObject
{
  public:
    hkArray<hkMatrix4> m_kMatrices;  // +0x8
    hkUint8 m_bIsAnimated;           // +0x14 (Hint)
    char pad15[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxAnimatedMatrix[(sizeof(hkxAnimatedMatrix) == 0x18) ? 1 : -1];
#endif
