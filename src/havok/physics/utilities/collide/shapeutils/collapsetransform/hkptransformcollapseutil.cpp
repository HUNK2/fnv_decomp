
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

// Resets the three fields, forwards each ref's value at offset 0x10 to FUN_00d738f0, then calls FUN_00d74a20 and returns this.
// @fnv 0x00d74b20
ShapeData* ShapeData::FUN_00d74b20(ShapeRefArray* refs)
{
    m_kPointA = 0;
    m_kPointB = 0;
    m_iThirdValue = 0x80000000;
    for (int i = 0; i < refs->count; ++i)
        FUN_00d738f0(*(int*)(refs->refs[i] + 0x10));
    FUN_00d74a20();
    return this;
}

struct FUN_00d74980_Class
{
    int* refs;
    int count;
    int FindMappedValue(int value);
};

// Scans the refs array in groups of three and returns the third entry of the first group whose first or second entry equals value, otherwise 0.
// @fnv 0x00d74980
int FUN_00d74980_Class::FindMappedValue(int value)
{
    for (int i = 0; i < count; ++i)
    {
        if (refs[i * 3] == value || refs[i * 3 + 1] == value)
            return refs[i * 3 + 2];
    }

    return 0;
}

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

// @fnv 0x00d74420
int RunContextOperation(int aiArg1, int aiArg2, int aiArg3, int* piOut)
{
    FUN_00d74420_Context ctx;
    ctx.m_kPointA = 0;
    ctx.m_kPointB = 0;
    ctx.m_iThirdValue = 0x80000000;
    ctx.FUN_00d738f0(aiArg1);
    ctx.FUN_00d74a20();
    *piOut = FUN_00d739f0(aiArg1, aiArg2, &ctx, aiArg3);
    ctx.FUN_00d74aa0();
    return 0;
}

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

// Appends pkEntity to a local hkArrayD748 and forwards it with iA and iB to RemapCollisionShapes, returning its result.
// @fnv 0x00d748d0
int __cdecl FUN_00d748d0(hkpEntityD748* pkEntity, int iA, int iB) throw()
{
    hkArrayD748<hkpEntityD748*> kEntities;
    kEntities.AddBack(pkEntity);
    return RemapCollisionShapes(kEntities, iA, iB);
}

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

// Scans the table for an entry matching key in either key field, releases the old value, stores the new value, and returns 0 on success or 1 if not found.
// @fnv 0x00d749c0
int D749Table::SetEntryValue(int key, int value)
{
    int i = 0;
    if (m_uiItemCount > 0)
    {
        do
        {
            if (m_data[i].m_key0 == key || m_data[i].m_uiFilterValue == key)
                goto found;
            ++i;
        } while (i < m_uiItemCount);
    }
    return 1;
found:
    ((FUN_00c90510_Obj*)value)->FUN_00c90510();
    int pOldValue = m_data[i].m_uiFilterValue;
    if (pOldValue)
        ((hkReferencedObject*)pOldValue)->removeReference();
    m_data[i].m_uiFilterValue = value;
    return 0;
}

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

// Recursively processes a shape tree, replacing nodes with cached or newly allocated equivalents and storing results in the cache.
// @fnv 0x00d74480
Shp_d74480* __cdecl ProcessShape(Shp_d74480* shape, void* context, Cache_d74480* cache, void* settings)
{
    for (int i = 0; i < cache->count; ++i)
    {
        if (cache->data[i].source == shape)
        {
            Shp_d74480* found = cache->data[i].replacement;
            if (found)
            {
                found->FUN_00c90510();
                return found;
            }
            break;
        }
    }
    Shp_d74480* result;
    switch (shape->type)
    {
    case 9: {
        List_d74480* list = (List_d74480*)shape;
        int count = list->container.count();
        Arr_d74480 childShapes;
        childShapes.data = 0;
        childShapes.size = 0;
        childShapes.capacity = 0x80000000;
        bool bUnchanged = true;
        for (int i = 0; i < count; ++i)
        {
            Shp_d74480* pChild = list->children[i].shape;
            Shp_d74480* n = ProcessShape(pChild, context, cache, settings);
            Router_d74480* pRouter = fnvc_adapt::FUN_00c85750();
            if (childShapes.size == (childShapes.capacity & 0x3fffffff))
                ResizeAudioStream(&pRouter->heap(), &childShapes, 4);
            childShapes.data[childShapes.size++] = n;
            if (n != pChild)
                bUnchanged = false;
        }
        if (bUnchanged)
        {
            for (int i = 0; i < count; ++i)
                childShapes.data[i]->FUN_00c905b0();
            shape->FUN_00c90510();
            Alloc_d74480& a = fnvc_adapt::FUN_00c85750()->heap();
            childShapes.size = 0;
            if ((childShapes.capacity & 0x80000000) == 0)
                a.deallocate(childShapes.data, (childShapes.capacity & 0x3fffffff) * 4);
            result = shape;
            break;
        }
        Shp_d74480* v = (Shp_d74480*)fnvc_adapt::FUN_00c85750()->heap().allocate(0x70);
        v->GetAllocationSize = 0x70;
        v = v->FUN_00cf5640(childShapes.data, count, 1);
        for (int i = 0; i < count; ++i)
            childShapes.data[i]->FUN_00c905b0();
        cache->SetEntryValue(shape, v);
        result = v;
        Alloc_d74480& a = fnvc_adapt::FUN_00c85750()->heap();
        childShapes.size = 0;
        if ((childShapes.capacity & 0x80000000) == 0)
            a.deallocate(childShapes.data, (childShapes.capacity & 0x3fffffff) * 4);
        break;
    }
    case 15: {
        Xform_d74480* xf = (Xform_d74480*)shape;
        Shp_d74480* pChild = xf->child;
        Shp_d74480* v = ProcessShape(pChild, context, cache, settings);
        Shp_d74480* n = v;
        if (pChild == v)
        {
            v->FUN_00c905b0();
            v = shape;
            shape->FUN_00c90510();
        }
        else
        {
            Shp_d74480* mem = (Shp_d74480*)fnvc_adapt::FUN_00c85750()->heap().allocate(0x70);
            mem->GetAllocationSize = 0x70;
            v = mem->FUN_00cf5990(n, &xf->transform);
            n->FUN_00c905b0();
            cache->SetEntryValue(shape, v);
        }
        result = FUN_00d739f0(v, context, cache, settings);
        v->FUN_00c905b0();
        break;
    }
    case 12: {
        Convex_d74480* cv = (Convex_d74480*)shape;
        Shp_d74480* pChild = cv->child;
        Shp_d74480* v = ProcessShape(pChild, context, cache, settings);
        Shp_d74480* n = v;
        if (pChild == v)
        {
            v->FUN_00c905b0();
            v = shape;
            shape->FUN_00c90510();
        }
        else
        {
            Shp_d74480* mem = (Shp_d74480*)fnvc_adapt::FUN_00c85750()->heap().allocate(0x60);
            mem->GetAllocationSize = 0x60;
            v = mem->FUN_00d5d7a0(n, &cv->translation, 1);
            n->FUN_00c905b0();
            cache->SetEntryValue(shape, v);
        }
        result = FUN_00d739f0(v, context, cache, settings);
        v->FUN_00c905b0();
        break;
    }
    case 11: {
        Convex_d74480* cv = (Convex_d74480*)shape;
        Shp_d74480* v;
        Shp_d74480* pChild = cv->child;
        Shp_d74480* n = ProcessShape(pChild, context, cache, settings);
        if (pChild == n)
        {
            n->FUN_00c905b0();
            v = shape;
            shape->FUN_00c90510();
        }
        else
        {
            Convex_d74480* pNewConvex = (Convex_d74480*)fnvc_adapt::FUN_00c85750()->heap().allocate(0x30);
            pNewConvex->GetAllocationSize = 0x30;
            pNewConvex->FUN_00c9e340(11, ((Convex_d74480*)n)->radius, n, 1);
            pNewConvex->vtbl = &DAT_010d0e5c;
            pNewConvex->translation = _mm_and_ps(cv->translation, DAT_010c4c10);
            pNewConvex->unk1c = 0;
            v = pNewConvex;
            n->FUN_00c905b0();
            cache->SetEntryValue(shape, v);
        }
        result = FUN_00d739f0(v, context, cache, settings);
        v->FUN_00c905b0();
        break;
    }
    default:
        shape->FUN_00c90510();
        result = shape;
        break;
    }
    return result;
}

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

// Remaps each collision shape in refs via ProcessShape, storing results back into the entries and releasing the old references.
// @fnv 0x00d74850
int __cdecl RemapCollisionShapes(hkShapeEntryArrayD748* refs, void* context, hkShapeOutputD748* out)
{
    out->FUN_00d73400();
    hkShapeMapD748 map;
    map.FUN_00d74b20(refs);
    for (int i = 0; i < refs->m_iElementCount; i++)
    {
        hkShapeEntryD748* entry = refs->m_data[i];
        hkReferencedObject* shape = entry->m_pCollisionShape;
        hkReferencedObject* pRemappedShape = ProcessShape(shape, context, &map, out);
        shape->removeReference();
        entry->m_pCollisionShape = pRemappedShape;
    }
    map.FUN_00d74aa0();
    return 0;
}

struct hkpShapeD737;
struct hkpListChildInfoD737
{
    const hkpShapeD737* m_pCollisionShape;
    unsigned int m_uiCollisionFilterData;
    int m_iShapeKey;
    int m_iChildShapeCount;
};
class hkpShapeContainerD737
{
  public:
    virtual ~hkpShapeContainerD737();
    virtual int GetNumChildShapes() const;
};
struct hkpShapeD737
{
    void* m_vtbl;
    int m_usMemSizeAndFlags;
    unsigned int m_ulUserData;
    int m_type;
};
struct hkpListShapeD737 : hkpShapeD737
{
    hkpShapeContainerD737 m_container;
    const hkpShapeD737* m_14;
    hkpListChildInfoD737* m_kChildInfoList;
};
struct hkpSingleD737 : hkpShapeD737
{
    int m_10;
    const hkpShapeD737* m_14;
    const hkpShapeD737* m_18;
};

template <class T> static __forceinline void PushBackD737(hkArrayD748<T>* a, const T& t)
{
    hkMemoryAllocatorD748& kAlloc = FUN_00c85750().heap();
    if (a->m_iElementCount == a->getCapacity())
        ResizeAudioStream(&kAlloc, a, sizeof(T));
    constructWithCopyD748(a->m_data + a->m_iElementCount, 1, t);
    a->m_iElementCount++;
}

// Appends the child shapes of a shape to out: every list child for type 9, or the single child pointer for types 15, 12 and 11.
// @fnv 0x00d737d0
static __declspec(noinline) void FUN_00d737d0(const hkpShapeD737* shape, hkArrayD748<const hkpShapeD737*>* out)
{
    switch (shape->m_type)
    {
    case 9: {
        const hkpListShapeD737* list = (const hkpListShapeD737*)shape;
        for (int i = 0; i < list->m_container.GetNumChildShapes(); i++)
        {
            const hkpShapeD737* child = list->m_kChildInfoList[i].m_pCollisionShape;
            PushBackD737(out, child);
        }
    }
    break;
    case 15: {
        const hkpShapeD737* child = ((const hkpSingleD737*)shape)->m_14;
        PushBackD737(out, child);
    }
    break;
    case 12: {
        const hkpShapeD737* child = ((const hkpSingleD737*)shape)->m_18;
        PushBackD737(out, child);
    }
    break;
    case 11: {
        const hkpShapeD737* child = ((const hkpSingleD737*)shape)->m_18;
        PushBackD737(out, child);
    }
    break;
    }
}

void zz_probe_d737d0(const hkpShapeD737* shape, hkArrayD748<const hkpShapeD737*>* out)
{
    FUN_00d737d0(shape, out);
}

struct D74A20Ref
{
    void FUN_00c905b0();
};

struct D74A20Entry
{
    D74A20Ref* m_kPointA;
    D74A20Ref* m_kPointB;
    int m_uiItemCount;
};

struct D74A20Array
{
    D74A20Entry* m_data;
    int m_iElementCount;
};

// @fnv 0x00d74a20
void ShapeData::FUN_00d74a20()
{
    D74A20Array* array = reinterpret_cast<D74A20Array*>(this);

    int index = array->m_iElementCount - 1;
    if (index < 0)
        return;

    while (index >= 0)
    {
        if (array->m_data[index].m_uiItemCount < 2)
        {
            if (array->m_data[index].m_kPointA != 0)
                array->m_data[index].m_kPointA->FUN_00c905b0();

            if (array->m_data[index].m_kPointB != 0)
                array->m_data[index].m_kPointB->FUN_00c905b0();

            for (int once = 0; once < 1; once++)
            {
                array->m_iElementCount--;
                int n = array->m_iElementCount;
                if (n != index)
                {
                    char* d = reinterpret_cast<char*>(array->m_data);
                    char* src = d + n * 12;
                    d += index * 12;
                    int* dst = reinterpret_cast<int*>(d);
                    int delta = (int)(src - d);
                    int count = 3;
                    do
                    {
                        *dst = *reinterpret_cast<int*>(reinterpret_cast<char*>(dst) + delta);
                        dst++;
                    } while (--count != 0);
                }
            }
        }

        index--;
    }
}

extern "C"
{
    __m128 _mm_setzero_ps(void);
    __m128 _mm_and_ps(__m128, __m128);
}

extern const __m128 g_hkQuadXYZMask;

struct hkVector4
{
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void setXYZ0(const hkVector4& v)
    {
        m_vComponents = _mm_and_ps(v.m_vComponents, g_hkQuadXYZMask);
    }
};

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkRotation
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkBool IsEqualWithinTolerance(const hkRotation& other, float epsilon) const;
    __forceinline void setIdentity()
    {
        hkVector4 zero;
        zero.setZero4();
        m_kColumn0 = zero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1 = zero;
        m_kColumn1(1) = 1.0f;
        m_kColumn2 = zero;
        m_kColumn2(2) = 1.0f;
    }
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
    static const hkTransform s_identity;
    __forceinline static const hkTransform& GetIdentityTransform()
    {
        return s_identity;
    }
    __forceinline hkRotation& getRotation()
    {
        return m_rotation;
    }
    __forceinline const hkRotation& getRotation() const
    {
        return m_rotation;
    }
    __forceinline void setTranslation(const hkVector4& t)
    {
        m_vTranslation = t;
    }
    hkBool IsEqualWithinTolerance(const hkTransform& other, float epsilon) const;
    void SetProduct(const hkTransform& a, const hkTransform& b);
};

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct NineIntegerRecord
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    static NineIntegerRecord& GetMonitorStream();
    __forceinline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct hkBaseObject
{
    virtual ~hkBaseObject();
};

struct CollapseRefObject : hkBaseObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    __forceinline void* operator new(unsigned int nbytes)
    {
        CollapseRefObject* b =
            static_cast<CollapseRefObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    void FUN_00c90510() const;
};

enum CollisionShapeType
{
    HK_SHAPE_CONVEX_TRANSLATE = 0xb,
    HK_SHAPE_CONVEX_TRANSFORM = 0xc,
    HK_SHAPE_TRANSFORM = 0xf,
};

struct hkpShape : CollapseRefObject
{
    unsigned int m_ulUserData;
    int m_type;
    __forceinline int getType() const
    {
        return m_type;
    }
};

struct hkpConvexShape : hkpShape
{
    float m_fSphereRadius;
    __forceinline float getRadius() const
    {
        return m_fSphereRadius;
    }
};

struct hkpSingleShapeContainer
{
    virtual ~hkpSingleShapeContainer();
    const hkpShape* m_pContainedShape;
    __forceinline const hkpShape* getChild() const
    {
        return m_pContainedShape;
    }
};

struct hkpConvexTransformShapeBase : hkpConvexShape
{
    hkpSingleShapeContainer m_pContainedShape;
    int m_iChildShapeSize;
    hkpConvexTransformShapeBase(int type, float radius, const hkpConvexShape* childShape, int ref);
    __forceinline const hkpConvexShape* GetShapeForKey() const
    {
        return static_cast<const hkpConvexShape*>(m_pContainedShape.getChild());
    }
};

struct hkpConvexTranslateShape : hkpConvexTransformShapeBase
{
    hkVector4 m_vTranslation;
    __forceinline hkpConvexTranslateShape(const hkpConvexShape* childShape, const hkVector4& translation, int ref = 1)
        : hkpConvexTransformShapeBase(HK_SHAPE_CONVEX_TRANSLATE, childShape->getRadius(), childShape, ref)
    {
        m_vTranslation.setXYZ0(translation);
        m_iChildShapeSize = 0;
    }
    virtual ~hkpConvexTranslateShape();
    __forceinline const hkVector4& getTranslation() const
    {
        return m_vTranslation;
    }
};

struct hkpConvexTransformShape : hkpConvexTransformShapeBase
{
    hkTransform m_kMotionTransform;
    hkpConvexTransformShape(const hkpConvexShape* childShape, const hkTransform& transform, int ref = 1);
    __forceinline const hkTransform& getTransform() const
    {
        return m_kMotionTransform;
    }
};

struct hkQuaternion
{
    hkVector4 m_vec;
};

struct hkpTransformShape : hkpShape
{
    hkpSingleShapeContainer m_pContainedShape;
    int m_iChildShapeSize;
    hkQuaternion m_rotation;
    hkTransform m_kMotionTransform;
    hkpTransformShape(const hkpShape* childShape, const hkTransform& transform);
    __forceinline const hkpShape* GetShapeForKey() const
    {
        return m_pContainedShape.getChild();
    }
    __forceinline const hkTransform& getTransform() const
    {
        return m_kMotionTransform;
    }
};

// Applies a transform to a shape, collapsing identity results to the child shape or creating a new transform/convex shape wrapper.
// @fnv 0x00d73590
const hkpShape* __cdecl FUN_00d73590(const hkpShape* shape, const hkTransform& transform) throw()
{
    if (transform.IsEqualWithinTolerance(hkTransform::GetIdentityTransform(), 0.001f))
    {
        shape->FUN_00c90510();
        return shape;
    }

    switch (shape->getType())
    {
    case HK_SHAPE_TRANSFORM: {
        const hkpTransformShape* pTransformShape = static_cast<const hkpTransformShape*>(shape);
        hkTransform combined;
        combined.SetProduct(transform, pTransformShape->getTransform());
        if (combined.IsEqualWithinTolerance(hkTransform::GetIdentityTransform(), 0.001f))
        {
            const hkpShape* child = pTransformShape->GetShapeForKey();
            child->FUN_00c90510();
            return child;
        }
        return new hkpTransformShape(pTransformShape->GetShapeForKey(), combined);
    }
    case HK_SHAPE_CONVEX_TRANSFORM: {
        const hkpConvexTransformShape* cts = static_cast<const hkpConvexTransformShape*>(shape);
        hkTransform combined;
        combined.SetProduct(transform, cts->getTransform());
        if (combined.IsEqualWithinTolerance(hkTransform::GetIdentityTransform(), 0.001f))
        {
            const hkpShape* child = cts->GetShapeForKey();
            child->FUN_00c90510();
            return child;
        }
        return new hkpConvexTransformShape(cts->GetShapeForKey(), combined);
    }
    case HK_SHAPE_CONVEX_TRANSLATE: {
        if (transform.getRotation().IsEqualWithinTolerance(hkTransform::GetIdentityTransform().getRotation(), 0.001f))
        {
            const hkpConvexTranslateShape* cts = static_cast<const hkpConvexTranslateShape*>(shape);
            hkTransform local;
            local.getRotation().setIdentity();
            local.setTranslation(cts->getTranslation());
            hkTransform combined;
            combined.SetProduct(transform, local);
            if (combined.IsEqualWithinTolerance(hkTransform::GetIdentityTransform(), 0.001f))
            {
                const hkpShape* child = cts->GetShapeForKey();
                child->FUN_00c90510();
                return child;
            }
            return new hkpConvexTranslateShape(cts->GetShapeForKey(), cts->getTranslation());
        }
        break;
    }
    }

    return new hkpTransformShape(shape, transform);
}

template <class T> class hkArrayD74
{
  public:
    enum
    {
        DONT_DEALLOCATE_FLAG = 0x80000000,
        CAPACITY_MASK = 0x3fffffff
    };
    int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    void ClearAndRelease()
    {
        hkMemoryAllocatorD748& alloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct RefPairD74
{
    hkReferencedObject* m_kPointA;
    hkReferencedObject* m_kPointB;
    int m_iThirdValue;
};
class RefPairListD74
{
  public:
    hkArrayD74<RefPairD74> m_pairs;
    void FUN_00d74aa0();
};
// Removes references from all pairs in m_pairs and then clears and releases the underlying array storage.
// @fnv 0x00d74aa0
void RefPairListD74::FUN_00d74aa0()
{
    for (int i = 0; i < m_pairs.m_iElementCount; i++)
    {
        if (m_pairs.m_data[i].m_kPointA)
            m_pairs.m_data[i].m_kPointA->removeReference();
        if (m_pairs.m_data[i].m_kPointB)
            m_pairs.m_data[i].m_kPointB->removeReference();
    }
    m_pairs.ClearAndRelease();
}
