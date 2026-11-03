
// src/gamebryo2.2/corelibs/niparticle/nipsysupdatetask_noehsc_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/gamebryo2.2/corelibs/niparticle/nipsysupdatetask.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/niparticle/nipsysupdatetask.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysupdatetask.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void* g_01202580;
void* __cdecl NiPSysUpdateTask_GetRTTI();
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
NiPSysUpdateTask* PopNiPSysUpdateTask();
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
void __cdecl DestroyManager();
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

extern "C" void* __cdecl FUN_00aa1420(unsigned int size);
struct C25990Elem
{
    void* m_vf;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    C25990Elem();
    ~C25990Elem()
    {}
    static void* operator new[](unsigned int size, unsigned int count)
    {
        if (count == 0)
            return DAT_011f6238.Alloc(4);
        return FUN_00aa1420(size);
    }
    static void operator delete[](void* p);
};
// @fnv 0x00c25990
void* __cdecl FUN_00c25990(unsigned int count)
{
    return new (count) C25990Elem[count];
}
