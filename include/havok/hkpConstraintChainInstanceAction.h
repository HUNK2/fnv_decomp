// include/havok/hkpConstraintChainInstanceAction.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKPCONSTRAINTCHAININSTANCEACTION_H
#define FNV_HAVOK_HKPCONSTRAINTCHAININSTANCEACTION_H

#include "hkBase.h"
#include "hkpAction.h"
class hkpConstraintChainInstance;
#pragma pack(push, 1)
class hkpConstraintChainInstanceAction : public hkpAction
{
  public:
    hkpConstraintChainInstance* m_pConstraintChainInstance;  // +0x18
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConstraintChainInstanceAction[(sizeof(hkpConstraintChainInstanceAction) == 0x1C) ? 1 : -1];
#endif
