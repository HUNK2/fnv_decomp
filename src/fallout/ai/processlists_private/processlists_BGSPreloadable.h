// fallout/ai/processlists_private/processlists_BGSPreloadable.h: declares BGSPreloadable
#ifndef PROCESSLISTS_PRIVATE_BGSPRELOADABLE_H
#define PROCESSLISTS_PRIVATE_BGSPRELOADABLE_H
#include "processlists_BaseFormComponent.h"
class QueuedFile;
enum IO_TASK_PRIORITY
{
    IO_TASK_PRIORITY_CRITICAL = 0,
    IO_TASK_PRIORITY_VERY_HIGH = 1,
    IO_TASK_PRIORITY_HIGH = 2,
    IO_TASK_PRIORITY_MID = 3,
    IO_TASK_PRIORITY_LOW = 4,
    IO_TASK_PRIORITY_VERY_LOW = 5,
    IO_TASK_PRIORITY_COUNT = 6,
    IO_TASK_PRIORITY_INVALID = 7
};
class BGSPreloadable : public BaseFormComponent
{
  public:
    BGSPreloadable();
    ~BGSPreloadable();
    virtual void Preload(IO_TASK_PRIORITY priority, QueuedFile* file);
};
FNV_STATIC_ASSERT(sizeof(BGSPreloadable) == 4);
#endif
