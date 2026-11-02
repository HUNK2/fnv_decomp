// include/havok/hkpBallSocketChainData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x34.
#ifndef FNV_HAVOK_HKPBALLSOCKETCHAINDATA_H
#define FNV_HAVOK_HKPBALLSOCKETCHAINDATA_H

#include "hkBase.h"
#include "hkpBridgeAtoms.h"
#include "hkpConstraintChainData.h"
class hkpBallSocketChainDataConstraintInfo;
#pragma pack(push, 1)
class hkpBallSocketChainData : public hkpConstraintChainData
{
  public:
    hkpBridgeAtoms m_kBridgeAtoms;                                    // +0xC
    hkArray<hkpBallSocketChainDataConstraintInfo> m_pConstraintInfo;  // +0x18
    hkReal m_fTau;                                                    // +0x24
    hkReal m_fMotorDamping;                                           // +0x28
    hkReal m_fMaxErrorDistance;                                       // +0x2C
    hkReal m_fMaximumAngularImpulse;                                  // +0x30
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpBallSocketChainData[(sizeof(hkpBallSocketChainData) == 0x34) ? 1 : -1];
#endif
