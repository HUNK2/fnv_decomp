
// src/havok/physics/collide/shape/hkpshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/hkpshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpShape.h"

// @fnv 0x00c9e3f0
int __stdcall FUN_00c9e3f0(void* p, int size)
{
    return -1;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);

extern const __m128 DAT_010c71d0;
extern const __m128 DAT_010c44d0;

namespace hkC9E5 {
struct VectorComponentValue
{
    __m128 m_vValue;

    operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

struct hkVector4
{
    __m128 m_vComponents;

    hkVector4()
    {}
    hkVector4(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    void mul4(const __m128& s)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, s);
    }
    void setFlipSign(const hkVector4& v, const hkVector4& sign)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, _mm_and_ps(sign.m_vComponents, DAT_010c44d0));
    }
    VectorComponentValue dot3(const hkVector4& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        VectorComponentValue r;
        r.m_vValue = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
        return r;
    }
};

struct hkMatrix3
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;

    void setIdentity()
    {
        hkVector4 kZero;
        kZero.setZero4();
        m_kColumn0 = kZero;
        m_kColumn1 = kZero;
        m_kColumn2 = kZero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct hkTransform
{
    hkMatrix3 m_rotation;
    hkVector4 m_vTranslation;

    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

struct hkAabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw();
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShape : public hkReferencedObject
{
  public:
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const hkTransform& kLocalToWorld, float fTolerance, hkAabb& kOut) const = 0;

    float FUN_00c9e560(const hkVector4& kDirection) const;

    unsigned long m_ulUserData;
    unsigned int m_type;
};

// Computes the support point of the shape's AABB along kDirection and returns its dot product with kDirection.
// @fnv 0x00c9e560
float hkpShape::FUN_00c9e560(const hkVector4& kDirection) const
{
    hkTransform kLocalToWorld;
    kLocalToWorld.setIdentity();
    const float fTolerance = 0.0f;
    hkAabb kAabb;
    getAabb(kLocalToWorld, fTolerance, kAabb);

    hkVector4 kTargetCenter;
    kTargetCenter.setAdd4(kAabb.m_kMinimumCorner, kAabb.m_kMaximumCorner);
    kTargetCenter.mul4(DAT_010c71d0);
    hkVector4 kHalfExtent;
    kHalfExtent.setSub4(kAabb.m_kMaximumCorner, kAabb.m_kMinimumCorner);
    kHalfExtent.mul4(DAT_010c71d0);

    hkVector4 kSupport;
    kSupport.setFlipSign(kHalfExtent, kDirection);
    kSupport.add4(kTargetCenter);
    return kSupport.dot3(kDirection);
}
}
