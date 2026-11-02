// include/havok/hkLinkAttribute.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1.
#ifndef FNV_HAVOK_HKLINKATTRIBUTE_H
#define FNV_HAVOK_HKLINKATTRIBUTE_H
#include "hkBase.h"
#pragma pack(push, 1)
class hkLinkAttribute
{
  public:
    enum Link
    {
        NONE = 0,
        DIRECT_LINK = 1,
        CHILD = 2,
        MESH = 3,
        PARENT_NAME = 4
    };
    hkInt8 m_type;  // +0x0 (Link)
};
#pragma pack(pop)
typedef char fnv_hk_size_hkLinkAttribute[(sizeof(hkLinkAttribute) == 0x1) ? 1 : -1];
#endif
