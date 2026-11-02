
// src/havok/physics/collide/util/hkptriangleutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/hkptriangleutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128;

extern "C" __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_sub_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_add_ss(__m128 _A, __m128 _B);
extern "C" __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);
extern "C" void _mm_store_ss(float* _V, __m128 _A);

typedef float hkReal;

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class VectorComponentValue
{
  public:
    __m128 m_vValue;
    VectorComponentValue(const __m128& x) : m_vValue(x)
    {}
    operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

class hkVector4
{
  public:
    __m128 m_vComponents;

    void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    VectorComponentValue lengthSquared3() const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
        return s;
    }
    VectorComponentValue dot3(const hkVector4& v) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        s = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), s);
        return s;
    }
};

// @fnv 0x00ceb8d0
hkBool __cdecl IsDegenerateTriangle(const hkVector4& aVertexA, const hkVector4& aVertexB, const hkVector4& aVertexC,
                                    hkReal tolerance)
{
    hkVector4 vAB;
    vAB.setSub4(aVertexA, aVertexB);
    hkVector4 vAC;
    vAC.setSub4(aVertexA, aVertexC);
    hkVector4 vNormal1;
    vNormal1.setCross(vAB, vAC);
    hkVector4 vBA;
    vBA.setSub4(aVertexB, aVertexA);
    hkVector4 vBC;
    vBC.setSub4(aVertexB, aVertexC);
    hkVector4 vNormal2;
    vNormal2.setCross(vBA, vBC);
    if (vNormal1.lengthSquared3() < tolerance || vNormal2.lengthSquared3() < tolerance)
        return true;
    hkVector4 vCB;
    vCB.setSub4(aVertexC, aVertexB);
    hkReal lab = vAB.dot3(vAB);
    hkReal lcb = vCB.lengthSquared3();
    hkReal fDot = vCB.dot3(vAB);
    hkReal fProduct = lab * lcb;
    hkReal fDotSq = fDot * fDot;
    hkReal fRemainder = fProduct - fDotSq;
    if (fRemainder == 0.0f)
        return true;
    return false;
}
