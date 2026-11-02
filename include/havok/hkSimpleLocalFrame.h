// include/havok/hkSimpleLocalFrame.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKSIMPLELOCALFRAME_H
#define FNV_HAVOK_HKSIMPLELOCALFRAME_H

#include "hkBase.h"
#include "hkLocalFrame.h"
class hkLocalFrameGroup;
#pragma pack(push, 1)
class hkSimpleLocalFrame : public hkLocalFrame
{
  public:
    char pad8[0x8];
    hkTransform m_kMotionTransform;     // +0x10
    hkArray<hkLocalFrame*> m_children;  // +0x50
    hkLocalFrame* m_pParentFrame;       // +0x5C
    hkLocalFrameGroup* m_kGroupData;    // +0x60
    hkStringPtr m_name;                 // +0x64
    char pad68[0x8];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkSimpleLocalFrame[(sizeof(hkSimpleLocalFrame) == 0x70) ? 1 : -1];
#endif
