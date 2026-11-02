// the end are the canonical generated-header additions requested for
// The shared FNV_ACTORPACKAGE_H guard keeps this copy conflict-free until the
// canonical header is regenerated and this file retires.
#ifndef FNV_ACTORPACKAGE_H
#define FNV_ACTORPACKAGE_H
#include "layout_support.h"
#pragma pack(push, 4)
class ActorPackageContext
{
  public:
    TESPackage* pPackage;     // +0x0
    ActorPackageData* pData;  // +0x4
    TESObjectREFR* pTarget;   // +0x8
    int m_iPackageValue;      // +0xC
    float m_fPackageValue;    // +0x10
    unsigned int iFlags;      // +0x14
    // Canonical additions requested:
    int GetProcedureIndex();
    void AddToProcedureIndex(int);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ActorPackageContext) == 0x18);
FNV_STATIC_ASSERT(offsetof(ActorPackageContext, pPackage) == 0x0);
FNV_STATIC_ASSERT(offsetof(ActorPackageContext, pData) == 0x4);
FNV_STATIC_ASSERT(offsetof(ActorPackageContext, pTarget) == 0x8);
FNV_STATIC_ASSERT(offsetof(ActorPackageContext, m_iPackageValue) == 0xC);
FNV_STATIC_ASSERT(offsetof(ActorPackageContext, m_fPackageValue) == 0x10);
FNV_STATIC_ASSERT(offsetof(ActorPackageContext, iFlags) == 0x14);
#endif
