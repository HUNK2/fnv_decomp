// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESSCRIPTFUNCTIONS_TESACTORBASEDATA_H
#define FNV_TESSCRIPTFUNCTIONS_TESACTORBASEDATA_H
#include "tesscriptfunctions_layout_support.h"
#include "tesscriptfunctions_BaseFormComponent.h"
#include "tesscriptfunctions_layout_support.h"
class ActorBaseAttributes;
class BGSVoiceType;
class FactionReaction;
class TESActorBaseData;
class ActorBaseAttributes
{
  public:
    int m_uiActorFlags;          // +0x0, 4 bytes
    unsigned short m_usField04;  // +0x4, 2 bytes
    unsigned short m_usField06;  // +0x6, 2 bytes
    unsigned short sLevel;       // +0x8, 2 bytes
    unsigned short m_usField0A;  // +0xA, 2 bytes
    unsigned short m_usField0C;  // +0xC, 2 bytes
    unsigned short m_usField0E;  // +0xE, 2 bytes
    float m_fField10;            // +0x10, 4 bytes
    unsigned short m_usField14;  // +0x14, 2 bytes
    unsigned short m_usField16;  // +0x16, 2 bytes
    // void __cdecl ActorBaseAttributes::*()
};
FNV_STATIC_ASSERT(sizeof(ActorBaseAttributes) == 24);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_uiActorFlags) == 0);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField04) == 4);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField06) == 6);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, sLevel) == 8);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField0A) == 10);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField0C) == 12);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField0E) == 14);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_fField10) == 16);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField14) == 20);
FNV_STATIC_ASSERT(offsetof(ActorBaseAttributes, m_usField16) == 22);
class TESActorBaseData : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    void SetEssential(bool value);
    void SetMatchesPCLevel(bool value);
    void UpdateFlagBit(int flag, bool value, bool addChange);
    ActorBaseAttributes actorData;             // +0x4, 24 bytes
    TESLevItem* m_pBaseTemplateForm;           // +0x1C, 4 bytes
    BGSVoiceType* m_kFactionList;              // +0x20, 4 bytes
    TESForm* m_ppTemplateForms;                // +0x24, 4 bytes
    int m_pDeathItem;                          // +0x28, 4 bytes
    BSSimpleList<FactionReaction*> m_pVoiceType;  // +0x2C, 8 bytes
    // TESActorBaseData
    // void __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(BaseFormComponent*)
    // bool __cdecl TESActorBaseData::*(BaseFormComponent*)
    // void __cdecl TESActorBaseData::*(TESForm*)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(TESActorBaseData::TEMPLATE_USE_FLAG, bool)
    // bool __cdecl TESActorBaseData::*(TESActorBaseData::TEMPLATE_USE_FLAG)
    // TESForm* __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(TESForm*)
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // bool __cdecl TESActorBaseData::*()
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(TESObjectREFR*)
    // TESActorBase* __cdecl TESActorBaseData::*(TESActorBase*, TESActorBase*)
    // bool __cdecl TESActorBaseData::*(TESActorBase*)
    // bool __cdecl TESActorBaseData::*(TESActorBase*, TESActorBase*)
    // TESForm* __cdecl TESActorBaseData::*(TESActorBase*, unsigned short&)
    // int* __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(int)
    // bool __cdecl TESActorBaseData::*(int)
    // void __cdecl TESActorBaseData::*(int, bool, bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool, bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // bool __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // void __cdecl TESActorBaseData::*(bool)
    // unsigned short __cdecl TESActorBaseData::*()
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // TESLevItem* __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(TESLevItem*)
    // void __cdecl TESActorBaseData::*(unsigned short)
    // const char* __cdecl TESActorBaseData::*(Actor*)
    // void __cdecl TESActorBaseData::*(float)
    // void __cdecl TESActorBaseData::*(float)
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // int __cdecl TESActorBaseData::*(TESActorBase*, int&)
    // int __cdecl TESActorBaseData::*(TESFaction*, bool)
    // void __cdecl TESActorBaseData::*(TESFaction*, char)
    // void __cdecl TESActorBaseData::*(TESFaction*, char, bool)
    // bool __cdecl TESActorBaseData::*()
    // bool __cdecl TESActorBaseData::*()
    // unsigned short __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(unsigned short)
    // void __cdecl TESActorBaseData::*(BGSVoiceType*)
    // void __cdecl TESActorBaseData::*(int)
    // void __cdecl TESActorBaseData::*(int)
    // void __cdecl TESActorBaseData::*(int)
    // void __cdecl TESActorBaseData::*(int)
    // int __cdecl TESActorBaseData::*()
    // unsigned short __cdecl TESActorBaseData::*(unsigned int)
    // SaveGame
    // LoadGame
    // void __cdecl TESActorBaseData::*(PC_FACTION_FLAG)
    // bool __cdecl TESActorBaseData::*(TESFaction*)
    // void __cdecl TESActorBaseData::*()
    // void __cdecl TESActorBaseData::*(TESActorBaseData*)
    // TESActorBaseData& __cdecl TESActorBaseData::*(const TESActorBaseData&)
    // void* __cdecl TESActorBaseData::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(TESActorBaseData) == 52);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, actorData) == 4);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_pBaseTemplateForm) == 28);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_kFactionList) == 32);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_ppTemplateForms) == 36);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_pDeathItem) == 40);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_pVoiceType) == 44);
FNV_STATIC_ASSERT(__alignof(ActorBaseAttributes) == 4);
FNV_STATIC_ASSERT(__alignof(TESActorBaseData) == 4);
FNV_STATIC_ASSERT(sizeof(BSSimpleList<FactionReaction*>) == 8);
FNV_STATIC_ASSERT(__alignof(BSSimpleList<FactionReaction*>) == 4);
#endif
