#ifndef FNV_DIALOGUE_DATA_H
#define FNV_DIALOGUE_DATA_H

#include "processlists_layout_support.h"
class DialogueTopicData
{
  public:
    char type;    // +0x0
    char cFlags;  // +0x1
};
FNV_STATIC_ASSERT(sizeof(DialogueTopicData) == 0x2);
FNV_STATIC_ASSERT(offsetof(DialogueTopicData, type) == 0x0);
FNV_STATIC_ASSERT(offsetof(DialogueTopicData, cFlags) == 0x1);
#endif
