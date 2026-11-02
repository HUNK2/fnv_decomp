// include/havok/hkxVertexBufferVertexData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x54.
#ifndef FNV_HAVOK_HKXVERTEXBUFFERVERTEXDATA_H
#define FNV_HAVOK_HKXVERTEXBUFFERVERTEXDATA_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkxVertexBufferVertexData
{
  public:
    hkArray<hkVector4> m_kVectorData;  // +0x0
    hkArray<hkReal> m_kFloatData;      // +0xC
    hkArray<hkUint32> m_kUInt32Data;   // +0x18
    hkArray<hkUint16> m_kUInt16Data;   // +0x24
    hkArray<hkUint8> m_kUInt8Data;     // +0x30
    hkUint32 m_uiVertexCount;          // +0x3C
    hkUint32 m_uiVectorDataStride;     // +0x40
    hkUint32 m_uiFloatDataStride;      // +0x44
    hkUint32 m_uiUInt32DataStride;     // +0x48
    hkUint32 m_uiUInt16DataStride;     // +0x4C
    hkUint32 m_uiUInt8DataStride;      // +0x50
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxVertexBufferVertexData[(sizeof(hkxVertexBufferVertexData) == 0x54) ? 1 : -1];
#endif
