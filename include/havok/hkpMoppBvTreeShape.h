// include/havok/hkpMoppBvTreeShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPMOPPBVTREESHAPE_H
#define FNV_HAVOK_HKPMOPPBVTREESHAPE_H

#include "hkBase.h"
#include "hkMoppBvTreeShapeBase.h"
#include "hkpSingleShapeContainer.h"
#pragma pack(push, 1)
class hkpMoppBvTreeShape : public hkMoppBvTreeShapeBase
{
  public:
    hkpSingleShapeContainer m_pChildAtom;  // +0x30
    hkInt32 m_iChildSize;                  // +0x38
    char pad3C[0x4];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpMoppBvTreeShape[(sizeof(hkpMoppBvTreeShape) == 0x40) ? 1 : -1];
#endif
