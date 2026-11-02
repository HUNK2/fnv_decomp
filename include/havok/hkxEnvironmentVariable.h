// include/havok/hkxEnvironmentVariable.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKXENVIRONMENTVARIABLE_H
#define FNV_HAVOK_HKXENVIRONMENTVARIABLE_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkxEnvironmentVariable
{
  public:
    hkStringPtr m_name;           // +0x0
    hkStringPtr m_uiFilterValue;  // +0x4
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxEnvironmentVariable[(sizeof(hkxEnvironmentVariable) == 0x8) ? 1 : -1];
#endif
