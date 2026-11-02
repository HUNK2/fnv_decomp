// include/havok/hkxMaterialShaderSet.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKXMATERIALSHADERSET_H
#define FNV_HAVOK_HKXMATERIALSHADERSET_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkxMaterialShader;
#pragma pack(push, 1)
class hkxMaterialShaderSet : public hkReferencedObject
{
  public:
    hkArray<hkxMaterialShader*> m_spPixelShaders;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxMaterialShaderSet[(sizeof(hkxMaterialShaderSet) == 0x14) ? 1 : -1];
#endif
