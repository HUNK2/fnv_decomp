
// src/havok/physics/dynamics/world/util/hkpworldcallbackutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldcallbackutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" unsigned long _tls_index;
struct AudioTlsState
{
    unsigned unk0;
    unsigned unk4;
    unsigned unk8;
    unsigned unkC;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1C;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2C;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3C;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4C;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5C;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6C;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7C;
    unsigned unk80;
    unsigned unk84;
    unsigned unk88;
    unsigned unk8C;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    unsigned unk9C;
    unsigned unkA0;
    unsigned unkA4;
    unsigned unkA8;
    unsigned unkAC;
    unsigned unkB0;
    unsigned unkB4;
    unsigned unkB8;
    unsigned unkBC;
    unsigned unkC0;
    unsigned unkC4;
    unsigned unkC8;
    unsigned unkCC;
    unsigned unkD0;
    unsigned unkD4;
    unsigned unkD8;
    unsigned unkDC;
    unsigned unkE0;
    unsigned unkE4;
    unsigned unkE8;
    unsigned unkEC;
    unsigned unkF0;
    unsigned unkF4;
    unsigned unkF8;
    unsigned unkFC;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10C;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11C;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12C;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13C;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14C;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15C;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16C;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17C;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18C;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19C;
    unsigned unk1A0;
    unsigned unk1A4;
    unsigned unk1A8;
    unsigned unk1AC;
    unsigned unk1B0;
    unsigned unk1B4;
    unsigned unk1B8;
    unsigned unk1BC;
    unsigned unk1C0;
    unsigned unk1C4;
    unsigned unk1C8;
    unsigned unk1CC;
    unsigned unk1D0;
    unsigned unk1D4;
    unsigned unk1D8;
    unsigned unk1DC;
    unsigned unk1E0;
    unsigned unk1E4;
    unsigned unk1E8;
    unsigned unk1EC;
    unsigned unk1F0;
    unsigned unk1F4;
    unsigned unk1F8;
    unsigned unk1FC;
    unsigned unk200;
    unsigned unk204;
    unsigned unk208;
    unsigned unk20C;
    unsigned unk210;
    unsigned unk214;
    unsigned unk218;
    unsigned unk21C;
    unsigned unk220;
    unsigned unk224;
    unsigned unk228;
    unsigned unk22C;
    unsigned unk230;
    unsigned unk234;
    unsigned unk238;
    unsigned unk23C;
    unsigned unk240;
    unsigned unk244;
    unsigned unk248;
    unsigned unk24C;
    unsigned unk250;
    unsigned unk254;
    unsigned unk258;
    unsigned unk25C;
    unsigned unk260;
    unsigned unk264;
    unsigned unk268;
    unsigned unk26C;
    unsigned unk270;
    unsigned unk274;
    unsigned unk278;
    unsigned unk27C;
    unsigned unk280;
    unsigned unk284;
    unsigned unk288;
    unsigned unk28C;
    unsigned unk290;
    unsigned unk294;
    unsigned unk298;
    unsigned unk29C;
    unsigned unk2A0;
    unsigned unk2A4;
    unsigned unk2A8;
    unsigned unk2AC;
    unsigned unk2B0;
    unsigned m_uiMemoryContext;
};
__declspec(thread) AudioTlsState threadData;
struct ScopedContext
{
    unsigned previous;
    __forceinline ScopedContext(unsigned value)
    {
        previous = threadData.m_uiMemoryContext;
        threadData.m_uiMemoryContext = value;
    }
    __forceinline ~ScopedContext()
    {
        threadData.m_uiMemoryContext = previous;
    }
};
struct Metadata
{
    int unk00, unk04, unk08, unk0C, unk10;
    unsigned char flags;
};
struct Reference
{
    int unk00, unk04, unk08;
    Metadata* metadata;
    void FUN_00c905b0();
};
struct World
{
    void FUN_00c95800(Reference**, unsigned);
};
void* FUN_00ec61c0(void*, int, unsigned);
struct Owner
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual World* GetWorld();
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    Reference** references;
    unsigned count;
    void ClearReferences();
};
// @fnv 0x00c67bc0
void Owner::ClearReferences()
{
    ScopedContext scope(16);
    if (count > 0)
    {
        if (count >= 200)
            count = 200;
        World* world = GetWorld();
        if (world)
        {
            world->FUN_00c95800(references, count);
            for (unsigned i = 0; i < count; ++i)
            {
                Reference* reference = references[i];
                if (reference)
                {
                    Metadata* metadata = reference->metadata;
                    if (metadata)
                        metadata->flags &= ~32;
                }
                references[i]->FUN_00c905b0();
            }
            FUN_00ec61c0(references, 0, count * 4);
            count = 0;
        }
    }
}

struct D00370Array
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        char* dst = (char*)&m_data[index];
        const char* src = (const char*)&m_data[index + 1];
        int nbytes = (m_iElementCount - index) * 4;
        for (int i = 0; i < nbytes; i += 4)
            *(int*)(dst + i) = *(const int*)(src + i);
    }
};

// Iterates cleanupArray backwards and removes every null element via removeAtAndCopy.
// @fnv 0x00d00370
static void FUN_00d00370(D00370Array& cleanupArray)
{
    for (int i = cleanupArray.m_iElementCount - 1; i >= 0; i--)
    {
        if (cleanupArray.m_data[i] == 0)
            cleanupArray.removeAtAndCopy(i);
    }
}

// Callers so the file-static helper is emitted with its register calling convention.
void D00370CleanupBoth(D00370Array* a, D00370Array* b)
{
    FUN_00d00370(*a);
    FUN_00d00370(*b);
}

// RemoveZeroEntries - removes the NULL entries of a small array.

struct FNV_SmallArray_00d00320
{
    int* m_pItems;
    unsigned short m_uiItemCount;
};

// Removes every zero element from the array by shifting later items down and decrementing the count.
// @fnv 0x00d00320
static __declspec(noinline) void RemoveZeroEntries(FNV_SmallArray_00d00320* pArray)
{
    unsigned short nCount = pArray->m_uiItemCount;
    for (int i = (int)nCount - 1; i >= 0; i--)
    {
        if (pArray->m_pItems[i] == 0)
        {
            pArray->m_uiItemCount = (unsigned short)(pArray->m_uiItemCount - 1);
            for (int j = i; j < (int)pArray->m_uiItemCount; j++)
            {
                pArray->m_pItems[j] = pArray->m_pItems[j + 1];
            }
        }
    }
}

void KeepAlive_00d00320(FNV_SmallArray_00d00320* pArray)
{
    RemoveZeroEntries(pArray);
}

extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class hkpAction;
class hkpActionListener
{
  public:
    virtual ~hkpActionListener();
    virtual void ActionAddedCallback(hkpAction*);
    virtual void ActionRemovedCallback(hkpAction*);
    virtual void actionShapeSetCallback(hkpAction*);
    virtual void actionDeletedCallback(hkpAction*);
};
struct Array833
{
    hkpActionListener** data;
    int size;
    int capacity;
};
struct World833
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;

    Array833 actionListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00d00370(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(hkpActionListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(hkpActionListener*))
                *(hkpActionListener**)(destination + offset) = *(hkpActionListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0126835c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Invokes ActionAddedCallback on each non-null hkpActionListener in world->actionListeners, then removes null entries from the array.
// @fnv 0x00d003c0
void __cdecl NotifyActionAdded(World833* world, hkpAction* action)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = world->actionListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtactAddCb", beginTicks);
            listeners.data[i]->ActionAddedCallback(action);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00d00370(listeners);
}

namespace fnv_00d00500 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class hkpEntity;
class hkpEntityListener
{
  public:
    virtual ~hkpEntityListener();
    virtual void EntityAddedCallback(hkpEntity*);
    virtual void EntityRemovedCallback(hkpEntity*);
    virtual void EntityShapeSetCallback(hkpEntity*);
    virtual void EntityDeletionCallback(hkpEntity*);
};
struct Array833
{
    hkpEntityListener** data;
    int size;
    int capacity;
};
struct World833
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;

    Array833 entityListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00d00370(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(hkpEntityListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(hkpEntityListener*))
                *(hkpEntityListener**)(destination + offset) = *(hkpEntityListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0126835c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Invokes EntityAddedCallback on each non-null hkpEntityListener in the world's listener array, then compacts the array to remove null entries.
// @fnv 0x00d00500
void __cdecl NotifyEntityAdded(World833* world, hkpEntity* entity)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = world->entityListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtentAddCb", beginTicks);
            listeners.data[i]->EntityAddedCallback(entity);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00d00370(listeners);
}
}  // namespace fnv_00d00500

namespace fnv_00d006e0 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class hkpEntity;
class hkpEntityListener
{
  public:
    virtual ~hkpEntityListener();
    virtual void EntityAddedCallback(hkpEntity*);
    virtual void EntityRemovedCallback(hkpEntity*);
    virtual void EntityShapeSetCallback(hkpEntity*);
    virtual void entitySetMotionTypeCallback(hkpEntity*);
};
struct Array833
{
    hkpEntityListener** data;
    int size;
    int capacity;
};
struct World833
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;

    Array833 entityListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00d00370(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(hkpEntityListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(hkpEntityListener*))
                *(hkpEntityListener**)(destination + offset) = *(hkpEntityListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0126835c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Invokes entitySetMotionTypeCallback on each non-null listener in world->entityListeners, then compacts the listener array via FUN_00d00370.
// @fnv 0x00d006e0
void __cdecl NotifyEntitySetMotionType(World833* world, hkpEntity* entity)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = world->entityListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtsetMotionTypeCb", beginTicks);
            listeners.data[i]->entitySetMotionTypeCallback(entity);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00d00370(listeners);
}
}  // namespace fnv_00d006e0

namespace fnv_00d00780 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class hkpPhantom;
class hkpPhantomListener
{
  public:
    virtual ~hkpPhantomListener();
    virtual void PhantomAddedCallback(hkpPhantom*);
    virtual void PhantomRemovedCallback(hkpPhantom*);
    virtual void phantomShapeSetCallback(hkpPhantom*);
    virtual void phantomDeletedCallback(hkpPhantom*);
};
struct Array833
{
    hkpPhantomListener** data;
    int size;
    int capacity;
};
struct World833
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    Array833 phantomListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00d00370(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(hkpPhantomListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(hkpPhantomListener*))
                *(hkpPhantomListener**)(destination + offset) = *(hkpPhantomListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0126835c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Invokes PhantomAddedCallback on each non-null hkpPhantomListener in world->phantomListeners, then removes null entries via FUN_00d00370.
// @fnv 0x00d00780
void __cdecl NotifyPhantomAdded(World833* world, hkpPhantom* phantom)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = world->phantomListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtphntAddCb", beginTicks);
            listeners.data[i]->PhantomAddedCallback(phantom);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00d00370(listeners);
}
}  // namespace fnv_00d00780

#include <windows.h>

extern DWORD DAT_0126835c;
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);

struct TraceRecord
{
    const char* m_pTag;
    DWORD m_dwTime;
    DWORD unk08;
};

struct TraceBuffer
{
    DWORD unk00;
    TraceRecord* m_pCurrent;
    DWORD unk08;
    TraceRecord* m_pRecordEnd;
};

struct ListenerBase
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void OnEvent(void* apParam);
};

struct ListenerList
{
    ListenerBase** m_ppItems;
    int m_iArrayLength;
};

struct ListenerOwner
{
    DWORD unk0000, unk0004, unk0008, unk000C, unk0010, unk0014, unk0018, unk001C;
    DWORD unk0020, unk0024, unk0028, unk002C, unk0030, unk0034, unk0038, unk003C;
    DWORD unk0040, unk0044, unk0048, unk004C, unk0050, unk0054, unk0058, unk005C;
    DWORD unk0060, unk0064, unk0068, unk006C, unk0070, unk0074, unk0078, unk007C;
    DWORD unk0080, unk0084, unk0088, unk008C, unk0090, unk0094, unk0098, unk009C;
    DWORD unk00A0, unk00A4, unk00A8, unk00AC, unk00B0, unk00B4, unk00B8, unk00BC;
    DWORD unk00C0, unk00C4, unk00C8, unk00CC, unk00D0, unk00D4, unk00D8, unk00DC;
    DWORD unk00E0, unk00E4, unk00E8, unk00EC, unk00F0, unk00F4, unk00F8, unk00FC;
    DWORD unk0100, unk0104, unk0108, unk010C, unk0110, unk0114, unk0118, unk011C;
    DWORD unk0120, unk0124, unk0128, unk012C, unk0130, unk0134, unk0138, unk013C;
    D00370Array m_kNode;
};

// Iterates the listener list in apOwner in reverse, calling OnEvent on each non-null item with tracing, then calls FUN_00d00370 on the list.
// @fnv 0x00d00bf0
void __cdecl FUN_00d00bf0(ListenerOwner* apOwner, void* apParam)
{
    struct State
    {
        volatile DWORD endTick;
        D00370Array* list;
    } state;
    volatile DWORD beginTick;
    state.list = &apOwner->m_kNode;
    int i = state.list->m_iElementCount - 1;
    if (i >= 0)
    {
        LPVOID(WINAPI * pfnTls)(DWORD) = TlsGetValue;
        do
        {
            ListenerBase* pItem = (ListenerBase*)state.list->m_data[i];
            if (pItem != 0)
            {
                TraceBuffer* pBuf = (TraceBuffer*)pfnTls(DAT_0126835c);
                TraceRecord* pRec = pBuf->m_pCurrent;
                if (pRec < pBuf->m_pRecordEnd)
                {
                    pRec->m_pTag = "TtconRepairedCb";
                    _ReadWriteBarrier();
                    beginTick = (DWORD)__rdtsc();
                    pRec->m_dwTime = beginTick;
                    pBuf->m_pCurrent = pRec + 1;
                }
                pItem->OnEvent(apParam);
                TraceBuffer* pBuf2 = (TraceBuffer*)pfnTls(DAT_0126835c);
                TraceRecord* pRec2 = pBuf2->m_pCurrent;
                if (pRec2 < pBuf2->m_pRecordEnd)
                {
                    pRec2->m_pTag = "Et";
                    _ReadWriteBarrier();
                    state.endTick = (DWORD)__rdtsc();
                    pRec2->m_dwTime = state.endTick;
                    pBuf2->m_pCurrent = pRec2 + 1;
                }
            }
        } while (--i >= 0);
    }
    FUN_00d00370(*state.list);
}

struct D00CA0TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D00CA0MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

extern DWORD g_D00CA0TlsIndex;

__forceinline D00CA0MonitorStream& D00CA0GetMonitorStream()
{
    return *(D00CA0MonitorStream*)TlsGetValue(g_D00CA0TlsIndex);
}

__forceinline void D00CA0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    D00CA0MonitorStream& mStream = D00CA0GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        D00CA0TimerCommand* h = (D00CA0TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D00CA0Listener
{
    virtual void entityCallback(void* entity);
};

struct D00CA0ListenerArray
{
    D00CA0Listener** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D00CA0CleanupNullPointers(D00CA0ListenerArray& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D00CA0World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    D00CA0ListenerArray m_kEntityListenerArray;
};

extern const char g_D00CA0TimerEntityCb[];
extern const char g_D00CA0TimerEnd[];

// Invokes entityCallback on each non-null listener in the world's entity listener array, then removes null entries.
// @fnv 0x00d00ca0
void __cdecl FUN_00d00ca0(D00CA0World* world, void* entity)
{
    D00CA0ListenerArray& listeners = world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D00CA0TimerBegin(g_D00CA0TimerEntityCb, beginTicks);
            listeners.m_data[i]->entityCallback(entity);
            D00CA0TimerBegin(g_D00CA0TimerEnd, endTicks);
        }
    }
    D00CA0CleanupNullPointers(listeners);
}

namespace fnv_00d00d40 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class CollisionEvent;
class NewCollisionListener
{
  public:
    virtual ~NewCollisionListener();
    virtual void newCollisionCallback(CollisionEvent*);
};
struct Array833
{
    NewCollisionListener** data;
    int size;
    int capacity;
};
struct World833
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    Array833 collisionListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00d00370(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(NewCollisionListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(NewCollisionListener*))
                *(NewCollisionListener**)(destination + offset) = *(NewCollisionListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0126835c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Invokes newCollisionCallback on each valid collision listener in world->collisionListeners, then compacts the array by removing null entries.
// @fnv 0x00d00d40
void __cdecl DispatchCollisionEvents(World833* world, CollisionEvent* simulation)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = world->collisionListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtNewCollCb", beginTicks);
            listeners.data[i]->newCollisionCallback(simulation);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00d00370(listeners);
}
}  // namespace fnv_00d00d40

struct D00DE0TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D00DE0MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

extern DWORD g_D00DE0TlsIndex;

__forceinline D00DE0MonitorStream& D00DE0GetMonitorStream()
{
    return *(D00DE0MonitorStream*)TlsGetValue(g_D00DE0TlsIndex);
}

__forceinline void D00DE0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    D00DE0MonitorStream& mStream = D00DE0GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        D00DE0TimerCommand* h = (D00DE0TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D00DE0Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void entityCallback(void* entity);
};

struct D00DE0ListenerArray
{
    D00DE0Listener** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D00DE0CleanupNullPointers(D00DE0ListenerArray& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D00DE0World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    D00DE0ListenerArray m_kEntityListenerArray;
};

extern const char g_D00DE0TimerEntityCb[];
extern const char g_D00DE0TimerEnd[];

// Invokes entityCallback on each non-null listener in the world's entity listener array, then removes null entries.
// @fnv 0x00d00de0
void __cdecl FUN_00d00de0(D00DE0World* world, void* entity)
{
    D00DE0ListenerArray& listeners = world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D00DE0TimerBegin(g_D00DE0TimerEntityCb, beginTicks);
            listeners.m_data[i]->entityCallback(entity);
            D00DE0TimerBegin(g_D00DE0TimerEnd, endTicks);
        }
    }
    D00DE0CleanupNullPointers(listeners);
}

struct D00E80TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D00E80MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

extern DWORD g_D00E80TlsIndex;

__forceinline D00E80MonitorStream& D00E80GetMonitorStream()
{
    return *(D00E80MonitorStream*)TlsGetValue(g_D00E80TlsIndex);
}

__forceinline void D00E80TimerBegin(const char* name, volatile unsigned int& ticks)
{
    D00E80MonitorStream& mStream = D00E80GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        D00E80TimerCommand* h = (D00E80TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D00E80World;

struct D00E80Listener
{
    virtual void unk00();
    virtual void actionCallback(D00E80World* pkWorld);
};

struct D00E80ListenerArray
{
    D00E80Listener** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D00E80CleanupNullPointers(D00E80ListenerArray& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D00E80TickPair
{
    volatile unsigned int m_uiBegin;
    volatile unsigned int m_uiEndTick;
};

struct D00E80World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    D00E80ListenerArray m_kEntityListenerArray;
};

extern const char g_D00E80TimerActionCb[];
extern const char g_D00E80TimerEnd[];

// Iterates the world's entity listener array in reverse, calling each non-null listener's actionCallback with the world, then compacts out null entries.
// @fnv 0x00d00e80
void __cdecl FUN_00d00e80(D00E80World* world)
{
    D00E80TickPair kTicks;
    D00E80ListenerArray& listeners = world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            D00E80TimerBegin(g_D00E80TimerActionCb, kTicks.m_uiBegin);
            listeners.m_data[i]->actionCallback(world);
            D00E80TimerBegin(g_D00E80TimerEnd, kTicks.m_uiEndTick);
        }
    }
    D00E80CleanupNullPointers(listeners);
}

namespace fnv_00d00f30 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class hkpPhantom;
class WorldDeletionListener
{
  public:
    virtual ~WorldDeletionListener();
    virtual void unknown04();
    virtual void WorldDeletedCallback(void*);
};
struct Array833
{
    WorldDeletionListener** data;
    int size;
    int capacity;
};
struct World833
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    Array833 worldDeletionListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00d00370(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(WorldDeletionListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(WorldDeletionListener*))
                *(WorldDeletionListener**)(destination + offset) = *(WorldDeletionListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0126835c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Invokes WorldDeletedCallback on each non-null entry in world->worldDeletionListeners, then compacts the array via FUN_00d00370.
// @fnv 0x00d00f30
void __cdecl NotifyWorldDeleted(World833* world)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = world->worldDeletionListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtworldDelCb", beginTicks);
            listeners.data[i]->WorldDeletedCallback(world);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00d00370(listeners);
}
}  // namespace fnv_00d00f30

namespace fnv_00d01380 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class hkpPhantom;
class PostSimulationListener
{
  public:
    virtual ~PostSimulationListener();
    virtual void postSimulationCallback(void*);
};
struct Array833
{
    PostSimulationListener** data;
    int size;
    int capacity;
};
struct World833
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    Array833 postSimulationListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00d00370(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(PostSimulationListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(PostSimulationListener*))
                *(PostSimulationListener**)(destination + offset) = *(PostSimulationListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0126835c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Iterates postSimulationListeners, calling postSimulationCallback on each non-null entry, then compacts the array via FUN_00d00370.
// @fnv 0x00d01380
void __cdecl FUN_00d01380(World833* world)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = world->postSimulationListeners;
    int previousSize = listeners.size;
    int i = previousSize - 1;
    for (; i >= 0; --i)
    {
        if (previousSize > listeners.size)
        {

            i += listeners.size - previousSize;
            previousSize = listeners.size;
        }
        if (listeners.data[i])
        {
            TimerEvent833("TtpostSimCb", beginTicks);
            listeners.data[i]->postSimulationCallback(world);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00d00370(listeners);
}
}  // namespace fnv_00d01380

namespace fnv_00d01440 {
extern "C" void _ReadWriteBarrier();
extern "C" unsigned __int64 __rdtsc();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
class hkpPhantom;
class PostIntegrationListener
{
  public:
    virtual ~PostIntegrationListener();
    virtual void postIntegrationCallback(void*, void*);
};
struct Array833
{
    PostIntegrationListener** data;
    int size;
    int capacity;
};
struct World833
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    Array833 postIntegrationListeners;
};

struct Timer833
{
    const char* command;
    unsigned int time0, time1;
};
struct Stream833
{
    int unk00;
    Timer833* end;
    int unk08;
    Timer833* capacityEnd;
};
static __declspec(noinline) void FUN_00d00370(Array833& listeners)
{
    for (int index = listeners.size - 1; index >= 0; --index)
    {
        if (!listeners.data[index])
        {
            --listeners.size;
            char* destination = (char*)&listeners.data[index];
            const char* source = (const char*)&listeners.data[index + 1];
            int bytes = (listeners.size - index) * sizeof(PostIntegrationListener*);
            for (int offset = 0; offset < bytes; offset += sizeof(PostIntegrationListener*))
                *(PostIntegrationListener**)(destination + offset) =
                    *(PostIntegrationListener* const*)(source + offset);
        }
    }
}
__forceinline void CaptureTicks833(volatile unsigned int& ticks)
{
    ticks = (unsigned int)__rdtsc();
}
__forceinline void TimerEvent833(const char* name, volatile unsigned int& ticks)
{
    Stream833* stream = static_cast<Stream833*>(TlsGetValue(DAT_0126835c));
    Timer833* command = stream->end;
    if (command < stream->capacityEnd)
    {
        command->command = name;
        _ReadWriteBarrier();
        CaptureTicks833(ticks);
        command->time0 = ticks;
        stream->end = command + 1;
    }
}
// Iterates the world's postIntegrationListeners, calling each non-null listener's postIntegrationCallback with world and stepInfo, then compacts the array.
// @fnv 0x00d01440
void __cdecl FUN_00d01440(World833* world, void* stepInfo)
{
    volatile unsigned beginTicks;
    volatile unsigned endTicks;
    Array833& listeners = world->postIntegrationListeners;
    int i = listeners.size - 1;
    for (; i >= 0; --i)
    {
        if (listeners.data[i])
        {
            TimerEvent833("TtpostIntCb", beginTicks);
            listeners.data[i]->postIntegrationCallback(world, stepInfo);
            TimerEvent833("Et", endTicks);
        }
    }
    FUN_00d00370(listeners);
}
}  // namespace fnv_00d01440

struct D014F0TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D014F0MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

extern DWORD g_D014F0TlsIndex;

__forceinline D014F0MonitorStream& D014F0GetMonitorStream()
{
    return *(D014F0MonitorStream*)TlsGetValue(g_D014F0TlsIndex);
}

__forceinline void D014F0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    D014F0MonitorStream& mStream = D014F0GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        D014F0TimerCommand* h = (D014F0TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D014F0World;

struct D014F0Listener
{
    virtual void unk00();
    virtual void collisionAddedCallback(D014F0World* pkWorld, void* pvEvent);
};

struct D014F0ListenerArray
{
    D014F0Listener** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D014F0CleanupNullPointers(D014F0ListenerArray& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D014F0TickPair
{
    volatile unsigned int m_uiBegin;
    volatile unsigned int m_uiEndTick;
};

struct D014F0World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    D014F0ListenerArray m_kEntityListenerArray;
};

extern const char g_D014F0TimerCollisionAddedCb[];
extern const char g_D014F0TimerEnd[];

// Iterates the world's entity listener array, invoking collisionAddedCallback on each non-null listener with timing markers, then removes null entries.
// @fnv 0x00d014f0
void __cdecl FUN_00d014f0(D014F0World* world, void* pvEvent)
{
    D014F0TickPair kTicks;
    D014F0ListenerArray& listeners = world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            D014F0TimerBegin(g_D014F0TimerCollisionAddedCb, kTicks.m_uiBegin);
            listeners.m_data[i]->collisionAddedCallback(world, pvEvent);
            D014F0TimerBegin(g_D014F0TimerEnd, kTicks.m_uiEndTick);
        }
    }
    D014F0CleanupNullPointers(listeners);
}

struct D015A0TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D015A0MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

extern DWORD g_D015A0TlsIndex;

__forceinline D015A0MonitorStream& D015A0GetMonitorStream()
{
    return *(D015A0MonitorStream*)TlsGetValue(g_D015A0TlsIndex);
}

__forceinline void D015A0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    D015A0MonitorStream& mStream = D015A0GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        D015A0TimerCommand* h = (D015A0TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D015A0Listener
{
    virtual void unk00();
    virtual void contactCallback(void* pkCurrentObject, void* pkSecond);
};

struct D015A0ListenerArray
{
    D015A0Listener** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D015A0CleanupNullPointers(D015A0ListenerArray& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D015A0World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    D015A0ListenerArray m_kContactListeners;
};

extern const char g_D015A0TimerContactCb[];
extern const char g_D015A0TimerEnd[];

// Invokes contactCallback on each non-null listener in world->m_kContactListeners, then removes null entries from the array.
// @fnv 0x00d015a0
void __cdecl FUN_00d015a0(D015A0World* world, void* apFirst, void* pkSecond)
{
    D015A0ListenerArray& listeners = world->m_kContactListeners;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D015A0TimerBegin(g_D015A0TimerContactCb, beginTicks);
            listeners.m_data[i]->contactCallback(apFirst, pkSecond);
            D015A0TimerBegin(g_D015A0TimerEnd, endTicks);
        }
    }
    D015A0CleanupNullPointers(listeners);
}

struct D01650TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D01650MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

extern DWORD g_D01650TlsIndex;

__forceinline D01650MonitorStream& D01650GetMonitorStream()
{
    return *(D01650MonitorStream*)TlsGetValue(g_D01650TlsIndex);
}

__forceinline void D01650TimerBegin(const char* name, volatile unsigned int& ticks)
{
    D01650MonitorStream& mStream = D01650GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        D01650TimerCommand* h = (D01650TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D01650Listener
{
    virtual void unk00();
    virtual void collisionAddedCallback(void* pvEvent, void* pvContext);
};

struct D01650ListenerArray
{
    D01650Listener** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D01650CleanupNullPointers(D01650ListenerArray& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D01650World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    D01650ListenerArray m_kEntityListenerArray;
};

extern const char g_D01650TimerCollisionAddedCb[];
extern const char g_D01650TimerEnd[];

// Invokes collisionAddedCallback on each non-null listener in the array, then removes null entries.
// @fnv 0x00d01650
void __cdecl FUN_00d01650(D01650World* world, void* pvEvent, void* pvContext)
{
    D01650ListenerArray& listeners = world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D01650TimerBegin(g_D01650TimerCollisionAddedCb, beginTicks);
            listeners.m_data[i]->collisionAddedCallback(pvEvent, pvContext);
            D01650TimerBegin(g_D01650TimerEnd, endTicks);
        }
    }
    D01650CleanupNullPointers(listeners);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;

struct Listener
{
    virtual void vfunc0();
    virtual void vfunc1(void* a1, void* a2);
};

struct ListenerArray
{
    Listener** m_data;
    int m_iElementCount;
    int m_pRayCursor;
};

struct hkpWorld
{
    char pad[0x1ac];
    ListenerArray m_kListeners;
};

struct StringCursor
{
    char* m_kRayStart;
    char* m_pTileTemplate;
    char* m_kRayEnd;
    char* m_pRayCursor;
};

__declspec(noinline) static void FUN_00d00370(ListenerArray* arr)
{
    for (int i = arr->m_iElementCount - 1; i >= 0; --i)
    {
        if (!arr->m_data[i])
        {
            arr->m_iElementCount--;
            int count = arr->m_iElementCount - i;
            if (count > 0)
            {
                memmove(&arr->m_data[i], &arr->m_data[i + 1], count * sizeof(Listener*));
            }
        }
    }
}

static __forceinline void writeTimestamp(char* cur, const char* tag, volatile unsigned int& t)
{
    *(const char**)cur = tag;
    _ReadWriteBarrier();
    t = (unsigned int)__rdtsc();
    *(unsigned int*)(cur + 4) = t;
}

// Iterates hkpWorld listener array, writes start/end timestamps to TLS buffer, invokes each listener, then compacts the array.
// @fnv 0x00d01700
void __cdecl FUN_00d01700(hkpWorld* world, void* a1, void* a2)
{
    volatile unsigned int uiStartTsc;
    volatile unsigned int t1;
    ListenerArray* arr = &world->m_kListeners;
    for (int i = arr->m_iElementCount - 1; i >= 0; --i)
    {
        if (arr->m_data[i])
        {
            StringCursor* ms = (StringCursor*)TlsGetValue(DAT_0126835c);
            char* cur = ms->m_pTileTemplate;
            if (cur < ms->m_pRayCursor)
            {
                writeTimestamp(cur, "TtimpLimitCb", uiStartTsc);
                ms->m_pTileTemplate = cur + 12;
            }
            arr->m_data[i]->vfunc1(a1, a2);
            ms = (StringCursor*)TlsGetValue(DAT_0126835c);
            cur = ms->m_pTileTemplate;
            if (cur < ms->m_pRayCursor)
            {
                writeTimestamp(cur, "Et", t1);
                ms->m_pTileTemplate = cur + 12;
            }
        }
    }
    FUN_00d00370(arr);
}

struct D017B0TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D017B0MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

extern DWORD g_D017B0TlsIndex;

__forceinline D017B0MonitorStream& D017B0GetMonitorStream()
{
    return *(D017B0MonitorStream*)TlsGetValue(g_D017B0TlsIndex);
}

__forceinline void D017B0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    D017B0MonitorStream& mStream = D017B0GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        D017B0TimerCommand* h = (D017B0TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D017B0Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void EntityRemovedCallback(void* entity);
};

struct D017B0ListenerArray
{
    D017B0Listener** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D017B0CleanupNullPointers(D017B0ListenerArray& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D017B0World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    D017B0ListenerArray m_kEntityListenerArray;
};

extern const char g_D017B0TimerEntityRemovedCb[];
extern const char g_D017B0TimerEnd[];

// Invokes EntityRemovedCallback on each non-null listener in the world's entity listener array, then removes null entries.
// @fnv 0x00d017b0
void __cdecl NotifyEntityRemoved(D017B0World* world, void* entity)
{
    D017B0ListenerArray& listeners = world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D017B0TimerBegin(g_D017B0TimerEntityRemovedCb, beginTicks);
            listeners.m_data[i]->EntityRemovedCallback(entity);
            D017B0TimerBegin(g_D017B0TimerEnd, endTicks);
        }
    }
    D017B0CleanupNullPointers(listeners);
}

struct D019B0TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D019B0MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

extern DWORD g_D019B0TlsIndex;

__forceinline D019B0MonitorStream& D019B0GetMonitorStream()
{
    return *(D019B0MonitorStream*)TlsGetValue(g_D019B0TlsIndex);
}

__forceinline void D019B0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    D019B0MonitorStream& mStream = D019B0GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        D019B0TimerCommand* h = (D019B0TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D019B0Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void shapeSetCallback(void* entity);
};

struct D019B0ListenerArray
{
    D019B0Listener** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D019B0CleanupNullPointers(D019B0ListenerArray& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D019B0World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    D019B0ListenerArray m_kEntityListenerArray;
};

extern const char g_D019B0TimerSetShapeCb[];
extern const char g_D019B0TimerEnd[];

struct D019B0Event
{
    int unk00;
    int unk04;
    int m_result;
};

// Invokes shapeSetCallback on each non-null entity listener in the world's listener array, then removes any null entries.
// @fnv 0x00d019b0
void __cdecl NotifyShapeSetListeners(D019B0World* world, D019B0Event* event)
{
    event->m_result = 0;
    D019B0ListenerArray& listeners = world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D019B0TimerBegin(g_D019B0TimerSetShapeCb, beginTicks);
            listeners.m_data[i]->shapeSetCallback(event);
            D019B0TimerBegin(g_D019B0TimerEnd, endTicks);
        }
    }
    D019B0CleanupNullPointers(listeners);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern char DAT_010cca74[];
extern char DAT_010c41f8[];
struct TimerEntry
{
    const char* m_name;
    unsigned int m_uiCommandId;
    unsigned int m_08;
};
struct MonitorStream
{
    int m_00;
    char* m_cur;
    int m_08;
    char* m_kRayEnd;
};
static inline void TimerWriteV(const char* name, volatile unsigned int& t)
{
    MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_cur < s->m_kRayEnd)
    {
        TimerEntry* h = (TimerEntry*)s->m_cur;
        h->m_name = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        h->m_uiCommandId = t;
        s->m_cur = (char*)(h + 1);
    }
}
struct ActionListener
{
    virtual void v00();
    virtual void v04();
    virtual void ActionRemovedCallback(void* action);
};
struct WorldA
{
    int m_000, m_004, m_008, m_00c, m_010, m_014, m_018, m_01c;
    int m_020, m_024, m_028, m_02c, m_030, m_034, m_038, m_03c;
    int m_040, m_044, m_048, m_04c, m_050, m_054, m_058, m_05c;
    int m_060, m_064, m_068, m_06c, m_070, m_074, m_078, m_07c;
    int m_080, m_084, m_088, m_08c, m_090, m_094, m_098, m_09c;
    int m_0a0, m_0a4, m_0a8, m_0ac, m_0b0, m_0b4, m_0b8, m_0bc;
    int m_0c0, m_0c4, m_0c8, m_0cc, m_0d0, m_0d4, m_0d8, m_0dc;
    int m_0e0, m_0e4, m_0e8, m_0ec, m_0f0, m_0f4, m_0f8, m_0fc;
    int m_100, m_104, m_108, m_10c, m_110, m_114, m_118;
    D00370Array m_kActionListeners;
};
// Iterates world->m_kActionListeners in reverse, calling ActionRemovedCallback on each non-null listener, then calls FUN_00d00370 on the array.
// @fnv 0x00d00460
void __cdecl NotifyActionRemoved(WorldA* world, void* action)
{
    D00370Array& listen = world->m_kActionListeners;
    for (int i = listen.m_iElementCount - 1; i >= 0; i--)
    {
        if (listen.m_data[i] != 0)
        {
            volatile unsigned int t1;
            volatile unsigned int t2;
            TimerWriteV(DAT_010cca74, t1);
            ((ActionListener*)listen.m_data[i])->ActionRemovedCallback(action);
            TimerWriteV(DAT_010c41f8, t2);
        }
    }
    FUN_00d00370(listen);
}

struct D005A0TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D005A0MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

extern DWORD g_D005A0TlsIndex;

__forceinline D005A0MonitorStream& D005A0GetMonitorStream()
{
    return *(D005A0MonitorStream*)TlsGetValue(g_D005A0TlsIndex);
}

__forceinline void D005A0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    D005A0MonitorStream& mStream = D005A0GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        D005A0TimerCommand* h = (D005A0TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D005A0Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void EntityRemovedCallback(void* entity);
};

struct D005A0ListenerArray
{
    D005A0Listener** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D005A0CleanupNullPointers(D005A0ListenerArray& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D005A0World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    D005A0ListenerArray m_kEntityListenerArray;
};

extern const char g_D005A0TimerEntityAddedCb[];
extern const char g_D005A0TimerEnd[];

// Iterates the world's entity listener array, calling EntityRemovedCallback on each non-null listener, then removes null entries.
// @fnv 0x00d005a0
void __cdecl FUN_00d005a0(D005A0World* world, void* entity)
{
    D005A0ListenerArray& listeners = world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D005A0TimerBegin(g_D005A0TimerEntityAddedCb, beginTicks);
            listeners.m_data[i]->EntityRemovedCallback(entity);
            D005A0TimerBegin(g_D005A0TimerEnd, endTicks);
        }
    }
    D005A0CleanupNullPointers(listeners);
}

struct D00640TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D00640MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

extern DWORD g_D00640TlsIndex;

__forceinline D00640MonitorStream& D00640GetMonitorStream()
{
    return *(D00640MonitorStream*)TlsGetValue(g_D00640TlsIndex);
}

__forceinline void D00640TimerBegin(const char* name, volatile unsigned int& ticks)
{
    D00640MonitorStream& mStream = D00640GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        D00640TimerCommand* h = (D00640TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D00640Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void shapeSetCallback(void* entity);
};

struct D00640ListenerArray
{
    D00640Listener** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D00640CleanupNullPointers(D00640ListenerArray& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D00640World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    D00640ListenerArray m_kEntityListenerArray;
};

extern const char g_D00640TimerSetShapeCb[];
extern const char g_D00640TimerEnd[];

// Iterates the entity listener array, calls shapeSetCallback on each non-null listener, then compacts out null entries.
// @fnv 0x00d00640
void __cdecl NotifyShapeSet(D00640World* world, void* entity)
{
    D00640ListenerArray& listeners = world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D00640TimerBegin(g_D00640TimerSetShapeCb, beginTicks);
            listeners.m_data[i]->shapeSetCallback(entity);
            D00640TimerBegin(g_D00640TimerEnd, endTicks);
        }
    }
    D00640CleanupNullPointers(listeners);
}

struct D00820TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D00820MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

extern DWORD g_D00820TlsIndex;

__forceinline D00820MonitorStream& D00820GetMonitorStream()
{
    return *(D00820MonitorStream*)TlsGetValue(g_D00820TlsIndex);
}

__forceinline void D00820TimerBegin(const char* name, volatile unsigned int& ticks)
{
    D00820MonitorStream& mStream = D00820GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        D00820TimerCommand* h = (D00820TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D00820Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void entityCallback(void* entity);
};

struct D00820ListenerArray
{
    D00820Listener** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D00820CleanupNullPointers(D00820ListenerArray& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D00820World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    D00820ListenerArray m_kEntityListenerArray;
};

extern const char g_D00820TimerSetShapeCb[];
extern const char g_D00820TimerEnd[];

// Iterates the world's entity listener array, calls entityCallback on each non-null listener with the entity, then removes null entries.
// @fnv 0x00d00820
void __cdecl FUN_00d00820(D00820World* world, void* entity)
{
    D00820ListenerArray& listeners = world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D00820TimerBegin(g_D00820TimerSetShapeCb, beginTicks);
            listeners.m_data[i]->entityCallback(entity);
            D00820TimerBegin(g_D00820TimerEnd, endTicks);
        }
    }
    D00820CleanupNullPointers(listeners);
}

struct D008C0TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;

    __forceinline void setTime(volatile unsigned int& ticks)
    {
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        m_uiStartTicks = ticks;
    }
};

struct D008C0MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;

    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

extern DWORD g_D008C0TlsIndex;

__forceinline D008C0MonitorStream& D008C0GetMonitorStream()
{
    return *(D008C0MonitorStream*)TlsGetValue(g_D008C0TlsIndex);
}

__forceinline void D008C0TimerBegin(const char* name, volatile unsigned int& ticks)
{
    D008C0MonitorStream& mStream = D008C0GetMonitorStream();
    if (mStream.memoryAvailable())
    {
        D008C0TimerCommand* h = (D008C0TimerCommand*)mStream.m_kRayEnd;
        h->m_pCommandName = name;
        h->setTime(ticks);
        mStream.m_kRayEnd = (char*)(h + 1);
    }
}

struct D008C0Listener
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void shapeSetCallback(void* entity);
};

struct D008C0ListenerArray
{
    D008C0Listener** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// array to it in a register, which is what the target's codegen depends on.
static __declspec(noinline) void D008C0CleanupNullPointers(D008C0ListenerArray& listeners)
{
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] == 0)
        {
            listeners.m_iElementCount--;
            int* dst = (int*)&listeners.m_data[i];
            int* src = dst + 1;
            for (int n = (listeners.m_iElementCount - i) * 4; n > 0; n -= 4)
                *dst++ = *src++;
        }
    }
}

struct D008C0World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    D008C0ListenerArray m_kEntityListenerArray;
};

extern const char g_D008C0TimerSetShapeCb[];
extern const char g_D008C0TimerEnd[];

// Iterates the world's entity listener array in reverse, invoking shapeSetCallback on each non-null listener, then compacts the array to remove null entries.
// @fnv 0x00d008c0
void __cdecl FUN_00d008c0(D008C0World* world, void* entity)
{
    D008C0ListenerArray& listeners = world->m_kEntityListenerArray;
    for (int i = listeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (listeners.m_data[i] != 0)
        {
            volatile unsigned int beginTicks;
            volatile unsigned int endTicks;
            D008C0TimerBegin(g_D008C0TimerSetShapeCb, beginTicks);
            listeners.m_data[i]->shapeSetCallback(entity);
            D008C0TimerBegin(g_D008C0TimerEnd, endTicks);
        }
    }
    D008C0CleanupNullPointers(listeners);
}

extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
unsigned __int64 __cdecl __rdtsc(void);
struct ProfRec
{
    const char* name;
    unsigned tick;
    unsigned unk08;
};
struct ProfBuf
{
    unsigned unk00;
    ProfRec* cur;
    unsigned unk08;
    ProfRec* end;
};
class ProfTarget
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(unsigned a1);
    virtual void v3();
    virtual void v4();
};
struct ProfOwner
{
    unsigned unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C, unk030,
        unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C, unk060, unk064, unk068,
        unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C, unk0A0,
        unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8,
        unk0DC, unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110,
        unk114, unk118, unk11C, unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    D00370Array m_kTargets;
};
__forceinline void ProfMark(const char* name, volatile DWORD& outTick)
{
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->cur < pBuf->end)
    {
        ProfRec* pRec = pBuf->cur;
        pRec->name = name;
        _ReadWriteBarrier();
        outTick = (DWORD)__rdtsc();
        pRec->tick = outTick;
        pBuf->cur = pRec + 1;
    }
}
// Iterates m_kTargets in reverse, calling v2 on each non-null ProfTarget with a2, then calls FUN_00d00370 on the array.
// @fnv 0x00d00a00
void __cdecl NotifyTargets(ProfOwner* pOwner, DWORD a2)
{
    volatile DWORD beginTick, endTick;
    D00370Array& targets = pOwner->m_kTargets;
    int i = (int)targets.m_iElementCount - 1;
    if (i >= 0)
    {
        do
        {
            if (((ProfTarget**)targets.m_data)[i] != 0)
            {
                ProfMark("TtconRemCb", beginTick);
                ((ProfTarget**)targets.m_data)[i]->v2(a2);
                ProfMark("Et", endTick);
            }
        } while (--i >= 0);
    }
    FUN_00d00370(targets);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern char DAT_010ccab0[];
extern char DAT_010c41f8[];
struct Phantom
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(int a);
};
struct OwnerD
{
    int m_000, m_004, m_008, m_00c, m_010, m_014, m_018, m_01c;
    int m_020, m_024, m_028, m_02c, m_030, m_034, m_038, m_03c;
    int m_040, m_044, m_048, m_04c, m_050, m_054, m_058, m_05c;
    int m_060, m_064, m_068, m_06c, m_070, m_074, m_078, m_07c;
    int m_080, m_084, m_088, m_08c, m_090, m_094, m_098, m_09c;
    int m_0a0, m_0a4, m_0a8, m_0ac, m_0b0, m_0b4, m_0b8, m_0bc;
    int m_0c0, m_0c4, m_0c8, m_0cc, m_0d0, m_0d4, m_0d8, m_0dc;
    int m_0e0, m_0e4, m_0e8, m_0ec, m_0f0, m_0f4, m_0f8, m_0fc;
    int m_100, m_104, m_108, m_10c, m_110, m_114, m_118, m_11c;
    int m_120, m_124, m_128, m_12c, m_130, m_134, m_138, m_13c;
    D00370Array m_kListeners;
};
// Iterates owner's m_kListeners in reverse, calling v10 with a2 on each non-null listener between timer samples, then calls FUN_00d00370 on the array.
// @fnv 0x00d00aa0
void __cdecl FUN_00d00aa0(OwnerD* owner, int a2)
{
    D00370Array& listen = owner->m_kListeners;
    for (int i = listen.m_iElementCount - 1; i >= 0; i--)
    {
        if (listen.m_data[i] != 0)
        {
            volatile unsigned int t1;
            volatile unsigned int t2;
            TimerWriteV(DAT_010ccab0, t1);
            ((Phantom*)listen.m_data[i])->v10(a2);
            TimerWriteV(DAT_010c41f8, t2);
        }
    }
    FUN_00d00370(listen);
}

extern "C" void _ReadWriteBarrier(void);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned long DAT_0126835c;
extern "C" char str_010ccaf8;
extern "C" char str_010ccaec;
extern "C" char str_010c41f8;
struct Scene;
struct Entity;
struct Callback
{
    virtual void unused();
    virtual void invoke(Scene*);
    virtual void execute(Entity*);
};
struct CallbackList
{
    Callback** slots;
    unsigned short count;
};
struct Game
{
    unsigned int unk00;
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int field8c;
    unsigned int field90;
    int field94;
    unsigned int unk98;
    unsigned char field9c;
    unsigned int unka0;
    unsigned int fielda4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    D00370Array field158;
    void FUN_00c91120();
    void FUN_00c91140();
};
struct Entity
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    CallbackList* field214;
};
struct Scene
{
    unsigned int unk00;
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    Entity** field48;
    int field4c;
};
struct LogBuffer
{
    int ReportDiagnostic;
    unsigned int* current;
    int unused8;
    unsigned int* limit;
};
static __declspec(noinline) void RemoveZeroEntries(CallbackList* list)
{
    for (int i = (int)list->count - 1; i >= 0; --i)
    {
        if (!list->slots[i])
        {
            list->count--;
            for (int k = i; k < (int)list->count; ++k)
            {
                list->slots[k] = list->slots[k + 1];
            }
        }
    }
}
// Calls game->field158 callbacks with scene, then each scene entity's callbacks, bracketed by a field94 inc/dec; at zero may call FUN_00c91120 or FUN_00c91140.
// @fnv 0x00d00fe0
void __cdecl ProcessSceneCallbacks(Game* game, Scene* scene)
{
    struct
    {
        volatile unsigned int tick1;
        volatile unsigned int tick2;
    } timer;
    ++game->field94;
    _ReadWriteBarrier();
    int i = game->field158.m_iElementCount - 1;
    D00370Array* pSlots = &game->field158;
    for (; i >= 0; --i)
    {
        if (pSlots->m_data[i])
        {
            {
                LogBuffer* log = (LogBuffer*)TlsGetValue(DAT_0126835c);
                unsigned int* current = log->current;
                if (current < log->limit)
                {
                    current[0] = (unsigned int)&str_010ccaf8;
                    _ReadWriteBarrier();
                    timer.tick1 = (unsigned int)__rdtsc();
                    current[1] = timer.tick1;
                    log->current = current + 3;
                }
            }
            ((Callback*)pSlots->m_data[i])->invoke(scene);
            {
                LogBuffer* log = (LogBuffer*)TlsGetValue(DAT_0126835c);
                unsigned int* current = log->current;
                if (current < log->limit)
                {
                    current[0] = (unsigned int)&str_010c41f8;
                    _ReadWriteBarrier();
                    timer.tick2 = (unsigned int)__rdtsc();
                    current[1] = timer.tick2;
                    log->current = current + 3;
                }
            }
        }
    }
    FUN_00d00370(*pSlots);
    for (int i = 0; i < scene->field4c; ++i)
    {
        Entity* ent = scene->field48[i];
        if (ent->field214)
        {
            CallbackList* callbacks = ent->field214;
            for (int j = (int)callbacks->count - 1; j >= 0; --j)
            {
                if (callbacks->slots[j])
                {
                    {
                        LogBuffer* log = (LogBuffer*)TlsGetValue(DAT_0126835c);
                        unsigned int* current = log->current;
                        if (current < log->limit)
                        {
                            current[0] = (unsigned int)&str_010ccaec;
                            _ReadWriteBarrier();
                            timer.tick2 = (unsigned int)__rdtsc();
                            current[1] = timer.tick2;
                            log->current = current + 3;
                        }
                    }
                    callbacks->slots[j]->execute(scene->field48[i]);
                    {
                        LogBuffer* log = (LogBuffer*)TlsGetValue(DAT_0126835c);
                        unsigned int* current = log->current;
                        if (current < log->limit)
                        {
                            current[0] = (unsigned int)&str_010c41f8;
                            _ReadWriteBarrier();
                            timer.tick1 = (unsigned int)__rdtsc();
                            current[1] = timer.tick1;
                            log->current = current + 3;
                        }
                    }
                }
            }
            RemoveZeroEntries(callbacks);
        }
    }
    if (--game->field94 == 0 && !game->field9c)
    {
        if (game->field8c)
            game->FUN_00c91120();
        if (game->fielda4 == 1 && game->field90)
            game->FUN_00c91140();
    }
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern char DAT_010cca50[];
extern char DAT_010c41f8[];
struct ContactListener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void HandleContactEvent(void* event);
};
struct RemovedEvent
{
    int m_00, m_04, m_08, m_0c;
    void* m_iUnknownValue;
};
struct WorldD
{
    int m_000, m_004, m_008, m_00c, m_010, m_014, m_018, m_01c;
    int m_020, m_024, m_028, m_02c, m_030, m_034, m_038, m_03c;
    int m_040, m_044, m_048, m_04c, m_050, m_054, m_058, m_05c;
    int m_060, m_064, m_068, m_06c, m_070, m_074, m_078, m_07c;
    int m_080, m_084, m_088, m_08c, m_090, m_094, m_098, m_09c;
    int m_0a0, m_0a4, m_0a8, m_0ac, m_0b0, m_0b4, m_0b8, m_0bc;
    int m_0c0, m_0c4, m_0c8, m_0cc, m_0d0, m_0d4, m_0d8, m_0dc;
    int m_0e0, m_0e4, m_0e8, m_0ec, m_0f0, m_0f4, m_0f8, m_0fc;
    int m_100, m_104, m_108, m_10c, m_110, m_114, m_118, m_11c;
    int m_120, m_124, m_128, m_12c, m_130, m_134, m_138, m_13c;
    int m_140, m_144, m_148, m_14c, m_150, m_154, m_158, m_15c;
    int m_160, m_164, m_168, m_16c, m_170, m_174, m_178, m_17c;
    int m_180, m_184, m_188, m_18c, m_190, m_194, m_198, m_19c;
    D00370Array m_kContactListeners;
};
// Iterates world->m_kContactListeners in reverse, calling HandleContactEvent(&event) on each non-null listener between timer samples, then calls FUN_00d00370.
// @fnv 0x00d01900
void __cdecl FUN_00d01900(WorldD* world, RemovedEvent& event)
{
    D00370Array& listen = world->m_kContactListeners;
    event.m_iUnknownValue = 0;
    for (int i = listen.m_iElementCount - 1; i >= 0; i--)
    {
        if (listen.m_data[i] != 0)
        {
            volatile unsigned int t1;
            volatile unsigned int t2;
            TimerWriteV(DAT_010cca50, t1);
            ((ContactListener*)listen.m_data[i])->HandleContactEvent(&event);
            TimerWriteV(DAT_010c41f8, t2);
        }
    }
    FUN_00d00370(listen);
}

extern void*(__stdcall* DAT_00fdf044)(unsigned long);
struct ProfRecQ
{
    const char* m_pName;
    unsigned long m_iTick;
    unsigned long unk08;
};
struct ProfBufQ
{
    unsigned long unk00;
    ProfRecQ* m_pCur;
    unsigned long unk08;
    ProfRecQ* m_pRecordEnd;
};
class ListenerObjQ
{
  public:
    virtual void v00(void);
    virtual void v01(void);
    virtual void v02(void);
    virtual void v03(void);
    virtual void v04(void);
    virtual void v05(unsigned long a1);
};
struct ListenerArrayQ
{
    ListenerObjQ** m_ppItems;
    unsigned long m_uiItemCount;
};
struct ListenerOwnerQ
{
    unsigned long unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned long unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned long unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    unsigned long unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    unsigned long unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned long unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    unsigned long unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    unsigned long unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    unsigned long unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    unsigned long unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C;
    ListenerArrayQ m_kListeners;
};
// Iterates pOwner's listener array, profiling each call to v05(a2), then calls FUN_00d00370 on the array.
// @fnv 0x00d00b40
void __cdecl FUN_00d00b40(ListenerOwnerQ* pOwner, unsigned long a2)
{
    volatile unsigned long tick1;
    struct ProfileState
    {
        volatile unsigned long tick;
        ListenerArrayQ* arr;
    };
    ProfileState state;
    state.arr = &pOwner->m_kListeners;
    int i = (int)state.arr->m_uiItemCount - 1;
    if (i >= 0)
    {
        void*(__stdcall * getBuf)(unsigned long) = DAT_00fdf044;
        do
        {
            ListenerObjQ* pItem = state.arr->m_ppItems[i];
            if (pItem != 0)
            {
                ProfBufQ* pBuf = (ProfBufQ*)getBuf(DAT_0126835c);
                if (pBuf->m_pCur < pBuf->m_pRecordEnd)
                {
                    ProfRecQ* pRec = pBuf->m_pCur;
                    pRec->m_pName = "TtconBrokenCb";
                    _ReadWriteBarrier();
                    tick1 = (unsigned long)__rdtsc();
                    pRec->m_iTick = tick1;
                    pBuf->m_pCur = pRec + 1;
                }

                pItem->v05(a2);

                pBuf = (ProfBufQ*)getBuf(DAT_0126835c);
                if (pBuf->m_pCur < pBuf->m_pRecordEnd)
                {
                    ProfRecQ* pRec = pBuf->m_pCur;
                    pRec->m_pName = "Et";
                    _ReadWriteBarrier();
                    state.tick = (unsigned long)__rdtsc();
                    pRec->m_iTick = state.tick;
                    pBuf->m_pCur = pRec + 1;
                }
            }
            i--;
        } while (i >= 0);
    }
    FUN_00d00370(*(D00370Array*)state.arr);
}

// Based on an unverified 2026-10-22 contribution.
extern "C" void _ReadWriteBarrier(void);
extern DWORD DAT_0126835c;
extern LPVOID(WINAPI* DAT_00fdf044)(DWORD);
unsigned __int64 __cdecl __rdtsc(void);
struct S00d01850_Out
{
    int unk00, unk04, unk08;
    DWORD unk0C;
    DWORD m_i10;
};
class S00d01850_Item
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vtbl10(S00d01850_Out*);
    virtual void v5();
};
struct S00d01850_ItemList
{
    S00d01850_Item** m_ppItems;
    int m_iArrayLength;
};
struct S00d01850_Owner
{
    unsigned unk000;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    unsigned unk138;
    unsigned unk13c;
    unsigned unk140;
    unsigned unk144;
    unsigned unk148;
    unsigned unk14c;
    unsigned unk150;
    unsigned unk154;
    unsigned unk158;
    unsigned unk15c;
    unsigned unk160;
    unsigned unk164;
    unsigned unk168;
    unsigned unk16c;
    unsigned unk170;
    unsigned unk174;
    unsigned unk178;
    unsigned unk17c;
    unsigned unk180;
    unsigned unk184;
    unsigned unk188;
    unsigned unk18c;
    unsigned unk190;
    unsigned unk194;
    unsigned unk198;
    unsigned unk19c;
    D00370Array m_kNode;
};
// Zeroes pOut->unk0C, calls vtbl10(pOut) on each non-null list item from the end with profiler records, then calls FUN_00d00370 on the list.
// @fnv 0x00d01850
void __cdecl FUN_00d01850(S00d01850_Owner* pOwner, S00d01850_Out* pOut)
{
    volatile DWORD t1;
    volatile DWORD t2;
    volatile DWORD& rT2 = t2;
    D00370Array* pCallbacks = &pOwner->m_kNode;
    pOut->unk0C = 0;
    int i = pCallbacks->m_iElementCount - 1;
    if (i >= 0)
    {
        LPVOID(WINAPI * pfnTls)(DWORD) = DAT_00fdf044;
        for (; i >= 0; --i)
        {
            if (pCallbacks->m_data[i] != 0)
            {
                ProfBuf* pBuf = (ProfBuf*)pfnTls(DAT_0126835c);
                if (pBuf->cur < pBuf->end)
                {
                    ProfRec* pRec = pBuf->cur;
                    pRec->name = "TtcpAddCb";
                    _ReadWriteBarrier();
                    t1 = (DWORD)__rdtsc();
                    pRec->tick = t1;
                    pBuf->cur = pRec + 1;
                }
                ((S00d01850_Item*)pCallbacks->m_data[i])->vtbl10(pOut);
                ProfBuf* pBuf2 = (ProfBuf*)pfnTls(DAT_0126835c);
                if (pBuf2->cur < pBuf2->end)
                {
                    ProfRec* pRec2 = pBuf2->cur;
                    pRec2->name = "Et";
                    _ReadWriteBarrier();
                    rT2 = (DWORD)__rdtsc();
                    pRec2->tick = rT2;
                    pBuf2->cur = pRec2 + 1;
                }
            }
        }
    }
    FUN_00d00370(*pCallbacks);
}

#include <windows.h>

extern DWORD DAT_0126835c;
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern const char str_010ccb10[];
extern const char str_010ccb04[];

struct S011b0_Rec
{
    const char* m_pTag;
    DWORD m_dwTime;
    DWORD unk08;
};

struct S011b0_Buf
{
    DWORD unk00;
    S011b0_Rec* m_pCurrent;
    DWORD unk08;
    S011b0_Rec* m_pRecordEnd;
};

struct S011b0_Listener
{
    virtual void v00();
    virtual void v04(void* p);
    virtual void v08(void* p);
};

struct S011b0_Ext
{
    FNV_SmallArray_00d00320 m_kContactListenerArray;
};

struct S011b0_Entity
{
    DWORD unk0000;
    DWORD unk0004;
    DWORD unk0008;
    DWORD unk000C;
    DWORD unk0010;
    DWORD unk0014;
    DWORD unk0018;
    DWORD unk001C;
    DWORD unk0020;
    DWORD unk0024;
    DWORD unk0028;
    DWORD unk002C;
    DWORD unk0030;
    DWORD unk0034;
    DWORD unk0038;
    DWORD unk003C;
    DWORD unk0040;
    DWORD unk0044;
    DWORD unk0048;
    DWORD unk004C;
    DWORD unk0050;
    DWORD unk0054;
    DWORD unk0058;
    DWORD unk005C;
    DWORD unk0060;
    DWORD unk0064;
    DWORD unk0068;
    DWORD unk006C;
    DWORD unk0070;
    DWORD unk0074;
    DWORD unk0078;
    DWORD unk007C;
    DWORD unk0080;
    DWORD unk0084;
    DWORD unk0088;
    DWORD unk008C;
    DWORD unk0090;
    DWORD unk0094;
    DWORD unk0098;
    DWORD unk009C;
    DWORD unk00A0;
    DWORD unk00A4;
    DWORD unk00A8;
    DWORD unk00AC;
    DWORD unk00B0;
    DWORD unk00B4;
    DWORD unk00B8;
    DWORD unk00BC;
    DWORD unk00C0;
    DWORD unk00C4;
    DWORD unk00C8;
    DWORD unk00CC;
    DWORD unk00D0;
    DWORD unk00D4;
    DWORD unk00D8;
    DWORD unk00DC;
    DWORD unk00E0;
    DWORD unk00E4;
    DWORD unk00E8;
    DWORD unk00EC;
    DWORD unk00F0;
    DWORD unk00F4;
    DWORD unk00F8;
    DWORD unk00FC;
    DWORD unk0100;
    DWORD unk0104;
    DWORD unk0108;
    DWORD unk010C;
    DWORD unk0110;
    DWORD unk0114;
    DWORD unk0118;
    DWORD unk011C;
    DWORD unk0120;
    DWORD unk0124;
    DWORD unk0128;
    DWORD unk012C;
    DWORD unk0130;
    DWORD unk0134;
    DWORD unk0138;
    DWORD unk013C;
    DWORD unk0140;
    DWORD unk0144;
    DWORD unk0148;
    DWORD unk014C;
    DWORD unk0150;
    DWORD unk0154;
    DWORD unk0158;
    DWORD unk015C;
    DWORD unk0160;
    DWORD unk0164;
    DWORD unk0168;
    DWORD unk016C;
    DWORD unk0170;
    DWORD unk0174;
    DWORD unk0178;
    DWORD unk017C;
    DWORD unk0180;
    DWORD unk0184;
    DWORD unk0188;
    DWORD unk018C;
    DWORD unk0190;
    DWORD unk0194;
    DWORD unk0198;
    DWORD unk019C;
    DWORD unk01A0;
    DWORD unk01A4;
    DWORD unk01A8;
    DWORD unk01AC;
    DWORD unk01B0;
    DWORD unk01B4;
    DWORD unk01B8;
    DWORD unk01BC;
    DWORD unk01C0;
    DWORD unk01C4;
    DWORD unk01C8;
    DWORD unk01CC;
    DWORD unk01D0;
    DWORD unk01D4;
    DWORD unk01D8;
    DWORD unk01DC;
    DWORD unk01E0;
    DWORD unk01E4;
    DWORD unk01E8;
    DWORD unk01EC;
    DWORD unk01F0;
    DWORD unk01F4;
    DWORD unk01F8;
    DWORD unk01FC;
    DWORD unk0200;
    DWORD unk0204;
    DWORD unk0208;
    DWORD unk020C;
    DWORD unk0210;
    S011b0_Ext* m_pSub;
};

struct S011b0_Island
{
    DWORD unk0000;
    DWORD unk0004;
    DWORD unk0008;
    DWORD unk000C;
    DWORD unk0010;
    DWORD unk0014;
    DWORD unk0018;
    DWORD unk001C;
    DWORD unk0020;
    DWORD unk0024;
    DWORD unk0028;
    DWORD unk002C;
    DWORD unk0030;
    DWORD unk0034;
    DWORD unk0038;
    DWORD unk003C;
    DWORD unk0040;
    DWORD unk0044;
    S011b0_Entity** m_ppEnts;
    int m_nEnts;
};

struct S011b0_World
{
    DWORD unk0000;
    DWORD unk0004;
    DWORD unk0008;
    DWORD unk000C;
    DWORD unk0010;
    DWORD unk0014;
    DWORD unk0018;
    DWORD unk001C;
    DWORD unk0020;
    DWORD unk0024;
    DWORD unk0028;
    DWORD unk002C;
    DWORD unk0030;
    DWORD unk0034;
    DWORD unk0038;
    DWORD unk003C;
    DWORD unk0040;
    DWORD unk0044;
    DWORD unk0048;
    DWORD unk004C;
    DWORD unk0050;
    DWORD unk0054;
    DWORD unk0058;
    DWORD unk005C;
    DWORD unk0060;
    DWORD unk0064;
    DWORD unk0068;
    DWORD unk006C;
    DWORD unk0070;
    DWORD unk0074;
    DWORD unk0078;
    DWORD unk007C;
    DWORD unk0080;
    DWORD unk0084;
    DWORD unk0088;
    DWORD m_8c;
    DWORD m_90;
    int m_94;
    DWORD unk98;
    unsigned char m_9c;
    unsigned char unk9d;
    unsigned char unk9e;
    unsigned char unk9f;
    DWORD unkA0;
    int m_a4;
    DWORD unk00A8;
    DWORD unk00AC;
    DWORD unk00B0;
    DWORD unk00B4;
    DWORD unk00B8;
    DWORD unk00BC;
    DWORD unk00C0;
    DWORD unk00C4;
    DWORD unk00C8;
    DWORD unk00CC;
    DWORD unk00D0;
    DWORD unk00D4;
    DWORD unk00D8;
    DWORD unk00DC;
    DWORD unk00E0;
    DWORD unk00E4;
    DWORD unk00E8;
    DWORD unk00EC;
    DWORD unk00F0;
    DWORD unk00F4;
    DWORD unk00F8;
    DWORD unk00FC;
    DWORD unk0100;
    DWORD unk0104;
    DWORD unk0108;
    DWORD unk010C;
    DWORD unk0110;
    DWORD unk0114;
    DWORD unk0118;
    DWORD unk011C;
    DWORD unk0120;
    DWORD unk0124;
    DWORD unk0128;
    DWORD unk012C;
    DWORD unk0130;
    DWORD unk0134;
    DWORD unk0138;
    DWORD unk013C;
    DWORD unk0140;
    DWORD unk0144;
    DWORD unk0148;
    DWORD unk014C;
    DWORD unk0150;
    DWORD unk0154;
    D00370Array m_kNode;
    void FUN_00c91120();
    void FUN_00c91140();
};

// Calls the world's and each entity's listeners for isl with profiler records, then may run FUN_00c91120/FUN_00c91140 when w->m_94 returns to 0 and m_9c is clear.
// @fnv 0x00d011b0
void __cdecl FUN_00d011b0(S011b0_World* apWorld, S011b0_Island* apIsland)
{
    struct
    {
        volatile DWORD first;
        volatile DWORD second;
    } timing;
    apWorld->m_94++;
    {
        D00370Array& list = apWorld->m_kNode;
        for (int i = list.m_iElementCount - 1; i >= 0; i--)
        {
            if (list.m_data[i] != 0)
            {
                S011b0_Buf* pBuf = (S011b0_Buf*)TlsGetValue(DAT_0126835c);
                if (pBuf->m_pCurrent < pBuf->m_pRecordEnd)
                {
                    S011b0_Rec* pRec = pBuf->m_pCurrent;
                    pRec->m_pTag = str_010ccb10;
                    _ReadWriteBarrier();
                    timing.first = (DWORD)__rdtsc();
                    pRec->m_dwTime = timing.first;
                    pBuf->m_pCurrent = pRec + 1;
                }
                ((S011b0_Listener*)list.m_data[i])->v08(apIsland);
                pBuf = (S011b0_Buf*)TlsGetValue(DAT_0126835c);
                if (pBuf->m_pCurrent < pBuf->m_pRecordEnd)
                {
                    S011b0_Rec* pRec = pBuf->m_pCurrent;
                    pRec->m_pTag = &str_010c41f8;
                    _ReadWriteBarrier();
                    timing.second = (DWORD)__rdtsc();
                    pRec->m_dwTime = timing.second;
                    pBuf->m_pCurrent = pRec + 1;
                }
            }
        }
        ::FUN_00d00370(list);
    }
    for (int iEntity = 0; iEntity < apIsland->m_nEnts; iEntity++)
    {
        S011b0_Entity* ent = apIsland->m_ppEnts[iEntity];
        if (ent->m_pSub)
        {
            FNV_SmallArray_00d00320& l = ent->m_pSub->m_kContactListenerArray;
            for (int j = l.m_uiItemCount - 1; j >= 0; j--)
            {
                if (l.m_pItems[j] != 0)
                {
                    S011b0_Buf* pBuf = (S011b0_Buf*)TlsGetValue(DAT_0126835c);
                    if (pBuf->m_pCurrent < pBuf->m_pRecordEnd)
                    {
                        S011b0_Rec* pRec = pBuf->m_pCurrent;
                        pRec->m_pTag = str_010ccb04;
                        _ReadWriteBarrier();
                        timing.second = (DWORD)__rdtsc();
                        pRec->m_dwTime = timing.second;
                        pBuf->m_pCurrent = pRec + 1;
                    }
                    ((S011b0_Listener*)l.m_pItems[j])->v04(apIsland->m_ppEnts[iEntity]);
                    pBuf = (S011b0_Buf*)TlsGetValue(DAT_0126835c);
                    if (pBuf->m_pCurrent < pBuf->m_pRecordEnd)
                    {
                        S011b0_Rec* pRec = pBuf->m_pCurrent;
                        pRec->m_pTag = &str_010c41f8;
                        _ReadWriteBarrier();
                        timing.first = (DWORD)__rdtsc();
                        pRec->m_dwTime = timing.first;
                        pBuf->m_pCurrent = pRec + 1;
                    }
                }
            }
            ::RemoveZeroEntries(&l);
        }
    }
    if (--apWorld->m_94 == 0 && !apWorld->m_9c)
    {
        if (apWorld->m_8c)
            apWorld->FUN_00c91120();
        if (apWorld->m_a4 == 1 && apWorld->m_90)
            apWorld->FUN_00c91140();
    }
}

struct D00960Listener
{
    virtual void method0();
    virtual void method1(void* arg);
};

// Iterates owner->m_kTargets, records TtconAddCb/Et profiler ticks around each D00960Listener::method1 call, then calls FUN_00d00370 on the list.
// @fnv 0x00d00960
void __cdecl FUN_00d00960(::ProfOwner* owner, void* arg)
{
    volatile unsigned long uiEndTick;
    volatile unsigned long* pEndTick = &uiEndTick;
    ::D00370Array* list = &owner->m_kTargets;
    int i = list->m_iElementCount;
    while (--i >= 0)
    {
        if (list->m_data[i])
        {
            ::ProfBuf* buf = (::ProfBuf*)::TlsGetValue(::DAT_0126835c);
            ::ProfRec* rec = buf->cur;
            if (rec < buf->end)
            {
                volatile unsigned long uiStartTick;
                rec->name = "TtconAddCb";
                // Publish the marker name before sampling its timestamp.
                ::_ReadWriteBarrier();
                uiStartTick = (unsigned long)::__rdtsc();
                rec->tick = uiStartTick;
                buf->cur = rec + 1;
            }
            ((D00960Listener*)list->m_data[i])->method1(arg);
            buf = (::ProfBuf*)::TlsGetValue(::DAT_0126835c);
            rec = buf->cur;
            if (rec < buf->end)
            {
                rec->name = "Et";
                // Publish the marker name before sampling its timestamp.
                ::_ReadWriteBarrier();
                *pEndTick = (unsigned long)::__rdtsc();
                rec->tick = uiEndTick;
                buf->cur = rec + 1;
            }
        }
    }
    ::FUN_00d00370(*list);
}
