
// src/havok/common/visualize/serialize/hkobjectserialize.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/serialize/hkobjectserialize.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef unsigned int C68E30size_t;

struct C68E30Allocator;

struct C68E30MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C68E30Allocator* m_pStreamAllocator;

    C68E30Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" C68E30MemoryRouter& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct C68E30PrimaryBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct C68E30Listener
{
    int unk00;
};

struct C68E30Entity : C68E30PrimaryBase, C68E30Listener
{
};

struct C68E30Holder
{
    int unk00;
    int unk04;
    C68E30Entity* m_pEntity;
};

struct C68E30Pair
{
    C68E30Listener* m_kListener;
    int m_uiFilterValue;

    static void* operator new(C68E30size_t, void* p) throw()
    {
        return p;
    }
};

struct C68E30PairArray
{
    C68E30Pair* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _pushBack(C68E30Allocator& alloc, const C68E30Pair& pair)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(C68E30Pair));
        new (m_data + m_iElementCount) C68E30Pair(pair);
        m_iElementCount++;
    }

    void AddBack(const C68E30Pair& pair)
    {
        _pushBack(FUN_00c85750().heap(), pair);
    }
};

struct C68E30Owner
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
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    C68E30PairArray m_kListeners;

    void FUN_00c68e30(C68E30Holder* holder, int value);
};

// @fnv 0x00c68e30
void C68E30Owner::FUN_00c68e30(C68E30Holder* holder, int value)
{
    C68E30Pair pair;
    pair.m_uiFilterValue = value;
    C68E30Listener* listener = 0;
    if (holder->m_pEntity)
        listener = holder->m_pEntity;
    pair.m_kListener = listener;
    m_kListeners.AddBack(pair);
}

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
    virtual void v0c();
    virtual void Resize(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* volatile m_pAllocator;
};

namespace fnvc_adapt {
AudioHolder* __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(void* apOwner, void* apArray, int aiSize, int aiAlign);

extern int DAT_01268fd0;

struct SweptVirtualObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(void* apItem, int aiFlag, int aiZero);
};

struct SweptItemArray
{
    void** m_00;
    int m_04;
    unsigned int m_08;
};

struct SweptEntry
{
    int unk00;
    SweptItemArray m_04;
};

struct FUN_00d641f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    SweptVirtualObj* m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    SweptEntry** m_30;
    int m_34;

    void ClearSweptEntry(int aiIndex);
};

// @fnv 0x00d641f0
void FUN_00d641f0_cls::ClearSweptEntry(int aiIndex)
{
    SweptEntry* pEntry = m_30[aiIndex];
    int i = 0;
    if (pEntry->m_04.m_04 > 0)
    {
        do
        {
            m_18->v14(pEntry->m_04.m_00[i], DAT_01268fd0, 0);
            ++i;
        } while (i < pEntry->m_04.m_04);
    }

    SweptItemArray* pArray = &pEntry->m_04;
    AudioHolder* pAudioHolder = fnvc_adapt::FUN_00c85750();
    void* pAllocator = pAudioHolder->m_pAllocator;
    int iCapacity = (int)(pArray->m_08 & 0x3fffffffu);
    if (iCapacity < 0)
    {
        FUN_00c908c0(pAllocator, pArray, (iCapacity * 2) > 0 ? iCapacity * 2 : 0, 4);
    }
    pArray->m_04 = 0;
}

struct Sink
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual bool* Get(bool* out) throw();
    virtual void Put(const void* data, unsigned int size) throw();
};

struct Entry8
{
    unsigned int first, second;
};
struct Entry16
{
    unsigned int first, second, third, unused;
};
struct Data
{
    Entry8* pairs;
    unsigned int pairCount;
    unsigned int pairCapacity;
    Entry16* triples;
    unsigned int tripleCount;
};

struct ByteSwap
{
    bool value;
};
struct Buffer
{
    void* vtable;
    unsigned short state, references;
    Sink* stream;
    bool byteSwap;
    void FUN_00d60830(Sink*, ByteSwap) throw();
    void FUN_00d609a0(unsigned int, unsigned int) throw();
    void WriteInt(unsigned int) throw();
    void FUN_00d60960(unsigned int) throw();
    void FUN_00d60590() throw();
};

// Serializes a1-a4, data pairs/triples, and payload into sink via buffer, returning total bytes written or -1 on failure.
// @fnv 0x00e0b850
static __declspec(noinline) int FUN_00e0b850(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4,
                                             const void* payload, unsigned int payloadBytes, ByteSwap byteSwap,
                                             Data* data, Sink* sink)
{
    bool status;
    unsigned int bytes;
    unsigned int count;
    Buffer buffer;
    buffer.FUN_00d60830(sink, byteSwap);
    buffer.FUN_00d609a0(a1, a2);
    if (!*sink->Get(&status))
    {
        buffer.FUN_00d60590();
        return -1;
    }
    buffer.FUN_00d609a0(a3, a4);
    if (!*sink->Get(&status))
    {
        buffer.FUN_00d60590();
        return -1;
    }
    count = data->pairCount;
    buffer.FUN_00d60960(count);
    bytes = 0x14;
    for (unsigned int i = 0; i < count; ++i)
    {
        buffer.WriteInt(data->pairs[i].first);
        buffer.WriteInt(data->pairs[i].second);
        if (!*sink->Get(&status))
        {
            buffer.FUN_00d60590();
            return -1;
        }
        bytes += 8;
    }
    count = data->tripleCount;
    buffer.FUN_00d60960(count);
    bytes += 4;
    for (unsigned int i = 0; i < count; ++i)
    {
        buffer.WriteInt(data->triples[i].first);
        buffer.FUN_00d609a0(data->triples[i].second, 0);
        buffer.FUN_00d609a0(data->triples[i].third, 0);
        if (!*sink->Get(&status))
        {
            buffer.FUN_00d60590();
            return -1;
        }
        bytes += 20;
    }
    buffer.FUN_00d60960(payloadBytes);
    if (!*sink->Get(&status))
    {
        buffer.FUN_00d60590();
        return -1;
    }
    sink->Put(payload, payloadBytes);
    if (!*sink->Get(&status))
    {
        buffer.FUN_00d60590();
        return -1;
    }
    buffer.FUN_00d60590();
    return bytes + payloadBytes + 4;
}

int SerializeData(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, const void* payload,
                  unsigned int payloadBytes, ByteSwap byteSwap, Data* data, Sink* sink)
{
    return FUN_00e0b850(a1, a2, a3, a4, payload, payloadBytes, byteSwap, data, sink);
}

struct C68E30Allocator
{
    virtual ~C68E30Allocator() throw();
    virtual void unk04() throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int numBytes) throw();
};

void __cdecl FUN_00c908c0(void* alloc, void* array, int numElements, int sizeElem);
void* __cdecl AllocateWithHeader(void* alloc, int size);
void __cdecl FUN_00c856c0(void* alloc, void* p);

struct hkBool
{
    char m_cBooleanValue;
    hkBool() throw()
    {}
    hkBool(bool b) throw() : m_cBooleanValue(b ? 1 : 0)
    {}
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
};

struct hkStreamReader
{
    virtual ~hkStreamReader() throw();
    virtual void unk04() throw();
    virtual void unk08() throw();
    virtual hkBool IsStreamValid() const throw();
    virtual int read(void* buf, int nbytes) throw();
};

struct Reloc
{
    int m_iSourceOffset;
    int toOffset;
};

struct Item24
{
    int field00;
    int field04;
    __int64 field08;
    __int64 field10;
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    __forceinline void ClearAndRelease(C68E30Allocator& alloc) throw()
    {
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc.ReleaseBlock(m_data, (cap & 0x3fffffff) * sizeof(T));
        }
    }

    __forceinline void SetSizeAndGrow(C68E30Allocator& alloc, int size) throw()
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < size)
        {
            int newCap = cap + cap;
            if (size >= newCap)
                newCap = size;
            FUN_00c908c0(&alloc, this, newCap, sizeof(T));
        }
        m_iElementCount = size;
    }

    __forceinline T& operator[](int index)
    {
        return m_data[index];
    }
};

// Reads a header, tag, relocation table, item list, and allocated buffer from a stream, applies relocations to the buffer, and returns the header value.
// @fnv 0x00e0ba10
unsigned __int64 __cdecl ReadRelocatedData(hkStreamReader* stream, char** outBuffer, int* outAllocSize,
                                           hkArray<Item24>& outItems, void* tag)
{
    int numRelocs;
    int numItems;
    int i;
    unsigned __int64 header;

    stream->read(&header, 8);
    if (!stream->IsStreamValid())
        return 0;

    stream->read(tag, 8);
    if (!stream->IsStreamValid())
        return 0;

    hkArray<Reloc> relocs;
    stream->read(&numRelocs, 4);
    if (!stream->IsStreamValid())
    {
        relocs.ClearAndRelease(FUN_00c85750().heap());
        return 0;
    }

    int count = numRelocs;
    relocs.SetSizeAndGrow(FUN_00c85750().heap(), count);
    for (i = 0; i < (unsigned int)numRelocs; ++i)
    {
        Reloc& r = relocs[i];
        stream->read(&r.m_iSourceOffset, 4);
        stream->read(&r.toOffset, 4);
        if (!stream->IsStreamValid())
        {
            relocs.ClearAndRelease(FUN_00c85750().heap());
            return 0;
        }
    }

    stream->read(&numItems, 4);
    if (!stream->IsStreamValid())
    {
        relocs.ClearAndRelease(FUN_00c85750().heap());
        return 0;
    }

    count = numItems;
    outItems.SetSizeAndGrow(FUN_00c85750().heap(), count);
    for (i = 0; i < (unsigned int)numItems; ++i)
    {
        char* item = (char*)&outItems[i];
        stream->read(item, 4);
        stream->read(item + 8, 8);
        stream->read(item + 16, 8);
        if (!stream->IsStreamValid())
        {
            relocs.ClearAndRelease(FUN_00c85750().heap());
            return 0;
        }
    }

    stream->read(outAllocSize, 4);
    if (!stream->IsStreamValid())
    {
        relocs.ClearAndRelease(FUN_00c85750().heap());
        return 0;
    }

    int iAllocationSize = *outAllocSize;
    char* buffer = (char*)AllocateWithHeader(&FUN_00c85750().heap(), iAllocationSize);
    stream->read(buffer, *outAllocSize);
    if (!stream->IsStreamValid())
    {
        FUN_00c856c0(&FUN_00c85750().heap(), buffer);
        relocs.ClearAndRelease(FUN_00c85750().heap());
        return 0;
    }

    for (i = 0; i < (unsigned int)numRelocs; ++i)
    {
        int m_iSourceOffset = relocs[i].m_iSourceOffset;
        if (m_iSourceOffset >= 0)
        {
            *(char**)(buffer + m_iSourceOffset) = buffer + relocs[i].toOffset;
        }
    }

    *outBuffer = buffer;
    unsigned __int64 ret = header;
    relocs.ClearAndRelease(FUN_00c85750().heap());
    return ret;
}

struct ObjectWriteFlag
{
    char value;
    ObjectWriteFlag(bool b) : value(b)
    {}
    ObjectWriteFlag(const ObjectWriteFlag& b) : value(b.value)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
static __declspec(noinline) int FUN_00e0b850(Data* fixups, Sink* output, unsigned int idLow, unsigned int idHigh,
                                             unsigned int classLow, unsigned int classHigh, const void* payload,
                                             unsigned int payloadSize, ObjectWriteFlag swap)
{
    bool ok;
    unsigned int total;
    unsigned int count;
    Buffer archive;
    ByteSwap endian;
    endian.value = swap;
    archive.FUN_00d60830(output, endian);
    archive.FUN_00d609a0(idLow, idHigh);
    if (!*output->Get(&ok))
    {
        archive.FUN_00d60590();
        return -1;
    }
    archive.FUN_00d609a0(classLow, classHigh);
    if (!*output->Get(&ok))
    {
        archive.FUN_00d60590();
        return -1;
    }
    count = fixups->pairCount;
    archive.FUN_00d60960(count);
    total = 20;
    for (unsigned int j = 0; j < count; ++j)
    {
        archive.WriteInt(fixups->pairs[j].first);
        archive.WriteInt(fixups->pairs[j].second);
        if (!*output->Get(&ok))
        {
            archive.FUN_00d60590();
            return -1;
        }
        total += 8;
    }
    count = fixups->tripleCount;
    archive.FUN_00d60960(count);
    total += 4;
    for (unsigned int j = 0; j < count; ++j)
    {
        archive.WriteInt(fixups->triples[j].first);
        archive.FUN_00d609a0(fixups->triples[j].second, 0);
        archive.FUN_00d609a0(fixups->triples[j].third, 0);
        if (!*output->Get(&ok))
        {
            archive.FUN_00d60590();
            return -1;
        }
        total += 20;
    }
    archive.FUN_00d60960(payloadSize);
    if (!*output->Get(&ok))
    {
        archive.FUN_00d60590();
        return -1;
    }
    output->Put(payload, payloadSize);
    if (!*output->Get(&ok))
    {
        archive.FUN_00d60590();
        return -1;
    }
    archive.FUN_00d60590();
    return total + payloadSize + 4;
}

struct ObjectWriteTri
{
    int a;
    int b;
    int c;
    int d;
};

struct ObjectWriteItem
{
    int m_00;
    int unk04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

struct ObjectWriteArrItem
{
    ObjectWriteItem* m_data;
    int m_iElementCount;
    int m_cap;
};

struct ObjectWriteArrTri
{
    ObjectWriteTri* m_data;
    int m_iElementCount;
    int m_cap;
};

struct ObjectWriteArrByte
{
    char* m_data;
    int m_iElementCount;
    int m_cap;
};

struct ObjectWriteArrInt
{
    int* m_data;
    int m_iElementCount;
    int m_cap;
};

struct ObjectWriteW
{
    ObjectWriteArrInt m_a0;
    ObjectWriteArrTri m_a1;
    ObjectWriteArrInt m_a2;
    ObjectWriteArrInt m_a3;
    int m_30;
    void FUN_00e028e0();
};

struct ObjectWriteZ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void FUN_00cc06f0(ObjectWriteArrByte* y, int one);
    void FUN_00cc0780();
};

struct ObjectWriteInfo
{
    char unk00;
    char m_01;
};

struct ObjectWriteX
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_00e02bb0(ObjectWriteInfo* info);
    void FUN_00e02a80(ObjectWriteZ* z, int a, int b, ObjectWriteW* w);
    void FUN_00e02c70();
};

extern char DAT_011b7b89;

// Writes an object record to a sink by serializing its fixups and payload via FUN_00e0b850, returning the total bytes written.
// @fnv 0x00e0bd40
int __cdecl FUN_00e0bd40(Sink* p1, ObjectWriteInfo* p2, unsigned int aiIdLow, unsigned int aiIdHigh, int p5,
                         unsigned int p6, ObjectWriteArrItem* out)
{
    ObjectWriteX x;
    x.FUN_00e02bb0(p2);
    ObjectWriteArrByte y;
    y.m_data = 0;
    y.m_iElementCount = 0;
    y.m_cap = 0x80000000;
    ObjectWriteZ z;
    z.FUN_00cc06f0(&y, 1);
    ObjectWriteW w;
    w.m_a0.m_data = 0;
    w.m_a0.m_iElementCount = 0;
    w.m_a0.m_cap = 0x80000000;
    w.m_a1.m_data = 0;
    w.m_a1.m_iElementCount = 0;
    w.m_a1.m_cap = 0x80000000;
    w.m_a2.m_data = 0;
    w.m_a2.m_iElementCount = 0;
    w.m_a2.m_cap = 0x80000000;
    w.m_a3.m_data = 0;
    w.m_a3.m_iElementCount = 0;
    w.m_a3.m_cap = 0x80000000;
    w.m_30 = 0;
    x.FUN_00e02a80(&z, p5, p6, &w);

    int need = out->m_iElementCount + w.m_a1.m_iElementCount;
    C68E30Allocator& alloc = FUN_00c85750().heap();
    if ((out->m_cap & 0x3fffffff) < need)
    {
        int iDoubled = (out->m_cap & 0x3fffffff) * 2;
        FUN_00c908c0(&alloc, out, need < iDoubled ? iDoubled : need, 0x18);
    }
    for (int i = 0; i < w.m_a1.m_iElementCount; i++)
    {
        C68E30MemoryRouter* router = &FUN_00c85750();
        if (out->m_iElementCount == (out->m_cap & 0x3fffffff))
            ResizeAudioStream(router->m_pStreamAllocator, out, 0x18);
        ObjectWriteItem* p = out->m_data + out->m_iElementCount;
        out->m_iElementCount++;
        p->m_00 = w.m_a1.m_data[i].a;
        p->m_08 = w.m_a1.m_data[i].b;
        p->m_0c = 0;
        p->m_10 = w.m_a1.m_data[i].c;
        p->m_14 = 0;
    }
    int r = FUN_00e0b850((Data*)&w, p1, aiIdLow, aiIdHigh, p6, 0, y.m_data, y.m_iElementCount,
                         ObjectWriteFlag(p2->m_01 != DAT_011b7b89));
    w.FUN_00e028e0();
    z.FUN_00cc0780();
    C68E30Allocator& allocY = FUN_00c85750().heap();
    y.m_iElementCount = 0;
    if ((y.m_cap & 0x80000000) == 0)
        allocY.ReleaseBlock(y.m_data, y.m_cap & 0x3fffffff);
    y.m_data = 0;
    y.m_cap = 0x80000000;
    x.FUN_00e02c70();
    return r;
}
