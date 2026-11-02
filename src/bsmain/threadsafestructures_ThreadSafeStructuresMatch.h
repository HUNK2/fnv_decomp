// Unit-local C++03 declarations. Layout evidence is itemized in NOTES.md.
#ifndef FNV_THREAD_SAFE_STRUCTURES_MATCH_H
#define FNV_THREAD_SAFE_STRUCTURES_MATCH_H

#include <stddef.h>
void* __cdecl operator new(size_t);
void* __cdecl operator new[](size_t);
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
extern "C" void* __cdecl memcpy(void*, const void*, size_t);
extern "C" const char kThreadSafeStructuresSourceFile[];
unsigned int __cdecl FUN_0044e330();
class bhkRigidBody;
class QueuedReference;
class TESObjectREFR;
class BSTreeNode;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
};
enum MEM_CONTEXT
{
    MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD = 6
};
class AutoMemContext
{
  public:
    MEM_CONTEXT m_eMemoryContext;
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
class InterfacedClass
{
  public:
    InterfacedClass();
    virtual ~InterfacedClass();
    virtual void* AllocateInterface(unsigned int) = 0;
};
class __declspec(align(32)) RecursiveSpinLock
{
  public:
    RecursiveSpinLock();
    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
};
template <class T> class ThreadInterfaceManager
{
  public:
    struct ThreadInterfaceEntry
    {
        ThreadInterfaceEntry();
        unsigned int uiThreadID;
        T* pInterface;
    };
    unsigned int uiMaxThreads;
    unsigned int uiTLSIndex;
    ThreadInterfaceEntry* m_pThreadInterfaceEntries;
    unsigned int uiThreadCount;
    ThreadInterfaceManager(unsigned int maxThreads);
};
template <class T> class LockFreeQueue : public InterfacedClass
{
  public:
    struct LockFreeQueueEntry
    {
        LockFreeQueueEntry();
        LockFreeQueueEntry* pNext;
        T tData;
    };
    class QueueDeleteManagerTag;
    typedef ThreadInterfaceManager<QueueDeleteManagerTag> Manager;
    LockFreeQueue(unsigned int maxThreads, unsigned int deleteBatchSize);
    virtual ~LockFreeQueue();
    virtual void* AllocateInterface(unsigned int thread);
    virtual void IncrementCount();
    virtual void DecrementCount();
    virtual unsigned int GetCount() const;
    LockFreeQueueEntry* pHead;
    LockFreeQueueEntry* pTail;
    unsigned int m_uiDeleteBatchSize;
    LockFreeQueueEntry** m_ppDeletedNodeBuffers;
    Manager* pMenuInterfaceManager;
    volatile int iCount;
    RecursiveSpinLock kLock;
};
template <class K, class T> class LockFreeMap : public InterfacedClass
{
  public:
    template <class P> struct ThreadSafePointer
    {
        ThreadSafePointer();
        volatile P* pPointer;
    };
    struct ThreadSafeHashTableNode
    {
        K tKey;
        T tData;
        ThreadSafePointer<ThreadSafeHashTableNode> pNext;
        ThreadSafeHashTableNode* GetNextDelete();
        void SetNextDelete(ThreadSafeHashTableNode*);
    };
    class DeletedNodeScanner
    {
      public:
        LockFreeMap* pOwner;
        ThreadSafeHashTableNode** m_ppDeletedNodeBuffers[3];
        ThreadSafePointer<ThreadSafeHashTableNode>* pPrev;
        ThreadSafePointer<ThreadSafeHashTableNode> Current;
        ThreadSafePointer<ThreadSafeHashTableNode> Next;
        ThreadSafeHashTableNode* m_pDeletedNodeHead;
        unsigned int m_uiDeleteCount;
        void ScanForDeletedNodes();
    };
    typedef ThreadInterfaceManager<DeletedNodeScanner> Manager;
    LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize);
    virtual ~LockFreeMap();
    virtual void* AllocateInterface(unsigned int thread);
    virtual bool GetAt(K, T&);
    virtual bool SetAt(unsigned int, K, const T&, bool);
    virtual bool SetAtAlt(K, const T&, bool);
    virtual bool RemoveAt(K);
    virtual bool Remove(unsigned int, T);
    virtual bool RemoveAlt(T);
    virtual bool GetAtAlt(K, T&);
    virtual unsigned int GetBucketForKey(K);
    virtual void DeleteKey(K);
    virtual K CopyKey(K);
    virtual void CopyKeyDirect(K, K&);
    virtual bool IsKeyGreaterOrEqual(K, K) const;
    virtual bool IsKeyEqual(K, K) const;
    virtual void IncrementCount();
    virtual void DecrementCount();
    virtual unsigned int GetCount() const;
    ThreadSafeHashTableNode** m_ppDeletedNodeBuffers;
    unsigned int uiNumBuckets;
    ThreadSafePointer<ThreadSafeHashTableNode>* m_pBuckets;
    unsigned int uiDeleteBatchSize;
    Manager* pManager;
    volatile unsigned int ItemUpdateArray;
    RecursiveSpinLock kLock;
    unsigned int GetMaxThreads() const;
    void DeleteNode(ThreadSafeHashTableNode*);
};
typedef LockFreeQueue<bhkRigidBody*> RigidBodyQueue;
typedef LockFreeMap<TESObjectREFR*, BSTreeNode*> TreeMap;
typedef char CheckSpinLockSize[(sizeof(RecursiveSpinLock) == 32) ? 1 : -1];
typedef char CheckQueueSize[(sizeof(RigidBodyQueue) == 64) ? 1 : -1];
typedef char CheckQueueLock[(offsetof(RigidBodyQueue, kLock) == 32) ? 1 : -1];
typedef char CheckMapSize[(sizeof(TreeMap) == 64) ? 1 : -1];
typedef char CheckMapLock[(offsetof(TreeMap, kLock) == 32) ? 1 : -1];
typedef char CheckMapInterface[(sizeof(TreeMap::DeletedNodeScanner) == 36) ? 1 : -1];
namespace ThreadSafeStructuresPC_0044b750 {
template <class K, class T> class LockFreeMap : public InterfacedClass
{
  public:
    // Shared helper identities are evidenced by the call targets. The PC
    // constructor copies have distinct vtables; their nominal types are unresolved.
    typedef ::TreeMap::ThreadSafeHashTableNode ThreadSafeHashTableNode;
    typedef ::TreeMap::ThreadSafePointer<ThreadSafeHashTableNode> Bucket;
    typedef ::TreeMap::Manager Manager;
    LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize);
    virtual ~LockFreeMap();
    virtual void* AllocateInterface(unsigned int thread);
    virtual bool GetAt(K, T&);
    virtual bool SetAt(unsigned int, K, const T&, bool);
    virtual bool SetAtAlt(K, const T&, bool);
    virtual bool RemoveAt(K);
    virtual bool Remove(unsigned int, T);
    virtual bool RemoveAlt(T);
    virtual bool GetAtAlt(K, T&);
    virtual unsigned int GetBucketForKey(K);
    virtual void DeleteKey(K);
    virtual K CopyKey(K);
    virtual void CopyKeyDirect(K, K&);
    virtual bool IsKeyGreaterOrEqual(K, K) const;
    virtual bool IsKeyEqual(K, K) const;
    virtual void IncrementCount();
    virtual void DecrementCount();
    virtual unsigned int GetCount() const;
    ThreadSafeHashTableNode** m_ppDeletedNodeBuffers;
    unsigned int uiNumBuckets;
    Bucket* m_pBuckets;
    unsigned int uiDeleteBatchSize;
    Manager* pManager;
    volatile unsigned int ItemUpdateArray;
    RecursiveSpinLock kLock;
    unsigned int GetMaxThreads() const;
    void DeleteNode(ThreadSafeHashTableNode*);
};
}
namespace ThreadSafeStructuresPC_0044ba10 {
template <class K, class T> class LockFreeMap : public InterfacedClass
{
  public:
    // Shared helper identities are evidenced by the call targets. The PC
    // constructor copies have distinct vtables; their nominal types are unresolved.
    typedef ::TreeMap::ThreadSafeHashTableNode ThreadSafeHashTableNode;
    typedef ::TreeMap::ThreadSafePointer<ThreadSafeHashTableNode> Bucket;
    typedef ::TreeMap::Manager Manager;
    LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize);
    virtual ~LockFreeMap();
    virtual void* AllocateInterface(unsigned int thread);
    virtual bool GetAt(K, T&);
    virtual bool SetAt(unsigned int, K, const T&, bool);
    virtual bool SetAtAlt(K, const T&, bool);
    virtual bool RemoveAt(K);
    virtual bool Remove(unsigned int, T);
    virtual bool RemoveAlt(T);
    virtual bool GetAtAlt(K, T&);
    virtual unsigned int GetBucketForKey(K);
    virtual void DeleteKey(K);
    virtual K CopyKey(K);
    virtual void CopyKeyDirect(K, K&);
    virtual bool IsKeyGreaterOrEqual(K, K) const;
    virtual bool IsKeyEqual(K, K) const;
    virtual void IncrementCount();
    virtual void DecrementCount();
    virtual unsigned int GetCount() const;
    ThreadSafeHashTableNode** m_ppDeletedNodeBuffers;
    unsigned int uiNumBuckets;
    Bucket* m_pBuckets;
    unsigned int uiDeleteBatchSize;
    Manager* pManager;
    volatile unsigned int ItemUpdateArray;
    RecursiveSpinLock kLock;
    unsigned int GetMaxThreads() const;
    void DeleteNode(ThreadSafeHashTableNode*);
};
}
namespace ThreadSafeStructuresPC_0044bbe0 {
template <class K, class T> class LockFreeMap : public InterfacedClass
{
  public:
    // Shared helper identities are evidenced by the call targets. The PC
    // constructor copies have distinct vtables; their nominal types are unresolved.
    typedef ::TreeMap::ThreadSafeHashTableNode ThreadSafeHashTableNode;
    typedef ::TreeMap::ThreadSafePointer<ThreadSafeHashTableNode> Bucket;
    typedef ::TreeMap::Manager Manager;
    LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize);
    virtual ~LockFreeMap();
    virtual void* AllocateInterface(unsigned int thread);
    virtual bool GetAt(K, T&);
    virtual bool SetAt(unsigned int, K, const T&, bool);
    virtual bool SetAtAlt(K, const T&, bool);
    virtual bool RemoveAt(K);
    virtual bool Remove(unsigned int, T);
    virtual bool RemoveAlt(T);
    virtual bool GetAtAlt(K, T&);
    virtual unsigned int GetBucketForKey(K);
    virtual void DeleteKey(K);
    virtual K CopyKey(K);
    virtual void CopyKeyDirect(K, K&);
    virtual bool IsKeyGreaterOrEqual(K, K) const;
    virtual bool IsKeyEqual(K, K) const;
    virtual void IncrementCount();
    virtual void DecrementCount();
    virtual unsigned int GetCount() const;
    ThreadSafeHashTableNode** m_ppDeletedNodeBuffers;
    unsigned int uiNumBuckets;
    Bucket* m_pBuckets;
    unsigned int uiDeleteBatchSize;
    Manager* pManager;
    volatile unsigned int ItemUpdateArray;
    RecursiveSpinLock kLock;
    unsigned int GetMaxThreads() const;
    void DeleteNode(ThreadSafeHashTableNode*);
};
}
namespace ThreadSafeStructuresPC_0044be80 {
template <class K, class T> class LockFreeMap : public InterfacedClass
{
  public:
    // Shared helper identities are evidenced by the call targets. The PC
    // constructor copies have distinct vtables; their nominal types are unresolved.
    typedef ::TreeMap::ThreadSafeHashTableNode ThreadSafeHashTableNode;
    typedef ::TreeMap::ThreadSafePointer<ThreadSafeHashTableNode> Bucket;
    typedef ::TreeMap::Manager Manager;
    LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize);
    virtual ~LockFreeMap();
    virtual void* AllocateInterface(unsigned int thread);
    virtual bool GetAt(K, T&);
    virtual bool SetAt(unsigned int, K, const T&, bool);
    virtual bool SetAtAlt(K, const T&, bool);
    virtual bool RemoveAt(K);
    virtual bool Remove(unsigned int, T);
    virtual bool RemoveAlt(T);
    virtual bool GetAtAlt(K, T&);
    virtual unsigned int GetBucketForKey(K);
    virtual void DeleteKey(K);
    virtual K CopyKey(K);
    virtual void CopyKeyDirect(K, K&);
    virtual bool IsKeyGreaterOrEqual(K, K) const;
    virtual bool IsKeyEqual(K, K) const;
    virtual void IncrementCount();
    virtual void DecrementCount();
    virtual unsigned int GetCount() const;
    ThreadSafeHashTableNode** m_ppDeletedNodeBuffers;
    unsigned int uiNumBuckets;
    Bucket* m_pBuckets;
    unsigned int uiDeleteBatchSize;
    Manager* pManager;
    volatile unsigned int ItemUpdateArray;
    RecursiveSpinLock kLock;
    unsigned int GetMaxThreads() const;
    void DeleteNode(ThreadSafeHashTableNode*);
};
}
namespace ThreadSafeStructuresPC_0044c040 {
template <class K, class T> class LockFreeMap : public InterfacedClass
{
  public:
    // Shared helper identities are evidenced by the call targets. The PC
    // constructor copies have distinct vtables; their nominal types are unresolved.
    typedef ::TreeMap::ThreadSafeHashTableNode ThreadSafeHashTableNode;
    typedef ::TreeMap::ThreadSafePointer<ThreadSafeHashTableNode> Bucket;
    typedef ::TreeMap::Manager Manager;
    LockFreeMap(unsigned int maxThreads, unsigned int numBuckets, unsigned int deleteBatchSize);
    virtual ~LockFreeMap();
    virtual void* AllocateInterface(unsigned int thread);
    virtual bool GetAt(K, T&);
    virtual bool SetAt(unsigned int, K, const T&, bool);
    virtual bool SetAtAlt(K, const T&, bool);
    virtual bool RemoveAt(K);
    virtual bool Remove(unsigned int, T);
    virtual bool RemoveAlt(T);
    virtual bool GetAtAlt(K, T&);
    virtual unsigned int GetBucketForKey(K);
    virtual void DeleteKey(K);
    virtual K CopyKey(K);
    virtual void CopyKeyDirect(K, K&);
    virtual bool IsKeyGreaterOrEqual(K, K) const;
    virtual bool IsKeyEqual(K, K) const;
    virtual void IncrementCount();
    virtual void DecrementCount();
    virtual unsigned int GetCount() const;
    ThreadSafeHashTableNode** m_ppDeletedNodeBuffers;
    unsigned int uiNumBuckets;
    Bucket* m_pBuckets;
    unsigned int uiDeleteBatchSize;
    Manager* pManager;
    volatile unsigned int ItemUpdateArray;
    RecursiveSpinLock kLock;
    unsigned int GetMaxThreads() const;
    void DeleteNode(ThreadSafeHashTableNode*);
};
}
#endif
