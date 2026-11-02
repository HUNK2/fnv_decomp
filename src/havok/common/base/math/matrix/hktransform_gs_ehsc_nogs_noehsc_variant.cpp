
// src/havok/common/base/math/matrix/hktransform_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/math/matrix/hktransform.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/math/matrix/hktransform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hktransform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Matrix43;
struct Transform
{
    void FUN_00ce5300(Matrix43* out);
};
struct __declspec(align(16)) Matrix43
{
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
    void FUN_00cb2240(Matrix43* a, Matrix43* b);
    void FUN_00cb22c0(Transform* a, Matrix43* b);
};
struct FourFloatVector
{
    float x;
    float y;
    float z;
    float w;
};
struct Matrix44;
struct FUN_00cb21e0_shell
{
    void __thiscall FUN_00cb21e0(const Matrix44* source);
};
struct FUN_00cb2240_shell
{
    void __thiscall FUN_00cb2240(const Matrix44* left, const Matrix44* right);
};
__declspec(align(16)) struct Matrix44
{
    FourFloatVector row0;
    FourFloatVector row1;
    FourFloatVector row2;
    FourFloatVector row3;
    void FUN_00cb2420(const Matrix44* left, const Matrix44* right);
};
struct S_c7f4e0_Foo
{
    bool* __thiscall CheckFloatsFinite(bool* value);
};
struct S_cb2110_Foo
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

    S_c7f4e0_Foo unk30;

    bool* __thiscall FUN_00cb2d70(bool* value);
    bool* __thiscall FUN_00cb2110(bool* result);
};
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_unpacklo_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movelh_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_movehl_ps(__m128 a, __m128 b);
class hkMatrix3CB22;
struct hkVector4CB22
{
    __m128 m_vComponents;

    hkVector4CB22()
    {}
    hkVector4CB22(const hkVector4CB22& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4CB22& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void _setRotatedDir(const hkMatrix3CB22& r, const hkVector4CB22& b);
    __forceinline void _setRotatedInverseDir(const hkMatrix3CB22& r, const hkVector4CB22& b);
    void setSub4(const hkVector4CB22& a, const hkVector4CB22& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
};
class hkMatrix3CB22
{
  public:
    __forceinline void SetMulInverse(const hkMatrix3CB22& kA, const hkMatrix3CB22& kB)
    {
        hkMatrix3CB22 kATrans;
        kATrans.m_kColumn0 = kA.m_kColumn0;
        kATrans.m_kColumn1 = kA.m_kColumn1;
        kATrans.m_kColumn2 = kA.m_kColumn2;
        kATrans.transpose();
        for (int i = 0; i < 3; i++)
        {
            hkVector4CB22 kCol = kB.getColumn(i);
            getColumn(i)._setRotatedDir(kATrans, kCol);
        }
    }

    hkVector4CB22& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    const hkVector4CB22& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
    __forceinline void transpose()
    {
        __m128 tmp = _mm_unpacklo_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents);
        __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents),
                                     m_kColumn2.m_vComponents, 0xe4);
        m_kColumn0.m_vComponents = _mm_movelh_ps(tmp, m_kColumn2.m_vComponents);
        tmp = _mm_movehl_ps(m_kColumn0.m_vComponents, tmp);
        m_kColumn1.m_vComponents = _mm_shuffle_ps(tmp, m_kColumn2.m_vComponents, 0xd4);
        m_kColumn2.m_vComponents = ctmp;
    }

    hkVector4CB22 m_kColumn0;
    hkVector4CB22 m_kColumn1;
    hkVector4CB22 m_kColumn2;
};
__forceinline void hkVector4CB22::_setRotatedDir(const hkMatrix3CB22& r, const hkVector4CB22& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(r.m_kColumn0.m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(r.m_kColumn1.m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(r.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void hkVector4CB22::_setRotatedInverseDir(const hkMatrix3CB22& r, const hkVector4CB22& b)
{
    hkVector4CB22 kC0 = r.m_kColumn0;
    hkVector4CB22 kC1 = r.m_kColumn1;
    hkVector4CB22 kC2 = r.m_kColumn2;
    __m128 tmp = _mm_unpacklo_ps(kC0.m_vComponents, kC1.m_vComponents);
    const __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(kC0.m_vComponents, kC1.m_vComponents), kC2.m_vComponents, 0xe4);
    kC0.m_vComponents = _mm_movelh_ps(tmp, kC2.m_vComponents);
    tmp = _mm_movehl_ps(kC0.m_vComponents, tmp);
    kC1.m_vComponents = _mm_shuffle_ps(tmp, kC2.m_vComponents, 0xd4);
    kC2.m_vComponents = ctmp;
    const __m128 r0 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00), kC0.m_vComponents);
    const __m128 r1 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55), kC1.m_vComponents);
    const __m128 r2 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa), kC2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
class hkTransformCB22
{
  public:
    void FUN_00cb22f0(const hkTransformCB22& kA, const hkTransformCB22& kB);

    hkMatrix3CB22 m_rotation;
    hkVector4CB22 m_vTranslation;
};
struct Row
{
    union
    {
        __m128 v;
        float f0;
    };
};
struct Matrix
{
    Row r0;
    Row r1;
    Row r2;
    Row r3;
};
struct Obj : Matrix
{
    void __thiscall FUN_00cb2240(Matrix* m, int a);
    void __thiscall FUN_00cb23e0(int a);
};

struct FUN_00cb2240_cls
{
    __m128 m_col[4];

    void FUN_00cb2240(const __m128* __restrict a, const __m128* __restrict b);
};

// @fnv 0x00cb2240
void FUN_00cb2240_cls::FUN_00cb2240(const __m128* __restrict a, const __m128* __restrict b)
{
    const __m128& c1 = a[1];
    const __m128& c0 = a[0];
    const __m128& c2 = a[2];
    for (int i = 3; i >= 0; i--)
    {
        const __m128& v = b[i];
        m_col[i] =
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0), c0), _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1)),
                       _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2));
    }
    m_col[3] = _mm_add_ps(a[3], m_col[3]);
}
