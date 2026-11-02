// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_COMBATMANAGER_H
#define FNV_COMBATMANAGER_H

#include "layout_support.h"
#include "Actor.h"
#include "TimeoutTimer.h"
#include "layout_support.h"
class CombatCoverMap;
class ActorCombatGroup;
class CombatManager;
class CombatTargetMap;
class CombatThreatMap;
class CombatTargetTimestamp;
class BGSLoadGameBuffer;
class NiTMap_Actor_____int64_;
class NiTPrimitiveArray_CombatGroup___;
#pragma pack(push, 4)
class NiTPrimitiveArray_CombatGroup___ : public NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> >
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_CombatGroup___) == 16);
#pragma pack(push, 4)
class CombatTargetTimestamp
{
  public:
    float fTimeStamp;  // +0x0, 4 bytes
    float GetElapsedTime();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CombatTargetTimestamp) == 4);
FNV_STATIC_ASSERT(offsetof(CombatTargetTimestamp, fTimeStamp) == 0);
#pragma pack(push, 4)
class CombatManager
{
  public:
    NiTPrimitiveArray_CombatGroup___ m_kCombatGroups;  // +0x0, 16 bytes
    NiTMap_Actor_____int64_* m_pActorCombatGroupMap;   // +0x10, 4 bytes
    CombatThreatMap* m_pThreatMap;                     // +0x14, 4 bytes
    CombatCoverMap* m_pCoverMap;                       // +0x18, 4 bytes
    CombatTargetMap* m_pTargetMap;                     // +0x1C, 4 bytes
    CombatTargetTimestamp m_kFourByteManagerData;            // +0x20, 4 bytes
    TimeoutTimer m_kFirstEightByteManagerData;          // +0x24, 8 bytes
    TimeoutTimer m_kSecondEightByteManagerData;         // +0x2C, 8 bytes
    unsigned int m_uiDebugFlags;                       // +0x34, 4 bytes
    NiPointer<NiNode> m_spDebugRootNode;               // +0x38, 4 bytes
    unsigned int GetCombatGroupTargetCount(Actor* target, unsigned int* recentCount);
    void Update(bool arg);
    void UpdateCombatGroups(bool arg);
    void ResetTargetMap();
    bool IsCombatActive();
    void LoadGame(BGSLoadGameBuffer* buffer);
    void ApplyLoadBuffer(BGSLoadGameBuffer* buffer);
    void FUN_00991dc0();
    // CombatManager
    // void __cdecl CombatManager::*()
    // void __cdecl CombatManager::*()
    // void __cdecl CombatManager::*(bool)
    // void __cdecl CombatManager::*()
    // void __cdecl CombatManager::*()
    // void __cdecl CombatManager::*(bool)
    // void __cdecl CombatManager::*(bool)
    // void __cdecl CombatManager::*()
    // void __cdecl CombatManager::*()
    // CombatController* __cdecl CombatManager::*(Actor*, Actor*, unsigned int, bool)
    // CombatController* __cdecl CombatManager::*(Actor*, TESPackage*)
    // unsigned int __cdecl CombatManager::*(Actor*, unsigned int*)
    // bool __cdecl CombatManager::*(Actor*, Actor*)
    // void __cdecl CombatManager::*(Actor*, Actor*)
    // bool __cdecl CombatManager::*(Actor*, Actor*)
    // bool __cdecl CombatManager::*(Actor*, Actor*)
    // bool __cdecl CombatManager::*(Actor*, BGSExplosion*, const NiPoint3&, float)
    // void __cdecl CombatManager::*(TESObjectREFR*)
    // void __cdecl CombatManager::*(IDebugText*)
    // void __cdecl CombatManager::*(IDebugText*, TESObjectREFR*)
    // void __cdecl CombatManager::*(IDebugText*, TESObjectREFR*)
    // bool __cdecl CombatManager::*()
    // void __cdecl CombatManager::*(Actor*)
    // void __cdecl CombatManager::*(Actor*)
    // unsigned int __cdecl CombatManager::*(NiPoint3, float, float, Actor*, unsigned int*, unsigned int*, unsigned int*, unsigned int*)
    // CombatThreatMap* __cdecl CombatManager::*()
    // CombatCoverMap* __cdecl CombatManager::*()
    // CombatTargetMap* __cdecl CombatManager::*()
    // void __cdecl CombatManager::*(BGSSaveGameBuffer*)
    // void __cdecl CombatManager::*(BGSLoadGameBuffer*)
    // void __cdecl CombatManager::*(BGSLoadGameBuffer*)
    // void __cdecl CombatManager::*(BGSLoadGameBuffer*)
    // void __cdecl CombatManager::*(BGSLoadGameBuffer*)
    // unsigned int __cdecl CombatManager::*()
    // CombatManager& __cdecl CombatManager::*(const CombatManager&)
    // void* __cdecl CombatManager::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CombatManager) == 60);
FNV_STATIC_ASSERT(offsetof(CombatManager, m_kCombatGroups) == 0);
FNV_STATIC_ASSERT(offsetof(CombatManager, m_pActorCombatGroupMap) == 16);
FNV_STATIC_ASSERT(offsetof(CombatManager, m_pThreatMap) == 20);
FNV_STATIC_ASSERT(offsetof(CombatManager, m_pCoverMap) == 24);
FNV_STATIC_ASSERT(offsetof(CombatManager, m_pTargetMap) == 28);
FNV_STATIC_ASSERT(offsetof(CombatManager, m_kFourByteManagerData) == 32);
FNV_STATIC_ASSERT(offsetof(CombatManager, m_kFirstEightByteManagerData) == 36);
FNV_STATIC_ASSERT(offsetof(CombatManager, m_kSecondEightByteManagerData) == 44);
FNV_STATIC_ASSERT(offsetof(CombatManager, m_uiDebugFlags) == 52);
FNV_STATIC_ASSERT(offsetof(CombatManager, m_spDebugRootNode) == 56);
#endif
