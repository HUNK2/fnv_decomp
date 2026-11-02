// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESACTORBASE_H
#define FNV_TESACTORBASE_H

#include "layout_support.h"
#include "ActorValueOwner.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESHealthForm.h"
#include "TESScriptableForm.h"
#include "layout_support.h"
class ActorBaseAttributes;
class PackedRecordData;
class BGSDestructibleObjectForm;
class BGSTouchSpellForm;
class BGSVoiceType;
class BSFileEntry;
class InventoryItemEntry;
class CollisionComponent;
class FactionReaction;
class MagicItemForm;
class ShortPoint3;
class PackageList;
class TESAIForm;
class TESActorBaseData;
class TESAnimation;
class TESAttributes;
class TESBoundAnimObject;
class TESBoundObject__BOUND_DATA;
class TESContainer;
class TESLevSpell;
class TESModel;
class TESFormList;
class TESSpellList;
class FileEntryList;
#pragma pack(push, 4)
class TESObject : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
    // TESObject
    // void __cdecl TESObject::*()
    // NiAVObject* __cdecl TESObject::*()
    // unsigned int __cdecl TESObject::*()
    // TESFormList* __cdecl TESObject::*()
    // unsigned int __cdecl TESObject::*()
    // bool __cdecl TESObject::*()
    // char* __cdecl TESObject::*()
    // void __cdecl TESObject::*(TESFormList*)
    // void __cdecl TESObject::*(TESObject*)
    // void __cdecl TESObject::*(TESObject*)
    // TESObject* __cdecl TESObject::*()
    // TESObject* __cdecl TESObject::*()
    // NiAVObject* __cdecl TESObject::*(NiAVObject*, const char*)
    // const char* __cdecl TESObject::*(TESObjectREFR*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // TESObject& __cdecl TESObject::*(const TESObject&)
    // void __cdecl TESObject::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObject) == 36);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pOwningList) == 24);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pPreviousObject) == 28);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pNextObject) == 32);
#pragma pack(push, 4)
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
    // ShortPoint3
    // short& __cdecl ShortPoint3::*(int)
    // operator=
    // operator==
    // operator!=
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&)
    // operator-
    // operator*
    // ShortPoint3 __cdecl ShortPoint3::*(float)
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&, const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(float)
    // ShortPoint3& __cdecl ShortPoint3::*(float)
    // float __cdecl ShortPoint3::*()
    // short __cdecl ShortPoint3::*()
    // short __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&)
    // float __cdecl ShortPoint3::*()
    // float __cdecl ShortPoint3::*()
    // float __cdecl ShortPoint3::*()
    // void __cdecl ShortPoint3::*(float)
    // void __cdecl ShortPoint3::*(float)
    // void __cdecl ShortPoint3::*(float)
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // void __cdecl ShortPoint3::*(NiStream&)
    // void __cdecl ShortPoint3::*(NiStream&)
    // char* __cdecl ShortPoint3::*(const char*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ShortPoint3) == 6);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, y) == 2);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, z) == 4);
#pragma pack(push, 4)
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject__BOUND_DATA) == 12);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMax) == 6);
#pragma pack(push, 4)
class TESBoundObject : public TESObject
{
  public:
    // base TESObject at +0x0, size 36
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
    // TESBoundObject
    // void __cdecl TESBoundObject::*()
    // bool __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*(NiAVObject*)
    // void __cdecl TESBoundObject::*(TESBoundObject*)
    // NiPoint3 __cdecl TESBoundObject::*()
    // NiPoint3 __cdecl TESBoundObject::*()
    // float __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*(TESFile*)
    // bool __cdecl TESBoundObject::*(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int)
    // bool __cdecl TESBoundObject::*(bool)
    // TESBoundObject& __cdecl TESBoundObject::*(const TESBoundObject&)
    // void __cdecl TESBoundObject::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 48);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, TESBoundObjectBounds) == 36);
#pragma pack(push, 4)
class TESBoundAnimObject : public TESBoundObject
{
  public:
    // base TESBoundObject at +0x0, size 48
    // TESBoundAnimObject
    // void __cdecl TESBoundAnimObject::*()
    // bool __cdecl TESBoundAnimObject::*()
    // void __cdecl TESBoundAnimObject::*(NiAVObject*, bool)
    // bool __cdecl TESBoundAnimObject::*(const char*)
    // TESBoundAnimObject& __cdecl TESBoundAnimObject::*(const TESBoundAnimObject&)
    // void __cdecl TESBoundAnimObject::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundAnimObject) == 48);
#pragma pack(push, 4)
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
#pragma pack(pop)
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
#pragma pack(push, 4)
class TESActorBaseData : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
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
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESActorBaseData) == 52);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, actorData) == 4);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_pBaseTemplateForm) == 28);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_kFactionList) == 32);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_ppTemplateForms) == 36);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_pDeathItem) == 40);
FNV_STATIC_ASSERT(offsetof(TESActorBaseData, m_pVoiceType) == 44);
#pragma pack(push, 4)
class TESContainer : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSSimpleList<InventoryItemEntry*> objectList;  // +0x4, 8 bytes
    // TESContainer
    // void __cdecl TESContainer::*()
    // void __cdecl TESContainer::*()
    // void __cdecl TESContainer::*()
    // void __cdecl TESContainer::*()
    // void __cdecl TESContainer::*(BaseFormComponent*)
    // bool __cdecl TESContainer::*(BaseFormComponent*)
    // void __cdecl TESContainer::*(TESForm*)
    // void __cdecl TESContainer::*()
    // AddObject
    // void __cdecl TESContainer::*(InventoryItemEntry*)
    // InventoryItemEntry* __cdecl TESContainer::*()
    // void __cdecl TESContainer::*(InventoryItemEntry*)
    // void __cdecl TESContainer::*(TESObject*, TESObject*)
    // bool __cdecl TESContainer::*(TESObject*)
    // float __cdecl TESContainer::*(bool)
    // int __cdecl TESContainer::*(TESObject*)
    // char __cdecl TESContainer::*(InventoryItemEntry*, InventoryItemEntry*)
    // float __cdecl TESContainer::*()
    // bool __cdecl TESContainer::*(unsigned char)
    // bool __cdecl TESContainer::*(TESObject*)
    // void __cdecl TESContainer::*(TESContainer*)
    // void __cdecl TESContainer::*(int)
    // void __cdecl TESContainer::*(float)
    // void __cdecl TESContainer::*(TESObjectREFR*, bool)
    // void __cdecl TESContainer::*(int, InventoryChanges*)
    // TESAmmo* __cdecl TESContainer::*(TESActorBase*)
    // TESObjectWEAP* __cdecl TESContainer::*(TESActorBase*)
    // TESObjectARMO* __cdecl TESContainer::*(TESActorBase*, BIPED_OBJECT)
    // TESObjectCLOT* __cdecl TESContainer::*(TESActorBase*, BIPED_OBJECT)
    // TESBoundObject* __cdecl TESContainer::*(BIPED_OBJECT)
    // BSSimpleList<InventoryItemEntry *>* __cdecl TESContainer::*()
    // BSSimpleList<InventoryItemEntry *>* __cdecl TESContainer::*()
    // TESContainer& __cdecl TESContainer::*(const TESContainer&)
    // void* __cdecl TESContainer::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESContainer) == 12);
FNV_STATIC_ASSERT(offsetof(TESContainer, objectList) == 4);
#pragma pack(push, 4)
class BGSTouchSpellForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    MagicItemForm* m_pMagicItem;        // +0x4, 4 bytes
    unsigned short m_usTouchSpellType;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    // BGSTouchSpellForm
    // void __cdecl BGSTouchSpellForm::*()
    // void __cdecl BGSTouchSpellForm::*()
    // void __cdecl BGSTouchSpellForm::*()
    // void __cdecl BGSTouchSpellForm::*(TESForm*)
    // void __cdecl BGSTouchSpellForm::*(BaseFormComponent*)
    // bool __cdecl BGSTouchSpellForm::*(BaseFormComponent*)
    // GetFormTouchSpell
    // void __cdecl BGSTouchSpellForm::*(MagicItemForm*)
    // GetFormTouchSpellAnimation
    // void __cdecl BGSTouchSpellForm::*(unsigned short)
    // BGSTouchSpellForm& __cdecl BGSTouchSpellForm::*(const BGSTouchSpellForm&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSTouchSpellForm) == 12);
FNV_STATIC_ASSERT(offsetof(BGSTouchSpellForm, m_pMagicItem) == 4);
FNV_STATIC_ASSERT(offsetof(BGSTouchSpellForm, m_usTouchSpellType) == 8);
#pragma pack(push, 4)
class TESSpellList : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSSimpleList<SpellItem*> spellList;           // +0x4, 8 bytes
    BSSimpleList<TESLevSpell*> leveledSpellList;  // +0xC, 8 bytes
    // TESSpellList
    // void __cdecl TESSpellList::*()
    // void __cdecl TESSpellList::*()
    // void __cdecl TESSpellList::*()
    // void __cdecl TESSpellList::*()
    // void __cdecl TESSpellList::*(BaseFormComponent*)
    // bool __cdecl TESSpellList::*(BaseFormComponent*)
    // void __cdecl TESSpellList::*(TESForm*)
    // void __cdecl TESSpellList::*()
    // AddSpell
    // RemoveSpell
    // bool __cdecl TESSpellList::*(SpellItem*)
    // unsigned int __cdecl TESSpellList::*()
    // bool __cdecl TESSpellList::*(TESLevSpell*)
    // unsigned int __cdecl TESSpellList::*()
    // BSSimpleList<SpellItem *>* __cdecl TESSpellList::*()
    // BSSimpleList<TESLevSpell *>* __cdecl TESSpellList::*()
    // SaveGame
    // LoadGame
    // TESSpellList& __cdecl TESSpellList::*(const TESSpellList&)
    // void* __cdecl TESSpellList::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESSpellList) == 20);
FNV_STATIC_ASSERT(offsetof(TESSpellList, spellList) == 4);
FNV_STATIC_ASSERT(offsetof(TESSpellList, leveledSpellList) == 12);
#pragma pack(push, 4)
class PackedRecordData
{
  public:
    unsigned char m_ucField00;  // +0x0, 1 bytes
    unsigned char m_ucField01;  // +0x1, 1 bytes
    unsigned char m_ucField02;  // +0x2, 1 bytes
    unsigned char m_ucField03;  // +0x3, 1 bytes
    unsigned char m_ucField04;  // +0x4, 1 bytes
    unsigned char layoutPadding5[3];
    unsigned int m_uiField08;   // +0x8, 4 bytes
    unsigned char m_ucField0C;  // +0xC, 1 bytes
    unsigned char m_ucField0D;  // +0xD, 1 bytes
    unsigned char m_ucField0E;  // +0xE, 1 bytes
    bool m_bField0F;            // +0xF, 1 bytes
    unsigned int m_uiField10;   // +0x10, 4 bytes
    // void __cdecl PackedRecordData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackedRecordData) == 20);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField00) == 0);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField01) == 1);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField02) == 2);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField03) == 3);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField04) == 4);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_uiField08) == 8);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0C) == 12);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0D) == 13);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_ucField0E) == 14);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_bField0F) == 15);
FNV_STATIC_ASSERT(offsetof(PackedRecordData, m_uiField10) == 16);
#pragma pack(push, 4)
class PackageList
{
  public:
    BSSimpleList<TESPackage*> m_kPackages;  // +0x0, 8 bytes
    // PackageList
    // void __cdecl PackageList::*()
    // bool __cdecl PackageList::*(TESPackage*)
    // void __cdecl PackageList::*(TESPackage*)
    // bool __cdecl PackageList::*(TESPackage*, bool)
    // void __cdecl PackageList::*(TESPackage*, TESPackage*, bool)
    // void __cdecl PackageList::*(TESPackage*)
    // void __cdecl PackageList::*()
    // void __cdecl PackageList::*()
    // void __cdecl PackageList::*(PackageList*)
    // bool __cdecl PackageList::*(PackageList*)
    // void __cdecl PackageList::*(TESForm*)
    // TESPackage* __cdecl PackageList::*(Actor*)
    // void __cdecl PackageList::*(Actor*, BSSimpleList<TESPackage *>*, float, float)
    // bool __cdecl PackageList::*()
    // unsigned int __cdecl PackageList::*()
    // BSSimpleList<TESPackage *>* __cdecl PackageList::*()
    // PackageList& __cdecl PackageList::*(const PackageList&)
    // void* __cdecl PackageList::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackageList) == 8);
FNV_STATIC_ASSERT(offsetof(PackageList, m_kPackages) == 0);
#pragma pack(push, 4)
class TESAIForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    PackedRecordData m_kAIData;  // +0x4, 20 bytes
    PackageList m_kPackageList;  // +0x18, 8 bytes
    // TESAIForm
    // void __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(BaseFormComponent*)
    // bool __cdecl TESAIForm::*(BaseFormComponent*)
    // void __cdecl TESAIForm::*(TESForm*)
    // void __cdecl TESAIForm::*(TESAIForm*)
    // void __cdecl TESAIForm::*(TESAIForm*)
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char, bool)
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char)
    // GetConfidenceLevel
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char, bool)
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char, bool)
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char, bool)
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char)
    // unsigned int __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned int, bool)
    // bool __cdecl TESAIForm::*(unsigned int)
    // void __cdecl TESAIForm::*(unsigned int, bool)
    // ActorValue::Index __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(ActorValue::Index)
    // unsigned char __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned char)
    // void __cdecl TESAIForm::*(PackedRecordData*)
    // bool __cdecl TESAIForm::*(TESObject*)
    // bool __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(bool)
    // unsigned int __cdecl TESAIForm::*()
    // void __cdecl TESAIForm::*(unsigned int)
    // bool __cdecl TESAIForm::*(TESPackage*)
    // void __cdecl TESAIForm::*(TESPackage*)
    // bool __cdecl TESAIForm::*(TESPackage*, bool)
    // void __cdecl TESAIForm::*(TESPackage*, TESPackage*, bool)
    // void __cdecl TESAIForm::*(TESPackage*)
    // TESPackage* __cdecl TESAIForm::*(Actor*)
    // void __cdecl TESAIForm::*(Actor*, BSSimpleList<TESPackage *>*, float, float)
    // void __cdecl TESAIForm::*(int)
    // SaveGame
    // LoadGame
    // PackageList* __cdecl TESAIForm::*()
    // TESAIForm& __cdecl TESAIForm::*(const TESAIForm&)
    // void* __cdecl TESAIForm::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESAIForm) == 32);
FNV_STATIC_ASSERT(offsetof(TESAIForm, m_kAIData) == 4);
FNV_STATIC_ASSERT(offsetof(TESAIForm, m_kPackageList) == 24);
#pragma pack(push, 4)
class TESAttributes : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned char cAttribute[7];  // +0x4, 7 bytes
    unsigned char layoutPaddingB[1];
    // TESAttributes
    // void __cdecl TESAttributes::*()
    // void __cdecl TESAttributes::*()
    // void __cdecl TESAttributes::*()
    // unsigned int __cdecl TESAttributes::*(void*)
    // unsigned int __cdecl TESAttributes::*(void*)
    // void __cdecl TESAttributes::*(BaseFormComponent*)
    // bool __cdecl TESAttributes::*(BaseFormComponent*)
    // unsigned int __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*(ActorValue::Index)
    // void __cdecl TESAttributes::*(ActorValue::Index, unsigned char, bool)
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // unsigned short __cdecl TESAttributes::*(unsigned int)
    // SaveGame
    // LoadGame
    // TESAttributes& __cdecl TESAttributes::*(const TESAttributes&)
    // void* __cdecl TESAttributes::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESAttributes) == 12);
FNV_STATIC_ASSERT(offsetof(TESAttributes, cAttribute) == 4);
#pragma pack(push, 4)
class TESAnimation : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSSimpleList<const char*> m_kKFFileList;  // +0x4, 8 bytes
    // TESAnimation
    // void __cdecl TESAnimation::*()
    // void __cdecl TESAnimation::*()
    // void __cdecl TESAnimation::*()
    // bool __cdecl TESAnimation::*(const char*)
    // void __cdecl TESAnimation::*(const char*)
    // bool __cdecl TESAnimation::*()
    // BSSimpleList<char const *>* __cdecl TESAnimation::*()
    // void __cdecl TESAnimation::*(CHUNK_ID)
    // void __cdecl TESAnimation::*(TESAnimation*, TESFile*)
    // void __cdecl TESAnimation::*(BaseFormComponent*)
    // bool __cdecl TESAnimation::*(BaseFormComponent*)
    // TESAnimation& __cdecl TESAnimation::*(const TESAnimation&)
    // void* __cdecl TESAnimation::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESAnimation) == 12);
FNV_STATIC_ASSERT(offsetof(TESAnimation, m_kKFFileList) == 4);
#pragma pack(push, 4)
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
    // void __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*()
    // bool __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*(CHUNK_ID, const char*)
    // void __cdecl FileEntryList::*(TESFile*, TESForm*, const char*)
    // void __cdecl FileEntryList::*(FileEntryList*)
    // unsigned char __cdecl FileEntryList::*()
    // BSFileEntry** __cdecl FileEntryList::*()
    // void* __cdecl FileEntryList::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
#pragma pack(push, 4)
class TESModel : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    // TESModel
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*(CHUNK_ID, CHUNK_ID)
    // void __cdecl TESModel::*(BaseFormComponent*)
    // bool __cdecl TESModel::*(BaseFormComponent*)
    // void __cdecl TESModel::*(CHUNK_ID)
    // GetModelLength
    // bool __cdecl TESModel::*(CHUNK_ID)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // bool __cdecl TESModel::*()
    // char __cdecl TESModel::*()
    // void __cdecl TESModel::*(char)
    // bool __cdecl TESModel::*()
    // void __cdecl TESModel::*(bool)
    // unsigned int __cdecl TESModel::*()
    // void __cdecl TESModel::*(unsigned int)
    // bool __cdecl TESModel::*()
    // FileEntryList* __cdecl TESModel::*()
    // TESModel& __cdecl TESModel::*(const TESModel&)
    // void __cdecl TESModel::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
#pragma pack(push, 4)
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    CollisionComponent* pData;  // +0x4, 4 bytes
    // BGSDestructibleObjectForm
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(BGSDestructibleObjectForm*, TESFile*)
    // void __cdecl BGSDestructibleObjectForm::*(BaseFormComponent*)
    // bool __cdecl BGSDestructibleObjectForm::*(BaseFormComponent*)
    // void __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // CollisionComponent* __cdecl BGSDestructibleObjectForm::*()
    // unsigned char __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(unsigned int)
    // bool __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // BGSDestructibleObjectForm* __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // int __cdecl BGSDestructibleObjectForm::*(TESForm*, TESModel*)
    // TESModel* __cdecl BGSDestructibleObjectForm::*(TESForm*, int)
    // bool __cdecl BGSDestructibleObjectForm::*()
    // bool __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(bool)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, float, bool)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BGSExplosion*, unsigned int, TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BGSDebris*, unsigned int, TESObjectREFR*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // bool __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, bool)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BSSimpleArray<NiNode *,1024>&)
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // bool __cdecl BGSDestructibleObjectForm::*(NiAVObject*)
    // void __cdecl BGSDestructibleObjectForm::*(TESBoundObject*, IO_TASK_PRIORITY, QueuedFile*)
    // void __cdecl BGSDestructibleObjectForm::*(TESBoundObject*)
    // void __cdecl BGSDestructibleObjectForm::*()
    // bool __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // CalculateDangerousExplosionHealth
    // float __cdecl BGSDestructibleObjectForm::*(unsigned char, float, float, BGSExplosion**)
    // void __cdecl BGSDestructibleObjectForm::*(IDebugText*, TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(IDebugText*, TESObjectREFR*)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, float)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // NiTMap<TESObjectREFR *,unsigned int>* __cdecl BGSDestructibleObjectForm::*()
    // float __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(float)
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // BGSDestructibleObjectForm& __cdecl BGSDestructibleObjectForm::*(const BGSDestructibleObjectForm&)
    // void* __cdecl BGSDestructibleObjectForm::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 8);
FNV_STATIC_ASSERT(offsetof(BGSDestructibleObjectForm, pData) == 4);
#pragma pack(push, 4)
class TESActorBase : public TESBoundAnimObject,
                     public TESActorBaseData,
                     public TESContainer,
                     public BGSTouchSpellForm,
                     public TESSpellList,
                     public TESAIForm,
                     public TESHealthForm,
                     public TESAttributes,
                     public TESAnimation,
                     public TESFullName,
                     public TESModel,
                     public TESScriptableForm,
                     public ActorValueOwner,
                     public BGSDestructibleObjectForm
{
  public:
    SEX GetSex();
    // base TESBoundAnimObject at +0x0, size 48
    // base TESActorBaseData at +0x30, size 52
    // base TESContainer at +0x64, size 12
    // base BGSTouchSpellForm at +0x70, size 12
    // base TESSpellList at +0x7C, size 20
    // base TESAIForm at +0x90, size 32
    // base TESHealthForm at +0xB0, size 8
    // base TESAttributes at +0xB8, size 12
    // base TESAnimation at +0xC4, size 12
    // base TESFullName at +0xD0, size 12
    // base TESModel at +0xDC, size 24
    // base TESScriptableForm at +0xF4, size 12
    // base ActorValueOwner at +0x100, size 4
    // base BGSDestructibleObjectForm at +0x104, size 8
    // bool __cdecl TESActorBase::*()
    // int __cdecl TESActorBase::*()
    // void __cdecl TESActorBase::*(int)
    // int __cdecl TESActorBase::*()
    // void __cdecl TESActorBase::*(int)
    // bool __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // SEX __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // void __cdecl TESActorBase::*(bool)
    // float __cdecl TESActorBase::*(TESForm*)
    // bool __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*()
    // void __cdecl TESActorBase::*(bool)
    // unsigned short __cdecl TESActorBase::*()
    // int __cdecl TESActorBase::*(ActorValue::Index)
    // float __cdecl TESActorBase::*(ActorValue::Index)
    // SetActorValue
    // ModActorValue
    // void __cdecl TESActorBase::*(HWND__*)
    // TESForm* __cdecl TESActorBase::*()
    // bool __cdecl TESActorBase::*(TESObjectREFR*)
    // void __cdecl TESActorBase::*(int)
    // void __cdecl TESActorBase::*(int)
    // unsigned short __cdecl TESActorBase::*(unsigned int)
    // SaveGame
    // LoadGame
    // Revert
    // void __cdecl TESActorBase::*(unsigned char)
    // TESActorBase
    // void __cdecl TESActorBase::*()
    // TESActorBase& __cdecl TESActorBase::*(const TESActorBase&)
    // void __cdecl TESActorBase::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESActorBase) == 268);
#endif
