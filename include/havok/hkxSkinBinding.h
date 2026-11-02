// include/havok/hkxSkinBinding.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x70.
#ifndef FNV_HAVOK_HKXSKINBINDING_H
#define FNV_HAVOK_HKXSKINBINDING_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkxMesh;
#pragma pack(push, 1)
class hkxSkinBinding : public hkReferencedObject
{
  public:
    hkxMesh* m_pMesh;                                  // +0x8
    hkArray<hkStringPtr> m_kBoneNames;                 // +0xC
    hkArray<hkMatrix4> m_kBoneFromSkinMeshTransforms;  // +0x18
    char pad24[0xC];
    hkMatrix4 m_kBindPose;  // +0x30
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxSkinBinding[(sizeof(hkxSkinBinding) == 0x70) ? 1 : -1];
#endif
