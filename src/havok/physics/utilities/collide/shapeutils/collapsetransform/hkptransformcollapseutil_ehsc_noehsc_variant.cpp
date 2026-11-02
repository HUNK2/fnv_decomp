
// src/havok/physics/utilities/collide/shapeutils/collapsetransform/hkptransformcollapseutil_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/collide/shapeutils/collapsetransform/hkptransformcollapseutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/collide/shapeutils/collapsetransform/hkptransformcollapseutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/collide/shapeutils/collapsetransform/hkptransformcollapseutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct ShapeRefArray
{
    int* refs;
    int count;
};
struct ShapeData
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void FUN_00d738f0(int);
    void FUN_00d74a20();
    ShapeData* FUN_00d74b20(ShapeRefArray* refs);
};
struct FUN_00d74980_Class
{
    int* refs;
    int count;
    int FindMappedValue(int value);
};
// RunContextOperation — __cdecl (caller pops its arguments).
//
// Builds a 12-byte context object on the stack, initializes it to
// (0, 0, 0x80000000), runs its setup pass, resets it, then delegates to the
// helper FUN_00d739f0 and stores its result through the caller's out pointer.
// Finally the context's cleanup pass runs and the function returns 0.
struct FUN_00d74420_Context
{
    int m_kPointA;  // +0x00
    int m_kPointB;  // +0x04
    int m_iThirdValue;  // +0x08, initialized to 0x80000000
    void FUN_00d738f0(int value);
    void FUN_00d74a20();
    void FUN_00d74aa0();
};
int FUN_00d739f0(int a1, int a2, FUN_00d74420_Context* ctx, int a3);
int RunContextOperation(int a1, int a2, int a3, int* out);
class hkMemoryAllocatorD748
{
  public:
    virtual ~hkMemoryAllocatorD748() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterD748
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD748* m_pStreamAllocator;
    hkMemoryAllocatorD748& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD748& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);
template <class T> __forceinline void constructWithCopyD748(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <class T> class hkArrayD748
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD748() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayD748() throw()
    {
        hkMemoryAllocatorD748& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorD748& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyD748(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};
class hkpEntityD748;
int __cdecl RemapCollisionShapes(hkArrayD748<hkpEntityD748*>& kEntities, int iA, int iB) throw();
int __cdecl FUN_00d748d0(hkpEntityD748* pkEntity, int iA, int iB) throw();
struct D749Entry
{
    int m_key0;
    int m_uiFilterValue;
    int m_key1;
};
struct FUN_00c90510_Obj
{
    void FUN_00c90510();
};
struct hkReferencedObject
{
    void removeReference();
};
class D749Table
{
  public:
    D749Entry* m_data;
    int m_uiItemCount;

    int SetEntryValue(int key, int value);
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_and_ps(__m128, __m128);
struct Shp_d74480;
struct Alloc_d74480
{
    virtual void unk00();
    virtual void* allocate(int size);
    virtual void unk08();
    virtual void unk0c();
    virtual void deallocate(void* p, int size);
};
struct Router_d74480
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Alloc_d74480* m_pStreamAllocator;
    Alloc_d74480& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace fnvc_adapt {
Router_d74480* __cdecl FUN_00c85750();
}
void __cdecl ResizeAudioStream(Alloc_d74480*, void*, int);
struct Shp_d74480
{
    void* vtbl;
    unsigned short GetAllocationSize;
    unsigned short refCount;
    int unk08;
    int type;
    void FUN_00c90510();
    void FUN_00c905b0();
    Shp_d74480* FUN_00cf5640(Shp_d74480** shapes, int count, int flag);
    Shp_d74480* FUN_00cf5990(Shp_d74480* child, void* transform);
    Shp_d74480* FUN_00d5d7a0(Shp_d74480* child, void* translation, int flag);
    void FUN_00c9e340(int type, float radius, Shp_d74480* child, int flag);
};
struct CacheEnt_d74480
{
    Shp_d74480* source;
    Shp_d74480* replacement;
    int unk08;
};
struct Cache_d74480
{
    CacheEnt_d74480* data;
    int count;
    int capacity;
    void SetEntryValue(Shp_d74480* source, Shp_d74480* replacement);
};
struct ChildInfo_d74480
{
    Shp_d74480* shape;
    int unk04;
    int unk08;
    int unk0c;
};
struct Cont_d74480
{
    virtual void unk00();
    virtual int count();
    int unk04;
};
struct List_d74480 : Shp_d74480
{
    Cont_d74480 container;
    ChildInfo_d74480* children;
};
struct Convex_d74480 : Shp_d74480
{
    float radius;
    int unk14;
    Shp_d74480* child;
    int unk1c;
    __m128 translation;
};
struct Xform_d74480 : Shp_d74480
{
    int unk10;
    Shp_d74480* child;
    int unk18;
    int unk1c;
    __m128 unk20;
    __m128 transform;
};
extern int DAT_010d0e5c;
extern __m128 DAT_010c4c10;
struct Arr_d74480
{
    Shp_d74480** data;
    int size;
    int capacity;
};
Shp_d74480* __cdecl FUN_00d739f0(Shp_d74480*, void*, Cache_d74480*, void*);
Shp_d74480* __cdecl ProcessShape(Shp_d74480* shape, void* context, Cache_d74480* cache, void* settings);
struct hkShapeEntryD748
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkReferencedObject* m_pCollisionShape;
};
struct hkShapeEntryArrayD748
{
    hkShapeEntryD748** m_data;
    int m_iElementCount;
};
struct hkShapeOutputD748
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void FUN_00d73400() throw();
};
struct hkShapeMapD748
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkShapeMapD748* FUN_00d74b20(hkShapeEntryArrayD748* refs) throw();
    void FUN_00d74aa0() throw();
};
hkReferencedObject* __cdecl ProcessShape(hkReferencedObject* shape, void* context, hkShapeMapD748* map,
                                         hkShapeOutputD748* out) throw();
int __cdecl RemapCollisionShapes(hkShapeEntryArrayD748* refs, void* context, hkShapeOutputD748* out);

struct ShapeD738;
struct ShapeContainerD738
{
    virtual ~ShapeContainerD738();
    virtual int GetNumChildShapes() const;
};
struct ChildInfoD738
{
    ShapeD738* m_pCollisionShape;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
};
struct ShapeD738
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_type;
};
struct ListShapeD738 : ShapeD738
{
    ShapeContainerD738 m_container;
    int m_unk14;
    ChildInfoD738* m_kChildInfoList;
};
struct BvShapeD738 : ShapeD738
{
    int m_unk10;
    ShapeD738* m_pContainedShape;
};
struct WrapperShapeD738 : ShapeD738
{
    int m_unk10;
    int m_unk14;
    ShapeD738* m_pContainedShape;
};
struct EntryD738
{
    int m_pCollisionShape;
    int m_unk04;
    int m_iObjectReferenceCount;
};

static __declspec(noinline) void FUN_00d737d0(ShapeD738* shape, hkArrayD748<ShapeD738*>* out)
{
    switch (shape->m_type)
    {
    case 9: {
        ListShapeD738* list = static_cast<ListShapeD738*>(shape);
        for (int i = 0; i < list->m_container.GetNumChildShapes(); i++)
            out->AddBack(list->m_kChildInfoList[i].m_pCollisionShape);
    }
    break;
    case 11:
        out->AddBack(static_cast<WrapperShapeD738*>(shape)->m_pContainedShape);
        break;
    case 12:
        out->AddBack(static_cast<WrapperShapeD738*>(shape)->m_pContainedShape);
        break;
    case 15:
        out->AddBack(static_cast<BvShapeD738*>(shape)->m_pContainedShape);
        break;
    }
}

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

static __forceinline int indexOfD738(ShapeData* self, int value)
{
    for (int i = 0; i < self->m_kPointB; i++)
        if (((EntryD738*)self->m_kPointA)[i].m_pCollisionShape == value)
            return i;
    return -1;
}

static __forceinline void addShapeD738(ShapeData* self, int value)
{
    EntryD738 e;
    e.m_pCollisionShape = value;
    e.m_unk04 = 0;
    e.m_iObjectReferenceCount = 1;
    hkMemoryAllocatorD748& kAlloc = FUN_00c85750().heap();
    if (self->m_kPointB == (self->m_iThirdValue & 0x3fffffff))
        ResizeAudioStream(&kAlloc, self, sizeof(EntryD738));
    new ((EntryD738*)self->m_kPointA + self->m_kPointB) EntryD738(e);
    self->m_kPointB++;

    ((FUN_00c90510_Obj*)value)->FUN_00c90510();

    hkArrayD748<ShapeD738*> children;
    FUN_00d737d0((ShapeD738*)value, &children);
    for (int i = 0; i < children.m_iElementCount; i++)
        self->FUN_00d738f0((int)children.m_data[i]);
}

// @fnv 0x00d738f0
void ShapeData::FUN_00d738f0(int value)
{
    int index = indexOfD738(this, value);
    if (index >= 0)
    {
        ((EntryD738*)m_kPointA)[index].m_iObjectReferenceCount++;
        return;
    }
    addShapeD738(this, value);
}

#include <math.h>
namespace CollapseSIMD {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" void _mm_store_ps(float*, __m128);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_and_ps(__m128, __m128);
}
typedef CollapseSIMD::__m128 hkQuadReal;
class hkBool
{
  public:
    inline hkBool()
    {}
    inline hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }

  private:
    char m_cBooleanValue;
};
class VectorComponentValue
{
  public:
    VectorComponentValue(const hkQuadReal& x) : m_vValue(x)
    {}
    VectorComponentValue()
    {}
    operator float() const
    {
        float s;
        CollapseSIMD::_mm_store_ss(&s, m_vValue);
        return s;
    }
    const hkQuadReal& getQuad() const
    {
        return m_vValue;
    }

  private:
    hkQuadReal m_vValue;
};
struct hkTransform;
class hkVector4
{
  public:
    __forceinline hkVector4()
    {}
    __forceinline hkVector4(float x, float y, float z, float w);
    __forceinline hkVector4(const hkVector4& v);
    __forceinline void operator=(const hkVector4& v);
    __forceinline float& operator()(int a);
    __forceinline const float& operator()(int a) const;
    __forceinline void setZero4();
    __forceinline VectorComponentValue dot3(const hkVector4& a) const;
    __forceinline VectorComponentValue length3() const;
    void FUN_00c7f640(const hkTransform*, const hkVector4*);
    void FUN_00c7f700(const class hkRotation&, const hkVector4&);
    __forceinline void _setTransformedPos(const hkTransform& t, const hkVector4& b);
    hkQuadReal m_vComponents;
};
inline hkVector4::hkVector4(float x, float y, float z, float w)
{
    m_vComponents = CollapseSIMD::_mm_setr_ps(x, y, z, w);
}
inline hkVector4::hkVector4(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}
inline void hkVector4::operator=(const hkVector4& v)
{
    m_vComponents = v.m_vComponents;
}
inline void hkVector4::setZero4()
{
    m_vComponents = CollapseSIMD::_mm_setzero_ps();
}
inline VectorComponentValue hkVector4::dot3(const hkVector4& a) const
{
    hkQuadReal x2 = CollapseSIMD::_mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = CollapseSIMD::_mm_add_ss(CollapseSIMD::_mm_shuffle_ps(x2, x2, 0x55), x2);
    return CollapseSIMD::_mm_add_ss(CollapseSIMD::_mm_shuffle_ps(x2, x2, 0xaa), xySum);
}
inline VectorComponentValue hkVector4::length3() const
{
    return CollapseSIMD::_mm_sqrt_ss(this->dot3(*this).getQuad());
}
inline float& hkVector4::operator()(int a)
{
    return reinterpret_cast<float*>(&m_vComponents)[a];
}
inline const float& hkVector4::operator()(int a) const
{
    return reinterpret_cast<const float*>(&m_vComponents)[a];
}
class hkMatrix3
{
  public:
    __forceinline hkVector4& getColumn(int i);
    __forceinline const hkVector4& getColumn(int i) const;
    __forceinline float& operator()(int r, int c);
    __forceinline void setZero();
    __forceinline void setIdentity();
    inline void operator=(const hkMatrix3& a);
    hkVector4 m_kColumn0, m_kColumn1, m_kColumn2;
};
inline hkVector4& hkMatrix3::getColumn(int x)
{
    return (&m_kColumn0)[x];
}
inline const hkVector4& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
inline float& hkMatrix3::operator()(int r, int c)
{
    return getColumn(c)(r);
}
inline void hkMatrix3::operator=(const hkMatrix3& a)
{
    m_kColumn0 = a.getColumn(0);
    m_kColumn1 = a.getColumn(1);
    m_kColumn2 = a.getColumn(2);
}
inline void hkMatrix3::setZero()
{
    hkVector4 zero;
    zero.setZero4();
    getColumn(0) = zero;
    getColumn(1) = zero;
    getColumn(2) = zero;
}
inline void hkMatrix3::setIdentity()
{
    setZero();
    float one = 1.0f;
    (*this)(0, 0) = one;
    (*this)(1, 1) = one;
    (*this)(2, 2) = one;
}
class hkRotation : public hkMatrix3
{
  public:
    hkBool IsOrthonormal(float) const;
    hkBool FUN_00cb2d70() const;
    hkBool FUN_00cd4e00(const hkRotation&, float) const;
};
struct hkTransform
{
    __forceinline hkTransform()
    {}
    __forceinline hkTransform(const hkTransform& t);
    __forceinline hkRotation& getRotation();
    __forceinline const hkRotation& getRotation() const;
    __forceinline hkVector4& getTranslation();
    __forceinline const hkVector4& getTranslation() const;
    __forceinline void SetBodyOrientation(const hkRotation& r);
    __forceinline void setTranslation(const hkVector4& t);
    __forceinline void setIdentity();
    hkBool FUN_00cb2160(const hkTransform&, float) const;
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};
inline hkRotation& hkTransform::getRotation()
{
    return m_rotation;
}
inline const hkRotation& hkTransform::getRotation() const
{
    return m_rotation;
}
inline hkVector4& hkTransform::getTranslation()
{
    return m_vTranslation;
}
inline const hkVector4& hkTransform::getTranslation() const
{
    return m_vTranslation;
}
inline void hkTransform::SetBodyOrientation(const hkRotation& r)
{
    m_rotation = r;
}
inline void hkTransform::setTranslation(const hkVector4& t)
{
    m_vTranslation = t;
}
inline void hkTransform::setIdentity()
{
    m_rotation.setIdentity();
    m_vTranslation.setZero4();
}
inline hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4 r0 = t.m_rotation.getColumn(0);
    const hkVector4 r1 = t.m_rotation.getColumn(1);
    const hkVector4 r2 = t.m_rotation.getColumn(2);
    const hkVector4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}
__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    hkQuadReal b0 = CollapseSIMD::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0);
    hkQuadReal r0 = CollapseSIMD::_mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    hkQuadReal b1 = CollapseSIMD::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    hkQuadReal r1 = CollapseSIMD::_mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    hkQuadReal b2 = CollapseSIMD::_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    hkQuadReal r2 = CollapseSIMD::_mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = CollapseSIMD::_mm_add_ps(CollapseSIMD::_mm_add_ps(r0, r1),
                                             CollapseSIMD::_mm_add_ps(r2, t.getTranslation().m_vComponents));
}
extern hkTransform DAT_01268370;
extern int DAT_010d0e5c;
extern float DAT_011b153c;
extern const double DAT_01032980;
void FUN_00c908c0(void*, void*, int, int);

__forceinline hkMemoryAllocatorD748& heapAllocator()
{
    return FUN_00c85750().heap();
}
struct hkTypeIsPod
{
};
struct HavokArrayUtilities
{
    template <class T> static __forceinline void construct(T*, int, hkTypeIsPod)
    {}
    template <class T> static __forceinline void destruct(T*, int, hkTypeIsPod)
    {}
    template <class T> static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, hkTypeIsPod)
    {
        for (int i = 0; i < n; ++i)
            t[i] = tcopy;
    }
};
template <class T> class hkArrayBase739
{
  public:
    enum
    {
        DONT_DEALLOCATE_FLAG = 0x80000000,
        CAPACITY_MASK = 0x3fffffff
    };
    __forceinline hkArrayBase739() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {}
    __forceinline ~hkArrayBase739()
    {}
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void clear()
    {
        HavokArrayUtilities::destruct(m_data, m_iElementCount, hkTypeIsPod());
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(hkMemoryAllocatorD748& alloc)
    {
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocatorD748& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(hkMemoryAllocatorD748& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        HavokArrayUtilities::destruct(m_data + n, m_iElementCount - n, hkTypeIsPod());
        HavokArrayUtilities::construct(m_data + m_iElementCount, n - m_iElementCount, hkTypeIsPod());
        m_iElementCount = n;
    }
    __forceinline void _pushBack(hkMemoryAllocatorD748& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        HavokArrayUtilities::constructWithCopy(m_data + m_iElementCount, 1, t, hkTypeIsPod());
        m_iElementCount++;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <class T> class hkArray739 : public hkArrayBase739<T>
{
  public:
    __forceinline hkArray739()
    {}
    __forceinline ~hkArray739()
    {
        ClearAndRelease();
    }
    __forceinline void ClearAndRelease()
    {
        this->_clearAndDeallocate(heapAllocator());
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        this->_setSize(heapAllocator(), n);
    }
    __forceinline void AddBack(const T& t)
    {
        this->_pushBack(heapAllocator(), t);
    }
};
struct FloatArrayDescriptor
{
    const float* m_kVertices;
    int m_iStridedVertexCount;
    int m_iVertexStride;
};
class hkpShape
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags, m_sReferenceCount;
    int m_ulUserData, m_type;
    int getType() const
    {
        return m_type;
    }
    void FUN_00c90510() const;
    void FUN_00c905b0() const;
};
__forceinline void* shapeNew(int nbytes)
{
    hkpShape* b = static_cast<hkpShape*>(heapAllocator().AllocateMemoryBlock(nbytes));
    b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
    return b;
}
class hkpConvexShape : public hkpShape
{
  public:
    float m_fSphereRadius;
    float getRadius() const
    {
        return m_fSphereRadius;
    }
};
class hkpTransformShape : public hkpShape
{
  public:
    int m_10;
    const hkpShape* m_pContainedShape;
    int m_18, m_1c, m_20, m_24, m_28, m_2c;
    hkTransform m_kMotionTransform;
    const hkTransform& getTransform() const
    {
        return m_kMotionTransform;
    }
    const hkpShape* GetShapeForKey() const
    {
        return m_pContainedShape;
    }
    hkpTransformShape* FUN_00cf5990(const hkpShape*, const hkTransform*);
};
class hkpConvexTransformShape : public hkpConvexShape
{
  public:
    int m_14;
    const hkpConvexShape* m_pContainedShape;
    int m_iChildShapeSize;
    hkTransform m_kMotionTransform;
    const hkTransform& getTransform() const
    {
        return m_kMotionTransform;
    }
    const hkpConvexShape* GetShapeForKey() const
    {
        return m_pContainedShape;
    }
    hkpConvexTransformShape* FUN_00d5d7a0(const hkpConvexShape*, const hkTransform*, int);
};
class hkpConvexTranslateShape : public hkpConvexShape
{
  public:
    int m_14;
    const hkpConvexShape* m_pContainedShape;
    int m_iChildShapeSize;
    hkVector4 m_vTranslation;
    const hkVector4& getTranslation() const
    {
        return m_vTranslation;
    }
    const hkpConvexShape* GetShapeForKey() const
    {
        return m_pContainedShape;
    }
    void FUN_00c9e340(int, float, const hkpConvexShape*, int);
    __forceinline hkpConvexTranslateShape* init(const hkpConvexShape* child, const hkVector4& translation)
    {
        FUN_00c9e340(11, child->m_fSphereRadius, child, 1);
        m_ppVirtualMethodTable = &DAT_010d0e5c;
        m_vTranslation.m_vComponents = CollapseSIMD::_mm_and_ps(
            translation.m_vComponents, reinterpret_cast<const CollapseSIMD::__m128&>(DAT_010c4c10));
        m_iChildShapeSize = 0;
        return this;
    }
};
class hkpCapsuleShape : public hkpConvexShape
{
  public:
    int m_14, m_18, m_1c;
    hkVector4 m_kVertexA, m_kVertexB;
    const hkVector4* GetIndexedVertices() const
    {
        return &m_kVertexA;
    }
    hkpCapsuleShape* FUN_00d22590(const hkVector4&, const hkVector4&, float);
};
class hkpCylinderShape : public hkpConvexShape
{
  public:
    int m_14, m_18, m_1c;
    hkVector4 m_kVertexA, m_kVertexB;
    const hkVector4* GetIndexedVertices() const
    {
        return &m_kVertexA;
    }
    float FUN_00d571a0() const;
    hkpCylinderShape* FUN_00d57aa0(const hkVector4&, const hkVector4&, float, float);
};
class hkpConvexVerticesShape : public hkpConvexShape
{
  public:
    void FUN_00d59200(hkArray739<hkVector4>&) const;
    const hkArray739<hkVector4>& FUN_00d58d50() const;
    hkpConvexVerticesShape* FUN_00d59bd0(const FloatArrayDescriptor&, const hkArray739<hkVector4>&, float);
};
class hkpBoxShape : public hkpConvexShape
{
  public:
    int m_14, m_18, m_1c;
    hkVector4 m_vHalfExtents;
    const hkVector4& getHalfExtents() const
    {
        return m_vHalfExtents;
    }
    hkpBoxShape* SetExtentsAndRadius(const hkVector4&, float);
};
class hkpShapeContainer
{
  public:
    virtual ~hkpShapeContainer();
    virtual int GetNumChildShapes() const;
};
struct hkpListChildInfo
{
    const hkpShape* m_pCollisionShape;
    int m_iFilter, m_iShapeKey, m_iChildShapeCount;
};
class hkpListShape : public hkpShape
{
  public:
    hkpShapeContainer m_container;
    int m_14;
    hkArray739<hkpListChildInfo> m_kChildInfoList;
    const hkpShape* getChildShapeInl(int i) const
    {
        return m_kChildInfoList[i].m_pCollisionShape;
    }
    hkpListShape* FUN_00cf5640(const hkpShape* const*, int, int);
};
struct Options
{
    int m_iFirstOptionValue, m_iSecondOptionValue;
    hkBool m_bOptionFlag;
};
struct Results
{
    int m_iFirstResult, m_iSecondResult, m_iThirdResult, m_numPropagatedTransformsInLists;
};
__forceinline void TransformPointArray(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                       hkVector4* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
// @fnv 0x00d739f0
const hkpShape* FUN_00d739f0(const hkpShape* transformShape, const Options& options, D749Table& sharedShapeData,
                             Results& resultsOut)
{
    const int transformShapeType = transformShape->getType();
    hkTransform parentFromChild;
    const hkpShape* childShape = 0;
    switch (transformShapeType)
    {
    case 15: {
        const hkpTransformShape* tformshape = static_cast<const hkpTransformShape*>(transformShape);
        parentFromChild = tformshape->getTransform();
        childShape = tformshape->GetShapeForKey();
        break;
    }
    case 12: {
        const hkpConvexTransformShape* ctformshape = static_cast<const hkpConvexTransformShape*>(transformShape);
        parentFromChild = ctformshape->getTransform();
        childShape = ctformshape->GetShapeForKey();
        break;
    }
    case 11: {
        const hkpConvexTranslateShape* ctlateshape = static_cast<const hkpConvexTranslateShape*>(transformShape);
        parentFromChild.setIdentity();
        parentFromChild.setTranslation(ctlateshape->getTranslation());
        childShape = ctlateshape->GetShapeForKey();
        break;
    }
    default:
        transformShape->FUN_00c90510();
        return transformShape;
    }
    const int childShapeType = childShape->getType();
    if (childShapeType == 1)
        parentFromChild.SetBodyOrientation(DAT_01268370.getRotation());
    if (parentFromChild.FUN_00cb2160(DAT_01268370, 1e-3f))
    {
        resultsOut.m_iSecondResult++;
        childShape->FUN_00c90510();
        sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(childShape));
        return childShape;
    }
    bool allowChangesToChildShape = true;
    switch (options.m_iFirstOptionValue)
    {
    case 0:
        allowChangesToChildShape = true;
        break;
    case 1:
        allowChangesToChildShape = false;
        break;
    case 2:
        allowChangesToChildShape =
            reinterpret_cast<FUN_00d74980_Class&>(sharedShapeData).FindMappedValue(reinterpret_cast<int>(childShape)) <
            options.m_iSecondOptionValue;
        break;
    }
    if (childShapeType == 9)
    {
        const hkpListShape* listShape = static_cast<const hkpListShape*>(childShape);
        if (!options.m_bOptionFlag && allowChangesToChildShape)
        {
            resultsOut.m_numPropagatedTransformsInLists++;
            hkArray739<const hkpShape*> newChildren;
            for (int i = 0; i < listShape->m_container.GetNumChildShapes(); i++)
            {
                const hkpShape* grandChildShape = listShape->getChildShapeInl(i);
                hkpTransformShape* wrapperMem = static_cast<hkpTransformShape*>(shapeNew(0x70));
                const hkpShape* childTransformShape = wrapperMem->FUN_00cf5990(grandChildShape, &parentFromChild);
                const hkpShape* collapsedGrandChild =
                    FUN_00d739f0(childTransformShape, options, sharedShapeData, resultsOut);
                newChildren.AddBack(collapsedGrandChild);
                childTransformShape->FUN_00c905b0();
            }
            hkpListShape* newListMem = static_cast<hkpListShape*>(shapeNew(0x70));
            hkpListShape* newListShape = newListMem->FUN_00cf5640(newChildren.begin(), newChildren.GetLogicalSize(), 1);
            for (int n = 0; n < newChildren.GetLogicalSize(); n++)
                newChildren[n]->FUN_00c905b0();
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(newListShape));
            return newListShape;
        }
        transformShape->FUN_00c90510();
        return transformShape;
    }
    if (allowChangesToChildShape)
    {
        switch (childShapeType)
        {
        case 5: {
            const hkpCapsuleShape* childCapsuleShape = static_cast<const hkpCapsuleShape*>(childShape);
            const hkVector4* childA = &childCapsuleShape->GetIndexedVertices()[0];
            const hkVector4* childB = &childCapsuleShape->GetIndexedVertices()[1];
            const float radius = childCapsuleShape->getRadius();
            hkVector4 parentA;
            parentA.FUN_00c7f640(&parentFromChild, childA);
            hkVector4 parentB;
            parentB.FUN_00c7f640(&parentFromChild, childB);
            hkpCapsuleShape* newCapsuleMem = static_cast<hkpCapsuleShape*>(shapeNew(0x40));
            hkpCapsuleShape* newCapsule = newCapsuleMem->FUN_00d22590(parentA, parentB, radius);
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(newCapsule));
            resultsOut.m_iFirstResult++;
            return newCapsule;
        }
        case 2: {
            const hkpCylinderShape* childCylinderShape = static_cast<const hkpCylinderShape*>(childShape);
            const hkVector4* childA = &childCylinderShape->GetIndexedVertices()[0];
            const hkVector4* childB = &childCylinderShape->GetIndexedVertices()[1];
            const float cylRadius = childCylinderShape->FUN_00d571a0();
            const float radius = childCylinderShape->getRadius();
            hkVector4 parentA;
            parentA.FUN_00c7f640(&parentFromChild, childA);
            hkVector4 parentB;
            parentB.FUN_00c7f640(&parentFromChild, childB);
            hkpCylinderShape* newCylinderMem = static_cast<hkpCylinderShape*>(shapeNew(0x60));
            hkpCylinderShape* newCylinder = newCylinderMem->FUN_00d57aa0(parentA, parentB, cylRadius, radius);
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(newCylinder));
            resultsOut.m_iFirstResult++;
            return newCylinder;
        }
        case 6: {
            const hkpConvexVerticesShape* childCVShape = static_cast<const hkpConvexVerticesShape*>(childShape);
            hkArray739<hkVector4> vertices;
            childCVShape->FUN_00d59200(vertices);
            TransformPointArray(parentFromChild, vertices.begin(), vertices.GetLogicalSize(), vertices.begin());
            FloatArrayDescriptor newverts;
            newverts.m_iStridedVertexCount = vertices.GetLogicalSize();
            newverts.m_iVertexStride = 16;
            newverts.m_kVertices = &vertices[0](0);
            const hkArray739<hkVector4>& planes = childCVShape->FUN_00d58d50();
            hkArray739<hkVector4> newplanes;
            newplanes.SetSizeAndGrow(planes.GetLogicalSize());
            hkVector4 pivotShift(parentFromChild.getTranslation());
            for (int p = 0; p < planes.GetLogicalSize(); p++)
            {
                hkVector4 plane;
                CollapseSIMD::_mm_store_ps(reinterpret_cast<float*>(&plane.m_vComponents), planes[p].m_vComponents);
                const float newDist = plane(3) - pivotShift.dot3(plane);
                plane.FUN_00c7f700(parentFromChild.getRotation(), plane);
                plane(3) = newDist;
                newplanes[p] = plane;
            }
            hkpConvexVerticesShape* newCVShapeMem = static_cast<hkpConvexVerticesShape*>(shapeNew(0x70));
            hkpConvexVerticesShape* newCVShape =
                newCVShapeMem->FUN_00d59bd0(newverts, newplanes, childCVShape->getRadius());
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(newCVShape));
            resultsOut.m_iFirstResult++;
            return newCVShape;
        }
        case 4: {
            const double& tol = DAT_01032980;
            if (!(parentFromChild.getRotation().IsOrthonormal(1e-3f) && parentFromChild.getRotation().FUN_00cb2d70()))
                break;
            if (parentFromChild.getRotation().FUN_00cd4e00(DAT_01268370.getRotation(), 1e-3f))
                break;
            bool failedA = false;
            bool failedB = false;
            int map[3];
            for (int i = 0; i < 3; i++)
            {
                const hkVector4& axisRot = parentFromChild.getRotation().getColumn(i);
                bool passedA1 = false;
                for (int j = 0; j < 3; j++)
                {
                    const bool testA0 = fabsf(axisRot(j)) < tol;
                    const bool testA1 = fabsf(fabsf(axisRot(j)) - 1.0f) < tol;
                    if (!testA0 && !testA1)
                    {
                        failedA = true;
                        break;
                    }
                    if (testA1)
                    {
                        map[j] = i;
                        passedA1 = true;
                    }
                }
                if (!passedA1)
                    failedA = true;
                if (failedA)
                    break;
                float sum = 0.0f;
                for (int j = 0; j < 3; j++)
                    sum += fabsf(axisRot(j));
                failedB = !(sum - 1.0f < tol);
                if (failedB)
                    break;
            }
            if (failedA || failedB)
                break;
            const hkpBoxShape* childBoxShape = static_cast<const hkpBoxShape*>(childShape);
            const hkVector4& halfExtents = childBoxShape->getHalfExtents();
            hkVector4 newHalfExtents(halfExtents(map[0]), halfExtents(map[1]), halfExtents(map[2]), 0.0f);
            hkpBoxShape* newBoxShapeMem = static_cast<hkpBoxShape*>(shapeNew(0x30));
            hkpBoxShape* newBoxShape = newBoxShapeMem->SetExtentsAndRadius(newHalfExtents, DAT_011b153c);
            if (parentFromChild.getTranslation().length3() < tol)
            {
                sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape),
                                              reinterpret_cast<int>(newBoxShape));
                resultsOut.m_iFirstResult++;
                return newBoxShape;
            }
            hkpConvexTranslateShape* newShapeMem = static_cast<hkpConvexTranslateShape*>(shapeNew(0x30));
            hkpConvexTranslateShape* pRemappedShape = newShapeMem->init(newBoxShape, parentFromChild.getTranslation());
            newBoxShape->FUN_00c905b0();
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(pRemappedShape));
            resultsOut.m_iThirdResult++;
            return pRemappedShape;
        }
        }
    }
    switch (childShapeType)
    {
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 18: {
        const hkpConvexShape* childConvexShape = static_cast<const hkpConvexShape*>(childShape);
        hkBool translateOnly = parentFromChild.getRotation().FUN_00cd4e00(DAT_01268370.getRotation(), 1e-3f);
        if (translateOnly && transformShapeType != 11)
        {
            hkpConvexTranslateShape* newShapeMem = static_cast<hkpConvexTranslateShape*>(shapeNew(0x30));
            hkpConvexTranslateShape* pRemappedShape =
                newShapeMem->init(childConvexShape, parentFromChild.getTranslation());
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(pRemappedShape));
            resultsOut.m_iThirdResult++;
            return pRemappedShape;
        }
        if (transformShapeType == 15)
        {
            hkpConvexTransformShape* newShapeMem = static_cast<hkpConvexTransformShape*>(shapeNew(0x60));
            hkpConvexTransformShape* pRemappedShape = newShapeMem->FUN_00d5d7a0(childConvexShape, &parentFromChild, 1);
            sharedShapeData.SetEntryValue(reinterpret_cast<int>(transformShape), reinterpret_cast<int>(pRemappedShape));
            resultsOut.m_iThirdResult++;
            return pRemappedShape;
        }
    }
    }
    transformShape->FUN_00c90510();
    return transformShape;
}
