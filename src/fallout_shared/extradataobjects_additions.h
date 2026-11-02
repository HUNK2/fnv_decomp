// Unit-private additions. No supplied header or accepted definition is changed.
#ifndef FNV_EXTRADATAOBJECTS_ADDITIONS_H
#define FNV_EXTRADATAOBJECTS_ADDITIONS_H

// Canonical callable identities from IDENTITIES.md. Settings named by
// JohnnyGuitarNVSE GameSettingCollection.hpp and JIP settings_enum.h.
union SETTING_VALUE
{
    int i;
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Int();
    SETTING_VALUE* Float();
};
class GameSettingCollection
{
  public:
    static SettingT_GameSettingCollection_ iLockLevelMaxVeryEasy;
    static SettingT_GameSettingCollection_ iLockLevelMaxEasy;
    static SettingT_GameSettingCollection_ iLockLevelMaxAverage;
    static SettingT_GameSettingCollection_ iLockLevelMaxHard;
    static SettingT_GameSettingCollection_ iLockLevelMaxVeryHard;
    static SettingT_GameSettingCollection_ fLeveledLockMult;
    static SettingT_GameSettingCollection_ iLockLevelMaxImpossible;
};

// Declaration source: include/NiPoint3.h; natural PC alignment.
// Source layout: NiPoint3. PC corrections are in generate_headers.py.
class NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
};
FNV_STATIC_ASSERT(sizeof(NiPoint3) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiPoint3, x) == 0x0);
FNV_STATIC_ASSERT(offsetof(NiPoint3, y) == 0x4);
FNV_STATIC_ASSERT(offsetof(NiPoint3, z) == 0x8);

// Names of nested/template specializations use the canonical generator identifier mapping.
class ReferenceIntersectionData;
class ReferenceIntersectionData
{
  public:
    TESObjectREFR* m_pHitReference;  // +0x0, 4 bytes
    NiPoint3 Intersect;              // +0x4, 12 bytes
    NiPoint3 Normal;                 // +0x10, 12 bytes
};
FNV_STATIC_ASSERT(sizeof(ReferenceIntersectionData) == 28);
FNV_STATIC_ASSERT(offsetof(ReferenceIntersectionData, m_pHitReference) == 0);
FNV_STATIC_ASSERT(offsetof(ReferenceIntersectionData, Intersect) == 4);
FNV_STATIC_ASSERT(offsetof(ReferenceIntersectionData, Normal) == 16);

// Names of nested/template specializations use the canonical generator identifier mapping.
class ExtraHealth;
class ExtraHealth : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    float fHealthPercent;  // +0xC, 4 bytes
    bool Compare(BSExtraData* extra);
    // ExtraHealth
    // bool __cdecl ExtraHealth::*(BSExtraData*)
    // void __cdecl ExtraHealth::*()
    // ExtraHealth& __cdecl ExtraHealth::*(const ExtraHealth&)
    // void __cdecl ExtraHealth::*()
};
FNV_STATIC_ASSERT(sizeof(ExtraHealth) == 16);
FNV_STATIC_ASSERT(offsetof(ExtraHealth, fHealthPercent) == 12);

// Names of nested/template specializations use the canonical generator identifier mapping.
class ExtraDecalRefs;
class ReferenceIntersectionData;
class ExtraDecalRefs : public BSExtraData
{
  public:
    // base BSExtraData at +0x0, size 12
    BSSimpleList<ReferenceIntersectionData*> m_kDecalReferences;  // +0xC, 8 bytes
    ReferenceIntersectionData* FindDecalReference(TESObjectREFR*);
    // ExtraDecalRefs
    // void __cdecl ExtraDecalRefs::*()
    // void __cdecl ExtraDecalRefs::*(TESForm*)
    // bool __cdecl ExtraDecalRefs::*(BSExtraData*)
    // void __cdecl ExtraDecalRefs::*(BSExtraData*)
    // void __cdecl ExtraDecalRefs::*()
    // void __cdecl ExtraDecalRefs::*(TESObjectREFR*)
    // void __cdecl ExtraDecalRefs::*(TESObjectREFR*, const NiPoint3&, const NiPoint3&)
    // ExtraDecalRefs& __cdecl ExtraDecalRefs::*(const ExtraDecalRefs&)
    // void __cdecl ExtraDecalRefs::*()
};
FNV_STATIC_ASSERT(sizeof(ExtraDecalRefs) == 20);
FNV_STATIC_ASSERT(offsetof(ExtraDecalRefs, m_kDecalReferences) == 12);

// independently declares these names/types and the PC8-byte record layout.
class FactionReaction
{
  public:
    TESFaction* pFaction;
    char m_ucRank;
};
FNV_STATIC_ASSERT(sizeof(FactionReaction) == 8);
FNV_STATIC_ASSERT(offsetof(FactionReaction, pFaction) == 0);
FNV_STATIC_ASSERT(offsetof(FactionReaction, m_ucRank) == 4);
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* pointer);

void* __cdecl operator new[](unsigned int size);
void __cdecl operator delete[](void* pointer);
extern "C" void* __cdecl memcpy(void* destination, const void* source, unsigned int size);

// Public names/layout: JohnnyGuitarNVSE BGSQuestObjective.hpp; its cpp
// explicitly annotates SetOwner as GAME00437730. No implementation copied.
class TESQuest;
class RegionObjectEntry;
class BGSQuestObjective
{
  public:
    BGSQuestObjective();
    virtual ~BGSQuestObjective();
    struct _State
    {
        enum State
        {
            DORMANT = 0,
            DISPLAYED = 1,
            COMPLETED = 2,
            COMPLETED_DISPLAYED = 3
        };
    };
    typedef _State::State State;
    unsigned int uiIndex;
    BSStringT<char> QuestObjectiveEntry;
    TESQuest* m_pOwnerQuest;
    BSSimpleList<RegionObjectEntry*> kTargets;
    bool bInitialized;
    State eState;
    void SetOwner(TESQuest*);
};
FNV_STATIC_ASSERT(sizeof(BGSQuestObjective) == 0x24);
FNV_STATIC_ASSERT(offsetof(BGSQuestObjective, uiIndex) == 4);
FNV_STATIC_ASSERT(offsetof(BGSQuestObjective, QuestObjectiveEntry) == 8);
FNV_STATIC_ASSERT(offsetof(BGSQuestObjective, m_pOwnerQuest) == 0x10);
FNV_STATIC_ASSERT(offsetof(BGSQuestObjective, kTargets) == 0x14);
FNV_STATIC_ASSERT(offsetof(BGSQuestObjective, bInitialized) == 0x1C);
FNV_STATIC_ASSERT(offsetof(BGSQuestObjective, eState) == 0x20);
#endif
