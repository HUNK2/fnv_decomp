// gamebryo2.2/corelibs/nimain/nisourcetexture_decls.h: declares NiMemObject, NiRenderer, NiBinaryStream, NiFixedStringCallShim, NiFileAccessCallShim and more
#ifndef FNV_NISOURCETEXTURE_DECLS_H
#define FNV_NISOURCETEXTURE_DECLS_H

#include "NiFixedString.h"

extern unsigned int DAT_011c16bc;
void FUN_00a47350();
void FUN_00a5b690();
bool __cdecl FUN_00aa1a30(const char*, int);
extern "C" void __fastcall __security_check_cookie(unsigned int);

#define FNV_NIMEMOBJECT_H
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
};

class NiRenderer
{
  public:
    static NiRenderer* ms_pRenderer;
    char _pdbpad_1[7];
    char m_spAccum_pad7_pad7[4];
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

extern NiFixedString EmptyFS;
extern bool DAT_011f4448;
extern bool DAT_011a9594;
extern bool DAT_011f4780;

void FUN_00a57500(NiFixedString*);
void FUN_00a76960(void*, void*);
void FUN_00a47350();
void FUN_00a64ea0();
void FUN_00a64700();
void FUN_00a5b690();
void FUN_00a645b0();
void FUN_00a636f0();
void FUN_00a636b0();
void FUN_00a633d0();
void FUN_00a2e750();
void FUN_00a633b0();

class NiBinaryStream
{
  public:
    void* m_pUnknown;
    unsigned int m_uiPosition;
    void* m_pfnRead;
};

class NiFixedStringCallShim
{
  public:
    NiFixedStringCallShim& operator=(const char*);
};

class NiFileAccessCallShim
{
  public:
    static bool Access(const char*, NiFile::OpenMode);
};

class NiSourceTexture;
class NiSourceTextureDeleteVCall
{
  public:
    virtual void Delete(unsigned int) = 0;
};

class NiFileVCall
{
  public:
    virtual void Delete(unsigned int) = 0;
};

class NiRendererVCall
{
  public:
    virtual void vfn_000() = 0;
    virtual void vfn_004() = 0;
    virtual void vfn_008() = 0;
    virtual void vfn_00c() = 0;
    virtual void vfn_010() = 0;
    virtual void vfn_014() = 0;
    virtual void vfn_018() = 0;
    virtual void vfn_01c() = 0;
    virtual void vfn_020() = 0;
    virtual void vfn_024() = 0;
    virtual void vfn_028() = 0;
    virtual void vfn_02c() = 0;
    virtual void vfn_030() = 0;
    virtual void vfn_034() = 0;
    virtual void vfn_038() = 0;
    virtual void vfn_03c() = 0;
    virtual void vfn_040() = 0;
    virtual void vfn_044() = 0;
    virtual void vfn_048() = 0;
    virtual void vfn_04c() = 0;
    virtual void vfn_050() = 0;
    virtual void vfn_054() = 0;
    virtual void vfn_058() = 0;
    virtual void vfn_05c() = 0;
    virtual void vfn_060() = 0;
    virtual void vfn_064() = 0;
    virtual void vfn_068() = 0;
    virtual void vfn_06c() = 0;
    virtual void vfn_070() = 0;
    virtual void vfn_074() = 0;
    virtual void vfn_078() = 0;
    virtual void vfn_07c() = 0;
    virtual void vfn_080() = 0;
    virtual void vfn_084() = 0;
    virtual void vfn_088() = 0;
    virtual void vfn_08c() = 0;
    virtual void vfn_090() = 0;
    virtual void vfn_094() = 0;
    virtual void vfn_098() = 0;
    virtual void vfn_09c() = 0;
    virtual void vfn_0a0() = 0;
    virtual void vfn_0a4() = 0;
    virtual void vfn_0a8() = 0;
    virtual void vfn_0ac() = 0;
    virtual void vfn_0b0() = 0;
    virtual void vfn_0b4() = 0;
    virtual void vfn_0b8() = 0;
    virtual void vfn_0bc() = 0;
    virtual void vfn_0c0() = 0;
    virtual void vfn_0c4() = 0;
    virtual void vfn_0c8() = 0;
    virtual void vfn_0cc() = 0;
    virtual void vfn_0d0() = 0;
    virtual void vfn_0d4() = 0;
    virtual void vfn_0d8() = 0;
    virtual void vfn_0dc() = 0;
    virtual void vfn_0e0() = 0;
    virtual void vfn_0e4() = 0;
    virtual void vfn_0e8() = 0;
    virtual void vfn_0ec() = 0;
    virtual void vfn_0f0() = 0;
    virtual void vfn_0f4() = 0;
    virtual void vfn_0f8() = 0;
    virtual void vfn_0fc() = 0;
    virtual void vfn_100() = 0;
    virtual void vfn_104() = 0;
    virtual void vfn_108() = 0;
    virtual void vfn_10c() = 0;
    virtual void vfn_110() = 0;
    virtual void vfn_114() = 0;
    virtual void vfn_118() = 0;
    virtual void vfn_11c() = 0;
    virtual void vfn_120() = 0;
    virtual void vfn_124() = 0;
    virtual void vfn_128() = 0;
    virtual void vfn_12c() = 0;
    virtual void vfn_130() = 0;
    virtual void vfn_134() = 0;
    virtual void vfn_138() = 0;
    virtual bool vfn_13c(NiSourceTexture*) = 0;
};

class NiSourceTextureVCall
{
  public:
    virtual void vfn_000() = 0;
    virtual void vfn_004() = 0;
    virtual void vfn_008() = 0;
    virtual void vfn_00c() = 0;
    virtual void vfn_010() = 0;
    virtual void vfn_014() = 0;
    virtual void vfn_018() = 0;
    virtual void vfn_01c() = 0;
    virtual void vfn_020() = 0;
    virtual void vfn_024() = 0;
    virtual void vfn_028() = 0;
    virtual void vfn_02c() = 0;
    virtual void vfn_030() = 0;
    virtual void vfn_034() = 0;
    virtual void vfn_038() = 0;
    virtual void vfn_03c() = 0;
    virtual void vfn_040() = 0;
    virtual void vfn_044() = 0;
    virtual void vfn_048() = 0;
    virtual void vfn_04c() = 0;
    virtual void vfn_050() = 0;
    virtual void vfn_054() = 0;
    virtual void vfn_058() = 0;
    virtual void vfn_05c() = 0;
    virtual void vfn_060() = 0;
    virtual void vfn_064() = 0;
    virtual void vfn_068() = 0;
    virtual void vfn_06c() = 0;
    virtual void vfn_070() = 0;
    virtual void vfn_074() = 0;
    virtual void vfn_078() = 0;
    virtual void vfn_07c() = 0;
    virtual void vfn_080() = 0;
    virtual void vfn_084() = 0;
    virtual void vfn_088() = 0;
    virtual void vfn_08c() = 0;
    virtual void vfn_090() = 0;
    virtual void vfn_094() = 0;
    virtual void vfn_098() = 0;
    virtual void vfn_09c() = 0;
    virtual void vfn_0a0() = 0;
    virtual void vfn_0a4() = 0;
    virtual void DestroyAppPixelData() = 0;
    virtual bool vfn_0ac() = 0;
};

#endif
