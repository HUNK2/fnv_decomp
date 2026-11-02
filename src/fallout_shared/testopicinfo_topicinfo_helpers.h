// fallout_shared/testopicinfo_topicinfo_helpers.h: declares TopicInfoArray, FormChangeMask, BGSLoadFormBuffer, PlayerCharacter
#ifndef TOPICINFO_HELPERS_H
#define TOPICINFO_HELPERS_H

#include "testopicinfo_topicinfo_layout_support.h"
class TopicInfoArray : public NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >
{
};
class QuestDialogueInfo
{
  public:
    TopicInfoArray* GetInfoArray();
};
class FormChangeMask
{
  protected:
    int iFlags;

  public:
    FormChangeMask();
    FormChangeMask(int flags);
    bool ContainsAnyFlags(int flags);
};
class BGSLoadFormBuffer
{
  public:
    FormChangeMask GetChangeFlags();
    FormChangeMask GetOldChangeFlags();
};
class PlayerCharacter
{
  public:
    void AddTopics(BSSimpleList<TESTopic*>* topics);
};
extern PlayerCharacter* pPlayer;
#endif
