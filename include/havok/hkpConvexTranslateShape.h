// include/havok/hkpConvexTranslateShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPCONVEXTRANSLATESHAPE_H
#define FNV_HAVOK_HKPCONVEXTRANSLATESHAPE_H

#include "hkBase.h"
#include "hkpConvexTransformShapeBase.h"
#pragma pack(push, 1)
class hkpConvexTranslateShape : public hkpConvexTransformShapeBase
{
  public:
    hkVector4 m_vTranslation;  // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConvexTranslateShape[(sizeof(hkpConvexTranslateShape) == 0x30) ? 1 : -1];
#endif
