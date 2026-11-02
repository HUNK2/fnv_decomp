// include/havok/hkpConvexVerticesConnectivity.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPCONVEXVERTICESCONNECTIVITY_H
#define FNV_HAVOK_HKPCONVEXVERTICESCONNECTIVITY_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkpConvexVerticesConnectivity : public hkReferencedObject
{
  public:
    hkArray<hkUint16> m_kVertexIndices;      // +0x8
    hkArray<hkUint8> m_kNumVerticesPerFace;  // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConvexVerticesConnectivity[(sizeof(hkpConvexVerticesConnectivity) == 0x20) ? 1 : -1];
#endif
