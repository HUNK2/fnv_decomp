// fallout/ai/mobileobject_private/mobileobject_package_enum.h: declares _PackageType
#ifndef MOBILEOBJECT_PACKAGE_ENUM_H
#define MOBILEOBJECT_PACKAGE_ENUM_H
struct _PackageType
{
    enum Type
    {
        NONE = -1,
        EXPLORE = 0,
        FOLLOW = 1,
        ESCORT = 2,
        EAT = 3,
        SLEEP = 4,
        WANDER = 5,
        TRAVEL = 6,
        ACCOMPANY = 7,
        USE_ITEM_AT = 8,
        AMBUSH = 9,
        FLEE_NON_COMBAT = 10,
        CAST_MAGIC = 11,
        SANDBOX = 12,
        PATROL = 13,
        GUARD = 14,
        DIALOGUE = 15,
        USE_WEAPON = 16,
        FIND = 17,
        COMBAT = 18,
        COMBAT_LOW = 19,
        ACTIVATE = 20,
        ALARM = 21,
        FLEE = 22,
        TRESPASS = 23,
        SPECTATOR = 24,
        REACT_TO_DEAD = 25,
        GET_UP = 26,
        DO_NOTHING = 27,
        IN_GAME_DIALOGUE = 28,
        SURFACE = 29,
        SEARCH_FOR_ATTACKER = 30,
        AVOID_RADIATION = 31,
        REACT_TO_DESTROYED_OBJECT = 32,
        REACT_TO_GRENADE_OR_MINE = 33,
        STEAL_WARNING = 34,
        PICKPOCKET_WARNING = 35,
        MOVEMENT_BLOCKED = 36,
        SANDMAN = 37,
        CANNIBAL = 38,
        BACKUP = 39,
        COUNT,
    };
};
typedef _PackageType::Type PACKAGE_TYPE;

#endif
