
// src/havok/common/visualize/shape/hkdisplaysphere_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/visualize/shape/hkdisplaysphere.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/visualize/shape/hkdisplaysphere.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaysphere.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;
extern "C" __m128 _mm_setzero_ps(void);
struct hkVector4
{
    __m128 m_vComponents;
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};
struct __declspec(align(16)) hkVec4f
{
    float x, y, z, w;
};
extern float DAT_012683b0;
struct FUN_008cd6a0_Class
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        float* d = &m_kColumn0(0);
        d[0] = 1.0f;
        d[5] = 1.0f;
        d[10] = 1.0f;
        m_vTranslation.setZero4();
    }
    void FUN_00cb2d90(void* p);
};
struct hkReferencedObject
{
    virtual void vf0();
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkReferencedObject()
    {
        m_sReferenceCount = 1;
    }
};
struct __declspec(align(16)) ShapeBase : hkReferencedObject
{
    int m_ulUserData;
    FUN_008cd6a0_Class m_kMotionTransform;
    int m_type;

    ShapeBase()
    {
        m_ulUserData = 0;
        m_type = 1;
        m_kMotionTransform.setIdentity();
    }
};
struct __declspec(align(16)) FUN_00e0af50 : ShapeBase
{
    hkVec4f m_vec;
    int m_kPointA;
    int m_kPointB;

    FUN_00e0af50(const hkVec4f& v, int a, int b);
};
void __stdcall FUN_00e0af40(int a, int b);
