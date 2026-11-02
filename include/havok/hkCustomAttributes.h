// include/havok/hkCustomAttributes.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKCUSTOMATTRIBUTES_H
#define FNV_HAVOK_HKCUSTOMATTRIBUTES_H

#include "hkBase.h"
class hkCustomAttributesAttribute;
#pragma pack(push, 1)
class hkCustomAttributes
{
  public:
    hkSimpleArray<hkCustomAttributesAttribute> m_pCustomAttributes;  // +0x0
};
#pragma pack(pop)
typedef char fnv_hk_size_hkCustomAttributes[(sizeof(hkCustomAttributes) == 0x8) ? 1 : -1];
#endif
