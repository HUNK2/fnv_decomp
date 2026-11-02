
// src/havok/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/chain/hkppoweredchainmapper.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPoweredChainMapper.h"

class hkMemoryAllocatorE3A5;

struct hkMemoryRouterE3A5
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE3A5* m_pStreamAllocator;
};

namespace hkRouterE3A5 {
extern "C" hkMemoryRouterE3A5& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct hkBoolE3A5
{
    char m_cBooleanValue;
    hkBoolE3A5()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

template <class T> __forceinline void constructWithCopyE3A5(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArrayE3A5
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& e)
    {
        hkMemoryRouterE3A5& router = hkRouterE3A5::FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        constructWithCopyE3A5<T>(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

struct hkRowE3A5
{
    int m_slots[20];
};

struct hkTableE3A5
{
    int unk00[16];
    hkRowE3A5 m_rows[1];
};

struct hkOwnerE3A5
{
    int unk00[6];
    hkTableE3A5* m_table;
};

struct hkRefE3A5
{
    hkOwnerE3A5* m_pOwnerObject;
    int m_row;
};

struct hkRangeE3A5
{
    int m_kRayStart;
    int m_uiItemCount;
    int unk08;
};

class hkSetE3A5
{
  public:
    int unk00;
    int unk04;
    hkRangeE3A5* m_ranges;
    int unk0C;
    int unk10;
    hkRefE3A5* m_refs;

    void CollectSlotValues(int range, int slot, hkArrayE3A5<int>& out);
};

// Iterates the refs of a range and appends the slot value from each owner's table row to out when non-zero.
// @fnv 0x00e3a520
void hkSetE3A5::CollectSlotValues(int range, int slot, hkArrayE3A5<int>& out)
{
    const hkRangeE3A5& r = m_ranges[range];
    for (int i = 0; i < r.m_uiItemCount; i++)
    {
        const hkRefE3A5& ref = m_refs[r.m_kRayStart + i];
        int v = ref.m_pOwnerObject->m_table->m_rows[ref.m_row].m_slots[slot];
        if (v)
            out.AddBack(v);
    }
}

struct FnPlacement
{
};
inline void* operator new(unsigned int, FnPlacement* p)
{
    return p;
}
struct FnAllocator
{
    virtual void reserved0();
    virtual void* allocate(int size) throw();
    virtual void VirtualFunction8();
    virtual void reservedC();
    virtual void release(void* pointer, int size) throw();
};
struct FnMemory
{
    void* base;
    int reserved04;
    int reserved08;
    int reserved0C;
    FnAllocator* heap;
    FnAllocator& getHeap() const
    {
        return *heap;
    }
};
extern "C" FnMemory* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(FnAllocator*, void*, int, int);
extern "C" void __cdecl ResizeAudioStream(FnAllocator*, void*, int);
extern "C" void* __cdecl FUN_00cb1280(void*, int, unsigned int);
extern "C" int DAT_010e0654;

template <class T> struct FnArray
{
    T* data;
    int size;
    int capacity;
    FnArray() throw() : data(0), size(0), capacity(0x80000000)
    {}
    ~FnArray() throw()
    {
        clear();
    }
    void clear()
    {
        FnAllocator& heap = FUN_00c85750()->getHeap();
        size = 0;
        if (!(capacity & 0x80000000))
            heap.release(data, sizeof(T) * (capacity & 0x3fffffff));
        data = 0;
        capacity = 0x80000000;
    }
    void reserve(FnAllocator& heap, int n)
    {
        int cap = capacity & 0x3fffffff;
        if (cap < n)
        {
            cap *= 2;
            if (n >= cap)
                cap = n;
            FUN_00c908c0(&heap, this, cap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(FnAllocator& allocator, int count)
    {
        reserve(allocator, count);
        int n = count - size;
        T* p = data + size;
        if (n > 0)
            do
            {
                new ((FnPlacement*)p) T;
                ++p;
            } while (--n);
        size = count;
    }
    void push(const T& value)
    {
        FnAllocator& heap = FUN_00c85750()->getHeap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(&heap, this, sizeof(T));
        T* destination = data + size;
        const T* source = &value;
        for (int i = 0; i < 1; ++i)
            *destination++ = *source++;
        ++size;
    }
    T& expand()
    {
        FnAllocator& heap = FUN_00c85750()->getHeap();
        if (size == (capacity & 0x3fffffff))
            ResizeAudioStream(&heap, this, sizeof(T));
        return data[size++];
    }
};
struct FnMap
{
    struct Entry
    {
        int key;
        int value;
    };
    Entry* data;
    int size;
    int capacity;
    FnMap() throw() : data(0), size(0), capacity(-1)
    {
        FnAllocator& heap = FUN_00c85750()->getHeap();
        EnsureCapacity(&heap, 0);
    }
    ~FnMap() throw()
    {
        ProcessArgument(FUN_00c85750()->heap);
        FUN_00a29680();
    }
    void __thiscall EnsureCapacity(FnAllocator*, int) throw();
    void __thiscall FUN_00cb1870(FnAllocator*, int, int) throw();
    int __thiscall FindSlot(int) throw();
    void __thiscall ProcessArgument(FnAllocator*) throw();
    void __thiscall FUN_00a29680() throw();
};
struct FnNodePair
{
    int first;
    int second;
};
struct FnLink
{
    int offset;
    int count;
    int fallback;
    FnLink() : offset(-1), count(0), fallback(0)
    {}
};
struct FnTarget
{
    void* constraint;
    int target;
};
struct FnVisit
{
    void* constraint;
    int localIndex;
    int linkIndex;
};
struct FnConstraint
{
    virtual void reserved00();
    virtual void reserved04();
    virtual void reserved08();
    virtual void reserved0C();
    virtual void VirtualFunction10();
    virtual void reserved14();
    virtual void reserved18();
    virtual void reserved1C();
    virtual int getType() throw();
};
struct FnObject
{
    int reserved00;
    int reserved04;
    int reserved08;
    FnConstraint* constraint;
    void __thiscall FUN_00c905b0() throw();
};
struct FnMapper
{
    void* vtable;
    unsigned short GetAllocationSize;
    unsigned short refs;
    FnArray<FnLink> links;
    FnArray<FnTarget> targets;
    FnArray<FnObject*> chains;
    static void* operator new(unsigned int size)
    {
        FnAllocator& allocator = FUN_00c85750()->getHeap();
        FnMapper* p = (FnMapper*)allocator.allocate(size);
        p->GetAllocationSize = (unsigned short)size;
        return p;
    }
    FnMapper() : vtable(&DAT_010e0654), refs(1)
    {}
};
extern "C" int __cdecl FUN_00e5ba30(hkArray<int>*, int, int, FnArray<int>*, FnArray<int>*);
extern "C" FnObject* __cdecl FUN_00e5b510(FnArray<int>*, unsigned char);
extern "C" int __cdecl CloneInstanceFromSource(int);
struct FnDiagnostic
{
    int stream;
    int cursor;
    int capacity;
    void __thiscall FUN_00cb1600(char*, int) throw();
    void __thiscall FUN_00cc01c0(const char*) throw();
    void __thiscall FUN_00cc00e0() throw();
};
struct FnLogger
{
    virtual void reserved00();
    virtual void reserved04();
    virtual void reserved08();
    virtual void report(int, unsigned int, char*, const char*, int) throw();
};
extern "C" FnLogger* DAT_01268360;
inline void reportError(const char* message, unsigned int id, int line)
{
    unsigned int buffer[128];
    FnDiagnostic diagnostic;
    diagnostic.FUN_00cb1600((char*)buffer, 512);
    diagnostic.FUN_00cc01c0(message);
    DAT_01268360->report(1, id, (char*)buffer, ".\\Constraint\\Chain\\hkpPoweredChainMapper.cpp", line);
    diagnostic.FUN_00cc00e0();
}
__forceinline int buildOffsets(FnMapper* mapper, FnArray<int>& linkCounts)
{
    int total = 0;
    for (int i = 0; i < mapper->links.size; ++i)
    {
        mapper->links.data[i].offset = total;
        total += linkCounts.data[i];
        mapper->links.data[i].count = 0;
    }
    return total;
}
struct FnFlags
{
    unsigned char copyFallbacks;
    unsigned char includeChains;
};
// Builds an FnMapper by resolving constraint chains for node pairs, populating link offsets, targets, and optionally collecting unlinked ids.
// @fnv 0x00e3a5b0
FnMapper* __cdecl BuildPoweredChainMapper(FnFlags flags, hkArray<int>* linkIds, hkArray<FnNodePair>* pairs,
                                          hkArray<int>* unlinked) throw()
{
    FnMapper* mapper = new FnMapper;

    FnArray<FnVisit> visits;
    FnArray<int> linkCounts;
    int count = linkIds->m_iElementCount;
    linkCounts.reserve(FUN_00c85750()->getHeap(), count);
    linkCounts.size = count;
    FUN_00cb1280(linkCounts.data, 0, 4 * count);
    FnMap table;
    for (int k = 0; k < linkIds->m_iElementCount; ++k)
    {
        int key = linkIds->m_data[k];
        FnAllocator& heap = FUN_00c85750()->getHeap();
        table.FUN_00cb1870(&heap, key, k);
    }
    count = linkIds->m_iElementCount;
    mapper->links.SetSizeAndGrow(FUN_00c85750()->getHeap(), count);
    FUN_00cb1280(mapper->links.data, 0, 12 * mapper->links.size);
    for (int pairIndex = 0; pairIndex < pairs->m_iElementCount; ++pairIndex)
    {
        FnArray<int> scratch;
        FnArray<int> chainLinks;
        FnNodePair& pair = pairs->m_data[pairIndex];
        if (FUN_00e5ba30(linkIds, pair.first, pair.second, &scratch, &chainLinks) == 1)
        {
            reportError("Cannot find a chain of constraints linking one of the entity pairs.", 0xabbaaa88, 68);
            ((FnObject*)mapper)->FUN_00c905b0();
            return 0;
        }
        FnObject* obj = FUN_00e5b510(&chainLinks, flags.includeChains);
        if (!obj)
        {
            reportError("Failed to build a chain.", 0xabbaddaa, 78);
            ((FnObject*)mapper)->FUN_00c905b0();
            return 0;
        }
        mapper->chains.push(obj);
        for (int j = 0; j < chainLinks.size; ++j)
        {
            int entity = chainLinks.data[j];
            int index = table.FindSlot(entity);
            if (index > table.capacity)
            {
                reportError("Internal error.", 0xabba99dd, 93);
                obj->FUN_00c905b0();
                ((FnObject*)mapper)->FUN_00c905b0();
                return 0;
            }
            int linkIndex = table.data[index].value;
            FnLink* link = &mapper->links.data[linkIndex];
            FnVisit& v = visits.expand();
            v.linkIndex = linkIndex;
            ++linkCounts.data[linkIndex];
            if (obj->constraint->getType() != 0x66)
            {
                reportError("Internal error; invalid chain type.", 0xabba9d6d, 108);
                obj->FUN_00c905b0();
                ((FnObject*)mapper)->FUN_00c905b0();
                return 0;
            }
            v.constraint = obj->constraint;
            v.localIndex = j;
            if (flags.copyFallbacks && !link->fallback)
                link->fallback = CloneInstanceFromSource(chainLinks.data[j]);
        }
    }
    int total = buildOffsets(mapper, linkCounts);
    mapper->targets.SetSizeAndGrow(FUN_00c85750()->getHeap(), total);
    for (int i = 0; i < visits.size; ++i)
    {
        FnVisit& visit = visits.data[i];
        FnLink& link = mapper->links.data[visit.linkIndex];
        FnTarget& target = mapper->targets.data[link.offset + link.count];
        target = *(FnTarget*)&visit;
        ++link.count;
    }
    if (unlinked)
    {
        for (int i = 0; i < mapper->links.size; ++i)
        {
            if (!mapper->links.data[i].count)
            {
                int& key = linkIds->m_data[i];
                ((FnArray<int>*)unlinked)->push(key);
            }
        }
    }
    return mapper;
}

#include <xmmintrin.h>
struct TargetRuntime
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    __m128 m_vVectorData;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};

struct ChainInstance
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    TargetRuntime* m_pRuntime;
};

struct hkpPoweredChainMapperTarget
{
    ChainInstance* m_pChainInstance;
    int m_targetIndex;
};

struct hkpPoweredChainMapperLinkInfo
{
    int m_iChainIndex;
    int m_iLinkIndex;
    int unk08;
};

struct SomeClass : public hkpPoweredChainMapper
{
    void SetLinkVector(int chainIndex, const __m128& vec);
};

// Writes vec into the runtime vector slot of every target belonging to the link at chainIndex.
// @fnv 0x00e3a4d0
void SomeClass::SetLinkVector(int chainIndex, const __m128& vec)
{
    hkpPoweredChainMapperLinkInfo& linkInfo = m_ppLinks.m_data[chainIndex];
    for (int i = 0; i < linkInfo.m_iLinkIndex; ++i)
    {
        hkpPoweredChainMapperTarget& target = m_kTargets.m_data[linkInfo.m_iChainIndex + i];
        target.m_pChainInstance->m_pRuntime[target.m_targetIndex].m_vVectorData = vec;
    }
}

class hkMemoryAllocatorE3A3
{
  public:
    virtual ~hkMemoryAllocatorE3A3() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterE3A3
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE3A3* m_pStreamAllocator;
    hkMemoryAllocatorE3A3& heap()
    {
        return *m_pStreamAllocator;
    }
};

template <class T> __forceinline void destructE3A3(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayE3A3
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    T& operator[](int i)
    {
        T* p0 = m_data;
        T* p1 = p0;
        T* p2 = p1;
        T* p3 = p2;
        T* p4 = p3;
        T* p5 = p4;
        T* p6 = p5;
        T* p7 = p6;
        T* p8 = p7;
        T* p9 = p8;
        T* p10 = p9;
        T* p11 = p10;
        T* p12 = p11;
        T* p13 = p12;
        T* p14 = p13;
        T* p15 = p14;
        T* p16 = p15;
        T* p17 = p16;
        T* p18 = p17;
        T* p19 = p18;
        return p19[i];
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~hkArrayE3A3() throw()
    {
        ClearAndRelease(FUN_00c85750()->getHeap());
    }
    __forceinline void clear()
    {
        destructE3A3(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(FnAllocator& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.release(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkConstraintRefE3A3
{
  public:
    void removeReference() throw();
};

struct hkpConstraintEntryE3A3
{
    hkConstraintRefE3A3* m_pHavokConstraint;
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
};

class hkReferencedObjectE3A3
{
  public:
    virtual ~hkReferencedObjectE3A3() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

namespace FUN_00e3a3d0 {
class hkpConstraintChainMapperE3A3 : public hkReferencedObjectE3A3
{
  public:
    hkArrayE3A3<hkpConstraintEntryE3A3> m_entries;

    virtual ~hkpConstraintChainMapperE3A3() throw();
};

// Iterates over m_entries and calls removeReference on each m_pHavokConstraint.
// @fnv 0x00e3a3d0
hkpConstraintChainMapperE3A3::~hkpConstraintChainMapperE3A3() throw()
{
    const int iEntryIndex = m_entries.m_iElementCount;
    for (int i = 0; i < iEntryIndex; i++)
        m_entries[i].m_pHavokConstraint->removeReference();
}
}

class hkMemoryAllocatorE3AD
{
  public:
    virtual ~hkMemoryAllocatorE3AD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE3AD
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorE3AD* m_pStreamAllocator;

    hkMemoryAllocatorE3AD& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkR3AD {
hkMemoryRouterE3AD& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayE3AD
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        T* p = m_data;
        return p[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }

    ~hkArrayE3AD() throw()
    {
        hkMemoryAllocatorE3AD& kAlloc = hkR3AD::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkE3AD {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void FUN_00c905b0() throw();
};
}

namespace hkE3AD {
struct LinkInfoE3AD
{
    int unk00;
    int unk04;
    hkReferencedObject* m_pConstraintInstance;
};

struct TargetE3AD
{
    int unk00;
    int unk04;
};
}

namespace FUN_00e3ad80 {
class hkpPoweredChainMapper : public hkE3AD::hkReferencedObject
{
  public:
    virtual ~hkpPoweredChainMapper();

    hkArrayE3AD<hkE3AD::LinkInfoE3AD> m_ppLinks;
    hkArrayE3AD<hkE3AD::TargetE3AD> m_kTargets;
    hkArrayE3AD<hkE3AD::hkReferencedObject*> m_kChainInstances;
};

// @fnv 0x00e3ad80
hkpPoweredChainMapper::~hkpPoweredChainMapper()
{
    for (int i = 0; i < m_ppLinks.GetLogicalSize(); i++)
    {
        if (m_ppLinks[i].m_pConstraintInstance)
            m_ppLinks[i].m_pConstraintInstance->FUN_00c905b0();
    }
    for (int i = 0; i < m_kChainInstances.m_iElementCount; i++)
        m_kChainInstances.m_data[i]->FUN_00c905b0();
}
}
