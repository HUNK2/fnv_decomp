// include/havok/hkaSkeleton.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x48.
#ifndef FNV_HAVOK_HKASKELETON_H
#define FNV_HAVOK_HKASKELETON_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkaBone;
class hkaSkeletonLocalFrameOnBone;
#pragma pack(push, 1)
class hkaSkeleton : public hkReferencedObject
{
  public:
    hkStringPtr m_name;                                   // +0x8
    hkArray<hkInt16> m_kParentIndices;                    // +0xC
    hkArray<hkaBone> m_kBones;                            // +0x18
    hkArray<hkQsTransform> m_kReferencePose;              // +0x24
    hkArray<hkStringPtr> m_kBoneNames;                    // +0x30
    hkArray<hkaSkeletonLocalFrameOnBone> m_kLocalFrames;  // +0x3C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaSkeleton[(sizeof(hkaSkeleton) == 0x48) ? 1 : -1];
#endif
