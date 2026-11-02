// include/havok/hkxSparselyAnimatedInt.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKXSPARSELYANIMATEDINT_H
#define FNV_HAVOK_HKXSPARSELYANIMATEDINT_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxSparselyAnimatedInt : public hkReferencedObject
{
  public:
    hkArray<hkInt32> m_auiHeaderValues;  // +0x8
    hkArray<hkReal> m_kTimes;            // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxSparselyAnimatedInt[(sizeof(hkxSparselyAnimatedInt) == 0x20) ? 1 : -1];
#endif
