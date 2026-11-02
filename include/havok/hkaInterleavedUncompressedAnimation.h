// include/havok/hkaInterleavedUncompressedAnimation.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKAINTERLEAVEDUNCOMPRESSEDANIMATION_H
#define FNV_HAVOK_HKAINTERLEAVEDUNCOMPRESSEDANIMATION_H

#include "hkBase.h"
#include "hkaAnimation.h"
#pragma pack(push, 1)
class hkaInterleavedUncompressedAnimation : public hkaAnimation
{
  public:
    hkArray<hkQsTransform> m_kTransforms;  // +0x28
    hkArray<hkReal> m_kFloats;             // +0x34
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkaInterleavedUncompressedAnimation[(sizeof(hkaInterleavedUncompressedAnimation) == 0x40) ? 1 : -1];
#endif
