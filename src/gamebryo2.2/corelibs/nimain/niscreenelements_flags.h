// gamebryo2.2/corelibs/nimain/niscreenelements_flags.h: declares TaskQueueInterface
#ifndef NISCREENELEMENTS_FLAGS_H
#define NISCREENELEMENTS_FLAGS_H
class TaskQueueInterface
{
  public:
    void SetTaskFlagDWord(bool enabled, unsigned int mask);
    void SetTaskFlag2000(bool enabled);
};
#endif
