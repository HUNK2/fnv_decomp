// include/havok/hkpTransformShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKPTRANSFORMSHAPE_H
#define FNV_HAVOK_HKPTRANSFORMSHAPE_H

#include "hkBase.h"
#include "hkpShape.h"
#include "hkpSingleShapeContainer.h"
#pragma pack(push, 1)
class hkpTransformShape : public hkpShape
{
  public:
    hkpSingleShapeContainer m_pContainedShape;  // +0x10
    hkInt32 m_iChildShapeSize;                  // +0x18
    char pad1C[0x4];
    hkQuaternion m_rotation;         // +0x20
    hkTransform m_kMotionTransform;  // +0x30
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpTransformShape[(sizeof(hkpTransformShape) == 0x70) ? 1 : -1];
#endif
