// src/havok/common/base/math/qstransform/hkqstransform_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/base/math/qstransform/hkqstransform_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/common/base/math/qstransform/hkqstransform_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/base/math/qstransform/hkqstransform.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/base/math/qstransform/hkqstransform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/qstransform/hkqstransform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Matrix
{
    float values[12];
    bool* HasFiniteValues(bool* output);
};
#include <xmmintrin.h>
struct S_00ce5070_Vector4
{
    __m128 m_vComponents;
};
extern const S_00ce5070_Vector4 DAT_010c7170;
struct S_00ce5070_Rotation
{
    S_00ce5070_Vector4 m_kColumn0;
    S_00ce5070_Vector4 m_kColumn1;
    S_00ce5070_Vector4 m_kColumn2;
};
struct S_00ce5070_Transform
{
    S_00ce5070_Rotation m_rotation;
    S_00ce5070_Vector4 m_vTranslation;
};
struct S_00ce5070_Quaternion
{
    S_00ce5070_Vector4 m_vec;
    void FUN_00cb26e0(const S_00ce5070_Rotation& r);
};
struct S_00ce5070_QsTransform
{
    S_00ce5070_Vector4 m_vTranslation;
    S_00ce5070_Quaternion m_rotation;
    S_00ce5070_Vector4 m_vScale;

    void FUN_00ce5070(const S_00ce5070_Transform& t);
};
class CB2FC0Object
{
  public:
    void FUN_00cb2d90(void* snapshot);
};
class FUN_00ce50b0_cls
{
  public:
    void FUN_00ce50b0(CB2FC0Object* target);
};
struct __declspec(align(16)) Vector
{
    float x, y, z, w;
};
struct FUN_008cd6a0_Class
{
    Vector row0, row1, row2;
    void FUN_00cb2d90(void*);
};
struct FUN_00cdf250_class
{
    Vector row0, row1, row2;
    void FUN_00cd55b0(int*, int);
};
struct TransformMatrix
{
    Vector row0, row1, row2, row3;
    void FUN_00cb2050(int);
};
struct Transform
{
    Vector position;
    float rotationX, rotationY, rotationZ, rotationW;
    float scaleX, scaleY, scaleZ;
    void FUN_00ce51f0(int);
};
struct S_00ce5290_Vector4
{
    float x, y, z, w;
    __m128& q()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& q() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
};
struct S_00ce5290_Bool
{
    char m_cBooleanValue;
    S_00ce5290_Bool(bool b)
    {
        m_cBooleanValue = b;
    }
};
struct S_00ce5290_Result
{
    S_00ce5290_Vector4 m_v0;
    S_00ce5290_Vector4 m_v1;
    S_00ce5290_Vector4 m_v2;
    char unk30;
    char unk31;
    short unk32;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
};
void FUN_00d72e90(const void* input, S_00ce5290_Result* out);
struct S_00ce5290
{
    S_00ce5290_Vector4 m_v0;
    S_00ce5290_Vector4 m_v1;
    S_00ce5290_Vector4 m_v2;
    S_00ce5290_Bool SetFromInput(const void* input);
};

#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier();

extern const float DAT_01012054;
extern "C" const __declspec(align(16)) unsigned int DAT_01017d10[4];

struct hkBool5120
{
    char m_cBooleanValue;
    hkBool5120(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct hkVector4_5120
{
    __m128 m_vComponents;
};

struct hkQsTransform5120
{
    hkVector4_5120 m_vTranslation;
    hkVector4_5120 m_rotation;
    hkVector4_5120 m_vScale;
    hkBool5120 FUN_00ce5120(const hkQsTransform5120& other, float epsilon) const;
};

// @fnv 0x00ce5120
hkBool5120 hkQsTransform5120::FUN_00ce5120(const hkQsTransform5120& other, float epsilon) const
{
    __m128 eps = _mm_set1_ps(epsilon);
    __m128 absMask = *(const __m128*)DAT_01017d10;
    __m128 t = _mm_and_ps(_mm_sub_ps(m_vTranslation.m_vComponents, other.m_vTranslation.m_vComponents), absMask);
    if ((_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 7) != 7)
        return false;
    t = _mm_and_ps(_mm_sub_ps(m_vScale.m_vComponents, other.m_vScale.m_vComponents), absMask);
    if ((_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 7) != 7)
        return false;
    __m128 rot = m_rotation.m_vComponents;
    _ReadWriteBarrier();
    t = other.m_rotation.m_vComponents;
    __m128 p = _mm_mul_ps(t, rot);
    __m128 s = _mm_add_ps(_mm_shuffle_ps(p, p, 0x4e), p);
    s = _mm_add_ps(_mm_shuffle_ps(s, s, 0xb1), s);
    float dot;
    _mm_store_ss(&dot, s);
    if (dot < 0.0f)
    {
        __m128 m1 = _mm_load_ss(&DAT_01012054);
        rot = _mm_mul_ps(_mm_shuffle_ps(m1, m1, 0), rot);
    }
    t = _mm_and_ps(_mm_sub_ps(rot, t), absMask);
    return (_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 0xf) == 0xf;
}
