// include/havok/hkpListShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKPLISTSHAPE_H
#define FNV_HAVOK_HKPLISTSHAPE_H

#include "hkBase.h"
#include "hkpShapeCollection.h"
class hkpListShapeChildInfo;
#pragma pack(push, 1)
class hkpListShape : public hkpShapeCollection
{
  public:
    enum ListShapeFlags
    {
        ALL_FLAGS_CLEAR = 0,
        DISABLE_SPU_CACHE_FOR_LIST_CHILD_INFO = 1
    };
    hkArray<hkpListShapeChildInfo> m_kChildInfoList;  // +0x18
    hkUint16 m_flags;                                 // +0x24
    hkUint16 m_usNumDisabledChildren;                 // +0x26
    char pad28[0x8];
    hkVector4 m_kAabbHalfExtents;       // +0x30
    hkVector4 m_kAabbCenter;            // +0x40
    hkUint32 m_uiChildEnabledFlags[8];  // +0x50
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpListShape[(sizeof(hkpListShape) == 0x70) ? 1 : -1];
#endif
