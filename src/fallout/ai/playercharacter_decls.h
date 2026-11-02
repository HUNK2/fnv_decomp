// Private declarations for the playercharacter.h unit.
#ifndef FNV_PLAYERCHARACTER_UNIT_DECLS_H
#define FNV_PLAYERCHARACTER_UNIT_DECLS_H

#include "layout_support.h"
class TESObjectWEAP;
class ActorCombatGroup;
class Animation;
class BSAnimGroupSequence;
enum ACTION_FLAGS
{
    ACTION_FLAGS_NONE = 0
};
enum ANIM_GROUP_SECTION
{
    ANIM_GROUP_SECTION_NONE = -1
};
class Animation
{
  public:
    BSAnimGroupSequence* FUN_00491040(ANIM_GROUP_SECTION section);
    BSAnimGroupSequence* GetSequenceForKey(BSAnimGroupSequence* sequence, unsigned short group);
    bool IsGroupQueued(unsigned short group);
    BSAnimGroupSequence* PlayGroup(unsigned short group, ACTION_FLAGS flags, int loops, ANIM_GROUP_SECTION section);
};
class TESAnimGroup
{
  public:
    static ANIM_GROUP_ENUM GetType(unsigned short group);
    static bool IsIronSightsAction(unsigned short group);
    static bool IsIronSightsAction(ANIM_GROUP_ENUM group);
};
struct PlayerCharacterAnimGroupInfo
{
    bool availableInThirdPerson;
    unsigned char layoutPadding1[3];
    ANIM_GROUP_SECTION section;
    unsigned char layoutPadding8[28];
};
extern PlayerCharacterAnimGroupInfo DAT_011977dc[];
FNV_STATIC_ASSERT(sizeof(PlayerCharacterAnimGroupInfo) == 0x24);
FNV_STATIC_ASSERT(offsetof(PlayerCharacterAnimGroupInfo, section) == 4);
// Source layout: PlayerCharacter. PC corrections are in generate_headers.py.
#ifndef FNV_PLAYERCHARACTER_H
#define FNV_PLAYERCHARACTER_H
#include "layout_support.h"
#include "playercharacter_actor_decls.h"
#include "../../../include/Character.h"
#pragma pack(push, 4)
class PlayerCharacter : public Character
{
  public:
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
    unsigned char layoutPadding681[55];
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
    unsigned char layoutPaddingADC[648];
    ActorCombatGroup* m_pCombatData;  // +0xD64
    unsigned char layoutPaddingD68[232];
    void SetActionGroupFlags(unsigned short group, ACTION_FLAGS flags);
    void ResetActorValueModifiers();
    ActorCombatGroup* GetCombatGroup();
    Animation* GetAnimation(bool firstPerson);
    float GetActorValueModifierAmount(ModifierGroup modifier, ActorValue::Index actorValue);
    virtual int GetActorValue(ActorValue::Index actorValue);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PlayerCharacter) == 0xE50);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, m_pCombatData) == 0xD64);
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

#endif
