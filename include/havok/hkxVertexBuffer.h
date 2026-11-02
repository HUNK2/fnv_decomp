// include/havok/hkxVertexBuffer.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x68.
#ifndef FNV_HAVOK_HKXVERTEXBUFFER_H
#define FNV_HAVOK_HKXVERTEXBUFFER_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#include "hkxVertexBufferVertexData.h"
#include "hkxVertexDescription.h"
#pragma pack(push, 1)
class hkxVertexBuffer : public hkReferencedObject
{
  public:
    hkxVertexBufferVertexData m_data;    // +0x8
    hkxVertexDescription m_kCreateDesc;  // +0x5C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxVertexBuffer[(sizeof(hkxVertexBuffer) == 0x68) ? 1 : -1];
#endif
