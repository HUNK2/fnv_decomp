
// src/havok/physics/dynamics/collide/contactlistener/util/hkpendofstepcallbackutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/collide/contactlistener/util/hkpendofstepcallbackutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d9ec10_cls
{
    void SwapThreeInts(int* a);
};

// Swaps the first three ints of this object with the first three ints of the given array.
// @fnv 0x00d9ec10
void FUN_00d9ec10_cls::SwapThreeInts(int* paiValues)
{
    int* b = (int*)this;
    int t;
    t = b[0];
    b[0] = paiValues[0];
    paiValues[0] = t;
    t = b[1];
    b[1] = paiValues[1];
    paiValues[1] = t;
    t = b[2];
    b[2] = paiValues[2];
    paiValues[2] = t;
}

struct FirstBase
{
    int m_i00;
    int m_i04;
};

struct SecondBase
{
    int m_i00;
};

struct Derived : FirstBase, SecondBase
{
};

struct Target
{
    void FUN_00c93920(SecondBase* apObject);
};

// Calls FUN_00c93920 on apTarget, passing apObject as the argument.
// @fnv 0x00d9e250
void __fastcall PassObjectToTarget(Derived* apObject, void* apUnused, Target* apTarget)
{
    apTarget->FUN_00c93920(apObject);
}

struct S_00d9e280_B2
{
    virtual void f2();
};
struct S_00d9e280_World
{
    int ClearValue(S_00d9e280_B2* p);
};
struct S_00d9e280_B0
{
    virtual void FUN_00d9e280(S_00d9e280_World* w);
    int unk04;
};
struct S_00d9e280_D : S_00d9e280_B0, S_00d9e280_B2
{
    virtual void FUN_00d9e280(S_00d9e280_World* w);
};

// Passes this object to the world's ClearValue method.
// @fnv 0x00d9e280
void S_00d9e280_D::FUN_00d9e280(S_00d9e280_World* apWorld)
{
    apWorld->ClearValue(this);
}

struct S_00d9e2b0_Bool
{
    char m_cBooleanValue;
    S_00d9e2b0_Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct S_00d9e2b0
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    S_00d9e2b0_Bool Equals(const S_00d9e2b0& other) const;
};

// @fnv 0x00d9e2b0
S_00d9e2b0_Bool S_00d9e2b0::Equals(const S_00d9e2b0& other) const
{
    return other.m_iWordAt00 == m_iWordAt00 && other.m_iWordAt04 == m_iWordAt04 && other.m_8 == m_8;
}

struct Record
{
    void* first;
    void* second;
    void* third;
};
struct RecordArray
{
    Record* data;
    unsigned int count;
    unsigned int capacity;
};
struct MemoryManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* allocator;
};
struct FUN_00d9e450_class
{
    int unk00;
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
    RecordArray records;
    void AppendRecord(void* first, void* second, void* third);
};
MemoryManager* __cdecl FUN_00885750();
void __cdecl FUN_00890940(void* allocator, RecordArray* array, unsigned int elementSize);
// Appends a record of three pointers to the records array, growing it via the allocator when count reaches capacity.
// @fnv 0x00d9e450
void FUN_00d9e450_class::AppendRecord(void* first, void* second, void* third)
{
    RecordArray* array = &records;
    MemoryManager* manager = FUN_00885750();
    if (array->count == (array->capacity & 0x3fffffff))
        FUN_00890940(manager->allocator, array, sizeof(Record));
    unsigned int index = array->count;
    Record* data = array->data;
    Record* slot = data + index;
    array->count = index + 1;
    slot->first = first;
    slot->second = second;
    slot->third = third;
}

struct hkBaseObject
{
    virtual void BaseV() = 0;
};
struct hkReferencedObject : hkBaseObject
{
    unsigned short unk04;
    unsigned short unk06;
    hkReferencedObject();
};
hkReferencedObject::hkReferencedObject() : unk06(1)
{}
struct hkpWorldPostSimulationListener
{
    virtual void ListenerMethod() = 0;
};
struct FUN_00d9e860 : hkReferencedObject, hkpWorldPostSimulationListener
{
    volatile int unk0C;
    volatile unsigned char unk10;
    volatile int unk14;
    volatile int unk18;
    volatile int unk1C;
    volatile int unk20;
    volatile int unk24;
    volatile int unk28;
    volatile int unk2C;
    volatile int unk30;
    volatile int unk34;
    virtual ~FUN_00d9e860() = 0;
    FUN_00d9e860();
};
// @fnv 0x00d9e860
FUN_00d9e860::FUN_00d9e860()
{
    unk0C = 0;
    unk10 = 0;
    unk14 = 0;
    unk18 = 0;
    unk1C = (int)0x80000000;
    unk20 = 0;
    unk24 = 0;
    unk28 = (int)0x80000000;
    unk2C = 0;
    unk30 = 0;
    unk34 = (int)0x80000000;
}

extern "C" void* __cdecl FUN_00c85750(void);
extern "C" void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize);

struct S_00d9e3f0_Router
{
    int unk00, unk04, unk08, unk0C;
    void* m10;
    static S_00d9e3f0_Router& GetMonitorStream()
    {
        return *(S_00d9e3f0_Router*)FUN_00c85750();
    }
};

struct S_00d9e3f0_Item
{
    int unk00, unk04, unk08, unk0C;
};

struct S_00d9e3f0_Arr
{
    S_00d9e3f0_Item* m_data;
    int m_iElementCount;
    unsigned m_cap;
    S_00d9e3f0_Item& AllocatePair()
    {
        S_00d9e3f0_Router& r = S_00d9e3f0_Router::GetMonitorStream();
        if (m_iElementCount == (int)(m_cap & 0x3fffffff))
            ResizeAudioStream(r.m10, this, sizeof(S_00d9e3f0_Item));
        return m_data[m_iElementCount++];
    }
};

struct FUN_00d9e3f0_class
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    S_00d9e3f0_Arr m_aiIndexedValues;
    void AppendItem(int a, int b, int c);
};

// Appends a new item to the array with the three given values and a sequence number taken from unk0C, which is then incremented.
// @fnv 0x00d9e3f0
void FUN_00d9e3f0_class::AppendItem(int a, int b, int c)
{
    S_00d9e3f0_Item& it = m_aiIndexedValues.AllocatePair();
    it.unk00 = a;
    it.unk04 = b;
    it.unk08 = c;
    it.unk0C = unk0C++;
}

struct S_00d9ec40_Ref
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    unsigned int m_iOwnerObjectOffset;
};

struct S_00d9ec40_Obj
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    S_00d9ec40_Ref* m_kPointA;
    S_00d9ec40_Ref* m_kPointB;
};

struct __declspec(align(16)) S_00d9ec40_Entry
{
    S_00d9ec40_Obj* m_obj;
    int unk4;
    int unk8;
    int m_order;
};

static inline unsigned __int64 S_00d9ec40_getKey(const S_00d9ec40_Entry& e)
{
    return ((unsigned __int64)e.m_obj->m_kPointA->m_iOwnerObjectOffset << 32) | e.m_obj->m_kPointB->m_iOwnerObjectOffset;
}

struct S_00d9ec40_Less
{
    inline bool operator()(const S_00d9ec40_Entry& a, const S_00d9ec40_Entry& b) const
    {
        unsigned __int64 ka = S_00d9ec40_getKey(a);
        unsigned __int64 kb = S_00d9ec40_getKey(b);
        return ka < kb || (ka == kb && a.m_order < b.m_order);
    }
};

template <typename T> inline void S_00d9ec40_swap2(T& x, T& y)
{
    T t(y);
    y = x;
    x = t;
}

// Sorts the entry range [d,h] in place with a Hoare-style quicksort using cmpLess, recursing on the left part and looping on the right.
// @fnv 0x00d9ec40
void QuickSortEntries(S_00d9ec40_Entry* pEntries, int iLow, int iHigh, S_00d9ec40_Less comparator)
{
setRecursionStart:
    int i = iLow;
    int iRight = iHigh;
    S_00d9ec40_Entry pivotEntry = pEntries[(iLow + iHigh) >> 1];
    do
    {
        while (comparator(pEntries[i], pivotEntry))
            i++;
        while (comparator(pivotEntry, pEntries[iRight]))
            iRight--;
        if (iRight >= i)
        {
            if (iRight != i)
            {
                S_00d9ec40_swap2(pEntries[i], pEntries[iRight]);
            }
            iRight--;
            i++;
        }
    } while (i <= iRight);
    if (iLow < iRight)
        QuickSortEntries(pEntries, iLow, iRight, comparator);
    if (i < iHigh)
    {
        iLow = i;
        goto setRecursionStart;
    }
}

namespace fnv_00d9ee20 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00d9ee20_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00d0b0d0();

    FUN_00d9ee20_cls* FUN_00d9ee20(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// Calls FUN_00d0b0d0, then if acFlags bit 0 is set frees this through the allocator from FUN_00c85750 with m_uSize, and returns this.
// @fnv 0x00d9ee20
FUN_00d9ee20_cls* FUN_00d9ee20_cls::FUN_00d9ee20(unsigned char acFlags)
{
    FUN_00d0b0d0();
    if (acFlags & 1)
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00d9ee20

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
extern DWORD DAT_0126835c;

struct S_00d9ea80_Heap
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void ReleaseBlock(void* p, int n);
};
struct S_00d9ea80_Router
{
    int unk0, unk4, unk8, unkc;
    S_00d9ea80_Heap* m_pStreamAllocator;
    static S_00d9ea80_Router& GetMonitorStream()
    {
        return *(S_00d9ea80_Router*)FUN_00c85750();
    }
    S_00d9ea80_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
void __cdecl FUN_00c908c0(S_00d9ea80_Heap*, void* arr, int n, int elemSize);

struct S_00d9ea80_TimerEntry
{
    const char* m_name;
    unsigned m_uiStartTicks;
    int unk8;
};
struct S_00d9ea80_Timers
{
    int unk0;
    S_00d9ea80_TimerEntry* m_cur;
    int unk8;
    S_00d9ea80_TimerEntry* m_kRayEnd;
};

struct S_00d9ea80_Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    short unk24;
    unsigned char flags26;
};
struct S_00d9ea80_Sub
{
    S_00d9ea80_Info* FUN_00cf3dd0();
};
struct S_00d9ea80_Obj
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual S_00d9ea80_Sub* FUN_vfn40();
};
void __cdecl FUN_00d9e2e0(S_00d9ea80_Obj* obj, int a, int b);

struct S_00d9ea80_Src
{
    S_00d9ea80_Obj* obj;
    int a;
    int b;
    int d;
};
struct S_00d9ea80_Entry
{
    S_00d9ea80_Obj* obj;
    int a;
    int b;
};
struct S_00d9ea80_SrcArray
{
    S_00d9ea80_Src* m_data;
    int m_iElementCount;
    int m_cap;
};
struct S_00d9ea80_EntryArray
{
    S_00d9ea80_Entry* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void reserve(S_00d9ea80_Heap& a, int n)
    {
        int cap = m_cap & 0x3fffffff;
        if (cap < n)
        {
            int c2 = cap * 2;
            FUN_00c908c0(&a, this, (n < c2) ? c2 : n, sizeof(S_00d9ea80_Entry));
        }
    }
};
struct S_00d9ea80_Less
{
    char c;
};
void __cdecl FUN_00d9e4a0(void* c, S_00d9ea80_SrcArray* b);
void __cdecl FUN_00d9e680(void* c, S_00d9ea80_EntryArray* a);
void __cdecl FUN_00d9e8b0(S_00d9ea80_SrcArray* b, S_00d9ea80_EntryArray* a);
void __cdecl QuickSortEntries(S_00d9ea80_Src* data, int lo, int hi, S_00d9ea80_Less l);

struct S_00d9ea80
{
    int unk0;
    int unk4;
    unsigned char m_sort;
    unsigned char unk9, unka, unkb;
    S_00d9ea80_EntryArray m_entries;
    S_00d9ea80_SrcArray m_src;
    int m_iThirdValue[3];
    void FUN_00d9ea80(int arg);
};

// Records a timer, merges m_src into m_entries (sorting if m_sort), invokes FUN_00d9e2e0 on flagged entries, and clears unk4.
// @fnv 0x00d9ea80
void S_00d9ea80::FUN_00d9ea80(int arg)
{
    int off;
    S_00d9ea80_Timers* tm = (S_00d9ea80_Timers*)TlsGetValue(DAT_0126835c);
    S_00d9ea80_TimerEntry* h = tm->m_cur;
    if (h < tm->m_kRayEnd)
    {
        h->m_name = "TtEndOfStepCbs";
        _ReadWriteBarrier();
        *(volatile unsigned*)&off = (unsigned)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned*)&off;
        tm->m_cur = h + 1;
    }
    FUN_00d9e4a0(m_iThirdValue, &m_src);
    S_00d9ea80_EntryArray* arr = &m_entries;
    FUN_00d9e680(m_iThirdValue, arr);
    if (m_sort)
    {
        S_00d9ea80_Less less;
        less.c = 0;
        if (m_src.m_iElementCount > 1)
            QuickSortEntries(m_src.m_data, 0, m_src.m_iElementCount - 1, less);
        FUN_00d9e8b0(&m_src, arr);
    }
    else
    {
        int n = m_src.m_iElementCount;
        S_00d9ea80_Heap& hp = S_00d9ea80_Router::GetMonitorStream().heap();
        int iOldCount = arr->m_iElementCount;
        arr->reserve(hp, iOldCount + n);
        arr->m_iElementCount += n;
        S_00d9ea80_Entry* dst = arr->m_data + iOldCount;
        for (int i = 0; i < m_src.m_iElementCount; i++, dst++)
        {
            S_00d9ea80_Src* pSrc = m_src.m_data + i;
            dst->obj = pSrc->obj;
            dst->a = pSrc->a;
            dst->b = pSrc->b;
        }
        m_src.m_iElementCount = 0;
    }
    int count = m_entries.m_iElementCount;
    if (count > 0)
    {
        off = 0;
        for (int i = 0; i < count; i++, off += sizeof(S_00d9ea80_Entry))
        {
            S_00d9ea80_Entry* e = (S_00d9ea80_Entry*)((char*)arr->m_data + off);
            S_00d9ea80_Obj* pObj = e->obj;
            S_00d9ea80_Info* pInfo = pObj->FUN_vfn40()->FUN_00cf3dd0();
            if (pInfo->flags26 & 0xc)
                FUN_00d9e2e0(pObj, e->a, e->b);
        }
    }
    unk4 = 0;
    tm = (S_00d9ea80_Timers*)TlsGetValue(DAT_0126835c);
    S_00d9ea80_TimerEntry* pCurEntry2 = tm->m_cur;
    if (pCurEntry2 < tm->m_kRayEnd)
    {
        pCurEntry2->m_name = "Et";
        _ReadWriteBarrier();
        volatile unsigned uiTicks = (unsigned)__rdtsc();
        pCurEntry2->m_uiStartTicks = uiTicks;
        tm->m_cur = pCurEntry2 + 1;
    }
}

// sub ecx,8; jmp FUN_00d9ee20  ==  MSVC adjustor thunk (multiple inheritance, 8-byte primary base).
struct AdjPrimaryBase
{
    virtual void FUN_00d9ee10();
    int unk04;
};

struct AdjSecondaryBase
{
    virtual void FUN_00d9ee10();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00d9ee10
    virtual void FUN_00d9ee10();
};

AdjDerived::AdjDerived()
{}

struct NotifyProperties
{
    int unk00, unk04, unk08;
    unsigned short unk0c;
    unsigned char unk0e;
    unsigned char flags;
    int unk10;
};
struct NotifyResource
{
    int unk00, unk04, unk08, unk0c;
    unsigned short unk10;
    unsigned char flags;
};
struct EventFlag
{
    char value;
    EventFlag()
    {}
    EventFlag(bool v) : value((char)v)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct EventBase
{
    int unk00, unk04, unk08;
    void* unk0c;
    EventBase(int source, int first, int second, void* owner) : unk00(source), unk0c(owner)
    {
        unk04 = first;
        unk08 = second;
    }
};
struct S_Notify : EventBase
{
    int unk10;
    char* unk14;
    char* unk18;
    EventFlag unk1c, unk1d, unk1e;
    float* unk20;
    float* unk24;
    char* unk28;
    void* unk2c;
    void* unk30;
    S_Notify(int source, int first, int second, void* owner, int kind, char* point, char* properties, float* velocity,
             float* normal, EventFlag full, EventFlag initial, EventFlag final, char* keys, void* accumulatorA,
             void* accumulatorB)
        : EventBase(source, first, second, owner), unk10(kind), unk14(point), unk18(properties), unk1c(full),
          unk1d(initial), unk1e(final), unk20(velocity), unk24(normal), unk28(keys)
    {
        unk2c = accumulatorA;
        unk30 = accumulatorB;
    }
};

struct S_Listener
{
    virtual void Notify0(S_Notify* n);
};

struct S_Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    NotifyResource* unk30;
};

struct S_Block
{
    int unk00;
    unsigned short count;
    unsigned short extra;
    unsigned short unk08;
    unsigned char stride;
};

struct S_Owner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual S_Info* v10();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38;
    char* block;
};

struct ListenerArg
{
    S_Listener* p;
    ListenerArg(S_Listener* v) : p(v)
    {}
};
// Iterates block entries in reverse, calling the listener's Notify0 for each entry whose properties flag bit 1 is set or when the resource flags bit 8 is set.
// @fnv 0x00d9e2e0
void FUN_00d9e2e0(S_Owner* self, ListenerArg listener, int aiSource)
{
    int a = self->v10()->unk14;
    int c = self->v10()->unk18;
    char* block = self->block;
    S_Block* b = (S_Block*)block;
    int count = b->count;
    char* pProperties = block + 0x30 + (b->extra << 5);
    int stride = b->stride;
    char* pPoint = block + 0x30;
    bool bResourceFlag = ((unsigned)(self->v10()->unk30->flags & 8)) > 0;
    for (int i = count - 1; i >= 0; --i)
    {
        if ((((NotifyProperties*)pProperties)->flags & 1) || bResourceFlag)
        {
            S_Listener* __restrict callbackListener = listener.p;
            S_Notify n(aiSource, a, c, self, 3, pPoint, pProperties, 0, 0, bResourceFlag, i == count - 1, i == 0,
                       pProperties + 0x14, 0, 0);
            callbackListener->Notify0(&n);
        }
        pPoint += 0x20;
        pProperties += stride;
    }
}

struct StripCollisionD9E : S_00d9e2b0
{
    S_00d9e2b0_Bool Equals(const StripCollisionD9E& other) const;
};
struct hkMemAllocatorD9E
{
    virtual void Slot0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    virtual void* BufRealloc(void* pold, int oldNumBytes, int& reqNumBytesInOut);
};
struct hkMemRouterD9E
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemAllocatorD9E* m_pStreamAllocator;
    __forceinline hkMemAllocatorD9E& heap()
    {
        return *m_pStreamAllocator;
    }
    static __forceinline hkMemRouterD9E& GetMonitorStream()
    {
        return *static_cast<hkMemRouterD9E*>(FUN_00c85750());
    }
};
void __cdecl FUN_00c908c0(hkMemAllocatorD9E* alloc, void* array, int reqNumElems, int sizeElem);

static __forceinline StripCollisionD9E* bufAllocD9E(hkMemAllocatorD9E* alloc, int& n)
{
    int nbytes = n * (int)sizeof(StripCollisionD9E);
    StripCollisionD9E* p = static_cast<StripCollisionD9E*>(alloc->AllocateBufferWithSize(nbytes));
    n = nbytes / (int)sizeof(StripCollisionD9E);
    return p;
}
struct CopyTypeD9E
{
    int x;
};
template <unsigned int ELEMENTSIZE> static __forceinline void memCpyOneAlignedD9E(void* dst, const void* src)
{
    int i = 0;
    do
    {
        static_cast<CopyTypeD9E*>(dst)[i] = static_cast<const CopyTypeD9E*>(src)[i];
        ++i;
    } while (i < int(ELEMENTSIZE / sizeof(CopyTypeD9E)));
}
struct ElemArrayD9E
{
    StripCollisionD9E* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    static __forceinline hkMemAllocatorD9E* heap()
    {
        return static_cast<hkMemRouterD9E*>(FUN_00c85750())->m_pStreamAllocator;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline ElemArrayD9E(int n)
    {
        int cap = n;
        StripCollisionD9E* p;
        int flags;
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = (int)0x80000000;
        hkMemRouterD9E* router = static_cast<hkMemRouterD9E*>(FUN_00c85750());
        hkMemAllocatorD9E* alloc = router->m_pStreamAllocator;
        p = cap ? bufAllocD9E(alloc, cap) : 0;
        flags = cap ? cap : (int)0x80000000;
        m_data = p;
        m_iElementCount = cap;
        m_iCapacityState = flags;
    }
    __forceinline int indexOf(const StripCollisionD9E& t) const
    {
        int end = m_iElementCount;
        for (int i = 0; i < end; ++i)
        {
            if (m_data[i].Equals(t).m_cBooleanValue)
                return i;
        }
        return -1;
    }
    __forceinline void removeAt(int idx)
    {
        m_iElementCount--;
        if (m_iElementCount != idx)
            memCpyOneAlignedD9E<sizeof(StripCollisionD9E)>(m_data + idx, m_data + m_iElementCount);
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        hkMemAllocatorD9E& alloc = hkMemRouterD9E::GetMonitorStream().heap();
        int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(StripCollisionD9E));
        }
        m_iElementCount = n;
    }
    __forceinline void ClearAndRelease()
    {
        hkMemAllocatorD9E& alloc = hkMemRouterD9E::GetMonitorStream().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * (int)sizeof(StripCollisionD9E));
    }
    void SwapThreeInts(ElemArrayD9E& other);
};

__declspec(noinline) S_00d9e2b0_Bool StripCollisionD9E::Equals(const StripCollisionD9E& other) const
{
    return S_00d9e2b0_Bool(m_iWordAt00 == other.m_iWordAt00 && m_iWordAt04 == other.m_iWordAt04 && m_8 == other.m_8);
}

static __forceinline void stripCollisionArrays(ElemArrayD9E& a, ElemArrayD9E& b)
{
    int asize0 = a.m_iElementCount;
    int bsize = b.m_iElementCount;
    if (asize0 == 0)
        return;
    ElemArrayD9E kept(bsize);
    int i;
    int k = 0;
    for (i = 0; i < bsize; i++)
    {
        int idx = a.indexOf(b.m_data[i]);
        if (idx == -1)
            kept.m_data[k++] = b.m_data[i];
        else
            a.removeAt(idx);
    }
    kept.SetSizeAndGrow(bsize - asize0 + a.m_iElementCount);
    b.SwapThreeInts(kept);
    kept.ClearAndRelease();
}

// Removes entries from the first array that are found in the second, then replaces the second array with the remaining entries.
// @fnv 0x00d9e680
void __cdecl FUN_00d9e680(void* apFirstArray, S_00d9ea80_EntryArray* apSecondArray)
{
    stripCollisionArrays(*static_cast<ElemArrayD9E*>(apFirstArray), *reinterpret_cast<ElemArrayD9E*>(apSecondArray));
}

struct hkMergeTarget8b0
{
    void SwapThreeInts(int* pkSource);
};
struct hkValue8b0
{
    S_00d9ec40_Obj* m_pkObj;
    int m_iA;
    int m_iB;
};
struct __declspec(align(16)) hkEntry8b0
{
    hkValue8b0 m_kValue;
};
struct hkArray16_8b0
{
    hkEntry8b0* m_pData;
    int m_uiLogicalSize;
    int m_iCapacityAndFlags;
};
struct hkArray12_8b0
{
    hkValue8b0* m_pData;
    int m_uiLogicalSize;
    int m_iCapacityAndFlags;
};
struct hkAllocator8b0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* BufAlloc(int& iNumBytesInOut);
    virtual void BufFree(void* pvData, int iNumBytes);
};
struct hkRouter8b0
{
    int unk00, unk04, unk08, unk0C;
    hkAllocator8b0* m_pkHeap;
};
static inline unsigned __int64 GetKey8b0(const hkValue8b0& kValue)
{
    return ((unsigned __int64)kValue.m_pkObj->m_kPointA->m_iOwnerObjectOffset << 32) |
           kValue.m_pkObj->m_kPointB->m_iOwnerObjectOffset;
}

static inline hkValue8b0* AllocArray8b0(hkAllocator8b0* pkHeap, int& iCount)
{
    if (iCount)
    {
        int iNumBytes = iCount * sizeof(hkValue8b0);
        hkValue8b0* pkData = (hkValue8b0*)pkHeap->BufAlloc(iNumBytes);
        iCount = iNumBytes / (int)sizeof(hkValue8b0);
        return pkData;
    }
    return 0;
}

// Merges two arrays ordered by key into a new buffer, hands it to argOut via FUN_00d9ec10, zeroes pkNew's count and frees the temporary buffer.
// @fnv 0x00d9e8b0
void __cdecl FUN_00d9e8b0(hkArray16_8b0* pkNew, hkArray12_8b0* volatile argOut)
{
    hkArray12_8b0* pkOut = argOut;
    hkEntry8b0* pkA = pkNew->m_pData;
    hkEntry8b0* pkAEnd = pkA + pkNew->m_uiLogicalSize;
    if (pkA == pkAEnd)
        return;

    int iTotalCount = pkOut->m_uiLogicalSize + pkNew->m_uiLogicalSize;
    hkRouter8b0& kRouter0 = *(hkRouter8b0*)FUN_00c85750();
    hkValue8b0* pkData = AllocArray8b0(kRouter0.m_pkHeap, iTotalCount);
    int iCapacity = iTotalCount ? iTotalCount : 0x80000000;
    hkArray12_8b0 kMerged;
    kMerged.m_iCapacityAndFlags = iCapacity;
    hkValue8b0* pkB = pkOut->m_pData;
    kMerged.m_pData = pkData;
    kMerged.m_uiLogicalSize = iTotalCount;
    hkValue8b0* pkBEnd = pkB + pkOut->m_uiLogicalSize;
    hkValue8b0* pkDst = kMerged.m_pData;
    while (pkA < pkAEnd && pkB < pkBEnd)
    {
        if (GetKey8b0(pkA->m_kValue) < GetKey8b0(*pkB))
            *pkDst = (pkA++)->m_kValue;
        else
            *pkDst = *pkB++;
        pkDst++;
    }
    while (pkA < pkAEnd)
        *pkDst++ = (pkA++)->m_kValue;
    while (pkB < pkBEnd)
        *pkDst++ = *pkB++;

    ((hkMergeTarget8b0*)argOut)->SwapThreeInts((int*)&kMerged);
    pkNew->m_uiLogicalSize = 0;
    hkRouter8b0& kRouter = *(hkRouter8b0*)FUN_00c85750();
    hkAllocator8b0* pkHeap = kRouter.m_pkHeap;
    if ((kMerged.m_iCapacityAndFlags & 0x80000000) == 0)
        pkHeap->BufFree(kMerged.m_pData, (kMerged.m_iCapacityAndFlags & 0x3fffffff) * sizeof(hkValue8b0));
}

struct BatchCollision : S_00d9e2b0
{
    __declspec(noinline) S_00d9e2b0_Bool Equals(const BatchCollision& other) const;
};
S_00d9e2b0_Bool BatchCollision::Equals(const BatchCollision& other) const
{
    return other.m_iWordAt00 == m_iWordAt00 && other.m_iWordAt04 == m_iWordAt04 && other.m_8 == m_8;
}
struct BatchSwap
{
    void SwapThreeInts(int*);
};
struct BatchHeap
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* allocate(int* bytes);
    virtual void freeBuffer(void* data, int bytes);
};
struct BatchContext
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    BatchHeap* heap;
};

static __forceinline void transferEntry(void* out, const void* in)
{
    unsigned k = 0;
    do
    {
        ((int*)out)[k] = ((const int*)in)[k];
    } while (++k < 3);
}
template <class T> struct BatchArrayView
{
    T* data;
    int count;
    int capacity;
    __forceinline BatchArrayView() : data(0), count(0), capacity(0x80000000)
    {}
    __forceinline int size() const
    {
        return count;
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline int find(const T& item, int start = 0, int end = -1) const
    {
        if (end < 0)
            end = count;
        for (int i = start; i < end; ++i)
        {
            if (data[i].Equals(item).m_cBooleanValue)
                return i;
        }
        return -1;
    }
    __forceinline void remove(int i)
    {
        --count;
        if (count != i)
            transferEntry(data + i, data + count);
    }
};
struct IncomingBatch : BatchArrayView<S_00d9e3f0_Item>
{
};
struct PendingBatch : BatchArrayView<BatchCollision>
{
};
static __forceinline S_00d9e3f0_Item* makeAllocation(BatchHeap* heap, int& size)
{
    int bytes = size * 16;
    S_00d9e3f0_Item* result = (S_00d9e3f0_Item*)heap->allocate(&bytes);
    size = bytes / 16;
    return result;
}
struct BatchBuffer;
extern "C" void __cdecl FUN_00c908c0(BatchHeap*, BatchBuffer*, int, int);
struct BatchBuffer : BatchArrayView<S_00d9e3f0_Item>
{
    __forceinline BatchBuffer(int size) : BatchArrayView<S_00d9e3f0_Item>()
    {
        BatchContext* context = (BatchContext*)FUN_00c85750();
        BatchHeap* heap = context->heap;
        S_00d9e3f0_Item* allocation = size ? makeAllocation(heap, size) : 0;
        int cap = size ? size : 0x80000000;
        data = allocation;
        count = size;
        capacity = cap;
    }
    __forceinline void resize(int size)
    {
        BatchContext* context = (BatchContext*)FUN_00c85750();
        BatchHeap* heap = context->heap;
        int cap = capacity & 0x3fffffff;
        if (cap < size)
            FUN_00c908c0(heap, this, size < 2 * cap ? 2 * cap : size, 16);
        count = size;
    }
    __forceinline void clear()
    {
        BatchContext* context = (BatchContext*)FUN_00c85750();
        BatchHeap* heap = context->heap;
        count = 0;
        if ((capacity & 0x80000000) == 0)
            heap->freeBuffer(data, (capacity & 0x3fffffff) * 16);
    }
};
struct DestinationArg
{
    PendingBatch* p;
    DestinationArg(PendingBatch* v) : p(v)
    {}
    __forceinline PendingBatch* get() const
    {
        return p;
    }
};
struct IncomingArg
{
    IncomingBatch* p;
    IncomingArg(IncomingBatch* v) : p(v)
    {}
};
// For each incoming item, removes it from destination if present, otherwise appends it to a temporary buffer, then swaps the buffer into incoming.
// @fnv 0x00d9e4a0
void __cdecl FUN_00d9e4a0(PendingBatch& destination, IncomingBatch& incoming)
{
    int initialCount = destination.size();
    int sourceCount = incoming.size();
    if (initialCount)
    {
        BatchBuffer temporary(sourceCount);
        int written = 0;
        for (int i = 0; i < sourceCount; ++i)
        {
            int matchIndex = destination.find((const BatchCollision&)incoming[i]);
            if (matchIndex == -1)
            {
                temporary[written] = incoming[i];
                ++written;
            }
            else
            {
                destination.remove(matchIndex);
            }
        }
        temporary.resize(sourceCount - initialCount + destination.size());
        ((BatchSwap*)&incoming)->SwapThreeInts((int*)&temporary);
        temporary.clear();
    }
}
