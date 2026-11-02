// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_COMBATTARGETMAP_H
#define FNV_COMBATTARGETMAP_H

#include "layout_support.h"
#include "Actor.h"
#include "layout_support.h"
class ActorCombatTargetData;
class CombatTargetMap;
class DFALL_NiTMapItem_Actor___CombatTargetData_____;
class NiTMap_Actor___CombatTargetData___;
class NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData___;
class NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData_____AntiBloatAllocator;
#pragma pack(push, 4)
class DFALL_NiTMapItem_Actor___CombatTargetData_____
{
  public:
    // void* __cdecl DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >::*()
    // void __cdecl DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >::*(void*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DFALL_NiTMapItem_Actor___CombatTargetData_____) == 1);
#pragma pack(push, 4)
class NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData_____AntiBloatAllocator
    : public DFALL_NiTMapItem_Actor___CombatTargetData_____
{
  public:
    // base DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(
    sizeof(NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData_____AntiBloatAllocator) ==
    4);
FNV_STATIC_ASSERT(
    offsetof(NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData_____AntiBloatAllocator,
             m_uiCount) == 0);
#pragma pack(push, 4)
class NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData___
{
  public:
    void** m_ppVirtualMethodTable;                                              // +0x0, 4 bytes
    unsigned int m_uiHashSize;                                    // +0x4, 4 bytes
    NiTMapItem<Actor*, ActorCombatTargetData*>** m_ppkHashTable;  // +0x8, 4 bytes
    NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData_____AntiBloatAllocator
        m_kItemCount;  // +0xC, 4 bytes
    // NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>
    // unsigned int __cdecl NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>::*(Actor*, ActorCombatTargetData*)
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>::*(Actor*)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>::*(Actor*, ActorCombatTargetData*&)
    // void* __cdecl NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>::*(void*&, Actor*&, ActorCombatTargetData*&)
    // NiTMapItem<Actor *,ActorCombatTargetData *>* __cdecl NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>::*(Actor*)
    // NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>& __cdecl NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>::*(const NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>&)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData___) == 16);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData___,
                           m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData___,
                           m_uiHashSize) == 4);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData___,
                           m_ppkHashTable) == 8);
FNV_STATIC_ASSERT(offsetof(NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData___,
                           m_kItemCount) == 12);
#pragma pack(push, 4)
class NiTMap_Actor___CombatTargetData___
    : public NiTMapBase_DFALL_NiTMapItem_Actor___CombatTargetData______Actor___CombatTargetData___
{
  public:
    // base NiTMapBase<DFALL<NiTMapItem<Actor *,ActorCombatTargetData *> >,Actor *,ActorCombatTargetData *> at +0x0, size 16
    // NiTMap<Actor *,ActorCombatTargetData *>
    // void __cdecl NiTMap<Actor *,ActorCombatTargetData *>::*()
    // NiTMapItem<Actor *,ActorCombatTargetData *>* __cdecl NiTMap<Actor *,ActorCombatTargetData *>::*()
    // void __cdecl NiTMap<Actor *,ActorCombatTargetData *>::*(NiTMapItem<Actor *,ActorCombatTargetData *>*)
    // NiTMap<Actor *,ActorCombatTargetData *>& __cdecl NiTMap<Actor *,ActorCombatTargetData *>::*(const NiTMap<Actor *,ActorCombatTargetData *>&)
    // void __cdecl NiTMap<Actor *,ActorCombatTargetData *>::*()
    // void __cdecl NiTMap<Actor *,ActorCombatTargetData *>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTMap_Actor___CombatTargetData___) == 16);
#pragma pack(push, 4)
class CombatTargetMap : public NiTMap_Actor___CombatTargetData___
{
  public:
    void* GetTargetsForActor(Actor* actor);
    // base NiTMap<Actor *,ActorCombatTargetData *> at +0x0, size 16
    // CombatTargetMap
    // void __cdecl CombatTargetMap::*()
    // void __cdecl CombatTargetMap::*(Actor*, Actor*)
    // void __cdecl CombatTargetMap::*(Actor*, Actor*)
    // void __cdecl CombatTargetMap::*(Actor*)
    // BSSimpleArray<Actor *,1024>* __cdecl CombatTargetMap::*(Actor*)
    // int __cdecl CombatTargetMap::*(Actor*, Actor*)
    // void __cdecl CombatTargetMap::*()
    // CombatTargetMap& __cdecl CombatTargetMap::*(const CombatTargetMap&)
    // void __cdecl CombatTargetMap::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CombatTargetMap) == 16);
#endif
