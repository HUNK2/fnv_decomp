// include/havok/hkpStiffSpringChainData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPSTIFFSPRINGCHAINDATA_H
#define FNV_HAVOK_HKPSTIFFSPRINGCHAINDATA_H

#include "hkBase.h"
#include "hkpBridgeAtoms.h"
#include "hkpConstraintChainData.h"
class hkpStiffSpringChainDataConstraintInfo;
#pragma pack(push, 1)
class hkpStiffSpringChainData : public hkpConstraintChainData
{
  public:
    hkpBridgeAtoms m_kBridgeAtoms;                                     // +0xC
    hkArray<hkpStiffSpringChainDataConstraintInfo> m_pConstraintInfo;  // +0x18
    hkReal m_fTau;                                                     // +0x24
    hkReal m_fMotorDamping;                                            // +0x28
    hkReal m_fMaxErrorDistance;                                        // +0x2C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpStiffSpringChainData[(sizeof(hkpStiffSpringChainData) == 0x30) ? 1 : -1];
#endif
