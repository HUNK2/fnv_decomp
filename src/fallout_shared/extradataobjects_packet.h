// Authored header for fallout_shared/extradataobjects.cpp hand matches.
//
// BSExtraData is declared locally (not included from the canonical tree)
// because the canonical BSExtraData.h carries layout only, while every Extra
// constructor below must invoke the base initializer BSExtraData(etype) (the
// 0x0040ec80 call that stores the base vtable, the type tag and a null next
// pointer before the derived vtable store). Request: promote
// BSExtraData(unsigned char) into the canonical BSExtraData.h so this local
// declaration can be replaced by the canonical include; layouts here are
// identical to the canonical ones.
//
// with their layout asserts; only matched member-function declarations are
// existed), so its two members come from the 0x00414010 ctor bytes (8-byte
// construction: pointer at +0x0, float at +0x4) and the operator new(8)
// construction sites. Each Extra class declares its virtual destructor so
// the compiler emits the vtable store the originals contain.
#ifndef FNV_EXTRADATAOBJECTS_H
#define FNV_EXTRADATAOBJECTS_H

#include "layout_support.h"

class TESObjectREFR;
class TESObjectCELL;
class TESGlobal;
class TESKey;
class Script;
class ScriptLocals;
class RagDollData;
class Point3Offset;
class TESForm;

#pragma pack(push, 4)
class BSExtraData
{
  public:
    // Promoted form: the compiler vptr occupies +0x0, so the explicit
    unsigned char m_ucExtraDataType;  // +0x4
    unsigned char layoutPadding5[3];
    BSExtraData* pNext;  // +0x8

    virtual ~BSExtraData();
    BSExtraData(unsigned char aEtype);
    bool Compare(BSExtraData*);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSExtraData) == 0xC);
FNV_STATIC_ASSERT(offsetof(BSExtraData, m_ucExtraDataType) == 0x4);
FNV_STATIC_ASSERT(offsetof(BSExtraData, pNext) == 0x8);

// 8-byte activation record. Proved by the 0x00414010 ctor (stores a pointer
// at +0x0 and +0.0f at +0x4, no base construction) and by operator new(8)
// construction sites that fill +0x0 with a reference and link the record
// into a child list.
#pragma pack(push, 4)
class ReferenceFloatEntry
{
  public:
    TESObjectREFR* m_pWorldReferenceInfo;  // +0x0, 4 bytes
    float m_fDelay;               // +0x4, 4 bytes

    ReferenceFloatEntry();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ReferenceFloatEntry) == 8);
FNV_STATIC_ASSERT(offsetof(ReferenceFloatEntry, m_pWorldReferenceInfo) == 0);
FNV_STATIC_ASSERT(offsetof(ReferenceFloatEntry, m_fDelay) == 4);

// matched member-function declaration is added.
#pragma pack(push, 4)
class LockExtraData
{
  public:
    unsigned char m_uiLockState;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    TESKey* pKey;  // +0x4, 4 bytes
    char cFlags;   // +0x8, 1 bytes
    unsigned char layoutPadding9[3];
    unsigned int m_uiLockDifficulty;  // +0xC, 4 bytes
    unsigned int m_uiLockValue;       // +0x10, 4 bytes

    void SetLocked(bool aLocked);
    int GetLevel(TESObjectREFR*);
    static int ConvertLockLevel(int);
    int GetLockLevel(TESObjectREFR*);
    bool MeetsMinimumLockLevel();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(LockExtraData) == 20);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockState) == 0);
FNV_STATIC_ASSERT(offsetof(LockExtraData, pKey) == 4);
FNV_STATIC_ASSERT(offsetof(LockExtraData, cFlags) == 8);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockDifficulty) == 12);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockValue) == 16);

// matched member-function declarations are added.
#pragma pack(push, 4)
class ExtraUsedMarkers : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    unsigned int m_uiUsedMarkerFlags;  // +0xC, 4 bytes

    virtual ~ExtraUsedMarkers();
    void SetUsedMarker(unsigned int aMarker, bool aUsed);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraUsedMarkers) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraUsedMarkers, m_uiUsedMarkerFlags) == 12);

#pragma pack(push, 4)
class ExtraAction : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    unsigned char eAction;  // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
    TESObjectREFR* m_pActionReference;  // +0x10, 4 bytes

    virtual ~ExtraAction();
    ExtraAction();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraAction) == 20);
FNV_STATIC_ASSERT(offsetof(ExtraAction, eAction) == 12);
FNV_STATIC_ASSERT(offsetof(ExtraAction, m_pActionReference) == 16);

#pragma pack(push, 4)
class ExtraGlobal : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    TESGlobal* pGlobalForm;  // +0xC, 4 bytes

    virtual ~ExtraGlobal();
    ExtraGlobal(TESGlobal* aGlobal);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraGlobal) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraGlobal, pGlobalForm) == 12);

#pragma pack(push, 4)
class ExtraCount : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    short iCount;  // +0xC, 2 bytes
    unsigned char layoutPaddingE[2];

    virtual ~ExtraCount();
    ExtraCount(short aCount);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraCount) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraCount, iCount) == 12);

#pragma pack(push, 4)
class ExtraScript : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    Script* pScript;          // +0xC, 4 bytes
    ScriptLocals* m_pLocals;  // +0x10, 4 bytes

    virtual ~ExtraScript();
    ExtraScript(Script* aScript);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraScript) == 20);
FNV_STATIC_ASSERT(offsetof(ExtraScript, pScript) == 12);
FNV_STATIC_ASSERT(offsetof(ExtraScript, m_pLocals) == 16);

#pragma pack(push, 4)
class ExtraLeveledItem : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    int iIndex;             // +0xC, 4 bytes
    bool m_bIsLeveledItem;  // +0x10, 1 bytes
    unsigned char layoutPadding11[3];

    virtual ~ExtraLeveledItem();
    ExtraLeveledItem(int aIndex);
    bool Compare(BSExtraData*);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraLeveledItem) == 20);
FNV_STATIC_ASSERT(offsetof(ExtraLeveledItem, iIndex) == 12);
FNV_STATIC_ASSERT(offsetof(ExtraLeveledItem, m_bIsLeveledItem) == 16);

#pragma pack(push, 4)
class ExtraPersistentCell : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    TESObjectCELL* m_pCell;  // +0xC, 4 bytes

    virtual ~ExtraPersistentCell();
    ExtraPersistentCell(TESObjectCELL* aCell);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraPersistentCell) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraPersistentCell, m_pCell) == 12);

#pragma pack(push, 4)
class ExtraRagDollData : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    RagDollData* m_pRagDollData;  // +0xC, 4 bytes

    virtual ~ExtraRagDollData();
    ExtraRagDollData();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraRagDollData) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraRagDollData, m_pRagDollData) == 12);

#pragma pack(push, 4)
class ExtraReservedMarkers : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    unsigned int m_uiReservedMarkers;  // +0xC, 4 bytes

    virtual ~ExtraReservedMarkers();
    ExtraReservedMarkers();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraReservedMarkers) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraReservedMarkers, m_uiReservedMarkers) == 12);

#pragma pack(push, 4)
class ExtraStartingWorldOrCell : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    TESForm* m_pStartingWorldOrCell;  // +0xC, 4 bytes

    virtual ~ExtraStartingWorldOrCell();
    ExtraStartingWorldOrCell();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraStartingWorldOrCell) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraStartingWorldOrCell, m_pStartingWorldOrCell) == 12);

#pragma pack(push, 4)
class ExtraMultiBoundData : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    Point3Offset* pBound;  // +0xC, 4 bytes

    virtual ~ExtraMultiBoundData();
    ExtraMultiBoundData();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraMultiBoundData) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraMultiBoundData, pBound) == 12);
#endif

extern char* DAT_011c6444;
class ExtraSecuritronFace
{
  public:
    static char* GetPersonality();
};
class ExtraLock
{
  public:
    char pad[12];
    LockExtraData* lock;
    void Unlock();
    void Lock();
};
template <class T> class NiTNewInterface;
template <class T, class A> class NiTArray
{
  public:
    void* vptr;
    T* data;
    T& GetAt(unsigned int);
};
enum MagicSystem__CastingType
{
    CastingTypeNone
};
class TESEnchantableForm
{
  public:
    void SetCastingType(MagicSystem__CastingType);
};
class BaseProcess
{
  public:
    int vptr;
    TESEnchantableForm procedure;
    void SetPackageInfoState(int);
};
class NavMeshInfo;
class TESForm
{
  public:
    unsigned int GetFormID();
};
class Actor : public TESForm
{
};
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    template <class U> unsigned int Find(U&, unsigned int, bool(__cdecl*)(U&, U&));
    unsigned int Add(T&);
};
bool __cdecl FUN_009a3830(NavMeshInfo*&, NavMeshInfo*&);
class ExtraGuardedRefData
{
  public:
    char pad[12];
    BSSimpleArray<NavMeshInfo*, 1024> guards;
    void AddGuardingActor(Actor*);
};

extern char DAT_01183b2c;
extern char DAT_01184680;
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
class TESFaction;
class BGSPerkEntry
{
  public:
    TESFaction* faction;
};
class QuestDialogueInfo;
class TESTopic
{
  public:
    BSSimpleList<QuestDialogueInfo*>* GetQuestInfoList() const;
};
class ExtraFactionChanges
{
  public:
    bool HasFactionEntry(TESFaction*);
};
class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
void __cdecl ApplyPerkModifiers(int, Actor*, ...);
