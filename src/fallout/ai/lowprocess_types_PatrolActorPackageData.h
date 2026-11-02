// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PATROLACTORPACKAGEDATA_H
#define FNV_PATROLACTORPACKAGEDATA_H
#include "layout_support.h"
#include "lowprocess_Actor.h"
#include "lowprocess_TESObjectREFR.h"
#include "layout_support.h"
class PatrolActorPackageData;
class TESPatrolPackageData;
enum PatrolActorPackageData__PATROL_STATE
{
    PatrolActorPackageData__PATROL_STATE_PATROL_STATE_INIT = 0,
    PatrolActorPackageData__PATROL_STATE_PATROL_STATE_TRAVELING_TO_NEXT_REF = 1,
    PatrolActorPackageData__PATROL_STATE_PATROL_STATE_AT_REF = 2,
    PatrolActorPackageData__PATROL_STATE_PATROL_STATE_DEBUG_ACTOR_DELETED = 3,
    PatrolActorPackageData__PATROL_STATE_PATROL_STATE_DEBUG_DESTRUCTED = 4
};
#pragma pack(push, 4)
class ActorPackageData
{
  public:
    void FUN_006ecd40(void*);
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
    // ActorPackageData
    // ActorPackageData* __cdecl ActorPackageData::*(PTYPE)
    // ActorPackageData& __cdecl ActorPackageData::*(const ActorPackageData&)
    // void __cdecl ActorPackageData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ActorPackageData) == 4);
FNV_STATIC_ASSERT(offsetof(ActorPackageData, m_ppVirtualMethodTable) == 0);
#pragma pack(push, 4)
class PatrolActorPackageData : public ActorPackageData
{
  public:
    bool Init(Actor*, TESPackage*);
    bool AdvanceToNextReference(bool);
    TESObjectREFR* GetCurrentPatrolReference();
    static TESObjectREFR* GetPatrolReference(Actor*, TESPackage*);

    // base ActorPackageData at +0x0, size 4
    PatrolActorPackageData__PATROL_STATE eState;  // +0x4, 4 bytes
    float m_fElapsedWaitTime;                     // +0x8, 4 bytes
    bool m_bPatrolFlag;                           // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
    Actor* pActor;                                     // +0x10, 4 bytes
    TESPackage* pPackage;                              // +0x14, 4 bytes
    const TESPatrolPackageData* m_pEscortPackageData;  // +0x18, 4 bytes
    BSSimpleArray<TESObjectREFR*, 1024> References;    // +0x1C, 16 bytes
    bool m_bReferenceFlag;                             // +0x2C, 1 bytes
    unsigned char layoutPadding2D[3];
    unsigned int m_uiValueAfterReferenceFlag;        // +0x30, 4 bytes
    unsigned int m_uiSecondValueAfterReferenceFlag;  // +0x34, 4 bytes
    // PatrolActorPackageData
    // void __cdecl PatrolActorPackageData::*()
    // bool __cdecl PatrolActorPackageData::*(Actor*, TESPackage*)
    // void __cdecl PatrolActorPackageData::*(TESObjectREFR*)
    // bool __cdecl PatrolActorPackageData::*(bool)
    // TESObjectREFR* __cdecl PatrolActorPackageData::*()
    // PTYPE __cdecl PatrolActorPackageData::*()
    // void __cdecl PatrolActorPackageData::*(BGSSaveFormBuffer*)
    // void __cdecl PatrolActorPackageData::*(BGSLoadFormBuffer*)
    // void __cdecl PatrolActorPackageData::*(BGSLoadFormBuffer*)
    // TESObjectREFR* __cdecl PatrolActorPackageData::*(Actor*, TESPackage*)
    // bool __cdecl PatrolActorPackageData::*()
    // void __cdecl PatrolActorPackageData::*()
    // bool __cdecl PatrolActorPackageData::*(unsigned int)
    // void __cdecl PatrolActorPackageData::*(const NiPoint3&)
    // PatrolActorPackageData& __cdecl PatrolActorPackageData::*(const PatrolActorPackageData&)
    // void __cdecl PatrolActorPackageData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PatrolActorPackageData) == 56);
FNV_STATIC_ASSERT(offsetof(PatrolActorPackageData, eState) == 4);
FNV_STATIC_ASSERT(offsetof(PatrolActorPackageData, m_fElapsedWaitTime) == 8);
FNV_STATIC_ASSERT(offsetof(PatrolActorPackageData, m_bPatrolFlag) == 12);
FNV_STATIC_ASSERT(offsetof(PatrolActorPackageData, pActor) == 16);
FNV_STATIC_ASSERT(offsetof(PatrolActorPackageData, pPackage) == 20);
FNV_STATIC_ASSERT(offsetof(PatrolActorPackageData, m_pEscortPackageData) == 24);
FNV_STATIC_ASSERT(offsetof(PatrolActorPackageData, References) == 28);
FNV_STATIC_ASSERT(offsetof(PatrolActorPackageData, m_bReferenceFlag) == 44);
FNV_STATIC_ASSERT(offsetof(PatrolActorPackageData, m_uiValueAfterReferenceFlag) == 48);
FNV_STATIC_ASSERT(offsetof(PatrolActorPackageData, m_uiSecondValueAfterReferenceFlag) == 52);
#endif
