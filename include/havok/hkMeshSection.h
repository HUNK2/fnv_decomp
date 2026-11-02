// include/havok/hkMeshSection.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x28.
#ifndef FNV_HAVOK_HKMESHSECTION_H
#define FNV_HAVOK_HKMESHSECTION_H

#include "hkBase.h"
class hkMeshMaterial;
class hkMeshVertexBuffer;
#pragma pack(push, 1)
class hkMeshSection
{
  public:
    enum MeshSectionIndexType
    {
        INDEX_TYPE_NONE = 0,
        INDEX_TYPE_UINT16 = 1,
        INDEX_TYPE_UINT32 = 2
    };
    enum PrimitiveType
    {
        PRIMITIVE_TYPE_UNKNOWN = 0,
        PRIMITIVE_TYPE_POINT_LIST = 1,
        PRIMITIVE_TYPE_LINE_LIST = 2,
        PRIMITIVE_TYPE_TRIANGLE_LIST = 3,
        PRIMITIVE_TYPE_TRIANGLE_STRIP = 4
    };
    hkUint8 m_ePrimitiveType;  // +0x0 (PrimitiveType)
    char pad1[0x3];
    hkInt32 m_iNumPrimitives;       // +0x4
    hkInt32 m_iIndexCount;          // +0x8
    hkInt32 m_iIndexType;           // +0xC
    hkInt32 m_iSectionVertexCount;  // +0x10
    hkUint8 m_eIndexType;           // +0x14 (MeshSectionIndexType)
    char pad15[0x3];
    void* m_ppIndices;                        // +0x18
    hkMeshVertexBuffer* m_pMeshVertexBuffer;  // +0x1C
    hkMeshMaterial* m_iMaterialIndex;         // +0x20
    hkInt32 m_iVertexOffset;                  // +0x24
};
#pragma pack(pop)
typedef char fnv_hk_size_hkMeshSection[(sizeof(hkMeshSection) == 0x28) ? 1 : -1];
#endif
