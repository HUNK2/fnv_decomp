
// src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/instance/hkaragdollinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkaRagdollInstance.h"

extern int DAT_01268700;
void __stdcall FUN_00ce1760(int, int, int);
// @fnv 0x00ce18d0
void __stdcall FUN_00ce18d0(int a)
{
    FUN_00ce1760(a, (int)&DAT_01268700, 0);
}

struct FUN_00ce2430_Transform
{
    unsigned char pad[0x30];
};

struct FUN_00ce2430_Data
{
    unsigned char pad[0x1c];
    int count;
};

struct FUN_00ce2430_Class
{
    unsigned char pad[0x2c];
    FUN_00ce2430_Data* data;

    void FUN_00ce2150(int, float, void*);
    void ApplyValueToTransforms(float, FUN_00ce2430_Transform*);
};

// Iterates over data->count entries, calling FUN_00ce2150 with each index, value and successive transform.
// @fnv 0x00ce2430
void FUN_00ce2430_Class::ApplyValueToTransforms(float value, FUN_00ce2430_Transform* transforms)
{
    int count = this->data->count;

    for (int i = 0; i < count; ++i)
    {
        this->FUN_00ce2150(i, value, transforms);
        ++transforms;
    }
}

struct MemoryManager
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void release(void* object, unsigned short value);
};

struct MemoryRouter
{
    void* ReportDiagnostic;
    void* unused1;
    void* unused2;
    void* FlushUsageData;
    MemoryManager* manager;
};

struct FUN_00ce29b0_standin
{
    void FUN_00ce2600();
    void* Destroy(unsigned char deletingFlag);
};

MemoryRouter* _D1A0E0GetMemoryRouter();

// @fnv 0x00ce29b0
void* FUN_00ce29b0_standin::Destroy(unsigned char deletingFlag)
{
    FUN_00ce2600();

    if (deletingFlag & 1)
    {
        MemoryRouter* router = _D1A0E0GetMemoryRouter();
        router->manager->release(this, *(unsigned short*)((unsigned char*)this + 4));
    }

    return this;
}

extern int DAT_010cfd84;

struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* FUN_00ce25f0(unsigned int unusedArg);
};

// @fnv 0x00ce25f0
FnvVtObj* FnvVtObj::FUN_00ce25f0(unsigned int unusedArg)
{
    m_vptr = (int)&DAT_010cfd84;
    return this;
}

struct ReferenceObject : hkReferencedObject
{
    void FUN_00c90510();
    void FUN_00c905b0();
};
struct ArrayAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void* allocateBuffer(int& bytes);
    virtual void freeBuffer(void* buffer, int bytes);
};
struct ArrayRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    ArrayAllocator* m_pStreamAllocator;
};
ArrayRouter* __cdecl FUN_00c85750();
template <class T> struct ObjectArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void assign(const ObjectArray& source)
    {
        ArrayAllocator* heap = FUN_00c85750()->m_pStreamAllocator;
        int capacity = m_iCapacityState & 0x3fffffff;
        if (capacity < source.m_iElementCount)
        {
            if (!(m_iCapacityState & 0x80000000))
                heap->freeBuffer(m_data, capacity * (int)sizeof(T));
            int bytes = source.m_iElementCount * (int)sizeof(T);
            m_data = (T*)heap->allocateBuffer(bytes);
            m_iCapacityState = bytes / (int)sizeof(T);
        }
        m_iElementCount = source.m_iElementCount;
        int count = m_iElementCount;
        T* destination = m_data;
        const T* input = source.m_data;
        for (int i = 0; i < count; ++i)
            destination[i] = input[i];
    }
};
struct RagdollInstance : hkReferencedObject
{
    ObjectArray<ReferenceObject*> m_ppRigidBodies;
    ObjectArray<ReferenceObject*> m_ppConstraints;
    ObjectArray<int> m_kBoneMap;
    ReferenceObject* m_pSkeleton;
    void FUN_00ce22c0(const ObjectArray<ReferenceObject*>& bodies, const ObjectArray<ReferenceObject*>& constraints,
                      ReferenceObject* skeleton);
};
// @fnv 0x00ce22c0
void RagdollInstance::FUN_00ce22c0(const ObjectArray<ReferenceObject*>& bodies,
                                   const ObjectArray<ReferenceObject*>& constraints, ReferenceObject* skeleton)
{
    if (skeleton)
        skeleton->FUN_00c90510();
    if (m_pSkeleton)
        m_pSkeleton->FUN_00c905b0();
    m_pSkeleton = skeleton;
    m_ppRigidBodies.assign(bodies);
    m_ppConstraints.assign(constraints);
    for (int i = 0; i < m_ppRigidBodies.m_iElementCount; ++i)
        if (m_ppRigidBodies[i])
            m_ppRigidBodies[i]->FUN_00c90510();
    for (int i = 0; i < m_ppConstraints.m_iElementCount; ++i)
        if (m_ppConstraints[i])
            m_ppConstraints[i]->FUN_00c90510();
}

namespace fnv_00ce2600 {
extern int DAT_010cb830;
extern int DAT_0102e388;
struct FnvRefObject
{
    void FUN_00c905b0() throw();
};
struct FnvMemoryManager
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void release(void*, unsigned int) throw();
};
struct FnvRouter
{
    void* a;
    void* b;
    void* c;
    void* d;
    FnvMemoryManager* manager;
};
FnvRouter* FUN_00c85750();
struct FnvArray
{
    void** data;
    int size;
    unsigned int capacityAndFlags;
    ~FnvArray() throw()
    {
        FnvRouter* router = FUN_00c85750();
        FnvMemoryManager* mgr = router->manager;
        unsigned int cap = capacityAndFlags;
        size = 0;
        if (!(cap & 0x80000000u))
            mgr->release(data, (cap & 0x3fffffffu) * 4);
        data = 0;
        capacityAndFlags = 0x80000000u;
    }
};
struct FnvParent
{
    void* vtbl;
    unsigned short flags;
    short references;
    ~FnvParent() throw()
    {
        vtbl = &DAT_0102e388;
    }
};
struct FUN_00ce2600 : FnvParent
{
    FnvArray bodies, constraints, mapping;
    FnvRefObject* skeleton;
    ~FUN_00ce2600() throw();
};
// @fnv 0x00ce2600
FUN_00ce2600::~FUN_00ce2600() throw()
{
    vtbl = &DAT_010cb830;
    for (int i = 0; i < bodies.size; ++i)
        ((FnvRefObject*)bodies.data[i])->FUN_00c905b0();
    for (int j = 0; j < constraints.size; ++j)
        ((FnvRefObject*)constraints.data[j])->FUN_00c905b0();
    if (skeleton)
        skeleton->FUN_00c905b0();
    skeleton = 0;
}
}  // namespace fnv_00ce2600

struct FUN_00ce26f0_ObjectC
{
    float FUN_00c91020();
};

struct FUN_00ce26f0_ObjectB
{
    void* unk00;
    void* unk04;
    FUN_00ce26f0_ObjectC* unk08;
};

struct FUN_00ce26f0_ObjectA
{
    FUN_00ce26f0_ObjectB* unk00;
};

struct FUN_00ce26f0_Class
{
    int unk00;
    int unk04;
    FUN_00ce26f0_ObjectA* unk08;

    void FUN_00ce18d0(FUN_00ce2430_Transform* a);
    void ApplyValueToTransforms(float a, FUN_00ce2430_Transform* b);
    void FUN_00ce26f0(FUN_00ce2430_Transform* a);
};

// Calls FUN_00c91020 and passes its result to ApplyValueToTransforms when the nested pointer exists; otherwise calls FUN_00ce18d0.
// @fnv 0x00ce26f0
void FUN_00ce26f0_Class::FUN_00ce26f0(FUN_00ce2430_Transform* apTransform)
{
    FUN_00ce26f0_ObjectB* object = this->unk08->unk00;
    FUN_00ce26f0_ObjectC* target = object != 0 ? object->unk08 : 0;

    if (target == 0)
    {
        this->FUN_00ce18d0(apTransform);
        return;
    }

    this->ApplyValueToTransforms(target->FUN_00c91020(), apTransform);
}

typedef unsigned int hk_size_tR;
class hkMemoryAllocatorR
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
struct hkMemoryRouterR
{
    void* m_aiEntries;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorR* m_pStreamAllocator;
    hkMemoryAllocatorR& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterR& __cdecl GetMemoryRouterR() throw();
void __cdecl hkArrayUtil_reserveR(hkMemoryAllocatorR& kAlloc, void* pkArray, int iNumElements, int iSizeElem) throw();
template <typename T> struct hkArrayR
{
    hkArrayR() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArrayR() throw()
    {
        hkMemoryAllocatorR& kAlloc = GetMemoryRouterR().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocatorR& kAlloc = GetMemoryRouterR().heap();
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            hkArrayUtil_reserveR(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T> __forceinline T* hkAllocateStackR(int n)
{
    hkMemoryRouterR& kRouter = GetMemoryRouterR();
    char* pcCur = (char*)kRouter.m_aiEntries;
    kRouter.m_aiEntries = pcCur + ((n * sizeof(T) + 0x7f) & ~0x7f);
    return (T*)pcCur;
}
template <typename T> __forceinline void hkDeallocateStackR(T* p)
{
    GetMemoryRouterR().m_aiEntries = p;
}
template <typename T> struct hkLocalArrayR : public hkArrayR<T>
{
    __forceinline hkLocalArrayR(int n) throw()
    {
        T* pLocal = hkAllocateStackR<T>(n);
        this->m_data = pLocal;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = pLocal;
    }
    __forceinline ~hkLocalArrayR() throw()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        hkDeallocateStackR(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};
class hkReferencedObjectR
{
  public:
    virtual ~hkReferencedObjectR() throw();
    void removeReference() const throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class hkpRigidBodyR : public hkReferencedObjectR
{
  public:
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual hkpRigidBodyR* clone() const throw();
};
class hkpConstraintInstanceR : public hkReferencedObjectR
{
  public:
    hkpConstraintInstanceR* clone(hkpRigidBodyR* pkEntityA, hkpRigidBodyR* pkEntityB, int eCloneMode) const throw();
};
class hkaSkeletonR : public hkReferencedObjectR
{
  public:
    const char* m_name;
    hkArrayR<short> m_kParentIndices;
};
class hkaRagdollInstanceR : public hkReferencedObjectR
{
  public:
    __forceinline void* operator new(hk_size_tR uiBytes)
    {
        hkReferencedObjectR* b =
            static_cast<hkReferencedObjectR*>(GetMemoryRouterR().heap().AllocateMemoryBlock(uiBytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(uiBytes);
        return b;
    }
    void operator delete(void* p, hk_size_tR uiBytes);
    hkaRagdollInstanceR(const hkArrayR<hkpRigidBodyR*>& kRigidBodies,
                        const hkArrayR<hkpConstraintInstanceR*>& kConstraints, const hkaSkeletonR* pkSkeleton,
                        const hkArrayR<int>& kBoneToRigidBodyMap) throw();
    hkaRagdollInstanceR* FUN_00ce2730(int eMode) const throw();
    const hkaSkeletonR* getSkeleton() const
    {
        return m_pSkeleton;
    }
    hkArrayR<hkpRigidBodyR*> m_ppRigidBodies;
    hkArrayR<hkpConstraintInstanceR*> m_ppConstraints;
    hkArrayR<int> m_kBoneMap;
    const hkaSkeletonR* m_pSkeleton;
};

// Clones the ragdoll's rigid bodies and constraints, builds a new hkaRagdollInstanceR from them, and returns it.
// @fnv 0x00ce2730
hkaRagdollInstanceR* hkaRagdollInstanceR::FUN_00ce2730(int aeCloneMode) const throw()
{
    const int iNumRigidBodies = m_ppRigidBodies.GetLogicalSize();
    const int iNumConstraints = m_ppConstraints.GetLogicalSize();
    hkLocalArrayR<hkpRigidBodyR*> kNewRigidBodies(iNumRigidBodies);
    kNewRigidBodies.SetSizeAndGrow(iNumRigidBodies);
    hkLocalArrayR<hkpConstraintInstanceR*> kNewConstraints(iNumConstraints);
    kNewConstraints.SetSizeAndGrow(iNumConstraints);
    for (int rb = 0; rb < iNumRigidBodies; rb++)
        kNewRigidBodies[rb] = m_ppRigidBodies[rb]->clone();
    for (int c = 0; c < iNumConstraints; c++)
    {
        hkpRigidBodyR* pkChildRb = kNewRigidBodies[c + 1];
        hkpRigidBodyR* pkParentRb = kNewRigidBodies[m_pSkeleton->m_kParentIndices[c + 1]];
        kNewConstraints[c] = m_ppConstraints[c]->clone(pkChildRb, pkParentRb, aeCloneMode);
    }
    hkaRagdollInstanceR* pkNewInstance =
        new hkaRagdollInstanceR(kNewRigidBodies, kNewConstraints, getSkeleton(), m_kBoneMap);
    for (int rb = 0; rb < iNumRigidBodies; rb++)
        kNewRigidBodies[rb]->removeReference();
    for (int c = 0; c < iNumConstraints; c++)
        kNewConstraints[c]->removeReference();
    return pkNewInstance;
}

#include <xmmintrin.h>
struct FUN_00ce14b0_standin
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
    __m128 unk10;
    unsigned short unk20;
    unsigned short unk22;
    unsigned short unk24;

    void FUN_00ce14b0(unsigned short a, unsigned short b, unsigned short c, const void* data);
};

// @fnv 0x00ce14b0
void FUN_00ce14b0_standin::FUN_00ce14b0(unsigned short auwFirst, unsigned short auwSecond, unsigned short auwThird,
                                        const void* data)
{
    unsigned short second = auwSecond;
    unsigned short third = auwThird;

    unk20 = auwFirst;
    unk22 = second;
    unk00 = 0;
    unk04 = 0;
    unk08 = 0x80000000;
    unk24 = third;

    __m128 value = *reinterpret_cast<const __m128*>(data);
    unk10 = value;
}

struct FUN_00ce1680_Body
{
    void* unk00;
    void* unk04;
    void* unk08;
};

struct FUN_00c94bd0_Obj
{
    void FUN_00c94bd0(void* objects, int count, int flag);
};

struct FUN_00c97d30_Obj
{
    void FUN_00c97d30(void* object);
};

struct CallRet
{
    void FUN_00c946e0(void* object, int a, int b);
};

class FUN_00ce1680_Ragdoll : public hkReferencedObject
{
  public:
    hkArray<void*> m_ppRigidBodies;
    hkArray<void*> m_ppConstraints;
    hkArray<hkInt32> m_kBoneMap;
    hkaSkeleton* m_pSkeleton;

    int FUN_00ce1680(void* world, unsigned char flag);
};

// Passes rigid bodies and constraints to world methods; when flag is nonzero, calls another world method for each body.
// @fnv 0x00ce1680
int FUN_00ce1680_Ragdoll::FUN_00ce1680(void* world, unsigned char flag)
{
    FUN_00ce1680_Body* firstBody = (FUN_00ce1680_Body*)m_ppRigidBodies.m_data[0];

    if (firstBody && firstBody->unk08)
        return 1;

    ((FUN_00c94bd0_Obj*)world)->FUN_00c94bd0(m_ppRigidBodies.m_data, m_ppRigidBodies.m_iElementCount, 1);

    for (int iConstraintIndex = 0; iConstraintIndex < m_ppConstraints.m_iElementCount; ++iConstraintIndex)
    {
        ((FUN_00c97d30_Obj*)world)->FUN_00c97d30(m_ppConstraints.m_data[iConstraintIndex]);
    }

    if (flag)
    {
        int bodyCount = m_ppRigidBodies.m_iElementCount;
        int bodyIndex = 0;

        if (bodyCount > 0)
        {
            do
            {
                ((CallRet*)world)->FUN_00c946e0(m_ppRigidBodies.m_data[bodyIndex], 1, 0);
            } while (++bodyIndex < bodyCount);
        }
    }

    return 0;
}

extern int DAT_010cb830;
void __cdecl FUN_00c908c0(ArrayAllocator* heap, void* array, int numElements, int sizeOfElement);
struct RouterRef_ce24
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    ArrayAllocator* m_pStreamAllocator;
    ArrayAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
    static RouterRef_ce24& __cdecl FUN_00c85750() throw();
};

template <class T> struct hkArray_ce24
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void SetSizeAndGrow(int n)
    {
        ArrayAllocator& heap = RouterRef_ce24::FUN_00c85750().heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = 2 * cap;
            FUN_00c908c0(&heap, this, n < cap2 ? cap2 : n, sizeof(T));
        }
        m_iElementCount = n;
    }
};

struct Skeleton_ce24
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    int m_iBoneCount;
};

struct RagdollInstance_ce24
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    hkArray_ce24<ReferenceObject*> m_ppRigidBodies;
    hkArray_ce24<ReferenceObject*> m_ppConstraints;
    hkArray_ce24<int> m_kBoneMap;
    Skeleton_ce24* m_pSkeleton;
    void FUN_00ce22c0(const hkArray_ce24<ReferenceObject*>& bodies, const hkArray_ce24<ReferenceObject*>& constraints,
                      Skeleton_ce24* skeleton);
    RagdollInstance_ce24* FUN_00ce2470(const hkArray_ce24<ReferenceObject*>& bodies,
                                       const hkArray_ce24<ReferenceObject*>& constraints, Skeleton_ce24* skeleton);
};

// Initializes a RagdollInstance_ce24 with the given rigid bodies, constraints, and skeleton, and returns the instance.
// @fnv 0x00ce2470
RagdollInstance_ce24* RagdollInstance_ce24::FUN_00ce2470(const hkArray_ce24<ReferenceObject*>& bodies,
                                                         const hkArray_ce24<ReferenceObject*>& constraints,
                                                         Skeleton_ce24* skeleton)
{
    m_vtbl = &DAT_010cb830;
    m_sReferenceCount = 1;
    m_ppRigidBodies.init();
    m_ppConstraints.init();
    m_kBoneMap.init();
    m_pSkeleton = 0;
    FUN_00ce22c0(bodies, constraints, skeleton);
    m_kBoneMap.SetSizeAndGrow(skeleton->m_iBoneCount);
    for (int i = 0; i < skeleton->m_iBoneCount; i++)
        m_kBoneMap[i] = i;
    return this;
}

extern "C"
{
    extern __m128 DAT_010c71e0;
    extern __m128 DAT_010c7170;
    extern __m128 DAT_010c44d0;
    extern __m128 DAT_010c4c00;
    extern __m128 DAT_010c4c10;
}

void __cdecl FUN_00ce2d10(unsigned int p0, void* p1, unsigned int p2, int p3, unsigned int p4);

struct Vec4x3
{
    __m128 r0;
    __m128 r1;
    __m128 r2;
};

// Reserves stack space for count Vec4x3 values, transforms each source entry with SIMD, calls FUN_00ce2d10, then restores the stack cursor.
// @fnv 0x00ce2f40
void __cdecl FUN_00ce2f40(unsigned int arg0, unsigned int arg1, unsigned int arg2, int count, unsigned int arg4)
{
    void** cursor = (void**)FUN_00c85750();
    unsigned char* pMatBase = (unsigned char*)*cursor;
    unsigned int size = (unsigned int)((count * 3) << 4) + 0x7f;
    size &= 0xffffff80u;
    *cursor = pMatBase + size;

    if (count > 0)
    {
        const Vec4x3* s = (const Vec4x3*)arg1;
        Vec4x3* d = (Vec4x3*)pMatBase;
        for (int i = 0; i < count; i++)
        {
            __m128 b = s[i].r1;
            __m128 a = s[i].r0;

            __m128 ab = _mm_mul_ps(a, b);
            __m128 vCross = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
            __m128 cb = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
            vCross = _mm_sub_ps(vCross, cb);
            __m128 vW = _mm_shuffle_ps(b, b, 0xff);
            vCross = _mm_mul_ps(vCross, vW);
            __m128 t1 = _mm_add_ss(_mm_shuffle_ps(ab, ab, 0x55), ab);
            __m128 vDot = _mm_add_ss(_mm_shuffle_ps(ab, ab, 0xaa), t1);
            __m128 t5 = _mm_mul_ps(vW, vW);
            t5 = _mm_add_ps(t5, DAT_010c71e0);
            t5 = _mm_mul_ps(t5, a);
            __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(vDot, vDot, 0), b);
            t5 = _mm_add_ps(t5, t2);
            vCross = _mm_add_ps(vCross, t5);
            __m128 res = _mm_add_ps(vCross, vCross);
            d[i].r0 = res;
            res = _mm_xor_ps(res, DAT_010c44d0);
            d[i].r0 = res;

            __m128 k = _mm_xor_ps(s[i].r1, DAT_010c4c00);
            d[i].r1 = k;

            __m128 c = s[i].r2;
            __m128 x = _mm_unpackhi_ps(c, DAT_010c7170);
            x = _mm_shuffle_ps(c, x, 0xc4);
            __m128 vRcp = _mm_rcp_ps(x);
            __m128 tt = _mm_mul_ps(vRcp, x);
            tt = _mm_mul_ps(tt, vRcp);
            __m128 vRecip = _mm_add_ps(vRcp, vRcp);
            vRecip = _mm_sub_ps(vRecip, tt);
            vRecip = _mm_and_ps(vRecip, DAT_010c4c10);
            d[i].r2 = vRecip;
        }
    }

    FUN_00ce2d10(arg0, (void*)pMatBase, arg2, count, arg4);
    void** cursor2 = (void**)FUN_00c85750();
    *cursor2 = pMatBase;
}

extern float DAT_01267e30;
extern float DAT_01017d00;
extern float DAT_01017d10;

struct UnkCall
{
    void FUN_00c9c1d0();
    void FUN_00ca8860(const hkVector4& pos, const hkQuaternion& rot);
};

struct hkpMotion
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void SetTranslationalVelocity(const hkVector4& vel);
    virtual void SetRotationalVelocity(const hkVector4& vel);
    int unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
};

struct hkpRigidBody : public UnkCall
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc;
    hkpMotion m_pMotionState;

    void SetTranslationalVelocity(const hkVector4& vel)
    {
        FUN_00c9c1d0();
        m_pMotionState.SetTranslationalVelocity(vel);
    }
    void SetRotationalVelocity(const hkVector4& vel)
    {
        FUN_00c9c1d0();
        m_pMotionState.SetRotationalVelocity(vel);
    }
};

struct hkaBone
{
    hkStringPtr m_name;
    hkBool m_bLockTranslation;
};

class hkaSkeleton : public hkReferencedObject
{
  public:
    hkStringPtr m_name;
    hkArray<hkInt16> m_kParentIndices;
    hkArray<hkaBone> m_kBones;
};

struct PoseW
{
    const hkQsTransform* p;
    PoseW(const hkQsTransform* q) : p(q)
    {}
};
struct RagdollHelper : public hkaRagdollInstance
{
    void FUN_00ce1560(PoseW pose);
};

// Sets mapped rigid-body transforms from pose and sets each velocity to zero when not all four components are within epsilon of zero.
// @fnv 0x00ce1560
void RagdollHelper::FUN_00ce1560(PoseW pose)
{
    int numBones = m_pSkeleton->m_kBones.m_iElementCount;
    const hkVector4& zero = *(const hkVector4*)&DAT_01267e30;
    int i = 0;
    if (numBones <= 0)
        return;
    const hkQsTransform* cursor = pose.p;
    do
    {
        int rbIndex = m_kBoneMap.m_data[i];
        if (rbIndex >= 0)
        {
            hkpRigidBody* rb = (hkpRigidBody*)m_ppRigidBodies.m_data[rbIndex];
            if (rb)
            {
                rb->FUN_00ca8860(cursor->m_vTranslation, cursor->m_rotation);

                __m128 kZeroVec = *(const __m128*)&zero;
                __m128 kLinVel = *(const __m128*)&rb->m_pMotionState.m_kTranslationalVelocity;
                __m128 eps = _mm_set1_ps(DAT_01017d00);
                __m128 kDiffLin = _mm_sub_ps(kZeroVec, kLinVel);
                __m128 kAbsLin = _mm_and_ps(kDiffLin, *(const __m128*)&DAT_01017d10);
                __m128 kCmpLin = _mm_cmple_ps(kAbsLin, eps);
                if ((_mm_movemask_ps(kCmpLin) & 0xf) != 0xf)
                {
                    rb->SetTranslationalVelocity(zero);
                    kZeroVec = *(const __m128*)&zero;
                }

                __m128 kAngVel = *(const __m128*)&rb->m_pMotionState.m_kAngularVelocity;
                __m128 kDiffAng = _mm_sub_ps(kZeroVec, kAngVel);
                __m128 kAbsAng = _mm_and_ps(kDiffAng, *(const __m128*)&DAT_01017d10);
                __m128 kCmpAng = _mm_cmple_ps(kAbsAng, eps);
                if ((_mm_movemask_ps(kCmpAng) & 0xf) != 0xf)
                {
                    rb->SetRotationalVelocity(zero);
                }
            }
        }
        cursor = *static_cast<const hkQsTransform* volatile*>(&cursor);
        ++i;
        ++cursor;
    } while (i < numBones);
}

template <class T> struct InitArray : ObjectArray<T>
{
    InitArray()
    {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
    }
};
extern "C" int DAT_010cb830;

struct FUN_00ce2510
{
    void* m_vptr;
    short m_iWordAt04;
    short m_6;
    InitArray<void*> m_ppRigidBodies;
    InitArray<void*> m_ppConstraints;
    InitArray<int> m_kBoneMap;
    int m_2c;

    void FUN_00ce22c0(int a, int b, int c);
    FUN_00ce2510(int a, int b, int c, ObjectArray<int>* d);
};

// Sets the vtable and reference count, calls FUN_00ce22c0, and assigns m_kBoneMap from the provided array.
// @fnv 0x00ce2510
FUN_00ce2510::FUN_00ce2510(int a, int b, int c, ObjectArray<int>* apBoneMap) : m_vptr(&DAT_010cb830), m_6(1)
{
    m_2c = 0;

    FUN_00ce22c0(a, b, c);
    m_kBoneMap.assign(*apBoneMap);
}
