// include/havok/hkpBreakableConstraintData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x28.
#ifndef FNV_HAVOK_HKPBREAKABLECONSTRAINTDATA_H
#define FNV_HAVOK_HKPBREAKABLECONSTRAINTDATA_H

#include "hkBase.h"
#include "hkpBridgeAtoms.h"
#include "hkpConstraintData.h"
#pragma pack(push, 1)
class hkpBreakableConstraintData : public hkpConstraintData
{
  public:
    hkpBridgeAtoms m_kBridgeAtoms;         // +0xC
    hkpConstraintData* m_pConstraintData;  // +0x18
    hkUint16 m_usRuntimeOffset;            // +0x1C
    hkUint16 m_usNumSolverResults;         // +0x1E
    hkReal m_fBreakingStrength;            // +0x20
    hkBool m_bRemoveWhenBroken;            // +0x24
    hkBool m_bRevertBackVelocityOnBreak;   // +0x25
    char pad26[0x2];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpBreakableConstraintData[(sizeof(hkpBreakableConstraintData) == 0x28) ? 1 : -1];
#endif
