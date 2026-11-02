// fallout_shared/tesconditionfunctions_conditionfn_BGSQuestObjective.h: declares BGSQuestObjective, _State
#ifndef CONDITIONFN_BGSQUESTOBJECTIVE_DECLARATIONS_H
#define CONDITIONFN_BGSQUESTOBJECTIVE_DECLARATIONS_H

#include "tesconditionfunctions_conditionfn_dep_layout_support.h"

// PC declaration and member facts: public JohnnyGuitarNVSE BGSQuestObjective.hpp.
// Methods below are reconstructed solely from the supplied complete PC assembly.
class BGSQuestObjective
{
  public:
    BGSQuestObjective();
    virtual ~BGSQuestObjective();
    struct _State
    {
        enum State
        {
            DORMANT = 0,
            DISPLAYED = 1,
            COMPLETED = 2,
            COMPLETED_DISPLAYED = 3
        };
    };
    typedef _State::State State;
    unsigned int uiIndex;
    BSStringT<char> QuestObjectiveEntry;
    TESQuest* m_pOwnerQuest;
    BSSimpleList<RegionObjectEntry*> kTargets;
    bool bInitialized;
    State eState;
    bool GetCompleted() const;
    bool GetDisplayed() const;
};
FNV_STATIC_ASSERT(sizeof(BGSQuestObjective) == 0x24);
FNV_STATIC_ASSERT(offsetof(BGSQuestObjective, uiIndex) == 0x4);
FNV_STATIC_ASSERT(offsetof(BGSQuestObjective, QuestObjectiveEntry) == 0x8);
FNV_STATIC_ASSERT(offsetof(BGSQuestObjective, m_pOwnerQuest) == 0x10);
FNV_STATIC_ASSERT(offsetof(BGSQuestObjective, kTargets) == 0x14);
FNV_STATIC_ASSERT(offsetof(BGSQuestObjective, bInitialized) == 0x1c);
FNV_STATIC_ASSERT(offsetof(BGSQuestObjective, eState) == 0x20);
#endif
