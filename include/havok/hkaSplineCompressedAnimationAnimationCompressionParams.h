// include/havok/hkaSplineCompressedAnimationAnimationCompressionParams.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x4.
#ifndef FNV_HAVOK_HKASPLINECOMPRESSEDANIMATIONANIMATIONCOMPRESSIONPARAMS_H
#define FNV_HAVOK_HKASPLINECOMPRESSEDANIMATIONANIMATIONCOMPRESSIONPARAMS_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkaSplineCompressedAnimationAnimationCompressionParams
{
  public:
    hkUint16 m_iMaxFramesPerBlock;       // +0x0
    hkBool m_bEnableSampleSingleTracks;  // +0x2
    char pad3[0x1];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaSplineCompressedAnimationAnimationCompressionParams
    [(sizeof(hkaSplineCompressedAnimationAnimationCompressionParams) == 0x4) ? 1 : -1];
#endif
