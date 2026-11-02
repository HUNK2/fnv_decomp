// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESPACKAGE_H
#define FNV_TESPACKAGE_H

#include "layout_support.h"
#include "Script.h"
#include "PerkEntryConditionSet.h"
#include "TESForm.h"
#include "TESTopic.h"
class Actor;
class TESObjectREFR;
class BGSIdleCollection;
class PackageRuntimeData;
class PackedByteIntRecord;
class PackageEventActionData;
class LocationDescriptor;
class DurationData;
class PackageTargetRecord;
class TESCombatStyle;
class TESIdleForm;
class TESPackageData;
enum PACKAGE_PROCEDURE_TYPE
{
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_NONE = -1,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_EXPLORE_TRAVEL = 0,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_EXPLORE_WANDER = 1,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_EXPLORE_ACTIVATE = 2,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_EXPLORE_ACQUIRE = 3,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_SLEEP = 4,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_EAT = 5,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_FOLLOW_WITH_ESCORT = 6,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_AMBUSH_FOLLOW = 7,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_ESCORT_ACTOR = 8,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_ESCORT_OBJECT = 9,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_DIALOGUE = 10,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_ALARM = 11,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_COMBAT = 12,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_ACTIVATE = 13,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_GREET = 14,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_OBSERVE_COMBAT = 15,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_OBSERVE_DIALOGUE = 16,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_TALK_TO_DEAD = 17,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_COMBAT_NOT_IN_HIGH = 18,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_FLEE = 19,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_TRESPASS = 20,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_GET_UP = 21,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_EXPLORE_NPC = 22,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_MOUNT_HORSE = 23,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_DISMOUNT_HORSE = 24,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_DO_NOTHING = 25,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_EXPLORE_ACQUIRE_GENERIC = 26,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_ACCOMPANY = 27,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_USEITEMAT = 28,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_SANDMAN = 29,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_AMBUSH = 30,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_SURFACE = 31,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_FLEE_NON_COMBAT = 32,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_SEARCH = 33,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_CLEAR_MOUNT_POSITION = 34,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_SUMMON_CREATURE_DEFEND = 35,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_AVOID_RADIATION = 36,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_SANDBOX = 37,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_PATROL = 38,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_EXPLOSION_REACTION = 39,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_GRENADE_MINE_REACTION = 40,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_GUARD = 41,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_STEAL_WARN = 42,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_PICKPOCKET_WARN = 43,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_USEWEAPON = 44,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_FOLLOW_WITHOUT_ESCORT = 45,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_MOVEMENT_BLOCKED = 46,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_CANNIBAL = 47,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_BACK_UP = 48,
    PACKAGE_PROCEDURE_TYPE_PACKAGE_PROCEDURE_COUNT = 49
};
enum PACK_EVENT_ACTION_TYPE
{
    PACK_EVENT_ACTION_TYPE_PEAT_BEGIN = 0,
    PACK_EVENT_ACTION_TYPE_PEAT_END = 1,
    PACK_EVENT_ACTION_TYPE_PEAT_CHANGE = 2,
    PACK_EVENT_ACTION_TYPE_PEAT_PATROL = 3,
    PACK_EVENT_ACTION_TYPE_NUM_PACK_EVENT_ACTION_TYPES = 4
};
#pragma pack(push, 4)
class PackageRuntimeData
{
  public:
    unsigned int m_uiPackEventActionType;  // +0x0, 4 bytes
    char m_cEventActionValue;              // +0x4, 1 bytes
    unsigned char layoutPadding5[1];
    unsigned short IntegerByteAndShortPairRecord;  // +0x6, 2 bytes
    unsigned short m_usPairedShortValue;           // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    // void __cdecl PackageRuntimeData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackageRuntimeData) == 12);
FNV_STATIC_ASSERT(offsetof(PackageRuntimeData, m_uiPackEventActionType) == 0);
FNV_STATIC_ASSERT(offsetof(PackageRuntimeData, m_cEventActionValue) == 4);
FNV_STATIC_ASSERT(offsetof(PackageRuntimeData, IntegerByteAndShortPairRecord) == 6);
FNV_STATIC_ASSERT(offsetof(PackageRuntimeData, m_usPairedShortValue) == 8);
#pragma pack(push, 4)
class PackedByteIntRecord
{
  public:
    char m_cByte0;  // +0x0, 1 bytes
    char m_cByte1;  // +0x1, 1 bytes
    char m_cByte2;  // +0x2, 1 bytes
    char m_cLastByteBeforePayloadItem;     // +0x3, 1 bytes
    int m_iPayloadInteger;  // +0x4, 4 bytes
    // void __cdecl PackedByteIntRecord::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackedByteIntRecord) == 8);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_cByte0) == 0);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_cByte1) == 1);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_cByte2) == 2);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_cLastByteBeforePayloadItem) == 3);
FNV_STATIC_ASSERT(offsetof(PackedByteIntRecord, m_iPayloadInteger) == 4);
#pragma pack(push, 4)
class DurationData
{
  public:
    PackedByteIntRecord m_kScheduleData;  // +0x0, 8 bytes
    // DurationData
    // void __cdecl DurationData::*()
    // PSMONTH __cdecl DurationData::*()
    // void __cdecl DurationData::*(PSMONTH)
    // PSDAYOFWEEK __cdecl DurationData::*()
    // void __cdecl DurationData::*(PSDAYOFWEEK)
    // char __cdecl DurationData::*()
    // void __cdecl DurationData::*(char)
    // char __cdecl DurationData::*()
    // void __cdecl DurationData::*(char)
    // int __cdecl DurationData::*()
    // void __cdecl DurationData::*(int)
    // void __cdecl DurationData::*(DurationData*)
    // bool __cdecl DurationData::*(DurationData*)
    // void __cdecl DurationData::*()
    // const char* __cdecl DurationData::*()
    // const char* __cdecl DurationData::*()
    // void* __cdecl DurationData::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DurationData) == 8);
FNV_STATIC_ASSERT(offsetof(DurationData, m_kScheduleData) == 0);
#pragma pack(push, 4)
class PackageEventActionData
{
  public:
    TESIdleForm* m_pIdleForm;      // +0x0, 4 bytes
    Script* m_pScript;             // +0x4, 4 bytes
    TESTopic* pTopic;              // +0x8, 4 bytes
    PACK_EVENT_ACTION_TYPE eType;  // +0xC, 4 bytes
    // void __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*()
    // TESIdleForm* __cdecl PackageEventActionData::*()
    // Script* __cdecl PackageEventActionData::*()
    // TESTopic* __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*(TESIdleForm*)
    // void __cdecl PackageEventActionData::*(const char*)
    // void __cdecl PackageEventActionData::*(TESTopic*)
    // void __cdecl PackageEventActionData::*(PACK_EVENT_ACTION_TYPE)
    // PACK_EVENT_ACTION_TYPE __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*(PackageEventActionData*)
    // bool __cdecl PackageEventActionData::*(PackageEventActionData*)
    // void __cdecl PackageEventActionData::*(TESFile*)
    // void __cdecl PackageEventActionData::*(CHUNK_ID)
    // void __cdecl PackageEventActionData::*(TESForm*)
    // unsigned short __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*()
    // void __cdecl PackageEventActionData::*()
    // const char* __cdecl PackageEventActionData::*()
    // void* __cdecl PackageEventActionData::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackageEventActionData) == 16);
FNV_STATIC_ASSERT(offsetof(PackageEventActionData, m_pIdleForm) == 0);
FNV_STATIC_ASSERT(offsetof(PackageEventActionData, m_pScript) == 4);
FNV_STATIC_ASSERT(offsetof(PackageEventActionData, pTopic) == 8);
FNV_STATIC_ASSERT(offsetof(PackageEventActionData, eType) == 12);
#pragma pack(push, 4)
class TESPackage : public TESForm
{
  public:
    static float GetPackageDefaultFloat();
    TESObjectREFR* GetTargetForActor(Actor* actor, bool arg2);
    // base TESForm at +0x0, size 24
    PACKAGE_PROCEDURE_TYPE m_eProcedureType;  // +0x18, 4 bytes
    PackageRuntimeData StridedDataTransfer;   // +0x1C, 12 bytes
    TESPackageData* m_pPackageData;           // +0x28, 4 bytes
    LocationDescriptor* m_pPackageLocation;   // +0x2C, 4 bytes
    PackageTargetRecord* m_pTargetRecord;     // +0x30, 4 bytes
    BGSIdleCollection* m_pIdleCollection;     // +0x34, 4 bytes
    DurationData m_kSchedule;                 // +0x38, 8 bytes
    PerkEntryConditionSet m_kConditions;               // +0x40, 8 bytes
    TESCombatStyle* m_pCombatStyle;           // +0x48, 4 bytes
    PackageEventActionData OnBegin;           // +0x4C, 16 bytes
    PackageEventActionData OnEnd;             // +0x5C, 16 bytes
    PackageEventActionData OnChange;          // +0x6C, 16 bytes
    unsigned int m_uiRefCount;                // +0x7C, 4 bytes
    // TESPackage* __cdecl TESPackage::*(PTYPE)
    // TESPackage
    // void __cdecl TESPackage::*()
    // unsigned int __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(unsigned int)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // void __cdecl TESPackage::*(TESPackage*)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // void __cdecl TESPackage::*(bool)
    // void __cdecl TESPackage::*(bool)
    // void __cdecl TESPackage::*(bool)
    // void __cdecl TESPackage::*(bool)
    // void __cdecl TESPackage::*(bool)
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(bool)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(TESObjectREFR*, bool)
    // PTYPE __cdecl TESPackage::*()
    // LocationDescriptor* __cdecl TESPackage::*()
    // LocationDescriptor* __cdecl TESPackage::*()
    // LocationDescriptor* __cdecl TESPackage::*()
    // PackageTargetRecord* __cdecl TESPackage::*()
    // DurationData* __cdecl TESPackage::*()
    // BGSIdleCollection* __cdecl TESPackage::*()
    // TESTopic* __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*()
    // float __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*()
    // float __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*(MobileObject*, float&)
    // bool __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(PTYPE)
    // void __cdecl TESPackage::*(LocationDescriptor*)
    // void __cdecl TESPackage::*(LocationDescriptor*)
    // void __cdecl TESPackage::*(PackageTargetRecord*)
    // void __cdecl TESPackage::*(DurationData*)
    // void __cdecl TESPackage::*(BGSIdleCollection*)
    // void __cdecl TESPackage::*(TESTopic*)
    // void __cdecl TESPackage::*(bool)
    // void __cdecl TESPackage::*(float)
    // void __cdecl TESPackage::*(bool)
    // void __cdecl TESPackage::*(bool)
    // void __cdecl TESPackage::*(float)
    // void __cdecl TESPackage::*(bool)
    // TESIdleForm* __cdecl TESPackage::*()
    // TESIdleForm* __cdecl TESPackage::*()
    // TESIdleForm* __cdecl TESPackage::*()
    // TESTopic* __cdecl TESPackage::*()
    // TESTopic* __cdecl TESPackage::*()
    // TESTopic* __cdecl TESPackage::*()
    // Script* __cdecl TESPackage::*()
    // Script* __cdecl TESPackage::*()
    // Script* __cdecl TESPackage::*()
    // void __cdecl TESPackage::*()
    // TESCombatStyle* __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(TESCombatStyle*)
    // const char* __cdecl TESPackage::*(PackageNS::CRIME_TYPE)
    // void __cdecl TESPackage::*()
    // void __cdecl TESPackage::*()
    // void __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*(TESFile*)
    // void __cdecl TESPackage::*(TESForm*)
    // bool __cdecl TESPackage::*(TESForm*)
    // void __cdecl TESPackage::*()
    // char* __cdecl TESPackage::*()
    // TESUseWeaponPackageData* __cdecl TESPackage::*()
    // TESPatrolPackageData* __cdecl TESPackage::*()
    // TESEscortPackageData* __cdecl TESPackage::*()
    // TESObjectREFR* __cdecl TESPackage::*(MobileObject*)
    // TESWorldSpace* __cdecl TESPackage::*(MobileObject*)
    // TESObjectCELL* __cdecl TESPackage::*(MobileObject*)
    // const NiPoint3 __cdecl TESPackage::*(MobileObject*)
    // unsigned int __cdecl TESPackage::*(MobileObject*)
    // unsigned int __cdecl TESPackage::*(MobileObject*)
    // TESObjectREFR* __cdecl TESPackage::*(MobileObject*)
    // LocationDescriptor* __cdecl TESPackage::*(MobileObject*)
    // TESWorldSpace* __cdecl TESPackage::*(MobileObject*)
    // TESObjectCELL* __cdecl TESPackage::*(MobileObject*)
    // const NiPoint3 __cdecl TESPackage::*(MobileObject*)
    // TESObjectREFR* __cdecl TESPackage::*(MobileObject*)
    // TESObjectCELL* __cdecl TESPackage::*(MobileObject*)
    // const NiPoint3 __cdecl TESPackage::*(MobileObject*)
    // unsigned int __cdecl TESPackage::*(MobileObject*)
    // const TESUseWeaponPackageData* __cdecl TESPackage::*()
    // const TESPatrolPackageData* __cdecl TESPackage::*()
    // const TESFollowPackageData* __cdecl TESPackage::*()
    // const TESEscortPackageData* __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*(MobileObject*, float)
    // int __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*(Actor*)
    // PACKAGE_PROCEDURE_TYPE __cdecl TESPackage::*()
    // void __cdecl TESPackage::*(PACKAGE_PROCEDURE_TYPE)
    // void __cdecl TESPackage::*(TESObjectREFR*)
    // TESObjectREFR* __cdecl TESPackage::*(Actor*, bool)
    // int __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*(TESObjectREFR*, long)
    // int __cdecl TESPackage::*(DurationData*)
    // bool __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*(MobileObject*)
    // bool __cdecl TESPackage::*(bool)
    // SaveGame
    // LoadGame
    // InitLoadGame
    // Revert
    // void __cdecl TESPackage::*(BGSLoadFormBuffer*)
    // unsigned int __cdecl TESPackage::*()
    // unsigned int __cdecl TESPackage::*()
    // unsigned int __cdecl TESPackage::*()
    // bool __cdecl TESPackage::*(TESForm*, PACKAGE_OBJECT_TYPE)
    // PACKAGE_OBJECT_TYPE __cdecl TESPackage::*(TESForm*)
    // char* __cdecl TESPackage::*()
    // float __cdecl TESPackage::*(MobileObject*, bool)
    // float __cdecl TESPackage::*(MobileObject*, bool)
    // float __cdecl TESPackage::*(MobileObject*, bool)
    // unsigned int __cdecl TESPackage::*()
    // TESPackage& __cdecl TESPackage::*(const TESPackage&)
    // void __cdecl TESPackage::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESPackage) == 128);
FNV_STATIC_ASSERT(offsetof(TESPackage, m_eProcedureType) == 24);
FNV_STATIC_ASSERT(offsetof(TESPackage, StridedDataTransfer) == 28);
FNV_STATIC_ASSERT(offsetof(TESPackage, m_pPackageData) == 40);
FNV_STATIC_ASSERT(offsetof(TESPackage, m_pPackageLocation) == 44);
FNV_STATIC_ASSERT(offsetof(TESPackage, m_pTargetRecord) == 48);
FNV_STATIC_ASSERT(offsetof(TESPackage, m_pIdleCollection) == 52);
FNV_STATIC_ASSERT(offsetof(TESPackage, m_kSchedule) == 56);
FNV_STATIC_ASSERT(offsetof(TESPackage, m_kConditions) == 64);
FNV_STATIC_ASSERT(offsetof(TESPackage, m_pCombatStyle) == 72);
FNV_STATIC_ASSERT(offsetof(TESPackage, OnBegin) == 76);
FNV_STATIC_ASSERT(offsetof(TESPackage, OnEnd) == 92);
FNV_STATIC_ASSERT(offsetof(TESPackage, OnChange) == 108);
FNV_STATIC_ASSERT(offsetof(TESPackage, m_uiRefCount) == 124);
#endif
