// src/havok/common/base/math/matrix/hkmatrix4_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/math/matrix/hkmatrix4_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHs-c- /Gy (unit lists /MT /O2 /GS- /EHs-c- /Gy). Declarations copied from that unit's skeleton.


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

static __forceinline float zvalue(const S00de9140_Vector4& v)
{
    return v.m_vComponents.m128_f32[2];
}
static __forceinline float scalarIdentity(float x)
{
    return x;
}
extern "C" double __cdecl fabs(double);
struct S00de8910_Work_b10903
{
    hkVector4 invDetVec;
    hkMatrix4 adj;
};

// @fnv 0x00de8910
int S00de9140_Matrix4::FUN_00de8910(float epsilon)
{
    const S00de9140_Vector4& column2 = m_kColumn2;
    const float& val2x = column2.m_vComponents.m128_f32[0];
    const float& val2y = column2.m_vComponents.m128_f32[1];
    const float& val2z = column2.m_vComponents.m128_f32[2];
    const float& val2w = column2.m_vComponents.m128_f32[3];

    float s0 =
        -((*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[1]) * m_kColumn1.m_vComponents.m128_f32[0]) +
        m_kColumn0.m_vComponents.m128_f32[0] * m_kColumn1.m_vComponents.m128_f32[1];
    float s1 = -((*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[1]) * val2x) +
               (*(const volatile float*)&val2y) * m_kColumn0.m_vComponents.m128_f32[0];
    float s2 =
        -((*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[1]) * m_kColumn3.m_vComponents.m128_f32[0]) +
        m_kColumn0.m_vComponents.m128_f32[0] * m_kColumn3.m_vComponents.m128_f32[1];
    float s3 = -(val2x * m_kColumn1.m_vComponents.m128_f32[1]) + val2y * m_kColumn1.m_vComponents.m128_f32[0];
    float s4 = -(m_kColumn3.m_vComponents.m128_f32[0] * m_kColumn1.m_vComponents.m128_f32[1]) +
               m_kColumn3.m_vComponents.m128_f32[1] * m_kColumn1.m_vComponents.m128_f32[0];
    float s5 = -(m_kColumn3.m_vComponents.m128_f32[0] * val2y) + val2x * m_kColumn3.m_vComponents.m128_f32[1];

    float c0 = -(m_kColumn1.m_vComponents.m128_f32[2] * m_kColumn0.m_vComponents.m128_f32[3]) +
               m_kColumn1.m_vComponents.m128_f32[3] * m_kColumn0.m_vComponents.m128_f32[2];
    float c1 = val2w * m_kColumn0.m_vComponents.m128_f32[2] -
               (*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[3]) * (float)(+val2z);
    float c2 = -(m_kColumn3.m_vComponents.m128_f32[2] * m_kColumn0.m_vComponents.m128_f32[3]) +
               m_kColumn3.m_vComponents.m128_f32[3] * m_kColumn0.m_vComponents.m128_f32[2];
    float c3 = -((*(const volatile float*)&m_kColumn1.m_vComponents.m128_f32[3]) * (*(const volatile float*)&val2z)) +
               val2w * m_kColumn1.m_vComponents.m128_f32[2];
    float c4 = -(m_kColumn3.m_vComponents.m128_f32[2] * m_kColumn1.m_vComponents.m128_f32[3]) +
               (*(const volatile float*)&m_kColumn3.m_vComponents.m128_f32[3]) * m_kColumn1.m_vComponents.m128_f32[2];
    float c5 = -(m_kColumn3.m_vComponents.m128_f32[2] * (*(const volatile float*)&val2w)) +
               (*(const volatile float*)&m_kColumn3.m_vComponents.m128_f32[3]) * (float)(double)val2z;

    S00de8910_Work_b10903 w;
    float det = (float)(s0)*c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0;
    float invDet = 1.0f / det;

    *(__m128*)&w.invDetVec = _mm_load_ss(&invDet);
    if ((float)fabs(det) <= epsilon)
    {
        return 1;
    }

    w.adj.m_kColumn0.x = m_kColumn1.m_vComponents.m128_f32[1] * c5 - scalarIdentity(val2y) * c4 +
                         m_kColumn3.m_vComponents.m128_f32[1] * c3;
    w.adj.m_kColumn0.y = -(*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[1]) * c5 + val2y * c2 -
                         m_kColumn3.m_vComponents.m128_f32[1] * c1;
    w.adj.m_kColumn0.z = -m_kColumn1.m_vComponents.m128_f32[1] * c2 +
                         (*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[1]) * c4 +
                         m_kColumn3.m_vComponents.m128_f32[1] * scalarIdentity(c0);
    w.adj.m_kColumn0.w = m_kColumn1.m_vComponents.m128_f32[1] * c1 -
                         (*(const volatile float*)&m_kColumn0.m_vComponents.m128_f32[1]) * c3 - val2y * c0;

    w.adj.m_kColumn1.x =
        -m_kColumn1.m_vComponents.m128_f32[0] * c5 + val2x * c4 - m_kColumn3.m_vComponents.m128_f32[0] * c3;
    w.adj.m_kColumn1.y =
        m_kColumn0.m_vComponents.m128_f32[0] * c5 - val2x * c2 + m_kColumn3.m_vComponents.m128_f32[0] * c1;
    w.adj.m_kColumn1.z = -m_kColumn0.m_vComponents.m128_f32[0] * c4 + m_kColumn1.m_vComponents.m128_f32[0] * c2 -
                         m_kColumn3.m_vComponents.m128_f32[0] * c0;
    w.adj.m_kColumn1.w =
        m_kColumn0.m_vComponents.m128_f32[0] * c3 - m_kColumn1.m_vComponents.m128_f32[0] * c1 + val2x * c0;

    w.adj.m_kColumn2.x =
        m_kColumn1.m_vComponents.m128_f32[3] * s5 - val2w * s4 + m_kColumn3.m_vComponents.m128_f32[3] * s3;
    w.adj.m_kColumn2.y =
        -m_kColumn0.m_vComponents.m128_f32[3] * s5 + val2w * s2 - (float)(m_kColumn3.m_vComponents.m128_f32[3]) * s1;
    w.adj.m_kColumn2.z = m_kColumn0.m_vComponents.m128_f32[3] * s4 - m_kColumn1.m_vComponents.m128_f32[3] * s2 +
                         m_kColumn3.m_vComponents.m128_f32[3] * s0;
    w.adj.m_kColumn2.w =
        -m_kColumn0.m_vComponents.m128_f32[3] * s3 + m_kColumn1.m_vComponents.m128_f32[3] * s1 - val2w * s0;

    w.adj.m_kColumn3.x = -m_kColumn1.m_vComponents.m128_f32[2] * s5 + zvalue(m_kColumn2) * s4 -
                         m_kColumn3.m_vComponents.m128_f32[2] * s3;
    w.adj.m_kColumn3.y = m_kColumn0.m_vComponents.m128_f32[2] * s5 - *(&m_kColumn2.m_vComponents.m128_f32[2]) * s2 +
                         m_kColumn3.m_vComponents.m128_f32[2] * s1;
    w.adj.m_kColumn3.z = -m_kColumn0.m_vComponents.m128_f32[2] * s4 + m_kColumn1.m_vComponents.m128_f32[2] * s2 -
                         m_kColumn3.m_vComponents.m128_f32[2] * s0;
    w.adj.m_kColumn3.w =
        m_kColumn0.m_vComponents.m128_f32[2] * s3 - m_kColumn1.m_vComponents.m128_f32[2] * s1 + (float)(+val2z) * s0;

    FUN_00de88a0(*(const S00de9140_SimdReal*)&w.invDetVec, *(const S00de9140_Matrix4*)&w.adj);
    return 0;
}
