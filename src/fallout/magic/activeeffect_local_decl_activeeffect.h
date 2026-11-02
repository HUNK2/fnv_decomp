// Unit-private declarations with layouts verified against the packet PC disassembly.
#ifndef FNV_ACTIVEFFECT_LOCAL_H
#define FNV_ACTIVEFFECT_LOCAL_H

#include "layout_support.h"
#include "magichiteffect_classes.h"
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char layoutPadding5[3];
    BSSoundHandle__ASSUMED_STATE eState;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
    bool IsSoundPlaying();
    bool Stop();
    bool PausePlayback();
};
class EffectSetting;
class EffectItem;
class MagicHitEffect;
class MagicCaster;
class MagicTarget;
class MagicItem;
class TESBoundObject;
class Actor;
class BGSLoadFormBuffer;
class BGSPerkEntry;
class BGSSaveFormBuffer;
template <typename T> class BSSimpleList;
enum MagicSystem__SpellType
{
    MagicSystem__SpellType_SPELL = 0,
    MagicSystem__SpellType_DISEASE = 1,
    MagicSystem__SpellType_POWER = 2,
    MagicSystem__SpellType_LESSER_POWER = 3,
    MagicSystem__SpellType_ABILITY = 4,
    MagicSystem__SpellType_POISON = 5,
    MagicSystem__SpellType_ENCHANTMENT = 6,
    MagicSystem__SpellType_POTION = 7,
    MagicSystem__SpellType_WORTCRAFT = 8,
    MagicSystem__SpellType_LEVELED_SPELL = 9,
    MagicSystem__SpellType_ADDICTION = 10,
    MagicSystem__SpellType_SPELL_TYPE_COUNT = 11
};
#pragma pack(push, 4)
class ActiveEffect
{
  public:
    virtual ~ActiveEffect();                                    // v00
    virtual ActiveEffect* Copy();                               // v04
    virtual void Finalize();                                    // v08
    virtual void Update(float afElapsedSeconds);                // v0C
    virtual unsigned short GetSaveSize(Actor* apActor);         // v10
    virtual void SaveGame(Actor* apActor);                      // v18
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);         // v14
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);         // v20
    virtual void LoadGame(Actor* apActor);                      // v1C
    virtual void InitLoadGame(Actor* apActor);                  // v28
    virtual void InitLoadGame(BGSLoadFormBuffer* apBuffer);     // v24
    virtual void FinishLoadGameTES(Actor* apActor);             // v2C
    virtual void Revert(Actor* apActor);                        // v34
    virtual void Revert(BGSLoadFormBuffer* apBuffer);           // v30
    virtual bool CanApply(MagicCaster* apCaster);               // v38
    virtual bool CanFinish();                                   // v3C
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer);  // v40
    virtual void CopyData(ActiveEffect* apOther);               // v44
    virtual bool CanCast(MagicCaster* apCaster);                // v48
    virtual bool IsEffectValid(MagicTarget* apTarget);          // v4C
    virtual void Start();                                       // v50
    virtual void Continue();                                    // v54
    virtual void Finish();                                      // v58
    ActiveEffect(MagicCaster*, MagicItem*, EffectItem*);
    void AddFlags(unsigned int);
    bool IsFlagged();
    bool HasFlag(unsigned int);
    float m_fEffectMagnitude;
    MagicItem* pSpell;
    EffectItem* pEffect;
    bool bActive;
    bool bEffectFlag;
    bool bWasPlaying;
    bool bPickResultFound;
    bool m_bEffectState;
    unsigned char layoutPadding15[3];
    int iFlags;
    float m_fElapsedTime;
    float fDuration;
    MagicTarget* pTarget;
    MagicCaster* m_pEffectInstance;
    MagicSystem__SpellType m_eSpellType;
    SoundPlaybackHandle m_kSoundHandle;
    TESBoundObject* pSource;
    BSSimpleList<MagicHitEffect*>* pHitEffectList;
    MagicItem* pMagicItem;
    bool FUN_007df210();
    void AdvanceEffect(float, bool);
    bool IsTerminated();
    bool FUN_00833c20();
    float GetAge();
    void SetEffectiveness(float);
    float FUN_007df1f0();
    float GetFloatAtOffset1C();
    void FUN_00693d50(float);
    void FUN_00804cb0(float);
    EffectSetting* GetEffectSetting();
    void ResetEffectState();
    static void LoadActiveEffectList(BGSLoadFormBuffer*, BSSimpleList<ActiveEffect*>*);
    static ActiveEffect* ReadActiveEffect(BGSLoadFormBuffer*);
    static void WriteActiveEffectList(BGSLoadFormBuffer* pBuffer, BSSimpleList<ActiveEffect*>* pList);
};
#pragma pack(pop)
template <> class BSSimpleList<BGSPerkEntry*>
{
  public:
    BGSPerkEntry*& GetItem();
    BSSimpleList<BGSPerkEntry*>* GetNext();
};
template <> class BSSimpleList<MagicHitEffect*>
{
  public:
    MagicHitEffect* m_item;
    BSSimpleList<MagicHitEffect*>* m_pkNext;
    MagicHitEffect*& GetItem();
    BSSimpleList<MagicHitEffect*>* GetNext();
    bool IsEmpty();
    void RemoveAll();
    void* scalar_deleting_dtor(unsigned int);
};
FNV_STATIC_ASSERT(sizeof(ActiveEffect) == 72);

FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_fEffectMagnitude) == 4);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pSpell) == 8);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pEffect) == 12);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, bActive) == 16);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, bEffectFlag) == 17);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, bWasPlaying) == 18);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, bPickResultFound) == 19);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_bEffectState) == 20);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, iFlags) == 24);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_fElapsedTime) == 28);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, fDuration) == 32);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pTarget) == 36);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_pEffectInstance) == 40);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_eSpellType) == 44);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, m_kSoundHandle) == 48);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pSource) == 60);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pHitEffectList) == 64);
FNV_STATIC_ASSERT(offsetof(ActiveEffect, pMagicItem) == 68);
class EffectSetting
{
  public:
    char data[0x98];
    int archetype;
    int GetArchetype();
    bool IsFlagSet(unsigned int);
    bool HasAllFlags(unsigned int);
};
class BGSLoadGameBuffer
{
  public:
    int ReadElementCount();
    bool ReadFormIdentifier(void*);
};
class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
  public:
    void ReadTypedData(void*, unsigned int);
};
template <> class BSSimpleList<ActiveEffect*>
{
  public:
    void Insert(ActiveEffect*, int (*)(ActiveEffect*, ActiveEffect*));
};
void FUN_00806ba0(BGSLoadFormBuffer*, BSSimpleList<ActiveEffect*>*);
void InitLoadGameForEffects(Actor*, BSSimpleList<ActiveEffect*>*);
class BSTempEffect;
class ProcessLists
{
  public:
    void RegisterTempEffect(BSTempEffect*);
};
class GlobalObject_0096d020 : public ProcessLists
{
};
extern GlobalObject_0096d020 g_011e0e80;
class PerkEntryConditionSet;
class EffectItem
{
  public:
    EffectSetting* GetEffectSetting();
    int GetMagnitude();
    int GetDuration();
    PerkEntryConditionSet* GetConditions();
};
class TESObjectREFR;
class PerkEntryConditionSet
{
  public:
    BGSPerkEntry*& GetItem();
    bool ContainsTrait(TESObjectREFR*, TESObjectREFR*);
};
float FUN_00404040(float);
class EffectItemList
{
  public:
    EffectItem* GetEffectItemAtIndex(unsigned char);
};
class MagicEffectSystem
{
  public:
    static ActiveEffect* Activate(MagicCaster*, MagicItem*, EffectItem*, TESBoundObject*);
};
class ActorPackageContext
{
  public:
    void AddToProcedureIndex(int);
};
void LogWarning(const char*, ...);
extern const char DAT_010794a8[];
template <> class BSSimpleList<const char*>
{
  public:
    bool IsEmpty();
};
class LowProcess
{
  public:
    TESObjectREFR* GetActiveCombatTarget();
};
class ActorMover
{
  public:
    unsigned int GetCurrentMoveModeType();
};
union SETTING_VALUE
{
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
class GlobalObject_0040e0b0 : public SettingT_GameSettingCollection_
{
};
extern GlobalObject_0040e0b0 g_011d17dc;
extern "C" double floor(float);
class ActiveEffectCasterDispatch
{
  public:
    virtual void vfn_00();
    virtual TESObjectREFR* GetCasterReference();
    virtual BSSimpleList<BGSPerkEntry*>* GetActiveEffectList();
};
class ActorPrimary
{
  public:
    virtual void vfn_00();
    char data[0x90];
};
class ActorValueOwner
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual int GetActorValue(int);
};
#endif
