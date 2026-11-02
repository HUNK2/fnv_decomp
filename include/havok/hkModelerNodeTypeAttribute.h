// include/havok/hkModelerNodeTypeAttribute.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1.
#ifndef FNV_HAVOK_HKMODELERNODETYPEATTRIBUTE_H
#define FNV_HAVOK_HKMODELERNODETYPEATTRIBUTE_H
#include "hkBase.h"
#pragma pack(push, 1)
class hkModelerNodeTypeAttribute
{
  public:
    enum ModelerType
    {
        DEFAULT = 0,
        LOCATOR = 1
    };
    hkInt8 m_type;  // +0x0 (ModelerType)
};
#pragma pack(pop)
typedef char fnv_hk_size_hkModelerNodeTypeAttribute[(sizeof(hkModelerNodeTypeAttribute) == 0x1) ? 1 : -1];
#endif
