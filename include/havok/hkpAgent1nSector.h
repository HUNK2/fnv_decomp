// include/havok/hkpAgent1nSector.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x200.
#ifndef FNV_HAVOK_HKPAGENT1NSECTOR_H
#define FNV_HAVOK_HKPAGENT1NSECTOR_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpAgent1nSector
{
  public:
    hkUint32 m_uiAgentCount;      // +0x0
    hkUint32 m_uiStandInValue;    // +0x4
    hkUint32 m_iValueAfterStandIn;              // +0x8
    hkUint32 m_pAuxiliaryObject;  // +0xC
    hkUint8 m_data[496];          // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpAgent1nSector[(sizeof(hkpAgent1nSector) == 0x200) ? 1 : -1];
#endif
