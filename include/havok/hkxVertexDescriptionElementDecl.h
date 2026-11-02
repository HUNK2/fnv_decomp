// include/havok/hkxVertexDescriptionElementDecl.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKXVERTEXDESCRIPTIONELEMENTDECL_H
#define FNV_HAVOK_HKXVERTEXDESCRIPTIONELEMENTDECL_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkxVertexDescriptionElementDecl
{
  public:
    hkUint32 m_uiByteOffset;  // +0x0
    hkUint16 m_type;          // +0x4 (DataType)
    hkUint16 m_eDataUsage;    // +0x6 (DataUsage)
    hkUint32 m_uiByteStride;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxVertexDescriptionElementDecl[(sizeof(hkxVertexDescriptionElementDecl) == 0xC) ? 1 : -1];
#endif
