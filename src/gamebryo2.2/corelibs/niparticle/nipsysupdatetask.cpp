
// src/gamebryo2.2/corelibs/niparticle/nipsysupdatetask.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysupdatetask.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_01202580;

// @fnv 0x00c25870
void* __cdecl NiPSysUpdateTask_GetRTTI()
{
    return &g_01202580;
}

struct NiRefObject
{
    ~NiRefObject();
};
extern int DAT_010be45c;
extern int DAT_01069674;
extern int(__stdcall* DAT_00fdf1c4)(void*);
struct Obj
{
    virtual void u0();
    virtual void u1();
    int m_ref;
};
struct S
{
    void* vf;
    int _4;
    int _8;
    Obj* volatile _c;
    void Destroy();
};
// @fnv 0x00c25880
void S::Destroy()
{
    int(__stdcall * f)(void*) = DAT_00fdf1c4;
    *(void* volatile*)this = (void*)&DAT_010be45c;
    Obj* p = _c;
    if (p)
    {
        if (f(&p->m_ref) == 0)
            p->u1();
        _c = 0;
    }
    p = _c;
    if (p)
    {
        if (f(&p->m_ref) == 0)
            p->u1();
    }
    *(void* volatile*)this = (void*)&DAT_01069674;
    ((NiRefObject*)this)->~NiRefObject();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct Ref_00c258e0
{
    virtual void F0();
    virtual void F1();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            F1();
    }
};
struct Host_00c258e0
{
    char _pad[12];
    Ref_00c258e0* m_ptr;
    float m_f;
    void AssignRefAndValue(Ref_00c258e0* pkObject, float fNew);
};
// @fnv 0x00c258e0
void Host_00c258e0::AssignRefAndValue(Ref_00c258e0* pkObject, float afValue)
{
    if (m_ptr != pkObject)
    {
        if (m_ptr)
            m_ptr->DecRefCount();
        m_ptr = pkObject;
        if (m_ptr)
            m_ptr->IncRefCount();
    }
    m_f = afValue;
}

extern unsigned char DAT_011f5b08;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct FakeSys
{
    void** vtbl;
    volatile long ref;
};
struct Task
{
    void** vtbl;
    int _a;
    int _b;
    FakeSys* sys;
    float tm;
    void ReleaseSysAndDispatch();
};
// @fnv 0x00c25930
void Task::ReleaseSysAndDispatch()
{
    FakeSys* p = sys;
    if (p && !DAT_011f5b08)
    {
        ((void(__thiscall*)(FakeSys*, float))p->vtbl[61])(p, tm);
        FakeSys* pSysRef = sys;
        if (pSysRef)
        {
            if (InterlockedDecrement(&pSysRef->ref) == 0)
                ((void(__thiscall*)(FakeSys*))pSysRef->vtbl[1])(pSysRef);
            sys = 0;
        }
    }
    ((void(__thiscall*)(Task*))vtbl[37])(this);
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct NiPSysUpdateTask
{
};
struct PoolHelper
{
    void __thiscall AppendRecords(int);
};
extern void* DAT_011aeb98;
extern int DAT_011aeba0;
extern int DAT_011aeba8;
extern int DAT_01202600;
// Under a critical section, grows the pool when empty, pops the last task into slot 0 and returns the previous slot-0 task.
// @fnv 0x00c25c40
NiPSysUpdateTask* PopNiPSysUpdateTask()
{
    EnterCriticalSection((void*)&DAT_01202600);
    if (DAT_011aeba0 == 0)
    {
        ((PoolHelper*)&DAT_011aeb98)->AppendRecords(DAT_011aeba8);
        DAT_011aeba8 = DAT_011aeba8 * 2;
    }
    NiPSysUpdateTask* pkTask = ((NiPSysUpdateTask**)DAT_011aeb98)[0];
    DAT_011aeba0--;
    ((NiPSysUpdateTask**)DAT_011aeb98)[0] = ((NiPSysUpdateTask**)DAT_011aeb98)[DAT_011aeba0];
    LeaveCriticalSection((void*)&DAT_01202600);
    return pkTask;
}

typedef unsigned int C25AC0size_t;

struct C25AC0MemoryManager
{
    void Deallocate(void* pvMem);
};
extern C25AC0MemoryManager g_C25AC0MemoryManager;

inline void __cdecl operator delete(void* pvMem)
{
    g_C25AC0MemoryManager.Deallocate(pvMem);
}
inline void __cdecl operator delete[](void* pvMem)
{
    g_C25AC0MemoryManager.Deallocate(pvMem);
}

struct C25AC0MemObject
{
};

struct C25AC0Entry : C25AC0MemObject
{
    virtual ~C25AC0Entry();
};

struct C25AC0Helper : C25AC0MemObject
{
    void DeleteThis(int iFlags);
};

struct C25AC0Manager : C25AC0MemObject
{
    C25AC0Entry* m_pkEntryArray;
    int unk04;
    C25AC0Helper* m_pkHelper;

    ~C25AC0Manager()
    {
        delete[] m_pkEntryArray;
        if (m_pkHelper)
            m_pkHelper->DeleteThis(1);
    }
};

extern C25AC0Manager* g_C25AC0Instance;
extern int g_C25AC0Count;
extern int g_C25AC0Current;
extern int g_C25AC0Default;

// Resets the count to zero, deletes the global manager instance, and restores the current value from the default.
// @fnv 0x00c25ac0
void __cdecl DestroyManager()
{
    C25AC0Manager* pkManager = g_C25AC0Instance;
    g_C25AC0Count = 0;
    delete pkManager;
    g_C25AC0Current = g_C25AC0Default;
}

// The per-count link record the game allocates: { data, count, next }.
struct LinkRec_00c25b30
{
    unsigned char* m_data;
    unsigned int m_uiItemCount;
    LinkRec_00c25b30* m_next;
};

// The game's global memory manager object.
struct PoolAlloc_00c25b30
{
    void* Alloc(unsigned int size);
};
extern PoolAlloc_00c25b30 DAT_011f6238;

// Builds the array of 20-byte link records (lives in another unit of the game).
void* __cdecl FUN_00c25990(unsigned int count);

// The link-id set: { items, capacity, size, head }.
struct LinkIDSet_00c25b30
{
    void** m_items;
    unsigned int m_cap;
    unsigned int m_iElementCount;
    LinkRec_00c25b30* m_pFirstNode;

    void Grow(unsigned int newCapacity);
    void AppendRecords(unsigned int count);
};

// Allocates a record block of count entries, appends a pointer to each entry to m_items (growing as needed), and links the block at the head of the list.
// @fnv 0x00c25b30
void LinkIDSet_00c25b30::AppendRecords(unsigned int count)
{
    LinkRec_00c25b30* pBlock;
    unsigned int i;
    LinkRec_00c25b30* pNewBlock = (LinkRec_00c25b30*)DAT_011f6238.Alloc(0xc);
    if (pNewBlock != 0)
    {
        pNewBlock->m_uiItemCount = count;
        pNewBlock->m_next = 0;
        if (count > 0)
            pNewBlock->m_data = (unsigned char*)FUN_00c25990(count);
        else
            pNewBlock->m_data = 0;
        pBlock = pNewBlock;
    }
    else
    {
        pBlock = 0;
    }

    i = 0;
    if (0 < count)
    {
        unsigned int offset = 0;
        for (; i < count; i++)
        {
            unsigned char* p;
            if (i >= pBlock->m_uiItemCount)
                p = 0;
            else
                p = pBlock->m_data + offset;
            if (m_iElementCount == m_cap)
            {
                unsigned int newCap;
                if (m_cap > 0)
                    newCap = m_cap * 2;
                else
                    newCap = 1;
                Grow(newCap);
            }
            m_items[m_iElementCount] = p;
            m_iElementCount++;
            offset += 0x14;
        }
    }
    pBlock->m_next = m_pFirstNode;
    m_pFirstNode = pBlock;
}

struct S_00c25be0
{
    int unk00;
    int unk04;
    int unk08;
    Obj* volatile unk0c;

    bool FUN_00c25be0();
};

struct S_00e7ec00
{
    void __thiscall FindOrAdd(void*);
};

extern void(__stdcall* DAT_00fdf05c)(void*);
extern void(__stdcall* DAT_00fdf100)(void*);

// @fnv 0x00c25be0
bool S_00c25be0::FUN_00c25be0()
{
    Obj* pObj = unk0c;

    if (pObj != 0)
    {
        if (DAT_00fdf1c4(reinterpret_cast<void*>(reinterpret_cast<char*>(pObj) + 4)) == 0)
        {
            pObj->u1();
        }

        unk0c = 0;
    }

    DAT_00fdf05c(&DAT_01202600);

    S_00c25be0* pSelf = this;
    reinterpret_cast<S_00e7ec00*>(&DAT_011aeb98)->FindOrAdd(&pSelf);

    DAT_00fdf100(&DAT_01202600);

    return true;
}

class FUN_00a5d3d0
{
  public:
    ~FUN_00a5d3d0();
};
void __cdecl operator delete(void* pv, int iSize);
void __cdecl FUN_00aa1490(void* pv, unsigned int uiSize);

struct Elem_c25 : FUN_00a5d3d0
{
    void* m_vf;
    int m_iWordAt04;
    int m_8;
    Obj* volatile m_iThirdValue;
    int m_10;
    __forceinline void Destruct()
    {
        *(int* volatile*)this = &DAT_010be45c;
        Obj* pkObj = m_iThirdValue;
        if (pkObj)
        {
            if (InterlockedDecrement((volatile long*)&pkObj->m_ref) == 0)
                pkObj->u1();
            m_iThirdValue = 0;
        }
        Obj* pkObjCur = m_iThirdValue;
        if (pkObjCur)
        {
            if (InterlockedDecrement((volatile long*)&pkObjCur->m_ref) == 0)
                pkObjCur->u1();
        }
        *(int**)this = &DAT_01069674;
        this->FUN_00a5d3d0::~FUN_00a5d3d0();
    }
    void* DestroyElements(unsigned int uiFlags);
};

// @fnv 0x00c259f0
void* Elem_c25::DestroyElements(unsigned int uiFlags)
{
    if (uiFlags & 2)
    {
        int* piCount = (int*)this - 1;
        int iCount = *piCount;
        Elem_c25* pkElem = this + iCount;
        while (--iCount >= 0)
        {
            --pkElem;
            pkElem->Destruct();
        }
        if (uiFlags & 1)
            FUN_00aa1490(piCount, 0x14);
        return piCount;
    }
    ((S*)this)->Destroy();
    if (uiFlags & 1)
        operator delete(this, 0x14);
    return this;
}
