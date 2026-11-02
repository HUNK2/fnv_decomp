// include/havok/hkSemanticsAttribute.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1.
#ifndef FNV_HAVOK_HKSEMANTICSATTRIBUTE_H
#define FNV_HAVOK_HKSEMANTICSATTRIBUTE_H
#include "hkBase.h"
#pragma pack(push, 1)
class hkSemanticsAttribute
{
  public:
    enum Semantics
    {
        UNKNOWN = 0,
        DISTANCE = 1,
        ANGLE = 2,
        NORMAL = 3,
        POSITION = 4
    };
    hkInt8 m_type;  // +0x0 (Semantics)
};
#pragma pack(pop)
typedef char fnv_hk_size_hkSemanticsAttribute[(sizeof(hkSemanticsAttribute) == 0x1) ? 1 : -1];
#endif
