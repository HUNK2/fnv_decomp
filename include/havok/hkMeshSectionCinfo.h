// include/havok/hkMeshSectionCinfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKMESHSECTIONCINFO_H
#define FNV_HAVOK_HKMESHSECTIONCINFO_H

#include "hkBase.h"
class hkMeshMaterial;
class hkMeshVertexBuffer;
#pragma pack(push, 1)
class hkMeshSectionCinfo
{
  public:
    hkMeshVertexBuffer* m_pMeshVertexBuffer;  // +0x0
    hkMeshMaterial* m_iMaterialIndex;         // +0x4
    hkUint8 m_ePrimitiveType;                 // +0x8 (PrimitiveType)
    char pad9[0x3];
    hkInt32 m_iNumPrimitives;  // +0xC
    hkUint8 m_eIndexType;      // +0x10 (MeshSectionIndexType)
    char pad11[0x3];
    void* m_ppIndices;              // +0x14
    hkInt32 m_iIndexType;           // +0x18
    hkInt32 m_iSectionVertexCount;  // +0x1C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkMeshSectionCinfo[(sizeof(hkMeshSectionCinfo) == 0x20) ? 1 : -1];
#endif
