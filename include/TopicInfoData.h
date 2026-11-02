#ifndef FNV_TOPIC_INFO_DATA_H
#define FNV_TOPIC_INFO_DATA_H

#include "layout_support.h"
#pragma pack(push, 4)
class TopicInfoData
{
  public:
    char type;              // +0x0
    char nextSpeaker;       // +0x1
    char flags;             // +0x2
    char DialogueMetadata;  // +0x3
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TopicInfoData) == 0x4);
FNV_STATIC_ASSERT(offsetof(TopicInfoData, type) == 0x0);
FNV_STATIC_ASSERT(offsetof(TopicInfoData, nextSpeaker) == 0x1);
FNV_STATIC_ASSERT(offsetof(TopicInfoData, flags) == 0x2);
FNV_STATIC_ASSERT(offsetof(TopicInfoData, DialogueMetadata) == 0x3);
#endif
