// src/bsshader/mtrenderingsystem_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/bsshader/mtrenderingsystem.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "mtrenderingsystem_decls.h"
#pragma optimize("gty", on)
#pragma optimize("", off)
#pragma optimize("gty", on)
#pragma optimize("", off)

namespace fnv_00ba3690 {
#pragma optimize("gty", on)
extern "C" void _ReadWriteBarrier(void);

struct HandlerRegistration
{
    void* queuedHead;
    void* queuedTail;
    unsigned int queuedCount;
    HandlerRegistration();
    ~HandlerRegistration();
};

struct ThreadNode
{
    void* firstTask;
    void* lastTask;
    unsigned int taskCount;
    unsigned int nextTask;
    void* batch;
    void* renderer;
    unsigned int stage;
    unsigned int flags;
    ThreadNode();
    ~ThreadNode();
};

struct RenderingState
{
    int threadStages[3];
    int threadCounts[3];
    HandlerRegistration taskQueues[3];
    ThreadNode taskThreads[24];

    RenderingState();
};

// @fnv 0x00ba3690
RenderingState::RenderingState()
{
    int i = 0;
    do
    {
        threadStages[i] = 0;
        threadCounts[i] = 0;
        _ReadWriteBarrier();
    } while (++i < 3);
}
}  // namespace fnv_00ba3690

namespace RenderStageWait {
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct WaitHandleCounter
{
    volatile long count;
    void* handle;
    unsigned int maximum;

    __forceinline void Acquire()
    {
        WaitForSingleObject(handle, ~0UL);
        InterlockedDecrement(&count);
    }
};

struct ThreadStages : ::TaskThreadManager
{
    void* renderWorker;
    void* visibilityWorker;
    void* linearWorker;
    volatile int completed[3];
    WaitHandleCounter signals[3];
};

// @fnv 0x00ba3130
extern "C" void __fastcall FUN_00ba3130(ThreadStages* system, void*, int threadIndex, int stage)
{
    if (!::DAT_011f94b4)
        return;

    while (system->completed[threadIndex] < stage)
    {
        system->signals[threadIndex].Acquire();
        ++system->completed[threadIndex];
    }
}
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);

struct MemoryManager
{
    void* Allocate(unsigned int size);
    void Free(void* p);
};
extern MemoryManager _g_memoryManager;

namespace AccumTaskDetail {

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;

    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;

    __forceinline NiPointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
            {
                m_pObject->DecRefCount();
            }
            m_pObject = pObject;
            if (m_pObject)
            {
                m_pObject->IncRefCount();
            }
        }
        return *this;
    }
};

class Class0xa4
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;

    Class0xa4();
    void* operator new(size_t size)
    {
        return _g_memoryManager.Allocate(size);
    }
    void operator delete(void* p)
    {
        _g_memoryManager.Free(p);
    }
};

class TaskArg1
{
  public:
    void FUN_00c477f0(Class0xa4* obj);
};

extern "C" const void* DAT_0101e2ec;

struct NiVisibleArray;
class FUN_00a69400
{
  public:
    const void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;

    FUN_00a69400(NiVisibleArray* pArray = 0);
};

class BSCullingProcess : public FUN_00a69400
{
  public:
    unsigned int cullMode;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    void* field_bc;
    void* field_c0;
    void* field_c4;

    BSCullingProcess(NiVisibleArray* pkVisibleSet = 0) : FUN_00a69400(pkVisibleSet)
    {
        vtable = &DAT_0101e2ec;
        cullMode = 0;
        field_bc = 0;
        field_c0 = 0;
        field_c4 = 0;
    }

    void FUN_004a0f60();

    void SetAccumulator(NiRefObject* accumulator)
    {
        if (accumulator)
        {
            field_c4 = accumulator;
            accumulator->IncRefCount();
        }
    }

    void SetCullMode(unsigned int mode)
    {
        cullMode = mode;
    }

    void SetCompoundFrustum(TaskArg1* frustum)
    {
        field_c0 = frustum;
    }

    __forceinline ~BSCullingProcess()
    {
        FUN_004a0f60();
    }
};

void __cdecl FUN_00b6bee0(void* arg0, void* arg2, BSCullingProcess* pCulling);
void __cdecl FUN_00b6bfc0(void* arg0, void* arg, BSCullingProcess* pCulling);

struct TaskItem
{
    NiPointer<NiRefObject> sp00;
    Class0xa4* p04;
    NiPointer<NiRefObject> sp08;
    void* unk0c;
    void* unk10;
    NiPointer<NiRefObject> sp14;
    unsigned int cullMode;
    void* unk1c;
};

class AccumTaskReceiver : public ::TaskThreadManager
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    TaskItem tasks[24];

    __forceinline TaskItem& GetTask(unsigned int index)
    {
        return tasks[index];
    }
};

// @fnv 0x00ba3390
void __fastcall FUN_00ba3390(AccumTaskReceiver* self, void*, NiRefObject* a1, TaskArg1* a2, NiRefObject* a3, void* a4,
                             void* a5, NiRefObject* a6, unsigned int a7, unsigned int a8, void* a9)
{
    if (::DAT_011f94b4)
    {
        self->GetTask(a8).sp00 = a1;
        self->GetTask(a8).p04 = 0;
        self->GetTask(a8).sp08 = a3;
        self->GetTask(a8).unk0c = a4;
        self->GetTask(a8).unk10 = a5;
        self->GetTask(a8).sp14 = a6;
        self->GetTask(a8).cullMode = a7;
        self->GetTask(a8).unk1c = a9;

        if (a2)
        {
            Class0xa4* obj = new Class0xa4();
            self->GetTask(a8).p04 = obj;
            a2->FUN_00c477f0(obj);
        }
    }
    else
    {
        BSCullingProcess culling;
        culling.SetAccumulator(a6);
        culling.SetCullMode(a7);
        culling.SetCompoundFrustum(a2);
        if (a3)
        {
            FUN_00b6bee0(a1, a3, &culling);
        }
        if (a4)
        {
            FUN_00b6bfc0(a1, a4, &culling);
        }
        if (a5)
        {
            FUN_00b6bfc0(a1, a5, &culling);
        }
    }
}

}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void*, unsigned long);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace RenderShutdownDetail {
typedef int(__stdcall* SemaphoreRelease)(void*, long, long*);
struct TaskSemaphore
{
    volatile long count;
    void* handle;
    void Signal(SemaphoreRelease release)
    {
        release(handle, 1, 0);
        InterlockedIncrement(&count);
    }
    void Wait()
    {
        WaitForSingleObject(handle, 0xffffffffUL);
        InterlockedDecrement(&count);
    }
};
struct RenderTask
{
    virtual ~RenderTask();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    TaskSemaphore signal;
    unsigned int unk38;
    TaskSemaphore completion;
    unsigned int unk44;
    bool stopping;
};
struct RenderTaskManager : ::TaskThreadManager
{
    RenderTask* tasks[2];
};
// @fnv 0x00ba2d80
void __fastcall FUN_00ba2d80(RenderTaskManager* manager)
{
    if (!::DAT_011f94b4)
        return;
    SemaphoreRelease release = &ReleaseSemaphore;
    for (unsigned int index = 0; index < 2; ++index)
    {
        RenderTask* task = manager->tasks[index];
        if (task)
        {
            task->stopping = true;
            task->signal.Signal(release);
            task = manager->tasks[index];
            task->completion.Wait();
            delete manager->tasks[index];
            manager->tasks[index] = 0;
        }
    }
}

}

int sprintf_s(char*, size_t, const char*, ...);

extern MemoryManager g_memoryManager;
struct BSThread
{
    void Initialize(int stackSize, const char* name, bool suspended);
    void FUN_00aa6550(unsigned int);
    void SetThreadPriority(int);
    void SetName(const char*);
};
struct BSLinearTaskThread : BSThread
{
    BSLinearTaskThread();
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
};
extern void* DAT_010b7f50;
struct RenderTaskThread : BSLinearTaskThread
{
    void(__cdecl* m_pTaskFunction)();
    RenderTaskThread(void(__cdecl* f)())
    {
        *(void**)this = &DAT_010b7f50;
        m_pTaskFunction = f;
    }
    void* operator new(size_t s)
    {
        return g_memoryManager.Allocate(s);
    }
    void operator delete(void*);
};
struct ThreadOwner
{
    RenderTaskThread* m_threads[2];
    void FUN_00ba2e00(int index, unsigned int affinity, void(__cdecl* task)(), const char* name,
                      unsigned int stackSize);
};
// @fnv 0x00ba2e00
void ThreadOwner::FUN_00ba2e00(int index, unsigned int affinity, void(__cdecl* task)(), const char* name,
                               unsigned int stackSize)
{
    if (index < 3 && index < 2 && !m_threads[index])
    {
        m_threads[index] = new RenderTaskThread(task);
        m_threads[index]->Initialize(stackSize, name, false);
        m_threads[index]->FUN_00aa6550(affinity);
        m_threads[index]->SetThreadPriority(0);
        if (!name)
        {
            char buf[0x104];
            sprintf_s(buf, 0x104, "Rendering Task Thread DEF %i", index);
            m_threads[index]->SetName(buf);
        }
    }
}

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* hSemaphore, long lReleaseCount,
                                                                long* lpPreviousCount);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);
struct WorkerSync_ba2f30
{
    volatile long activeCount;
    void* semaphore;
};
struct WorkerState_ba2f30
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    WorkerSync_ba2f30 synchronization;
};
class ThreadCoordinator_ba2f30
{
  public:
    WorkerState_ba2f30* workers[2];
    unsigned int unk08;
    volatile unsigned int counters[2];
    void FUN_00ba2f30();
};
// @fnv 0x00ba2f30
void ThreadCoordinator_ba2f30::FUN_00ba2f30()
{
    if (!DAT_011f94b4)
        return;
    volatile unsigned int* current = counters;
    unsigned int remaining = 2;
    do
    {
        *current++ = 0;
    } while (--remaining);
    for (unsigned int index = 0; index < 2; ++index)
    {
        WorkerState_ba2f30* worker = workers[index];
        if (worker != 0)
        {
            WorkerSync_ba2f30* synchronization = &worker->synchronization;
            ReleaseSemaphore(synchronization->semaphore, 1, 0);
            InterlockedIncrement(&synchronization->activeCount);
        }
    }
}

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);
extern bool DAT_011f94b4;

struct SemaphoreBA2
{
    long m_lCount;
    void* m_hEvent;

    void Wait()
    {
        WaitForSingleObject(m_hEvent, 0xffffffff);
        InterlockedDecrement(&m_lCount);
    }
};

struct TaskThreadBA2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    SemaphoreBA2 m_kDoneSemaphore;
};

class FUN_00ba2fa0_C
{
  public:
    TaskThreadBA2* m_apThreads[2];

    void FUN_00ba2fa0();
};

// @fnv 0x00ba2fa0
void FUN_00ba2fa0_C::FUN_00ba2fa0()
{
    if (DAT_011f94b4)
    {
        for (unsigned int i = 0; i < 2; i++)
        {
            TaskThreadBA2* pThread = m_apThreads[i];
            if (pThread)
                pThread->m_kDoneSemaphore.Wait();
        }
    }
}

namespace fnv_00ba2ff0 {
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
namespace fnv_ba2ff0_cleanup {
struct ThreadState
{
    void* vtable;
    void* criticalSection;
    unsigned int unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c, unk20, unk24, unk28, unk2c;
    void __thiscall FUN_00aa63c0();
};
struct SemaphoreState
{
    volatile int count;
    void* handle;
    int maximumCount;
    __forceinline void Release()
    {
        CloseHandle(handle);
    }
};
struct WorkerThreadState : ThreadState
{
    SemaphoreState startProcessing;
    SemaphoreState finishedProcessing;
    bool killThread;
};
// @fnv 0x00ba2ff0
void* __fastcall FUN_00ba2ff0(WorkerThreadState* self, void*, unsigned int flags)
{
    self->finishedProcessing.Release();
    self->startProcessing.Release();
    self->ThreadState::FUN_00aa63c0();
    if (flags & 1)
        g_memoryManager.Deallocate(self);
    return self;
}
}
}  // namespace fnv_00ba2ff0

struct NiRefObject
{
    virtual void F0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct NiPointer
{
    T* m_pObject;
    ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

struct FUN_00ba3030
{
    NiPointer<NiRefObject> m_p1;
    int m_iValueAfterStandIn;
    NiPointer<NiRefObject> m_p2;
    int m_pAuxiliaryObject[2];
    NiPointer<NiRefObject> m_p3;
    int m_pad3[2];

    ~FUN_00ba3030();
};

// @fnv 0x00ba3030
FUN_00ba3030::~FUN_00ba3030()
{}

struct FUN_00ba30e0
{
    int state00;
    int unk04;
    int state08;
    int unk0c;
    int unk10;
    int state14;

    FUN_00ba30e0();
};

// @fnv 0x00ba30e0
FUN_00ba30e0::FUN_00ba30e0()
{
    state00 = 0;
    state08 = 0;
    state14 = 0;
}

__declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);
extern int(__stdcall* DAT_00fdf1c0)(void*);

namespace ThreadStageSignalDetail {
struct Semaphore
{
    volatile int count;
    void* handle;
    int maximum;
};

class RenderingStageController : public TaskThreadManager
{
  public:
    void* threads[3];
    volatile int stages[3];
    Semaphore semaphores[3];

    void FUN_00ba30f0(int threadIndex, int stage);
};

// @fnv 0x00ba30f0
void RenderingStageController::FUN_00ba30f0(int threadIndex, int stage)
{
    if (DAT_011f94b4 && threadIndex < 2)
    {
        Semaphore& signal = semaphores[threadIndex];
        ReleaseSemaphore(signal.handle, 1, 0);
        DAT_00fdf1c0(const_cast<int*>(&signal.count));
    }
}
}

namespace fnv_00ba3190 {
extern "C" unsigned long __readfsdword(unsigned long offset);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* semaphore, long releaseCount,
                                                                long* previousCount);

struct RefObjMt
{
    virtual void vfn00();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};

struct SubObjMt
{
    void FUN_00c47770();
};

struct MemoryManagerMt
{
    void Deallocate(void* p);
};
extern MemoryManagerMt g_memoryManager;

struct MTRenderingSystem_Helper
{
    void FUN_00ba3130(int a, int b);
};

struct FUN_00a69400
{
    FUN_00a69400(void* pArray);
    void* vtbl;
};

extern const void* DAT_0101e2ec;

struct BSCullingProcess
{
    void FUN_004a0f60();
};

struct CullProc : FUN_00a69400
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    SubObjMt* unkC0;
    RefObjMt* unkC4;
    CullProc() : FUN_00a69400(0)
    {
        vtbl = &DAT_0101e2ec;
        unk90 = 0;
        unkBC = 0;
        unkC0 = 0;
        unkC4 = 0;
    }
    ~CullProc()
    {
        ((BSCullingProcess*)this)->FUN_004a0f60();
    }
};
void FUN_00b6bee0(RefObjMt* a, RefObjMt* b, CullProc* c);
void FUN_00b6bfc0(RefObjMt* a, void* b, CullProc* c);
static inline void AddB(RefObjMt* a, RefObjMt* b, CullProc* c)
{
    FUN_00b6bee0(a, b, c);
}
static inline void AddC(RefObjMt* a, void* b, CullProc* c)
{
    FUN_00b6bfc0(a, b, c);
}

struct TaskRecordMt
{
    RefObjMt* unk00;
    SubObjMt* unk04;
    RefObjMt* unk08;
    void* unk0C;
    void* unk10;
    RefObjMt* unk14;
    int unk18;
    int unk1C;
};
extern TaskRecordMt DAT_012000e4[23];

extern unsigned int DAT_0126fd98;
extern volatile long DAT_012000ac;
extern void* DAT_012000b0;

static inline void Release(RefObjMt*& rp)
{
    RefObjMt* p = rp;
    if (p)
    {
        if (InterlockedDecrement(&p->m_uiRefCount) == 0)
            p->DeleteThis();
        rp = 0;
    }
}

// @fnv 0x00ba3190
void FUN_00ba3190()
{
    for (int i = 1; i < 24; i++)
    {
        TaskRecordMt* rec = &DAT_012000e4[i - 1];
        ((MTRenderingSystem_Helper*)&DAT_01200088)->FUN_00ba3130(0, i);
        if (rec->unk14)
        {
            *(int*)(((char**)__readfsdword(0x2c))[DAT_0126fd98] + 0x2bc) = rec->unk1C;
            CullProc cull;
            RefObjMt* p = rec->unk14;
            if (p)
            {
                cull.unkC4 = p;
                InterlockedIncrement(&p->m_uiRefCount);
            }
            cull.unk90 = rec->unk18;
            cull.unkC0 = rec->unk04;
            if (rec->unk08)
                AddB(rec->unk00, rec->unk08, &cull);
            if (rec->unk0C)
                AddC(rec->unk00, rec->unk0C, &cull);
            if (rec->unk10)
                AddC(rec->unk00, rec->unk10, &cull);
            rec->unk1C = 0;
            rec->unk0C = 0;
            rec->unk10 = 0;
            Release(rec->unk14);
            Release(rec->unk00);
            Release(rec->unk08);
            SubObjMt* s = rec->unk04;
            if (s)
            {
                s->FUN_00c47770();
                g_memoryManager.Deallocate(s);
                rec->unk04 = 0;
            }
        }
        if (DAT_011f94b4)
        {
            ReleaseSemaphore(DAT_012000b0, 1, 0);
            InterlockedIncrement(&DAT_012000ac);
        }
    }
}
}  // namespace fnv_00ba3190

void __cdecl FUN_00ba2d70();
void __cdecl FUN_00ba3030();
void __stdcall FUN_00ec5fce(void*, unsigned int, int, void(__cdecl*)());

struct LinearTaskRecord
{
    unsigned int taskId;
    unsigned int flags;
    unsigned int state;
};

struct RenderTaskRecord
{
    unsigned int type;
    unsigned int index;
    unsigned int input;
    unsigned int output;
    unsigned int width;
    unsigned int height;
    unsigned int format;
    unsigned int options;
};

struct LinearTaskGroup
{
    LinearTaskRecord tasks[3];
    __forceinline ~LinearTaskGroup()
    {
        FUN_00ec5fce(tasks, sizeof(LinearTaskRecord), 3, FUN_00ba2d70);
    }
};

struct RenderTaskGroup
{
    RenderTaskRecord tasks[24];
    __forceinline ~RenderTaskGroup()
    {
        FUN_00ec5fce(tasks, sizeof(RenderTaskRecord), 24, FUN_00ba3030);
    }
};

struct FUN_00ba3620
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    LinearTaskGroup linearTasks;
    RenderTaskGroup renderTasks;
    ~FUN_00ba3620();
};

// @fnv 0x00ba3620
FUN_00ba3620::~FUN_00ba3620()
{}
