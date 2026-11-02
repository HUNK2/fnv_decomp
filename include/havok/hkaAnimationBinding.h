// include/havok/hkaAnimationBinding.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x2C.
#ifndef FNV_HAVOK_HKAANIMATIONBINDING_H
#define FNV_HAVOK_HKAANIMATIONBINDING_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkaAnimation;
#pragma pack(push, 1)
class hkaAnimationBinding : public hkReferencedObject
{
  public:
    enum BlendHint
    {
        NORMAL = 0,
        ADDITIVE = 1
    };
    hkStringPtr m_name;                                // +0x8
    hkaAnimation* m_pAnimation;                        // +0xC
    hkArray<hkInt16> m_kTransformTrackToBoneIndices;   // +0x10
    hkArray<hkInt16> m_kFloatTrackToFloatSlotIndices;  // +0x1C
    hkInt8 m_eBlendHint;                               // +0x28 (BlendHint)
    char pad29[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaAnimationBinding[(sizeof(hkaAnimationBinding) == 0x2C) ? 1 : -1];
#endif
