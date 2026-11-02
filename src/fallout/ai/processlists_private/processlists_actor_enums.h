// Unit-private PC declaration dependencies from public JohnnyGuitar BSEnums.hpp.
// C++03 spelling of genuine enum declarations; no function implementations.
#ifndef FNV_PROCESSLISTS_ACTOR_ENUMS_H
#define FNV_PROCESSLISTS_ACTOR_ENUMS_H
#include "processlists_layout_support.h"
struct _AnimationAction
{
    enum Action
    {
        NONE = -1,
        EQUIP_WEAPON,
        UNEQUIP_WEAPON,
        ATTACK,
        ATTACK_EJECT,
        ATTACK_FOLLOW_THROUGH,
        ATTACK_THROW,
        ATTACK_THROW_ATTACH,
        BLOCK,
        RECOIL,
        RELOAD,
        STAGGER,
        DODGE,
        LOWER_BODY_ANIM,
        SPECIAL_IDLE,
        SCRIPT_ANIMATION,
        RELOAD_LOOP_START,
        RELOAD_LOOP_END,
        RELOAD_LOOP,
        COUNT,
    };
};
typedef _AnimationAction::Action ANIMATION_ACTION;
FNV_STATIC_ASSERT(sizeof(ANIMATION_ACTION) == 4);

struct _AnimGroup
{
    enum Group
    {
        NONE = -1,

        IDLE = 0,
        DYNAMIC_IDLE,
        SPECIAL_IDLE,

        MOVE_FORWARD,
        MOVE_BACK,
        MOVE_LEFT,
        MOVE_RIGHT,
        FAST_FORWARD,
        FAST_BACK,
        FAST_LEFT,
        FAST_RIGHT,
        DODGE_FORWARD,
        DODGE_BACK,
        DODGE_LEFT,
        DODGE_RIGHT,
        TURN_LEFT,
        TURN_RIGHT,

        _MOVEMENT_START = MOVE_FORWARD,
        _MOVEMENT_END = TURN_RIGHT,

        AIM,
        AIM_UP,
        AIM_DOWN,
        AIM_IS,
        AIM_IS_UP,
        AIM_IS_DOWN,

        _AIM_START = AIM,
        _AIM_END = AIM_IS_DOWN,

        HOLSTER,
        EQUIP,
        UNEQUIP,
        ATTACK_LEFT,
        ATTACK_LEFT_UP,
        ATTACK_LEFT_DOWN,
        ATTACK_LEFT_IS,
        ATTACK_LEFT_IS_UP,
        ATTACK_LEFT_IS_DOWN,
        ATTACK_RIGHT,
        ATTACK_RIGHT_UP,
        ATTACK_RIGHT_DOWN,
        ATTACK_RIGHT_IS,
        ATTACK_RIGHT_IS_UP,
        ATTACK_RIGHT_IS_DOWN,
        ATTACK_3,
        ATTACK_3_UP,
        ATTACK_3_DOWN,
        ATTACK_3_IS,
        ATTACK_3_IS_UP,
        ATTACK_3_IS_DOWN,
        ATTACK_4,
        ATTACK_4_UP,
        ATTACK_4_DOWN,
        ATTACK_4_IS,
        ATTACK_4_IS_UP,
        ATTACK_4_IS_DOWN,
        ATTACK_5,
        ATTACK_5_UP,
        ATTACK_5_DOWN,
        ATTACK_5_IS,
        ATTACK_5_IS_UP,
        ATTACK_5_IS_DOWN,
        ATTACK_6,
        ATTACK_6_UP,
        ATTACK_6_DOWN,
        ATTACK_6_IS,
        ATTACK_6_IS_UP,
        ATTACK_6_IS_DOWN,
        ATTACK_7,
        ATTACK_7_UP,
        ATTACK_7_DOWN,
        ATTACK_7_IS,
        ATTACK_7_IS_UP,
        ATTACK_7_IS_DOWN,
        ATTACK_8,
        ATTACK_8_UP,
        ATTACK_8_DOWN,
        ATTACK_8_IS,
        ATTACK_8_IS_UP,
        ATTACK_8_IS_DOWN,
        ATTACK_LOOP,
        ATTACK_LOOP_UP,
        ATTACK_LOOP_DOWN,
        ATTACK_LOOP_IS,
        ATTACK_LOOP_IS_UP,
        ATTACK_LOOP_IS_DOWN,
        ATTACK_SPIN,
        ATTACK_SPIN_UP,
        ATTACK_SPIN_DOWN,
        ATTACK_SPIN_IS,
        ATTACK_SPIN_IS_UP,
        ATTACK_SPIN_IS_DOWN,
        ATTACK_SPIN_2,
        ATTACK_SPIN_2_UP,
        ATTACK_SPIN_2_DOWN,
        ATTACK_SPIN_2_IS,
        ATTACK_SPIN_2_IS_UP,
        ATTACK_SPIN_2_IS_DOWN,
        ATTACK_POWER,
        ATTACK_FORWARD_POWER,
        ATTACK_BACK_POWER,
        ATTACK_LEFT_POWER,
        ATTACK_RIGHT_POWER,
        ATTACK_CUSTOM_1_POWER,
        ATTACK_CUSTOM_2_POWER,
        ATTACK_CUSTOM_3_POWER,
        ATTACK_CUSTOM_4_POWER,
        ATTACK_CUSTOM_5_POWER,
        PLACE_MINE,
        PLACE_MINE_UP,
        PLACE_MINE_DOWN,
        PLACE_MINE_IS,
        PLACE_MINE_IS_UP,
        PLACE_MINE_IS_DOWN,
        PLACE_MINE_2,
        PLACE_MINE_2_UP,
        PLACE_MINE_2_DOWN,
        PLACE_MINE_2_IS,
        PLACE_MINE_2_IS_UP,
        PLACE_MINE_2_IS_DOWN,
        ATTACK_THROW,
        ATTACK_THROW_UP,
        ATTACK_THROW_DOWN,
        ATTACK_THROW_IS,
        ATTACK_THROW_IS_UP,
        ATTACK_THROW_IS_DOWN,
        ATTACK_THROW_2,
        ATTACK_THROW_2_UP,
        ATTACK_THROW_2_DOWN,
        ATTACK_THROW_2_IS,
        ATTACK_THROW_2_IS_UP,
        ATTACK_THROW_2_IS_DOWN,
        ATTACK_THROW_3,
        ATTACK_THROW_3_UP,
        ATTACK_THROW_3_DOWN,
        ATTACK_THROW_3_IS,
        ATTACK_THROW_3_IS_UP,
        ATTACK_THROW_3_IS_DOWN,
        ATTACK_THROW_4,
        ATTACK_THROW_4_UP,
        ATTACK_THROW_4_DOWN,
        ATTACK_THROW_4_IS,
        ATTACK_THROW_4_IS_UP,
        ATTACK_THROW_4_IS_DOWN,
        ATTACK_THROW_5,
        ATTACK_THROW_5_UP,
        ATTACK_THROW_5_DOWN,
        ATTACK_THROW_5_IS,
        ATTACK_THROW_5_IS_UP,
        ATTACK_THROW_5_IS_DOWN,
        ATTACK_9,
        ATTACK_9_UP,
        ATTACK_9_DOWN,
        ATTACK_9_IS,
        ATTACK_9_IS_UP,
        ATTACK_9_IS_DOWN,
        ATTACK_THROW_6,
        ATTACK_THROW_6_UP,
        ATTACK_THROW_6_DOWN,
        ATTACK_THROW_6_IS,
        ATTACK_THROW_6_IS_UP,
        ATTACK_THROW_6_IS_DOWN,
        ATTACK_THROW_7,
        ATTACK_THROW_7_UP,
        ATTACK_THROW_7_DOWN,
        ATTACK_THROW_7_IS,
        ATTACK_THROW_7_IS_UP,
        ATTACK_THROW_7_IS_DOWN,
        ATTACK_THROW_8,
        ATTACK_THROW_8_UP,
        ATTACK_THROW_8_DOWN,
        ATTACK_THROW_8_IS,
        ATTACK_THROW_8_IS_UP,
        ATTACK_THROW_8_IS_DOWN,
        COUNTER_ATTACK,

        _WEAPONS_START = EQUIP,
        _WEAPONS_END = COUNTER_ATTACK,

        STOMP,
        BLOCK_IDLE,
        BLOCK_HIT,
        RECOIL,

        RELOAD_W_START,
        RELOAD_X_START,
        RELOAD_Y_START,
        RELOAD_Z_START,
        RELOAD_A,
        RELOAD_B,
        RELOAD_C,
        RELOAD_D,
        RELOAD_E,
        RELOAD_F,
        RELOAD_G,
        RELOAD_H,
        RELOAD_I,
        RELOAD_J,
        RELOAD_K,
        RELOAD_L,
        RELOAD_M,
        RELOAD_N,
        RELOAD_O,
        RELOAD_P,
        RELOAD_Q,
        RELOAD_R,
        RELOAD_S,
        RELOAD_W,
        RELOAD_X,
        RELOAD_Y,
        RELOAD_Z,

        _RELOAD_START = RELOAD_A,
        _LOOPING_RELOAD_START = RELOAD_W,
        _RELOAD_END = RELOAD_Z,

        JAM_A,
        JAM_B,
        JAM_C,
        JAM_D,
        JAM_E,
        JAM_F,
        JAM_G,
        JAM_H,
        JAM_I,
        JAM_J,
        JAM_K,
        JAM_L,
        JAM_M,
        JAM_N,
        JAM_O,
        JAM_P,
        JAM_Q,
        JAM_R,
        JAM_S,
        JAM_W,
        JAM_X,
        JAM_Y,
        JAM_Z,

        _WEAPON_JAM_START = JAM_A,
        _WEAPON_JAM_END = JAM_Z,

        STAGGER,
        DEATH,
        TALKING,
        PIPBOY,

        JUMP_START,
        JUMP_LOOP,
        JUMP_LAND,

        HAND_GRIP_1,
        HAND_GRIP_2,
        HAND_GRIP_3,
        HAND_GRIP_4,
        HAND_GRIP_5,
        HAND_GRIP_6,

        JUMP_LOOP_FORWARD,
        JUMP_LOOP_BACKWARD,
        JUMP_LOOP_LEFT,
        JUMP_LOOP_RIGHT,

        PIPBOY_CHILD,

        JUMP_LAND_FORWARD,
        JUMP_LAND_BACKWARD,
        JUMP_LAND_LEFT,
        JUMP_LAND_RIGHT,

        COUNT,
    };
};
typedef _AnimGroup::Group ANIM_GROUP_TYPE;
FNV_STATIC_ASSERT(sizeof(ANIM_GROUP_TYPE) == 4);

struct _AnimationIdlePlayType
{
    enum Type
    {
        REPLACE = 0,
        QUEUE = 1,
        AUTO = 2,
        AUTO_EXCLUSIVE = 3,
    };
};
typedef _AnimationIdlePlayType::Type ANIM_IDLE_PLAY_TYPE;
FNV_STATIC_ASSERT(sizeof(ANIM_IDLE_PLAY_TYPE) == 4);

struct _BodyPartType
{
    enum Type
    {
        NONE = -1,
        TORSO,
        HEAD_1,
        HEAD_2,
        LEFT_ARM_1,
        LEFT_ARM_2,
        RIGHT_ARM_1,
        RIGHT_ARM_2,
        LEFT_LEG_1,
        LEFT_LEG_2,
        LEFT_LEG_3,
        RIGHT_LEG_1,
        RIGHT_LEG_2,
        RIGHT_LEG_3,
        BRAIN,
        WEAPON,
        COUNT,
    };
};
typedef _BodyPartType::Type LIMB_TYPE;
FNV_STATIC_ASSERT(sizeof(LIMB_TYPE) == 4);

struct _DetectionLevel
{
    enum Level
    {
        LOST = 0,
        UNSEEN = 1,
        NOTICED = 2,
        SEEN = 3,
        COUNT = 4,
    };
};
typedef _DetectionLevel::Level DETECTION_LEVEL;
FNV_STATIC_ASSERT(sizeof(DETECTION_LEVEL) == 4);

struct _SoundLevel
{
    enum Level
    {
        LOUD,
        NORMAL,
        SILENT,
        COUNT,
    };
};
typedef _SoundLevel::Level SOUND_LEVEL;
FNV_STATIC_ASSERT(sizeof(SOUND_LEVEL) == 4);

#endif
