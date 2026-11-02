// include/havok/hkpSingleShapeContainer.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKPSINGLESHAPECONTAINER_H
#define FNV_HAVOK_HKPSINGLESHAPECONTAINER_H

#include "hkBase.h"
#include "hkpShapeContainer.h"
class hkpShape;
#pragma pack(push, 1)
class hkpSingleShapeContainer : public hkpShapeContainer
{
  public:
    hkpShape* m_pContainedShape;  // +0x4
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpSingleShapeContainer[(sizeof(hkpSingleShapeContainer) == 0x8) ? 1 : -1];
#endif
