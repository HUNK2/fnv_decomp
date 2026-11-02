#ifndef FNV_QUEST_INFO_H
#define FNV_QUEST_INFO_H

#include "layout_support.h"
#include "INFO_LINK_ELEMENT.h"
#include "TopicInfoArray.h"
#pragma pack(push, 4)
class QuestDialogueInfo
{
  public:
    TESQuest* pQuest;                                     // +0x0
    TopicInfoArray infoArray;                             // +0x4
    BSSimpleArray<INFO_LINK_ELEMENT, 1024> m_kInfoLinks;  // +0x1C
    TESQuest* m_pAlternateQuest;                          // +0x2C
    bool bInitialized;                                    // +0x30
    unsigned char layoutPadding31;
    unsigned short layoutPadding32;
    TopicInfoArray* GetInfoArray();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(QuestDialogueInfo) == 0x34);
FNV_STATIC_ASSERT(offsetof(QuestDialogueInfo, pQuest) == 0x0);
FNV_STATIC_ASSERT(offsetof(QuestDialogueInfo, infoArray) == 0x4);
FNV_STATIC_ASSERT(offsetof(QuestDialogueInfo, m_kInfoLinks) == 0x1C);
FNV_STATIC_ASSERT(offsetof(QuestDialogueInfo, m_pAlternateQuest) == 0x2C);
FNV_STATIC_ASSERT(offsetof(QuestDialogueInfo, bInitialized) == 0x30);
#endif
