// include/havok/hkpCompressedMeshShapeChunk.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPCOMPRESSEDMESHSHAPECHUNK_H
#define FNV_HAVOK_HKPCOMPRESSEDMESHSHAPECHUNK_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpCompressedMeshShapeChunk
{
  public:
    hkVector4 m_offset;                 // +0x0
    hkArray<hkUint16> m_kVertices;      // +0x10
    hkArray<hkUint16> m_ppIndices;      // +0x1C
    hkArray<hkUint16> m_pStripIndices;  // +0x28
    hkArray<hkUint16> m_kWeldingInfo;   // +0x34
    hkUint32 m_uiReference;             // +0x40
    hkUint16 m_kSmartReference;         // +0x44
    hkUint16 m_iSectionVertexCount;     // +0x46
    char pad48[0x8];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCompressedMeshShapeChunk[(sizeof(hkpCompressedMeshShapeChunk) == 0x50) ? 1 : -1];
#endif
