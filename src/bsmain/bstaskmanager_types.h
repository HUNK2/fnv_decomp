// bsmain/bstaskmanager_types.h: declares IOTask
#ifndef FNV_BSTASKMANAGER_TYPES_H
#define FNV_BSTASKMANAGER_TYPES_H

#include <stddef.h>

// Enumerators are unused by this unit.
enum IO_TASK_PRIORITY
{
};
enum BS_TASK_STATE
{
    BS_TASK_STATE_PENDING = 0,
    BS_TASK_STATE_QUEUED = 1,
    BS_TASK_STATE_MOVING = 2,
    BS_TASK_STATE_RUNNING = 3,
    BS_TASK_STATE_FINISHED = 4,
    BS_TASK_STATE_COMPLETED = 5,
    BS_TASK_STATE_CANCELED = 6
};

template <class T> class BSTask
{
  public:
    BSTask();
    virtual ~BSTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel(BS_TASK_STATE state, void* parent);
    virtual bool GetDescription(char* description, unsigned int bufferSize);

    __declspec(align(8)) volatile int BackgroundTask;
    BS_TASK_STATE eState;
    T Key;
};

class IOTask : public BSTask<__int64>
{
  public:
    IOTask(IO_TASK_PRIORITY priority);
    virtual ~IOTask();
    virtual void ProcessLoadedAnimIdle();
    virtual void GenerateKey();
    virtual void ChangePriority(IO_TASK_PRIORITY priority);
    void SetIOTaskPriority(IO_TASK_PRIORITY priority);
};

typedef char IOTaskPriority_size[(sizeof(IO_TASK_PRIORITY) == 4) ? 1 : -1];
typedef char BSTaskInt64_size[(sizeof(BSTask<__int64>) == 24) ? 1 : -1];
typedef char BSTaskInt64_refcount_offset[(offsetof(BSTask<__int64>, BackgroundTask) == 8) ? 1 : -1];
typedef char BSTaskInt64_state_offset[(offsetof(BSTask<__int64>, eState) == 12) ? 1 : -1];
typedef char BSTaskInt64_key_offset[(offsetof(BSTask<__int64>, Key) == 16) ? 1 : -1];
typedef char IOTask_size[(sizeof(IOTask) == 24) ? 1 : -1];
#endif
