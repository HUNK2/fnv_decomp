// include/havok/hkClassEnum.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKCLASSENUM_H
#define FNV_HAVOK_HKCLASSENUM_H

#include "hkBase_decl_hkclassenum.h"
class hkClassEnumItem;
class hkCustomAttributes;
#pragma pack(push, 1)
class hkClassEnum
{
  public:
    void FUN_00db7600(class hkStreamWriter* writer) const;  // declared for the original code (decl_variants.py)

  public:
    enum FlagValues
    {
        FLAGS_NONE = 0
    };
    char* m_name;                             // +0x0
    hkSimpleArray<hkClassEnumItem> m_items;   // +0x4
    hkCustomAttributes* m_pCustomAttributes;  // +0xC
    hkUint32 m_flags;                         // +0x10 (FlagValues)
};
#pragma pack(pop)
typedef char fnv_hk_size_hkClassEnum[(sizeof(hkClassEnum) == 0x14) ? 1 : -1];
#endif
