// fallout_shared/tesraceform_decls.h: declares TESRace, TESRaceForm, BGSCameraPath, TESNPC
#ifndef FNV_TESRACEFORM_DECLS_H
#define FNV_TESRACEFORM_DECLS_H


namespace ActorValue {
enum Index
{
    ActorValue__Index_AGGRESSION = 0,
    ActorValue__Index_CONFIDENCE = 1,
    ActorValue__Index_ENERGY = 2,
    ActorValue__Index_RESPONSIBILITY = 3,
    ActorValue__Index_MOOD = 4,
    ActorValue__Index_STRENGTH = 5,
    ActorValue__Index_PERCEPTION = 6,
    ActorValue__Index_ENDURANCE = 7,
    ActorValue__Index_CHARISMA = 8,
    ActorValue__Index_INTELLIGENCE = 9,
    ActorValue__Index_AGILITY = 10,
    ActorValue__Index_LUCK = 11,
    ActorValue__Index_ACTION_POINTS = 12,
    ActorValue__Index_CARRY_WEIGHT = 13,
    ActorValue__Index_CRITICAL_CHANCE = 14,
    ActorValue__Index_HEALING_RATE = 15,
    ActorValue__Index_HEALTH = 16,
    ActorValue__Index_MELEE_DAMAGE = 17,
    ActorValue__Index_DAMAGE_RESISTANCE = 18,
    ActorValue__Index_POISON_RESISTANCE = 19,
    ActorValue__Index_RADIATION_RESISTANCE = 20,
    ActorValue__Index_SPEED_MULT = 21,
    ActorValue__Index_FATIGUE = 22,
    ActorValue__Index_KARMA = 23,
    ActorValue__Index_EXPERIENCE_POINTS = 24,
    ActorValue__Index_PERCEPTION_CONDITION = 25,
    ActorValue__Index_ENDURANCE_CONDITION = 26,
    ActorValue__Index_LEFT_ATTACK_CONDITION = 27,
    ActorValue__Index_RIGHT_ATTACK_CONDITION = 28,
    ActorValue__Index_LEFT_MOBILITY_CONDITION = 29,
    ActorValue__Index_RIGHT_MOBILITY_CONDITION = 30,
    ActorValue__Index_BRAIN_CONDITION = 31,
    ActorValue__Index_BARTER = 32,
    ActorValue__Index_BIG_GUNS = 33,
    ActorValue__Index_ENERGY_WEAPONS = 34,
    ActorValue__Index_EXPLOSIVES = 35,
    ActorValue__Index_LOCKPICK = 36,
    ActorValue__Index_MEDICINE = 37,
    ActorValue__Index_MELEE_WEAPONS = 38,
    ActorValue__Index_REPAIR = 39,
    ActorValue__Index_SCIENCE = 40,
    ActorValue__Index_SMALL_GUNS = 41,
    ActorValue__Index_SNEAK = 42,
    ActorValue__Index_SPEECH = 43,
    ActorValue__Index_SURVIVAL = 44,
    ActorValue__Index_UNARMED = 45,
    ActorValue__Index_INVENTORY_WEIGHT = 46,
    ActorValue__Index_PARALYSIS = 47,
    ActorValue__Index_INVISIBILITY = 48,
    ActorValue__Index_CHAMELEON = 49,
    ActorValue__Index_NIGHT_EYE_BONUS = 50,
    ActorValue__Index_TURBO = 51,
    ActorValue__Index_FIRE_RESISTANCE = 52,
    ActorValue__Index_WATER_BREATHING = 53,
    ActorValue__Index_RADIATION_RADS = 54,
    ActorValue__Index_BLOODY_MESS = 55,
    ActorValue__Index_UNARMED_DAMAGE = 56,
    ActorValue__Index_ASSISTANCE = 57,
    ActorValue__Index_ELECTRICAL_RESISTANCE = 58,
    ActorValue__Index_FROST_RESISTANCE = 59,
    ActorValue__Index_ENERGY_RESISTANCE = 60,
    ActorValue__Index_EMP_RESISTANCE = 61,
    ActorValue__Index_VARIABLE_01 = 62,
    ActorValue__Index_VARIABLE_02 = 63,
    ActorValue__Index_VARIABLE_03 = 64,
    ActorValue__Index_VARIABLE_04 = 65,
    ActorValue__Index_VARIABLE_05 = 66,
    ActorValue__Index_VARIABLE_06 = 67,
    ActorValue__Index_VARIABLE_07 = 68,
    ActorValue__Index_VARIABLE_08 = 69,
    ActorValue__Index_VARIABLE_09 = 70,
    ActorValue__Index_VARIABLE_10 = 71,
    ActorValue__Index_IGNORE_CRIPPLED_LIMBS = 72,
    ActorValue__Index_DEHYDRATION = 73,
    ActorValue__Index_HUNGER = 74,
    ActorValue__Index_SLEEPDEPREVATION = 75,
    ActorValue__Index_DAMAGE_THRESHOLD = 76,
    ActorValue__Index_ACTOR_VALUE_COUNT = 77,
    ActorValue__Index_AI_ATTRIBUTE_START = 0,
    ActorValue__Index_ATTRIBUTE_START = 5,
    ActorValue__Index_ACTOR_VALUE_START = 0,
    ActorValue__Index_DERIVED_ATTRIBUTE_START = 12,
    ActorValue__Index_CONDITION_START = 25,
    ActorValue__Index_SKILL_START = 32,
    ActorValue__Index_INT_START = 46,
    ActorValue__Index_VARIABLE_START = 62,
    ActorValue__Index_AI_ATTRIBUTE_END = 5,
    ActorValue__Index_ATTRIBUTE_END = 12,
    ActorValue__Index_CONDITION_END = 32,
    ActorValue__Index_DERIVED_ATTRIBUTE_END = 32,
    ActorValue__Index_SKILL_END = 46,
    ActorValue__Index_INT_END = 62,
    ActorValue__Index_VARIABLE_END = 76,
    ActorValue__Index_ATTRIBUTE_COUNT = 7,
    ActorValue__Index_DERIVED_ATTRIBUTE_COUNT = 20,
    ActorValue__Index_SKILL_COUNT = 14,
    ActorValue__Index_AI_ATTRIBUTE_COUNT = 5,
    ActorValue__Index_CONDITION_COUNT = 7,
    ActorValue__Index_INT_COUNT = 16,
    ActorValue__Index_VALUE_NONE = -1,
    ActorValue__Index_SKILL_NONE = -1,
    ActorValue__Index_ATTRIBUTE_NONE = -1,
};
}

class Script;
class TESLevItem;
class SpellItem;
class TESPackage;

#include "TESForm.h"

// Only the polymorphic base is needed for the race downcast.
class TESRace : public TESForm
{
};

class TESRaceForm : public BaseFormComponent
{
  public:
    TESRace* m_pRace;
    void InitItem(TESForm* owner);
    void BaseFormRecord(BaseFormComponent* component);
    TESRace* GetFormRace() const;
    void SetFormRace(TESRace* race);
};
FNV_STATIC_ASSERT(sizeof(TESRaceForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESRaceForm, m_pRace) == 4);

// This shared name predicate is already bound under BGSCameraPath in
// canonical source. Its receiver is the TESForm prefix.
class BGSCameraPath
{
  public:
    int HasNameForWarning();
};

TESForm* __cdecl GetFormByID(unsigned int formID);
int __cdecl Warning(const char* format, ...);

#include "tesraceform_actorbase.h"

namespace ActorValue {
bool IsSkill(Index actorValue);
unsigned char ToArrayIndex(int section, Index actorValue);
}

// TESNPC prefix through the two arrays used by GetActorValue.
class TESNPC : public TESActorBase, public TESRaceForm
{
  public:
    struct Data
    {
        unsigned char ucSkillValues[14];
        unsigned char ucSkillOffsets[14];
    } kData;
    virtual int GetActorValue(ActorValue::Index actorValue);
};
FNV_STATIC_ASSERT(offsetof(TESNPC, kData) == 0x114);

#endif
