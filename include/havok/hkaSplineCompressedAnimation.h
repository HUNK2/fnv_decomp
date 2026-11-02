// include/havok/hkaSplineCompressedAnimation.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x84.
#ifndef FNV_HAVOK_HKASPLINECOMPRESSEDANIMATION_H
#define FNV_HAVOK_HKASPLINECOMPRESSEDANIMATION_H

#include "hkBase.h"
#include "hkaAnimation.h"
#pragma pack(push, 1)
class hkaSplineCompressedAnimation : public hkaAnimation
{
  public:
    hkInt32 m_iFrameCount;                   // +0x28
    hkInt32 m_iBlockCount;                   // +0x2C
    hkInt32 m_iMaxFramesPerBlock;            // +0x30
    hkInt32 m_iMaskAndQuantizationSize;      // +0x34
    hkReal m_fBlockDuration;                 // +0x38
    hkReal m_fBlockInverseDuration;          // +0x3C
    hkReal m_fPerFrameDuration;              // +0x40
    hkArray<hkUint32> m_kFirstUInt32Array;   // +0x44
    hkArray<hkUint32> m_kFloatBlockOffsets;  // +0x50
    hkArray<hkUint32> m_kTransformOffsets;   // +0x5C
    hkArray<hkUint32> m_kFloatOffsets;       // +0x68
    hkArray<hkUint8> m_data;                 // +0x74
    hkInt32 m_iEndian;                       // +0x80
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaSplineCompressedAnimation[(sizeof(hkaSplineCompressedAnimation) == 0x84) ? 1 : -1];
#endif
