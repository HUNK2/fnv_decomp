#ifndef FNV_BSTASKMANAGER_H
#define FNV_BSTASKMANAGER_H
#include "bstaskmanager_types.h"

// @fnv 0x00440540
IOTask::IOTask(IO_TASK_PRIORITY priority) : BSTask<__int64>()
{
    SetIOTaskPriority(priority);
}
#endif
