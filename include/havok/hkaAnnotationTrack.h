// include/havok/hkaAnnotationTrack.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKAANNOTATIONTRACK_H
#define FNV_HAVOK_HKAANNOTATIONTRACK_H

#include "hkBase.h"
class hkaAnnotationTrackAnnotation;
#pragma pack(push, 1)
class hkaAnnotationTrack
{
  public:
    hkStringPtr m_kTrackName;                              // +0x0
    hkArray<hkaAnnotationTrackAnnotation> m_kAnnotations;  // +0x4
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaAnnotationTrack[(sizeof(hkaAnnotationTrack) == 0x10) ? 1 : -1];
#endif
