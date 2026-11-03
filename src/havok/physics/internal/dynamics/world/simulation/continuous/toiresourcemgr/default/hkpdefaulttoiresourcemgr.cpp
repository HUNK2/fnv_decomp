
// src/havok/physics/internal/dynamics/world/simulation/continuous/toiresourcemgr/default/hkpdefaulttoiresourcemgr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/dynamics/world/simulation/continuous/toiresourcemgr/default/hkpdefaulttoiresourcemgr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpDefaultToiResourceMgr.h"

extern char g_0126955c_arg0;

// Calls two virtual functions on self: one with a pointer to g_0126955c_arg0, then one with no arguments.
// @fnv 0x00d9fb50
void __stdcall FUN_00d9fb50(void* self, int aiUnused)
{
    (*(void(__thiscall**)(void*, char*))(*(char**)self + 0x18))(self, &g_0126955c_arg0);
    (*(void(__thiscall**)(void*))(*(char**)self + 0x1c))(self);
}

extern int DAT_010d4310;

struct FUN_00d9fb90
{
    void* m_ppVirtualMethodTable;  // +0x00
    short m_pad4;    // +0x04
    short m_pad6;    // +0x06
    int m_pad8;      // +0x08
    int m_fieldC;    // +0x0c

    FUN_00d9fb90();
};

// @fnv 0x00d9fb90
FUN_00d9fb90::FUN_00d9fb90()
{
    m_pad6 = 1;
    m_ppVirtualMethodTable = (void*)&DAT_010d4310;
    m_fieldC = 0x20000;
}

struct FUN_00d9fc30Arg
{
    unsigned char pad_00[0x18];
    int memoryType;
};

struct MemoryManager
{
    virtual void* Function0() = 0;
    virtual void* Function1() = 0;
    virtual void* Function2() = 0;
    virtual void* Function3() = 0;
    virtual void* Function4(int, int) = 0;
};

struct MemoryRouter
{
    unsigned char pad_00[0x18];
    MemoryManager* pMemoryManager;
};

MemoryRouter* __cdecl _D1A0E0GetMemoryRouter();

struct FUN_00d9fc30Class
{
    void* pVftable;
    void* pUnknown;
    int allocationSize;

    void* AllocateMemory(int, int, FUN_00d9fc30Arg*);
};

// Allocates this object's allocationSize bytes from the memory manager obtained via the memory router, using the memory type from pInfo.
// @fnv 0x00d9fc30
void* FUN_00d9fc30Class::AllocateMemory(int, int, FUN_00d9fc30Arg* pInfo)
{
    int size = this->allocationSize;
    int memoryType = pInfo->memoryType;
    MemoryRouter* pRouter = _D1A0E0GetMemoryRouter();
    return pRouter->pMemoryManager->Function4(memoryType, size);
}

namespace fnv_00d9fc70 {
struct FUN_00d9fc70_MemoryManager;

typedef void(__thiscall* FUN_00d9fc70_Callback)(FUN_00d9fc70_MemoryManager*, void*, unsigned short);

struct FUN_00d9fc70_MemoryManager
{
    FUN_00d9fc70_Callback* vtable;
};

struct FUN_00d9fc70_Router
{
    void* vtable;
    unsigned char padding[12];
    FUN_00d9fc70_MemoryManager* memoryManager;
};

struct FUN_00d9fc70_Class
{
    void* vtable;
    unsigned short value;

    void __thiscall FUN_00d9fb30();
    void* __thiscall FUN_00d9fc70(unsigned char flag);
};

FUN_00d9fc70_Router* _D1A0E0GetMemoryRouter();

// Calls FUN_00d9fb30, then if flag bit 0 is set, invokes the memory manager's vtable[2] callback with this and value, and returns this.
// @fnv 0x00d9fc70
void* __thiscall FUN_00d9fc70_Class::FUN_00d9fc70(unsigned char flag)
{
    FUN_00d9fb30();

    if (flag & 1)
    {
        FUN_00d9fc70_Router* router = _D1A0E0GetMemoryRouter();
        FUN_00d9fc70_MemoryManager* memoryManager = router->memoryManager;
        unsigned short size = value;
        FUN_00d9fc70_Callback callback = memoryManager->vtable[2];

        callback(memoryManager, this, size);
    }

    return this;
}
}  // namespace fnv_00d9fc70

// @fnv 0x00d9fb70
int __cdecl FUN_00d9fb70()
{
    return 1;
}

// hkpDefaultToiResourceMgr_getClassType
// Returns the address of the global registration object that lives at
// DAT_0126955c.  The startup code fills that object (13 dwords) through a
// constructor call, and this getter hands out its address.
extern int DAT_0126955c;

// @fnv 0x00d9fc60
int* __cdecl hkpDefaultToiResourceMgr_getClassType()
{
    return &DAT_0126955c;
}

// @fnv 0x00d9fb80
int __stdcall FUN_00d9fb80(int arg0)
{
    return 0;
}

class hkMemoryAllocatorD9FB
{
  public:
    virtual ~hkMemoryAllocatorD9FB() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
};

struct hkMemoryRouterD9FB
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    hkMemoryAllocatorD9FB* m_pSolver;

    hkMemoryAllocatorD9FB& solver()
    {
        return *m_pSolver;
    }
};

extern "C" hkMemoryRouterD9FB& __cdecl FUN_00c85750() throw();

struct hkBoolD9FB
{
    char m_cBooleanValue;
    hkBoolD9FB()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

enum hkResultD9FB
{
    HK_SUCCESS_D9FB = 0,
    HK_FAILURE_D9FB = 1
};

struct hkpToiEventD9FB;
template <class T> struct hkArrayD9FB
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct hkpToiResourcesD9FB
{
    int m_iFirstValue;
    int m_iSecondInteger;
    int m_iThirdValue;
    int m_iFourthValue;
    int m_iFifthInteger;
    int m_numRequiredStepsForSolver;
    char* m_pCharacterBuffer;
    int m_iCharacterBufferSize;
};

class hkpDefaultToiResourceMgrD9FB
{
  public:
    virtual ~hkpDefaultToiResourceMgrD9FB();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_iNumToiResources;
    int m_iMaxNumToiResources;

    hkBoolD9FB FUN_00d9fb40(const hkpToiEventD9FB& event) throw();
    hkResultD9FB AllocateToiResources(const hkpToiEventD9FB& event, const hkArrayD9FB<hkpToiEventD9FB>& otherEvents,
                                      hkpToiResourcesD9FB& resourcesOut);
};

template <class T> inline T* bufAllocD9FB(hkMemoryAllocatorD9FB& a, int& n)
{
    int nb = n * sizeof(T);
    T* p = static_cast<T*>(a.AllocateBufferWithSize(nb));
    n = nb / sizeof(T);
    return p;
}

// @fnv 0x00d9fbb0
hkResultD9FB hkpDefaultToiResourceMgrD9FB::AllocateToiResources(const hkpToiEventD9FB& event,
                                                                const hkArrayD9FB<hkpToiEventD9FB>& otherEvents,
                                                                hkpToiResourcesD9FB& resourcesOut)
{
    if (FUN_00d9fb40(event))
    {
        m_iNumToiResources = resourcesOut.m_iCharacterBufferSize = m_iMaxNumToiResources;
        resourcesOut.m_pCharacterBuffer = bufAllocD9FB<char>(FUN_00c85750().solver(), m_iNumToiResources);
        resourcesOut.m_iThirdValue = 1000;
        resourcesOut.m_iFourthValue = 1000;
        resourcesOut.m_iSecondInteger = 1000;
        resourcesOut.m_iFifthInteger = 3;
        resourcesOut.m_numRequiredStepsForSolver = 4;
        resourcesOut.m_iFirstValue = 3;
        return HK_SUCCESS_D9FB;
    }
    return HK_FAILURE_D9FB;
}
