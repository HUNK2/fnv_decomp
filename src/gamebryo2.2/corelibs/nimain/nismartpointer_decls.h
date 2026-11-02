// gamebryo2.2/corelibs/nimain/nismartpointer_decls.h: declares WaitableObject, KFModel, LoadedFile, NavMeshPtr, PathingLocation and more
#ifndef FNV_NISMARTPOINTER_DECLS_H
#define FNV_NISMARTPOINTER_DECLS_H


extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);

#define FNV_REFCOUNTED_TYPE(T)                                                                                         \
    class T                                                                                                            \
    {                                                                                                                  \
      public:                                                                                                          \
        virtual ~T();                                                                                                  \
        virtual void DeleteThis();                                                                                     \
        unsigned long m_uiRefCount;                                                                                    \
    }
FNV_REFCOUNTED_TYPE(NiD3DPixelShader);
FNV_REFCOUNTED_TYPE(NiGPUProgram);
#undef FNV_REFCOUNTED_TYPE

class WaitableObject
{
  public:
    void FUN_00401970();
    void FUN_0040f6e0();
};

class KFModel
{
  public:
    void FUN_0044b050();
    void FUN_0044b010();
};

class LoadedFile
{
  public:
    void FUN_0044b180();
    void FUN_0044b0f0();
};

template <class T> struct NiPointerRefOps
{
    static void Dec(T* object)
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)) == 0)
            object->DeleteThis();
    }
    static void Inc(T* object)
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount));
    }
};

class PathingAvoidNodeArray;
template <class T, int N> class BSSimpleArray;
class NavMeshPtr
{
  public:
    void* object;
    NavMeshPtr& FUN_0042fdc0(const NavMeshPtr&);
    NavMeshPtr& operator=(const NavMeshPtr&);
};

class PathingLocation
{
  public:
    PathingLocation& operator=(const PathingLocation&);
};

class PathingAvoidPointerView
{
  public:
    PathingAvoidPointerView& Assign(PathingAvoidNodeArray*);
};

class PathingRequest
{
  public:
    char prefix[0x34];
    PathingLocation destination;
    char padding[0x94 - 0x35];
    PathingAvoidPointerView avoid;
    void SetDestination(PathingLocation*);
    void SetAvoidNodeArray(BSSimpleArray<void*, 1024>*);
};

class KFModelLookupTable
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual bool Lookup(const char* key, KFModel*& result);
};

class KFModelLookup
{
  public:
    void* unknown;
    KFModelLookupTable* table;
    KFModel* Lookup(const char* key);
};

class NiGPUProgramOwner
{
  public:
    char prefix[0x30];
    NiGPUProgram* program;
    void SetProgram(NiGPUProgram*);
};

class GlobalObject_006ece90;
extern GlobalObject_006ece90 g_011d77f0;
class QueuedMessage;
template <class T> class BSTFreeList;
template <class T> class BSTCommonLLMessageQueue
{
  public:
    virtual void vfn_00();
    char storage[0x10];
    BSTCommonLLMessageQueue(GlobalObject_006ece90*);
    ~BSTCommonLLMessageQueue();
};

class PathingSolutionBase
{
  public:
    virtual void vfn_00();
    long refcount;
    PathingSolutionBase();
};

class ActorPathingMessageQueue : public BSTCommonLLMessageQueue<QueuedMessage>, public PathingSolutionBase
{
  public:
    ActorPathingMessageQueue();
    virtual void vfn_00();
};

#endif
