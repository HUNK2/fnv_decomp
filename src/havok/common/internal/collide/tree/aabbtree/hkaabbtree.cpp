// havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp: ElemPool, Owner, RecordPool, MapD9 and more (24 functions)

#include <xmmintrin.h>
// src/havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/tree/aabbtree/hkaabbtree.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d9be20_class {
    void FUN_00d9be20();
};

struct FUN_00d9be30_class {
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    int m14;
    int m18;
    int m1c;
    void FUN_00d9be30();
};

// @fnv 0x00d9be30
void FUN_00d9be30_class::FUN_00d9be30()
{
    reinterpret_cast<FUN_00d9be20_class*>(reinterpret_cast<char*>(this) + 0x1c)->FUN_00d9be20();
    m10 = 0;
    m14 = 0x7fffffff;
    m18 = 0;
}

struct FUN_00d9be20_cls {
    void __thiscall FUN_00d9be20();
};
struct FUN_00d9bed0_cls {
    void __thiscall FUN_00d9bed0();
};
// @fnv 0x00d9bed0
void __thiscall FUN_00d9bed0_cls::FUN_00d9bed0()
{
    ((FUN_00d9be20_cls*)((char*)this + 0x1c))->FUN_00d9be20();
    *(int*)((char*)this + 0x10) = 0;
    *(unsigned short*)((char*)this + 0x14) = 0x7fff;
    *(int*)((char*)this + 0x18) = 0;
}

struct Obj_d9be20 {
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    void FUN_00d9be20();
};
// @fnv 0x00d9be20
void Obj_d9be20::FUN_00d9be20() { m4 = 0; m10 = 0; }

#ifndef _INCLUDED_MM2
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    signed char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
};
#endif

struct Vec4 {
    __m128 m_vComponents;
    Vec4& operator=(const Vec4& o) { m_vComponents = o.m_vComponents; return *this; }
};

struct Key {
    int a;
    int b;
    Key& operator=(const Key& o) { a = o.a; b = o.b; a = o.a; return *this; }
};

struct Elem {
    Vec4 v0;
    Vec4 v1;
    Key k;
    int c;
    int d;
};

struct IntArray {
    int* m_data;
    int m_iElementCount;
    int& back() { return m_data[m_iElementCount - 1]; }
    void popBack() { m_iElementCount--; }
    int GetLogicalSize() const { return m_iElementCount; }
};

struct ElemPool {
    Elem* m_pElements;
    int m_pRayCursor;
    int m_unk08;
    IntArray m_freeArr;

    void Grow(int newCapacity, int a, int b);
    int AllocElem(int a, int b, const Elem& e);
};

// @fnv 0x00d9cd80
int ElemPool::AllocElem(int aiArg1, int aiArg2, const Elem& arElem)
{
    if (m_freeArr.GetLogicalSize() == 0)
        Grow(m_pRayCursor + 128, aiArg1, aiArg2);
    int idx = m_freeArr.back();
    m_freeArr.popBack();
    m_pElements[idx] = arElem;
    return idx;
}

struct FUN_00d9ce00_Class
{
    int base;
    int value;
    int unk08;
    int* items;
    int count;
    int FUN_00d9c450(int start, int first, int second);
    int* PopItem(int first, int second, int* output);
};

// @fnv 0x00d9ce00
int* FUN_00d9ce00_Class::PopItem(int first, int second, int* output)
{
    if (count == 0)
        FUN_00d9c450(value + 0x80, first, second);
    *output = items[count - 1];
    --count;
    return (int*)(((*output * 3) << 4) + base);
}

struct UnsignedShortArray { unsigned short* elements; unsigned int count; unsigned int capacity; };
struct AllocationContext { int unknown00, unknown04, unknown08, unknown0c; void* memory; };
void __cdecl ResizeAudioStream(void* memory, UnsignedShortArray* buffer, unsigned int count);
struct Owner { int unknown00, unknown04, unknown08; UnsignedShortArray buffer; AllocationContext* FUN_00c85750(); unsigned short* AppendElement(unsigned short value); };
// Grows the buffer if it is full, appends value at the end, increments the count and returns a pointer to the stored element.
// @fnv 0x00d9bef0
unsigned short* Owner::AppendElement(unsigned short value) {
    UnsignedShortArray* pBuffer = &buffer;
    AllocationContext* context = FUN_00c85750();
    if (pBuffer->count == (pBuffer->capacity & 0x3fffffff))
        ResizeAudioStream(context->memory, pBuffer, 2);
    unsigned short* pElement = pBuffer->elements + pBuffer->count;
    *pElement = value;
    ++pBuffer->count;
    return pElement;
}

struct Allocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void Free(void* p, unsigned int bytes);
};

struct AllocHolder {
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Allocator* m_pThreadAllocator;
};

AllocHolder* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(Allocator* allocator, void** data, unsigned int capacity, unsigned int elemSize);

struct S_d9bf30_Rec {
    int unk0; int unk4; int unk8; int unkc;
    unsigned short unk10; unsigned short unk12;
};

struct S_d9bf30_Words {
    unsigned short* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
    void push(unsigned short v) {
        unsigned short* p = m_data + m_uiItemCount;
        for (int k = 0; k < 1; k++) p[k] = v;
        m_uiItemCount++;
    }
    __forceinline void refill(unsigned short newSize, int oldCount) {
        AllocHolder* holder = FUN_00c85750();
        Allocator* alloc = holder->m_pThreadAllocator;

        unsigned int cap = m_capFlags & 0x3fffffffu;
        if ((int)cap < (int)newSize) {
            unsigned int nc = cap + cap;
            if ((int)newSize >= (int)nc) {
                nc = newSize;
            }
            FUN_00c908c0(alloc, (void**)&m_data, nc, 2);
        }

        for (int i = (int)newSize - 1; i >= oldCount; --i) {
            push((unsigned short)i);
        }
    }
};

struct FUN_00d9bf30_cls {
    S_d9bf30_Rec* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
    S_d9bf30_Words m_free;

    void AllocateRecords(unsigned short newSize, S_d9bf30_Rec** out, unsigned short* idx);
};

// @fnv 0x00d9bf30
void FUN_00d9bf30_cls::AllocateRecords(unsigned short newSize, S_d9bf30_Rec** apOutRec, unsigned short* apIndex)
{
    int oldCount = m_uiItemCount;
    int n = newSize;

    AllocHolder* holder = FUN_00c85750();
    Allocator* alloc;
    alloc = holder->m_pThreadAllocator;

    unsigned int cap = m_capFlags & 0x3fffffffu;
    if ((int)cap < n) {
        unsigned long nc = cap + cap;
        if (n >= (int)nc) {
            nc = newSize;
        }
        FUN_00c908c0(alloc, (void**)&m_data, nc, 0x14);
    }

    int k = n - m_uiItemCount;
    S_d9bf30_Rec* rec = m_data + m_uiItemCount;
    if (k > 0) {
        do {
            if (0 != rec) {
                rec->unk10 = 0;
            }
            ++rec;
        } while (--k != 0);
    }

    m_uiItemCount = newSize;

    m_free.refill(newSize, oldCount);

    int id = *apIndex;
    if ((unsigned short)id != 0x7fff) {
        *apOutRec = m_data + (unsigned short)id;
    }
}

namespace fnv_00d9c010 {
// ---------------------------------------------------------------------------
// ClearBuffers
//
// Releases the two growable buffers that the object owns and marks both of
// them empty again.
//
// Every buffer is described by a data pointer, the number of live items and
// the capacity that was reserved for it.  A capacity of 0x80000000 is the
// "empty" marker, a capacity with the sign bit set therefore means that
// nothing was reserved and nothing has to be released.
//
// The memory itself belongs to the audio sink that is reached through the
// thread local BSAudio instance; the number of bytes that is reported back
// to the sink is the masked capacity multiplied by the size of one item,
// because that is the number of bytes the sink handed out in the first
// place.  The release goes through the fifth entry of the sink's vtable.
// ---------------------------------------------------------------------------

// The sink that owns the memory of the streamed buffers.
struct AudioSink {
    virtual void* unk00();
    virtual void* unk04();
    virtual void* unk08();
    virtual void* unk0c();
    virtual void release(void* data, int size);
};

// The thread local audio system, the sink is its fifth member.
struct BSAudio {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioSink* m_sink;
};

// The thread local getter of the audio system (it is declared, not defined,
// because it lives in another translation unit).
BSAudio* __cdecl FUN_00c85750();

// The object that owns the two buffers: items of 48 bytes and items of 4
// bytes, each with its own data pointer, item count and capacity.
struct FUN_00d9c010_cls {
    void* m_data0;   // 0x00
    int m_count0;    // 0x04
    int m_capacity0; // 0x08
    void* m_data1;   // 0x0c
    int m_count1;    // 0x10
    int m_capacity1; // 0x14
    void ClearBuffers();
};

// @fnv 0x00d9c010
void FUN_00d9c010_cls::ClearBuffers()
{
    {
        BSAudio* audio = FUN_00c85750();
        AudioSink* sink = audio->m_sink;
        int capacity = m_capacity1;
        m_count1 = 0;
        if (!(capacity & 0x80000000))
            sink->release(m_data1, (capacity & 0x3fffffff) * 4);
        m_data1 = 0;
        m_capacity1 = 0x80000000;
    }
    {
        BSAudio* audio = FUN_00c85750();
        AudioSink* sink = audio->m_sink;
        int capacity = m_capacity0;
        m_count0 = 0;
        if (!(capacity & 0x80000000))
            sink->release(m_data0, (capacity & 0x3fffffff) * 48);
        m_data0 = 0;
        m_capacity0 = 0x80000000;
    }
}
}  // namespace fnv_00d9c010

namespace fnv_00d9c090 {
struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00d9c090_cls {
    void* m_pData2;
    int m_iCount2;
    unsigned int m_uCapBits2;
    void* m_pData1;
    int m_iCount1;
    unsigned int m_uCapBits1;

    void ClearArrays();
};

// @fnv 0x00d9c090
void FUN_00d9c090_cls::ClearArrays()
{
    AudioHolder* pHolder = FUN_00c85750();
    AudioAllocator* pAllocator = pHolder->m_pAllocator;
    unsigned int uCapBits1 = m_uCapBits1;
    m_iCount1 = 0;
    if ((uCapBits1 & 0x80000000u) == 0) {
        pAllocator->FreeArray(m_pData1, (uCapBits1 & 0x3fffffffu) * 2);
    }
    m_pData1 = 0;
    m_uCapBits1 = 0x80000000u;

    AudioHolder* pHolder2 = FUN_00c85750();
    AudioAllocator* pAllocator2 = pHolder2->m_pAllocator;
    unsigned int uCapBits2 = m_uCapBits2;
    m_iCount2 = 0;
    if ((uCapBits2 & 0x80000000u) == 0) {
        pAllocator2->FreeArray(m_pData2, (uCapBits2 & 0x3fffffffu) * 20);
    }
    m_pData2 = 0;
    m_uCapBits2 = 0x80000000u;
}
}  // namespace fnv_00d9c090

struct Record20 { int field0,field4,field8,fieldC,field10; };
struct RecordPool {
    Record20* records;
    unsigned short type;
    unsigned short unk06;
    int unk08;
    unsigned short* available;
    int count;
    void __thiscall AllocateRecords(unsigned short typeCode, int first, int second);
    unsigned short __thiscall AddRecord(int first,int second,const Record20* item);
};
// @fnv 0x00d9c210
unsigned short RecordPool::AddRecord(int first,int second,const Record20* item) {
    if (!count) AllocateRecords((unsigned short)(type + 0x80),first,second);
    unsigned short slot=available[count - 1];
    volatile int& remaining = count;
    --remaining;
    records[slot] = *item;
    return slot;
}

namespace fnv_00d9c280 {
// PopGlyphRecord - pops one 16-bit entry off the object's stack and returns the
// record it names.  The stack is refilled (in blocks of 0x80 records) by
// AllocateRecords when it runs empty.
//
// Object layout (from the disassembly):
//   +0x00  Glyph20* m_pRecords   array of 0x14-byte records
//   +0x04  int      m_nRecords   number of records
//   +0x08  int      m_capRecords record capacity
//   +0x0c  ushort*  m_pStackBuffer     array of 16-bit stack entries
//   +0x10  int      m_nStack     number of stack entries
//   +0x14  int      m_capStack   stack capacity

struct Glyph20 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

struct FUN_00d9bf30_cls {
    void __thiscall AllocateRecords(unsigned short index, int* outRecord, unsigned short* inChar);
};

struct FUN_00d9c280_cls {
    Glyph20* m_pRecords;      // +0x00
    int m_nRecords;           // +0x04
    int m_capRecords;         // +0x08
    unsigned short* m_pStackBuffer; // +0x0c
    int m_nStack;             // +0x10
    int m_capStack;           // +0x14

    Glyph20* PopGlyphRecord(int* outRecord, unsigned short* inChar, unsigned short* outChar);
};

// @fnv 0x00d9c280
Glyph20* FUN_00d9c280_cls::PopGlyphRecord(int* outRecord, unsigned short* inChar, unsigned short* outChar) {
    if (m_nStack == 0) {
        unsigned short index = (unsigned short)(0x80 + m_nRecords);
        ((FUN_00d9bf30_cls*)this)->AllocateRecords(index, outRecord, inChar);
    }
    unsigned short*& stack = m_pStackBuffer;
    *outChar = stack[m_nStack - 1];
    m_nStack--;
    return &m_pRecords[*outChar];
}
}  // namespace fnv_00d9c280

namespace fnv_00d9c320 {
extern int DAT_010d40ac;

struct AudioAllocator {
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct SubObject_b3483 {
    int unk00;
    void Release();
};

struct FUN_00d9c320_cls {
    int m_vptr;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    SubObject_b3483 m_sub;

    void BaseRelease();
    FUN_00d9c320_cls* Destroy(unsigned char acFlags);
};

// Sets the vtable, calls BaseRelease and the sub-object's Release, and if bit 0 of acFlags is set frees this object through the audio allocator.
// @fnv 0x00d9c320
FUN_00d9c320_cls* FUN_00d9c320_cls::Destroy(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010d40ac;
    BaseRelease();
    m_sub.Release();
    if (acFlags & 1) {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, 0x80);
    }
    return this;
}
}  // namespace fnv_00d9c320

namespace fnv_00d9c360 {
struct D9C360Allocator {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct D9C360MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D9C360Allocator* m_pStreamAllocator;

    D9C360Allocator& heap() { return *m_pStreamAllocator; }
};

extern "C" D9C360MemoryRouter& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);

struct D9C360Node {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_pChildAtom;
    int unk24;
    unsigned int m_flags;
    int m_sibling;
};

struct D9C360NodeArray {
    D9C360Node* get(int index);
};

// hkInplaceArray<D9C360Node*, 128> without a destructor (Havok was built without EH).
struct D9C360NodeStack {
    D9C360Node** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    D9C360Node* m_kStorage[128];

    D9C360NodeStack() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(0x80000080) {}

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void AddBack(D9C360Node* n)
    {
        D9C360Allocator& alloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(D9C360Node*));
        m_data[m_iElementCount++] = n;
    }

    void release()
    {
        D9C360Allocator& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(D9C360Node*));
    }
};

struct D9C360Tree {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    D9C360NodeArray m_kNodeCollection;

    void TraverseTree(D9C360Node* root, void* context);
};

// @fnv 0x00d9c360
void D9C360Tree::TraverseTree(D9C360Node* node, void* context)
{
    if (!node)
        return;
    D9C360NodeStack stack;
    for (;;) {
        if (node->m_flags & 0x80000000) {
            if (stack.m_iElementCount == 0)
                break;
            node = stack.m_data[stack.m_iElementCount - 1];
            stack.m_iElementCount--;
            continue;
        }
        node = m_kNodeCollection.get(node->m_pChildAtom);
        D9C360Node* sibling = (node->m_sibling != 0x7fffffff) ? m_kNodeCollection.get(node->m_sibling) : 0;
        stack.AddBack(sibling);
    }
    stack.release();
}
}  // namespace fnv_00d9c360

struct BoundsNode { unsigned short m00,m02,m04,m06,m08,m0A,m0C,m0E,m10,m12; };
struct FUN_00d9a4d0_cls { BoundsNode* __thiscall GetEntryOffset(unsigned short key); };
struct FUN_00d9b450_cls { int m00,m04,m08,m0C,m10,m14,m18; FUN_00d9a4d0_cls m1c; void __thiscall UpdateBoundsNode(BoundsNode* a1,unsigned short a2,unsigned short a3); };
// Sets a node's m12 to a3, then unless m10 has bit 0x8000 set, updates its two child nodes and recomputes the node's bounds from them.
// @fnv 0x00d9b450
void FUN_00d9b450_cls::UpdateBoundsNode(BoundsNode* pNode,unsigned short usValue,unsigned short usValue2) {
 pNode->m12=usValue2;
 if(pNode->m10&0x8000) return;
 BoundsNode* pChild1=m1c.GetEntryOffset(pNode->m0C);
 BoundsNode* pChild2=m1c.GetEntryOffset(pNode->m0E);
 pChild1->m10=(pChild1->m10&0x8000)|usValue;
 pChild2->m10=(pChild2->m10&0x8000)|usValue;
 UpdateBoundsNode(pChild1,pNode->m0C,pNode->m0E);
 UpdateBoundsNode(pChild2,pNode->m0E,usValue2);
 unsigned short b=pChild2->m06, c=pChild1->m06; pNode->m06=c<b?c:b;
 b=pChild2->m00; c=pChild1->m00; pNode->m00=c>b?c:b;
 b=pChild2->m08; c=pChild1->m08; pNode->m08=c<b?c:b;
 b=pChild2->m02; c=pChild1->m02; pNode->m02=c>b?c:b;
 b=pChild2->m0A; c=pChild1->m0A; pNode->m0A=c<b?c:b;
 b=pChild2->m04; c=pChild1->m04; pNode->m04=c>b?c:b;
}

struct S_00d9d650_Heap
{
    virtual void unkVfn0();
    virtual void unkVfn1();
    virtual void unkVfn2();
    virtual void unkVfn3();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00d9d650_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d9d650_Heap* m_pStreamAllocator;
    S_00d9d650_Heap& heap() { return *m_pStreamAllocator; }
};

namespace fnvc_adapt { S_00d9d650_Router& __cdecl FUN_00c85750(); }
void __cdecl FUN_00c908c0(S_00d9d650_Heap& alloc, void* array, int reqCapacity, int sizeElem);

template <typename T>
struct S_00d9d650_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00d9d650_Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~S_00d9d650_Array() throw() { _clearAndDeallocate(fnvc_adapt::FUN_00c85750().heap()); }

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    T& operator[](int i) { return m_data[i]; }

    void _clearAndDeallocate(S_00d9d650_Heap& alloc) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(S_00d9d650_Heap& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S_00d9d650_Heap& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n) { _setSize(fnvc_adapt::FUN_00c85750().heap(), n); }
};

struct S_00d9d650_Vector4
{
    __m128 m_vComponents;
    void operator=(const S_00d9d650_Vector4& v) { m_vComponents = v.m_vComponents; }
};

struct S_00d9d650_Aabb
{
    S_00d9d650_Vector4 m_kMinimumCorner;
    S_00d9d650_Vector4 m_kMaximumCorner;
};

struct S_00d9d650_Node
{
    S_00d9d650_Aabb m_kBounds;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    void setLeaf(int key)
    {
        m_20 = key;
        m_28 |= 0x80000000;
    }
};

struct S_00d9d650_Pool
{
    void FUN_00d9c450(int numNodes, S_00d9d650_Node** root, int* a);
    S_00d9d650_Node* PopItem(S_00d9d650_Node** root, int* a, int* b);
};

struct S_00d9d650_Tree
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d9d650_Node* m_pTreeNode;
    int m_14;
    int m_iNodeCount;
    S_00d9d650_Pool m_kNodePool;

    void FUN_00d9d1c0(S_00d9d650_Aabb* aabbs, const int* keys, int n, S_00d9d650_Node* root, S_00d9d650_Array<int>& out, int depth);
    void MergeNode(S_00d9d650_Node* root, int a, int b);
    void TraverseTree(S_00d9d650_Node* root, int a);
    void BuildTree(const S_00d9d650_Aabb* aabbs, const int* keys, int n, S_00d9d650_Array<int>& out) throw();
};

// @fnv 0x00d9d650
void S_00d9d650_Tree::BuildTree(const S_00d9d650_Aabb* aabbs, const int* keys, int n, S_00d9d650_Array<int>& out) throw()
{
    m_iNodeCount = n;
    if (n)
    {
        out.SetSizeAndGrow(n);
        m_kNodePool.FUN_00d9c450(2 * n - 1, &m_pTreeNode, &m_14);
        m_pTreeNode = m_kNodePool.PopItem(&m_pTreeNode, &m_14, &m_14);
        m_pTreeNode->m_28 |= 0x7fffffff;

        S_00d9d650_Array<S_00d9d650_Aabb> tmp;
        tmp.SetSizeAndGrow(n);
        for (int i = 0; i < n; i++)
        {
            S_00d9d650_Aabb& d = tmp[i];
            d.m_kMaximumCorner = aabbs[i].m_kMaximumCorner;
            d.m_kMinimumCorner = aabbs[i].m_kMinimumCorner;
        }

        if (n == 1)
        {
            m_pTreeNode->setLeaf(keys[0]);
            m_pTreeNode->m_2c = 0x7fffffff;
            m_pTreeNode->m_kBounds = tmp[0];
            out[0] = m_14;
        }
        else
        {
            FUN_00d9d1c0(tmp.m_data, keys, n, m_pTreeNode, out, 0);
        }
        MergeNode(m_pTreeNode, m_14, 0x7fffffff);
        TraverseTree(m_pTreeNode, 0);
    }
}

struct Node_d9c520
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned short unk10;
    unsigned short unk12;
};

struct Resolver_d9c520
{
    Node_d9c520* GetEntryOffset(unsigned short index);
    Node_d9c520* ResolveChild(unsigned short index);
};

struct TrackedArray_d9c520
{
    Node_d9c520** elements;
    unsigned int count;
    int capacity;
};

struct Pool_d9c520
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    Resolver_d9c520 resolver;

    void TraverseNodeTree(Node_d9c520* node, int second);
};

// Walks the node tree using a stack array, resolving children and pushing/popping nodes, then frees the tracked array if it was heap-allocated.
// @fnv 0x00d9c520
void Pool_d9c520::TraverseNodeTree(Node_d9c520* node, int second)
{
    if (node != 0)
    {
        TrackedArray_d9c520 nodeStack;
        Node_d9c520* stack[128];
        nodeStack.elements = stack;
        nodeStack.count = 0;
        nodeStack.capacity = 0x80000080;
        while (true)
        {
            if ((node->unk10 & 0x8000) != 0)
            {
                if (nodeStack.count == 0)
                    break;
                node = nodeStack.elements[nodeStack.count - 1];
                nodeStack.count = nodeStack.count - 1;
            }
            else
            {
                node = resolver.GetEntryOffset(node->unk0C);
                Node_d9c520* child = node->unk12 != 0x7fff ? resolver.ResolveChild(node->unk12) : 0;
                AllocHolder* holder = FUN_00c85750();
                if (nodeStack.count == (nodeStack.capacity & 0x3fffffff))
                    ResizeAudioStream(holder->m_pThreadAllocator, (UnsignedShortArray*)&nodeStack, 4);
                nodeStack.elements[nodeStack.count] = child;
                nodeStack.count = nodeStack.count + 1;
            }
        }
        AllocHolder* holder = FUN_00c85750();
        Allocator* allocator = holder->m_pThreadAllocator;
        int capacity = nodeStack.capacity;
        nodeStack.count = 0;
        if (capacity & 0x80000000)
            return;
        allocator->Free(nodeStack.elements, (capacity & 0x3fffffff) * 4);
    }
}

void __cdecl AppendElement();

// @fnv 0x00d9c2d0
void __cdecl FUN_00d9c2d0(int param_1, unsigned short param_2) {
    AppendElement();
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

struct NodeD9C7 {
    char unk00[0x10];
    unsigned short m_usFlags;
};

class FreeListD9C7 {
public:
    void FUN_00d9c2d0(NodeD9C7* pkNode);
};

class FUN_00d9c7d0_C {
public:
    char unk00[0x10];
    NodeD9C7* m_pkTreeNode;
    short m_sValue;
    short unk16;
    int m_iArrayLength;
    FreeListD9C7 m_kFreeList;

    void FUN_00d9bb50(NodeD9C7* pkNode, NodeD9C7** ppkOut);
    void FUN_00d9c7d0(NodeD9C7* pkNode);
};

// @fnv 0x00d9c7d0
void FUN_00d9c7d0_C::FUN_00d9c7d0(NodeD9C7* pkNode)
{
    if (!(m_pkTreeNode->m_usFlags & 0x8000)) {
        NodeD9C7* pkOther;
        FUN_00d9bb50(pkNode, &pkOther);
        m_kFreeList.FUN_00d9c2d0(pkOther);
    } else {
        m_sValue = 0x7fff;
        m_pkTreeNode = 0;
    }
    m_kFreeList.FUN_00d9c2d0(pkNode);
    m_iArrayLength--;
}

#ifndef _INCLUDED_MM2
extern "C" __m128 _mm_setr_ps(float e0, float e1, float e2, float e3);
#endif

struct hkVector4 {
    __m128 m_vComponents;
    hkVector4& operator=(const hkVector4& o) { m_vComponents = o.m_vComponents; return *this; }
    void set(float x, float y, float z, float w) { m_vComponents = _mm_setr_ps(x, y, z, w); }
};

extern hkVector4 DAT_01267e30;

struct Range {
    unsigned int m_kPointA;
    unsigned int m_kPointB;
    unsigned int m_iThirdValue;
    Range() : m_kPointA(0), m_kPointB(0), m_iThirdValue(0x80000000u) {}
};

struct FUN_00d9c110_cls {
    virtual ~FUN_00d9c110_cls();
    unsigned int m10;
    unsigned int m14;
    unsigned int m18;
    Range m1c;
    Range m28;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    hkVector4 m40;
    hkVector4 m50;
    hkVector4 m60;
    hkVector4 m70;
    FUN_00d9c110_cls();
};

// @fnv 0x00d9c110
FUN_00d9c110_cls::FUN_00d9c110_cls() {
    m40 = DAT_01267e30;
    m50 = DAT_01267e30;
    hkVector4 v;
    v.set(1.0f, 1.0f, 1.0f, 0.0f);
    m10 = 0;
    m18 = 0;
    m14 = 0x7fffffffu;
    m60 = v;
    m70 = v;
}

inline void* operator new(unsigned int, void* p) { return p; }

template <class T> struct hkArray_d9c4 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void reserve(int n)
    {
        S_00d9d650_Heap& heap = fnvc_adapt::FUN_00c85750().heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n) {
            int cap2 = 2 * cap;
            FUN_00c908c0(heap, this, n < cap2 ? cap2 : n, sizeof(T));
        }
    }
    static void construct(T* p, int n)
    {
        for (int i = 0; i < n; i++)
            new (p + i) T();
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        construct(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
    __forceinline void pushBackUnchecked(const T& t)
    {
        T* p = &m_data[m_iElementCount];
        __assume(p != 0);
        new (p) T(t);
        m_iElementCount++;
    }
};

struct Handle_d9c4 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int m_pOwnerObject;
    int unk2C;
    Handle_d9c4() { m_pOwnerObject = 0; }
};

struct HandlePool_d9c4 {
    hkArray_d9c4<Handle_d9c4> m_handles;
    hkArray_d9c4<int> m_kFreeListEntries;
    void FUN_00d9c450(int newSize, Handle_d9c4** ppHandle, const int* pIndex);
};

// @fnv 0x00d9c450
void HandlePool_d9c4::FUN_00d9c450(int newSize, Handle_d9c4** ppHandle, const int* pIndex)
{
    int oldSize = m_handles.m_iElementCount;
    m_handles.SetSizeAndGrow(newSize);
    m_kFreeListEntries.reserve(newSize);
    for (int i = newSize - 1; i >= oldSize; i--)
        m_kFreeListEntries.pushBackUnchecked(i);
    if (*pIndex != 0x7fffffff)
        *ppHandle = &m_handles.m_data[*pIndex];
}

struct S_00d9af30_Node {
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
    int unk20;
    int unk24;
    unsigned int m_flags;
    int unk2c;
};
struct S_00d9af30_Pool {
    S_00d9af30_Node* m_pData;
    S_00d9af30_Node* __thiscall FUN_00d9a4c0(int);
};
struct S_00d9af30 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    S_00d9af30_Pool m_kNodePool;
    void __thiscall MergeNode(S_00d9af30_Node* n, int a, int b);
};
// Stores b in n->unk2c; for nonleaf nodes, updates child flags, recurses, and combines their bounds into n.
// @fnv 0x00d9af30
void __thiscall S_00d9af30::MergeNode(S_00d9af30_Node* apNode, int a, int b)
{
    apNode->unk2c = b;
    if ((apNode->m_flags & 0x80000000) == 0) {
        S_00d9af30_Node* pLeft = m_kNodePool.FUN_00d9a4c0(apNode->unk20);
        S_00d9af30_Node* r = m_kNodePool.FUN_00d9a4c0(apNode->unk24);
        pLeft->m_flags = (pLeft->m_flags & 0x80000000) | a;
        r->m_flags = (r->m_flags & 0x80000000) | a;
        MergeNode(pLeft, apNode->unk20, apNode->unk24);
        MergeNode(r, apNode->unk24, b);
        apNode->m_kMinimumCorner = _mm_min_ps(pLeft->m_kMinimumCorner, r->m_kMinimumCorner);
        apNode->m_kMaximumCorner = _mm_max_ps(pLeft->m_kMaximumCorner, r->m_kMaximumCorner);
    }
}

struct __declspec(align(16)) Block32 {
    __m128 m00;
    __m128 m10;
};

struct S00d9a4c0_Cls {
    Block32* __thiscall FUN_00d9a4c0(int key);
};

__declspec(noalias) void __stdcall FUN_00d9b240(int key, unsigned int* out);

struct MapD9 {
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    S00d9a4c0_Cls m1c;
    void FUN_00d9afe0(int a1, int a2, int a3);
    void FUN_00d9be50(int key, const Block32* src);
};

// Stores a Block32 value for key, replacing an existing entry or inserting a new one via FUN_00d9afe0.
// @fnv 0x00d9be50
void MapD9::FUN_00d9be50(int key, const Block32* src) {
    if (m14 == key) {
        Block32* out = m1c.FUN_00d9a4c0(key);
        out->m10 = src->m10;
        out->m00 = src->m00;
        return;
    }
    unsigned int tmp;
    FUN_00d9b240(key, &tmp);
    Block32* out = m1c.FUN_00d9a4c0(key);
    __m128 hi = src->m10;
    __m128 lo = src->m00;
    out->m00 = lo;
    out->m10 = hi;
    FUN_00d9afe0(m14, key, tmp);
}

extern __m128 DAT_010c7170;

struct __declspec(align(16)) S_00d9c180_Vec { float x, y, z, w; };

struct S_00d9c180_Arr { int m_data; int m_iElementCount; int m_cap; S_00d9c180_Arr() { m_data = 0; m_iElementCount = 0; m_cap = 0x80000000; } };

struct S_00d9c180_Base
{
    virtual void Reserved0();
};

struct __declspec(align(16)) FUN_00d9c180 : S_00d9c180_Base
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned short unk14;
    unsigned short unk16;
    int unk18;
    S_00d9c180_Arr unk1C;
    S_00d9c180_Arr unk28;
    int unk34;
    int unk38;
    int unk3C;
    S_00d9c180_Vec unk40;
    S_00d9c180_Vec unk50;
    S_00d9c180_Vec unk60;
    S_00d9c180_Vec unk70;
    FUN_00d9c180(const S_00d9c180_Vec* a, const S_00d9c180_Vec* b, const S_00d9c180_Vec* c);
};

// Copies three input vectors into fields, computes a reciprocal approximation into unk70, and sets unk10 and unk18 to zero and unk14 to 0x7fff.
// @fnv 0x00d9c180
FUN_00d9c180::FUN_00d9c180(const S_00d9c180_Vec* apVecA, const S_00d9c180_Vec* apVecB, const S_00d9c180_Vec* apVecC)
{
    *(__m128*)&unk40 = *(const __m128*)apVecA;
    *(__m128*)&unk50 = *(const __m128*)apVecB;
    *(__m128*)&unk60 = *(const __m128*)apVecC;
    __m128 v = *(const __m128*)apVecC;
    __m128 t = _mm_unpackhi_ps(v, DAT_010c7170);
    __m128 vShuffled = _mm_shuffle_ps(v, t, 0xc4);
    __m128 r = _mm_rcp_ps(vShuffled);
    __m128 r2 = _mm_mul_ps(_mm_mul_ps(r, vShuffled), r);
    *(__m128*)&unk70 = _mm_sub_ps(_mm_add_ps(r, r), r2);
    unk10 = 0;
    unk18 = 0;
    unk14 = 0x7fff;
}

extern const void* DAT_010d40a4[];

struct TreeDeleteAllocatorD9C2 {
    virtual void First();
    virtual void Second();
    virtual void Deallocate(void* address, unsigned int size);
};

struct TreeDeleteNodeManagerD9C2 {
    void ClearBuffers();
};

struct TreeDeleteD9C2 {
    const void** m_ppVirtualMethodTable;
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    TreeDeleteNodeManagerD9C2 m_kNodeCollection;

    void FUN_00d9be30();
    TreeDeleteD9C2* FUN_00d9c2e0(unsigned char flags);
};

// Assigns a global address to a field, calls two member functions, optionally deallocates this when flags bit 0 is set, then returns this.
// @fnv 0x00d9c2e0
TreeDeleteD9C2* TreeDeleteD9C2::FUN_00d9c2e0(unsigned char flags)
{
    m_ppVirtualMethodTable = DAT_010d40a4;
    FUN_00d9be30();
    m_kNodeCollection.ClearBuffers();
    if (flags & 1) {
        AllocHolder* holder = FUN_00c85750();
        reinterpret_cast<TreeDeleteAllocatorD9C2*>(holder->m_pThreadAllocator)->Deallocate(this, 0x80);
    }
    return this;
}
