// include/havok/hkpConstraintChainInstance.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x48.
#ifndef FNV_HAVOK_HKPCONSTRAINTCHAININSTANCE_H
#define FNV_HAVOK_HKPCONSTRAINTCHAININSTANCE_H

#include "hkBase.h"
#include "hkpConstraintInstance.h"
class hkpConstraintChainInstanceAction;
class hkpEntity;
#pragma pack(push, 1)
class hkpConstraintChainInstance : public hkpConstraintInstance
{
  public:
    hkArray<hkpEntity*> m_ppRigidBodies;          // +0x38
    hkpConstraintChainInstanceAction* m_pAction;  // +0x44
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConstraintChainInstance[(sizeof(hkpConstraintChainInstance) == 0x48) ? 1 : -1];
#endif
