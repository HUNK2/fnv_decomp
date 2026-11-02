// include/havok/hkxAttribute.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKXATTRIBUTE_H
#define FNV_HAVOK_HKXATTRIBUTE_H

#include "hkBase.h"
class hkReferencedObject;
#pragma pack(push, 1)
class hkxAttribute
{
  public:
    enum Hint
    {
        HINT_NONE = 0,
        HINT_IGNORE = 1,
        HINT_TRANSFORM = 2,
        HINT_SCALE = 4,
        HINT_TRANSFORM_AND_SCALE = 6,
        HINT_FLIP = 8
    };
    hkStringPtr m_name;                   // +0x0
    hkReferencedObject* m_uiFilterValue;  // +0x4
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxAttribute[(sizeof(hkxAttribute) == 0x8) ? 1 : -1];
#endif
