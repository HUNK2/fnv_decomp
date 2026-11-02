// include/havok/hkaWaveletCompressedAnimation.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKAWAVELETCOMPRESSEDANIMATION_H
#define FNV_HAVOK_HKAWAVELETCOMPRESSEDANIMATION_H
#include "hkBase.h"
#include "hkaAnimation.h"
#include "hkaWaveletCompressedAnimationQuantizationFormat.h"
#pragma pack(push, 1)
class hkaWaveletCompressedAnimation : public hkaAnimation
{
  public:
    hkInt32 m_iFrameCount;                                                  // +0x28
    hkInt32 m_iDofCount;                                                    // +0x2C
    hkaWaveletCompressedAnimationQuantizationFormat m_eQuantizationFormat;  // +0x30
    hkUint32 m_uiFramesPerBlock;                                            // +0x44
    hkUint32 m_uiNumBlocks;                                                 // +0x48
    hkUint32 m_uiOffsetDataOffset;                                          // +0x4C
    hkUint32 m_uiScaleDataOffset;                                           // +0x50
    hkUint32 m_uiIndexDataOffset;                                           // +0x54
    hkUint32 m_uiNumIndices;                                                // +0x58
    hkUint32 m_uiNumDynamicDofs;                                            // +0x5C
    hkUint32 m_uiNumDynamicTracks;                                          // +0x60
    hkArray<hkUint8> m_kCompressedData;                                     // +0x64
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaWaveletCompressedAnimation[(sizeof(hkaWaveletCompressedAnimation) == 0x70) ? 1 : -1];
#endif
