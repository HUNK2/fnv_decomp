// include/havok/hkMoppBvTreeShapeBase.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKMOPPBVTREESHAPEBASE_H
#define FNV_HAVOK_HKMOPPBVTREESHAPEBASE_H

#include "hkBase.h"
class hkpMoppCode;
#pragma pack(push, 1)
class hkMoppBvTreeShapeBase
{
  public:
    char pad0[0x14];
    hkpMoppCode* m_pMoppCode;   // +0x14
    void* m_pMoppData;          // +0x18
    hkUint32 m_uiMoppDataSize;  // +0x1C
    hkVector4 m_kMoppCodeInfo;  // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkMoppBvTreeShapeBase[(sizeof(hkMoppBvTreeShapeBase) == 0x30) ? 1 : -1];
#endif
