#ifndef FNV_QUEST_DATA_H
#define FNV_QUEST_DATA_H

#include "layout_support.h"
#pragma pack(push, 4)
class QuestData
{
  public:
    unsigned char m_ucEntryType;  // +0x0
    unsigned char ucPriority;     // +0x1
    unsigned short layoutPadding2;
    float fQuestDelayTime;  // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(QuestData) == 0x8);
FNV_STATIC_ASSERT(offsetof(QuestData, m_ucEntryType) == 0x0);
FNV_STATIC_ASSERT(offsetof(QuestData, ucPriority) == 0x1);
FNV_STATIC_ASSERT(offsetof(QuestData, fQuestDelayTime) == 0x4);
#endif
