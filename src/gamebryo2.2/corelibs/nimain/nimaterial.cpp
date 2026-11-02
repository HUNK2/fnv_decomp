
// src/gamebryo2.2/corelibs/nimain/nimaterial.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nimaterial.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" char const* const g_011f6048_arg1;

// @fnv 0x00a8f860
char const* const* __cdecl FUN_00a8f860()
{
    return &g_011f6048_arg1;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Handler
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void run();
};
struct Registry
{
    int unk00;
    unsigned count04;
    void** entries08;
    void FUN_00a8f770(void** current, char** data, Handler** next);
};
struct CallbackState
{
    Handler* handler;
    void* current;
    char* data;
};
extern Registry* DAT_011f5e34;
extern char* DAT_0109b220;
// Finds the first non-null registry entry, then repeatedly calls FUN_00a8f770 and runs each returned handler until current becomes null.
// @fnv 0x00a8f870
void __cdecl RunRegistryHandlers()
{
    CallbackState callbackState;
    Registry* registry = DAT_011f5e34;
    unsigned index = 0;
    if (index < registry->count04)
    {
        void** ppEntry = registry->entries08;
        do
        {
            if (*ppEntry != 0)
            {
                callbackState.current = registry->entries08[index];
                goto found;
            }
            ++index;
            ++ppEntry;
        } while (index < registry->count04);
    }
    callbackState.current = 0;
found:
    callbackState.handler = 0;
    callbackState.data = DAT_0109b220;
    if (callbackState.current != 0)
    {
        do
        {
            DAT_011f5e34->FUN_00a8f770(&callbackState.current, &callbackState.data, &callbackState.handler);
            if (callbackState.handler)
            {
                callbackState.handler->run();
            }
        } while (callbackState.current != 0);
        if (callbackState.data != DAT_0109b220)
        {
            InterlockedDecrement((volatile long*)(callbackState.data - 8));
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);

extern long g_liveObjectCount;

extern char* g_emptyStringData;

struct String
{
    char* m_pData;

    String(const String& other)
    {
        if (other.m_pData != g_emptyStringData)
            InterlockedIncrement((long volatile*)(other.m_pData - 8));
        m_pData = other.m_pData;
    }
};

struct FUN_00a8f950;

struct ObjectRegistry
{
    void Register(String* name, FUN_00a8f950* object) throw();
};

extern ObjectRegistry* g_pObjectRegistry;

struct CountedObject
{
    virtual ~CountedObject();
    int m_iRefCount;

    CountedObject()
    {
        m_iRefCount = 0;
        InterlockedIncrement(&g_liveObjectCount);
    }
};

struct FUN_00a8f950 : CountedObject
{
    String m_name;
    FUN_00a8f950(const String& name);
    virtual ~FUN_00a8f950();
};

// Constructs a CountedObject-derived object holding a copy of name and registers it with g_pObjectRegistry.
// @fnv 0x00a8f950
FUN_00a8f950::FUN_00a8f950(const String& name) : m_name(name)
{
    g_pObjectRegistry->Register(&m_name, this);
}

void __cdecl FUN_00aa1460(void* pvMem, unsigned int uiSize);

extern long DAT_011f4400;

class NiFixedStringA8F9
{
  public:
    ~NiFixedStringA8F9()
    {
        if (m_kHandle != DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
    }
    char* m_kHandle;
};

class RegistryA8F9
{
  public:
    void FUN_00aa0250(NiFixedStringA8F9& kName) throw();
};

namespace a8f9 {
extern RegistryA8F9* DAT_011f5e34;
}

class NiRefObjectA8F9
{
  public:
    virtual ~NiRefObjectA8F9()
    {
        InterlockedDecrement(&DAT_011f4400);
    }
    long m_uiRefCount;
};

class NamedA8F9 : public NiRefObjectA8F9
{
  public:
    virtual ~NamedA8F9()
    {
        a8f9::DAT_011f5e34->FUN_00aa0250(m_kName);
    }

    static void operator delete(void* pvMem, unsigned int uiSize)
    {
        FUN_00aa1460(pvMem, uiSize);
    }

    NiFixedStringA8F9 m_kName;

    NamedA8F9* FUN_00a8f9b0(unsigned int uiFlags);
};

// Calls the destructor and, when uiFlags has bit 0 set, frees the object via operator delete, then returns this.
// @fnv 0x00a8f9b0
NamedA8F9* NamedA8F9::FUN_00a8f9b0(unsigned int uiFlags)
{
    this->NamedA8F9::~NamedA8F9();
    if (uiFlags & 1)
        NamedA8F9::operator delete(this, sizeof(NamedA8F9));
    return this;
}

struct A8F910MemoryManager
{
    void Deallocate(void* pvMem);
};
extern A8F910MemoryManager g_A8F910MemoryManager;

extern "C" void __cdecl A8F910NiFree(void* pvMem);

struct FUN_00a8f910
{
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;

    FUN_00a8f910();
    virtual ~FUN_00a8f910();

    void RemoveAll();

    static void operator delete(void* pvMem)
    {
        g_A8F910MemoryManager.Deallocate(pvMem);
    }
};

// Default constructor for a hash table object that holds a hash size and an array of pointers.
// @fnv 0x00a8f910
FUN_00a8f910::FUN_00a8f910()
{}

FUN_00a8f910::~FUN_00a8f910()
{
    RemoveAll();
    A8F910NiFree(m_ppkHashTable);
}

#include <windows.h>
struct NiPointerStandIn
{
    void* m_pObject;
};

struct ArrayStandIn
{
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short m_usSize;
    unsigned short unk0c;

    void SetAt(unsigned int idx, const NiPointerStandIn& value);
    void SetSize(unsigned int size);
};

extern "C" ArrayStandIn DAT_011ac040;
extern "C" CRITICAL_SECTION DAT_011f600c;

// Locks DAT_011f600c, nulls every element of DAT_011ac040, resets its size to zero, and unlocks.
// @fnv 0x00a9bb60
void __cdecl FUN_00a9bb60()
{
    EnterCriticalSection(&DAT_011f600c);
    unsigned int uiIndex = 0;
    if (uiIndex < DAT_011ac040.m_usSize)
    {
        NiPointerStandIn value = {0};
        do
        {
            DAT_011ac040.SetAt(uiIndex, value);
            ++uiIndex;
        } while (uiIndex < DAT_011ac040.m_usSize);
    }

    DAT_011ac040.SetSize(0);

    LeaveCriticalSection(&DAT_011f600c);
}
