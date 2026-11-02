// include/havok/hkxVertexFloatDataChannel.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKXVERTEXFLOATDATACHANNEL_H
#define FNV_HAVOK_HKXVERTEXFLOATDATACHANNEL_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxVertexFloatDataChannel : public hkReferencedObject
{
  public:
    enum VertexFloatDimensions
    {
        FLOAT = 0,
        DISTANCE = 1,
        ANGLE = 2
    };
    hkArray<hkReal> m_kFloatValues;    // +0x8
    hkUint8 m_eVertexFloatDimensions;  // +0x14 (VertexFloatDimensions)
    char pad15[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxVertexFloatDataChannel[(sizeof(hkxVertexFloatDataChannel) == 0x18) ? 1 : -1];
#endif
