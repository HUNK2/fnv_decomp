// include/havok/hkaSplineCompressedAnimationTrackCompressionParams.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKASPLINECOMPRESSEDANIMATIONTRACKCOMPRESSIONPARAMS_H
#define FNV_HAVOK_HKASPLINECOMPRESSEDANIMATIONTRACKCOMPRESSIONPARAMS_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkaSplineCompressedAnimationTrackCompressionParams
{
  public:
    enum RotationQuantization
    {
        POLAR32 = 0,
        THREECOMP40 = 1,
        THREECOMP48 = 2,
        THREECOMP24 = 3,
        STRAIGHT16 = 4,
        UNCOMPRESSED = 5
    };
    enum ScalarQuantization
    {
        BITS8 = 0,
        BITS16 = 1
    };
    hkReal m_fRotationTolerance;             // +0x0
    hkReal m_fTranslationTolerance;          // +0x4
    hkReal m_fScaleTolerance;                // +0x8
    hkReal m_fFloatingTolerance;             // +0xC
    hkUint16 m_iRotationDegree;              // +0x10
    hkUint16 m_iTranslationDegree;           // +0x12
    hkUint16 m_iScaleDegree;                 // +0x14
    hkUint16 m_iFloatingDegree;              // +0x16
    hkUint8 m_eRotationQuantizationType;     // +0x18 (RotationQuantization)
    hkUint8 m_eTranslationQuantizationType;  // +0x19 (ScalarQuantization)
    hkUint8 m_eScaleQuantizationType;        // +0x1A (ScalarQuantization)
    hkUint8 m_eFloatQuantizationType;        // +0x1B (ScalarQuantization)
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaSplineCompressedAnimationTrackCompressionParams
    [(sizeof(hkaSplineCompressedAnimationTrackCompressionParams) == 0x1C) ? 1 : -1];
#endif
