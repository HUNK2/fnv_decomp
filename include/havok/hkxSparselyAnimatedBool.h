// include/havok/hkxSparselyAnimatedBool.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKXSPARSELYANIMATEDBOOL_H
#define FNV_HAVOK_HKXSPARSELYANIMATEDBOOL_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxSparselyAnimatedBool : public hkReferencedObject
{
  public:
    hkArray<hkBool> m_kBools;  // +0x8
    hkArray<hkReal> m_kTimes;  // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxSparselyAnimatedBool[(sizeof(hkxSparselyAnimatedBool) == 0x20) ? 1 : -1];
#endif
