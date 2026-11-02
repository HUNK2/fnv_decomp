// fallout/ai/combat/combatgoal.h: declares CombatWorldStateListNode, CombatGoal, CombatGoalActivateCombatItem, CombatGoalAdvance, CombatGoalAmbush and more
#ifndef FNV_COMBATGOAL_H
#define FNV_COMBATGOAL_H


#include "layout_support.h"

// Authored layout header for fallout/ai/combat/combatgoal.cpp.
//
// goal type enumeration is nested as CombatGoal::COMBAT_GOAL so the parameter
// type matches the PC symbol index.  The leaf goal classes are the RTTI
// confirmed derived classes reconstructed for this factory; every one of them
// adds no data members, so each goal object stays 28 bytes.

// Warning() comes from the original script unit; declared here because the
// script closure is not part of this unit's header dependency set.
int Warning(const char* format, ...);

class UnsignedIdHandle;

class CombatWorldStateListNode : public BSSimpleList<UnsignedIdHandle*>
{
  public:
};

class CombatGoal
{
  public:
    enum COMBAT_GOAL
    {
        COMBAT_GOAL_STAY_IN_COMBAT_AREA = 0,
        COMBAT_GOAL_USE_COMBAT_ITEM = 1,
        COMBAT_GOAL_FLEE = 2,
        COMBAT_GOAL_AVOID_THREATS = 3,
        COMBAT_GOAL_ACTIVATE_COMBAT_ITEM = 4,
        COMBAT_GOAL_REACH_DESTINATION = 5,
        COMBAT_GOAL_GUARD = 6,
        COMBAT_GOAL_CLUSTER = 7,
        COMBAT_GOAL_ADVANCE = 8,
        COMBAT_GOAL_AMBUSH = 9,
        COMBAT_GOAL_FALLBACK = 10,
        COMBAT_GOAL_FLANK = 11,
        COMBAT_GOAL_FIND_TARGET = 12,
        COMBAT_GOAL_FLUSH_TARGET = 13,
        COMBAT_GOAL_KILL_TARGET = 14,
        COMBAT_GOAL_HIDE_FROM_TARGET = 15,
        COMBAT_GOAL_COUNT = 16,
    };

    void** m_ppVirtualMethodTable;                                       // +0x0, 4 bytes
    CombatWorldStateListNode m_kFirstWorldStateNode;       // +0x4, 8 bytes
    CombatWorldStateListNode m_kCombatWorldStateListNode;  // +0xC, 8 bytes
    COMBAT_GOAL eType;                                     // +0x14, 4 bytes
    unsigned int m_uiGoalFlags;                            // +0x18, 4 bytes

    static CombatGoal* CreateGoal(COMBAT_GOAL eType);
};
FNV_STATIC_ASSERT(sizeof(CombatGoal) == 28);
FNV_STATIC_ASSERT(offsetof(CombatGoal, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(CombatGoal, m_kFirstWorldStateNode) == 4);
FNV_STATIC_ASSERT(offsetof(CombatGoal, m_kCombatWorldStateListNode) == 12);
FNV_STATIC_ASSERT(offsetof(CombatGoal, eType) == 20);
FNV_STATIC_ASSERT(offsetof(CombatGoal, m_uiGoalFlags) == 24);

class CombatGoalActivateCombatItem : public CombatGoal
{
  public:
    CombatGoalActivateCombatItem(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalAdvance : public CombatGoal
{
  public:
    CombatGoalAdvance(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalAmbush : public CombatGoal
{
  public:
    CombatGoalAmbush(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalAvoidThreats : public CombatGoal
{
  public:
    CombatGoalAvoidThreats(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalCluster : public CombatGoal
{
  public:
    CombatGoalCluster(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalFallBack : public CombatGoal
{
  public:
    CombatGoalFallBack(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalFindTarget : public CombatGoal
{
  public:
    CombatGoalFindTarget(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalFlee : public CombatGoal
{
  public:
    CombatGoalFlee(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalFlank : public CombatGoal
{
  public:
    CombatGoalFlank(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalFlushTarget : public CombatGoal
{
  public:
    CombatGoalFlushTarget(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalGuard : public CombatGoal
{
  public:
    CombatGoalGuard(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalHideFromTarget : public CombatGoal
{
  public:
    CombatGoalHideFromTarget(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalKillTarget : public CombatGoal
{
  public:
    CombatGoalKillTarget(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalReachDestination : public CombatGoal
{
  public:
    CombatGoalReachDestination(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalStayInCombatArea : public CombatGoal
{
  public:
    CombatGoalStayInCombatArea(CombatGoal::COMBAT_GOAL eType);
};

class CombatGoalUseCombatItem : public CombatGoal
{
  public:
    CombatGoalUseCombatItem(CombatGoal::COMBAT_GOAL eType);
};

#endif
