// include/havok/hkpConvexTransformShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x60.
#ifndef FNV_HAVOK_HKPCONVEXTRANSFORMSHAPE_H
#define FNV_HAVOK_HKPCONVEXTRANSFORMSHAPE_H

#include "hkBase.h"
#include "hkpConvexTransformShapeBase.h"
#pragma pack(push, 1)
class hkpConvexTransformShape : public hkpConvexTransformShapeBase
{
  public:
    hkTransform m_kMotionTransform;  // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConvexTransformShape[(sizeof(hkpConvexTransformShape) == 0x60) ? 1 : -1];
#endif
