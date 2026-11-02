// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSDEBRIS_H
#define FNV_BGSDEBRIS_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "layout_support.h"
class BGSDebris;
class DebrisModelEntry;
class BGSPreloadable;
#pragma pack(push, 4)
class BGSPreloadable : public BaseFormComponent
{
  public:
    virtual void Preload(int priority, void* file);
    // base BaseFormComponent at +0x0, size 4
    // void __cdecl BGSPreloadable::*()
    // void __cdecl BGSPreloadable::*()
    // void __cdecl BGSPreloadable::*(BaseFormComponent*)
    // bool __cdecl BGSPreloadable::*(BaseFormComponent*)
    // BGSPreloadable
    // BGSPreloadable& __cdecl BGSPreloadable::*(const BGSPreloadable&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSPreloadable) == 4);
#pragma pack(push, 4)
class BGSDebris : public TESForm, public BGSPreloadable
{
  public:
    // base TESForm at +0x0, size 24
    // base BGSPreloadable at +0x18, size 4
    BSSimpleList<DebrisModelEntry*> DataList;  // +0x1C, 8 bytes
    // BGSDebris
    // void __cdecl BGSDebris::*()
    // void __cdecl BGSDebris::*()
    // BSSimpleList<DebrisModelEntry *>* __cdecl BGSDebris::*()
    BSSimpleList<DebrisModelEntry*>* GetDataList();
    void ClearData();
    bool Load(TESFile*);
    void Preload(int priority, void* file);
    DebrisModelEntry* AddDebrisModel(char chance, const char* path, char flags);
    void InsertDebrisIfValid(DebrisModelEntry*);
    // void __cdecl BGSDebris::*(TESObjectCELL*, const NiPoint3&, unsigned int, float)
    // void __cdecl BGSDebris::*(IO_TASK_PRIORITY, QueuedFile*)
    // TestHavokLayer
    // bool __cdecl BGSDebris::*(TESFile*)
    // void __cdecl BGSDebris::*()
    // void __cdecl BGSDebris::*(TESForm*)
    // bool __cdecl BGSDebris::*(TESForm*)
    // void __cdecl BGSDebris::*()
    // AddDebrisModel
    // void __cdecl BGSDebris::*(DebrisModelEntry*)
    // BGSDebris& __cdecl BGSDebris::*(const BGSDebris&)
    // void __cdecl BGSDebris::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSDebris) == 36);
FNV_STATIC_ASSERT(offsetof(BGSDebris, DataList) == 28);
#endif
