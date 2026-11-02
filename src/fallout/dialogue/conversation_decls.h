// fallout/dialogue/conversation_decls.h: declares DialogueItem
#ifndef FNV_CONVERSATION_DECLS_H
#define FNV_CONVERSATION_DECLS_H

#include "layout_support.h"
class DialogueItem
{
  public:
    BSSimpleList<DialogueResponse*> m_kResponseList;
    BSSimpleList<DialogueResponse*>* m_pCurrentResponseList;
    TESTopicInfo* pInfo;
    TESTopic* pTopic;
    TESQuest* pQuest;
    TESObjectREFR* m_pDialogueSpeaker;
    bool SelectDefaultResponseList();
};
#endif
