// Source layout: PlayerCharacter. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_PLAYERCHARACTER_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_PLAYERCHARACTER_H
#include "interface_rebase_layout_support.h"
#include "interface_rebase_Character.h"
class PlayerCharacter : public Character
{
  public:
    Animation* GetAnimation(bool firstPerson) const;
    enum ModifierGroup
    {
        TEMPORARY = 0,
        SCRIPTS = 1,
        DAMAGE = 2
    };
    unsigned char layoutPadding1C8[124];
    float ActorValueModifierData[77];  // +0x244
    float m_afScriptModifiers[77];     // +0x378
    float ActorValueState;             // +0x4AC
    float ActorValueData[77];          // +0x4B0
    unsigned char layoutPadding5E4[104];
    bool bThirdPerson;  // +0x64C
    unsigned char layoutPadding64D[51];
    unsigned char m_ucValueAt680;  // +0x680
    unsigned char layoutPadding681[15];
    Animation* p1stPersonAnimation;  // +0x690, JG name / JIP PC offset
    unsigned char layoutPadding694[36];
    TESQuest* m_pCurrentQuest;                          // +0x6B8
    BSSimpleList<BGSQuestObjective*> m_kObjectiveList;  // +0x6BC
    unsigned char layoutPadding6C4[244];
    unsigned char m_ucByteAtOffset7B8;  // +0x7B8
    unsigned char layoutPadding7B9[3];
    bool m_bHasPerks;  // +0x7BC
    unsigned char layoutPadding7BD[191];
    BSSimpleList<PerkForm*> Perks;                             // +0x87C
    BSSimpleList<BGSEntryPointPerkEntry*> m_kEntryPointPerks[74];  // +0x884
    BSSimpleList<PerkForm*> m_kCompanionPerks;                 // +0xAD4
    unsigned char layoutPaddingADC[884];
    float GetActorValueModifierAmount(ModifierGroup modifier, ActorValue::Index actorValue);
    virtual int GetActorValue(ActorValue::Index actorValue);
};
FNV_STATIC_ASSERT(sizeof(PlayerCharacter) == 0xE50);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, p1stPersonAnimation) == 0x690);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, ActorValueModifierData) == 0x244);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, m_afScriptModifiers) == 0x378);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, ActorValueState) == 0x4AC);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, ActorValueData) == 0x4B0);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, bThirdPerson) == 0x64C);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, m_ucValueAt680) == 0x680);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, m_pCurrentQuest) == 0x6B8);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, m_kObjectiveList) == 0x6BC);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, m_ucByteAtOffset7B8) == 0x7B8);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, m_bHasPerks) == 0x7BC);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, Perks) == 0x87C);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, m_kEntryPointPerks) == 0x884);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, m_kCompanionPerks) == 0xAD4);
#endif
