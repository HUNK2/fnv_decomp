#ifndef FNV_COMBATACTION_DECLS_H
#define FNV_COMBATACTION_DECLS_H


void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* memory);
int __cdecl Warning(const char* format, ...);

class UnsignedIdHandle;
struct CombatWorldStateListNode
{
    UnsignedIdHandle* item;
    CombatWorldStateListNode* next;
};

class CombatAction
{
  public:
    enum COMBAT_ACTION
    {
        COMBAT_ACTION_NONE = -1,
        COMBAT_ACTION_ATTACK_RANGED_EXPLOSIVE = 0,
        COMBAT_ACTION_ATTACK_RANGED_EXPLOSIVE_FROM_COVER = 1,
        COMBAT_ACTION_ATTACK_RANGED = 2,
        COMBAT_ACTION_ATTACK_RANGED_FROM_COVER = 3,
        COMBAT_ACTION_ATTACK_GRENADE = 4,
        COMBAT_ACTION_ATTACK_GRENADE_FLUSH_TARGET = 5,
        COMBAT_ACTION_ATTACK_GRENADE_FROM_COVER = 6,
        COMBAT_ACTION_ATTACK_MELEE = 7,
        COMBAT_ACTION_ATTACK_HAND_TO_HAND = 8,
        COMBAT_ACTION_MOVE = 9,
        COMBAT_ACTION_MOVE_AND_SWITCH_TO_MELEE = 10,
        COMBAT_ACTION_MOVE_AND_ATTACK_RANGED = 11,
        COMBAT_ACTION_MOVE_AND_ATTACK_RANGED_EXPLOSIVE = 12,
        COMBAT_ACTION_MOVE_AND_ATTACK_GRENADE = 13,
        COMBAT_ACTION_DRAW_WEAPON = 14,
        COMBAT_ACTION_SWITCH_WEAPON = 15,
        COMBAT_ACTION_AVOID_THREAT = 16,
        COMBAT_ACTION_SEARCH = 17,
        COMBAT_ACTION_INVESTIGATE = 18,
        COMBAT_ACTION_DODGE = 19,
        COMBAT_ACTION_IGNORE_BLOCKED_TARGET = 20,
        COMBAT_ACTION_FLEE = 21,
        COMBAT_ACTION_ACTIVATE_COMBAT_ITEM = 22,
        COMBAT_ACTION_USE_COMBAT_ITEM = 23,
        COMBAT_ACTION_ACQUIRE_LINE_OF_SIGHT = 24,
        COMBAT_ACTION_HIDE = 25,
        COMBAT_ACTION_APPROACH_TARGET = 26,
        COMBAT_ACTION_COUNT = 27
    };
    static CombatAction* CreateAction(COMBAT_ACTION type);
    void** m_ppVirtualMethodTable;
    CombatWorldStateListNode m_kFirstSoundEntryNode;
    CombatWorldStateListNode m_kActionWorldStateNode;
    CombatWorldStateListNode Effects;
    CombatWorldStateListNode m_kSecondSoundEntryNode;
    COMBAT_ACTION eType;
    unsigned int iFlags;
};
typedef char CombatActionSizeCheck[sizeof(CombatAction) == 44 ? 1 : -1];

// Constructor at 0x0097ad10; identity from its PC vtable.
class CombatActionAttackRanged : public CombatAction
{
  public:
    CombatActionAttackRanged(COMBAT_ACTION type);
};

// Constructor at 0x0097aeb0; identity from its PC vtable.
class CombatActionAttackRangedFromCover : public CombatAction
{
  public:
    CombatActionAttackRangedFromCover(COMBAT_ACTION type);
};

// Constructor at 0x0097b0b0; identity from its PC vtable.
class CombatActionAttackRangedExplosive : public CombatAction
{
  public:
    CombatActionAttackRangedExplosive(COMBAT_ACTION type);
};

// Constructor at 0x0097b280; identity from its PC vtable.
class CombatActionAttackRangedExplosiveFromCover : public CombatAction
{
  public:
    CombatActionAttackRangedExplosiveFromCover(COMBAT_ACTION type);
};

// Constructor at 0x0097b350; identity from its PC vtable.
class CombatActionAttackMelee : public CombatAction
{
  public:
    CombatActionAttackMelee(COMBAT_ACTION type);
};

// Constructor at 0x0097b4e0; identity from its PC vtable.
class CombatActionAttackHandToHand : public CombatAction
{
  public:
    CombatActionAttackHandToHand(COMBAT_ACTION type);
};

// Constructor at 0x0097b620; identity from its PC vtable.
class CombatActionAttackGrenade : public CombatAction
{
  public:
    CombatActionAttackGrenade(COMBAT_ACTION type);
};

// Constructor at 0x0097b7a0; identity from its PC vtable.
class CombatActionAttackGrenadeFlushTarget : public CombatAction
{
  public:
    CombatActionAttackGrenadeFlushTarget(COMBAT_ACTION type);
};

// Constructor at 0x0097b9e0; identity from its PC vtable.
class CombatActionAttackGrenadeFromCover : public CombatAction
{
  public:
    CombatActionAttackGrenadeFromCover(COMBAT_ACTION type);
};

// Constructor at 0x0097bbd0; identity from its PC vtable.
class CombatActionMove : public CombatAction
{
  public:
    CombatActionMove(COMBAT_ACTION type);
};

// Constructor at 0x0097bfe0; identity from its PC vtable.
class CombatActionMoveAndSwitchToMelee : public CombatAction
{
  public:
    CombatActionMoveAndSwitchToMelee(COMBAT_ACTION type);
};

// Constructor at 0x0097c170; identity from its PC vtable.
class CombatActionMoveAndAttackRanged : public CombatAction
{
  public:
    CombatActionMoveAndAttackRanged(COMBAT_ACTION type);
};

// Constructor at 0x0097c3a0; identity from its PC vtable.
class CombatActionMoveAndAttackRangedExplosive : public CombatAction
{
  public:
    CombatActionMoveAndAttackRangedExplosive(COMBAT_ACTION type);
};

// Constructor at 0x0097c560; identity from its PC vtable.
class CombatActionMoveAndAttackGrenade : public CombatAction
{
  public:
    CombatActionMoveAndAttackGrenade(COMBAT_ACTION type);
};

// Constructor at 0x0097c700; identity from its PC vtable.
class CombatActionDrawWeapon : public CombatAction
{
  public:
    CombatActionDrawWeapon(COMBAT_ACTION type);
};

// Constructor at 0x0097c850; identity from its PC vtable.
class CombatActionSwitchWeapon : public CombatAction
{
  public:
    CombatActionSwitchWeapon(COMBAT_ACTION type);
};

// Constructor at 0x0097c9d0; identity from its PC vtable.
class CombatActionAvoidThreat : public CombatAction
{
  public:
    CombatActionAvoidThreat(COMBAT_ACTION type);
};

// Constructor at 0x0097ca60; identity from its PC vtable.
class CombatActionSearch : public CombatAction
{
  public:
    CombatActionSearch(COMBAT_ACTION type);
};

// Constructor at 0x0097cb70; identity from its PC vtable.
class CombatActionInvestigate : public CombatAction
{
  public:
    CombatActionInvestigate(COMBAT_ACTION type);
};

// Constructor at 0x0097cc00; identity from its PC vtable.
class CombatActionDodge : public CombatAction
{
  public:
    CombatActionDodge(COMBAT_ACTION type);
};

// Constructor at 0x0097cc80; identity from its PC vtable.
class CombatActionIgnoreBlockedTarget : public CombatAction
{
  public:
    CombatActionIgnoreBlockedTarget(COMBAT_ACTION type);
};

// Constructor at 0x0097cd30; identity from its PC vtable.
class CombatActionFlee : public CombatAction
{
  public:
    CombatActionFlee(COMBAT_ACTION type);
};

// Constructor at 0x0097ce90; identity from its PC vtable.
class CombatActionActivateCombatItem : public CombatAction
{
  public:
    CombatActionActivateCombatItem(COMBAT_ACTION type);
};

// Constructor at 0x0097cfe0; identity from its PC vtable.
class CombatActionUseCombatItem : public CombatAction
{
  public:
    CombatActionUseCombatItem(COMBAT_ACTION type);
};

// Constructor at 0x0097d1c0; identity from its PC vtable.
class CombatActionAcquireLineOfSight : public CombatAction
{
  public:
    CombatActionAcquireLineOfSight(COMBAT_ACTION type);
};

// Constructor at 0x0097d250; identity from its PC vtable.
class CombatActionHide : public CombatAction
{
  public:
    CombatActionHide(COMBAT_ACTION type);
};

// Constructor at 0x0097d130; identity from its PC vtable.
class CombatActionApproachTarget : public CombatAction
{
  public:
    CombatActionApproachTarget(COMBAT_ACTION type);
};

#endif
