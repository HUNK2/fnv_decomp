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
