// include/havok/hkaAnimation.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x28.
#ifndef FNV_HAVOK_HKAANIMATION_H
#define FNV_HAVOK_HKAANIMATION_H
#include "hkBase.h"
#include "hkReferencedObject.h"
class hkaAnimatedReferenceFrame;
class hkaAnnotationTrack;
#pragma pack(push, 1)
class hkaAnimation : public hkReferencedObject
{
  public:
    enum HavokAnimationType
    {
        HK_UNKNOWN_ANIMATION = 0,
        HK_INTERLEAVED_ANIMATION = 1,
        HK_DELTA_COMPRESSED_ANIMATION = 2,
        HK_WAVELET_COMPRESSED_ANIMATION = 3,
        HK_MIRRORED_ANIMATION = 4,
        HK_SPLINE_COMPRESSED_ANIMATION = 5
    };
    hkInt32 m_type;                                   // +0x8 (HavokAnimationType)
    hkReal m_fAnimationDuration;                      // +0xC
    hkInt32 m_iNumTransformTracks;                    // +0x10
    hkInt32 m_iNumberOfFloatTracks;                   // +0x14
    hkaAnimatedReferenceFrame* m_pExtractedMotion;    // +0x18
    hkArray<hkaAnnotationTrack> m_kAnnotationTracks;  // +0x1C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaAnimation[(sizeof(hkaAnimation) == 0x28) ? 1 : -1];
#endif
