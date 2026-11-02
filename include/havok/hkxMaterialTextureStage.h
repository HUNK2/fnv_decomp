// include/havok/hkxMaterialTextureStage.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKXMATERIALTEXTURESTAGE_H
#define FNV_HAVOK_HKXMATERIALTEXTURESTAGE_H

#include "hkBase.h"
class hkReferencedObject;
#pragma pack(push, 1)
class hkxMaterialTextureStage
{
  public:
    hkReferencedObject* m_texture;  // +0x0
    hkInt32 m_iTcoordChannel;       // +0x4 (TextureType)
    hkInt32 m_iUsageHint;           // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxMaterialTextureStage[(sizeof(hkxMaterialTextureStage) == 0xC) ? 1 : -1];
#endif
