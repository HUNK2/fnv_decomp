// Source layout: TESQuest. PC corrections are in generate_headers.py.
#ifndef FNV_TESQUEST_H
#define FNV_TESQUEST_H

#include "layout_support.h"
#include "QuestData.h"
#include "PerkEntryConditionSet.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESIcon.h"
#include "TESScriptableForm.h"
#pragma pack(push, 4)
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
    unsigned char layoutPadding61;
    unsigned short layoutPadding62;
    bool GetEnabled();
    PerkEntryConditionSet* GetConditions();
    bool GetAllowRepeatedTopics();
    ScriptLocals* GetScriptLocalData();
};
#pragma pack(pop)
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
