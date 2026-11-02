
// src/havok/animation/animation/mapper/hkaskeletonmapperutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/mapper/hkaskeletonmapperutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CE5F90QsTransform
{
    float m_vTranslation[4];
    float m_rotation[4];
    float m_vScale[4];
};

void __cdecl FUN_00ce5a70(CE5F90QsTransform* out, const CE5F90QsTransform* a, const CE5F90QsTransform* b, int mode,
                          float weightA, float weightB);

// @fnv 0x00ce5f90
void __cdecl FUN_00ce5f90(CE5F90QsTransform* out, const CE5F90QsTransform* poseA, short boneA,
                          const CE5F90QsTransform* poseB, short boneB, int mode, float weightA, float weightB)
{
    FUN_00ce5a70(out, &poseA[boneA], &poseB[boneB], mode, weightA, weightB);
}

#include <xmmintrin.h>
extern const float DAT_0104da48;
extern const float DAT_0104e148;

struct __declspec(align(16)) VertexRecord
{
    __m128 m_kPathOffset;
    int m_ai10;
    int m_ai14;
    int m_ai18;
    int m_ai1c;
    int m_ai20;
    int m_ai24;
    int m_ai28;
    int m_ai2c;
};

// Computes the min and max of m_kPathOffset across aiCount VertexRecord entries, storing results in apMin and apMax.
// @fnv 0x00ce5560
void __cdecl FUN_00ce5560(const VertexRecord* apVertices, int aiCount, __m128* apMin, __m128* apMax)
{
    *apMin = _mm_set1_ps(DAT_0104da48);
    *apMax = _mm_set1_ps(DAT_0104e148);

    for (int i = 0; i < aiCount; i++)
    {
        __m128 kForMin = apVertices[i].m_kPathOffset;
        *apMin = _mm_min_ps(*apMin, kForMin);
        __m128 kForMax = apVertices[i].m_kPathOffset;
        *apMax = _mm_max_ps(*apMax, kForMax);
    }
}

namespace fnv_00ce55d0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);

typedef float hkReal;

extern __m128 DAT_010c71b0;

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void SetAllComponents(hkReal r)
    {
        m_vComponents = _mm_set_ps1(r);
    }
    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline hkReal length3() const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
        hkReal r;
        _mm_store_ss(&r, _mm_sqrt_ss(len2));
        return r;
    }
};

struct hkQsTransformq
{
    hkVector4q m_vTranslation;
    hkVector4q m_rotation;
    hkVector4q m_vScale;

    __forceinline void setIdentity()
    {
        m_vTranslation.setZero4();
        m_rotation.m_vComponents = DAT_010c71b0;
        m_vScale.SetAllComponents(1.0f);
    }
};

struct ScaleParams
{
    int m_iValueAfterFlags;
    int m_sBoneA;
    int m_sBoneB;
    hkReal m_scaleA;
    hkReal m_scaleB;
};

void __cdecl FUN_00ce5560(const hkQsTransformq* pose, int numBones, hkVector4q& minOut, hkVector4q& maxOut);

// Computes scale factors for two poses based on ScaleParams mode, storing results in outA and outB.
// @fnv 0x00ce55d0
void __cdecl FUN_00ce55d0(const ScaleParams* params, int unused, const hkQsTransformq* poseA, int numBonesA,
                          const hkQsTransformq* poseB, int numBonesB, hkQsTransformq* outA, hkQsTransformq* outB)
{
    outA->setIdentity();
    outB->setIdentity();

    if (params->m_iValueAfterFlags == 0)
    {
        hkVector4q minA, maxA, minB, maxB;
        FUN_00ce5560(poseA, numBonesA, minA, maxA);
        FUN_00ce5560(poseB, numBonesB, minB, maxB);
        hkVector4q extA;
        extA.setSub4(maxA, minA);
        hkVector4q extB;
        extB.setSub4(maxB, minB);
        hkReal lenA = extA.length3();
        hkReal lenB = extB.length3();
        hkReal fScaleA = lenB / lenA * params->m_scaleB / params->m_scaleA;
        hkReal fScaleB = lenA / lenB * params->m_scaleA / params->m_scaleB;
        outA->m_vScale.SetAllComponents(fScaleA);
        outB->m_vScale.SetAllComponents(fScaleB);
    }
    else if (params->m_iValueAfterFlags == 1)
    {
        hkReal lenA = poseA[params->m_sBoneA].m_vTranslation.length3();
        hkReal lenB = poseB[params->m_sBoneB].m_vTranslation.length3();
        hkReal fScaleA = lenB / lenA * params->m_scaleB / params->m_scaleA;
        hkReal fScaleB = lenA / lenB * params->m_scaleA / params->m_scaleB;
        outA->m_vScale.SetAllComponents(fScaleA);
        outB->m_vScale.SetAllComponents(fScaleB);
    }
    else
    {
        outA->m_vScale.SetAllComponents(params->m_scaleB / params->m_scaleA);
        outB->m_vScale.SetAllComponents(params->m_scaleA / params->m_scaleB);
    }
}
}  // namespace fnv_00ce55d0

#include <math.h>
struct ThresholdState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float threshold;
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
    int mode;
};

struct ValueSource
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

extern "C" float __cdecl GetAngle();
typedef float(__thiscall* ReadValue)(void*);

// Returns 1 if state->mode is not 1, otherwise returns whether the larger absolute angle of first or second is at most state->threshold.
// @fnv 0x00ce57c0
unsigned char __cdecl FUN_00ce57c0(ThresholdState* state, void* unused1, void* unused2, ValueSource* first,
                                   ValueSource* second)
{
    if (state->mode != 1)
        return 1;

    float a = fabs(reinterpret_cast<ReadValue>(GetAngle)(reinterpret_cast<char*>(first) + 0x10));
    float b = fabs(reinterpret_cast<ReadValue>(GetAngle)(reinterpret_cast<char*>(second) + 0x10));
    float fMaxAngle = a > b ? a : b;
    return static_cast<unsigned char>(fMaxAngle <= state->threshold);
}

namespace fnv_00ce5e60 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    void _mm_store_ss(float*, __m128);
}

typedef float hkReal;
typedef short hkInt16;

struct hkVector4f
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

union hkVector4q
{
    hkVector4f m_vec;
    __m128 m_vComponents;
};

struct hkQsTransformq
{
    hkVector4q m_vTranslation;
    hkVector4q m_rotation;
    hkVector4q m_vScale;
};

struct hkaSkeletonq
{
    int m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    const char* m_name;
    hkInt16* m_kParentIndices;
};

extern hkVector4q DAT_010c71e0;

static __forceinline __m128 hkDot3v(__m128 a, __m128 b)
{
    __m128 x2 = _mm_mul_ps(a, b);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xy);
}

static __forceinline __m128 hkCross(__m128 a, __m128 b)
{
    __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(c0, c1);
}

static __forceinline void hkSetRotatedDir(hkVector4q& out, const hkVector4q& quat, const hkVector4q& dir)
{
    __m128 q = quat.m_vComponents;
    __m128 d = dir.m_vComponents;
    __m128 qreal = _mm_shuffle_ps(q, q, 0xff);
    __m128 q2minus1 = _mm_add_ps(_mm_mul_ps(qreal, qreal), DAT_010c71e0.m_vComponents);
    __m128 ret = _mm_mul_ps(d, q2minus1);
    __m128 imagDotDir = hkDot3v(quat.m_vComponents, dir.m_vComponents);
    ret = _mm_add_ps(ret, _mm_mul_ps(_mm_shuffle_ps(imagDotDir, imagDotDir, 0), q));
    __m128 imagCrossDir = hkCross(q, d);
    ret = _mm_add_ps(ret, _mm_mul_ps(imagCrossDir, qreal));
    out.m_vComponents = _mm_add_ps(ret, ret);
}

static __forceinline hkReal hkLength3(const hkVector4q& v)
{
    __m128 l2 = hkDot3v(v.m_vComponents, v.m_vComponents);
    hkReal r;
    _mm_store_ss(&r, _mm_sqrt_ss(l2));
    return r;
}

// Walks the parent chain from bone to ancestor, rotating the accumulated position, adding translations, and summing their lengths.
// @fnv 0x00ce5e60
void FUN_00ce5e60(const hkaSkeletonq* apSkeleton, const hkQsTransformq* poses, hkInt16 ancestor, hkInt16 bone,
                  hkReal* pfLengthOut, hkVector4q* posOut)
{
    *pfLengthOut = 0.0f;
    posOut->m_vComponents = _mm_setzero_ps();
    for (hkInt16 b = bone; b > ancestor; b = apSkeleton->m_kParentIndices[b])
    {
        const hkQsTransformq& t = poses[b];
        hkVector4q tmp;
        tmp.m_vec = posOut->m_vec;
        hkSetRotatedDir(*posOut, t.m_rotation, tmp);
        posOut->m_vComponents = _mm_add_ps(posOut->m_vComponents, t.m_vTranslation.m_vComponents);
        *pfLengthOut += hkLength3(t.m_vTranslation);
    }
}
}  // namespace fnv_00ce5e60

namespace fnv_00ce5fe0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_set_ps1(float);
}

typedef float hkReal;
typedef short hkInt16;

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void normalize3()
    {
        __m128 p = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                              _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
        r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline void operator=(const hkQuaternion& q)
    {
        m_vec.m_vComponents = q.m_vec.m_vComponents;
    }
    void FUN_00cd9d10(const hkVector4& from, const hkVector4& to);
    void FUN_00c74b70(const hkQuaternion& a, const hkQuaternion& b);
};

struct hkQsTransform
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
};

struct hkaSkeleton;

struct BonePairInfo
{
    hkInt16 m_boneA0;
    hkInt16 m_boneA1;
    hkInt16 m_boneB0;
    hkInt16 m_boneB1;
    int unk08;
    int unk0C;
    hkVector4 m_offset;
    hkVector4 unk20;
    hkVector4 unk30;
    hkQuaternion m_rotation;
    hkQuaternion m_relRotation;
    hkVector4 m_vScale;
};

void FUN_00ce5f90(const void* data, const hkQsTransform* poseA, hkInt16 boneA, const hkQsTransform* poseB,
                  hkInt16 boneB, hkVector4* out, hkReal eps, hkReal weight);
void FUN_00ce5e60(const hkaSkeleton* skel, const hkQsTransform* poses, hkInt16 ancestor, hkInt16 bone,
                  hkReal* lengthOut, hkVector4* posOut);

// Fills out with bone indices, offset, rotation, scale, and relative rotation derived from two skeleton bone pairs.
// @fnv 0x00ce5fe0
void FUN_00ce5fe0(const void* data, const hkaSkeleton* skelA, const hkQsTransform* poseA, hkInt16 boneA0,
                  hkInt16 boneA1, const hkaSkeleton* skelB, const hkQsTransform* poseB, hkInt16 boneB0, hkInt16 boneB1,
                  BonePairInfo* out)
{
    out->m_boneA0 = boneA0;
    out->m_boneA1 = boneA1;
    out->m_boneB0 = boneB0;
    out->m_boneB1 = boneB1;
    FUN_00ce5f90(data, poseA, boneA0, poseB, boneB0, &out->m_offset, 1e-5f, 1.0f);

    hkReal lenA;
    hkReal lenB;
    hkVector4 dirA;
    hkVector4 dirB;
    FUN_00ce5e60(skelA, poseA, boneA0, boneA1, &lenA, &dirA);
    FUN_00ce5e60(skelB, poseB, boneB0, boneB1, &lenB, &dirB);

    dirA.normalize3();
    dirB.normalize3();

    hkQuaternion rot;
    rot.FUN_00cd9d10(dirB, dirA);
    out->m_rotation = rot;
    lenA = 1.0f / lenA;
    out->m_vScale.m_vComponents = _mm_set_ps1(lenA);
    out->m_relRotation.FUN_00c74b70(poseA[boneA1].m_rotation, poseB[boneB1].m_rotation);
}
}  // namespace fnv_00ce5fe0

typedef unsigned int size_t;

inline void* operator new(size_t, void* p)
{
    return p;
}

struct hkMemoryAllocator;

struct hkMemoryRouterStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
    hkMemoryAllocator* m_pStreamAllocator;
};

hkMemoryRouterStub* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(hkMemoryAllocator* mem, void* array, int numElems, int elemSize);

struct HkElem8
{
    int a;
    int b;
};

template <typename T> struct HkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    HkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; i++)
        {
            dst[i] = src[i];
        }
    }

    __forceinline void constructWithCopy(T* dst, int n, const T* src)
    {
        for (int i = 0; i < n; i++)
        {
            new (dst + i) T(src[i]);
        }
    }

    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newCap = n < cap2 ? cap2 : n;
            FUN_00c908c0(&alloc, this, newCap, sizeof(T));
        }
    }

    __forceinline void copyFromArray(hkMemoryAllocator& alloc, const HkArray& a)
    {
        const int oldSize = m_iElementCount;
        const int newSize = a.m_iElementCount;
        const int copiedSize = newSize > oldSize ? oldSize : newSize;
        reserve(alloc, newSize);
        copy(m_data, a.m_data, copiedSize);
        constructWithCopy(m_data + copiedSize, newSize - copiedSize, a.m_data + copiedSize);
        m_iElementCount = newSize;
    }

    __forceinline HkArray& operator=(const HkArray& other)
    {
        copyFromArray(FUN_00c85750()->heap(), other);
        return *this;
    }
};

struct FUN_00ce9580
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
    float unk10;
    HkArray<HkElem8> arr14;
    HkArray<HkElem8> arr20;
    HkArray<HkElem8> arr2C;
    char unk38;
    char unk39;
    struct Tail
    {
        int unk3C;
        int unk40;
        int unk44;
        int unk48;
        int unk4C;
        int unk50;
    } tail;

    FUN_00ce9580(const FUN_00ce9580& other);
};

// Copies scalar fields and tail from other, then deep-copies the three HkArray<HkElem8> members via their operator=.
// @fnv 0x00ce9580
FUN_00ce9580::FUN_00ce9580(const FUN_00ce9580& other)
    : unk00(other.unk00), unk04(other.unk04), unk08(other.unk08), unk0C(other.unk0C), unk10(other.unk10), arr14(),
      arr20(), arr2C(), unk38(other.unk38), unk39(other.unk39), tail(other.tail)
{
    arr14 = other.arr14;
    arr20 = other.arr20;
    arr2C = other.arr2C;
}
