// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSRADIATIONSTAGE_H
#define FNV_BGSRADIATIONSTAGE_H

#include "layout_support.h"
#include "TESForm.h"
class SpellItem : public TESForm
{
};
class BGSRadiationStage;
class SpellListEntry;
#pragma pack(push, 4)
class SpellListEntry
{
  public:
    unsigned int SpellEntryRecord;  // +0x0, 4 bytes
    SpellItem* m_pSpell;            // +0x4, 4 bytes
    // void __cdecl SpellListEntry::*()
    // void __cdecl SpellListEntry::*()
    // void __cdecl SpellListEntry::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SpellListEntry) == 8);
FNV_STATIC_ASSERT(offsetof(SpellListEntry, SpellEntryRecord) == 0);
FNV_STATIC_ASSERT(offsetof(SpellListEntry, m_pSpell) == 4);
#pragma pack(push, 4)
class BGSRadiationStage : public TESForm
{
  public:
    void ClearData();
    virtual bool Load(TESFile*);
    static void ClearStageData(BGSRadiationStage* stage);
    static BGSRadiationStage* GetStageForLevel(float level);
    virtual void InitItem();
    void* __RTDynamicCast(void* form);
    // base TESForm at +0x0, size 24
    SpellListEntry data;  // +0x18, 8 bytes
    // BGSRadiationStage
    // void __cdecl BGSRadiationStage::*()
    // void __cdecl BGSRadiationStage::*()
    // bool __cdecl BGSRadiationStage::*(TESFile*)
    // void __cdecl BGSRadiationStage::*(TESForm*)
    // bool __cdecl BGSRadiationStage::*(TESForm*)
    // void __cdecl BGSRadiationStage::*()
    // void __cdecl BGSRadiationStage::*()
    // SpellListEntry* __cdecl BGSRadiationStage::*()
    // void __cdecl BGSRadiationStage::*()
    // SpellItem* __cdecl BGSRadiationStage::*()
    // void __cdecl BGSRadiationStage::*(SpellItem*)
    // unsigned int __cdecl BGSRadiationStage::*()
    // void __cdecl BGSRadiationStage::*(unsigned int)
    // unsigned int __cdecl BGSRadiationStage::*()
    // BGSRadiationStage* __cdecl BGSRadiationStage::*(unsigned int)
    // BGSRadiationStage* __cdecl BGSRadiationStage::*(float)
    // BGSRadiationStage** __cdecl BGSRadiationStage::*(unsigned int)
    // void __cdecl BGSRadiationStage::*()
    // void __cdecl BGSRadiationStage::*(BGSRadiationStage*)
    // ClearStageData
    // BGSRadiationStage& __cdecl BGSRadiationStage::*(const BGSRadiationStage&)
    // void __cdecl BGSRadiationStage::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSRadiationStage) == 32);
FNV_STATIC_ASSERT(offsetof(BGSRadiationStage, data) == 24);
#endif
