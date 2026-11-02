
// src/havok/common/visualize/shape/hkdisplaycylinder_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/visualize/shape/hkdisplaycylinder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

void __stdcall FUN_00d58500(int, int);
#include <xmmintrin.h>
struct DE1F50Vector4
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
    void operator=(const DE1F50Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};
struct DE1F50Transform
{
    DE1F50Vector4 m_kColumn0;
    DE1F50Vector4 m_kColumn1;
    DE1F50Vector4 m_kColumn2;
    DE1F50Vector4 m_vTranslation;

    void setIdentity()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
        m_vTranslation.setZero4();
    }
};
class DE1F50ReferencedObject
{
  public:
    DE1F50ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
class DE1F50Shape : public DE1F50ReferencedObject
{
  public:
    DE1F50Shape() : m_ulUserData(0), m_type(2)
    {
        m_kMotionTransform.setIdentity();
    }

    int m_ulUserData;
    int unk0C;
    DE1F50Transform m_kMotionTransform;
    int m_type;
    int unk54;
    int unk58;
    int unk5C;
};
class FUN_00de1f50 : public DE1F50Shape
{
  public:
    FUN_00de1f50(const DE1F50Vector4& v);
    virtual void unk00();

    DE1F50Vector4 m_vector;
};
