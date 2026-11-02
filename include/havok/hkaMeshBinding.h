// include/havok/hkaMeshBinding.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x2C.
#ifndef FNV_HAVOK_HKAMESHBINDING_H
#define FNV_HAVOK_HKAMESHBINDING_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkaMeshBindingMapping;
class hkaSkeleton;
class hkxMesh;
#pragma pack(push, 1)
class hkaMeshBinding : public hkReferencedObject
{
  public:
    hkxMesh* m_pMesh;                                    // +0x8
    hkStringPtr m_name;                                  // +0xC
    hkaSkeleton* m_pSkeleton;                            // +0x10
    hkArray<hkaMeshBindingMapping> m_kMappings;          // +0x14
    hkArray<hkTransform> m_kBoneFromSkinningTransforms;  // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaMeshBinding[(sizeof(hkaMeshBinding) == 0x2C) ? 1 : -1];
#endif
