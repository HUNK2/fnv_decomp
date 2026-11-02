// Unit-private PC declarations. Sources: JohnnyGuitarNVSE Bethesda
// C++03 spelling only; no community implementation bodies are included.
#ifndef FNV_PROCESSLISTS_PRIVATE_SYNC_H
#define FNV_PROCESSLISTS_PRIVATE_SYNC_H

#include "processlists_layout_support.h"

class FNV_ALIGN(32) RecursiveSpinLock
{
  public:
    RecursiveSpinLock();
    ~RecursiveSpinLock();

    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;

    void Lock(const char* apName = 0);  // PC 0040FBF0
    bool TryLock();
    void Unlock();  // PC 0040FBA0
    bool IsLocked() const;

  private:
    RecursiveSpinLock(const RecursiveSpinLock&);
    RecursiveSpinLock& operator=(const RecursiveSpinLock&);
};
FNV_STATIC_ASSERT(sizeof(RecursiveSpinLock) == 0x20);
FNV_STATIC_ASSERT(__alignof(RecursiveSpinLock) == 32);
FNV_STATIC_ASSERT(offsetof(RecursiveSpinLock, m_uiOwningThreadID) == 0);
FNV_STATIC_ASSERT(offsetof(RecursiveSpinLock, m_uiRecursionCount) == 4);

class LockPrimitive
{
  public:
    LockPrimitive();
    ~LockPrimitive();

    unsigned int m_uiLockState;

    void Lock();
    bool TryLock();
    void Unlock();
    bool IsLocked() const;
};
FNV_STATIC_ASSERT(sizeof(LockPrimitive) == 4);
FNV_STATIC_ASSERT(offsetof(LockPrimitive, m_uiLockState) == 0);

class CountingSemaphore
{
  public:
    CountingSemaphore();
    CountingSemaphore(unsigned int auiCount);
    CountingSemaphore(unsigned int auiCount, unsigned int auiMaxCount);
    ~CountingSemaphore();

    unsigned int ItemUpdateArray;
    void* hSemaphore;
    unsigned int uiMaxCount;

    void Signal();
    void Wait();
    bool Test();
};
FNV_STATIC_ASSERT(sizeof(CountingSemaphore) == 0xC);
FNV_STATIC_ASSERT(offsetof(CountingSemaphore, ItemUpdateArray) == 0);
FNV_STATIC_ASSERT(offsetof(CountingSemaphore, hSemaphore) == 4);
FNV_STATIC_ASSERT(offsetof(CountingSemaphore, uiMaxCount) == 8);
#endif
