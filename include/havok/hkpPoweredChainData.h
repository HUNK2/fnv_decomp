// include/havok/hkpPoweredChainData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPPOWEREDCHAINDATA_H
#define FNV_HAVOK_HKPPOWEREDCHAINDATA_H

#include "hkBase.h"
#include "hkpBridgeAtoms.h"
#include "hkpConstraintChainData.h"
class hkpPoweredChainDataConstraintInfo;
#pragma pack(push, 1)
class hkpPoweredChainData : public hkpConstraintChainData
{
  public:
    hkpBridgeAtoms m_kBridgeAtoms;                                 // +0xC
    hkArray<hkpPoweredChainDataConstraintInfo> m_pConstraintInfo;  // +0x18
    hkReal m_fTau;                                                 // +0x24
    hkReal m_fMotorDamping;                                        // +0x28
    hkReal m_fMaximumErrorDistance;                                // +0x2C
    hkReal m_fMaximumLinearImpulse;                                // +0x30
    hkReal m_fBreachImpulse;                                       // +0x34
    hkReal m_fInertiaStabilizationFactor;                          // +0x38
    hkReal m_fMaximumAngularImpulse;                               // +0x3C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPoweredChainData[(sizeof(hkpPoweredChainData) == 0x40) ? 1 : -1];
#endif
