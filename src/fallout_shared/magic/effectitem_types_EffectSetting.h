// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_EFFECTSETTING_H
#define FNV_EFFECTSETTING_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESDescription.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESIcon.h"
#include "layout_support.h"
class BSFileEntry;
class EffectSetting__EffectSettingData;
class TESEffectShader;
class TESModel;
class TESObjectLIGH;
class FileEntryList;
enum EffectArchetypes__ArchetypeID
{
    EffectArchetypes__ArchetypeID_ARCHETYPE_NONE = -1,
    EffectArchetypes__ArchetypeID_ARCHETYPE_START = 0,
    EffectArchetypes__ArchetypeID_VALUE_MODIFIER = 0,
    EffectArchetypes__ArchetypeID_SCRIPT = 1,
    EffectArchetypes__ArchetypeID_DISPEL = 2,
    EffectArchetypes__ArchetypeID_CURE_DISEASE = 3,
    EffectArchetypes__ArchetypeID_ABSORB = 4,
    EffectArchetypes__ArchetypeID_SHIELD = 5,
    EffectArchetypes__ArchetypeID_CALM = 6,
    EffectArchetypes__ArchetypeID_DEMORALIZE = 7,
    EffectArchetypes__ArchetypeID_FRENZY = 8,
    EffectArchetypes__ArchetypeID_COMMAND_CREATURE = 9,
    EffectArchetypes__ArchetypeID_COMMAND_HUMANOID = 10,
    EffectArchetypes__ArchetypeID_INVISIBILITY = 11,
    EffectArchetypes__ArchetypeID_CHAMELEON = 12,
    EffectArchetypes__ArchetypeID_LIGHT = 13,
    EffectArchetypes__ArchetypeID_DARKNESS = 14,
    EffectArchetypes__ArchetypeID_NIGHT_EYE = 15,
    EffectArchetypes__ArchetypeID_LOCK = 16,
    EffectArchetypes__ArchetypeID_OPEN = 17,
    EffectArchetypes__ArchetypeID_BOUND_ITEM = 18,
    EffectArchetypes__ArchetypeID_SUMMON_CREATURE = 19,
    EffectArchetypes__ArchetypeID_DETECT_LIFE = 20,
    EffectArchetypes__ArchetypeID_TELEKINESIS = 21,
    EffectArchetypes__ArchetypeID_DISINTEGRATE_ARMOR = 22,
    EffectArchetypes__ArchetypeID_DISINTEGRATE_WEAPON = 23,
    EffectArchetypes__ArchetypeID_PARALYZE = 24,
    EffectArchetypes__ArchetypeID_REANIMATE = 25,
    EffectArchetypes__ArchetypeID_SOUL_TRAP = 26,
    EffectArchetypes__ArchetypeID_TURN_UNDEAD = 27,
    EffectArchetypes__ArchetypeID_SUN_DAMAGE = 28,
    EffectArchetypes__ArchetypeID_VAMPIRISM = 29,
    EffectArchetypes__ArchetypeID_CURE_PARALYSIS = 30,
    EffectArchetypes__ArchetypeID_CURE_ADDICTION = 31,
    EffectArchetypes__ArchetypeID_CURE_POISON = 32,
    EffectArchetypes__ArchetypeID_CONCUSSION = 33,
    EffectArchetypes__ArchetypeID_VALUE_AND_PARTS = 34,
    EffectArchetypes__ArchetypeID_LIMB_CONDITION = 35,
    EffectArchetypes__ArchetypeID_TURBO = 36,
    EffectArchetypes__ArchetypeID_ARCHETYPE_COUNT = 37
};
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
class EffectSetting__EffectSettingData
{
  public:
    unsigned int iFlags;                        // +0x0, 4 bytes
    float m_fBaseCost;                          // +0x4, 4 bytes
    TESForm* m_pAssociatedForm;                 // +0x8, 4 bytes
    ActorValue__Index m_iAssociatedSkill;       // +0xC, 4 bytes
    ActorValue__Index m_iResistanceActorValue;  // +0x10, 4 bytes
    short m_sCounterEffectCount;                // +0x14, 2 bytes
    unsigned char layoutPadding16[2];
    TESObjectLIGH* apTargetLight;                      // +0x18, 4 bytes
    float fSpeed;                               // +0x1C, 4 bytes
    TESEffectShader* m_pEffectShader;           // +0x20, 4 bytes
    TESEffectShader* m_pEnchantEffectShader;    // +0x24, 4 bytes
    TESSound* m_pCastSound;                     // +0x28, 4 bytes
    TESSound* m_pBoltSound;                     // +0x2C, 4 bytes
    TESSound* m_pContactSound;                  // +0x30, 4 bytes
    TESSound* m_pAreaEffectSound;               // +0x34, 4 bytes
    float m_fEnchantmentFactor;                 // +0x38, 4 bytes
    float m_fBarterFactor;                      // +0x3C, 4 bytes
    EffectArchetypes__ArchetypeID m_eEffectTypeItem;   // +0x40, 4 bytes
    ActorValue__Index m_iAssociatedActorValue;  // +0x44, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(EffectSetting__EffectSettingData) == 72);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, iFlags) == 0);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_fBaseCost) == 4);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pAssociatedForm) == 8);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_iAssociatedSkill) == 12);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_iResistanceActorValue) == 16);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_sCounterEffectCount) == 20);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, apTargetLight) == 24);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, fSpeed) == 28);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pEffectShader) == 32);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pEnchantEffectShader) == 36);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pCastSound) == 40);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pBoltSound) == 44);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pContactSound) == 48);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_pAreaEffectSound) == 52);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_fEnchantmentFactor) == 56);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_fBarterFactor) == 60);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_eEffectTypeItem) == 64);
FNV_STATIC_ASSERT(offsetof(EffectSetting__EffectSettingData, m_iAssociatedActorValue) == 68);
#pragma pack(push, 4)
class EffectSetting : public TESForm, public TESModel, public TESDescription, public TESFullName, public TESIcon
{
  public:
    // base TESForm at +0x0, size 24
    // base TESModel at +0x18, size 24
    // base TESDescription at +0x30, size 8
    // base TESFullName at +0x38, size 12
    // base TESIcon at +0x44, size 12
    bool(__cdecl* m_pEffectSettingCallback)(EffectSetting*, void*);  // +0x50, 4 bytes
    void* m_pPredicateData;                                          // +0x54, 4 bytes
    EffectSetting__EffectSettingData data;                           // +0x58, 72 bytes
    BSSimpleList<EffectSetting*> counterEffects;                     // +0xA0, 8 bytes
    int m_iActorValue;                                               // +0xA8, 4 bytes
    int m_iEffectID;                                                 // +0xAC, 4 bytes
    int GetEffectID();
    bool IsFlagSet(unsigned int flags);
    bool IsDetrimental();
    // EffectSetting
    // void __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*()
    // bool __cdecl EffectSetting::*(TESFile*)
    // void __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(TESForm*)
    // bool __cdecl EffectSetting::*(TESForm*)
    // bool __cdecl EffectSetting::*(EffectSetting::EffectFlag)
    // bool __cdecl EffectSetting::*(unsigned int)
    // bool __cdecl EffectSetting::*(unsigned int)
    // void __cdecl EffectSetting::*(EffectSetting::EffectFlag, bool)
    // void __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*()
    // bool __cdecl EffectSetting::*()
    // int __cdecl EffectSetting::*()
    // int __cdecl EffectSetting::*()
    // bool __cdecl EffectSetting::*(ActorValue::Index)
    // bool __cdecl EffectSetting::*()
    // bool __cdecl EffectSetting::*()
    // bool __cdecl EffectSetting::*()
    // bool __cdecl EffectSetting::*()
    // MagicSystem::ProjectileType __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(MagicSystem::ProjectileType)
    // BSStringT<char> __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(const char*)
    // float __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(float)
    // TESForm* __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(TESForm*)
    // ActorValue::Index __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(ActorValue::Index)
    // ActorValue::Index __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(ActorValue::Index)
    // BSSimpleList<EffectSetting *>* __cdecl EffectSetting::*()
    // int __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(BSSimpleList<EffectSetting *>*)
    // ActorValue::Index __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(ActorValue::Index)
    // EffectSetting* __cdecl EffectSetting::*()
    // bool __cdecl EffectSetting::*(EffectSetting*, bool, unsigned int)
    // TESSound* __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(TESSound*)
    // TESSound* __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(TESSound*)
    // TESSound* __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(TESSound*)
    // TESSound* __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(TESSound*)
    // TESObjectLIGH* __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(TESObjectLIGH*)
    // TESEffectShader* __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(TESEffectShader*)
    // TESEffectShader* __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(TESEffectShader*)
    // void __cdecl EffectSetting::*(float)
    // float __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(float)
    // float __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(float)
    // float __cdecl EffectSetting::*()
    // char* __cdecl EffectSetting::*()
    // bool __cdecl EffectSetting::*()
    // bool __cdecl EffectSetting::*()
    // int __cdecl EffectSetting::*()
    // int __cdecl EffectSetting::*()
    // int __cdecl EffectSetting::*()
    // int __cdecl EffectSetting::*()
    // bool __cdecl EffectSetting::*()
    // bool __cdecl EffectSetting::*()
    // int __cdecl EffectSetting::*()
    // int __cdecl EffectSetting::*()
    // int __cdecl EffectSetting::*()
    // int __cdecl EffectSetting::*()
    // unsigned int __cdecl EffectSetting::*()
    // void __cdecl EffectSetting::*(unsigned int)
    // void __cdecl EffectSetting::*(short)
    // EffectSetting& __cdecl EffectSetting::*(const EffectSetting&)
    // void __cdecl EffectSetting::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(EffectSetting) == 176);
FNV_STATIC_ASSERT(offsetof(EffectSetting, m_pEffectSettingCallback) == 80);
FNV_STATIC_ASSERT(offsetof(EffectSetting, m_pPredicateData) == 84);
FNV_STATIC_ASSERT(offsetof(EffectSetting, data) == 88);
FNV_STATIC_ASSERT(offsetof(EffectSetting, counterEffects) == 160);
FNV_STATIC_ASSERT(offsetof(EffectSetting, m_iActorValue) == 168);
FNV_STATIC_ASSERT(offsetof(EffectSetting, m_iEffectID) == 172);
#endif
