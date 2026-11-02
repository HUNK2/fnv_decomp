// include/havok/hkpPoweredChainMapperLinkInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKPPOWEREDCHAINMAPPERLINKINFO_H
#define FNV_HAVOK_HKPPOWEREDCHAINMAPPERLINKINFO_H

#include "hkBase.h"
class hkpConstraintInstance;
#pragma pack(push, 1)
class hkpPoweredChainMapperLinkInfo
{
  public:
    hkInt32 m_iChainIndex;                         // +0x0
    hkInt32 m_iLinkIndex;                          // +0x4
    hkpConstraintInstance* m_pConstraintInstance;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPoweredChainMapperLinkInfo[(sizeof(hkpPoweredChainMapperLinkInfo) == 0xC) ? 1 : -1];
#endif
