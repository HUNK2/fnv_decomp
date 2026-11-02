// include/havok/hkpConvexTransformShapeBase.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPCONVEXTRANSFORMSHAPEBASE_H
#define FNV_HAVOK_HKPCONVEXTRANSFORMSHAPEBASE_H

#include "hkBase.h"
#include "hkpConvexShape.h"
#include "hkpSingleShapeContainer.h"
#pragma pack(push, 1)
class hkpConvexTransformShapeBase : public hkpConvexShape
{
  public:
    hkpSingleShapeContainer m_pContainedShape;  // +0x14
    hkInt32 m_iChildShapeSize;                  // +0x1C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConvexTransformShapeBase[(sizeof(hkpConvexTransformShapeBase) == 0x20) ? 1 : -1];
#endif
