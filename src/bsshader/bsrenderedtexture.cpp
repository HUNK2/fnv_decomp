// bsshader/bsrenderedtexture.cpp: BSRenderedTexture (3 functions)

#include "bsrenderedtexture_decls.h"
// @fnv 0x00b6b260
NiRenderTargetGroup* BSRenderedTexture::GetGroup()
{
    if (!this)
        return 0;
    if (!(spTexture[0] ? spTexture[0]->IsExactKindOf(&DAT_012708e4) : false))
        return m_apRenderTargetGroups[0];
    return m_apRenderTargetGroups[spTexture[0]->face];
}

class B6FC90Property
{
  public:
    B6FC90Property();
    virtual ~B6FC90Property();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_iShaderIndex;
    unsigned int m_auiFlags[2];
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int m_iLastRenderPass;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int m_iShaderType;
    int unk5C;

    void SetFlag(unsigned int uiBit)
    {
        unsigned int uiMask = 1u << (uiBit & 31);
        if (!(m_auiFlags[uiBit >> 5] & uiMask))
            m_iLastRenderPass = 0;
        m_auiFlags[uiBit >> 5] |= uiMask;
    }
};

struct B6FC90Color
{
    B6FC90Color(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA)
    {}

    float r;
    float g;
    float b;
    float a;
};

struct B6FC90Range
{
    B6FC90Range() : m_usStart(0), m_usEnd(0)
    {}

    unsigned short m_usStart;
    unsigned short m_usEnd;
};

class FUN_00b6fc90 : public B6FC90Property
{
  public:
    FUN_00b6fc90();
    virtual ~FUN_00b6fc90();

    int m_iFirst;
    int m_iSecond;
    B6FC90Range m_kRange;
    int m_iMode;
    B6FC90Color m_kFogTint;
};

// Initializes the shader property: zeroes m_iFirst/m_iSecond, sets m_iMode to 3, clears the color, sets shader type/index and flags 31 and 32.
// @fnv 0x00b6fc90
FUN_00b6fc90::FUN_00b6fc90() : m_iFirst(0), m_iSecond(0), m_iMode(3), m_kFogTint(0.0f, 0.0f, 0.0f, 0.0f)
{
    m_iShaderType = 0x21;
    m_iShaderIndex = 0x15;
    SetFlag(31);
    SetFlag(32);
}

class NiRenderTargetGroup;

bool __cdecl FUN_00b6b7d0(NiRenderTargetGroup* pkGroup, int iArg);

class RendererB6B8
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2C();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3C();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4C();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5C();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6C();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7C();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8C();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9C();
    virtual void vfn_A0();
    virtual void vfn_A4();
    virtual void vfn_A8();
    virtual void vfn_AC();
    virtual void vfn_B0();
    virtual void vfn_B4();
    virtual void vfn_B8();
    virtual void vfn_BC();
    virtual void vfn_C0();
    virtual void vfn_C4();
    virtual void vfn_C8();
    virtual void vfn_CC();
    virtual void vfn_D0();
    virtual void vfn_D4();
    virtual void vfn_D8();
    virtual void vfn_DC();
    virtual void vfn_E0();
    virtual void vfn_E4();
    virtual void vfn_E8();
    virtual void vfn_EC();
    virtual void vfn_F0();
    virtual void vfn_F4();
    virtual void vfn_F8();
    virtual void vfn_FC();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10C();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11C();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12C();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13C();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14C();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15C();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16C();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual bool vfn_17C();

    int unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C, unk030;
    int unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C, unk060;
    int unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C, unk090;
    int unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0;
    int unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC, unk0F0;
    int unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120;
    int unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150;
    int unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C, unk180;
    int unk184, unk188, unk18C, unk190, unk194, unk198, unk19C, unk1A0, unk1A4, unk1A8, unk1AC, unk1B0;
    int unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC, unk1D0, unk1D4, unk1D8, unk1DC, unk1E0;
    int unk1E4, unk1E8, unk1EC, unk1F0, unk1F4, unk1F8, unk1FC;
    int m_iFadeIndex;
};

namespace gfxB6B8 {
extern RendererB6B8* DAT_011f4748;
}

// Sets m_iFadeIndex to 2 when it is 0 and vfn_17C() returns true, then forwards to FUN_00b6b7d0.
// @fnv 0x00b6b8d0
bool __cdecl FUN_00b6b8d0(int iArg, NiRenderTargetGroup* pkGroup)
{
    int& iState = gfxB6B8::DAT_011f4748->m_iFadeIndex;
    if (iState == 0 && gfxB6B8::DAT_011f4748->vfn_17C())
        iState = 2;
    return FUN_00b6b7d0(pkGroup, iArg);
}
