// gamebryo2.2/corelibs/nimain/ni2dbuffer_decls.h: declares NiRTTI, Ni2DBuffer, NiRenderer
#ifndef NI2DBUFFER_DECLS_H
#define NI2DBUFFER_DECLS_H

class NiPixelFormat;
struct NiRTTI
{
    const char* name;
    const NiRTTI* parent;
};
extern NiRTTI DAT_011f603c;
class Ni2DBuffer
{
  public:
    enum MultiSamplePreference
    {
        MULTISAMPLE_NONE,
        MULTISAMPLE_2,
        MULTISAMPLE_4,
        MULTISAMPLE_8
    };
    virtual void vfn_00();
    virtual void vfn_04();
    virtual const NiRTTI* GetType() const;
    bool IsKindOfType(const NiRTTI* target) const
    {
        const NiRTTI* type = GetType();
        while (type)
        {
            if (type == target)
                return true;
            type = type->parent;
        }
        return false;
    }
    unsigned int refCount;
    unsigned int width;
    unsigned int height;
    void* rendererData;
    bool CreateRendererData(const NiPixelFormat&, MultiSamplePreference);
};
class NiRenderer
{
  public:
    static NiRenderer* ms_pRenderer;
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual bool CreateDepthStencil(Ni2DBuffer*, const NiPixelFormat&, Ni2DBuffer::MultiSamplePreference);
    char _pdbpad_4[4];
    char m_acRendererDataA[4];
    void* m_pCamera;
    void* m_pActiveRenderTargetGroup;
    char m_acRendererDataB[4];
    char _pdbpad_18[104];
    char m_acRendererDataC[128];
    char m_acRendererDataD[128];
    char m_acRendererDataE[128];
    int m_iRendererState;
    unsigned int m_uiRendererFlags;
    bool m_bRendererFlagA;
    bool m_bRendererFlagB;
    char _pdbpad_20a[118];
};
#endif
