// include/havok/hkaWaveletCompressedAnimationCompressionParams.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x24.
#ifndef FNV_HAVOK_HKAWAVELETCOMPRESSEDANIMATIONCOMPRESSIONPARAMS_H
#define FNV_HAVOK_HKAWAVELETCOMPRESSEDANIMATIONCOMPRESSIONPARAMS_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkaWaveletCompressedAnimationCompressionParams
{
  public:
    hkUint16 m_iQuantizationBits;  // +0x0
    hkUint16 m_iDofCount;          // +0x2
    hkUint16 m_iBlockSize;         // +0x4
    char pad6[0x2];
    hkReal m_fTranslationTolerance;  // +0x8
    hkBool m_bPreserve;              // +0xC
    char padD[0x3];
    hkReal m_fStaticTrackTolerance;   // +0x10
    hkReal m_fFloatTolerance;         // +0x14
    hkReal m_fRotationTolerance;      // +0x18
    hkReal m_fScaleTolerance;         // +0x1C
    hkReal m_fQuantizationTolerance;  // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaWaveletCompressedAnimationCompressionParams
    [(sizeof(hkaWaveletCompressedAnimationCompressionParams) == 0x24) ? 1 : -1];
#endif
