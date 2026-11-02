
// src/havok/common/internal/collide/tree/aabbtree/hkaabbtree_gs_nogs_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/internal/collide/tree/aabbtree/hkaabbtree.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

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
struct FUN_00d9be20_cls {
    void __thiscall FUN_00d9be20();
};
struct FUN_00d9bed0_cls {
    void __thiscall FUN_00d9bed0();
};
struct Obj_d9be20 {
    int m0;
    int m4;
    int m8;
    int mc;
    int m10;
    void FUN_00d9be20();
};
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
struct UnsignedShortArray { unsigned short* elements; unsigned int count; unsigned int capacity; };
struct AllocationContext { int unknown00, unknown04, unknown08, unknown0c; void* memory; };
void __cdecl ResizeAudioStream(void* memory, UnsignedShortArray* buffer, unsigned int count);
struct Owner { int unknown00, unknown04, unknown08; UnsignedShortArray buffer; AllocationContext* FUN_00c85750(); unsigned short* AppendElement(unsigned short value); };
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
struct BoundsNode { unsigned short m00,m02,m04,m06,m08,m0A,m0C,m0E,m10,m12; };
struct FUN_00d9a4d0_cls { BoundsNode* __thiscall GetEntryOffset(unsigned short key); };
struct FUN_00d9b450_cls { int m00,m04,m08,m0C,m10,m14,m18; FUN_00d9a4d0_cls m1c; void __thiscall UpdateBoundsNode(BoundsNode* a1,unsigned short a2,unsigned short a3); };
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
void __cdecl AppendElement();
void __cdecl FUN_00d9c2d0(int param_1, unsigned short param_2);
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

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

extern const __m128 DAT_011b6d70;

struct S00d9c610_Vector4 {
    __m128 m_vComponents;
    __forceinline void setAdd4(const S00d9c610_Vector4& a, const S00d9c610_Vector4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(const S00d9c610_Vector4& a) { m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents); }
    __forceinline void setMin4(const S00d9c610_Vector4& a, const S00d9c610_Vector4& b) { m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setMax4(const S00d9c610_Vector4& a, const S00d9c610_Vector4& b) { m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline const float& operator()(int i) const { return m_vComponents.m128_f32[i]; }
};

struct S00d9c610_Aabb {
    S00d9c610_Vector4 m_kMinimumCorner;
    S00d9c610_Vector4 m_kMaximumCorner;
};

struct __declspec(align(16)) S00d9c610_AabbUint32 {
    unsigned int m_kMinimumCorner[3];
    unsigned char m_expansionMin0, m_expansionMin1, m_expansionMin2;
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_expansionMax0, m_expansionMax1, m_expansionMax2;
    unsigned char m_expansionMaxXYZ;
};

__forceinline void S00d9c610_convertToUint32WithClip(const S00d9c610_Vector4& in, const S00d9c610_Vector4& offset, const S00d9c610_Vector4& scale, const S00d9c610_Vector4& minv, const S00d9c610_Vector4& maxv, unsigned int* out)
{
    S00d9c610_Vector4 x;
    x.setAdd4(in, offset);
    x.mul4(scale);
    x.setMin4(x, maxv);
    x.setMax4(x, minv);

    out[0] = static_cast<unsigned int>(fnv_FloatToInt(x(0)));
    out[1] = static_cast<unsigned int>(fnv_FloatToInt(x(1)));
    out[2] = static_cast<unsigned int>(fnv_FloatToInt(x(2)));
    out[3] = static_cast<unsigned int>(fnv_FloatToInt(x(3)));
}

__forceinline void S00d9c610_convertAabbToUint32(const S00d9c610_Aabb& aabb, const S00d9c610_Vector4& offsetLow, const S00d9c610_Vector4& offsetHigh, const S00d9c610_Vector4& scale, S00d9c610_AabbUint32& aabbOut)
{
    S00d9c610_Vector4 maxVal; maxVal.m_vComponents = DAT_011b6d70;
    S00d9c610_convertToUint32WithClip(aabb.m_kMinimumCorner, offsetLow, scale, (const S00d9c610_Vector4&)DAT_01267e30, maxVal, aabbOut.m_kMinimumCorner);
    S00d9c610_convertToUint32WithClip(aabb.m_kMaximumCorner, offsetHigh, scale, (const S00d9c610_Vector4&)DAT_01267e30, maxVal, aabbOut.m_kMaximumCorner);
}

struct S00d9c610_TreeAabb16 {
    unsigned short m_max0, m_max1, m_max2;
    unsigned short m_min0, m_min1, m_min2;
    static __forceinline void convertAabbToTreeSpace(const S00d9c610_AabbUint32& volumeIn, S00d9c610_TreeAabb16& volumeOut)
    {
        volumeOut.m_max0 = (unsigned short)(volumeIn.m_kMaximumCorner[0] >> 15);
        volumeOut.m_min0 = (unsigned short)(volumeIn.m_kMinimumCorner[0] >> 15);
        volumeOut.m_max1 = (unsigned short)(volumeIn.m_kMaximumCorner[1] >> 15);
        volumeOut.m_min1 = (unsigned short)(volumeIn.m_kMinimumCorner[1] >> 15);
        volumeOut.m_max2 = (unsigned short)(volumeIn.m_kMaximumCorner[2] >> 15);
        volumeOut.m_min2 = (unsigned short)(volumeIn.m_kMinimumCorner[2] >> 15);
    }
    static __forceinline void convertAabbToTreeSpace(const S00d9c610_Aabb& volume, const S00d9c610_Vector4& bitOffsetLow, const S00d9c610_Vector4& bitOffsetHigh, const S00d9c610_Vector4& bitScale, S00d9c610_TreeAabb16& volumeOut)
    {
        S00d9c610_AabbUint32 qAabb;
        S00d9c610_convertAabbToUint32(volume, bitOffsetLow, bitOffsetHigh, bitScale, qAabb);
        convertAabbToTreeSpace(qAabb, volumeOut);
    }
};

struct S00d9c610_Node {
    S00d9c610_TreeAabb16 m_iBufferSize;
    union {
        struct { unsigned short m_childIdx0, m_childIdx1; } m_kChildIndices;
        struct { void* m_ulUserData; } m_kLeafData;
    };
    unsigned short m_usNodeValue;
    unsigned short m_iSkipNodeIndex;
    S00d9c610_Node() : m_usNodeValue(0) {}
    void setSkipNodeIdx(unsigned short idx) { m_iSkipNodeIndex = idx; }
    void setParentNodeIdx(unsigned short idx) { m_usNodeValue = idx | (m_usNodeValue & 0x8000); }
    void setLeafData(void* userData) { m_kLeafData.m_ulUserData = userData; m_usNodeValue |= 0x8000; }
};

struct S00d9c610_NodeManager {
    unsigned short AddRecord(S00d9c610_Node*& rootNode, unsigned short& rootIdx, S00d9c610_Node& node);
    S00d9c610_Node* PopGlyphRecord(S00d9c610_Node*& rootNode, unsigned short& rootIdx, unsigned short& newNodeIdx);
    S00d9c610_Node* GetEntryOffset(unsigned short idx);
};

struct S00d9c610_AabbTree {
    void* vtbl;
    unsigned int unk04, unk08, unk0c;
    S00d9c610_Node* m_pAabbRootNode;
    unsigned short m_usManagerValue;
    int m_iNodeCount;
    S00d9c610_NodeManager m_kNodeManager;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    S00d9c610_Vector4 m_kAabbMin;
    S00d9c610_Vector4 m_kAabbMaximum;
    S00d9c610_Vector4 m_kAabbScale;
    void FUN_00d9b580(unsigned short insertPointIdx, unsigned short newLeafIdx, unsigned short scratchNodeIdx);
    unsigned short FUN_00d9c610(const S00d9c610_Aabb& aabb, void* userData);
};

// @fnv 0x00d9c610
unsigned short S00d9c610_AabbTree::FUN_00d9c610(const S00d9c610_Aabb& aabb, void* userData)
{
    S00d9c610_AabbUint32 qAabb;
    S00d9c610_convertAabbToUint32(aabb, m_kAabbMin, m_kAabbMaximum, m_kAabbScale, qAabb);
    unsigned short leafIdx;
    {
        S00d9c610_Node node;
        S00d9c610_TreeAabb16::convertAabbToTreeSpace(qAabb, node.m_iBufferSize);
        node.setLeafData(userData);
        leafIdx = m_kNodeManager.AddRecord(m_pAabbRootNode, m_usManagerValue, node);
    }
    if (m_usManagerValue == 0x7fff)
    {
        S00d9c610_Node* n = m_kNodeManager.GetEntryOffset(leafIdx);
        n->setParentNodeIdx(0x7fff);
        n->setSkipNodeIdx(0x7fff);
        m_pAabbRootNode = n;
        m_usManagerValue = leafIdx;
    }
    else
    {
        unsigned short scratchNodeIdx;
        m_kNodeManager.PopGlyphRecord(m_pAabbRootNode, m_usManagerValue, scratchNodeIdx);
        FUN_00d9b580(m_usManagerValue, leafIdx, scratchNodeIdx);
    }
    m_iNodeCount++;
    return leafIdx;
}
