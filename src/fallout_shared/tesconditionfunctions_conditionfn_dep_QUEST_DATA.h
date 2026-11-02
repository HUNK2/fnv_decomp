#ifndef TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_QUEST_DATA_H
#define TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_QUEST_DATA_H

#include "tesconditionfunctions_conditionfn_dep_layout_support.h"
class QuestData
{
  public:
    unsigned char m_ucEntryType;  // +0x0
    unsigned char ucPriority;     // +0x1
    unsigned char layoutPadding2[2];
    float fQuestDelayTime;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(QuestData) == 0x8);
FNV_STATIC_ASSERT(offsetof(QuestData, m_ucEntryType) == 0x0);
FNV_STATIC_ASSERT(offsetof(QuestData, ucPriority) == 0x1);
FNV_STATIC_ASSERT(offsetof(QuestData, fQuestDelayTime) == 0x4);
#endif
