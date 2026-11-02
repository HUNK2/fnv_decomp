// include/havok/hkpBridgeConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKPBRIDGECONSTRAINTATOM_H
#define FNV_HAVOK_HKPBRIDGECONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
class hkpConstraintData;
#pragma pack(push, 1)
class hkpBridgeConstraintAtom : public hkpConstraintAtom
{
  public:
    char pad2[0x2];
    void* m_pBridge;                       // +0x4
    hkpConstraintData* m_pConstraintData;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpBridgeConstraintAtom[(sizeof(hkpBridgeConstraintAtom) == 0xC) ? 1 : -1];
#endif
