// gamebryo2.2/corelibs/niconsolerenderer/nidynamicgeometrygroup.cpp: NiDynamicGeometryGroup, SomeClass, UnsharedGroupStub, Group and more (17 functions)

#include "nidynamicgeometrygroup_decls.h"
// Constructs a NiDynamicGeometryGroup and initializes nextIndex to 0.
// @fnv 0x00e957b0
NiDynamicGeometryGroup::NiDynamicGeometryGroup() : nextIndex(0)
{}

struct NiStream;
struct NiObject
{
    virtual void LinkObject(NiStream&);
};
struct Direct3D9RenderSystem;
struct NiVBChip
{
    unsigned int m_uiPosition;
    NiObject* m_pkTreeBlock;
    NiStream* m_pkOwningStream;
};
struct NiGeometryBufferData
{
    char pad[0x20];
    unsigned int m_uiRegisterStreamCount;
    char pad2[4];
    NiVBChip** m_ppkVertexBuffers;
};
// @fnv 0x00e951e0
void __stdcall NiDynamicGeometryGroup_ReleaseChip(NiGeometryBufferData* pkBuffData, unsigned int uiStream)
{
    if (uiStream < pkBuffData->m_uiRegisterStreamCount)
    {
        NiVBChip* pkChip = pkBuffData->m_ppkVertexBuffers[uiStream];
        if (pkChip)
        {
            if (pkChip->m_pkOwningStream)
            {
                pkChip->m_pkTreeBlock->NiObject::LinkObject(*pkChip->m_pkOwningStream);
                pkChip->m_pkOwningStream = 0;
            }
            if (uiStream < pkBuffData->m_uiRegisterStreamCount)
                pkBuffData->m_ppkVertexBuffers[uiStream] = 0;
        }
    }
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

extern NiGeometryGroup* DAT_0126fa34;
extern void* DAT_010f1008;

// Returns the cached NiGeometryGroup singleton, constructing it with BSFadeNode::operator new and initialising it if DAT_0126fa34 is null.
// @fnv 0x00e94d70
NiGeometryGroup* __cdecl GetGeometryGroup()
{
    NiGeometryGroup* pkGroup = DAT_0126fa34;
    if (pkGroup == 0)
    {
        pkGroup = static_cast<NiGeometryGroup*>(BSFadeNode::operator new(0xc));
        if (pkGroup != 0)
        {
            pkGroup->NiGeometryGroup::NiGeometryGroup();
            *reinterpret_cast<void**>(pkGroup) = &DAT_010f1008;
            DAT_0126fa34 = pkGroup;
        }
        else
        {
            DAT_0126fa34 = 0;
        }
    }
    return DAT_0126fa34;
}

void __cdecl _NiFreeAlias(void*);
struct MM
{
    void __thiscall _DeallocateAlias(void*);
};
extern MM g_memoryManager;
extern int DAT_010f1034;
struct FUN_00e95780_shell
{
    void* _0;
    void* _4;
    void* __thiscall FUN_00e95780(unsigned int);
};
// Frees the stored pointer via _NiFreeAlias, sets the first field to &DAT_010f1034, and deallocates this when f has bit 0 set.
// @fnv 0x00e95780
void* __thiscall FUN_00e95780_shell::FUN_00e95780(unsigned int auiFlags)
{
    void* tmp = _4;
    _0 = (void*)&DAT_010f1034;
    _NiFreeAlias(tmp);
    if (auiFlags & 1)
        g_memoryManager._DeallocateAlias(this);
    return this;
}

void __cdecl FUN_00e95880();
void __cdecl operator delete(void*, unsigned int);
struct FUN_00e95b40_shell
{
    virtual ~FUN_00e95b40_shell();
    void* __thiscall DestroyIfFlagged(unsigned int uiFlags);
};
// Calls FUN_00e95880, then deletes this with size 0x50 when bit 0 of uiFlags is set, and returns this.
// @fnv 0x00e95b40
void* __thiscall FUN_00e95b40_shell::DestroyIfFlagged(unsigned int uiFlags)
{
    FUN_00e95880();
    if (uiFlags & 1)
        operator delete(this, 0x50);
    return this;
}

// Stand-ins for the unnamed/undeclared entities used by this function.
struct NiTMapBaseStub
{
    void __thiscall RemoveAll();
};

extern MM _g_memoryManager;

void __cdecl _NiFree(void*);

extern void* vftable_DynamicMap;
extern void* vftable_DynamicMapBase;

// Minimal polymorphic stand-in for the DynamicMap<NiVBChip> class hierarchy.
struct FUN_00e95380_shell
{
    void* m_pVftable;  // +0x00
    void* m_pUnk04;    // +0x04
    void* m_pUnk08;    // +0x08

    void* __thiscall DestroyDynamicMap(unsigned int uiFlags);
};

// @fnv 0x00e95380
void* __thiscall FUN_00e95380_shell::DestroyDynamicMap(unsigned int uiFlags)
{
    m_pVftable = &vftable_DynamicMap;
    ((NiTMapBaseStub*)this)->RemoveAll();
    m_pVftable = &vftable_DynamicMapBase;
    ((NiTMapBaseStub*)this)->RemoveAll();
    _NiFree(m_pUnk08);
    if (uiFlags & 1)
    {
        _g_memoryManager._DeallocateAlias(this);
    }
    return this;
}

struct SomeClass
{
    void* vtbl;
    void** data;
    unsigned short capacity;
    unsigned short size;
    unsigned short firstFree;
    unsigned short grow;

    void* FUN_00a93c50(unsigned int uiIndex);
};

// Clears the element at uiIndex, decrements firstFree if it was non-null, shrinks size when removing the last slot, and returns the removed pointer.
// @fnv 0x00a93c50
void* SomeClass::FUN_00a93c50(unsigned int uiIndex)
{
    if (uiIndex >= size)
        return 0;

    void* element = data[uiIndex];
    data[uiIndex] = 0;
    if (element)
        firstFree--;

    if (uiIndex == (unsigned short)(size - 1))
        size--;

    return element;
}

struct Base_00b601a0
{
    void __thiscall FUN_00b601a0();
};

struct Base_00aa4060
{
    void __thiscall FUN_00aa4060(void*);
};

extern "C" void __cdecl FUN_00aa10f0(int);
extern void* DAT_010f107c;
extern void* DAT_010f103c;
extern void* DAT_011f6238;

struct S_00e95300
{
    void* m_vftable;
    void* m_unk04;
    void* m_unk08;

    S_00e95300* __thiscall FUN_00e95300(int param);
};

// @fnv 0x00e95300
S_00e95300* __thiscall S_00e95300::FUN_00e95300(int aiFlags)
{
    m_vftable = &DAT_010f107c;
    ((Base_00b601a0*)this)->FUN_00b601a0();
    m_vftable = &DAT_010f103c;
    ((Base_00b601a0*)this)->FUN_00b601a0();
    FUN_00aa10f0((int)m_unk08);
    if (aiFlags & 1)
    {
        ((Base_00aa4060*)&DAT_011f6238)->FUN_00aa4060(this);
    }
    return this;
}

namespace fnv_00e95500 {
struct MemoryManager
{
    void* __thiscall FUN_00aa3e40(unsigned int);
};
extern MemoryManager DAT_011f6238;
extern char DAT_01400000;
struct Buffer
{
    unsigned int unk00;
    const char* unk04;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50;
    Buffer* __thiscall FUN_00e947c0();
};
struct Destination
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned short index18, unk1a;
    Buffer* buffer1c;
};
struct FUN_00e95500_Class
{
    void __thiscall FUN_00e98730(Buffer*);
    void __thiscall EnsureBuffer(Destination*);
};
// If destination->buffer1c is null, allocates a 0x54-byte Buffer, initializes it, stores it in buffer1c, calls FUN_00e98730, and sets index18 to 0xffff.
// @fnv 0x00e95500
void FUN_00e95500_Class::EnsureBuffer(Destination* destination)
{
    if (destination->buffer1c == 0)
    {
        Buffer* ptr = static_cast<Buffer*>(DAT_011f6238.FUN_00aa3e40(0x54));
        Buffer* newBuffer = ptr ? ptr->FUN_00e947c0() : 0;
        newBuffer->unk3c = 4;
        destination->buffer1c = newBuffer;
        newBuffer->unk04 = &DAT_01400000;
        FUN_00e98730(newBuffer);
        destination->index18 = 0xffff;
    }
}
}  // namespace fnv_00e95500

struct RttiStub
{
    const char* m_pcName;
    const RttiStub* m_pBaseRTTI;
};
extern const RttiStub kRtti_TriShapeData;
extern const RttiStub kRtti_TriStripsData;

struct MemMgrStub
{
    void* Allocate(unsigned int uiSize);
};
extern MemMgrStub g_kMemMgrStub;

extern int DAT_011bf558;

struct GeomDataStub
{
    virtual void V0();
    virtual void V1();
    virtual const RttiStub* GetRTTI() const;
    int unk04;
    int unk08;
    unsigned short m_usFlags;
    unsigned short unk0e;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    void* m_pkNormal;
    void* m_pkColor;
    int unk2c;
    int unk30;
    struct BuffDataStub* m_pkGeometryRendererData;
    void SetConsistencyMask(unsigned short usMask);
};

bool __cdecl IsKindOfStub(const RttiStub* pkRTTI, GeomDataStub* pkObject);

inline bool IsKindOfInline(const RttiStub* pkRTTI, GeomDataStub* pkObject)
{
    for (const RttiStub* p = pkObject->GetRTTI(); p; p = p->m_pBaseRTTI)
        if (p == pkRTTI)
            return true;
    return false;
}

struct BuffDataStub
{
    BuffDataStub() throw();
    static void* operator new(unsigned int uiSize)
    {
        return g_kMemMgrStub.Allocate(uiSize);
    }
    int unk00;
    unsigned int m_uiValue1;
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
    int unk30;
    int unk34;
    int unk38;
    unsigned int m_uiType;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
};

struct PartitionStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned short unk20;
    unsigned short m_usStrips;
    int unk24;
    BuffDataStub* m_pkGeometryRendererData;
};

struct UnsharedGroupStub
{
    void AddToBuffer(BuffDataStub* pkBuffData);
    void CreateBufferData(GeomDataStub* pkData, bool bHasAnimation, PartitionStub* pkPartition);
};

// @fnv 0x00e953c0
void UnsharedGroupStub::CreateBufferData(GeomDataStub* pkData, bool abUnused, PartitionStub* pkPartition)
{
    BuffDataStub* pkBuffData;
    if (pkPartition)
    {
        if (pkPartition->m_pkGeometryRendererData)
            return;
        pkBuffData = new BuffDataStub;
        pkBuffData->m_uiType = (pkPartition->m_usStrips != 0) + 4;
        pkPartition->m_pkGeometryRendererData = pkBuffData;
    }
    else
    {
        if (pkData->m_pkGeometryRendererData)
            return;
        pkBuffData = new BuffDataStub;
        if (IsKindOfInline(&kRtti_TriShapeData, pkData))
            pkBuffData->m_uiType = 4;
        else if (IsKindOfStub(&kRtti_TriStripsData, pkData))
            pkBuffData->m_uiType = 5;
        pkData->m_pkGeometryRendererData = pkBuffData;
    }

    bool bColors = pkData->m_pkColor != 0;
    bool bHasNormals = pkData->m_pkNormal != 0;
    bool bBinormals = bHasNormals && (pkData->m_usFlags & 0xf000);
    unsigned int uiT = pkData->m_usFlags & 1;
    if (uiT > (unsigned int)DAT_011bf558)
        uiT = DAT_011bf558;
    unsigned int uiFlags = 0;
    if (bColors)
        uiFlags = 0x400000;
    if (bHasNormals)
        uiFlags |= 0x800000;
    if (bBinormals)
        uiFlags |= 0x200000;
    pkBuffData->m_uiValue1 = (uiT << 24) | uiFlags;
    AddToBuffer(pkBuffData);
    pkData->SetConsistencyMask(0xffff);
}

struct ByteFlag
{
    union
    {
        bool value;
        unsigned int flags;
    };
    ByteFlag(bool b) : value(b)
    {}
};
struct MemoryAllocationProvider
{
    void* AllocateStream(unsigned int, unsigned int*, unsigned int*, bool, ByteFlag);
};
struct Chip
{
    unsigned int index;
    MemoryAllocationProvider* set;
    void* buffer;
    unsigned int size;
    unsigned int offset;
    unsigned int stride;
};
MemoryAllocationProvider* __cdecl CreateBufferSetData(unsigned int, void*, unsigned int, unsigned int);
Chip* __cdecl FUN_00537d60(unsigned int, void*, unsigned int, unsigned int, unsigned int);
template <class T> struct Map
{
    unsigned int vtable, size;
    void* table;
    unsigned int count;
    bool FUN_00a53c30(unsigned int, T*&);
    void InsertOrUpdate(unsigned int, T*);
};
template <class T> struct Array
{
    unsigned int vtable;
    T** data;
    unsigned short capacity, size, firstFree, grow;
    void FUN_00a90180(unsigned int);
    void FUN_00ba3aa0(unsigned int, T* const&);
};
struct Data
{
    unsigned int unk00, unk04, unk08, key, unk10;
    bool flag;
    unsigned char unk15;
    unsigned short unk16;
    unsigned int unk18, stride, count;
    unsigned int* lengths;
    unsigned int unk28, unk2c, unk30, unk34, result;
};
struct Group
{
    unsigned int vtable, refs;
    void* device;
    Map<MemoryAllocationProvider> sets;
    Map<Chip> chips;
    Array<MemoryAllocationProvider> streamSets;
    Array<Chip> streamChips;
    unsigned int nextIndex;
    Chip* GetOrCreateChip(Data*, unsigned int);
};
// @fnv 0x00e95550
Chip* Group::GetOrCreateChip(Data* data, unsigned int stream)
{
    Chip* chip = 0;
    unsigned int count = data->count;
    unsigned int key = data->key;
    unsigned int length = stream < count ? data->lengths[stream] : 0;
    unsigned int stride = data->stride * length;
    unsigned int size = 0;
    unsigned int offset = 0;
    if (count > 1)
    {
        if (streamSets.capacity < count)
        {
            streamSets.FUN_00a90180(count);
            streamChips.FUN_00a90180(count);
        }
        if (nextIndex >= streamSets.capacity)
            nextIndex = 0;
        MemoryAllocationProvider* set = streamSets.data[nextIndex];
        if (!set)
        {
            set = CreateBufferSetData(2048, device, 0, 0);
            streamSets.FUN_00ba3aa0(nextIndex, set);
        }
        ByteFlag flag(data->flag);
        void* buffer = set->AllocateStream(stride, &size, &offset, true, flag);
        Chip* branchChip = streamChips.data[nextIndex];
        if (!branchChip)
        {
            branchChip = FUN_00537d60(0, buffer, size, stride, 0);
            chip = branchChip;
            streamChips.FUN_00ba3aa0(nextIndex, chip);
        }
        else
        {
            branchChip->buffer = buffer;
            branchChip->size = size;
            branchChip->stride = stride;
        }
        branchChip->set = set;
        branchChip->offset = offset;
        data->result = 0;
        ++nextIndex;
        return branchChip;
    }
    else
    {
        MemoryAllocationProvider* set = 0;
        unsigned int mapKey = key ? key : length | 0x80000000;
        if (!sets.FUN_00a53c30(mapKey, set) || !set)
        {
            set = CreateBufferSetData(2048, device, key, 0);
            sets.InsertOrUpdate(mapKey, set);
        }
        ByteFlag flag(data->flag);
        void* buffer = set->AllocateStream(stride, &size, &offset, false, flag);
        chips.FUN_00a53c30(mapKey, chip);
        Chip* result = chip;
        if (!result)
        {
            result = FUN_00537d60(0, buffer, size, stride, 0);
            chips.InsertOrUpdate(mapKey, result);
        }
        else
        {
            result->buffer = buffer;
            result->size = size;
            result->stride = stride;
        }
        result->set = set;
        result->offset = offset;
        data->result = size / length;
        return result;
    }
}

struct NiMemObject
{
    static void* __cdecl operator new(unsigned int uiSize);
};
inline void* __cdecl operator new(unsigned int, void* pvMem) throw()
{
    return pvMem;
}
extern NiGeometryGroup* DAT_0126fa38;

// Creates the NiDynamicGeometryGroup singleton on first use and returns it.
// @fnv 0x00e95b10
NiGeometryGroup* __cdecl GetNiGeometryGroup() throw()
{
    if (!DAT_0126fa38)
        DAT_0126fa38 = new (NiMemObject::operator new(sizeof(NiDynamicGeometryGroup))) NiDynamicGeometryGroup;
    return DAT_0126fa38;
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct VertexBufferRef
{
    virtual void __stdcall QueryInterface() = 0;
    virtual void __stdcall AddRef() = 0;
    virtual void __stdcall Release() = 0;
};

struct BufferSetData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int size;
    VertexBufferRef* buffer;
    unsigned int unk10;
    unsigned int unk14;

    BufferSetData() : unk00(0), unk04(0), size(0), buffer(0), unk10(0)
    {}
    static void* operator new(unsigned int bytes)
    {
        return FUN_00aa13e0(bytes);
    }
    void SetBuffer(VertexBufferRef* value)
    {
        if (buffer)
            buffer->Release();
        if (value)
        {
            buffer = value;
            value->AddRef();
        }
        else
        {
            buffer = 0;
        }
    }
};

// @fnv 0x00e95230
MemoryAllocationProvider* __cdecl CreateBufferSetData(unsigned int size, void* buffer, unsigned int flags,
                                                      unsigned int kind)
{
    BufferSetData* set = new BufferSetData;
    if (set)
    {
        if (size & 15)
            size = (size & ~15U) + 32;
        set->size = size;
        set->SetBuffer((VertexBufferRef*)buffer);
        set->unk04 = flags;
        set->unk00 = kind;
    }
    return (MemoryAllocationProvider*)set;
}

namespace fnv_00e952c0 {
void _NiFreeAlias(void*);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct NiTMapBaseStub
{
    virtual void RemoveAll();
};
struct FUN_00e952c0 : NiTMapBaseStub
{
    int m_04;
    void* m_08;
    virtual ~FUN_00e952c0();
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
// Destructor that calls RemoveAll and then frees the m_08 alias via _NiFreeAlias.
// @fnv 0x00e952c0
FUN_00e952c0::~FUN_00e952c0()
{
    RemoveAll();
    _NiFreeAlias(m_08);
}
}  // namespace fnv_00e952c0

namespace fnv_00e95340 {
void __cdecl _NiFreeAlias(void*);
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct NiTMapBaseStub
{
    void RemoveAll();
};
struct FUN_00e95340
{
    int _04;
    void* _08;
    virtual ~FUN_00e95340();
    void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
// @fnv 0x00e95340
FUN_00e95340::~FUN_00e95340()
{
    ((NiTMapBaseStub*)this)->RemoveAll();
    _NiFreeAlias(_08);
}
}  // namespace fnv_00e95340

struct S_00e987c0_Stream
{
    void** vtable;
};

struct S_00e987c0_Device
{
    void** vtable;
};

typedef void(__stdcall* FUN_00e987c0_StreamRelease)(S_00e987c0_Stream*);
typedef int(__stdcall* FUN_00e987c0_Allocate)(S_00e987c0_Device*, unsigned int, unsigned int, void*, int, void*, int);

struct S_00e987c0_Class
{
    void* unk00;
    void* unk04;
    unsigned int unk08;
    S_00e987c0_Device* unk0c;
    S_00e987c0_Stream* unk10;
    unsigned int unk14;

    S_00e987c0_Stream* __thiscall AllocateStream(unsigned int uiStream, unsigned int* lpOffset, unsigned int* lpFlags,
                                                 unsigned char bForceFallback, unsigned char bUseSpecialFlags);
};

// Updates the stream size and allocation as needed, advances or resets the offset, sets flags, and returns the stream pointer.
// @fnv 0x00e987c0
S_00e987c0_Stream* __thiscall S_00e987c0_Class::AllocateStream(unsigned int uiStream, unsigned int* lpOffset,
                                                               unsigned int* lpFlags, unsigned char bForceFallback,
                                                               unsigned char bUseSpecialFlags)
{
    if (unk08 < uiStream)
    {
        if (unk10 != 0)
        {
            FUN_00e987c0_StreamRelease pfnRelease = reinterpret_cast<FUN_00e987c0_StreamRelease>(unk10->vtable[2]);
            pfnRelease(unk10);
        }

        unk10 = 0;

        unsigned int uiSize = uiStream;
        if ((uiStream & 0x0f) != 0)
        {
            uiSize = (uiStream & 0xfffffff0u) + 0x20u;
        }
        unk08 = uiSize;
    }

    S_00e987c0_Stream** ppStream = &unk10;

    if (unk10 == 0)
    {
        unsigned int uiAllocationFlags = 0x208u;
        if (bUseSpecialFlags != 0)
        {
            uiAllocationFlags = 0x218u;
        }

        int iResult = (reinterpret_cast<FUN_00e987c0_Allocate>(reinterpret_cast<void**>(unk0c->vtable)[0x1a]))(
            unk0c, unk08, uiAllocationFlags, unk04, 0, static_cast<void*>(ppStream), 0);

        if (iResult >= 0)
        {
            unk14 = 0;
        }
    }

    if (bForceFallback == 0)
    {
        unsigned int uiCommitted = unk14;
        unsigned int uiRemaining = unk08 - uiCommitted;

        if (uiRemaining >= uiStream)
        {
            *lpOffset = uiCommitted;
            unk14 += uiStream;
            *lpFlags = 0x1000u;
            goto L_00b3;
        }
    }

    *lpOffset = 0;
    unk14 = uiStream;
    *lpFlags = 0x2000u;

L_00b3:
    if (*lpOffset == 0)
    {
        *lpFlags = 0x2000u;
    }

    return *ppStream;
}

extern unsigned int DAT_010f10c4;
extern unsigned int DAT_010f0f7c;
extern unsigned int DAT_010f109c;
extern unsigned int DAT_010f105c;

struct ReleaseBuffer
{
    void** vtable;
};
typedef void(__stdcall* ReleaseFn)(ReleaseBuffer*);
struct DynamicSetData
{
    unsigned int unk00, unk04, capacity;
    ReleaseBuffer* buffer0c;
    ReleaseBuffer* buffer10;
    unsigned int offset;
    void Destroy()
    {
        ReleaseBuffer* a = buffer10;
        if (a)
            ((ReleaseFn)a->vtable[2])(a);
        ReleaseBuffer* b = buffer0c;
        if (b)
            ((ReleaseFn)b->vtable[2])(b);
    }
};
struct DynamicChipData
{
    static void operator delete(void*, unsigned int);
    ~DynamicChipData()
    {
        buffer = 0;
    }
    unsigned int index;
    DynamicSetData* set;
    ReleaseBuffer* buffer;
    unsigned int size, offset, stride, unk18, unk1c;
};
template <class T> struct MapEntryData
{
    MapEntryData* next;
    const char* key;
    T* value;
};
template <class T> struct DynamicMapData;
template <class T> struct MapVtableData
{
    void* slot0;
    unsigned int(__thiscall* hash)(DynamicMapData<T>*, const char*);
};
template <class T> struct DynamicMapData
{
    MapVtableData<T>* vtable;
    unsigned int size;
    MapEntryData<T>** table;
    unsigned int count;
    bool FUN_00e91fd0(const char*);
    void FUN_00b601a0();
    void Destroy(void* derivedVtable, void* baseVtable)
    {
        vtable = (MapVtableData<T>*)derivedVtable;
        FUN_00b601a0();
        vtable = (MapVtableData<T>*)baseVtable;
        FUN_00b601a0();
        _NiFree(table);
    }
    void* GetFirst() const
    {
        for (unsigned int i = 0; i < size; ++i)
            if (table[i])
                return table[i];
        return 0;
    }
    void GetNext(void*& pos, const char*& key, T*& value)
    {
        MapEntryData<T>* item = (MapEntryData<T>*)pos;
        key = item->key;
        value = item->value;
        if (item->next)
        {
            pos = item->next;
        }
        else
        {
            unsigned int i = vtable->hash(this, item->key);
            for (++i; i < size; i++)
            {
                item = table[i];
                if (item)
                {
                    pos = item;
                    return;
                }
            }
            pos = 0;
        }
    }
};
template <class T> struct DynamicArrayData
{
    void* vtable;
    T** data;
    unsigned short capacity, size, count, grow;
    T* RemoveAt(unsigned int i)
    {
        if (i >= size)
            return 0;
        T* value = data[i];
        data[i] = 0;
        if (value)
            --count;
        if (i == (unsigned short)(size - 1))
            --size;
        return value;
    }
};
struct DynamicGroupData
{
    void* vtable;
    unsigned int refs;
    void* device;
    DynamicMapData<DynamicSetData> sets;
    DynamicMapData<DynamicChipData> chips;
    DynamicArrayData<DynamicSetData> streamSets;
    DynamicArrayData<DynamicChipData> streamChips;
    unsigned int nextIndex;
    void FUN_00e98710();
    void FUN_00e95880();
};

// Iterates the set and chip maps and stream arrays, destroys entries, updates vtables, clears a matching global pointer, and calls FUN_00e98710.
// @fnv 0x00e95880
void DynamicGroupData::FUN_00e95880()
{
    vtable = &DAT_010f10c4;
    const char* key;
    DynamicSetData* set;
    DynamicChipData* chip;
    void* setPos = sets.GetFirst();
    while (setPos)
    {
        sets.GetNext(setPos, key, set);
        sets.FUN_00e91fd0(key);
        if (set)
        {
            set->Destroy();
            operator delete(set, sizeof(DynamicSetData));
        }
    }
    void* chipPos = chips.GetFirst();
    while (chipPos)
    {
        chips.GetNext(chipPos, key, chip);
        chips.FUN_00e91fd0(key);
        chip->buffer = 0;
        delete chip;
    }
    for (unsigned int i = 0; i < streamSets.capacity; ++i)
    {
        set = streamSets.RemoveAt(i);
        if (set)
        {
            set->Destroy();
            operator delete(set, sizeof(DynamicSetData));
        }
        chip = streamChips.RemoveAt(i);
        chip->buffer = 0;
        delete chip;
    }
    if (this == (void*)DAT_0126fa38)
        DAT_0126fa38 = 0;
    streamChips.vtable = &DAT_010f0f7c;
    _NiFree(streamChips.data);
    streamSets.vtable = &DAT_010f1034;
    _NiFree(streamSets.data);
    chips.Destroy(&DAT_010f109c, &DAT_010f105c);
    sets.Destroy(&DAT_010f107c, &DAT_010f103c);
    FUN_00e98710();
}
