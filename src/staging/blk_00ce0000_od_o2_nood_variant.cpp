
// src/staging/blk_00ce0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00ce0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

// src/staging/blk_00ce0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

struct __declspec(align(16)) SortElem16
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

typedef bool(__cdecl* SortElemLess)(const SortElem16& a, const SortElem16& b);

// @fnv 0x00cf83c0
void __cdecl FUN_00cf83c0(SortElem16* pArr, int d, int h, SortElemLess cmpLess)
{
    int i, j;
    SortElem16 str;
begin:
    i = d;
    j = h;
    str = pArr[(d + h) >> 1];
    do
    {
        while (cmpLess(pArr[i], str))
            i++;
        while (cmpLess(str, pArr[j]))
            j--;
        if (j >= i)
        {
            if (j != i)
            {
                SortElem16* pj = &pArr[j];
                SortElem16* pi = &pArr[i];
                SortElem16 tmp = *pj;
                *pj = *pi;
                *pi = tmp;
            }
            j--;
            i++;
        }
    } while (i <= j);
    if (d < j)
    {
        FUN_00cf83c0(pArr, d, j, cmpLess);
    }
    if (i < h)
    {
        d = i;
        goto begin;
    }
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);

struct QuaternionVector
{
    __m128 value;
    __declspec(noinline) void FUN_00c66320(const QuaternionVector* left, const QuaternionVector* right)
    {
        __m128 a = left->value;
        __m128 b = right->value;
        __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
        __m128 imag = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xff), a),
                                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xff), b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        value = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), 0xc4);
    }
};
struct Transform
{
    __m128 translation;
    QuaternionVector rotation;
    __m128 scale;
};
extern const __m128 DAT_010c71e0;
struct Par_00ce2d10
{
    __m128 translation;
    QuaternionVector rotation;
};

template <class T> struct PointerParam
{
    T* p;
    PointerParam(T* q) : p(q)
    {}
    operator T*() const
    {
        return p;
    }
    PointerParam& operator++()
    {
        ++p;
        return *this;
    }
    T* operator->() const
    {
        return p;
    }
};
// @fnv 0x00ce2d10
void __cdecl FUN_00ce2d10(const Transform* parents, PointerParam<const Transform> local, const short* indices,
                          int count, Transform* output)
{
    if (!indices)
    {
        for (int i = 0; i < count; ++i)
        {
            const Transform& l = local[i];
            const Transform& p = parents[i];
            __m128 v = l.translation;
            __m128 q = p.rotation.value;
            __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
            __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
            __m128 cross = _mm_sub_ps(t1, t2);
            __m128 w = _mm_shuffle_ps(q, q, 0xff);
            __m128 product = _mm_mul_ps(v, q);
            __m128 s55 = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
            __m128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), s55);
            __m128 rotated =
                _mm_add_ps(_mm_mul_ps(cross, w), _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v),
                                                            _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q)));
            output[i].translation = _mm_add_ps(_mm_add_ps(rotated, rotated), p.translation);
            output[i].rotation.FUN_00c66320(&p.rotation, &l.rotation);
            output[i].scale = _mm_mul_ps(l.scale, p.scale);
        }
    }
    else
    {
        int i = 0;
        if (i >= count)
            return;
        const Transform* source = local.p;
        do
        {
            short index = indices[i];
            if (index >= 0)
            {
                Transform parent;
                parent.rotation.value = parents[index].rotation.value;
                parent.scale = parents[index].scale;
                parent.translation = parents[index].translation;
                __m128 v = source->translation;
                __m128 q = parent.rotation.value;
                __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9));
                __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2));
                __m128 cross = _mm_sub_ps(t1, t2);
                __m128 w = _mm_shuffle_ps(q, q, 0xff);
                __m128 product = _mm_mul_ps(v, q);
                __m128 s55 = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
                __m128 dot = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), s55);
                __m128 rotated = _mm_add_ps(_mm_mul_ps(cross, w),
                                            _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v),
                                                       _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q)));
                output[index].translation = _mm_add_ps(_mm_add_ps(rotated, rotated), parent.translation);
                output[index].rotation.FUN_00c66320(&parent.rotation, &source->rotation);
                output[index].scale = _mm_mul_ps(source->scale, parent.scale);
                ++source;
            }
            else
            {
                ++source;
            }
            ++i;
        } while (i < count);
    }
}

struct Cls
{
    unsigned short m0, m2, m4, m6;
    __m128 v10, v20, v30, v40, v50, v60;
    Cls* FUN_00ce4a50(Cls* src);
};

// @fnv 0x00ce4a50
Cls* Cls::FUN_00ce4a50(Cls* src)
{
    m0 = src->m0;
    m2 = src->m2;
    m4 = src->m4;
    m6 = src->m6;
    v10 = src->v10;
    v20 = src->v20;
    v30 = src->v30;
    v40 = src->v40;
    v50 = src->v50;
    v60 = src->v60;
    return this;
}

struct SortRec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

typedef char*(__cdecl* SortCmp)(void* tag, const SortRec* lhs, const SortRec* rhs);

void __cdecl FUN_00ce245a(SortRec* a, int low, int high, SortCmp cmp);

// @fnv 0x00cf8510
void __cdecl FUN_00cf8510(SortRec* a, int low, int high, SortCmp cmp)
{
    char tagLo;
    char tagHi;

    for (;;)
    {
        int j = high;
        int i = low;
        __declspec(align(16)) SortRec pivot = a[(i + j) >> 1];
        do
        {
            while (*cmp(&tagLo, &a[i], &pivot))
                ++i;
            while (*cmp(&tagHi, &pivot, &a[j]))
                --j;
            if (j < i)
                break;
            if (j != i)
            {
                SortRec& x = a[j];
                SortRec& y = a[i];
                __declspec(align(16)) SortRec t = x;
                x = y;
                y = t;
            }
            --j;
            ++i;
        } while (i <= j);
        if (low < j)
            FUN_00ce245a(a, low, j, cmp);
        if (i >= high)
            return;
        low = i;
    }
}

namespace fnv_00cfac20 {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned int DAT_0126835c;
extern char DAT_010cc678[];
extern char DAT_010c41f8[];
void* __cdecl FUN_00c85750(void);
struct S00cfac20_Vec
{
    __m128 q;
    void setMin4(const S00cfac20_Vec& a, const S00cfac20_Vec& b)
    {
        q = _mm_min_ps(a.q, b.q);
    }
    void setMax4(const S00cfac20_Vec& a, const S00cfac20_Vec& b)
    {
        q = _mm_max_ps(a.q, b.q);
    }
};
struct S00cfac20_Ray
{
    S00cfac20_Vec from;
    S00cfac20_Vec to;
    S00cfac20_Vec extra;
};
struct S00cfac20_Aabb
{
    S00cfac20_Vec mn;
    S00cfac20_Vec mx;
    void includePoint(const S00cfac20_Vec& p)
    {
        mn.setMin4(mn, p);
        mx.setMax4(mx, p);
    }
};
struct S00cfac20_Builder
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
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
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual int GetLogicalSize();
    virtual void v64();
    virtual void init(S00cfac20_Aabb* bounds, void* mem);
};
struct S00cfac20_Mon
{
    int unk00;
    char* cur;
    int unk08;
    char* end;
};
struct S00cfac20_Stack
{
    char* cur;
    char* alloc(int size)
    {
        char* r = cur;
        cur = r + ((size + 0x7f) & ~0x7f);
        return r;
    }
    void release(char* p)
    {
        cur = p;
    }
};
struct S00cfac20_Grp
{
    void RecordAndDispatch(S00cfac20_Builder* b, S00cfac20_Ray* ray, void* ctx, void* mem, char* out);
    void FUN_00cfac20(S00cfac20_Builder* b, S00cfac20_Ray* rays, int count, void* ctx, char* out);
};
static inline void S00cfac20_timer(const char* name)
{
    S00cfac20_Mon* mon = (S00cfac20_Mon*)TlsGetValue(DAT_0126835c);
    char* p = mon->cur;
    if (p < mon->end)
    {
        *(const char**)p = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        *(unsigned int*)(p + 4) = t;
        p += 0xc;
        mon->cur = p;
    }
}
static __forceinline void S00cfac20_calcAabb(const S00cfac20_Ray* rays, int count, S00cfac20_Aabb& aabb)
{
    S00cfac20_Vec mn;
    mn.setMin4(rays->from, rays->to);
    aabb.mn.q = mn.q;
    aabb.mx.setMax4(rays->from, rays->to);
    const S00cfac20_Ray* p = rays + 1;
    int i = count - 2;
    if (i >= 0)
    {
        do
        {
            mn.setMin4(mn, p->to);
            aabb.mx.setMax4(aabb.mx, p->to);
            mn.setMin4(mn, p->from);
            aabb.mx.setMax4(aabb.mx, p->from);
            ++p;
        } while (--i >= 0);
        aabb.mn.q = mn.q;
    }
}
// @fnv 0x00cfac20
void S00cfac20_Grp::FUN_00cfac20(S00cfac20_Builder* b, S00cfac20_Ray* rays, int count, void* ctx, char* out)
{
    char* dst;
    int j;
    {
        S00cfac20_Mon* mon = (S00cfac20_Mon*)TlsGetValue(DAT_0126835c);
        char* p = mon->cur;
        if (p < mon->end)
        {
            *(const char**)p = DAT_010cc678;
            _ReadWriteBarrier();
            *(volatile unsigned*)&dst = (unsigned)__rdtsc();
            *(unsigned int*)(p + 4) = *(volatile unsigned*)&dst;
            p += 0xc;
            mon->cur = p;
        }
    }
    S00cfac20_Aabb aabb;
    S00cfac20_calcAabb(rays, count, aabb);
    char* mem = ((S00cfac20_Stack*)FUN_00c85750())->alloc(b->GetLogicalSize());
    b->init(&aabb, mem);
    S00cfac20_Ray* r = rays;
    dst = out;
    for (j = count - 1; j >= 0; --j)
    {
        RecordAndDispatch(b, r++, ctx, mem, dst);
        dst += 0x60;
    }
    ((S00cfac20_Stack*)FUN_00c85750())->release(mem);
    {
        S00cfac20_Mon* mon = (S00cfac20_Mon*)TlsGetValue(DAT_0126835c);
        char* p = mon->cur;
        if (p < mon->end)
        {
            *(const char**)p = DAT_010c41f8;
            _ReadWriteBarrier();
            *(volatile unsigned*)&j = (unsigned)__rdtsc();
            *(unsigned int*)(p + 4) = *(volatile unsigned*)&j;
            p += 0xc;
            mon->cur = p;
        }
    }
}
}  // namespace fnv_00cfac20

typedef unsigned short hkUint16;

inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline hkVector4()
    {}
    __forceinline hkVector4(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkReferencedObject
{
    void FUN_00c90510();
    void FUN_00c905b0();
};

template <class T> struct ReferenceCountedPointer
{
    T* m_pRetainedObject;

    __forceinline void operator=(const ReferenceCountedPointer& rp)
    {
        if (rp.m_pRetainedObject)
            rp.m_pRetainedObject->FUN_00c90510();
        if (m_pRetainedObject)
            m_pRetainedObject->FUN_00c905b0();
        m_pRetainedObject = rp.m_pRetainedObject;
    }
};

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);

    template <typename T> __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut * sizeof(T);
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / int(sizeof(T));
        return static_cast<T*>(p);
    }

    template <typename T> __forceinline void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem * sizeof(T));
    }
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;

    __forceinline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

void* __cdecl FUN_00c85750();

__forceinline hkMemoryAllocator& containerHeap()
{
    return static_cast<NineIntegerRecord*>(FUN_00c85750())->heap();
}

void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* array, int reqCapacity, int sizeElem);

template <typename T> __forceinline void hkConstructWithArray(T* t, int n, const T* tcopy)
{
    for (int i = 0; i < n; ++i)
    {
        new (t + i) T(tcopy[i]);
    }
}

template <typename T> __forceinline void hkCopy(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
    {
        dst[i] = src[i];
    }
}

template <typename T> __forceinline void hkConstructWithArray2(T* t, int n, const T* tcopy)
{
    for (int i = 0; i < n; ++i)
    {
        new (t) T(*tcopy);
        ++t;
        ++tcopy;
    }
}

template <typename T> __forceinline void hkCopy2(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; ++i)
    {
        *dst = *src;
        ++dst;
        ++src;
    }
}

template <typename T> struct hkArray
{
    enum
    {
        CAPACITY_MASK = 0x3fffffff,
        DONT_DEALLOCATE_FLAG = 0x80000000
    };

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }

    __forceinline void _copyFromArrayClass(hkMemoryAllocator& alloc, const hkArray& a)
    {
        int oldSize = m_iElementCount;
        int newSize = a.GetLogicalSize();
        int copiedSize = newSize > oldSize ? oldSize : newSize;

        GrowArrayCapacity(alloc, newSize);
        hkCopy(m_data, a.m_data, copiedSize);
        hkConstructWithArray(m_data + copiedSize, newSize - copiedSize, a.m_data + copiedSize);
        m_iElementCount = newSize;
    }

    __forceinline hkArray& operator=(const hkArray& a)
    {
        _copyFromArrayClass(containerHeap(), a);
        return *this;
    }

    __forceinline void _copyFromArrayPod(hkMemoryAllocator& alloc, const hkArray& a)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            {
                alloc._bufFree<T>(m_data, getCapacity());
            }
            int n = a.GetLogicalSize();
            m_data = alloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        hkCopy(m_data, a.m_data, m_iElementCount);
    }
};

struct VectorTriple
{
    hkVector4 a, b, c;
};

struct VertexInfo
{
    hkUint16 m_index0;
    hkUint16 m_index1;
    VectorTriple m_v;
};

struct FaceInfo
{
    hkUint16 m_index0;
    hkUint16 m_index1;
    hkUint16 m_index2;
    hkUint16 m_index3;
    VectorTriple m_kPointA;
    VectorTriple m_kPointB;
};

struct ShapeData
{
    ReferenceCountedPointer<hkReferencedObject> m_kFirstReferencedObject;
    ReferenceCountedPointer<hkReferencedObject> m_kSecondReferencedObject;
    hkArray<VertexInfo> m_kVertices;
    hkArray<FaceInfo> m_faces;
    hkArray<hkUint16> m_ppIndices;
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
    hkVector4 m_kCenterPosition;
    bool m_flag;
    int m_uiItemCount;

    ShapeData& FUN_00ce4ae0(const ShapeData& other);
};

// @fnv 0x00ce4ae0
ShapeData& ShapeData::FUN_00ce4ae0(const ShapeData& other)
{
    m_kFirstReferencedObject = other.m_kFirstReferencedObject;
    m_kSecondReferencedObject = other.m_kSecondReferencedObject;
    m_kVertices = other.m_kVertices;
    m_faces = other.m_faces;
    m_ppIndices._copyFromArrayPod(containerHeap(), other.m_ppIndices);
    m_kMinimumCorner = other.m_kMinimumCorner;
    m_kMaximumCorner = other.m_kMaximumCorner;
    m_kCenterPosition = other.m_kCenterPosition;
    m_flag = other.m_flag;
    m_uiItemCount = other.m_uiItemCount;
    return *this;
}
