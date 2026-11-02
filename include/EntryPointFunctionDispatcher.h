// include/EntryPointFunctionDispatcher.h: declares EntryPointFunctionDispatcher, StringReference, EntryPointParameterList, EntryPoint
#ifndef FNV_BGSENTRYPOINT_H
#define FNV_BGSENTRYPOINT_H

#include "layout_support.h"
#pragma pack(push, 4)
class EntryPointFunctionDispatcher
{
  public:
    enum ENTRY_POINT
    {
        CALCULATE_WEAPON_DAMAGE = 0,
        CALCULATE_CRITICAL_HIT_CHANCE = 1,
        CALCULATE_CRITICAL_HIT_DAMAGE = 2,
        CALCULATE_WEAPON_ATTACK_AP_COST = 3,
        CALCULATE_MINE_EXPLODE_CHANCE = 4,
        ADJUST_RANGE_PENALTY = 5,
        ADJUST_LIMB_DAMAGE = 6,
        CALCULATE_WEAPON_RANGE = 7,
        CALCULATE_TO_HIT_CHANCE = 8,
        ADJUST_EXPERIENCE_POINTS = 9,
        ADJUST_GAINED_SKILL_POINTS = 10,
        ADJUST_BOOK_SKILL_POINTS = 11,
        MODIFY_RECOVERED_HEALTH = 12,
        CALCULATE_INVENTORY_AP_COST = 13,
        GET_DISPOSITION = 14,
        GET_SHOULD_ATTACK = 15,
        GET_SHOULD_ASSIST = 16,
        CALCULATE_BUY_PRICE = 17,
        GET_BAD_KARMA = 18,
        GET_GOOD_KARMA = 19,
        IGNORE_LOCKED_TERMINAL = 20,
        ADD_LEVELED_LIST_ON_DEATH = 21,
        GET_MAX_CARRY_WEIGHT = 22,
        MODIFY_ADDICTION_CHANCE = 23,
        MODIFY_ADDICTION_DURATION = 24,
        MODIFY_POSITIVE_CHEM_DURATION = 25,
        ADJUST_DRINKING_RADIATION = 26,
        ACTIVATE = 27,
        MYSTERIOUS_STRANGER = 28,
        HAS_PARALYZING_PALM = 29,
        HACKING_SCIENCE_BONUS = 30,
        IGNORE_RUNNING_DURING_DETECTION = 31,
        IGNORE_BROKEN_LOCK = 32,
        HAS_CONCENTRATED_FIRE = 33,
        CALCULATE_GUN_SPREAD = 34,
        PLAYER_KILL_AP_REWARD = 35,
        MODIFY_ENEMY_CRITICAL_HIT_CHANCE = 36,
        RELOAD_SPEED_ENTRY = 37,
        EQUIP_SPEED_ENTRY = 38,
        ACTION_POINT_REGENERATION_ENTRY = 39,
        ACTION_POINT_COST_MODIFIER_ENTRY = 40,
        MISS_FORTUNE_ENTRY = 41,
        RUN_SPEED_MODIFIER = 42,
        ATTACK_SPEED_MODIFIER = 43,
        RADIATION_INGESTIBLE_BONUS = 44,
        HAS_PIP_HACKER = 45,
        HAS_MELTDOWN = 46,
        SEE_ENEMY_HEALTH = 47,
        HAS_JURY_RIGGING = 48,
        REDUCE_THREAT_RANGE = 49,
        REDUCE_THREAT_MODIFIER = 50,
        HAS_ALWAYS_FAST_TRAVEL = 51,
        KNOCKDOWN_CHANCE = 52,
        WEAPON_HANDLING_STRENGTH_BONUS = 53,
        AIM_MOVEMENT_MODIFIER = 54,
        HAS_LIGHT_ITEMS_WEIGH_NOTHING = 55,
        ADJUST_DAMAGE_THRESHOLD_DEFENDER = 56,
        MODIFY_CHANCE_FOR_AMMO_ITEM = 57,
        ADJUST_DAMAGE_THRESHOLD_ATTACKER = 58,
        THROWING_VELOCITY_MODIFIER = 59,
        CHANCE_FOR_ITEM_ON_FIRE = 60,
        HAS_UNARMED_FORWARD_POWER_ATTACK = 61,
        HAS_UNARMED_BACKWARD_POWER_ATTACK = 62,
        HAS_CROUCHED_POWER_ATTACK = 63,
        HAS_COUNTER_ATTACK = 64,
        HAS_UNARMED_LEFT_POWER_ATTACK = 65,
        HAS_UNARMED_RIGHT_POWER_ATTACK = 66,
        MODIFY_VATS_HELPER_CHANCE = 67,
        MODIFY_DAMAGE_TO_ITEMS = 68,
        HAS_IMPROVED_DETECTION = 69,
        HAS_IMPROVED_SPOTTING = 70,
        HAS_ITEM_DETECTION = 71,
        ADJUST_EXPLOSION_RADIUS = 72,
        MODIFY_HEAVY_WEAPON_WEIGHT = 73,
        ENTRY_POINT_COUNT = 74
    };
    struct StringReference
    {
        char* m_pStringValue;
    };
    struct EntryPointParameterList
    {
        unsigned char cCount;
        StringReference* pParameters;
    };
    struct EntryPoint
    {
        char* m_pName;
        EntryPointParameterList m_kParameters;
        unsigned char m_ucFunctionType;
    };
    static void ExecuteEntryPoint(ENTRY_POINT entryPoint, Actor* actor, ...);
    static EntryPoint ms_kEntryPointTable[];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(EntryPointFunctionDispatcher::StringReference) == 4);
FNV_STATIC_ASSERT(offsetof(EntryPointFunctionDispatcher::StringReference, m_pStringValue) == 0);
FNV_STATIC_ASSERT(sizeof(EntryPointFunctionDispatcher::EntryPointParameterList) == 8);
FNV_STATIC_ASSERT(offsetof(EntryPointFunctionDispatcher::EntryPointParameterList, cCount) == 0);
FNV_STATIC_ASSERT(offsetof(EntryPointFunctionDispatcher::EntryPointParameterList, pParameters) == 4);
FNV_STATIC_ASSERT(sizeof(EntryPointFunctionDispatcher::EntryPoint) == 16);
FNV_STATIC_ASSERT(offsetof(EntryPointFunctionDispatcher::EntryPoint, m_pName) == 0);
FNV_STATIC_ASSERT(offsetof(EntryPointFunctionDispatcher::EntryPoint, m_kParameters) == 4);
FNV_STATIC_ASSERT(offsetof(EntryPointFunctionDispatcher::EntryPoint, m_ucFunctionType) == 12);
#endif
