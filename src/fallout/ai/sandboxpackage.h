// Fallout: New Vegas - original source reconstruction.
// Original: platforms/common/code/fallout/ai/sandboxpackage.cpp
//
// Unit-local declarations for SandBoxActorPackageData save/load, location,
// activity-window and procedure-selection helpers. Layouts for
// SandBoxActorPackageData, SandboxProcedureData, Calendar and the
// BSSimpleArray<SandboxProcedureData, 1024> instantiation are copied verbatim
// layout, PC equivalence unproven), with out-of-line method declarations
// appended (non-virtual additions do not affect layout). TimeGlobal mirrors
// the community Timer/TimeGlobal layout (JIP LN NVSE nvse/GameData.h,
// the folded [ecx+0x14] millisecond getter at 0x825C00.
#ifndef FNV_SANDBOXPACKAGE_H
#define FNV_SANDBOXPACKAGE_H


#define TimeGlobal SandboxSharedTimeGlobal
#define g_timeGlobal g_sandboxSharedTimeGlobal
#include "layout_support.h"
#undef g_timeGlobal
#undef TimeGlobal
#include "Actor.h"
#include "TESForm.h"
#include "TESGlobal.h"
#include "TESObjectREFR.h"

#ifndef NULL
#define NULL 0
#endif

class BGSLoadFormBuffer;

class SandBoxActorPackageData;
class SandboxProcedureData;
enum SandBoxActorPackageData__SANDBOX_STATE
{
    SandBoxActorPackageData__SANDBOX_STATE_SANDBOX_STATE_INIT = 0,
    SandBoxActorPackageData__SANDBOX_STATE_SANDBOX_STATE_GETTING_UP = 1,
    SandBoxActorPackageData__SANDBOX_STATE_SANDBOX_STATE_MOVING = 2,
    SandBoxActorPackageData__SANDBOX_STATE_SANDBOX_STATE_DOINGSTUFF = 3,
    SandBoxActorPackageData__SANDBOX_STATE_NUM_SANDBOX_STATES = 4
};
enum SANDBOX_PROCEDURE
{
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_NONE = -1,
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_SIT = 0,
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_SLEEP = 1,
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_EAT = 2,
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_WANDER = 3,
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_USE_IDLE_MARKER = 4,
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_DIALOGUE = 5,
    SANDBOX_PROCEDURE_NUM_SANDBOX_PROCEDURES = 6
};
enum SANDBOX_ACTIVITY
{
    SANDBOX_ACTIVITY_SANDBOX_ACTIVITY_NONE = -1,
    SANDBOX_ACTIVITY_SANDBOX_ACTIVITY_SLEEP = 0,
    SANDBOX_ACTIVITY_SANDBOX_ACTIVITY_BREAKFAST = 1,
    SANDBOX_ACTIVITY_SANDBOX_ACTIVITY_LUNCH = 2,
    SANDBOX_ACTIVITY_SANDBOX_ACTIVITY_DINNER = 3,
    SANDBOX_ACTIVITY_NUM_SANDBOX_ACTIVITIES = 4
};
#pragma pack(push, 4)
class ActorPackageData
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ActorPackageData) == 4);
FNV_STATIC_ASSERT(offsetof(ActorPackageData, m_ppVirtualMethodTable) == 0);
#pragma pack(push, 4)
class SandboxProcedureData
{
  public:
    TESObjectREFR* pTarget;        // +0x0, 4 bytes
    SANDBOX_PROCEDURE eProcedure;  // +0x4, 4 bytes
    int m_iActivityState;          // +0x8, 4 bytes
    int m_iProcedureData;          // +0xC, 4 bytes
    // Unit-local out-of-line declarations (owned by other units except
    // SandboxProcedureData::LoadGame/InitLoadGame targets as noted).
    TESObjectREFR* GetTarget();
    SANDBOX_PROCEDURE GetProcedure();
    void LoadGame(BGSLoadFormBuffer* apBuffer);
    void InitLoadGame(BGSLoadFormBuffer* apBuffer);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SandboxProcedureData) == 16);
FNV_STATIC_ASSERT(offsetof(SandboxProcedureData, pTarget) == 0);
FNV_STATIC_ASSERT(offsetof(SandboxProcedureData, eProcedure) == 4);
FNV_STATIC_ASSERT(offsetof(SandboxProcedureData, m_iActivityState) == 8);
FNV_STATIC_ASSERT(offsetof(SandboxProcedureData, m_iProcedureData) == 12);
#pragma pack(push, 4)
class SandBoxActorPackageData : public ActorPackageData
{
  public:
    // base ActorPackageData at +0x0, size 4
    SandBoxActorPackageData__SANDBOX_STATE eState;               // +0x4, 4 bytes
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
    unsigned char layoutPadding41[3];
    TESObjectREFR* m_pCurrentFurniture;   // +0x44, 4 bytes
    unsigned int m_uiActivityStartDay;    // +0x48, 4 bytes
    unsigned int m_uiActivityEndDay;      // +0x4C, 4 bytes
    float m_fActivityStartHour;           // +0x50, 4 bytes
    float m_fActivityEndHour;             // +0x54, 4 bytes
    SANDBOX_ACTIVITY m_eSandboxActivity;  // +0x58, 4 bytes
    unsigned char m_ucProcedureFlags[6];  // +0x5C, 6 bytes
    unsigned char layoutPadding62[2];
    // Covered functions of this unit.
    bool IsLocationCheckDue();
    bool IsActivityTime();
    void SetReferenceTarget(TESObjectREFR* apDeletedRef);
    bool HasProcessTarget(Actor* apActor);
    void LoadGame(BGSLoadFormBuffer* apBuffer);
    void InitLoadGame(BGSLoadFormBuffer* apBuffer);
    // Other-unit-owned methods called from this unit.
    bool HasActivityEnded(bool* apbEndedToday);
    bool IsActivityProcedure();
    float GetHourDifference(float afLastTime, float afNow);
    bool IsActorWithinLocationRadius(Actor* apActor, bool abFlag);
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

// BSSimpleArray out-of-line helpers owned by other units. GetSize/GetAt come
// from the shared template; SetSize/RemoveAt need a derived declaration.
class SandboxChoiceArray : public BSSimpleArray<SandboxProcedureData, 1024>
{
  public:
    void SetSize(unsigned int auSize, bool abFlag);
    void RemoveAt(unsigned int auIndex, unsigned int auCount);
};

#pragma pack(push, 4)
class Calendar
{
  public:
    TESGlobal* m_pYearGlobal;            // +0x0, 4 bytes
    TESGlobal* m_pMonthGlobal;           // +0x4, 4 bytes
    TESGlobal* m_pDayGlobal;             // +0x8, 4 bytes
    TESGlobal* m_pHourGlobal;            // +0xC, 4 bytes
    TESGlobal* m_pGameDaysPassedGlobal;  // +0x10, 4 bytes
    TESGlobal* pHourGlobal;              // +0x14, 4 bytes
    unsigned int m_uiDaysPassed;         // +0x18, 4 bytes
    // Unit-local out-of-line declarations.
    unsigned int GetDaysPassed();
    float GetGameTime();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Calendar) == 28);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pYearGlobal) == 0);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pMonthGlobal) == 4);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pDayGlobal) == 8);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pHourGlobal) == 12);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pGameDaysPassedGlobal) == 16);
FNV_STATIC_ASSERT(offsetof(Calendar, pHourGlobal) == 20);
FNV_STATIC_ASSERT(offsetof(Calendar, m_uiDaysPassed) == 24);
extern Calendar g_calendar;

// Community-evidenced global timer (JIP LN NVSE GameData.h Timer/TimeGlobal,
// millisecond getter at 0x825C00.
class TimeGlobal
{
  public:
    unsigned char disableCounter;  // +0x0
    unsigned char pad01[3];
    float fpsClamp;           // +0x4
    float fpsClampRemainder;  // +0x8
    float secondsPassed;      // +0xC
    float lastSecondsPassed;  // +0x10
    unsigned int msPassed;    // +0x14
    unsigned int tickCount;   // +0x18
    unsigned int GetTimeStamp();
};
extern TimeGlobal g_timeGlobal;

// Minimal buffer declaration (same shape as the accepted actorpackagedata.h).
class BGSLoadFormBuffer
{
  public:
    void ReadTypedData(void* apData, unsigned int auSize);
    bool ReadFormIdentifier(void* apFormID);
    int ReadElementCount();
};

// Minimal region-point declaration (GetX binding ?GetX@RegionPoint@@QAEMXZ).
class RegionPoint
{
  public:
    float GetX();
};

// Other-unit-owned ExtraDataList/TESObjectREFR out-of-line helpers reached
// through subclass casts (no layout change, no bytes).
class ExtraDataListHelper : public ExtraDataList
{
  public:
    TESObjectREFR* GetLinkedRef();
    RegionPoint* GetStartingPositionData();
};
class TESObjectREFRHelper : public TESObjectREFR
{
  public:
    void SetTargetingState(bool abTargeted);
    bool IsReferenceActive(bool abFlag);
    void SetMarkerState(unsigned char abMarker, bool abReserved);
    bool IsMarkerAvailable(unsigned char abMarker, bool abFlag);
};

class SandboxTargetInfo
{
  public:
    bool CheckFoodMarker();
    bool CheckBedMarker();
    bool CheckChairMarker();
};
class ActorTargetSource
{
  public:
    SandboxTargetInfo* GetProcessTarget();
};

// Other-unit-owned free helpers.
TESForm* GetFormByID(unsigned int auFormID);
bool IsValidSandboxProcedure(int aiProcedure);

// Activity -> procedure table at 0x11A5F3C.
extern SANDBOX_PROCEDURE g_procedureForActivity[4];

#endif
