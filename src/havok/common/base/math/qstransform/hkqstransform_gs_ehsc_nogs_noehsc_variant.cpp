
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
