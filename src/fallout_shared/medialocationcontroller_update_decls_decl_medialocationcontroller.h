// Private declarations for MediaLocationController::Update.
// Existing class layouts are retained; only out-of-line declarations are added.
#ifndef FNV_MEDIALOCATIONCONTROLLER_UPDATE_DECLS_H
#define FNV_MEDIALOCATIONCONTROLLER_UPDATE_DECLS_H

// Unit-local header for fallout_shared/medialocationcontroller.cpp.
#ifndef FNV_MEDIALOCATIONCONTROLLER_UNIT_H
#define FNV_MEDIALOCATIONCONTROLLER_UNIT_H
#include "layout_support.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "layout_support.h"
class MediaLocationController;
class MediaSet;
enum FIGHT_REACTION
{
    FIGHT_REACTION_FIGHT_REACTION_NEUTRAL = 0,
    FIGHT_REACTION_FIGHT_REACTION_ENEMY = 1,
    FIGHT_REACTION_FIGHT_REACTION_ALLY = 2,
    FIGHT_REACTION_FIGHT_REACTION_FRIEND = 3,
    FIGHT_REACTION_FIGHT_REACTION_COUNT = 4
};
class MediaLocationController : public TESForm, public TESFullName
{
  public:
    MediaLocationController();
    // base TESForm at +0x0, size 24
    // base TESFullName at +0x18, size 12
    unsigned int m_fUpdateCooldown;  // +0x24, 4 bytes
    unsigned int m_uiFirstCounter;   // +0x28, 4 bytes
    unsigned int m_uiSecondCounter;  // +0x2C, 4 bytes
    unsigned int m_uiThirdCounter;   // +0x30, 4 bytes
    bool bIsActive;                  // +0x34, 1 bytes
    bool m_bCountWasNonzero;         // +0x35, 1 bytes
    bool m_bActorStateFlag;          // +0x36, 1 bytes
    bool m_bConditionWasTrue;        // +0x37, 1 bytes
    bool m_bConditionActive;         // +0x38, 1 bytes
    unsigned char layoutPadding39[3];
    float m_fLocationDistance;                     // +0x3C, 4 bytes
    unsigned int m_uiPerceivedActorCount;          // +0x40, 4 bytes
    unsigned int m_uiPreviousPerceivedActorCount;  // +0x44, 4 bytes
    FIGHT_REACTION m_eCurrentFightReaction;        // +0x48, 4 bytes
    char m_cMediaState;                            // +0x4C, 1 bytes
    unsigned char layoutPadding4D[3];
    MediaSet* m_pMediaSet;                     // +0x50, 4 bytes
    TESFullName m_kLocationName;               // +0x54, 12 bytes
    TESFaction* pFaction;                      // +0x60, 4 bytes
    FIGHT_REACTION m_eRequiredFightReaction;   // +0x64, 4 bytes
    TESObjectREFR* m_pReference;               // +0x68, 4 bytes
    int iFlags;                                // +0x6C, 4 bytes
    float m_fLowerWeightThreshold;             // +0x70, 4 bytes
    float m_fUpperWeightThreshold;             // +0x74, 4 bytes
    float m_fMediaSelectionValue;              // +0x78, 4 bytes
    float m_fUpdateInterval;                   // +0x7C, 4 bytes
    unsigned int m_uiShortDelay;               // +0x80, 4 bytes
    unsigned int m_uiLongDelay;                // +0x84, 4 bytes
    BSSimpleList<MediaSet*> m_kMediaSetList1;  // +0x88, 8 bytes
    BSSimpleList<MediaSet*> m_kMediaSetList2;  // +0x90, 8 bytes
    BSSimpleList<MediaSet*> m_kMediaSetList3;  // +0x98, 8 bytes
    BSSimpleList<MediaSet*> m_kMediaSetList4;  // +0xA0, 8 bytes
    BSSimpleList<MediaSet*> m_kMediaSetList5;  // +0xA8, 8 bytes
    BSSimpleList<MediaSet*> m_kMediaSetList6;  // +0xB0, 8 bytes
    virtual bool Load(TESFile* apFile);
    virtual void InitItem();
    void ProcessMediaSetList(BSSimpleList<MediaSet*>* apList);

  private:
    MediaSet* GetMediaSetFromList(BSSimpleList<MediaSet*>* apList);

  public:
    enum DEADREPFLAGS
    {
        DEADFACTION_CONDITIONAL_NEUTRAL,
        DEADFACTION_CONDITIONAL_ENEMY,
        DEADFACTION_CONDITIONAL_ALLY,
        DEADFACTION_CONDITIONAL_FRIEND,
        DEADFACTION_LOCATION,
        DEADFACTION_NONE
    };
    bool Update(bool abInCombat);
    bool IsMediaLocationActive();
    DEADREPFLAGS GetDeadRep();
    void ResetFormData();
    void ClearData();
};
FNV_STATIC_ASSERT(sizeof(MediaLocationController) == 184);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_fUpdateCooldown) == 36);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_uiFirstCounter) == 40);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_uiSecondCounter) == 44);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_uiThirdCounter) == 48);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, bIsActive) == 52);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_bCountWasNonzero) == 53);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_bActorStateFlag) == 54);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_bConditionWasTrue) == 55);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_bConditionActive) == 56);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_fLocationDistance) == 60);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_uiPerceivedActorCount) == 64);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_uiPreviousPerceivedActorCount) == 68);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_eCurrentFightReaction) == 72);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_cMediaState) == 76);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_pMediaSet) == 80);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_kLocationName) == 84);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, pFaction) == 96);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_eRequiredFightReaction) == 100);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_pReference) == 104);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, iFlags) == 108);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_fLowerWeightThreshold) == 112);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_fUpperWeightThreshold) == 116);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_fMediaSelectionValue) == 120);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_fUpdateInterval) == 124);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_uiShortDelay) == 128);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_uiLongDelay) == 132);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_kMediaSetList1) == 136);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_kMediaSetList2) == 144);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_kMediaSetList3) == 152);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_kMediaSetList4) == 160);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_kMediaSetList5) == 168);
FNV_STATIC_ASSERT(offsetof(MediaLocationController, m_kMediaSetList6) == 176);
#endif
#ifndef FNV_MEDIASET_LOCAL_H
#define FNV_MEDIASET_LOCAL_H
#include "layout_support.h"
#include "TESForm.h"
#include "TESFullName.h"
class MediaSet : public TESForm, public TESFullName
{
  public:
    class MediaSetEntry
    {
      public:
        BSStringT<char> Name;
        float Attenuation;
        float Percent;
        MediaSetEntry();
    };
    enum MEDIASETTYPE
    {
        BATTLE = 0,
        LAYER_LOCATION = 1,
        LAYER_DUNGEON = 2,
        INCIDENTAL = 3,
        SETTYPE_COUNT = 4
    };
    unsigned int m_uiMediaValue1;
    unsigned int m_uiMediaValue2;
    unsigned int m_uiMediaValue3;
    bool bEffectFlag;
    bool m_bActorStateFlag;
    bool m_bCountWasNonzero;
    bool m_bConditionWasTrue;
    char m_cMediaState;
    TESFullName m_kFullName;
    MEDIASETTYPE Type;
    MediaSetEntry m_kMediaSetEntry1;
    MediaSetEntry m_kMediaSetEntry2;
    MediaSetEntry m_kMediaSetEntry3;
    MediaSetEntry m_kMediaSetEntry4;
    MediaSetEntry m_kMediaSetEntry5;
    MediaSetEntry m_kMediaSetEntry6;
    char m_cMediaFlag;
    float m_fMediaParameter1;
    float fSkillValueBonus;
    float m_fMediaParameter3;
    float m_fMediaValue;
    TESSound* m_pSound1;
    TESSound* m_pSound2;
    void Reset();
    MEDIASETTYPE GetType();
    bool Update(unsigned int auiTime, bool abForce, MediaLocationController* apController);
};
FNV_STATIC_ASSERT(sizeof(MediaSet) == 0xC4);
FNV_STATIC_ASSERT(offsetof(MediaSet, m_kFullName) == 0x38);
FNV_STATIC_ASSERT(offsetof(MediaSet, m_kMediaSetEntry1) == 0x48);
FNV_STATIC_ASSERT(sizeof(MediaSet::MediaSetEntry) == 0x10);
FNV_STATIC_ASSERT(offsetof(MediaSet::MediaSetEntry, Name) == 0);
FNV_STATIC_ASSERT(offsetof(MediaSet::MediaSetEntry, Attenuation) == 8);
FNV_STATIC_ASSERT(offsetof(MediaSet::MediaSetEntry, Percent) == 12);
#endif

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& arOther) const;
    float GetSquaredXYLength() const;  // canonical binding for SqrXYLength()
};
FNV_STATIC_ASSERT(sizeof(NiPoint3) == 12);
class TESObjectREFR : public TESForm
{
  public:
    unsigned char refData[0x50];
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual NiPoint3* GetPos() const;
    float GetRadius();
};
FNV_STATIC_ASSERT(sizeof(TESObjectREFR) == 0x68);
class Actor : public TESObjectREFR
{
  public:
    bool HasFaction(TESFaction* apFaction);
};
struct ActorCombatEntry
{
    Actor* pActor;
    bool m_bIsEnemy;
    bool m_bIsCombatTarget;
};
FNV_STATIC_ASSERT(sizeof(ActorCombatEntry) == 8);
class MusicMarkerReference
{
  public:
    TESObjectREFR* m_pMarkerReference;
    void* m_pAudioMarkerData;
};
class PlayerCharacter : public Actor
{
  public:
    MusicMarkerReference* GetMusicMarkerReference();
    BSSimpleList<ActorCombatEntry*>* GetListofPerceivedActors();
};
extern PlayerCharacter* g_thePlayer;
class TESFaction : public TESForm
{
  public:
    FIGHT_REACTION GetFactionReaction(TESFaction* apFaction);
};
enum DEFAULT_OBJECT
{
    DEFAULT_OBJECT_PLAYER_FACTION = 6
};
class BGSDefaultObjectManager
{
  public:
    static TESForm* GetDefaultObjectByIndex(int aeObject);
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    unsigned int GetSynchTime();
};
extern MediaLocationController* DAT_011dd374;
extern MediaLocationController* DAT_011dd378;
#endif
