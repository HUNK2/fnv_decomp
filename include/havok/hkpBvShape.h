// include/havok/hkpBvShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKPBVSHAPE_H
#define FNV_HAVOK_HKPBVSHAPE_H

#include "hkBase.h"
#include "hkpShape.h"
#include "hkpSingleShapeContainer.h"
#pragma pack(push, 1)
class hkpBvShape : public hkpShape
{
  public:
    hkpShape* m_pBvShapeReference;            // +0x10
    hkpSingleShapeContainer m_pContainedShape;  // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpBvShape[(sizeof(hkpBvShape) == 0x1C) ? 1 : -1];
#endif
