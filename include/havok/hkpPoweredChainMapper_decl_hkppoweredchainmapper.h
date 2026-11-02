// include/havok/hkpPoweredChainMapper.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x2C.
#ifndef FNV_HAVOK_HKPPOWEREDCHAINMAPPER_H
#define FNV_HAVOK_HKPPOWEREDCHAINMAPPER_H

#include "hkBase.h"
#include "hkReferencedObject_decl_hkppoweredchainmapper.h"
class hkpConstraintChainInstance;
class hkpPoweredChainMapperLinkInfo;
class hkpPoweredChainMapperTarget;
#pragma pack(push, 1)
class hkpPoweredChainMapper : public hkReferencedObject
{
  public:
    void FUN_00e3a440(int linkIndex, int motorIndex,
                      class hkpConstraintMotor* motor);  // declared for the original code (decl_variants.py)

  public:
    hkArray<hkpPoweredChainMapperLinkInfo> m_ppLinks;        // +0x8
    hkArray<hkpPoweredChainMapperTarget> m_kTargets;         // +0x14
    hkArray<hkpConstraintChainInstance*> m_kChainInstances;  // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPoweredChainMapper[(sizeof(hkpPoweredChainMapper) == 0x2C) ? 1 : -1];
#endif
