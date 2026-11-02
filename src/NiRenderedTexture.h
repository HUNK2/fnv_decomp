// NiObject/NiDX9Renderer virtual names and order: JIP-LN-NVSE,
// 5a30ac4356ea0e93b9ff357b5031b1e420240a4d, internal/netimmerse.h.
// Existing Unk_XX names are community placeholders, not recovered originals.
// Unk_28 return type and CreateRenderedTexture second parameter are inferred
// from the covered PC caller. Only declarations are adapted here.
#ifndef FNV_RENDEREDTEXTURE_DECLARATIONS_H
#define FNV_RENDEREDTEXTURE_DECLARATIONS_H

#include <stddef.h>
typedef unsigned int UInt32;
class NiRTTI;
class NiNode;
class BSFadeNode;
class BSMultiBoundNode;
class NiGeometry;
class NiTriBasedGeom;
class NiTriStrips;
class NiTriShape;
class BSSegmentedTriShape;
class BSResizableTriShape;
class NiParticles;
class NiLines;
class bhkNiCollisionObject;
class bhkBlendCollisionObject;
class bhkRigidBody;
class bhkLimitedHingeConstraint;
class NiObjectCopyInfo;
class NiStream;
class NiBound;
class NiControllerManager;
class NiTimeController;
class NiExtraData;
class NiTexture;
class NiRenderedTexture;
class NiVector4;
class NiRenderTargetGroup;
class NiGeometryData;
class NiMaterialProperty;
class NiDynamicEffect;
class NiSkinPartition;
class NiSkinInstance;
class NiPixelData;
class NiSourceTexture;
template <class T> class NiTArray;
template <class T> class NiRect;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiMemObject
{
  public:
    static void* operator new(size_t size);
};
class NiRefObject : public NiMemObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};
class NiObject : public NiRefObject
{
  public:
    /*08*/ virtual NiRTTI* GetType();
    /*0C*/ virtual NiNode* GetNiNode();
    /*10*/ virtual BSFadeNode* GetFadeNode();
    /*14*/ virtual BSMultiBoundNode* GetMultiBoundNode();
    /*18*/ virtual NiGeometry* GetNiGeometry();
    /*1C*/ virtual NiTriBasedGeom* GetTriBasedGeom();
    /*20*/ virtual NiTriStrips* GetTriStrips();
    /*24*/ virtual NiTriShape* GetTriShape();
    /*28*/ virtual BSSegmentedTriShape* GetSegmentedTriShape();
    /*2C*/ virtual BSResizableTriShape* GetResizableTriShape();
    /*30*/ virtual NiParticles* GetNiParticles();
    /*34*/ virtual NiLines* GetNiLines();
    /*38*/ virtual bhkNiCollisionObject* GetCollisionObject();
    /*3C*/ virtual bhkBlendCollisionObject* GetBlendCollisionObject();
    /*40*/ virtual bhkRigidBody* GetRigidBody();
    /*44*/ virtual bhkLimitedHingeConstraint* GetLimitedHingeConstraint();
    /*48*/ virtual NiObject* Clone(NiObjectCopyInfo* copyInfo);
    /*4C*/ virtual void LoadBinary(NiStream* stream);
    /*50*/ virtual void LinkObject(NiStream* stream);
    /*54*/ virtual void RegisterStreamables(NiStream* stream);
    /*58*/ virtual void SaveBinary(NiStream* stream);
    /*5C*/ virtual bool Compare(NiObject* to);
    /*60*/ virtual void GetViewerStrings(NiTArray<char*>* strings);
    /*64*/ virtual void AddViewerStrings(NiTArray<char*>* strings);
    /*68*/ virtual void ProcessClone(NiObjectCopyInfo* copyInfo);
    /*6C*/ virtual void PostLinkObject(NiStream* stream);
    /*70*/ virtual bool StreamCanSkip();
    /*74*/ virtual NiRTTI* GetStreamableRTTI();
    /*78*/ virtual void SetWorldBound(NiBound* worldBound);
    /*7C*/ virtual UInt32 GetBlockAllocationSize();
    /*80*/ virtual void Unk_20(void);
    /*84*/ virtual void Unk_21(UInt32 arg);
    /*88*/ virtual NiControllerManager* GetControllerManager();
};
class NiFixedString
{
  public:
    char* m_kHandle;
};
class NiObjectNET : public NiObject
{
  public:
    NiFixedString m_kName;
    NiPointer<NiTimeController> m_pControllers;
    NiExtraData** m_ppExtraData;
    unsigned short m_usExtraDataCount;
    unsigned short m_usMaxSize;
};
class Ni2DBuffer : public NiObject
{
  public:
    enum MultiSamplePreference
    {
        MULTISAMPLE_NONE,
        MULTISAMPLE_2,
        MULTISAMPLE_4,
        MULTISAMPLE_8
    };
    // Name: ieee802dot11ac/fnv 074e045e, Ni2DBuffer.h; PC binding inferred.
    static Ni2DBuffer* Create(unsigned int width, unsigned int height);
    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;
    char m_pRendererData[4];
};
// Renderer instance fields omitted: only its virtual interface is used.
class NiRenderer : public NiObject
{
  public:
    virtual void Unk_23();
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
class NiDX9Renderer : public NiRenderer
{
  public:
    /*090*/ virtual void SetDefaultProgramCache();
    /*094*/ virtual void Unk_25(void);
    /*098*/ virtual void Unk_26(void);
    /*09C*/ virtual void Unk_27(void);
    /*0A0*/ virtual unsigned int Unk_28(void);
    /*0A4*/ virtual void Unk_29(void);
    /*0A8*/ virtual void Unk_2A(void);
    /*0AC*/ virtual void SetBackgroundColor(NiVector4* inARGB);
    /*0B0*/ virtual void Unk_2C(void);
    /*0B4*/ virtual void GetBackgroundColor(NiVector4* outARGB);
    /*0B8*/ virtual void Unk_2E(void);
    /*0BC*/ virtual void Unk_2F(void);
    /*0C0*/ virtual void Unk_30(void);
    /*0C4*/ virtual void Unk_31(void);
    /*0C8*/ virtual NiRenderTargetGroup* GetDefaultRT();
    /*0CC*/ virtual NiRenderTargetGroup* GetCurrentRT();
    /*0D0*/ virtual void Unk_34(void);
    /*0D4*/ virtual void Unk_35(void);
    /*0D8*/ virtual void Unk_36(void);
    /*0DC*/ virtual void Unk_37(void);
    /*0E0*/ virtual bool PrecacheTexture(NiTexture* pkIm, bool bForceLoad, bool bLocked);
    /*0E4*/ virtual void Unk_39(void);
    /*0E8*/ virtual void Unk_3A(void);
    /*0EC*/ virtual bool PrecacheGeometry(NiGeometry* pkGeometry, UInt32 uiBonesPerPartition, UInt32 uiBonesPerVertex);
    /*0F0*/ virtual void PurgeGeometry(NiGeometryData* geo);
    /*0F4*/ virtual void PurgeMaterial(NiMaterialProperty* material);
    /*0F8*/ virtual void PurgeEffect(NiDynamicEffect* effect);
    /*0FC*/ virtual void PurgeScreenTexture();
    /*100*/ virtual void PurgeSkinPartition(NiSkinPartition* skinPartition);
    /*104*/ virtual void PurgeSkinInstance(NiSkinInstance* skinInstance);
    /*108*/ virtual void Unk_42(void);
    /*10C*/ virtual bool PurgeAllTextures();
    /*110*/ virtual NiPixelData* TakeScreenShot(const NiRect<UInt32>* pkScreenRect,
                                                const NiRenderTargetGroup* pkTarget);
    /*114*/ virtual bool FastCopy(const Ni2DBuffer* pkSrc, Ni2DBuffer* pkDest, const NiRect<UInt32>* pkSrcRect,
                                  UInt32 uiDestX, UInt32 uiDestY);
    /*118*/ virtual bool Copy(const Ni2DBuffer* pkSrc, Ni2DBuffer* pkDest, NiRect<UInt32>* pkSrcRect,
                              NiRect<UInt32>* pkDestRect, UInt32 copyFilter);
    /*11C*/ virtual void Unk_47(void);
    /*120*/ virtual bool Unk_48(void* arg);
    /*124*/ virtual void Unk_49(void);
    /*128*/ virtual void Unk_4A(float arg);
    /*12C*/ virtual void Unk_4B(UInt32 size);
    /*130*/ virtual void Unk_4C(UInt32 arg0, UInt32 arg1);
    /*134*/ virtual void Unk_4D(UInt32 arg0, UInt32 arg1);
    /*138*/ virtual void Unk_4E(void* buf);
    /*13C*/ virtual void CreateSourceTexture(NiSourceTexture* texture);
    /*140*/ virtual bool CreateRenderedTexture(NiRenderedTexture* texture,
                                               Ni2DBuffer::MultiSamplePreference preference);
};
class NiTexture : public NiObjectNET
{
  public:
    struct TextureFormatPreferences
    {
        enum PixelLayout
        {
            PALETTIZED_8,
            HIGH_COLOR_16,
            TRUE_COLOR_32,
            COMPRESSED,
            BUMPMAP,
            PALETTIZED_4,
            PIX_DEFAULT,
            SINGLE_COLOR_8,
            SINGLE_COLOR_16,
            SINGLE_COLOR_32,
            DOUBLE_COLOR_32,
            DOUBLE_COLOR_64,
            FLOAT_COLOR_32,
            FLOAT_COLOR_64,
            FLOAT_COLOR_128
        };
        enum AlphaFormat
        {
            NONE,
            BINARY,
            SMOOTH,
            ALPHA_DEFAULT
        };
        enum MipFlag
        {
            NO,
            YES,
            MIP_DEFAULT
        };
        PixelLayout m_ePreferredPixelLayout;
        AlphaFormat m_eAlphaFormat;
        MipFlag m_eMipFlag;
    };
    class RendererData;
    TextureFormatPreferences m_kTextureFormatPreferences;
    RendererData* m_pTextureRendererData;
    NiTexture* m_pkPrev;
    NiTexture* m_pkNext;
};
enum _D3DFORMAT
{
    D3DFMT_A8R8G8B8 = 21
};
class NiRenderedTexture : public NiTexture
{
  public:
    NiRenderedTexture() throw();
    virtual ~NiRenderedTexture();
    static NiRenderedTexture* Create(const NiFixedString&, unsigned int, unsigned int, NiRenderer*,
                                     NiTexture::TextureFormatPreferences&, Ni2DBuffer::MultiSamplePreference,
                                     NiRenderedTexture*, unsigned int);
    NiPointer<Ni2DBuffer> m_spRenderTargetBuffer;
    unsigned int m_uiAliasOffset;
    NiRenderedTexture* m_pReuseTexture;
    Ni2DBuffer::MultiSamplePreference m_eMultiSamplePreference;
    bool m_bUseMipMaps;
    bool m_bUseDepthBuffer;
    _D3DFORMAT m_ePixelFormat;
    static bool ms_bUseMipMaps;
    static bool ms_bUseDepthBuffer;
    static _D3DFORMAT ms_eDepthStencilFormat;
};
typedef char NiRenderedTexture_size_check[(sizeof(NiRenderedTexture) == 0x48) ? 1 : -1];
typedef char NiRenderedTexture_buffer_check[(offsetof(NiRenderedTexture, m_spRenderTargetBuffer) == 0x30) ? 1 : -1];
typedef char NiRenderedTexture_format_check[(offsetof(NiRenderedTexture, m_ePixelFormat) == 0x44) ? 1 : -1];
#endif
