// include/havok/hkxAttributeGroup.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKXATTRIBUTEGROUP_H
#define FNV_HAVOK_HKXATTRIBUTEGROUP_H

#include "hkBase.h"
class hkxAttribute;
#pragma pack(push, 1)
class hkxAttributeGroup
{
  public:
    hkStringPtr m_name;                         // +0x0
    hkArray<hkxAttribute> m_pCustomAttributes;  // +0x4
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxAttributeGroup[(sizeof(hkxAttributeGroup) == 0x10) ? 1 : -1];
#endif
