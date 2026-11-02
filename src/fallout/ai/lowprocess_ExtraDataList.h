// fallout/ai/lowprocess_ExtraDataList.h: declares ExtraDataList
class RegionPoint;
// Source layout: ExtraDataList. PC corrections are in generate_headers.py.
#ifndef FNV_EXTRADATALIST_H
#define FNV_EXTRADATALIST_H
#include "layout_support.h"
#include "BaseExtraList.h"
#pragma pack(push, 4)
class ExtraDataList : public BaseExtraList
{
  public:
    ScriptLocals* GetScriptLocalData();
    RegionPoint* GetStartingPositionData();
    TESObjectREFR* GetReplacementReference();
    void AddGuardingActor(Actor*);
    TESObjectREFR* FUN_0041c8d0();

    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges* changes);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraDataList) == 0x20);
#endif
