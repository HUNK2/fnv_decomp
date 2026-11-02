// Fallout: New Vegas - original source reconstruction.
// Original: platforms/common/code/fallout/ai/actorpackagedata.h
//
// Unit-local declarations for ActorPackageData::CreatePackageData.
// ActorPackageData, EscortActorPackageData, PatrolActorPackageData and PTYPE are
// CodeView layout, PC equivalence unproven). GuardActorPackageData,
// SandBoxActorPackageData and UseWeaponActorPackageData are rendered from their
// the constructor disassembly (SandBox ctor zeroes m_ucProcedureFlags[6] at
// +0x5c; UseWeapon ctor stores only m_pUseTarget at +0x4).
// The PTYPE enumerator names follow the accepted guardpackage.h; the values
// USEWEAPON=16).
#ifndef FNV_TASK_ACTORPACKAGEDATA_UNIT_H
#define FNV_TASK_ACTORPACKAGEDATA_UNIT_H


#include "layout_support.h"

class Actor;
class TESPackage;
class TESObjectREFR;
class TESPatrolPackageData;
class TESEscortPackageData;
class SandboxProcedureData;

typedef enum
{
    PTYPE_NONE = -1,
    PTYPE_EXPLORE = 0,
    PTYPE_FOLLOW,
    PTYPE_ESCORT,
    PTYPE_EAT,
    PTYPE_SLEEP,
    PTYPE_WANDER,
    PTYPE_TRAVEL,
    PTYPE_ACCOMPANY,
    PTYPE_USEITEMAT,
    PTYPE_AMBUSH,
    PTYPE_FLEE_NON_COMBAT,
    PTYPE_CAST_MAGIC,
    PTYPE_SANDBOX,
    PTYPE_PATROL,
    PTYPE_GUARD,
    PTYPE_DIALOGUE,
    PTYPE_USEWEAPON,
    PTYPE_FIND,
    PTYPE_COMBAT,
    PTYPE_COMBAT_LOW,
    PTYPE_ACTIVATE,
    PTYPE_ALARM,
    PTYPE_FLEE,
    PTYPE_TRESPASS,
    PTYPE_SPECTATOR,
    PTYPE_GREET,
    PTYPE_GET_UP,
    PTYPE_DO_NOTHING,
    PTYPE_IN_GAME_DIALOGUE,
    PTYPE_SURFACE,
    PTYPE_SEARCH_FOR_ATTACKER,
    PTYPE_AVOID_RADIATION,
    PTYPE_EXPLOSION_REACTION,
    PTYPE_GRENDADE_MINE_REACTION,
    PTYPE_STEAL_WARNING,
    PTYPE_PICKPOCKET_WARNING,
    PTYPE_MOVEMENT_BLOCKED,
    PTYPE_SANDMAN,
    PTYPE_CANNIBAL,
    PTYPE_BACK_UP,
    PTYPE_COUNT
} PTYPE;

#pragma pack(push, 4)
class ActorPackageData
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
    static ActorPackageData* CreatePackageData(PTYPE aeType);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ActorPackageData) == 4);
FNV_STATIC_ASSERT(offsetof(ActorPackageData, m_ppVirtualMethodTable) == 0);

// above; constructor declaration added for the out-of-line ctor 0x009f0900).
#pragma pack(push, 4)
class EscortActorPackageData : public ActorPackageData
{
  public:
    // base ActorPackageData at +0x0, size 4
    Actor* pActor;                                     // +0x4, 4 bytes
    TESPackage* pPackage;                              // +0x8, 4 bytes
    const TESEscortPackageData* m_pEscortPackageData;  // +0xC, 4 bytes
    BSSimpleList<Actor*> m_kActorList;                 // +0x10, 8 bytes
    EscortActorPackageData();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(EscortActorPackageData) == 24);
FNV_STATIC_ASSERT(offsetof(EscortActorPackageData, pActor) == 4);
FNV_STATIC_ASSERT(offsetof(EscortActorPackageData, pPackage) == 8);
FNV_STATIC_ASSERT(offsetof(EscortActorPackageData, m_pEscortPackageData) == 12);
FNV_STATIC_ASSERT(offsetof(EscortActorPackageData, m_kActorList) == 16);

// above; forward declarations replace the header includes; constructor
// declaration added for the out-of-line ctor 0x009f29a0).
#pragma pack(push, 4)
class PatrolActorPackageData : public ActorPackageData
{
  public:
    // base ActorPackageData at +0x0, size 4
    enum PATROL_STATE
    {
        PATROL_STATE_INIT = 0,
        PATROL_STATE_TRAVELING_TO_NEXT_REF = 1,
        PATROL_STATE_AT_REF = 2,
        PATROL_STATE_DEBUG_ACTOR_DELETED = 3,
        PATROL_STATE_DEBUG_DESTRUCTED = 4
    };
    PATROL_STATE eState;       // +0x4, 4 bytes
    float m_fElapsedWaitTime;  // +0x8, 4 bytes
    bool m_bPatrolFlag;        // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
    Actor* pActor;                                     // +0x10, 4 bytes
    TESPackage* pPackage;                              // +0x14, 4 bytes
    const TESPatrolPackageData* m_pEscortPackageData;  // +0x18, 4 bytes
    BSSimpleArray<TESObjectREFR*, 1024> References;    // +0x1C, 16 bytes
    bool m_bReferenceFlag;                             // +0x2C, 1 bytes
    unsigned char layoutPadding2D[3];
    unsigned int m_uiValueAfterReferenceFlag;        // +0x30, 4 bytes
    unsigned int m_uiSecondValueAfterReferenceFlag;  // +0x34, 4 bytes
    PatrolActorPackageData();
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

#pragma pack(push, 4)
class GuardActorPackageData : public ActorPackageData
{
  public:
    // base ActorPackageData at +0x0, size 4
    enum GUARD_STATE
    {
        GUARD_STATE_INIT = 0,
        GUARD_STATE_IDLE = 1,
        GUARD_STATE_WAIT_TO_ATTACK = 2
    };
    GuardActorPackageData();
    GUARD_STATE eState;     // +0x4, 4 bytes
    Actor* pWarningTarget;  // +0x8, 4 bytes
    int iWarningCount;      // +0xC, 4 bytes
    float m_fWarningTimer;  // +0x10, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(GuardActorPackageData) == 20);
FNV_STATIC_ASSERT(offsetof(GuardActorPackageData, eState) == 4);
FNV_STATIC_ASSERT(offsetof(GuardActorPackageData, pWarningTarget) == 8);
FNV_STATIC_ASSERT(offsetof(GuardActorPackageData, iWarningCount) == 12);
FNV_STATIC_ASSERT(offsetof(GuardActorPackageData, m_fWarningTimer) == 16);

#pragma pack(push, 4)
class SandBoxActorPackageData : public ActorPackageData
{
  public:
    // base ActorPackageData at +0x0, size 4
    enum SANDBOX_STATE
    {
        SANDBOX_STATE_INIT = 0,
        SANDBOX_STATE_GETTING_UP = 1,
        SANDBOX_STATE_MOVING = 2,
        SANDBOX_STATE_DOINGSTUFF = 3,
        NUM_SANDBOX_STATES = 4
    };
    enum SANDBOX_PROCEDURE
    {
        SANDBOX_PROCEDURE_NONE = -1,
        SANDBOX_PROCEDURE_SIT = 0,
        SANDBOX_PROCEDURE_SLEEP = 1,
        SANDBOX_PROCEDURE_EAT = 2,
        SANDBOX_PROCEDURE_WANDER = 3,
        SANDBOX_PROCEDURE_USE_IDLE_MARKER = 4,
        SANDBOX_PROCEDURE_DIALOGUE = 5,
        NUM_SANDBOX_PROCEDURES = 6
    };
    enum SANDBOX_ACTIVITY
    {
        SANDBOX_ACTIVITY_NONE = -1,
        SANDBOX_ACTIVITY_SLEEP = 0,
        SANDBOX_ACTIVITY_BREAKFAST = 1,
        SANDBOX_ACTIVITY_LUNCH = 2,
        SANDBOX_ACTIVITY_DINNER = 3,
        NUM_SANDBOX_ACTIVITIES = 4
    };
    SandBoxActorPackageData();
    SANDBOX_STATE eState;                                        // +0x4, 4 bytes
    SANDBOX_PROCEDURE eProcedure;                                // +0x8, 4 bytes
    float m_fProcedureTime;                                      // +0xC, 4 bytes
    TESObjectREFR* pLocation;                                    // +0x10, 4 bytes
    float m_fLastProcedureCheckHour;                             // +0x14, 4 bytes
    float m_fNextProcedureCheckHour;                             // +0x18, 4 bytes
    unsigned int m_uiLastProcedureCheckDay;                      // +0x1C, 4 bytes
    BSSimpleArray<SandboxProcedureData, 1024> m_kProcedureList;  // +0x20, 16 bytes
    unsigned int m_uiProcedureIndex;                             // +0x30, 4 bytes
    bool m_bNeedsSandboxUpdate;                                  // +0x34, 1 bytes
    bool m_bHasFoodMarker;                                       // +0x35, 1 bytes
    bool m_bHasChairMarker;                                      // +0x36, 1 bytes
    bool m_bHasBedMarker;                                        // +0x37, 1 bytes
    int m_iSerializedValue;                                      // +0x38, 4 bytes
    TESObjectREFR* m_pCurrentTarget;                             // +0x3C, 4 bytes
    unsigned char m_ucProcedureIndex;                            // +0x40, 1 bytes
    TESObjectREFR* m_pCurrentFurniture;                          // +0x44, 4 bytes
    unsigned int m_uiActivityStartDay;                           // +0x48, 4 bytes
    unsigned int m_uiActivityEndDay;                             // +0x4C, 4 bytes
    float m_fActivityStartHour;                                  // +0x50, 4 bytes
    float m_fActivityEndHour;                                    // +0x54, 4 bytes
    SANDBOX_ACTIVITY m_eSandboxActivity;                         // +0x58, 4 bytes
    unsigned char m_ucProcedureFlags[NUM_SANDBOX_PROCEDURES];    // +0x5C, 6 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SandBoxActorPackageData) == 100);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, eState) == 4);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, eProcedure) == 8);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_fProcedureTime) == 12);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, pLocation) == 16);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_fLastProcedureCheckHour) == 20);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_fNextProcedureCheckHour) == 24);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_uiLastProcedureCheckDay) == 28);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_kProcedureList) == 32);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_uiProcedureIndex) == 48);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_bNeedsSandboxUpdate) == 52);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_bHasFoodMarker) == 53);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_bHasChairMarker) == 54);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_bHasBedMarker) == 55);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_iSerializedValue) == 56);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_pCurrentTarget) == 60);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_ucProcedureIndex) == 64);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_pCurrentFurniture) == 68);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_uiActivityStartDay) == 72);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_uiActivityEndDay) == 76);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_fActivityStartHour) == 80);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_fActivityEndHour) == 84);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_eSandboxActivity) == 88);
FNV_STATIC_ASSERT(offsetof(SandBoxActorPackageData, m_ucProcedureFlags) == 92);

#pragma pack(push, 4)
class UseWeaponActorPackageData : public ActorPackageData
{
  public:
    // base ActorPackageData at +0x0, size 4
    UseWeaponActorPackageData();
    TESObjectREFR* m_pUseTarget;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(UseWeaponActorPackageData) == 8);
FNV_STATIC_ASSERT(offsetof(UseWeaponActorPackageData, m_pUseTarget) == 4);

#endif
