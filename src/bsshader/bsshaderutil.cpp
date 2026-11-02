// bsshader/bsshaderutil.cpp: BSShaderRenderUtility (7 functions)

#include "bsshaderutil_decls.h"

#pragma optimize("", off)
// @fnv 0x00469860
bool BSShaderRenderUtility::IsRenderTargetId(unsigned int value)
{
    return value >= 0xff000000u;
}

#pragma optimize("", on)

// Allocates two BSShaderUtilTextureName objects and stores them in DAT_011fa050 and DAT_011fa054.
// @fnv 0x00b6ba70
void BSShaderRenderUtility::InitializeMultiBounds()
{
    DAT_011fa050 = new BSShaderUtilTextureName("ConvertedTexture");
    DAT_011fa054 = new BSShaderUtilTextureName("BackgroundConvertedTexture");
}

// @fnv 0x00b6c0d0
void BSShaderRenderUtility::SetRenderCamera(NiCamera* camera, BSShaderAccumulator* accumulator, bool)
{
    if (NiRenderer::ms_pRenderer && camera)
    {
        NiRenderer::ms_pRenderer->SetCurrentCamera(camera);
        DAT_011f917c = camera;
        FUN_00b54b10(accumulator);
        accumulator->SetCamera(camera);
        accumulator->Unk_2A();
    }
    accumulator->Unk_2B();
}

// @fnv 0x00b6bb30
void BSShaderRenderUtility::SetAlphaOnNode(NiNode* node, float alpha)
{
    if (node && node->m_kWorldBound && node->m_kWorldBound->m_fBoundRadius != 0.0f)
    {
        for (unsigned int i = 0; i < node->m_usChildrenCount; ++i)
        {
            NiAVObject* child = node->m_ppChildren[i];
            if (child)
            {
                FadeProperties* properties = child->vfn_18();
                if (properties)
                {
                    if (&properties->m_uiInterior)
                    {
                        FadeState* state = properties->m_pFadeState;
                        if (state)
                        {
                            state = state->m_iFadeIndex != -1 ? state : 0;
                            if (state)
                                state->m_fAlpha = alpha;
                        }
                    }
                }

                BSShaderRenderUtility::SetAlphaOnNode(child->vfn_0c(), alpha);
            }
        }
    }
}

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

extern NiPointer<NiRefObject> g_spCurrentAccumulator;

// Stores the given BSShaderAccumulator into the global g_spCurrentAccumulator smart pointer.
// @fnv 0x00b54b10
void FUN_00b54b10(BSShaderAccumulator* accumulator)
{
    g_spCurrentAccumulator = reinterpret_cast<NiRefObject*>(accumulator);
}

struct PipboyManager6b
{
    int unk00;
    int unk04;
    NiPointer<NiRefObject> m_pReferencedObject;
    void FUN_004dc540(NiRefObject* pkNode);
};
extern PipboyManager6b* DAT_011f4748;
void __cdecl FUN_00b54ac0(NiRefObject* pkNode);

struct Accumulator6b
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void RegisterObject(void* pkObject);
    virtual void SetSortingCamera(void* pkCamera, void* pkObject, int iFlags);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
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
    NiPointer<NiRefObject> m_spNode;
};

typedef void* ListIter6b;

struct PointerList6b
{
    NiTListItem<void*>* m_pkHead;
    NiTListItem<void*>* m_pkTail;
    unsigned int m_uiCount;

    ListIter6b GetHeadPos() const
    {
        return m_pkHead;
    }
    void* GetNext(ListIter6b& kPos) const
    {
        if (kPos)
        {
            void*& rpvElement = ((NiTListItem<void*>*)kPos)->m_element;
            kPos = ((NiTListItem<void*>*)kPos)->m_pkNext;
            return rpvElement;
        }
        return 0;
    }
};
// Sets the sorting camera from the first list item, then registers later items when the manager and camera are non-null.
// @fnv 0x00b6bfc0
void __cdecl FUN_00b6bfc0(void* pkCamera, PointerList6b& kList, Accumulator6b* pkAccumulator)
{
    if (!DAT_011f4748 || !pkCamera)
        return;

    NiPointer<NiRefObject> spRetainedObject = DAT_011f4748->m_pReferencedObject;
    DAT_011f4748->FUN_004dc540(pkAccumulator->m_spNode);
    FUN_00b54ac0(pkAccumulator->m_spNode);

    ListIter6b kPos = kList.GetHeadPos();
    if (kPos)
    {
        pkAccumulator->SetSortingCamera(pkCamera, kList.GetNext(kPos), 0);
        if (kPos)
        {
            void* pvObject = kList.GetNext(kPos);
            do
            {
                void* pvCurrent = pvObject;
                pvObject = kList.GetNext(kPos);
                pkAccumulator->RegisterObject(pvCurrent);
            } while (pvObject);
        }
    }
}

namespace fnv_00b6bbd0 {
#include <d3d9.h>

void _memmove(void* destination, const void* source, unsigned int size);

class NiPixelFormat
{
  public:
    unsigned int bitsPerPixel;
    unsigned int format;
    unsigned int tiling;
    unsigned int rendererHint;
    unsigned int extraData;
    unsigned int flags;
    unsigned int redComponent;
    unsigned int redRepresentation;
    unsigned int redBits;
    unsigned int greenComponent;
    unsigned int greenRepresentation;
    unsigned int greenBits;
    unsigned int blueComponent;
    unsigned int blueRepresentation;
    unsigned int blueBits;
    unsigned int alphaComponent;
    unsigned int alphaRepresentation;
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
class NiPixelData : public NiRefObject, public NiMemObject
{
  public:
    NiPixelFormat m_kPixelFormat;
    void* m_spPalette;
    unsigned char* m_pucPixels;
    unsigned int* m_puiWidth;
    unsigned int* m_puiHeight;
    unsigned int* m_puiOffset;
    unsigned int m_uiMipmapLevels;
    unsigned int m_uiPixelStride;
    unsigned int m_uiFaces;
    unsigned int m_uiFaceSize;
    unsigned int m_uiValue5;
    NiPixelData(unsigned int, unsigned int, const NiPixelFormat&, unsigned int, unsigned int);
};
class TextureRendererData
{
  public:
    virtual void vfn_00() = 0;
    virtual void vfn_04() = 0;
    virtual void vfn_08() = 0;
    virtual void vfn_0c() = 0;
    virtual void vfn_10() = 0;
    virtual void vfn_14() = 0;
    virtual void vfn_18() = 0;
    virtual void vfn_1c() = 0;
    virtual void vfn_20() = 0;
    virtual void vfn_24() = 0;
    virtual void vfn_28() = 0;
    virtual void vfn_2c() = 0;
    virtual void vfn_30() = 0;
    virtual void vfn_34() = 0;
    virtual void vfn_38() = 0;
    virtual void vfn_3c() = 0;
    virtual void vfn_40() = 0;
    virtual void vfn_44() = 0;
    virtual void vfn_48() = 0;
    virtual void vfn_4c() = 0;
    virtual void vfn_50() = 0;
    virtual void vfn_54() = 0;
    virtual void vfn_58() = 0;
    virtual void vfn_5c() = 0;
    virtual void vfn_60() = 0;
    virtual void vfn_64() = 0;
    virtual void vfn_68() = 0;
    virtual void vfn_6c() = 0;
    virtual void vfn_70() = 0;
    virtual void vfn_74() = 0;
    virtual void vfn_78() = 0;
    virtual void vfn_7c() = 0;
    virtual void vfn_80() = 0;
    virtual void vfn_84() = 0;
    virtual void vfn_88() = 0;
    virtual void vfn_8c() = 0;
    virtual void vfn_90() = 0;
    virtual void vfn_94() = 0;
    virtual void vfn_98() = 0;
    virtual IDirect3DTexture9* GetTexture() = 0;
};
struct TextureMipData
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int m_uiMipmapLevels;
};
class NiTexture
{
  public:
    virtual void vfn_00() = 0;
    virtual void vfn_04() = 0;
    virtual void vfn_08() = 0;
    virtual void vfn_0c() = 0;
    virtual void vfn_10() = 0;
    virtual void vfn_14() = 0;
    virtual void vfn_18() = 0;
    virtual void vfn_1c() = 0;
    virtual void vfn_20() = 0;
    virtual void vfn_24() = 0;
    virtual void vfn_28() = 0;
    virtual void vfn_2c() = 0;
    virtual void vfn_30() = 0;
    virtual void vfn_34() = 0;
    virtual void vfn_38() = 0;
    virtual void vfn_3c() = 0;
    virtual void vfn_40() = 0;
    virtual void vfn_44() = 0;
    virtual void vfn_48() = 0;
    virtual void vfn_4c() = 0;
    virtual void vfn_50() = 0;
    virtual void vfn_54() = 0;
    virtual void vfn_58() = 0;
    virtual void vfn_5c() = 0;
    virtual void vfn_60() = 0;
    virtual void vfn_64() = 0;
    virtual void vfn_68() = 0;
    virtual void vfn_6c() = 0;
    virtual void vfn_70() = 0;
    virtual void vfn_74() = 0;
    virtual void vfn_78() = 0;
    virtual void vfn_7c() = 0;
    virtual void vfn_80() = 0;
    virtual void vfn_84() = 0;
    virtual void vfn_88() = 0;
    virtual void vfn_8c() = 0;
    virtual void vfn_90() = 0;
    virtual unsigned int GetWidth() = 0;
    virtual unsigned int GetHeight() = 0;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    TextureRendererData* m_pTextureRendererData;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    TextureMipData* m_pkPixelData;
};
class TextureRenderer : public NiRenderer
{
  public:
    unsigned int unk280;
    unsigned int unk284;
    IDirect3DDevice9* m_pkDevice;
};
extern TextureRenderer* DAT_011f4748;
extern unsigned char DAT_011f4448;
extern bool DAT_011a9595;
struct TextureFormatPrefs
{
    unsigned int pixelLayout, alphaFormat, mipMapped;
};
extern TextureFormatPrefs DAT_011a9598;
int FUN_00e7bd20(const NiPixelFormat*);
HRESULT __stdcall FUN_00ee6de6(IDirect3DSurface9*, const PALETTEENTRY*, const RECT*, IDirect3DSurface9*,
                               const PALETTEENTRY*, const RECT*, DWORD, D3DCOLOR);
NiTexture* FUN_00a5ff10(NiPixelData*, void*, TextureFormatPrefs*);

// Converts a NiTexture to a supported D3D format by copying each mip level and swapping RGB bytes when needed, then builds a new NiTexture from the result.
// @fnv 0x00b6bbd0
NiTexture* FUN_00b6bbd0(NiTexture* texture, const NiPixelFormat* pixelFormat)
{
    TextureRenderer* renderer = DAT_011f4748;
    NiPixelFormat format = *pixelFormat;
    if (!texture || !renderer)
        return 0;
    int d3dFormat = FUN_00e7bd20(&format);
    switch (d3dFormat)
    {
    case 32:
        d3dFormat = 21;
        break;
    case 21:
    case 0x31545844:
    case 0x33545844:
    case 0x35545844:
        break;
    default:
        return 0;
    }
    IDirect3DDevice9* device = renderer->m_pkDevice;
    unsigned int width = texture->GetWidth();
    unsigned int height = texture->GetHeight();
    unsigned int levels = texture->m_pkPixelData ? texture->m_pkPixelData->m_uiMipmapLevels : 1;
    IDirect3DTexture9* source = texture->m_pTextureRendererData->GetTexture();
    IDirect3DTexture9* destination;
    HRESULT hStatus =
        device->CreateTexture(width, height, levels, 0, (D3DFORMAT)d3dFormat, D3DPOOL_SYSTEMMEM, &destination, 0);
    NiPixelData* pixels = 0;
    if (hStatus != 0 || !destination)
        return 0;
    IDirect3DSurface9* sourceSurface;
    IDirect3DSurface9* destinationSurface;
    D3DLOCKED_RECT lockedRect;
    pixels = new NiPixelData(width, height, format, levels, 1);
    for (unsigned int level = 0; level < levels; ++level)
    {
        source->GetSurfaceLevel(level, &sourceSurface);
        destination->GetSurfaceLevel(level, &destinationSurface);
        FUN_00ee6de6(destinationSurface, 0, 0, sourceSurface, 0, 0, 0xffffffff, 0);
        destinationSurface->LockRect(&lockedRect, 0, 0);
        if (d3dFormat == 21)
        {
            _memmove(pixels->m_pucPixels + pixels->m_puiOffset[level], lockedRect.pBits,
                     pixels->m_puiHeight[level] * lockedRect.Pitch);
            unsigned char* pPixelData = pixels->m_pucPixels + pixels->m_puiOffset[level];
            unsigned int bytes = pixels->m_puiWidth[level] * pixels->m_puiHeight[level] * 4;
            for (unsigned int offset = 0; offset < bytes; offset += 4)
            {
                unsigned char red = pPixelData[offset];
                pPixelData[offset] = pPixelData[offset + 2];
                pPixelData[offset + 2] = red;
            }
        }
        else if (d3dFormat == 0x31545844 || d3dFormat == 0x33545844 || d3dFormat == 0x35545844)
        {
            unsigned char* pPixelData = pixels->m_pucPixels + pixels->m_puiOffset[level];
            unsigned int rows = pixels->m_puiHeight[level];
            if (rows < 4)
                rows = 4;
            _memmove(pPixelData, lockedRect.pBits, (rows * lockedRect.Pitch) / 4);
        }
        destinationSurface->UnlockRect();
        destinationSurface->Release();
        sourceSurface->Release();
    }
    destination->Release();
    unsigned char oldFlag = DAT_011f4448;
    DAT_011f4448 = 0;
    void* pvGlobalData = *(void**)DAT_011fa050;
    NiTexture* pResultTexture = FUN_00a5ff10(pixels, pvGlobalData, &DAT_011a9598);
    DAT_011a9595 = levels > 1;
    DAT_011f4448 = oldFlag;
    return pResultTexture;
}
}  // namespace fnv_00b6bbd0
