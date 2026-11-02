
// src/havok/common/base/math/matrix/hkmatrix4_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/math/matrix/hkmatrix4.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/math/matrix/hkmatrix4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00de8f30_Class
{
    float m_data[16];
    void TransposeTo(float* dst);
};
struct FUN_00de8f10_Class
{
    float m_data[16];
    void FUN_00de8f10();
};
struct FUN_00de8fa0_Class
{
    float m_data[16];
    void FUN_00de8fa0(const float* src);
};
struct FUN_00de9010_Class
{
    float m_data[16];
    void CopyTo(float* dst);
};
struct FUN_00de9080_Class
{
    float m_data[16];
    void CopyFromFloats(const float* src);
};
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;
struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    void operator=(const hkVector4& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
};
struct hkMatrix4
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_kColumn3;
    void FUN_00de8da0(const hkMatrix4& a, const hkMatrix4& b);
    void FUN_00de8e50(const hkMatrix4& b);
    void operator=(const hkMatrix4& o)
    {
        m_kColumn0 = o.m_kColumn0;
        m_kColumn1 = o.m_kColumn1;
        m_kColumn2 = o.m_kColumn2;
        m_kColumn3 = o.m_kColumn3;
    }
};
struct FUN_00de90f0_Class
{
    __m128 rows[4];
    void FUN_00de90f0(const __m128* source);
};
struct CB20B0_Class
{
    void FUN_00cb20b0(void* src);
};
struct Matrix44_shell
{
    float m_data[16];
    void FUN_00de9130(CB20B0_Class* dst);
};
struct Owner
{
    __m128 row00;
    __m128 row10;
    __m128 row20;
    __m128 row30;
    void FUN_00de8910(float value);
    void FUN_00de8c50(const __m128* source, float value);
};
struct SourceBlockCDF
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
};
struct TargetBlockCDF
{
    void FUN_00cd55b0(SourceBlockCDF* pkSource, int iArg);
};
struct FUN_00cdf230_cls
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
    SourceBlockCDF m_kSource;
    TargetBlockCDF m_kRoomNode;
    void FUN_00cdf230(int iArg);
};
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
struct Row
{
    __m128 v;
    void operator+=(const Row& o)
    {
        __m128 t = o.v;
        v = _mm_add_ps(t, v);
    }
};
struct MatR
{
    Row m_row0;
    Row m_row1;
    Row m_row2;
    Row m_row3;
    const MatR* Add(const MatR* other);
};

extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_load_ss(const float*);
}

class S00de9140_SimdReal
{
  public:
    __forceinline S00de9140_SimdReal(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __m128 m_vValue;
};

class S00de9140_Vector4
{
  public:
    __forceinline S00de9140_Vector4()
    {}
    __forceinline S00de9140_Vector4(const S00de9140_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const S00de9140_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setMul4(const S00de9140_SimdReal& r, const S00de9140_Vector4& v)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v.m_vComponents);
    }
    __forceinline void add4(const S00de9140_Vector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setMul4(const S00de9140_Vector4& a, const S00de9140_Vector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const S00de9140_Vector4& x, const S00de9140_Vector4& y)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
    }
    __forceinline void setBroadcast(const S00de9140_Vector4& v, int i)
    {
        if (i == 0)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
        }
        else if (i == 1)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
        }
        else if (i == 2)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
        }
        else if (i == 3)
        {
            m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
        }
    }
    float& operator()(int i)
    {
        return ((float*)&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return ((const float*)&m_vComponents)[i];
    }
    __m128 m_vComponents;
};

class S00de9140_Matrix4
{
  public:
    S00de9140_Vector4 m_kColumn0;
    S00de9140_Vector4 m_kColumn1;
    S00de9140_Vector4 m_kColumn2;
    S00de9140_Vector4 m_kColumn3;

    __forceinline S00de9140_Matrix4()
    {}
    __forceinline S00de9140_Vector4& getColumn(int x)
    {
        return (&m_kColumn0)[x];
    }
    __forceinline const S00de9140_Vector4& getColumn(int x) const
    {
        return (&m_kColumn0)[x];
    }
    __forceinline float& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }
    __forceinline const float& operator()(int r, int c) const
    {
        return getColumn(c)(r);
    }
    __forceinline void operator=(const S00de9140_Matrix4& a)
    {
        m_kColumn0 = a.getColumn(0);
        m_kColumn1 = a.getColumn(1);
        m_kColumn2 = a.getColumn(2);
        m_kColumn3 = a.getColumn(3);
    }

    void FUN_00de88a0(const S00de9140_SimdReal& s, const S00de9140_Matrix4& m);
    int FUN_00de8910(float epsilon);

    __forceinline void transformPosition(const S00de9140_Vector4& positionIn, S00de9140_Vector4& positionOut) const
    {
        S00de9140_Vector4 xb;
        xb.setBroadcast(positionIn, 0);
        S00de9140_Vector4 yb;
        yb.setBroadcast(positionIn, 1);
        S00de9140_Vector4 zb;
        zb.setBroadcast(positionIn, 2);

        S00de9140_Vector4 t0;
        t0.setMul4(xb, m_kColumn0);
        t0.addMul4(yb, m_kColumn1);
        t0.addMul4(zb, m_kColumn2);
        t0.add4(m_kColumn3);

        positionOut = t0;
    }

    __forceinline void transformDirection(const S00de9140_Vector4& directionIn, S00de9140_Vector4& directionOut) const
    {
        S00de9140_Vector4 xb;
        xb.setBroadcast(directionIn, 0);
        S00de9140_Vector4 yb;
        yb.setBroadcast(directionIn, 1);
        S00de9140_Vector4 zb;
        zb.setBroadcast(directionIn, 2);

        S00de9140_Vector4 t0;
        t0.setMul4(xb, m_kColumn0);
        t0.addMul4(yb, m_kColumn1);
        t0.addMul4(zb, m_kColumn2);

        directionOut = t0;
    }

    __forceinline void setMulAffine(const S00de9140_Matrix4& a, const S00de9140_Matrix4& b)
    {
        S00de9140_Vector4 col0;
        a.transformDirection(b.m_kColumn0, col0);
        S00de9140_Vector4 col1;
        a.transformDirection(b.m_kColumn1, col1);
        S00de9140_Vector4 col2;
        a.transformDirection(b.m_kColumn2, col2);
        S00de9140_Vector4 col3;
        a.transformPosition(b.m_kColumn3, col3);

        m_kColumn0 = col0;
        m_kColumn1 = col1;
        m_kColumn2 = col2;
        m_kColumn3 = col3;
    }

    void FUN_00de9140(const S00de9140_Matrix4& a, const S00de9140_Matrix4& b);
};

__declspec(noinline) void S00de9140_Matrix4::FUN_00de88a0(const S00de9140_SimdReal& s, const S00de9140_Matrix4& m)
{
    m_kColumn0.setMul4(s, m.m_kColumn0);
    m_kColumn1.setMul4(s, m.m_kColumn1);
    m_kColumn2.setMul4(s, m.m_kColumn2);
    m_kColumn3.setMul4(s, m.m_kColumn3);
}

int S00de9140_Matrix4::FUN_00de8910(float epsilon)
{
    S00de9140_Matrix4& m = *this;

    float a0 = m(0, 0) * m(1, 1) - m(0, 1) * m(1, 0);
    float a1 = m(0, 0) * m(1, 2) - m(0, 2) * m(1, 0);
    float a2 = m(0, 0) * m(1, 3) - m(0, 3) * m(1, 0);
    float a3 = m(0, 1) * m(1, 2) - m(0, 2) * m(1, 1);
    float a4 = m(0, 1) * m(1, 3) - m(0, 3) * m(1, 1);
    float a5 = m(0, 2) * m(1, 3) - m(0, 3) * m(1, 2);
    float b0 = m(2, 0) * m(3, 1) - m(2, 1) * m(3, 0);
    float b1 = m(2, 0) * m(3, 2) - m(2, 2) * m(3, 0);
    float b2 = m(2, 0) * m(3, 3) - m(2, 3) * m(3, 0);
    float b3 = m(2, 1) * m(3, 2) - m(2, 2) * m(3, 1);
    float b4 = m(2, 1) * m(3, 3) - m(2, 3) * m(3, 1);
    float b5 = m(2, 2) * m(3, 3) - m(2, 3) * m(3, 2);

    float det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
    float absDet = det < 0.0f ? -det : det;
    if (absDet <= epsilon)
    {
        return 1;
    }

    S00de9140_Matrix4 inv;
    inv(0, 0) = m(1, 1) * b5 - m(1, 2) * b4 + m(1, 3) * b3;
    inv(1, 0) = -m(1, 0) * b5 + m(1, 2) * b2 - m(1, 3) * b1;
    inv(2, 0) = m(1, 0) * b4 - m(1, 1) * b2 + m(1, 3) * b0;
    inv(3, 0) = -m(1, 0) * b3 + m(1, 1) * b1 - m(1, 2) * b0;
    inv(0, 1) = -m(0, 1) * b5 + m(0, 2) * b4 - m(0, 3) * b3;
    inv(1, 1) = m(0, 0) * b5 - m(0, 2) * b2 + m(0, 3) * b1;
    inv(2, 1) = -m(0, 0) * b4 + m(0, 1) * b2 - m(0, 3) * b0;
    inv(3, 1) = m(0, 0) * b3 - m(0, 1) * b1 + m(0, 2) * b0;
    inv(0, 2) = m(3, 1) * a5 - m(3, 2) * a4 + m(3, 3) * a3;
    inv(1, 2) = -m(3, 0) * a5 + m(3, 2) * a2 - m(3, 3) * a1;
    inv(2, 2) = m(3, 0) * a4 - m(3, 1) * a2 + m(3, 3) * a0;
    inv(3, 2) = -m(3, 0) * a3 + m(3, 1) * a1 - m(3, 2) * a0;
    inv(0, 3) = -m(2, 1) * a5 + m(2, 2) * a4 - m(2, 3) * a3;
    inv(1, 3) = m(2, 0) * a5 - m(2, 2) * a2 + m(2, 3) * a1;
    inv(2, 3) = -m(2, 0) * a4 + m(2, 1) * a2 - m(2, 3) * a0;
    inv(3, 3) = m(2, 0) * a3 - m(2, 1) * a1 + m(2, 2) * a0;

    S00de9140_SimdReal invDet(1.0f / det);
    FUN_00de88a0(invDet, inv);
    return 0;
}

// @fnv 0x00de9140
void S00de9140_Matrix4::FUN_00de9140(const S00de9140_Matrix4& a, const S00de9140_Matrix4& b)
{
    S00de9140_Matrix4 bInv = b;
    bInv.FUN_00de8910(1.192092896e-07f);
    setMulAffine(a, bInv);
}
