#ifndef FNV_TESCONVERSATIONDATA_H
#define FNV_TESCONVERSATIONDATA_H

#include "testopicinfo_topicinfo_layout_support.h"
class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*> m_kLinkFromList;          // +0x0
    BSSimpleList<TESTopic*> m_kLinkToList;            // +0x8
    BSSimpleList<TESTopicInfo*> m_kFollowUpInfoList;  // +0x10
    BSSimpleList<TESTopic*>* GetLinkFromList();
    void InitItem(TESForm* owner);
    TESTopicInfoData();
    ~TESTopicInfoData();
    void Copy(TESTopicInfo* info, TESTopicInfoData* data);
    BSSimpleList<TESTopic*>* GetLinkToList();
    BSSimpleList<TESTopicInfo*>* GetFollowUpInfoList();
};
FNV_STATIC_ASSERT(sizeof(TESTopicInfoData) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESTopicInfoData, m_kLinkFromList) == 0x0);
FNV_STATIC_ASSERT(offsetof(TESTopicInfoData, m_kLinkToList) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESTopicInfoData, m_kFollowUpInfoList) == 0x10);
#endif
