// include/havok/hkpPoweredChainMapperTarget.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKPPOWEREDCHAINMAPPERTARGET_H
#define FNV_HAVOK_HKPPOWEREDCHAINMAPPERTARGET_H

#include "hkBase.h"
class hkpPoweredChainData;
#pragma pack(push, 1)
class hkpPoweredChainMapperTarget
{
  public:
    hkpPoweredChainData* m_pChainInstance;  // +0x0
    hkInt32 m_targetIndex;                  // +0x4
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPoweredChainMapperTarget[(sizeof(hkpPoweredChainMapperTarget) == 0x8) ? 1 : -1];
#endif
