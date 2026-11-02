// gamebryo2.2/corelibs/nimain/niscreenelements.cpp: TaskQueueInterface (1 function)
#include "niscreenelements_flags.h"

// @fnv 0x005467c0
void TaskQueueInterface::SetTaskFlag2000(bool enabled)
{
    SetTaskFlagDWord(enabled, 0x2000);
}
