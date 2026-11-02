// include/havok/hkpNamedMeshMaterial.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKPNAMEDMESHMATERIAL_H
#define FNV_HAVOK_HKPNAMEDMESHMATERIAL_H
#include "hkBase.h"
#include "hkpMeshMaterial.h"
#pragma pack(push, 1)
class hkpNamedMeshMaterial : public hkpMeshMaterial
{
  public:
    hkStringPtr m_name;  // +0x4
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpNamedMeshMaterial[(sizeof(hkpNamedMeshMaterial) == 0x8) ? 1 : -1];
#endif
