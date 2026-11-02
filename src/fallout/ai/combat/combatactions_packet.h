
// Private header for fallout/ai/combat/combatactions.cpp.
// CombatAction's data layout (four CombatWorldStateListNode members plus eType/iFlags)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
template <class T> class BSSimpleList
{
    T item;
    BSSimpleList* next;

  public:
    BSSimpleList();
    void AddTail(T&);
};

class CombatWorldStateListNode : public BSSimpleList<void*>
{
  public:
    void AddSoundEntry(int, int);
    void RemoveItemByOwner(int);
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
    CombatAction(COMBAT_ACTION);
    ~CombatAction();
    virtual void vfn_0();
    void FUN_0097adc0(int, int);
    void FUN_0097ade0(int, int);
    void FUN_0097bc60(int, int);
    void FUN_00984390(int, int);
    void FUN_0097c070(int);
    void FUN_0097c240(int);
    void FUN_0097c260(int);
    CombatWorldStateListNode m_kFirstSoundEntryNode;   // +0x04
    CombatWorldStateListNode m_kActionWorldStateNode;  // +0x0C
    CombatWorldStateListNode Effects;                  // +0x14
    CombatWorldStateListNode m_kSecondSoundEntryNode;  // +0x1C
    COMBAT_ACTION eType;                               // +0x24
    unsigned int iFlags;                               // +0x28
};

extern BSSimpleList<CombatAction*>* DAT_011f13d0[];

class CombatActionIgnoreBlockedTarget : public CombatAction
{
  public:
    CombatActionIgnoreBlockedTarget(COMBAT_ACTION);
    virtual void vfn_0();
};

class CombatActionAttackRangedExplosive : public CombatAction
{
  public:
    CombatActionAttackRangedExplosive(COMBAT_ACTION);
    static void Execute(int, CombatAction*);
};
class CombatActionAttackRanged : public CombatAction
{
  public:
    CombatActionAttackRanged(COMBAT_ACTION);
};
class CombatActionAttackRangedFromCover : public CombatAction
{
  public:
    CombatActionAttackRangedFromCover(COMBAT_ACTION);
};
class CombatActionAttackRangedExplosiveFromCover : public CombatAction
{
  public:
    CombatActionAttackRangedExplosiveFromCover(COMBAT_ACTION);
};
class CombatActionAttackMelee : public CombatAction
{
  public:
    CombatActionAttackMelee(COMBAT_ACTION);
};
class CombatActionAttackHandToHand : public CombatAction
{
  public:
    CombatActionAttackHandToHand(COMBAT_ACTION);
};
class CombatActionAttackGrenade : public CombatAction
{
  public:
    CombatActionAttackGrenade(COMBAT_ACTION);
};
class CombatActionAttackGrenadeFlushTarget : public CombatAction
{
  public:
    CombatActionAttackGrenadeFlushTarget(COMBAT_ACTION);
};
class CombatActionAttackGrenadeFromCover : public CombatAction
{
  public:
    CombatActionAttackGrenadeFromCover(COMBAT_ACTION);
};
class CombatActionMove : public CombatAction
{
  public:
    CombatActionMove(COMBAT_ACTION);
};
class CombatActionMoveAndSwitchToMelee : public CombatActionMove
{
  public:
    CombatActionMoveAndSwitchToMelee(COMBAT_ACTION);
};
class CombatActionMoveAndAttackRanged : public CombatActionAttackRanged
{
  public:
    CombatActionMoveAndAttackRanged(COMBAT_ACTION);
};
class CombatActionMoveAndAttackRangedExplosive : public CombatActionAttackRangedExplosive
{
  public:
    CombatActionMoveAndAttackRangedExplosive(COMBAT_ACTION);
};
class CombatActionMoveAndAttackGrenade : public CombatActionAttackGrenade
{
  public:
    CombatActionMoveAndAttackGrenade(COMBAT_ACTION);
};
class CombatActionDrawWeapon : public CombatAction
{
  public:
    CombatActionDrawWeapon(COMBAT_ACTION);
};
class CombatActionSwitchWeapon : public CombatAction
{
  public:
    CombatActionSwitchWeapon(COMBAT_ACTION);
};
class CombatActionAvoidThreat : public CombatAction
{
  public:
    CombatActionAvoidThreat(COMBAT_ACTION);
};
class CombatActionSearch : public CombatAction
{
  public:
    CombatActionSearch(COMBAT_ACTION);
};
class CombatActionInvestigate : public CombatAction
{
  public:
    CombatActionInvestigate(COMBAT_ACTION);
};
class CombatActionDodge : public CombatAction
{
  public:
    CombatActionDodge(COMBAT_ACTION);
};
