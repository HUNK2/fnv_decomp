// include/havok/hkxVertexVectorDataChannel.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKXVERTEXVECTORDATACHANNEL_H
#define FNV_HAVOK_HKXVERTEXVECTORDATACHANNEL_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxVertexVectorDataChannel : public hkReferencedObject
{
  public:
    hkArray<hkVector4> m_kVertexVectors;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxVertexVectorDataChannel[(sizeof(hkxVertexVectorDataChannel) == 0x14) ? 1 : -1];
#endif
