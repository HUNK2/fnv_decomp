// include/havok/hkxMeshSection.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x28.
#ifndef FNV_HAVOK_HKXMESHSECTION_H
#define FNV_HAVOK_HKXMESHSECTION_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkxIndexBuffer;
class hkxMaterial;
class hkxVertexBuffer;
#pragma pack(push, 1)
class hkxMeshSection : public hkReferencedObject
{
  public:
    hkxVertexBuffer* m_pMeshVertexBuffer;          // +0x8
    hkArray<hkxIndexBuffer*> m_kIndexBuffers;      // +0xC
    hkxMaterial* m_iMaterialIndex;                 // +0x18
    hkArray<hkReferencedObject*> m_kUserChannels;  // +0x1C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxMeshSection[(sizeof(hkxMeshSection) == 0x28) ? 1 : -1];
#endif
