
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpphantomdisplayviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpphantomdisplayviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_01269cd0;
extern int DAT_01268ff0;
void* __cdecl FUN_00d66770();
struct HKProcessFactory
{
    void* __thiscall RegisterProcess(const char* name, void* creator);
};
void* __cdecl FUN_00dd9380(void* factory, const char* name, void* creator);
// @fnv 0x00d66af0
void* __cdecl RegisterPhantomsProcess()
{
    DAT_01268ff0 = (int)((HKProcessFactory*)DAT_01269cd0)->RegisterProcess("Phantoms", (void*)&FUN_00d66770);
    return (void*)DAT_01268ff0;
}

struct Container
{
    void __thiscall ClearValue(void*);
};

struct World
{
    void __thiscall FUN_00c917f0(void*);
};

struct hkpPhantomDisplayViewer
{
    void FUN_00d66250(void*);
};

// @fnv 0x00d66250
void hkpPhantomDisplayViewer::FUN_00d66250(void* arg)
{
    void* p1 = this ? (char*)this + 0x28 : 0;
    ((World*)arg)->FUN_00c917f0(p1);
    void* p2 = this ? (char*)this + 0x2c : 0;
    ((Container*)arg)->ClearValue(p2);
    int i = 0;
    if (*(int*)((char*)arg + 0x114) > 0)
    {
        char* base = (char*)this + 0x28;
        do
        {
            void* item = *(void**)(*(int*)((char*)arg + 0x110) + i * 4);
            void* vt = *(void**)base;
            void* fn = *(void**)((char*)vt + 8);
            ((void(__thiscall*)(void*, void*))fn)(base, item);
            ++i;
        } while (i < *(int*)((char*)arg + 0x114));
    }
}

struct FUN_00c93860_stub
{
    void FUN_00c93860(void* arg);
};

struct D698B0Island
{
    void addListener(void* listener);
    char pad_0[0x110];
    void* m_items_110;  // +0x110
    int m_count_114;    // +0x114
};

struct FUN_00d662c0_stub
{
    void AttachToIsland(void* arg);
};

// @fnv 0x00d662c0
void FUN_00d662c0_stub::AttachToIsland(void* pIsland)
{
    char* pSelf = (char*)this;
    void* p1;
    if (pSelf)
        p1 = pSelf + 0x28;
    else
        p1 = 0;
    D698B0Island* edi = (D698B0Island*)pIsland;
    ((FUN_00c93860_stub*)edi)->FUN_00c93860(p1);
    void* p2;
    if (pSelf)
        p2 = pSelf + 0x2c;
    else
        p2 = 0;
    edi->addListener(p2);
    int i = 0;
    if (edi->m_count_114 > 0)
    {
        char* base = pSelf + 0x28;
        do
        {
            void* item = ((void**)edi->m_items_110)[i];
            void* pVtable = *(void**)base;
            ((void(__thiscall*)(void*, void*)) * (void**)((char*)pVtable + 4))(base, item);
            ++i;
        } while (i < edi->m_count_114);
    }
}

struct FUN_00d663f0_Array
{
    int* m_data;
    int m_uiItemCount;
    int m_pRayCursor;
};

struct FUN_00d663f0_MemoryRouter
{
    void* m_unknown0;
    void* m_unknown1;
    void* m_unknown2;
    void* m_unknown3;
    void* m_pThreadAllocator;
};

void* _D1A0E0GetMemoryRouter();
void __cdecl ResizeAudioStream(void*, void*, int);

struct FUN_00d663f0_Class
{
    void* m_unknown0;
    void* m_unknown1;
    FUN_00d663f0_Array m_ppData;

    void __thiscall AppendInt(int value);
};

// @fnv 0x00d663f0
void __thiscall FUN_00d663f0_Class::AppendInt(int value)
{
    FUN_00d663f0_Array& array = m_ppData;
    FUN_00d663f0_MemoryRouter* router = static_cast<FUN_00d663f0_MemoryRouter*>(_D1A0E0GetMemoryRouter());

    if (array.m_uiItemCount == (array.m_pRayCursor & 0x3fffffff))
        ResizeAudioStream(router->m_pThreadAllocator, &array, 4);

    int* element = array.m_data + array.m_uiItemCount;
    if (element)
        *element = value;

    ++array.m_uiItemCount;
}

namespace fnv_00d66b60 {
struct HKMemoryManager
{
    virtual void unused1();
    virtual void unused2();
    virtual void free(void* object, unsigned short size);
};

struct HKMemoryRouter
{
    void* m_auiShapeKeys[4];
    HKMemoryManager* m_manager;
};

struct hkpPhantomDisplayViewer
{
    void* m_vptr;
    unsigned short m_iElementCount;

    void FUN_00d66490();
    void* Destroy(int flags);
};

HKMemoryRouter* __cdecl _D1A0E0GetMemoryRouter();

// @fnv 0x00d66b60
void* hkpPhantomDisplayViewer::Destroy(int flags)
{
    FUN_00d66490();

    if (flags & 1)
    {
        HKMemoryRouter* router = _D1A0E0GetMemoryRouter();
        unsigned short size = m_iElementCount;
        HKMemoryManager* manager = router->m_manager;
        manager->free(this, size);
    }

    return this;
}
}  // namespace fnv_00d66b60

struct FnvCpu_FUN_00d66370_CpuTarget
{
    void FUN_00d66250();
};
struct FnvCpu_FUN_00d66370_CpuOwner
{
    void FUN_00d66370();
};
// @fnv 0x00d66370
void FnvCpu_FUN_00d66370_CpuOwner::FUN_00d66370()
{
    reinterpret_cast<FnvCpu_FUN_00d66370_CpuTarget*>(reinterpret_cast<char*>(this) + (-32))->FUN_00d66250();
}

// add ecx,-0x20; jmp AttachToIsland : override in Derived forwards to the primary base's virtual.
struct PrimaryBase
{
    virtual void AttachToIsland();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct SecondaryBase
{
    virtual void FUN_00d66380();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
    virtual void FUN_00d66380();
};

Derived::Derived()
{}

// Calls the base constructor AttachToIsland on this object.
// @fnv 0x00d66380
void Derived::FUN_00d66380()
{
    this->PrimaryBase::AttachToIsland();
}

extern int DAT_01268ff0;

// @fnv 0x00d66b10
int __cdecl FUN_00d66b10()
{
    return DAT_01268ff0;
}

struct ListenerCollection
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void** m_items;
    int m_uiItemCount;
};
struct FUN_00d66330_StandIn
{
    void* m_ppVirtualMethodTable;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    ListenerCollection* m_pShapeCollection;
    void FUN_00d66330();
};
// @fnv 0x00d66330
void FUN_00d66330_StandIn::FUN_00d66330()
{
    if (m_pShapeCollection)
    {
        for (int i = 0; i < m_pShapeCollection->m_uiItemCount; ++i)
        {
            reinterpret_cast<FUN_00d662c0_stub*>(reinterpret_cast<char*>(this) - 8)
                ->AttachToIsland(m_pShapeCollection->m_items[i]);
        }
    }
}

struct Viewer
{
    int unk00, unk04, unk08, unk0c;
    void* callbackState;
};

struct Callback
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void notify(void* field, int global, void* value);
};

extern int DAT_01268ff0;

struct OwnerBase
{
    Callback* callback;
    int unk04, unk08, unk0c;
};

struct ViewerList
{
    void* unk00;
    void* unk04;
    Viewer** entries;
    volatile int count;
    int capacity;
    void RemoveViewer(Viewer* target);
};

struct ViewerOwner : OwnerBase, ViewerList
{
};

// Scans entries for target, decrements count, moves the last entry into its slot, and notifies the owner's callback with the target's callbackState.
// @fnv 0x00d66390
void ViewerList::RemoveViewer(Viewer* pViewer)
{
    int index = 0;
    int length = count;
    if (length > 0)
    {
        Viewer** cursor = entries;
        do
        {
            if (*cursor == pViewer)
            {
                if (index >= 0)
                {
                    --count;
                    int newCount = count;
                    if (newCount != index)
                        entries[index] = entries[newCount];

                    ViewerOwner* owner = static_cast<ViewerOwner*>(this);
                    owner->callback->notify(&pViewer->callbackState, DAT_01268ff0, pViewer->callbackState);
                    return;
                }
                return;
            }
            ++index;
            ++cursor;
        } while (index < length);
        return;
    }
    return;
}

struct FnvCpu_FUN_00d66770_CpuBlock;
struct FnvCpu_FUN_00d66770_CpuAllocator
{
    virtual void slot00();
    virtual void* Invoke(unsigned int size);
};
struct FnvCpu_FUN_00d66770_CpuHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d66770_CpuAllocator* allocator;
};
void* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d66770_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d66770_CpuBlock* FUN_00d66430(unsigned int value);
};
// @fnv 0x00d66770
void* __cdecl FUN_00d66770(unsigned int value)
{
    FnvCpu_FUN_00d66770_CpuHolder* pCpuHolder = static_cast<FnvCpu_FUN_00d66770_CpuHolder*>(FUN_00c85750());
    FnvCpu_FUN_00d66770_CpuBlock* pCpuBlock =
        static_cast<FnvCpu_FUN_00d66770_CpuBlock*>(pCpuHolder->allocator->Invoke(60));
    pCpuBlock->size = 60;
    pCpuBlock = pCpuBlock->FUN_00d66430(value);
    if (pCpuBlock)
        return reinterpret_cast<char*>(pCpuBlock) + 8;
    return 0;
}

namespace fnv_00e015d0 {
struct Allocator
{
    virtual void allocatorOperation0();
    virtual void allocatorOperation1();
    virtual void deallocateObject(void* object, unsigned short allocatorTag);
    virtual void allocatorOperation3();
    virtual void deallocateArray(void* buffer, unsigned int bytes);
};
struct MemoryRouter
{
    int unknown00, unknown04, unknown08, unknown0c;
    Allocator* allocator;
};
MemoryRouter* __cdecl FUN_00c85750();
extern char DAT_0102e388;
struct HavokArrayOwner
{
    void* vtable;
    unsigned short allocatorTag;
    unsigned short unknown06;
    void* data;
    unsigned int size;
    int capacityFlags;
    HavokArrayOwner* DestroyHavokArrayOwner(unsigned int deletionFlags);
};
// Frees the owned data array through the allocator, resets the owner to empty, and optionally deallocates the object itself.
// @fnv 0x00e015d0
HavokArrayOwner* HavokArrayOwner::DestroyHavokArrayOwner(unsigned int deletionFlags)
{
    MemoryRouter* router = FUN_00c85750();
    Allocator* allocator = router->allocator;
    int previousCapacity = capacityFlags;
    size = 0;
    if ((previousCapacity & 0x80000000) == 0)
    {
        allocator->deallocateArray(data, (previousCapacity & 0x3fffffff) * 4);
    }
    data = 0;
    capacityFlags = 0x80000000;
    vtable = &DAT_0102e388;
    if (deletionFlags & 1)
    {
        MemoryRouter* router2 = FUN_00c85750();
        router2->allocator->deallocateObject(this, allocatorTag);
    }
    return this;
}
}  // namespace fnv_00e015d0

namespace d664 {
class hkReferencedObjectD66
{
  public:
    virtual void unkv00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkProcessD66
{
  public:
    virtual void unkv01();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class hkpWorldDeletionListenerD66
{
  public:
    virtual void unkv02();
    int unk04;
};
class FUN_00ddccb0 : public hkReferencedObjectD66, public hkProcessD66, public hkpWorldDeletionListenerD66
{
  public:
    FUN_00ddccb0(const void* contexts) throw();
};
}
class hkpPhantomListenerD66
{
  public:
    virtual void PhantomAddedCallback(void* phantom) = 0;
};
class hkpWorldPostSimulationListenerD66
{
  public:
    virtual void postSimulationCallback(void* world) = 0;
};
template <class T> class hkArrayD66
{
  public:
    hkArrayD66() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class FUN_00d66430 : public d664::FUN_00ddccb0,
                     protected hkpPhantomListenerD66,
                     protected hkpWorldPostSimulationListenerD66
{
  public:
    FUN_00d66430(const void* contexts);
    hkArrayD66<void*> m_kContexts;
};
// Constructor that passes contexts to the FUN_00ddccb0 base constructor; its own body is empty.
// @fnv 0x00d66430
FUN_00d66430::FUN_00d66430(const void* contexts) : d664::FUN_00ddccb0(contexts)
{}

class hkMemoryAllocatorD667
{
  public:
    virtual ~hkMemoryAllocatorD667() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD667
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD667* m_pStreamAllocator;
    hkMemoryAllocatorD667& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD667 {
extern "C" hkMemoryRouterD667& __cdecl FUN_00c85750() throw();
}

template <typename T> struct hkArrayD667
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayD667() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkReferencedObjectD667
{
  public:
    hkReferencedObjectD667()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectD667();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        hkReferencedObjectD667* b =
            static_cast<hkReferencedObjectD667*>(hkRouterD667::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class hkObjectD667 : public hkReferencedObjectD667
{
  public:
    hkArrayD667<void*> m_items;
    virtual ~hkObjectD667();
};

// Allocates and returns a new hkObjectD667 instance via the hkReferencedObjectD667 operator new.
// @fnv 0x00d66730
hkReferencedObjectD667* __cdecl CreateHkObject()
{
    return new hkObjectD667();
}

class hkMemoryAllocatorD664
{
  public:
    virtual ~hkMemoryAllocatorD664() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD664
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD664* m_pStreamAllocator;

    hkMemoryAllocatorD664& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterD664& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayD664
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD664() throw()
    {
        hkMemoryAllocatorD664& kAlloc = fnvc_adapt::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct hkpPhantomD664;

struct hkpWorldD664
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68;
    hkpPhantomD664** m_kPhantoms;
    int m_iPhantomCount;
};

namespace FUN_00ddcc60 {
class hkpWorldViewerBase
{
  public:
    virtual ~hkpWorldViewerBase();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
}

class hkProcessD664
{
  public:
    virtual void GetOperationType() = 0;
    int unk04, unk08, unk0C, unk10, unk14;
};

class hkpWorldDeletionListenerD664
{
  public:
    virtual void WorldDeletedCallback(void* pkWorld) = 0;
    hkpWorldD664* m_pkWorld;
};

class hkpPhantomListener
{
  public:
    virtual ~hkpPhantomListener() throw()
    {}
    virtual void PhantomAddedCallback(hkpPhantomD664* pkPhantom) = 0;
};

class hkpWorldPostSimulationListener
{
  public:
    virtual ~hkpWorldPostSimulationListener() throw()
    {}
    virtual void postSimulationCallback(hkpWorldD664* pkWorld) = 0;
};

namespace FUN_00d66490 {
class hkpPhantomDisplayViewer : public FUN_00ddcc60::hkpWorldViewerBase,
                                public hkProcessD664,
                                public hkpWorldDeletionListenerD664,
                                public hkpPhantomListener,
                                public hkpWorldPostSimulationListener
{
  public:
    virtual ~hkpPhantomDisplayViewer();
    virtual void GetOperationType();
    virtual void WorldDeletedCallback(void* pkWorld);
    virtual void PhantomAddedCallback(hkpPhantomD664* pkPhantom);
    virtual void postSimulationCallback(hkpWorldD664* pkWorld);

    void FUN_00d66250(hkpPhantomD664* pkPhantom) throw();

    hkArrayD664<int> m_kIds;
};

// Destructor that calls FUN_00d66250 on each phantom of m_pkWorld when the world pointer is set.
// @fnv 0x00d66490
hkpPhantomDisplayViewer::~hkpPhantomDisplayViewer()
{
    if (m_pkWorld)
    {
        for (int i = 0; i < m_pkWorld->m_iPhantomCount; i++)
            FUN_00d66250(m_pkWorld->m_kPhantoms[i]);
    }
}
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
inline void* operator new(unsigned int, void* p)
{
    return p;
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern "C" const char str_010d1c38[];
extern "C" const char str_010c41f8[];
struct MonitorCommand
{
    const char* name;
    unsigned int time0, time1;
    void setTime()
    {
        _ReadWriteBarrier();
        volatile unsigned int uiTicks = (unsigned int)__rdtsc();
        time0 = uiTicks;
    }
    void setTime(volatile unsigned int& slot)
    {
        _ReadWriteBarrier();
        slot = (unsigned int)__rdtsc();
        time0 = slot;
    }
};
struct MonitorStream
{
    char* start;
    char* cursor;
    char* capacity;
    char* limit;
    static MonitorStream& GetMonitorStream()
    {
        return *(MonitorStream*)TlsGetValue(DAT_0126835c);
    }
};
static __forceinline void Monitor(const char* name)
{
    MonitorStream& stream = MonitorStream::GetMonitorStream();
    if (stream.cursor < stream.limit)
    {
        MonitorCommand* cmd = (MonitorCommand*)stream.cursor;
        cmd->name = name;
        cmd->setTime();
        stream.cursor = (char*)(cmd + 1);
    }
}
static __forceinline void Monitor(const char* name, volatile unsigned int& slot)
{
    MonitorStream& stream = MonitorStream::GetMonitorStream();
    if (stream.cursor < stream.limit)
    {
        MonitorCommand* cmd = (MonitorCommand*)stream.cursor;
        cmd->name = name;
        cmd->setTime(slot);
        stream.cursor = (char*)(cmd + 1);
    }
}
struct MemoryAllocator
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void ReleaseBlock(void*, int);
};
struct MemoryRouter
{
    char* cursor;
    int unk04, unk08, unk0c;
    MemoryAllocator* allocator;
};
void* __cdecl FUN_00c85750();
static __forceinline MemoryRouter* S00d667b0_router()
{
    return (MemoryRouter*)FUN_00c85750();
}
extern "C" void __cdecl FUN_00c908c0(MemoryAllocator*, void*, int, int);
template <class T> struct LocalArray
{
    T* data;
    int size;
    int capacity;
    T* localMemory;
    __forceinline LocalArray(int count)
    {
        data = 0;
        size = 0;
        capacity = 0x80000000;
        MemoryRouter* router = S00d667b0_router();
        T* cur = (T*)router->cursor;
        router->cursor = (char*)cur + (((unsigned int)count * sizeof(T) + 127u) & ~127u);
        capacity = count | 0x80000000;
        data = cur;
        localMemory = cur;
    }
    static __forceinline void destruct(T* t, int n)
    {
        for (int i = 0; i < n; ++i)
            t[i].~T();
    }
    static __forceinline void construct(T* t, int n)
    {
        for (int i = 0; i < n; ++i)
            new (t + i) T;
    }
    __forceinline void clear()
    {
        destruct(data, size);
        size = 0;
    }
    __forceinline void reserve(MemoryAllocator& a, int n)
    {
        const int cap = capacity & 0x3fffffff;
        if (cap < n)
        {
            int newSize = cap * 2;
            if (n >= newSize)
                newSize = n;
            FUN_00c908c0(&a, this, newSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int count)
    {
        reserve(*S00d667b0_router()->allocator, count);
        destruct(data + count, size - count);
        construct(data + size, count - size);
        size = count;
    }
    __forceinline void deallocate(MemoryAllocator& allocator)
    {
        clear();
        if ((capacity & 0x80000000) == 0)
            allocator.ReleaseBlock(data, (capacity & 0x3fffffff) * sizeof(T));
    }
    __forceinline void releaseLocal()
    {
        if (localMemory == data)
            clear();
        T* lm = localMemory;
        S00d667b0_router()->cursor = (char*)lm;
        deallocate(*S00d667b0_router()->allocator);
    }
    __forceinline void releaseAndReset()
    {
        releaseLocal();
        data = 0;
        capacity = 0x80000000;
    }
};
struct __declspec(align(16)) FourFloatVector
{
    float x, y, z, w;
};
struct Transform
{
    FourFloatVector rotation[3];
    FourFloatVector translation;
};
struct Aabb
{
    FourFloatVector min, max;
};
struct ReferenceObject
{
    virtual ~ReferenceObject();
    unsigned short memorySize, refCount;
};
struct DisplayGeometry : ReferenceObject
{
    virtual ~DisplayGeometry();
    void* geometry;
    Transform transform;
    int type;
};
struct FUN_00de1210 : DisplayGeometry
{
    Aabb bounds;
    FUN_00de1210();
    virtual ~FUN_00de1210();
    void FUN_00de1170(const FourFloatVector&, const FourFloatVector&);
};
struct Collidable
{
    void* shape;
    unsigned int shapeKey;
    const Transform* motion;
};
struct Phantom : ReferenceObject
{
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void getAabb(Aabb&) const;
    void* world;
    unsigned int userData;
    Collidable collidable;
};
struct PhantomWorld
{
    int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8, unk0dc;
    int unk0e0, unk0e4, unk0e8, unk0ec, unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c;
    struct PhantomArray
    {
        Phantom** data;
        int size;
        int capacity;
    } phantoms;
};
struct DisplayHandler
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void m_bUpdateGeometry(const Transform*, const void*, int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void DisplayGeometryList(LocalArray<DisplayGeometry*>&, int, int, int);
};
struct ProcessBase
{
    virtual void processSlot0();
    int unk04, unk08;
    DisplayHandler* displayHandler;
    int unk10, unk14, unk18, unk1c;
};
struct PostSimulationListener
{
    virtual void FUN_00d667b0(PhantomWorld*) = 0;
};
extern int DAT_01268ff0;
struct S00d667b0_Viewer : ProcessBase, PostSimulationListener
{
    Phantom** tracked;
    int trackedCount;
    int trackedCapacity;
    virtual void FUN_00d667b0(PhantomWorld*);
    __forceinline void updateTracked()
    {
        for (int i = 0; i < trackedCount; ++i)
        {
            Phantom* phantom = tracked[i];
            displayHandler->m_bUpdateGeometry(phantom->collidable.motion, &phantom->collidable, DAT_01268ff0);
        }
    }
};
extern int DAT_01268ff0;
extern int DAT_01268ff4;
// Builds display geometry boxes from the phantom world's AABBs, submits them to the display handler, and updates tracked phantoms.
// @fnv 0x00d667b0
void S00d667b0_Viewer::FUN_00d667b0(PhantomWorld* world)
{
    Monitor(str_010d1c38);
    {
        const PhantomWorld::PhantomArray& phantoms = world->phantoms;
        LocalArray<FUN_00de1210> boxes(phantoms.size);
        boxes.SetSizeAndGrow(phantoms.size);
        LocalArray<DisplayGeometry*> geometries(phantoms.size);
        geometries.SetSizeAndGrow(phantoms.size);
        for (int i = 0; i < phantoms.size; ++i)
        {
            Aabb bounds;
            phantoms.data[i]->getAabb(bounds);
            boxes.data[i].FUN_00de1170(bounds.min, bounds.max);
            geometries.data[i] = boxes.data + i;
        }
        DisplayHandler* handler = displayHandler;
        handler->DisplayGeometryList(geometries, DAT_01268ff4, 0, DAT_01268ff0);
        geometries.releaseAndReset();
        boxes.releaseLocal();
    }
    updateTracked();
    Monitor(str_010c41f8);
}

namespace fnv_00d66b20 {
// sub ecx,0x20; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x20).
struct PrimaryBase
{
    virtual void FUN_00d66b20();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct SecondaryBase
{
    virtual void FUN_00d66b20();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66b20
    virtual void FUN_00d66b20();
};

Derived::Derived()
{}
}  // namespace fnv_00d66b20

namespace fnv_00d66b30 {
// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00d66b30();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d66b30();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66b30
    virtual void FUN_00d66b30();
};

Derived::Derived()
{}
}  // namespace fnv_00d66b30

namespace fnv_00d66b40 {
// sub ecx,0x28; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x28).
struct PrimaryBase
{
    virtual void FUN_00d66b40();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

struct SecondaryBase
{
    virtual void FUN_00d66b40();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d66b40
    virtual void FUN_00d66b40();
};

Derived::Derived()
{}
}  // namespace fnv_00d66b40

// Candidate 2 for FUN_00d66b50: this-adjusting thunk {adjustor 0x2c}. The displacement is the
// distance between the two copies of the host base, so the host base is made 44 bytes:
// Plat(8) + Host(44) at 8, Shim : Host at +0x34 -> copies at 8 and 0x34-8? -> delta 0x2c.
// The final overrider's body lives in the next translation unit (0xd66b60), declared only.

struct ThunkH_Plat
{
    void* t_unk00;
    virtual void vf0_aux(int* pArg);
};

struct ThunkH_Host
{
    void* h_unk04;
    void* h_unk08;
    void* h_unk0c;
    void* h_unk10;
    void* h_unk14;
    void* h_unk18;
    void* h_unk1c;
    void* h_unk20;
    void* h_unk24;
    void* h_unk28;
    virtual void FUN_00d66b50(int* pArg);
};

struct ThunkH_Shim : ThunkH_Host
{
    void* s_unk2c;
};

struct ThunkH_Derived : ThunkH_Plat, ThunkH_Host, ThunkH_Shim
{
    ThunkH_Derived();
// @fnv 0x00d66b50
    void FUN_00d66b50(int* pArg);
    void* d_unk40;
};

ThunkH_Derived::ThunkH_Derived()
{}

namespace fnv_00d66530 {
extern int DAT_01268ff0;
extern int DAT_01268ff4;
extern const char str_010d196c[];
extern const char str_010d1be8[];
void __cdecl ResizeAudioStream(void*, void*, int);

struct Vw66530Alloc
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int size);
};
struct Vw66530Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Vw66530Alloc* m_alloc;
    Vw66530Alloc& heap()
    {
        return *m_alloc;
    }
};
Vw66530Router* __cdecl FUN_00c85750();

template <class T> struct Vw66530Array
{
    T* m_data;
    int m_iElementCount;
    int m_capFlags;
    Vw66530Array() : m_data(0), m_iElementCount(0), m_capFlags(0x80000000)
    {}
    void destroy()
    {
        Vw66530Alloc& a = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_capFlags & 0x3fffffff) * sizeof(T));
    }
    int indexOf(T t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
            if (m_data[i] == t)
                return i;
        return -1;
    }
    __forceinline bool contains(T t) const
    {
        return indexOf(t) != -1;
    }
    static void construct(T* p, int n, const T& t)
    {
        for (int i = 0; i < n; i++)
            p[i] = t;
    }
    void AddBack(const T& t)
    {
        Vw66530Router* r = FUN_00c85750();
        if (m_iElementCount == (m_capFlags & 0x3fffffff))
            ResizeAudioStream(r->m_alloc, this, sizeof(T));
        construct(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    void removeAt(int i)
    {
        m_iElementCount--;
        if (m_iElementCount != i)
            m_data[i] = m_data[m_iElementCount];
    }
};

struct Vw66530Entry
{
    virtual ~Vw66530Entry();
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
};

struct Vw66530Info
{
    int unk00;
    int unk04;
    int unk08;
};

struct Vw66530Arg
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual int getType();
    int unk04;
    int unk08;
    int unk0C;
    Vw66530Info m_info;
};

struct Vw66530Global
{
    int unk00;
    int unk04;
    Vw66530Array<int> m_types;
};
extern Vw66530Global* DAT_01268fec;

struct Vw66530Logger
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void log(int a, int b, const char* msg, const char* file, int line);
};
extern Vw66530Logger* DAT_01268360;

struct Vw66530Str
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cb1600(char* buf, int size);
    void FUN_00cc01c0(const char* s);
    void FUN_00cc00e0();
};

struct Vw66530Obj
{
    int unk00;
    int unk04;
    void FUN_00ddfb70();
};
struct Vw66530Col
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void FUN_00ddfb80(Vw66530Obj* o);
    void FUN_00de0f90(int root, Vw66530Array<Vw66530Entry*>* out);
};

struct Vw66530Disp
{
    virtual void v00();
    virtual void add(Vw66530Array<Vw66530Entry*>* arr, int a, Vw66530Info* info, int tag, int root);
    virtual void v08();
    virtual void update(int b, Vw66530Info* info, int tag);
};

struct Vw66530Self
{
    int unk00;
    int unk04;
    Vw66530Array<Vw66530Arg*> m_args;
    void FUN_00d66530(Vw66530Arg* arg);
};

struct Vw66530Outer
{
    Vw66530Disp* m_disp;
    int unk04;
    int unk08;
    int unk0C;
    Vw66530Self self;
};

// For an allowed type and nonzero root, collects entries, drops and logs some, stores arg, then calls the dispatcher's add and update.
// @fnv 0x00d66530
void Vw66530Self::FUN_00d66530(Vw66530Arg* arg)
{
    int root = arg->m_info.unk00;
    Vw66530Info* info = &arg->m_info;
    int type = arg->getType();
    Vw66530Array<Vw66530Entry*> entries;
    Vw66530Str str;
    Vw66530Col col;
    Vw66530Obj o;
    int buf[0x80];
    bool bValid = true;
    if (type != 1 && type != 2)
        bValid = DAT_01268fec->m_types.contains(type);
    if (!bValid || root == 0)
        goto done;
    o.FUN_00ddfb70();
    col.FUN_00ddfb80(&o);
    col.FUN_00de0f90(root, &entries);
    for (int i = entries.m_iElementCount - 1; i >= 0; i--)
    {
        Vw66530Entry* pEntry = entries.m_data[i];
        if (pEntry->unk50 == 6 && pEntry->unk08 == 0)
        {
            str.FUN_00cb1600((char*)buf, 0x200);
            str.FUN_00cc01c0(str_010d196c);
            DAT_01268360->log(0, -1, (char*)buf, str_010d1be8, 0x91);
            str.FUN_00cc00e0();
            entries.removeAt(i);
        }
    }
    m_args.AddBack(arg);
    Vw66530Outer* outer = reinterpret_cast<Vw66530Outer*>((char*)this - 0x10);
    outer->m_disp->add(&entries, info->unk08, info, DAT_01268ff0, root);
    outer->m_disp->update(DAT_01268ff4, info, DAT_01268ff0);
    for (int k = 0; k < entries.m_iElementCount; k++)
        delete entries.m_data[k];
done:
    entries.destroy();
}
}  // namespace fnv_00d66530
