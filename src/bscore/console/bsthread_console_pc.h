// bscore/console/bsthread_console_pc.h: declares BSThreadCriticalSectionPC, BSThread, BSThreadEntryPC
#ifndef FNV_BSTHREAD_CONSOLE_PC_H
#define FNV_BSTHREAD_CONSOLE_PC_H


#include "layout_support.h"

struct BSThreadCriticalSectionPC
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

class BSThread
{
  public:
    enum StackSize
    {
        INHERIT_MAIN = 0,
        SMALL_STACK_SIZE = 16384,
        MEDIUM_STACK_SIZE = 32768,
        LARGE_STACK_SIZE = 65536,
        MAINTHREAD_STACK_SIZE = 131072
    };

    BSThread();
    virtual ~BSThread();
    void Initialize(StackSize stackSize, const char* name, bool suspended);
    void SetThreadPriority(int priority);
    void SetSchedulingPriority(unsigned int);
    unsigned int ThreadProc();
    void SetName(const char*);

    BSThreadCriticalSectionPC CriticalSection;
    void* m_pThreadHandle;
    void* m_pCurrentThreadHandle;
    unsigned int m_uiCreatedThreadId;
    unsigned int m_uiCurrentThreadId;
    bool m_bThreadStarted;
};

FNV_STATIC_ASSERT(sizeof(BSThreadCriticalSectionPC) == 0x18);
FNV_STATIC_ASSERT(sizeof(BSThread) == 0x30);
FNV_STATIC_ASSERT(offsetof(BSThread, CriticalSection) == 0x04);
FNV_STATIC_ASSERT(offsetof(BSThread, m_pThreadHandle) == 0x1c);
FNV_STATIC_ASSERT(offsetof(BSThread, m_pCurrentThreadHandle) == 0x20);
FNV_STATIC_ASSERT(offsetof(BSThread, m_uiCreatedThreadId) == 0x24);
FNV_STATIC_ASSERT(offsetof(BSThread, m_uiCurrentThreadId) == 0x28);
FNV_STATIC_ASSERT(offsetof(BSThread, m_bThreadStarted) == 0x2c);

extern "C"
{
    extern void(__stdcall* fnv_EnterCriticalSection)(void*);
    extern void(__stdcall* fnv_LeaveCriticalSection)(void*);
    __declspec(dllimport) void* __stdcall GetCurrentThread();
    __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
    __declspec(dllimport) void* __stdcall CreateThread(void*, unsigned long, unsigned long(__stdcall*)(void*), void*,
                                                       unsigned long, unsigned int*);
    __declspec(dllimport) unsigned long __stdcall ResumeThread(void*);
    __declspec(dllimport) int __stdcall SetThreadPriority(void*, int);
}

class BSThreadEntryPC
{
  public:
    virtual ~BSThreadEntryPC();
    virtual unsigned long ThreadProc();
};

// The thread entry point has no identity candidate in the task or lookup index.
unsigned long __stdcall RunThreadProc(void*);
extern void(__stdcall* DAT_00fdf054)(void*);

#endif
