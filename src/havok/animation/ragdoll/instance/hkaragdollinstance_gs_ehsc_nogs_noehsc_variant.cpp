
// src/havok/animation/ragdoll/instance/hkaragdollinstance_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/animation/ragdoll/instance/hkaragdollinstance.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/instance/hkaragdollinstance.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkaRagdollInstance.h"
extern int DAT_01268700;
void __stdcall FUN_00ce1760(int, int, int);
void __stdcall FUN_00ce18d0(int a);
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
extern int DAT_010cfd84;
struct FnvVtObj
{
    int m_vptr;

    FnvVtObj* FUN_00ce25f0(unsigned int unusedArg);
};
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
    hkaRagdollInstanceR* hkaRagdollInstance_clone(int eMode) const throw();
    const hkaSkeletonR* getSkeleton() const
    {
        return m_pSkeleton;
    }
    hkArrayR<hkpRigidBodyR*> m_ppRigidBodies;
    hkArrayR<hkpConstraintInstanceR*> m_ppConstraints;
    hkArrayR<int> m_kBoneMap;
    const hkaSkeletonR* m_pSkeleton;
};

#include <xmmintrin.h>
// FUN_00ce0d30 - build orthonormal basis from 3 indexed points, convert to quaternion via FUN_00cb26e0

extern float DAT_01016248;  // 0.5f
extern float DAT_01011d78;  // 0.0f
extern float DAT_01017718;  // 3.0f

struct VecF
{
    float x, y, z, w;
};

struct Elem
{
    VecF v;
    float pad[8];
};

struct ThisX
{
    unsigned char pad[0x20];
    short m_i0;
    short m_i1;
    short m_i2;
};

class FUN_00827200_class
{
  public:
    float m_00, m_04, m_08, m_0c;
    void FUN_00cb26e0(int);
};

static __forceinline __m128 Dot3(__m128 v)
{
    __m128 sq = _mm_mul_ps(v, v);
    __m128 t = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    return _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), t);
}

static __forceinline __m128 Normalize(__m128 v)
{
    __m128 dot = Dot3(v);
    __m128 e = _mm_rsqrt_ss(dot);
    __m128 q = _mm_mul_ss(_mm_mul_ss(dot, e), e);
    __m128 three = _mm_set_ss(DAT_01017718);
    __m128 half = _mm_set_ss(DAT_01016248);
    __m128 mask = _mm_cmpeq_ss(dot, _mm_set_ss(DAT_01011d78));
    __m128 f = _mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, e), _mm_sub_ss(three, q)));
    return _mm_mul_ps(_mm_shuffle_ps(f, f, 0), v);
}

static __forceinline __m128 Cross(__m128 a, __m128 b)
{
    __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    return _mm_sub_ps(t2, t1);
}

// @fnv 0x00ce0d30
void __fastcall FUN_00ce0d30(ThisX* th, void* edx_unused, const Elem* points, VecF* out)
{
    VecF p0 = points[th->m_i0].v;
    VecF p1 = points[th->m_i1].v;
    VecF p2 = points[th->m_i2].v;

    __m128 e1 = _mm_sub_ps(_mm_load_ps(&p1.x), *(__m128*)&p0.x);
    __m128 n1 = Normalize(e1);
    __m128 e2 = _mm_sub_ps(_mm_load_ps(&p2.x), *(__m128*)&p0.x);
    __m128 n2 = Normalize(e2);
    __m128 c = Normalize(Cross(n2, n1));
    __m128 c2 = Normalize(Cross(c, n1));
    __m128 b = Cross(n1, c2);

    FUN_00827200_class obj;
    VecF axes[3];
    _mm_store_ps(&axes[0].x, c2);
    _mm_store_ps(&axes[1].x, b);
    _mm_store_ps(&axes[2].x, n1);
    obj.FUN_00cb26e0((int)&axes[0]);
    _mm_store_ps(&out->x, _mm_load_ps(&obj.m_00));
}

ArrayRouter* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* a, void* b, int c);

struct __declspec(align(16)) Pose32
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    float unk14;
    int unk18;
    int unk1C;
};
struct SubObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* unk10;
};
struct Owner
{
    Pose32* data;
    int count;
    int capacity;
    int unk0C;
    SubObj sub;
    void FUN_00ce0d30(void* pose, Pose32* poseData);
    int FUN_00ce1420(void* pose, int arg2, float time);
};

struct __declspec(align(16)) Quaternion
{
    __m128 value;
    void FUN_00cb26e0(const __m128* matrix);
    void FUN_00c66320(const Quaternion& a, const Quaternion& b);
};
static __m128 cross3(__m128 a, __m128 b)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                      _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}
static __m128 dot3(__m128 a, __m128 b)
{
    __m128 v = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v));
}
static __declspec(noinline) void FUN_00ce0ff0(SubObj* object, Pose32* pose)
{
    __m128 axis = _mm_load_ps(reinterpret_cast<float*>(object));
    __declspec(align(16)) float absAxis[4];
    _mm_store_ps(absAxis, _mm_andnot_ps(_mm_set1_ps(-0.0f), axis));
    int major;
    if (absAxis[0] > absAxis[1])
        major = absAxis[0] > absAxis[2] ? 0 : 2;
    else
        major = absAxis[1] > absAxis[2] ? 1 : 2;
    __declspec(align(16)) float basis[4] = {0, 0, 0, 0};
    basis[(major + 1) % 3] = 1.0f;
    __m128 vector = _mm_load_ps(basis);
    __m128 q = _mm_load_ps(reinterpret_cast<float*>(pose));
    __m128 w = _mm_shuffle_ps(q, q, 0xff);
    __m128 d = dot3(q, vector);
    __m128 rotated = _mm_add_ps(_mm_mul_ps(cross3(q, vector), w),
                                _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), _mm_set1_ps(-0.5f)), vector),
                                           _mm_mul_ps(_mm_shuffle_ps(d, d, 0), q)));
    rotated = _mm_add_ps(rotated, rotated);
    __m128 third = cross3(rotated, axis);
    __m128 length = dot3(third, third);
    __m128 inverse = _mm_rsqrt_ss(length);
    inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), inverse),
                         _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(length, inverse), inverse)));
    inverse = _mm_andnot_ps(_mm_cmpeq_ss(length, _mm_setzero_ps()), inverse);
    third = _mm_mul_ps(third, _mm_shuffle_ps(inverse, inverse, 0));
    __m128 matrix[3] = {cross3(axis, third), axis, third};
    Quaternion orient;
    orient.FUN_00cb26e0(matrix);
    Quaternion conjugate;
    conjugate.value = _mm_xor_ps(orient.value, _mm_set_ps(0.0f, -0.0f, -0.0f, -0.0f));
    Quaternion result;
    result.FUN_00c66320(conjugate, *reinterpret_cast<Quaternion*>(pose));
    _mm_store_ps(reinterpret_cast<float*>(pose), result.value);
}

// @fnv 0x00ce1420
int Owner::FUN_00ce1420(void* pose, int arg2, float time)
{
    Pose32 poseData;
    poseData.unk14 = time;
    poseData.unk10 = arg2;
    FUN_00ce0d30(pose, &poseData);
    FUN_00ce0ff0(&sub, &poseData);
    ArrayRouter* router = FUN_00c85750();
    if (count == (capacity & 0x3FFFFFFF))
        ResizeAudioStream(router->m_pStreamAllocator, this, 0x20);
    Pose32* destination = data + count;
    if (destination != 0)
        *destination = poseData;
    count += 1;
    return count - 1;
}

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;
extern __m128 DAT_010c71b0;

class hkQuaternionCE2;

class hkVector4CE2
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4CE2& operator=(const hkVector4CE2& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4CE2& a, const hkVector4CE2& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4CE2& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4CE2& a, const hkVector4CE2& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4CE2& a, const hkVector4CE2& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4CE2& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4CE2& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4CE2& v1, const hkVector4CE2& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4CE2& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4CE2& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionCE2& q, const hkVector4CE2& dir);
    void setRotatedInverseDir(const hkQuaternionCE2& q, const hkVector4CE2& dir);
};

struct hkRotationCE2
{
    hkVector4CE2 m_kColumn0;
    hkVector4CE2 m_kColumn1;
    hkVector4CE2 m_kColumn2;
};

struct hkTransformCE2
{
    hkRotationCE2 m_rotation;
    hkVector4CE2 m_vTranslation;
};

class hkQuaternionCE2
{
  public:
    hkVector4CE2 m_vec;

    void set(const hkRotationCE2& kRotationBasis);

    __forceinline void SetConjugate(const hkQuaternionCE2& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionCE2& q0, const hkQuaternionCE2& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

__forceinline void hkVector4CE2::SetRotatedDirection(const hkQuaternionCE2& quat, const hkVector4CE2& direction)
{
    hkVector4CE2 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4CE2 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4CE2 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4CE2 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4CE2::setRotatedInverseDir(const hkQuaternionCE2& quat, const hkVector4CE2& direction)
{
    hkVector4CE2 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4CE2 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4CE2 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4CE2 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformCE2
{
  public:
    hkVector4CE2 m_vTranslation;
    hkQuaternionCE2 m_rotation;
    hkVector4CE2 m_vScale;

    __forceinline void SetConjugate(const hkQsTransformCE2& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4CE2 s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
    }
    __forceinline void setIdentity()
    {
        m_vTranslation.m_vComponents = _mm_setzero_ps();
        m_rotation.m_vec.m_vComponents = DAT_010c71b0;
        m_vScale.m_vComponents = _mm_set_ps1(1.0f);
    }
    __declspec(noinline) void SetFromTransform(const hkTransformCE2& kTransform)
    {
        m_rotation.set(kTransform.m_rotation);
        m_vTranslation = kTransform.m_vTranslation;
        m_vScale.m_vComponents = DAT_010c7170;
    }
    __forceinline void SetProduct(const hkQsTransformCE2& t1, const hkQsTransformCE2& t2)
    {
        hkVector4CE2 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.SetProduct(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
};

struct hkaSkeletonCE2
{
    int unk00;
    int unk04;
    int unk08;
    short* m_kParentIndices;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    hkQsTransformCE2* m_kReferencePose;
};

// Accumulated scale of a bone and all its parents in the reference pose.
__declspec(noinline) void __cdecl MultiplyBoneScales(const hkaSkeletonCE2* pkSkeleton, const hkQsTransformCE2* pkPose,
                                                     int iBone, hkVector4CE2& kScaleOut)
{
    hkVector4CE2 kScale;
    kScale.m_vComponents = DAT_010c7170;
    while (iBone != -1)
    {
        kScale.m_vComponents = _mm_mul_ps(pkPose[iBone].m_vScale.m_vComponents, kScale.m_vComponents);
        iBone = pkSkeleton->m_kParentIndices[iBone];
    }
    kScaleOut = kScale;
}

struct RigidBodyCE2
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    hkTransformCE2 m_kMotionTransform;
};

class FUN_00ce2000Owner
{
  public:
    int unk00;
    int unk04;
    RigidBodyCE2** m_ppBodies;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* m_piBoneToBody;
    int unk24;
    int unk28;
    hkaSkeletonCE2* m_pkSkeleton;

    void FUN_00ce2000(int iBone, hkQsTransformCE2& kOut);
};

// @fnv 0x00ce2000
void FUN_00ce2000Owner::FUN_00ce2000(int iBone, hkQsTransformCE2& kOut)
{
    int iBody = m_piBoneToBody[iBone];
    if (iBody >= 0)
    {
        RigidBodyCE2* pkBody = m_ppBodies[iBody];
        if (pkBody)
        {
            kOut.SetFromTransform(pkBody->m_kMotionTransform);
            MultiplyBoneScales(m_pkSkeleton, m_pkSkeleton->m_kReferencePose, iBone, kOut.m_vScale);
            return;
        }
    }

    hkQsTransformCE2 kParent;
    int iParent = m_pkSkeleton->m_kParentIndices[iBone];
    if (iParent >= 0)
        FUN_00ce2000(iParent, kParent);
    else
        kParent.setIdentity();
    kOut.SetProduct(kParent, m_pkSkeleton->m_kReferencePose[iBone]);
}

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;
extern __m128 DAT_010c71b0;

class hkQuaternionC21;

class hkVector4C21
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4C21& operator=(const hkVector4C21& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4C21& a, const hkVector4C21& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4C21& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4C21& a, const hkVector4C21& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4C21& a, const hkVector4C21& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4C21& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4C21& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4C21& v1, const hkVector4C21& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4C21& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4C21& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionC21& q, const hkVector4C21& dir);
    void setRotatedInverseDir(const hkQuaternionC21& q, const hkVector4C21& dir);
};

struct hkRotationC21
{
    hkVector4C21 m_kColumn0;
    hkVector4C21 m_kColumn1;
    hkVector4C21 m_kColumn2;
};

struct hkTransformC21
{
    hkRotationC21 m_rotation;
    hkVector4C21 m_vTranslation;
};

class hkQuaternionC21
{
  public:
    hkVector4C21 m_vec;

    void set(const hkRotationC21& kRotationBasis);

    __forceinline void SetConjugate(const hkQuaternionC21& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionC21& q0, const hkQuaternionC21& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

__forceinline void hkVector4C21::SetRotatedDirection(const hkQuaternionC21& quat, const hkVector4C21& direction)
{
    hkVector4C21 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4C21 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4C21 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4C21 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4C21::setRotatedInverseDir(const hkQuaternionC21& quat, const hkVector4C21& direction)
{
    hkVector4C21 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4C21 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4C21 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4C21 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformC21
{
  public:
    hkVector4C21 m_vTranslation;
    hkQuaternionC21 m_rotation;
    hkVector4C21 m_vScale;

    __forceinline void SetConjugate(const hkQsTransformC21& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4C21 s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
    }
    __forceinline void setIdentity()
    {
        m_vTranslation.m_vComponents = _mm_setzero_ps();
        m_rotation.m_vec.m_vComponents = DAT_010c71b0;
        m_vScale.m_vComponents = _mm_set_ps1(1.0f);
    }
    __declspec(noinline) void SetFromTransform(const hkTransformC21& kTransform)
    {
        m_rotation.set(kTransform.m_rotation);
        m_vTranslation = kTransform.m_vTranslation;
        m_vScale.m_vComponents = DAT_010c7170;
    }
    __forceinline void SetProduct(const hkQsTransformC21& t1, const hkQsTransformC21& t2)
    {
        hkVector4C21 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.SetProduct(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
};

struct hkaSkeletonC21
{
    int unk00;
    int unk04;
    int unk08;
    short* m_kParentIndices;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    hkQsTransformC21* m_kReferencePose;
};

// Accumulated scale of a bone and all its parents in the reference pose.
__declspec(noinline) void __cdecl MultiplyBoneScales(const hkaSkeletonC21* pkSkeleton, const hkQsTransformC21* pkPose,
                                                     int iBone, hkVector4C21& kScaleOut)
{
    hkVector4C21 kScale;
    kScale.m_vComponents = DAT_010c7170;
    while (iBone != -1)
    {
        kScale.m_vComponents = _mm_mul_ps(pkPose[iBone].m_vScale.m_vComponents, kScale.m_vComponents);
        iBone = pkSkeleton->m_kParentIndices[iBone];
    }
    kScaleOut = kScale;
}

struct MotionStateC21
{
    void EvaluateTransformAtTime(float fTime, hkTransformC21& kTransformOut) const;
};

struct RigidBodyC21
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    MotionStateC21 m_kMotionState;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    hkTransformC21 m_kMotionTransform;
};

class FUN_00ce2150Owner
{
  public:
    int unk00;
    int unk04;
    RigidBodyC21** m_ppBodies;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* m_piBoneToBody;
    int unk24;
    int unk28;
    hkaSkeletonC21* m_pkSkeleton;

    void FUN_00ce2150(int iBone, float fTime, hkQsTransformC21& kOut);
};

// @fnv 0x00ce2150
void FUN_00ce2150Owner::FUN_00ce2150(int iBone, float fTime, hkQsTransformC21& kOut)
{
    int iBody = m_piBoneToBody[iBone];
    if (iBody >= 0)
    {
        RigidBodyC21* pkBody = m_ppBodies[iBody];
        if (pkBody)
        {
            hkTransformC21 kTransform;
            pkBody->m_kMotionState.EvaluateTransformAtTime(fTime, kTransform);
            kOut.SetFromTransform(kTransform);
            MultiplyBoneScales(m_pkSkeleton, m_pkSkeleton->m_kReferencePose, iBone, kOut.m_vScale);
            return;
        }
    }

    {
        hkQsTransformC21 kParent;
        int iParent = m_pkSkeleton->m_kParentIndices[iBone];
        if (iParent >= 0)
            FUN_00ce2150(iParent, fTime, kParent);
        else
            kParent.setIdentity();
        kOut.SetProduct(kParent, m_pkSkeleton->m_kReferencePose[iBone]);
    }
}

extern int DAT_01012068;

struct Vq12
{
    __m128 m;
};
struct Xf12a0
{
    __m128 t, r, s;
    __forceinline void setIdentity()
    {
        t = _mm_setzero_ps();
        r = _mm_load_ps((const float*)&DAT_010c71b0);
        s = _mm_set1_ps(1.0f);
    }
};
__declspec(align(16)) struct Q4
{
    float x, y, z, w;
};

struct Ce0d30Obj
{
    void FUN_00ce0d30(void* arr, void* out);
};
struct Ce74Obj
{
    void FUN_00c74ac0(void* a, void* b);
};
struct Ceb2Obj
{
    void FUN_00cb2ca0(void* axis, void* tmp, float* angleOut);
    void FUN_00cb2450(void* axis, float angle);
};
struct Ce12a0Self
{
    int unk00, unk04, unk08, unk0c;
    void* unk10;
    int unk14, unk18, unk1c;
    short idx0, idx1, idx2;
};

class Ce12a0Host
{
  public:
    void FUN_00ce12a0(void* a1, void* a2, Xf12a0* a3, Xf12a0* a4);
};

struct SimdNumber
{
    __m128 value;
    __forceinline SimdNumber(__m128 n) : value(n)
    {}
};
struct MathVec
{
    __m128 value;
    __forceinline SimdNumber dot(const MathVec& other) const
    {
        __m128 products = _mm_mul_ps(value, other.value);
        __m128 partial = _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products);
        return SimdNumber(_mm_add_ss(_mm_shuffle_ps(products, products, 0xaa), partial));
    }
    __forceinline void cross(const MathVec& a, const MathVec& b)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(first, second);
    }
    __forceinline void rotate(const MathVec& q, const MathVec& b)
    {
        __m128 half = _mm_load_ps((const float*)&DAT_010c71e0);
        __m128 scalar = _mm_shuffle_ps(q.value, q.value, 0xff);
        __m128 factor = _mm_add_ps(half, _mm_mul_ps(scalar, scalar));
        __m128 base = _mm_mul_ps(b.value, factor);
        SimdNumber product = q.dot(b);
        __m128 splat = _mm_shuffle_ps(product.value, product.value, 0);
        base = _mm_add_ps(base, _mm_mul_ps(splat, q.value));
        MathVec crossed;
        crossed.cross(q, b);
        base = _mm_add_ps(base, _mm_mul_ps(scalar, crossed.value));
        value = _mm_add_ps(base, base);
    }
};

// @fnv 0x00ce12a0
void Ce12a0Host::FUN_00ce12a0(void* a1, void* a2, Xf12a0* a3, Xf12a0* a4)
{
    Ce12a0Self* self = (Ce12a0Self*)this;
    Q4 q0, q1;

    ((Ce0d30Obj*)self)->FUN_00ce0d30(a1, &q0);
    ((Ce0d30Obj*)self)->FUN_00ce0d30(a2, &q1);

    a4->setIdentity();
    int index = self->idx0;
    a4->t = ((Xf12a0*)a2)[index].t;
    ((Ce74Obj*)&a4->r)->FUN_00c74ac0(&q1, &q0);

    MathVec rotated;
    rotated.rotate(*(MathVec*)&a4->r, *(MathVec*)&((Xf12a0*)a1)[index].t);
    a4->t = _mm_sub_ps(a4->t, rotated.value);

    a3->setIdentity();
    a3->t = a4->t;
    a3->r = a4->r;
    a3->s = a4->s;

    {
        __declspec(align(16)) float angle;
        Q4 axis;
        ((Ceb2Obj*)&a3->r)->FUN_00cb2ca0(&self->unk10, &axis, &angle);
        ((Ceb2Obj*)&a3->r)->FUN_00cb2450(&self->unk10, angle);
    }
}

extern const float DAT_0104da4c = 1.1920928955078125e-7f;

struct ByteResult
{
    char value;
    ByteResult(bool b) : value(b)
    {}
};

struct VectorTest
{
    __m128 m_data;

    ByteResult FUN_00ce1500() const;
};

// @fnv 0x00ce1500
ByteResult VectorTest::FUN_00ce1500() const
{
    __m128 v = m_data;
    float scale = DAT_0104da4c;
    __m128 a = _mm_mul_ps(v, v);
    __m128 b = _mm_shuffle_ps(a, a, 0x55);
    __m128 c = _mm_shuffle_ps(a, a, 0xaa);
    b = _mm_add_ss(b, a);
    c = _mm_add_ss(c, b);
    c = _mm_sqrt_ss(c);
    __m128 r = c;
    float f;
    _mm_store_ss(&f, r);
    return ByteResult(f > scale);
}

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;

class hkQuaternionC18;

class hkVector4C18
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4C18& operator=(const hkVector4C18& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4C18& a, const hkVector4C18& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4C18& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4C18& a, const hkVector4C18& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4C18& a, const hkVector4C18& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4C18& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4C18& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4C18& v1, const hkVector4C18& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4C18& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4C18& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionC18& q, const hkVector4C18& dir);
    void setRotatedInverseDir(const hkQuaternionC18& q, const hkVector4C18& dir);
};

class hkQuaternionC18
{
  public:
    hkVector4C18 m_vec;

    __forceinline void SetConjugate(const hkQuaternionC18& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionC18& q0, const hkQuaternionC18& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

__forceinline void hkVector4C18::SetRotatedDirection(const hkQuaternionC18& quat, const hkVector4C18& direction)
{
    hkVector4C18 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4C18 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4C18 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4C18 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4C18::setRotatedInverseDir(const hkQuaternionC18& quat, const hkVector4C18& direction)
{
    hkVector4C18 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4C18 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4C18 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4C18 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformC18
{
  public:
    hkVector4C18 m_vTranslation;
    hkQuaternionC18 m_rotation;
    hkVector4C18 m_vScale;

    __forceinline void SetConjugate(const hkQsTransformC18& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.m_vComponents = _mm_xor_ps(m_vTranslation.m_vComponents, DAT_010c44d0);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4C18 s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
    }
    __forceinline void SetProduct(const hkQsTransformC18& t1, const hkQsTransformC18& t2)
    {
        hkVector4C18 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.SetProduct(t1.m_rotation, t2.m_rotation);
        m_vScale.m_vComponents = _mm_mul_ps(m_vScale.m_vComponents, t1.m_vScale.m_vComponents);
    }
    __forceinline void SetMulInverse(const hkQsTransformC18& a, const hkQsTransformC18& b)
    {
        hkQsTransformC18 h;
        h.SetConjugate(a);
        SetProduct(h, b);
    }
};

struct hkaSkeletonC18
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_iBoneCount;
};

class RagdollMapperC18
{
  public:
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
    hkaSkeletonC18* m_pkSkeleton;

    void getWorldPose(hkQsTransformC18* pkPoseOut);
    void FUN_00ce18f0(hkQsTransformC18* pkPoseOut, const hkQsTransformC18& kWorldFromModel);
};

// @fnv 0x00ce18f0
void RagdollMapperC18::FUN_00ce18f0(hkQsTransformC18* pkPoseOut, const hkQsTransformC18& kWorldFromModel)
{
    getWorldPose(pkPoseOut);
    int iNumBones = m_pkSkeleton->m_iBoneCount;
    hkQsTransformC18 kModelFromWorld;
    kModelFromWorld.SetConjugate(kWorldFromModel);
    for (int i = 0; i < iNumBones; i++)
        pkPoseOut[i].SetProduct(kModelFromWorld, pkPoseOut[i]);
}

extern "C" void _ReadWriteBarrier();
// Near miss: two load-register encodings remain under accepted GS- flags and RTM.

struct hkVec4
{
    __m128 m_vComponents;
};
extern const __m128 DAT_01017d10;
extern __m128 DAT_010c71e0;
extern __m128 DAT_010c4c00;
struct hkRot3
{
    hkVec4 m_kColumn0, m_kColumn1, m_kColumn2;
};
struct hkQuat
{
    hkVec4 m_vec;
    void FUN_00cb26e0(const hkRot3& r);
    void FUN_00c66320(const hkQuat& a, const hkQuat& b);
};
// @fnv 0x00ce0ff0
static __declspec(noinline) void FUN_00ce0ff0(const hkVec4& dir, hkQuat& q)
{
    hkVec4 perp;
    perp.m_vComponents = _mm_setzero_ps();
    hkVec4 a;
    a.m_vComponents = _mm_and_ps(dir.m_vComponents, DAT_01017d10);
    const float* f = (const float*)&a;
    int major;
    if (f[0] < f[1])
        major = (f[1] < f[2]) ? 2 : 1;
    else
        major = (f[0] < f[2]) ? 2 : 0;
    ((float*)&perp)[(major + 1) % 3] = 1.0f;

    __m128 qv = q.m_vec.m_vComponents;
    __m128 w = _mm_shuffle_ps(qv, qv, 0xff);
    __m128 d = dot3(qv, perp.m_vComponents);
    __m128 r0 = _mm_mul_ps(cross3(qv, perp.m_vComponents), w);
    __m128 t = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), perp.m_vComponents);
    t = _mm_add_ps(t, _mm_mul_ps(_mm_shuffle_ps(d, d, 0), qv));
    __m128 r = _mm_add_ps(r0, t);
    r = _mm_add_ps(r, r);

    __m128 dirQuad = dir.m_vComponents;
    __m128 c = cross3(r, dirQuad);

    const __m128 half = _mm_set_ss(0.5f);
    const __m128 three = _mm_set_ss(3.0f);
    const __m128 zero = _mm_set_ss(0.0f);

    const __m128 len2 = dot3(c, c);
    const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);

    const __m128 approx = _mm_rsqrt_ss(len2);
    const __m128 refined =
        _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
    __m128 s = _mm_andnot_ps(len2EqualsZero, refined);
    c = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), c);

    hkRot3 m;
    m.m_kColumn0.m_vComponents = cross3(dirQuad, c);
    m.m_kColumn1.m_vComponents = dirQuad;
    m.m_kColumn2.m_vComponents = c;
    hkQuat rq;
    rq.FUN_00cb26e0(m);
    hkQuat inv;
    __m128 mask = DAT_010c4c00;
    _ReadWriteBarrier();
    __m128 value = rq.m_vec.m_vComponents;
    _ReadWriteBarrier();
    inv.m_vec.m_vComponents = _mm_xor_ps(value, mask);
    hkQuat res;
    res.FUN_00c66320(inv, q);
    q.m_vec.m_vComponents = res.m_vec.m_vComponents;
}
// This ordinary array caller lets VC9 derive the internal register convention.
void AlignDirections(const hkVec4& dir, hkQuat* quaternions, int count)
{
    for (int i = 0; i < count; ++i)
        FUN_00ce0ff0(dir, quaternions[i]);
}

#include <math.h>
extern float DAT_0104da48;

class ScalarLane
{
    __m128 data;

  public:
    ScalarLane(const __m128& v) : data(v)
    {}
    operator float() const
    {
        float scalar;
        _mm_store_ss(&scalar, data);
        return scalar;
    }
};

struct PoseVector
{
    union
    {
        __m128 q;
        float component[4];
    };
    PoseVector()
    {}
    PoseVector(const __m128& v) : q(v)
    {}
    PoseVector(const PoseVector& other) : q(other.q)
    {}
    __forceinline void operator=(const PoseVector& other)
    {
        q = other.q;
    }
    ScalarLane dot(const PoseVector& other) const
    {
        __m128 product = _mm_mul_ps(q, other.q);
        __m128 pair = _mm_add_ps(_mm_shuffle_ps(product, product, 0x4e), product);
        __m128 swapped = _mm_shuffle_ps(pair, pair, 0xb1);
        return _mm_add_ps(pair, swapped);
    }
    __forceinline void cross(const PoseVector& a, const PoseVector& b)
    {
        q = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2)),
                       _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9)));
    }
    __forceinline void normalize()
    {
        __m128 square = _mm_mul_ps(q, q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(square, square, 0x55), square);
        __m128 length = _mm_add_ss(_mm_shuffle_ps(square, square, 0xaa), xy);
        __m128 estimate = _mm_rsqrt_ss(length);
        __m128 zero = _mm_cmpeq_ss(length, _mm_setzero_ps());
        __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(length, estimate), estimate));
        __m128 scale = _mm_andnot_ps(zero, _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction));
        q = _mm_mul_ps(q, _mm_shuffle_ps(scale, scale, 0));
    }
};

struct PoseBasis
{
    PoseVector x, y, z;
};
struct PoseRotation
{
    PoseVector vector;
    PoseRotation()
    {}
    __forceinline void operator=(const PoseRotation& other)
    {
        vector = other.vector;
    }
    void FUN_00cb26e0(const PoseBasis& basis);
    void FUN_00c66320(const PoseRotation& a, const PoseRotation& b);
};

static __declspec(noinline) void FUN_00ce0ff0(const PoseVector& axis, PoseRotation& value)
{
    PoseVector side;
    side.q = _mm_setzero_ps();
    PoseVector magnitudes;
    magnitudes.q = _mm_andnot_ps(_mm_set1_ps(-0.0f), axis.q);
    int major = magnitudes.component[0] < magnitudes.component[1]
                    ? (magnitudes.component[1] < magnitudes.component[2] ? 2 : 1)
                    : (magnitudes.component[0] < magnitudes.component[2] ? 2 : 0);
    side.component[(major + 1) % 3] = 1.0f;
    __m128 rotation = value.vector.q;
    __m128 real = _mm_shuffle_ps(rotation, rotation, 0xff);
    __m128 factor = _mm_add_ps(_mm_set1_ps(-0.5f), _mm_mul_ps(real, real));
    __m128 product = _mm_mul_ps(rotation, side.q);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    __m128 result = _mm_add_ps(_mm_mul_ps(side.q, factor), _mm_mul_ps(_mm_shuffle_ps(sum, sum, 0), rotation));
    PoseVector perpendicular;
    perpendicular.cross(value.vector, side);
    result = _mm_add_ps(result, _mm_mul_ps(real, perpendicular.q));
    side.q = _mm_add_ps(result, result);
    PoseVector up;
    up.cross(side, axis);
    up.normalize();
    side.cross(axis, up);
    PoseBasis basis;
    basis.x = side;
    basis.y = axis;
    basis.z = up;
    PoseRotation frame;
    frame.FUN_00cb26e0(basis);
    PoseRotation inverse;
    inverse.vector.q = _mm_xor_ps(frame.vector.q, _mm_set_ps(0.0f, -0.0f, -0.0f, -0.0f));
    PoseRotation composed;
    composed.FUN_00c66320(inverse, value);
    value = composed;
}

struct CandidatePose
{
    PoseRotation reference;
    const void* binding;
    float time;
};
struct PoseMatcher
{
    hkArray<CandidatePose> candidates;
    PoseVector axis;
    short rootBone, otherBone, thirdBone;
    void FUN_00ce0d30(const hkQsTransform* pose, PoseRotation& out) const;
    int FUN_00ce11f0(const hkQsTransform* pose, float& error) const;
};

inline float magnitude(float value)
{
    return fabsf(value);
}

// @fnv 0x00ce11f0
int PoseMatcher::FUN_00ce11f0(const hkQsTransform* pose, float& error) const
{
    PoseRotation orientation;
    FUN_00ce0d30(pose, orientation);
    FUN_00ce0ff0(axis, orientation);
    int selected = -1;
    error = DAT_0104da48;
    for (int index = 0; index < candidates.m_iElementCount; ++index)
    {
        float distance = 1.0f - magnitude(orientation.vector.dot(candidates.m_data[index].reference.vector));
        if (distance < error)
        {
            selected = index;
            error = distance;
        }
    }
    return selected;
}

extern "C"
{
}

extern __m128 DAT_010c71e0;
extern __m128 DAT_010c7170;
extern __m128 DAT_010c44d0;
extern __m128 DAT_010c4c00;
extern __m128 DAT_010c4c10;
extern __m128 DAT_010c71b0;

class hkQuaternionC17;

class hkVector4C17
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4C17& operator=(const hkVector4C17& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4C17& a, const hkVector4C17& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4C17& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4C17& a, const hkVector4C17& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4C17& a, const hkVector4C17& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4C17& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4C17& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4C17& v1, const hkVector4C17& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4C17& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    __forceinline void setReciprocal4(const hkVector4C17& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionC17& q, const hkVector4C17& dir);
    void setRotatedInverseDir(const hkQuaternionC17& q, const hkVector4C17& dir);
};

struct hkRotationC17
{
    hkVector4C17 m_kColumn0;
    hkVector4C17 m_kColumn1;
    hkVector4C17 m_kColumn2;
};

struct hkTransformC17
{
    hkRotationC17 m_rotation;
    hkVector4C17 m_vTranslation;
};

class hkQuaternionC17
{
  public:
    hkVector4C17 m_vec;

    void set(const hkRotationC17& kRotationBasis);

    __forceinline void SetConjugate(const hkQuaternionC17& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void FUN_00c66320(const hkQuaternionC17& q0, const hkQuaternionC17& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                                  _mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)));
        __m128 aw = _mm_shuffle_ps(a, a, 0xff);
        __m128 bw = _mm_shuffle_ps(b, b, 0xff);
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), 0xc4);
    }
};

__forceinline void hkVector4C17::SetRotatedDirection(const hkQuaternionC17& quat, const hkVector4C17& direction)
{
    hkVector4C17 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, 0xff);
    hkVector4C17 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, DAT_010c71e0);
    hkVector4C17 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4C17 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformC17
{
  public:
    hkVector4C17 m_vTranslation;
    hkQuaternionC17 m_rotation;
    hkVector4C17 m_vScale;

    __declspec(noinline) void FUN_00ce5070(const hkTransformC17& kTransform)
    {
        m_rotation.set(kTransform.m_rotation);
        m_vTranslation = kTransform.m_vTranslation;
        m_vScale.m_vComponents = DAT_010c7170;
    }
    __forceinline void SetProduct(const hkQsTransformC17& t1, const hkQsTransformC17& t2)
    {
        hkVector4C17 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.FUN_00c66320(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
};

struct hkaSkeletonC17
{
    int unk00;
    int unk04;
    int unk08;
    short* m_kParentIndices;
    int unk10;
    int unk14;
    int unk18;
    int m_iBoneCount;
    int unk20;
    hkQsTransformC17* m_kReferencePose;
};

extern "C" void __cdecl MultiplyBoneScales(const hkaSkeletonC17*, const hkQsTransformC17*, int, hkVector4C17&);

struct RigidBodyC17
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    hkTransformC17 m_kMotionTransform;
};

class Ragdoll4
{
  public:
    int unk00;
    int unk04;
    RigidBodyC17** m_ppBodies;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int* m_piBoneToBody;
    int unk24;
    int unk28;
    hkaSkeletonC17* m_pkSkeleton;

    void FUN_00ce1760(hkQsTransformC17* pkPoseOut, const hkQsTransformC17& kRoot, const hkQsTransformC17* pkLocalPose);
};

// @fnv 0x00ce1760
void Ragdoll4::FUN_00ce1760(hkQsTransformC17* pkPoseOut, const hkQsTransformC17& kRoot,
                            const hkQsTransformC17* pkLocalPose)
{
    if (!pkLocalPose)
        pkLocalPose = m_pkSkeleton->m_kReferencePose;

    for (int i = 0; i < m_pkSkeleton->m_iBoneCount; i++)
    {
        int iBody = m_piBoneToBody[i];
        if (iBody >= 0)
        {
            RigidBodyC17* pkBody = m_ppBodies[iBody];
            if (pkBody)
            {
                pkPoseOut[i].FUN_00ce5070(pkBody->m_kMotionTransform);
                MultiplyBoneScales(m_pkSkeleton, m_pkSkeleton->m_kReferencePose, i, pkPoseOut[i].m_vScale);
                continue;
            }
        }

        int iParent = m_pkSkeleton->m_kParentIndices[i];
        hkQsTransformC17 kParent;
        (iParent >= 0) ? (kParent = pkPoseOut[iParent]) : (kParent = kRoot);
        pkPoseOut[i].SetProduct(kParent, pkLocalPose[i]);
    }
}

#include <xmmintrin.h>
namespace fnv_00ce1ad0 {
#include <xmmintrin.h>

extern __declspec(align(16)) float DAT_01267e30;
extern __declspec(align(16)) const float DAT_010c71e0;
extern __declspec(align(16)) const float DAT_01017d10;

struct __declspec(align(16)) FUN_005611c0_t;

struct __declspec(align(16)) hkVec4
{
    float x, y, z, w;

    const __m128& get() const
    {
        return reinterpret_cast<const __m128&>(x);
    }
    void set(__m128 v)
    {
        reinterpret_cast<__m128&>(x) = v;
    }

    void SetRotatedDirection(const FUN_005611c0_t& quat, const hkVec4& direction);
    void setAdd4(const hkVec4& a, const hkVec4& b)
    {
        set(_mm_add_ps(a.get(), b.get()));
    }
    void setMul4(const hkVec4& a, const hkVec4& b)
    {
        set(_mm_mul_ps(a.get(), b.get()));
    }
    bool equals4(const float* v) const
    {
        __m128 t = _mm_and_ps(_mm_sub_ps(_mm_load_ps(v), get()), _mm_load_ps(&DAT_01017d10));
        __m128 eps = _mm_set1_ps(1e-3f);
        return (_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 0xf) == 0xf;
    }
};

struct __declspec(align(16)) FUN_005611c0_t
{
    float x, y, z, w;

    const __m128& get() const
    {
        return reinterpret_cast<const __m128&>(x);
    }

    void FUN_00c66320(const FUN_005611c0_t* q0, const FUN_005611c0_t* q1);
    void FUN_005611c0();
};

__forceinline void hkVec4::SetRotatedDirection(const FUN_005611c0_t& quat, const hkVec4& direction)
{
    __m128 q = quat.get();
    __m128 dir = direction.get();
    __m128 qreal = _mm_shuffle_ps(q, q, 0xff);
    __m128 ret = _mm_mul_ps(_mm_add_ps(_mm_load_ps(&DAT_010c71e0), _mm_mul_ps(qreal, qreal)), dir);
    __m128 x2 = _mm_mul_ps(q, dir);
    __m128 d = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    ret = _mm_add_ps(ret, _mm_mul_ps(_mm_shuffle_ps(d, d, 0), q));
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(dir, dir, 0xd2)),
                              _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(dir, dir, 0xc9)));
    ret = _mm_add_ps(ret, _mm_mul_ps(qreal, cross));
    set(_mm_add_ps(ret, ret));
}

struct RagQsTransform
{
    hkVec4 m_vTranslation;
    FUN_005611c0_t m_rotation;
    hkVec4 m_vScale;

    __forceinline void SetProduct(const RagQsTransform& t1, const RagQsTransform& t2)
    {
        hkVec4 extraTrans;
        extraTrans.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(extraTrans, t1.m_vTranslation);
        m_rotation.FUN_00c66320(&t1.m_rotation, &t2.m_rotation);
        m_vScale.set(_mm_mul_ps(_mm_load_ps(&t1.m_vScale.x), t2.m_vScale.get()));
    }
};

struct RagMotion
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void SetTranslationalVelocity(const float* v);
    virtual void SetRotationalVelocity(const float* v);
};

struct UnkCall
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
    int unkd4;
    int unkd8;
    int unkdc;
    RagMotion m_pMotionState;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    __m128 m_kTranslationalVelocity;
    __m128 m_kAngularVelocity;

    void FUN_00c9c1d0();
    void FUN_00ca8860(const hkVec4* pos, const FUN_005611c0_t* rot);

    void SetTranslationalVelocity(const float* v)
    {
        FUN_00c9c1d0();
        m_pMotionState.SetTranslationalVelocity(v);
    }
    void SetRotationalVelocity(const float* v)
    {
        FUN_00c9c1d0();
        m_pMotionState.SetRotationalVelocity(v);
    }
};

struct RagSkeleton
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_kBones;
    int m_iBoneCount;
};

struct RagInstance
{
    int unk00;
    int unk04;
    UnkCall** m_ppRigidBodies;
    int m_iRigidBodyCount;
    int m_rigidBodiesCap;
    void** m_ppConstraints;
    int m_iConstraintCount;
    int m_constraintsCap;
    int* m_kBoneMap;
    int m_numMap;
    int m_mapCap;
    RagSkeleton* m_pSkeleton;

    UnkCall* getRigidBodyOfBone(int b) const
    {
        int rbIdx = m_kBoneMap[b];
        if (rbIdx < 0)
            return 0;
        return m_ppRigidBodies[rbIdx];
    }

    void FUN_00ce1ad0(const RagQsTransform* pose, const RagQsTransform& worldFromModel);
};

static __forceinline bool equals4(const __m128& a, const float* v)
{
    __m128 t =
        _mm_and_ps(_mm_sub_ps(reinterpret_cast<const __m128&>(*v), a), reinterpret_cast<const __m128&>(DAT_01017d10));
    __m128 eps = _mm_set1_ps(1e-3f);
    return (_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 0xf) == 0xf;
}

// @fnv 0x00ce1ad0
void RagInstance::FUN_00ce1ad0(const RagQsTransform* pose, const RagQsTransform& worldFromModel)
{
    int numBones = m_pSkeleton->m_iBoneCount;
    for (int b = 0; b < numBones; b++, pose++)
    {
        UnkCall* rb = getRigidBodyOfBone(b);
        if (rb)
        {
            RagQsTransform rbWorld;
            rbWorld.SetProduct(worldFromModel, *pose);
            rbWorld.m_rotation.FUN_005611c0();
            rb->FUN_00ca8860(&rbWorld.m_vTranslation, &rbWorld.m_rotation);

            const float* zero = &DAT_01267e30;
            if (!equals4(rb->m_kTranslationalVelocity, zero))
                rb->SetTranslationalVelocity(zero);
            if (!equals4(rb->m_kAngularVelocity, zero))
                rb->SetRotationalVelocity(zero);
        }
    }
}
}  // namespace fnv_00ce1ad0
