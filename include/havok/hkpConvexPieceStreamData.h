// include/havok/hkpConvexPieceStreamData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x2C.
#ifndef FNV_HAVOK_HKPCONVEXPIECESTREAMDATA_H
#define FNV_HAVOK_HKPCONVEXPIECESTREAMDATA_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkpConvexPieceStreamData : public hkReferencedObject
{
  public:
    hkArray<hkUint32> m_pConvexPieceStreamData;  // +0x8
    hkArray<hkUint32> m_kSecondUInt32Array;      // +0x14
    hkArray<hkUint32> m_kThirdUInt32Array;       // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConvexPieceStreamData[(sizeof(hkpConvexPieceStreamData) == 0x2C) ? 1 : -1];
#endif
