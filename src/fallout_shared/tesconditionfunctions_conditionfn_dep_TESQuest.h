// Source layout: TESQuest. PC corrections are in generate_headers.py.
#ifndef TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_TESQUEST_H
#define TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_TESQUEST_H

#include "tesconditionfunctions_conditionfn_dep_layout_support.h"
#include "tesconditionfunctions_conditionfn_dep_QUEST_DATA.h"
#include "tesconditionfunctions_conditionfn_dep_TESCondition.h"
#include "tesconditionfunctions_conditionfn_dep_TESForm.h"
#include "tesconditionfunctions_conditionfn_dep_TESFullName.h"
#include "tesconditionfunctions_conditionfn_dep_TESIcon.h"
#include "tesconditionfunctions_conditionfn_dep_TESScriptableForm.h"
class TESQuest : public TESForm
{
  public:
    TESScriptableForm tESScriptableFormComponent;    // +0x18
    TESIcon tESIconComponent;                        // +0x24
    TESFullName tESFullNameComponent;                // +0x30
    QuestData data;                                 // +0x3C
    BSSimpleList<QuestStage*> m_kStageList;       // +0x44
    BSSimpleList<BGSQuestObjective*> m_kObjectives;  // +0x4C
    PerkEntryConditionSet m_kInfoConditions;                  // +0x54
    ScriptLocals* m_pScriptLocals;                   // +0x5C
    unsigned char m_ucEnabled;                       // +0x60
    unsigned char layoutPadding61[3];
    bool GetEnabled();
    PerkEntryConditionSet* GetConditions();
    bool GetAllowRepeatedTopics();
    ScriptLocals* GetScriptLocalData();
};
FNV_STATIC_ASSERT(sizeof(TESQuest) == 0x64);
FNV_STATIC_ASSERT(offsetof(TESQuest, tESScriptableFormComponent) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESQuest, tESIconComponent) == 0x24);
FNV_STATIC_ASSERT(offsetof(TESQuest, tESFullNameComponent) == 0x30);
FNV_STATIC_ASSERT(offsetof(TESQuest, data) == 0x3C);
FNV_STATIC_ASSERT(offsetof(TESQuest, m_kStageList) == 0x44);
FNV_STATIC_ASSERT(offsetof(TESQuest, m_kObjectives) == 0x4C);
FNV_STATIC_ASSERT(offsetof(TESQuest, m_kInfoConditions) == 0x54);
FNV_STATIC_ASSERT(offsetof(TESQuest, m_pScriptLocals) == 0x5C);
FNV_STATIC_ASSERT(offsetof(TESQuest, m_ucEnabled) == 0x60);
#endif
