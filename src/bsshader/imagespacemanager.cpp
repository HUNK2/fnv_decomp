// bsshader/imagespacemanager.cpp: ImageSpaceManager, Derived, Host, ImageSpaceManager_b8b and more (60 functions)

#include "imagespacemanager_geometry.h"
#include "imagespacemanager_types_ImageSpaceManager.h"
#include "imagespacemanager_effect.h"
#include "imagespacemanager_globals.h"

// @fnv 0x00b8b000
void ImageSpaceManager::SetRadialBlurParameters(float strength, float rampUp, float start, float rampDown,
                                                float downStart, const NiPoint2& arCenter)
{
    if (strength > m_fRadialBlurStrength)
    {
        m_fRadialBlurStrength = strength;
        m_fRadialBlurRampUp = rampUp;
        m_fRadialBlurStart = start;
        m_fRadialBlurRampDown = rampDown;
        m_fRadialBlurDownStart = downStart;
        m_kRadialBlurCenter = arCenter;
    }
}

// If strength exceeds the stored maximum, records the new strength, mode, distance, range and mask constant for depth of field.
// @fnv 0x00b8b0d0
void ImageSpaceManager::SetDepthOfFieldParameters(float strength, unsigned int mode, float maskConst, float distance,
                                                  float range)
{
    if (strength > m_fDepthOfFieldStrength)
    {
        m_fDepthOfFieldStrength = strength;
        m_bDepthOfFieldUsesObject = false;
        if (mode > 2)
        {
            m_bDepthOfFieldUsesObject = true;
            mode -= 3;
        }
        m_eDepthOfFieldMode = (ImageSpaceEffectDepthOfField__DepthOfFieldMode)mode;
        m_fDepthOfFieldMaskConstant = distance;
        m_fDepthOfFieldDistance = range;
        m_fDepthOfFieldRange = maskConst;
    }
}

extern ImageSpaceManager* DAT_011f91ac;
#pragma optimize("", off)
// @fnv 0x004e3270
ImageSpaceManager* ImageSpaceManager::FUN_004e3270()
{
    return DAT_011f91ac;
}
#pragma optimize("", on)

// Creates a NiScreenElementsData and NiScreenElements, configures its data, names it "Imagespace Effect Geometry", and updates it with zero time.
// @fnv 0x00b8c170
void ImageSpaceManager::CreateMenuBackgroundGeometry()
{
    m_pMenuBackgroundScreenElementsData = new NiScreenElementsData(false, false, 1, 1, 1, 4, 1, 2, 1);
    m_pMenuBackgroundScreenGeometry = new NiScreenElements(m_pMenuBackgroundScreenElementsData);
    m_pMenuBackgroundScreenGeometry->GetData()->FUN_00a87ae0(4, 0, 0);
    m_pMenuBackgroundScreenGeometry->GetData()->SetRectangleBounds(0, DAT_01012054, 1.0f, DAT_010162c0, DAT_0104a494);
    m_pMenuBackgroundScreenGeometry->GetData()->FUN_00a88130(0, 0, 0.0f, 0.0f, 1.0f, 1.0f);
    m_pMenuBackgroundScreenGeometry->GetData()->FUN_00a87900();
    m_pMenuBackgroundScreenGeometry->SetName(GeometryString("Imagespace Effect Geometry"));
    m_pMenuBackgroundScreenGeometry->UpdateSceneObject();
    NiUpdateData update;
    update.time = 0.0f;
    update.a = false;
    update.b = false;
    update.c = false;
    update.d = false;
    update.e = false;
    m_pMenuBackgroundScreenGeometry->Update(update);
}

// @fnv 0x00b8b200
void __stdcall FUN_00b8b200(bool value)
{
    DAT_012023f0 = value;
}

// @fnv 0x00b8b130
void ImageSpaceManager::ApplyDepthOfFieldParamModifierWeather(float strength, unsigned int mode, float maskConst,
                                                              float distance, float range)
{
    m_bMenuBackgroundBlendEnabled = false;
    m_fDepthOfFieldEffectStrength += strength;
    m_eDepthOfFieldTargetMode = (ImageSpaceEffectDepthOfField__DepthOfFieldMode)mode;
    m_fDepthOfFieldEffectDistance += distance;
    m_fDepthOfFieldEffectRange += range;
    m_fDepthOfFieldMaskValue += maskConst;
}

// Adds the r, g, b and a components of color to the tint color stored in the manager.
// @fnv 0x00b8b5c0
void ImageSpaceManager::ApplyTintColorParamModifierWeather(RgbaColor& color)
{
    RgbaColor& tint = m_kPartialRenderColor;
    tint.r += color.r;
    tint.g += color.g;
    tint.b += color.b;
    tint.a += color.a;
}

// Adds the r, g, b and a components of color to the fade color stored in the manager.
// @fnv 0x00b8b690
void ImageSpaceManager::ApplyFadeColorParamModifierWeather(RgbaColor& color)
{
    RgbaColor* fade = &m_kWeatherFadeColor;
    fade->r += color.r;
    fade->g += color.g;
    fade->b += color.b;
    fade->a += color.a;
}

// Accumulates the alpha-weighted RGB of color into a running tint sum and tracks the maximum alpha seen.
// @fnv 0x00b8b540
void ImageSpaceManager::ApplyTintColorParamModifier(RgbaColor& color)
{
    if (color.a > m_fPartialRenderBlend)
        m_fPartialRenderBlend = color.a;
    float r = color.r * color.a;
    color.r = r;
    color.g = color.g * color.a;
    color.b = color.b * color.a;
    m_kModifierColor.r += r;
    m_kModifierColor.g += color.g;
    m_kModifierColor.b += color.b;
    m_kModifierColor.a += color.a;
}

// Tracks the maximum alpha seen and adds the alpha-premultiplied color into the accumulator, scaling r, g and b by a.
// @fnv 0x00b8b610
void ImageSpaceManager::SetFadeColorParamModifier(RgbaColor& color)
{
    if (color.a > m_fFadeColorAlpha)
        m_fFadeColorAlpha = color.a;
    float r = color.r * color.a;
    color.r = r;
    color.g = color.g * color.a;
    color.b = color.b * color.a;
    m_kAccumulatedColor.r += r;
    m_kAccumulatedColor.g += color.g;
    m_kAccumulatedColor.b += color.b;
    m_kAccumulatedColor.a += color.a;
}

// Adds the given radial blur parameters and center offset into the manager's accumulated weather values.
// @fnv 0x00b8b6e0
void ImageSpaceManager::ApplyRadialBlurParamModifierWeather(float strength, float rampUp, float start, float rampDown,
                                                            float downStart, const NiPoint2& center)
{
    m_fWeatherRadialBlurStrength += strength;
    m_fWeatherRadialBlurRampUp += rampUp;
    m_fWeatherRadialBlurStart += start;
    m_fWeatherRadialBlurRampDown += rampDown;
    m_fWeatherRadialBlurDownStart += downStart;
    NiPoint2& weather = m_kWeatherRadialBlurCenter;
    weather.x += center.x;
    weather.y += center.y;
}

// Iterates the effect list up to EFFECT_TOP_LEVEL_END and calls Setup(this, 0) on each non-null ImageSpaceEffect.
// @fnv 0x00b8b360
void ImageSpaceManager::SetupEffects()
{
    for (int i = 0; i < ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_TOP_LEVEL_END; i++)
    {
        ImageSpaceEffect* effect = pEffectList.m_pBase[i];
        if (effect)
            effect->Setup(this, 0);
    }
}

// @fnv 0x00b8b390
bool ImageSpaceManager::IsEffectActive(ImageSpaceManager__ImageSpaceEffectEnum index)
{
    ImageSpaceEffect* effect = pEffectList.m_pBase[index];
    if (effect)
        return effect->IsActive();
    return false;
}

// Scans the effect list up to EFFECT_ENDOFFRAME_END, counts active effects and records the last active effect's enum index.
// @fnv 0x00b8b3f0
void ImageSpaceManager::PrepareEndOfFrameEffects()
{
    m_eEndOfFrameEffect = ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_NONE;
    m_iEndOfFrameEffectCount = 0;
    if (m_bHasEndOfFrameEffects)
    {
        for (int i = 0; i < ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_ENDOFFRAME_END; i++)
        {
            ImageSpaceEffect* effect = pEffectList.m_pBase[i];
            if (!effect)
                continue;
            if (!effect->IsActive())
                continue;
            m_iEndOfFrameEffectCount++;
            m_eEndOfFrameEffect = (ImageSpaceManager__ImageSpaceEffectEnum)i;
        }
    }
}

#include "imagespacemanager_array.h"

// @fnv 0x00b8b270
void NiTArray<bool, NiTMallocInterface<bool> >::SetAt(unsigned int index, const bool& value)
{
    if (index >= m_usSize)
    {
        m_usSize = (unsigned short)(index + 1);
        if (value)
            ++m_usESize;
    }
    else
    {
        if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
            --m_usESize;
    }
    m_pBase[index] = value;
}

// @fnv 0x00b8b190
BSRenderedTexture* ImageSpaceManager::GetDepthRenderedTexture()
{
    const ImageSpaceTexture& depth = m_kDepthTexture;
    if (!depth.GetTexture())
        m_kDepthTexture.CreateRenderTargetTexture(BSTextureManager::BSTM_RT_SCENE_DEPTH_BUFFER);
    return depth.GetRenderedTexture();
}

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

// @fnv 0x00b8b9a0
void ImageSpaceManager::BeginParamModifiers()
{
    float alpha = m_kBlendedParameterData.m_afColorAndAlphaParameters[7];
    m_fPartialRenderBlend = alpha;
    m_kModifierColor.r = m_kBlendedParameterData.m_afColorAndAlphaParameters[4] * alpha;
    m_kModifierColor.g = m_kBlendedParameterData.m_afColorAndAlphaParameters[5] * alpha;
    m_kModifierColor.b = m_kBlendedParameterData.m_afColorAndAlphaParameters[6] * alpha;
    m_kModifierColor.a = m_kBlendedParameterData.m_afColorAndAlphaParameters[7];
    {
        RgbaColor clear;
        clear.r = 0.0f;
        clear.g = 0.0f;
        clear.b = 0.0f;
        clear.a = 0.0f;
        m_kPartialRenderColor = clear;
    }
    m_fFadeColorAlpha = 0.0f;
    m_kAccumulatedColor.r = 0.0f;
    m_kAccumulatedColor.g = 0.0f;
    m_kAccumulatedColor.b = 0.0f;
    m_kAccumulatedColor.a = 0.0f;
    m_kWeatherFadeColor.r = 0.0f;
    m_kWeatherFadeColor.g = 0.0f;
    m_kWeatherFadeColor.b = 0.0f;
    m_kWeatherFadeColor.a = 0.0f;
    m_fDoubleVisionStrength = 0.0f;
    m_fWeatherDoubleVisionStrength = 0.0f;
    m_fRadialBlurStrength = 0.0f;
    m_fRadialBlurRampUp = 0.0f;
    m_fRadialBlurStart = 0.0f;
    m_fRadialBlurRampDown = 0.0f;
    m_fRadialBlurDownStart = 0.0f;
    {
        NiPoint2 clear;
        clear.x = 0.0f;
        clear.y = 0.0f;
        m_kRadialBlurCenter = clear;
    }
    m_fDepthOfFieldStrength = 0.0f;
    m_fDepthOfFieldMaskConstant = 0.0f;
    m_fDepthOfFieldDistance = 0.0f;
    m_fDepthOfFieldRange = 0.0f;
    m_eDepthOfFieldMode = (ImageSpaceEffectDepthOfField__DepthOfFieldMode)3;
    m_bDepthOfFieldUsesObject = false;
    m_fBlurRadius = 0.0f;
    m_fMenuBackgroundBlendValue = 0.0f;
    m_fWeatherBlurRadius = 0.0f;
    m_fAdditionalImageSpaceValue = 0.0f;
    m_fWeatherRadialBlurStrength = 0.0f;
    m_fWeatherRadialBlurRampUp = 0.0f;
    m_fWeatherRadialBlurStart = 0.0f;
    m_fWeatherRadialBlurRampDown = 0.0f;
    m_fWeatherRadialBlurDownStart = 0.0f;
    {
        NiPoint2 clear;
        clear.x = 0.0f;
        clear.y = 0.0f;
        m_kWeatherRadialBlurCenter = clear;
    }
    m_fDepthOfFieldEffectStrength = 0.0f;
    m_fDepthOfFieldEffectDistance = 0.0f;
    m_fDepthOfFieldEffectRange = 0.0f;
    m_fDepthOfFieldMaskValue = 0.0f;
    m_eDepthOfFieldTargetMode = (ImageSpaceEffectDepthOfField__DepthOfFieldMode)3;
    m_bMenuBackgroundBlendEnabled = false;
    m_fMenuBackgroundBlendTarget = 0.0f;
    fnv_zlib_memset(m_kModifierParameterData, 0, sizeof(m_kModifierParameterData));
}

struct FUN_00b8af10_shell : public ImageSpaceManager
{
    void RaiseHighestBlurRadius(float);
};

// If afBlurRadius exceeds the stored highest blur value at offset 0x25c, it stores afBlurRadius there.
// @fnv 0x00b8af10
void FUN_00b8af10_shell::RaiseHighestBlurRadius(float afBlurRadius)
{
    float& fHighestBlur = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x25c);
    if (afBlurRadius > fHighestBlur)
        fHighestBlur = afBlurRadius;
}

struct FUN_00b8af40_shell : public ImageSpaceManager
{
    void FUN_00b8af40(float);
};

// @fnv 0x00b8af40
void FUN_00b8af40_shell::FUN_00b8af40(float afBlurRadius)
{
    m_fWeatherBlurRadius += afBlurRadius;
}

struct FUN_00b8af60_shell : public ImageSpaceManager
{
    void RaiseBlurRadius(float);
};

// Raises the float at offset 0x2f0 to afBlurRadius if afBlurRadius is greater than its current value.
// @fnv 0x00b8af60
void FUN_00b8af60_shell::RaiseBlurRadius(float afBlurRadius)
{
    float& val = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x2f0);
    if (afBlurRadius > val)
        val = afBlurRadius;
}

struct FUN_00b8af90_shell : public ImageSpaceManager
{
    void FUN_00b8af90(float);
};

// @fnv 0x00b8af90
void FUN_00b8af90_shell::FUN_00b8af90(float afBlurRadius)
{
    *(float*)((char*)this + 0x2f4) += afBlurRadius;
}

struct FUN_00b8afb0_shell : public ImageSpaceManager
{
    void FUN_00b8afb0(float);
};

// Raises the stored double-vision value to afDoubleVision when the new value is greater.
// @fnv 0x00b8afb0
void FUN_00b8afb0_shell::FUN_00b8afb0(float afDoubleVision)
{
    if (afDoubleVision > m_fWeatherDoubleVisionStrength)
        m_fWeatherDoubleVisionStrength = afDoubleVision;
}

struct FUN_00b8afe0_shell : public ImageSpaceManager
{
    void AddDoubleVision(float);
};

// @fnv 0x00b8afe0
void FUN_00b8afe0_shell::AddDoubleVision(float afDoubleVision)
{
    *(float*)((char*)this + 0x268) += afDoubleVision;
}

// @fnv 0x00b8b210
void __fastcall FUN_00b8b210(char* pThis, int, int mode)
{
    if (mode != *(int*)(pThis + 0x58))
    {
        *(bool*)(pThis + 0x5) = true;
        *(int*)(pThis + 0x58) = mode;
        *(float*)(pThis + 0x70) = (mode == 1 || mode == 0) ? 1.0f : 0.0f;
        *(float*)(pThis + 0x74) = (mode == 2 || mode == 0) ? 1.0f : 0.0f;
    }
}

struct VTableObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void*);
    virtual void v9(void*, int);
    virtual void v10(void*);
};

struct PtrTable
{
    VTableObj* p00;
    VTableObj* p04;
    int p08;
    VTableObj* p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
    VTableObj* p20;
};

// @fnv 0x00b8b440
void __fastcall FUN_00b8b440(char* pThis, int, bool bFlag)
{
    PtrTable** ppTable = (PtrTable**)(pThis + 8);
    if ((*ppTable)->p00)
    {
        (*ppTable)->p00->v8(pThis + 0x50);
    }
    if ((*ppTable)->p04)
    {
        (*ppTable)->p04->v8(pThis + 0x14);
    }
    if ((*ppTable)->p20)
    {
        (*ppTable)->p20->v8(pThis + 0x5c);
    }
    if ((*ppTable)->p0c)
    {
        (*ppTable)->p0c->v9(pThis + 0x78, *(int*)(pThis + 0xa8));
        (*ppTable)->p0c->v10(pThis + 0x68);
    }
    if (!bFlag)
    {
        DAT_011ad87c = *(float*)(pThis + 0x34);
        DAT_011ad880 = 1.0f;
    }
    else
    {
        DAT_011ad880 = *(float*)(pThis + 0x34);
    }
    DAT_011f9190 = *(float*)(pThis + 0x40);
    DAT_011f918c = *(float*)(pThis + 0x48);
    DAT_011f9188 = *(float*)(pThis + 0x44);
    DAT_011f9184 = *(float*)(pThis + 0x1c);
}

// Sets the first three entries of the bool array at self+0x58 to true and the fourth to false.
// @fnv 0x00b8bc20
void __fastcall FUN_00b8bc20(char* self, int)
{
    NiTArray<bool, NiTMallocInterface<bool> >* arr =
        reinterpret_cast<NiTArray<bool, NiTMallocInterface<bool> >*>(self + 0x58);
    bool val;
    val = true;
    arr->SetAt(0, val);
    val = true;
    arr->SetAt(1, val);
    val = true;
    arr->SetAt(2, val);
    val = false;
    arr->SetAt(3, val);
}

class D3DRenderStateGroup
{
  public:
    void SetRenderState(unsigned int, unsigned int, bool);
    static D3DRenderStateGroup* __cdecl GetCurrentRenderStateGroup(void);
};

// Ensures the render state object exists, then sets render states 0x34, 0x38, 0x39 and 0x37 to 1, 7, 0x80 and 1.
// @fnv 0x00b8bfe0
void __fastcall FUN_00b8bfe0(char* pThis, int)
{
    char* pPass = *(char**)(pThis + 0x5c);
    if (*(D3DRenderStateGroup**)(pPass + 0x30) == 0)
        *(D3DRenderStateGroup**)(pPass + 0x30) = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    (*(D3DRenderStateGroup**)(pPass + 0x30))->SetRenderState(0x34, 1, true);

    pPass = *(char**)(pThis + 0x5c);
    if (*(D3DRenderStateGroup**)(pPass + 0x30) == 0)
        *(D3DRenderStateGroup**)(pPass + 0x30) = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    (*(D3DRenderStateGroup**)(pPass + 0x30))->SetRenderState(0x38, 7, true);

    pPass = *(char**)(pThis + 0x5c);
    if (*(D3DRenderStateGroup**)(pPass + 0x30) == 0)
        *(D3DRenderStateGroup**)(pPass + 0x30) = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    (*(D3DRenderStateGroup**)(pPass + 0x30))->SetRenderState(0x39, 0x80, true);

    pPass = *(char**)(pThis + 0x5c);
    if (*(D3DRenderStateGroup**)(pPass + 0x30) == 0)
        *(D3DRenderStateGroup**)(pPass + 0x30) = D3DRenderStateGroup::GetCurrentRenderStateGroup();
    (*(D3DRenderStateGroup**)(pPass + 0x30))->SetRenderState(0x37, 1, true);
}

struct ShaderInitBlock_00b8c0e0
{
    const char* name;
    int zero;
    int pad[17];
};

struct Vtable_00b8c0e0
{
    char pad0[0x13c];
    void(__thiscall* fn_13c)(void*, ShaderInitBlock_00b8c0e0*, ShaderInitBlock_00b8c0e0*, const char*, const char*,
                             const char*);
    char pad1[0x14c - 0x140];
    void(__thiscall* fn_14c)(void*);
};

struct Obj_00b8c0e0
{
    Vtable_00b8c0e0* vt;
};

static const char* const unused_str_order_00b8c0e0 = "TV";

// Fills vertex and pixel shader init blocks with the TV shader paths, calls the vtable init with "TV", "vs_1_1", "ps_2_0", then the vtable finalize.
// @fnv 0x00b8c0e0
void __fastcall InitTVShader(Obj_00b8c0e0* pObj, int)
{
    ShaderInitBlock_00b8c0e0 vsBlock;
    ShaderInitBlock_00b8c0e0 psBlock;
    vsBlock.name = "imagespace\\1x\\v\\base.v.hlsl";
    vsBlock.zero = 0;
    fnv_zlib_memset(vsBlock.pad, 0, 0x44);
    psBlock.name = "imagespace\\2x\\p\\tv.p.hlsl";
    psBlock.zero = 0;
    fnv_zlib_memset(psBlock.pad, 0, 0x44);
    pObj->vt->fn_13c(pObj, &vsBlock, &psBlock, "TV", "vs_1_1", "ps_2_0");
    pObj->vt->fn_14c(pObj);
}

int __cdecl FUN_00b59d30(int, int, int*);
// @fnv 0x00b8b1c0
int __stdcall FUN_00b8b1c0(int a, int b)
{
    return FUN_00b59d30(a, b, &b);
}

extern float DAT_012023f4;
extern float DAT_012023f8;
// @fnv 0x00b8b1e0
void __stdcall FUN_00b8b1e0(const int* aiValues)
{
    *reinterpret_cast<int*>(&DAT_012023f4) = aiValues[0];
    *reinterpret_cast<int*>(&DAT_012023f8) = aiValues[1];
}

extern ImageSpaceManager* DAT_011f91ac;

void __stdcall FUN_00b8b200(bool value);

extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);

extern "C" void* __cdecl _memmove(void*, const void*, unsigned int);
extern ImageSpaceModifierParameterData DAT_011ff940;
extern float DAT_012003d0;
extern float _DAT_01202400;

// Copies 0x98 bytes from the object's source pointer at 0xb0 or 0xac into offset 0x14, falling back to DAT_011ff940, then zeroes two floats.
// @fnv 0x00b8b500
void __fastcall FUN_00b8b500(void* thisPtr, int aiUnused)
{
    char* pSource = *(char**)((char*)thisPtr + 0xb0);
    if (pSource)
    {
        _memmove((char*)thisPtr + 0x14, pSource, 0x98);
        _DAT_01202400 = 0.0f;
        DAT_012003d0 = 0.0f;
        return;
    }
    pSource = *(char**)((char*)thisPtr + 0xac);
    if (pSource)
    {
        _memmove((char*)thisPtr + 0x14, pSource, 0x98);
        _DAT_01202400 = 0.0f;
        DAT_012003d0 = 0.0f;
        return;
    }
    _memmove((char*)thisPtr + 0x14, &DAT_011ff940, 0x98);
    _DAT_01202400 = 0.0f;
    DAT_012003d0 = 0.0f;
}

struct FUN_00b8bc80_shell
{
    NiTArray<bool, NiTMallocInterface<bool> > m_aiIndexedValues;  // at offset 0x58
    void __thiscall FUN_00b8bc80();
};
// Sets the bool array at offset 0x58: index 0, 1 and 3 to true and index 2 to false.
// @fnv 0x00b8bc80
void __thiscall FUN_00b8bc80_shell::FUN_00b8bc80()
{
    NiTArray<bool, NiTMallocInterface<bool> >* p = (NiTArray<bool, NiTMallocInterface<bool> >*)((char*)this + 0x58);
    p->SetAt(0, true);
    p->SetAt(1, true);
    p->SetAt(2, false);
    p->SetAt(3, true);
}

struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};

struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void __thiscall SetSize(unsigned int);
};

extern int DAT_010affa0;
extern int DAT_010affc0;

struct FUN_00b8bce0 : ImageSpaceEffectShader
{
    void* m_vtbl;
    char pad1[0x68];
    void* m_6c;
    char pad2[0x24];
    NiTPrimitiveArray_ImageSpaceTexture___ m_ppData;
    FUN_00b8bce0();
};

// @fnv 0x00b8bce0
FUN_00b8bce0::FUN_00b8bce0()
{
    m_vtbl = &DAT_010affc0;
    m_6c = &DAT_010affa0;
    m_ppData.SetSize(5);
}

extern const char g_011fed88_arg1[];
// Returns the address of the string g_011fed88_arg1.
// @fnv 0x00b8bd90
const char* __cdecl GetArg1String()
{
    return g_011fed88_arg1;
}

namespace fnv_00b8bea0 {
struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void __thiscall SetSize(unsigned int);
};
struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
};
extern int DAT_010b0174;
extern int DAT_010b0198;
struct FUN_00b8bea0 : ImageSpaceEffectShader
{
    int* v0;
    char pad1[0x68];
    int* v6c;
    char pad2[0x24];
    NiTPrimitiveArray_ImageSpaceTexture___ arr;
    FUN_00b8bea0();
};
// Initializes the object's two pointers to DAT_010b0198 and DAT_010b0174 and sets the texture array size to 2.
// @fnv 0x00b8bea0
FUN_00b8bea0::FUN_00b8bea0()
{
    v0 = &DAT_010b0198;
    v6c = &DAT_010b0174;
    arr.SetSize(2);
}
}  // namespace fnv_00b8bea0

struct FUN_00b8bf10_Desc
{
    const char* file;
    int flags;
    int r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15, r16;
};
struct FUN_00b8bf10_Obj;
typedef void(__thiscall* FUN_00b8bf10_Add)(FUN_00b8bf10_Obj*, FUN_00b8bf10_Desc*, FUN_00b8bf10_Desc*, const char*,
                                           const char*, const char*);
typedef void(__thiscall* FUN_00b8bf10_Fin)(FUN_00b8bf10_Obj*);
struct FUN_00b8bf10_Obj
{
    void** vt;
};
// Registers the Sunbeams shader with vertex shader base.v.hlsl and pixel shader sunbeams.p.hlsl, then finalizes it.
// @fnv 0x00b8bf10
void __fastcall RegisterSunbeamsShader(FUN_00b8bf10_Obj* self, int unused)
{
    FUN_00b8bf10_Desc a;
    FUN_00b8bf10_Desc b;
    a.file = "imagespace\\1x\\v\\base.v.hlsl";
    a.flags = 0;
    fnv_zlib_memset(&a.r0, 0, 0x44);
    b.file = "imagespace\\2x\\p\\sunbeams.p.hlsl";
    b.flags = 0;
    fnv_zlib_memset(&b.r0, 0, 0x44);
    reinterpret_cast<FUN_00b8bf10_Add>(self->vt[0x13c / 4])(self, &a, &b, "Sunbeams", "vs_1_1", "ps_2_a");
    reinterpret_cast<FUN_00b8bf10_Fin>(self->vt[0x14c / 4])(self);
}

namespace fnv_00b8c070 {
extern int DAT_010b0318;
extern int DAT_010b0338;

struct ImageSpaceEffectShader
{
    ImageSpaceEffectShader();
    ~ImageSpaceEffectShader();
    char pad[0x94];
};

struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void __thiscall SetSize(unsigned int);
};

struct FUN_00b8c070 : ImageSpaceEffectShader
{
    NiTPrimitiveArray_ImageSpaceTexture___ m;
    FUN_00b8c070();
};

// @fnv 0x00b8c070
FUN_00b8c070::FUN_00b8c070()
{
    *(int**)this = &DAT_010b0338;
    *(int**)((char*)this + 0x6c) = &DAT_010b0318;
    m.SetSize(4);
}
}  // namespace fnv_00b8c070

extern int DAT_010affa0;
extern int DAT_010affc0;
struct H_00c03a20
{
    void __thiscall FUN_00c03a20();
};
void __cdecl _delete(void*, unsigned int);
struct S_00b8bd50
{
    void* __thiscall FUN_00b8bd50(unsigned int);
};
// @fnv 0x00b8bd50
void* __thiscall S_00b8bd50::FUN_00b8bd50(unsigned int flags)
{
    *(int*)this = (int)&DAT_010affc0;
    *(int*)((char*)this + 0x6c) = (int)&DAT_010affa0;
    ((H_00c03a20*)this)->FUN_00c03a20();
    if (flags & 1)
        _delete(this, 0xd0);
    return this;
}

struct Obj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
};
struct Container
{
    char pad[136];
    char* arr[82];
};
struct Host
{
    char pad[8];
    Container* ptr;
    void FUN_00b8b3b0();
};
// @fnv 0x00b8b3b0
void Host::FUN_00b8b3b0()
{
    for (unsigned int i = 0x88; i < 0x1D0; i += 4)
    {
        if (*(char**)((char*)ptr + i))
        {
            char* pEntry = *(char**)((char*)ptr + i);
            Obj* o = pEntry ? (Obj*)(pEntry - 0x6C) : 0;
            o->f72();
        }
    }
}

extern int DAT_010b0198;
extern int DAT_010b0174;
void __cdecl _delete(void*, unsigned int);
struct UnkClass
{
    void FUN_00c03a20();
    void* DestroyIfFlagged(unsigned int);
};
// Resets two vtable pointers, calls FUN_00c03a20, and deletes this with size 0xd0 when flag bit 0 is set, returning this.
// @fnv 0x00b8bfa0
void* UnkClass::DestroyIfFlagged(unsigned int auiFlags)
{
    *(int**)this = &DAT_010b0198;
    *(int**)((char*)this + 0x6c) = &DAT_010b0174;
    FUN_00c03a20();
    if (auiFlags & 1)
        _delete(this, 0xd0);
    return this;
}

// @fnv 0x00b8aea0
void __fastcall FUN_00b8aea0(char* self)
{
    float* p = (float*)(self + 0x14c);
    int i = 0xf;
    for (; i; --i)
    {
        p[-0x26] = 1.0f;
        *p = 0.0f;
        ++p;
    }
    *(float*)(self + 0xf0) = 1.0f;
    *(float*)(self + 0xf4) = 1.0f;
    *(float*)(self + 0xf8) = 1.0f;
    *(float*)(self + 0x188) = 0.0f;
    *(float*)(self + 0x18c) = 0.0f;
    *(float*)(self + 0x190) = 0.0f;
    p = (float*)(self + 0x1b0);
    for (i += 0xc; i; --i)
    {
        p[-0x26] = 1.0f;
        *p = 0.0f;
        ++p;
    }
}

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long ulValue);

class B8AD00Header
{
  public:
    unsigned int m_auiFields[15];
    unsigned int m_auiA[3];
    unsigned int m_auiB[3];
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int m_auiC[12];
    unsigned int m_uiLast;

    void SwapEndian();
};

// Swap the header from big-endian.
// @fnv 0x00b8ad00
void B8AD00Header::SwapEndian()
{
    for (int i = 0; i < 15; i++)
        m_auiFields[i] = _byteswap_ulong(m_auiFields[i]);
    for (int j = 0; j < 3; j++)
        m_auiA[j] = _byteswap_ulong(m_auiA[j]);
    for (int j = 0; j < 3; j++)
        m_auiB[j] = _byteswap_ulong(m_auiB[j]);
    for (int j = 0; j < 12; j++)
        m_auiC[j] = _byteswap_ulong(m_auiC[j]);
    m_uiLast = _byteswap_ulong(m_uiLast);
}

extern ImageSpaceModifierParameterData DAT_011ff940;

// @fnv 0x00b8ad70
void __cdecl FUN_00b8ad70()
{
    DAT_011ff940.m_afFirstParameterSet[0] = 0.5f;
    DAT_011ff940.m_afFirstParameterSet[1] = 7.0f;
    DAT_011ff940.m_afFirstParameterSet[3] = 1.0f;
    DAT_011ff940.m_afFirstParameterSet[4] = 1.0f;
    DAT_011ff940.m_afFirstParameterSet[5] = 1.0f;
    DAT_011ff940.m_afFirstParameterSet[6] = 2.25f;
    DAT_011ff940.m_afFirstParameterSet[7] = 0.225f;
    DAT_011ff940.m_afFirstParameterSet[8] = 1.0f;
    DAT_011ff940.m_afFirstParameterSet[9] = 0.0f;
    DAT_011ff940.m_afFirstParameterSet[10] = 0.0f;
    DAT_011ff940.m_afFirstParameterSet[11] = 1.5f;
    DAT_011ff940.m_afFirstParameterSet[12] = 1.5f;
    DAT_011ff940.m_afFirstParameterSet[13] = 1.0f;
    DAT_011ff940.m_afFirstParameterSet[2] = 1.0f;
    DAT_011ff940.m_afSecondParameterSet[0] = 0.03f;
    DAT_011ff940.m_afSecondParameterSet[2] = 0.2f;
    DAT_011ff940.m_afSecondParameterSet[1] = 0.7f;
    DAT_011ff940.m_afThirdParameterSet[0] = 0.5f;
    DAT_011ff940.m_afThirdParameterSet[1] = 0.5f;
    DAT_011ff940.m_afThirdParameterSet[2] = 0.02f;
    DAT_011ff940.m_afFourthParameterSet[3] = 2.5f;
    DAT_011ff940.m_afFourthParameterSet[0] = 0.21f;
    DAT_011ff940.m_afFourthParameterSet[1] = 0.5f;
    DAT_011ff940.m_afFourthParameterSet[2] = 0.78f;
    DAT_011ff940.m_afColorAndAlphaParameters[3] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[2] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[0] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[4] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[5] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[6] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[8] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[9] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[10] = 1.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[1] = 0.5f;
    DAT_011ff940.m_afColorAndAlphaParameters[7] = 0.0f;
    DAT_011ff940.m_afColorAndAlphaParameters[11] = 0.0f;
}

struct B8B060Pair
{
    int m_iFirst;
    int m_iSecond;
};

class B8B060Request
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    float m_fTopicParamB;
    float m_fParamC;
    float m_fParamD;
    float m_fParamA;
    float m_fParamB;
    B8B060Pair m_kPair;
    int m_iType;

    void SetIfHigherPriority(float fPriority, int iType, float fA, float fB, float fC, float fD,
                             const B8B060Pair& kPair);
};

// If fPriority exceeds the stored priority, stores the priority, type, four float parameters and the pair.
// @fnv 0x00b8b060
void B8B060Request::SetIfHigherPriority(float fPriority, int iType, float fA, float fB, float fC, float fD,
                                        const B8B060Pair& kPair)
{
    if (fPriority > m_fTopicParamB)
    {
        m_fTopicParamB = fPriority;
        m_fParamC = fC;
        m_fParamD = fD;
        m_kPair = kPair;
        m_fParamA = fA;
        m_iType = iType;
        m_fParamB = fB;
    }
}

struct Vec3_b8b7d0
{
    float x;
    float y;
    float z;
};

struct NiPosGlobal_b8b7d0
{
    int unk00;
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
    Vec3_b8b7d0 m8c;
};

extern NiPosGlobal_b8b7d0* DAT_011f917c;
extern "C" double __cdecl sqrt(double);

int __cdecl FUN_00b59d30(int, int, int*);

struct FUN_00b8b7d0_cls
{
    void SetIfHigherPriority(float, int, float, float, float, float, int*);
    void FUN_00b8b7d0(float a0, int a1, float a2, float a3, Vec3_b8b7d0* p);
};

// @fnv 0x00b8b7d0
void FUN_00b8b7d0_cls::FUN_00b8b7d0(float afParam0, int aiParam1, float afParam2, float afParam3,
                                    Vec3_b8b7d0* pPosition)
{
    NiPosGlobal_b8b7d0* g = DAT_011f917c;
    Vec3_b8b7d0 gp = g->m8c;
    Vec3_b8b7d0 pos = *pPosition;
    Vec3_b8b7d0 d;
    d.x = pos.x - gp.x;
    d.y = pos.y - gp.y;
    d.z = pos.z - gp.z;
    float t = d.x * d.x + d.y * d.y + d.z * d.z;
    t = (float)sqrt((double)t);
    float dist = t;
    FUN_00b59d30((int)pPosition, (int)&pos, (int*)&t);
    t = t + afParam3;
    SetIfHigherPriority(afParam0, aiParam1, dist, dist, afParam2, t, (int*)&pos);
}

extern "C" void FUN_00ec61c0(void* a, unsigned int b, unsigned int c);
extern "C" void* FUN_00e7f5d0();

class ISPassCore
{
  public:
    void SetNodeValue(unsigned int a, unsigned int b, unsigned int c);
};

class ISPassHolder
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    ISPassCore* m_30;
};

struct FUN_00b8bdb0_cls
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c(void* a, void* b, const char* c, const char* d, const char* e);
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    ISPassHolder* m_5c;
    void InitScanBlendPass();
};

// Sets up the IFVATSSCANBLEND shader with its vertex/pixel sources and configures three pass core entries on m_5c.
// @fnv 0x00b8bdb0
void FUN_00b8bdb0_cls::InitScanBlendPass()
{
    unsigned int f[0x26];
    f[0x13] = (unsigned int)"imagespace\\1x\\v\\base.v.hlsl";
    f[0x14] = 0;
    FUN_00ec61c0(&f[0x15], 0, 0x44);
    f[0] = (unsigned int)"imagespace\\2x\\p\\scanlines_blend.p.hlsl";
    f[1] = (unsigned int)"BLURSRC1";
    f[2] = 0;
    f[3] = (unsigned int)"VATS";
    f[4] = 0;
    f[5] = 0;
    FUN_00ec61c0(&f[6], 0, 0x34);
    this->v13c((void*)&f[0x13], (void*)&f[0], "IFVATSSCANBLEND", "vs_1_1", "ps_2_0");
    this->v14c();
    ISPassHolder* a = (ISPassHolder*)this->m_5c;
    if (a->m_30 == 0)
        a->m_30 = (ISPassCore*)FUN_00e7f5d0();
    a->m_30->SetNodeValue(0x1b, 1, 1);
    ISPassHolder* b = (ISPassHolder*)this->m_5c;
    if (b->m_30 == 0)
        b->m_30 = (ISPassCore*)FUN_00e7f5d0();
    b->m_30->SetNodeValue(0x13, 5, 1);
    if (b->m_30 == 0)
        b->m_30 = (ISPassCore*)FUN_00e7f5d0();
    b->m_30->SetNodeValue(0x14, 6, 1);
}

struct MemoryManager
{
    void Deallocate(void* p);
};
extern MemoryManager _g_memoryManager;
inline void MemFree(void* p)
{
    _g_memoryManager.Deallocate(p);
}

class CachedEntry : public NiRefObject
{
  public:
    NiPointer<NiRefObject> spObj08;
    int unk0C;
    void* pData10;
    int unk14;
    NiPointer<NiRefObject> spObj18;
    NiPointer<NiRefObject> spObj1C;
    NiPointer<NiRefObject> spObj20;
    NiPointer<NiRefObject> spObj24;
};

struct CachedEntryMapItem
{
    CachedEntryMapItem* m_pkNext;
    const char* m_key;
    NiPointer<CachedEntry> m_val;
};

class CachedEntryMap
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiHashSize;
    CachedEntryMapItem** m_ppkHashTable;
    unsigned int m_uiCount;

    void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }
    unsigned int GetCount() const
    {
        return m_uiCount;
    }
    __declspec(noinline) void GetNext(void*& pos, const char*& key, NiPointer<CachedEntry>& val) const
    {
        CachedEntryMapItem* pItem = (CachedEntryMapItem*)pos;
        key = pItem->m_key;
        val = pItem->m_val;
        pos = pItem->m_pkNext;
    }
    void RemoveAll();
};

CachedEntryMap* __cdecl GetCachedEntryMap();
void __cdecl ClearOtherCachedMap();

// Clears another cached map, then walks the cached entry map releasing each entry's pointers and data, and removes all entries.
// @fnv 0x00b59940
void __cdecl ClearCachedEntryMap()
{
    ClearOtherCachedMap();
    void* pos = GetCachedEntryMap()->GetFirstPos();
    const char* key;
    NiPointer<CachedEntry> spEntry;
    if (GetCachedEntryMap()->GetCount() > 0)
    {
        while (pos)
        {
            GetCachedEntryMap()->GetNext(pos, key, spEntry);
            if (spEntry)
            {
                spEntry->spObj08 = 0;
                MemFree(spEntry->pData10);
                spEntry->pData10 = 0;
                spEntry->spObj18 = 0;
                spEntry->spObj20 = 0;
                spEntry->spObj1C = 0;
                spEntry->spObj24 = 0;
            }
        }
        GetCachedEntryMap()->RemoveAll();
    }
}

template <> class NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> > : public NiMemObject
{
  public:
    virtual ~NiTArray();
    ImageSpaceEffectParam** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetAt(unsigned int uiIndex, ImageSpaceEffectParam* const& element);
};
typedef NiTArray<ImageSpaceEffectParam*, NiTMallocInterface<ImageSpaceEffectParam*> > ParamArray_b8b;

struct ImageSpaceManager_b8b
{
    int unk;
    NiTPrimitiveArray_ImageSpaceEffect___ m_kEffects;
    void ShutdownAllEffects();
};

// Shuts down and destroys each effect in m_kEffects, clears the array entries, and resets its size counters to zero.
// @fnv 0x00b8b2e0
void ImageSpaceManager_b8b::ShutdownAllEffects()
{
    for (int i = 0; i < ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_COUNT; i++)
    {
        ImageSpaceEffect* pkEffect = m_kEffects.m_pBase[i];
        if (pkEffect)
        {
            pkEffect->Shutdown();
            pkEffect->Destroy(true);
            ImageSpaceEffectParam* pkNull = 0;
            ((ParamArray_b8b*)&m_kEffects)->SetAt(i, pkNull);
        }
    }
    for (unsigned short j = 0; j < m_kEffects.m_usSize; j++)
        m_kEffects.m_pBase[j] = 0;
    m_kEffects.m_usSize = 0;
    m_kEffects.m_usESize = 0;
}

extern __declspec(thread) unsigned int g_uiTlsAllocState;

struct TlsAllocStateGuard
{
    unsigned int uiSaved;
    TlsAllocStateGuard(unsigned int uiState)
    {
        uiSaved = g_uiTlsAllocState;
        g_uiTlsAllocState = uiState;
    }
    ~TlsAllocStateGuard()
    {
        g_uiTlsAllocState = uiSaved;
    }
};

struct ImageSpaceManagerHelper : public ImageSpaceManager
{
    void InitShaders();
    void InitTextures();
    void InitParams();
    void FUN_00b977d0();
};

struct ImageSpaceShaderParamGlobal
{
    void Init(int, int);
};
extern ImageSpaceShaderParamGlobal g_01202410;

struct BSTextureManagerStub
{
    BSRenderedTexture* CreateRenderedTexture(int, int, int, int, int);
};
extern BSTextureManagerStub* DAT_011f91a8;
extern int DAT_011f4748;

// Initializes shaders, textures, effects, params and a rendered texture once, guarded by a TLS alloc-state guard and a one-time flag.
// @fnv 0x00b977d0
void ImageSpaceManagerHelper::FUN_00b977d0()
{
    TlsAllocStateGuard kGuard(0x27);
    if (!m_bEndOfFrameEffectsEnabled)
    {
        InitShaders();
        InitTextures();
        m_bEndOfFrameEffectsEnabled = true;
        SetupEffects();
        g_01202410.Init(0, 0);
        InitParams();
        RgbaColor kTint;
        kTint.b = kTint.g = kTint.r = 0.0f;
        kTint.a = 0.3f;
        m_kMenuBackgroundTint = kTint;
        m_kMenuBackgroundRect.m_fMinimumU = 0.0f;
        m_kMenuBackgroundRect.m_fMaximumU = 1.0f;
        m_kMenuBackgroundRect.m_fMinimumV = 1.0f;
        m_kMenuBackgroundRect.m_fMaximumV = 0.0f;
        m_pCurrentRenderedTexture = 0;
        m_pMenuBackgroundTexture = DAT_011f91a8->CreateRenderedTexture(DAT_011f4748, 3, 0, 0, 0);
    }
}

// 0x00b8bda0  mov al,[ecx+4]; ret
struct C00b8bda0
{
    char pad00[0x4];
    unsigned char m4;
    unsigned char FUN_00b8bda0();
};

// @fnv 0x00b8bda0
unsigned char C00b8bda0::FUN_00b8bda0()
{
    return m4;
}

extern __declspec(thread) int g_tlsMemContext;

struct ScopedMemoryContext
{
    int iOldContext;
    ScopedMemoryContext(int aiContext)
    {
        iOldContext = g_tlsMemContext;
        g_tlsMemContext = aiContext;
    }
    ~ScopedMemoryContext()
    {
        g_tlsMemContext = iOldContext;
    }
};

__declspec(noinline) void ImageSpaceManager::FUN_00b8b540(RgbaColor& color)
{
    m_fPartialRenderBlend = color.a;
}

__declspec(noinline) void ImageSpaceManager::FUN_00b8b610(RgbaColor& color)
{
    m_fFadeColorAlpha = color.a;
}

class DerivedImageSpaceManager : public ImageSpaceManager
{
  public:
    void FUN_00b8ccb0();
};

// Blends weather values into image-space settings and raises blur, radial blur, depth-of-field and motion-blur strengths to their maxima.
// @fnv 0x00b8ccb0
void DerivedImageSpaceManager::FUN_00b8ccb0()
{
    for (int i = 0; i < 15; i++)
    {
        float afWeatherValues[2];
        afWeatherValues[0] = m_kModifierParameterData[0].m_afFirstParameterSet[i];
        afWeatherValues[1] = m_kModifierParameterData[1].m_afFirstParameterSet[i];
        ScopedMemoryContext ctx(0x27);
        float val = m_kBlendedParameterData.m_afFirstParameterSet[i];
        for (int j = 0; j < 2; j++)
        {
            float elem = afWeatherValues[j];
            float result = 0.0f;
            switch (j)
            {
            case 0:
                result = elem * val;
                break;
            case 1:
                result = elem + val;
                break;
            }
            val = result;
        }
        float diff = m_kBlendedParameterData.m_afFirstParameterSet[i] - val;
        m_kBlendedParameterData.m_afFirstParameterSet[i] -= diff;
    }

    for (int i = 0; i < 3; i++)
    {
        float afWeatherValues[2];
        afWeatherValues[0] = m_kModifierParameterData[0].m_afSecondParameterSet[i];
        afWeatherValues[1] = m_kModifierParameterData[1].m_afSecondParameterSet[i];
        ScopedMemoryContext ctx(0x27);
        float val = m_kBlendedParameterData.m_afSecondParameterSet[i];
        for (int j = 0; j < 2; j++)
        {
            float elem = afWeatherValues[j];
            float result = 0.0f;
            switch (j)
            {
            case 0:
                result = elem * val;
                break;
            case 1:
                result = elem + val;
                break;
            }
            val = result;
        }
        float diff = m_kBlendedParameterData.m_afSecondParameterSet[i] - val;
        m_kBlendedParameterData.m_afSecondParameterSet[i] -= diff;
    }

    for (int i = 0; i < 12; i++)
    {
        float afWeatherValues[2];
        afWeatherValues[0] = m_kModifierParameterData[0].m_afColorAndAlphaParameters[i];
        afWeatherValues[1] = m_kModifierParameterData[1].m_afColorAndAlphaParameters[i];
        ScopedMemoryContext ctx(0x27);
        float val = m_kBlendedParameterData.m_afColorAndAlphaParameters[i];
        for (int j = 0; j < 2; j++)
        {
            float elem = afWeatherValues[j];
            float result = 0.0f;
            switch (j)
            {
            case 0:
                result = elem * val;
                break;
            case 1:
                result = elem + val;
                break;
            }
            val = result;
        }
        float diff = m_kBlendedParameterData.m_afColorAndAlphaParameters[i] - val;
        m_kBlendedParameterData.m_afColorAndAlphaParameters[i] -= diff;
    }

    FUN_00b8b540(m_kPartialRenderColor);
    FUN_00b8b610(m_kWeatherFadeColor);

    float fBlurStrength = m_fWeatherBlurRadius;
    if (fBlurStrength > m_fDoubleVisionStrength)
    {
        m_fDoubleVisionStrength = fBlurStrength;
    }

    float fWeatherDouble = m_fAdditionalImageSpaceValue;
    if (fWeatherDouble > m_fWeatherDoubleVisionStrength)
    {
        m_fWeatherDoubleVisionStrength = fWeatherDouble;
    }

    float fWeatherRadialBlurStrength = m_fWeatherRadialBlurStrength;
    if (fWeatherRadialBlurStrength > m_fRadialBlurStrength)
    {
        m_fRadialBlurStrength = fWeatherRadialBlurStrength;
        m_fRadialBlurRampUp = m_fWeatherRadialBlurRampUp;
        m_fRadialBlurStart = m_fWeatherRadialBlurStart;
        m_fRadialBlurRampDown = m_fWeatherRadialBlurRampDown;
        m_fRadialBlurDownStart = m_fWeatherRadialBlurDownStart;
        m_kRadialBlurCenter = m_kWeatherRadialBlurCenter;
    }

    float fDOFStrength = m_fDepthOfFieldEffectStrength;
    float fDOFDistance = m_fDepthOfFieldEffectDistance;
    float fDOFRange = m_fDepthOfFieldEffectRange;
    unsigned int dofMode = m_eDepthOfFieldTargetMode;

    if (fDOFStrength > m_fDepthOfFieldStrength)
    {
        m_fDepthOfFieldStrength = fDOFStrength;
        m_bDepthOfFieldUsesObject = false;
        if (dofMode > 2)
        {
            m_bDepthOfFieldUsesObject = true;
            dofMode -= 3;
        }
        m_eDepthOfFieldMode = (ImageSpaceEffectDepthOfField__DepthOfFieldMode)dofMode;
        m_fDepthOfFieldMaskConstant = fDOFDistance;
        m_fDepthOfFieldDistance = fDOFRange;
        m_fDepthOfFieldRange = 0.0f;
    }

    float fMotionBlurStrength = m_fMenuBackgroundBlendTarget;
    if (fMotionBlurStrength > m_fMenuBackgroundBlendValue)
    {
        m_fMenuBackgroundBlendValue = fMotionBlurStrength;
    }
}

extern float DAT_01202400;
extern float DAT_012003d0;

struct ImageSpaceModifierRampState
{
    void* vtable;
    bool unk04;
    bool bActive;
    bool unk06;
    bool unk07;
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
    float fWaterLevelItem;
    float m_fRampUp;
    float fStart;
    float fRampDown;
    float m_fRampDownStart;
    NiPoint2 m_kCenter;

    void SetParams(float strength, float rampup, float start, float rampDown, float downStart, const NiPoint2& center)
    {
        fWaterLevelItem = strength;
        m_fRampUp = rampup;
        fStart = start;
        fRampDown = rampDown;
        m_fRampDownStart = downStart;
        m_kCenter = center;
    }
};

struct ImageSpaceEffectDepthOfFieldParams
{
    void* vtable;
    bool unk04;
    bool bActive;
    bool unk06;
    bool unk07;
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
    float fDistance;
    float fImpulseRadiusSquared;
    float fWaterLevelItem;
    ImageSpaceEffectDepthOfField__DepthOfFieldMode eMode;
    float m_fMaskConstant;

    void SetStrength(float strength)
    {
        bActive = true;
        fWaterLevelItem = strength;
    }
    void SetDistance(float distance)
    {
        bActive = true;
        fDistance = distance;
    }
    void SetRange(float range)
    {
        fImpulseRadiusSquared = range;
        bActive = true;
    }
    void SetMode(ImageSpaceEffectDepthOfField__DepthOfFieldMode mode)
    {
        if (mode != eMode)
        {
            bActive = true;
            eMode = mode;
        }
    }
    void FUN_00b8bc80();
    void FUN_00b8bc20();
};

struct ImageSpaceEffectDepthRadialBlurParams
{
    void* vtable;
    bool unk04;
    bool bActive;
    bool unk06;
    bool unk07;
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
    float fWaterLevelItem;
    int unk70;
    int unk74;
    int unk78;
    float fNear;
    float fFar;
    float fDistance;
    int unk88;
    float fStrength2;
    float m_fRampUp;
    float fStart;
    int unk98;
    float fImpulseRadiusSquared;

    void SetStrength(float strength)
    {
        bActive = true;
        fWaterLevelItem = strength;
    }
    void SetDistance(float dist)
    {
        float r = fImpulseRadiusSquared;
        if (fImpulseRadiusSquared < dist)
        {
            r = dist;
        }
        fDistance = dist;
        bActive = true;
        fNear = dist - r;
        fFar = dist + r;
    }
    void SetRange(float range)
    {
        bActive = true;
        fImpulseRadiusSquared = range;
        fNear = fDistance - range;
        fFar = fDistance + range;
    }
    void SetParams(float strength, float rampup, float start)
    {
        fStrength2 = strength;
        m_fRampUp = rampup;
        fStart = start;
    }
    void FUN_00b8b210(ImageSpaceEffectDepthRadialBlur__RadialBlurMode mode);
};

struct ImageSpaceModifierStrengthState
{
    void* vtable;
    bool unk04;
    bool bActive;
    bool unk06;
    bool unk07;
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
    float fWaterLevelItem;

    void SetStrength(float strength)
    {
        bActive = true;
        fWaterLevelItem = strength;
    }
};

class FUN_00b8d020_class : public ImageSpaceManager
{
  public:
    void FUN_00b8d020();
};

// @fnv 0x00b8d020
void FUN_00b8d020_class::FUN_00b8d020()
{
    if (m_kModifierColor.a > 0.0f)
    {
        float a = m_kModifierColor.a;
        m_kModifierColor.r /= a;
        m_kModifierColor.g /= a;
        m_kModifierColor.b /= a;
        m_kModifierColor.a /= a;
    }
    float tint = m_fPartialRenderBlend;
    m_kModifierColor.a = tint;
    m_kBlendedParameterData.m_afColorAndAlphaParameters[4] = m_kModifierColor.r;
    m_kBlendedParameterData.m_afColorAndAlphaParameters[5] = m_kModifierColor.g;
    m_kBlendedParameterData.m_afColorAndAlphaParameters[6] = m_kModifierColor.b;
    m_kBlendedParameterData.m_afColorAndAlphaParameters[7] = tint;

    if (m_kAccumulatedColor.a > 0.0f)
    {
        float a = m_kAccumulatedColor.a;
        m_kAccumulatedColor.r /= a;
        m_kAccumulatedColor.g /= a;
        m_kAccumulatedColor.b /= a;
        m_kAccumulatedColor.a /= a;
    }
    float fade = m_fFadeColorAlpha;
    m_kAccumulatedColor.a = fade;
    m_kBlendedParameterData.m_afColorAndAlphaParameters[8] = m_kAccumulatedColor.r;
    m_kBlendedParameterData.m_afColorAndAlphaParameters[9] = m_kAccumulatedColor.g;
    m_kBlendedParameterData.m_afColorAndAlphaParameters[10] = m_kAccumulatedColor.b;
    m_kBlendedParameterData.m_afColorAndAlphaParameters[11] = fade;

    DAT_01202400 = m_fWeatherDoubleVisionStrength;
    DAT_012003d0 = m_fDoubleVisionStrength;

    ImageSpaceModifierRampState* pRadialBlur =
        (ImageSpaceModifierRampState*)pEffectList.m_pBase[ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_RADIAL_BLUR];
    pRadialBlur->SetParams(m_fRadialBlurStrength, m_fRadialBlurRampUp, m_fRadialBlurStart, m_fRadialBlurRampDown,
                           m_fRadialBlurDownStart, m_kRadialBlurCenter);

    ImageSpaceEffectDepthOfFieldParams* pDOF =
        (ImageSpaceEffectDepthOfFieldParams*)
            pEffectList.m_pBase[ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_DEPTH_OF_FIELD];
    pDOF->SetStrength(m_fDepthOfFieldStrength);
    pDOF->SetDistance(m_fDepthOfFieldMaskConstant);
    pDOF->SetRange(m_fDepthOfFieldDistance);
    pDOF->m_fMaskConstant = m_fDepthOfFieldRange;
    pDOF->SetMode(m_eDepthOfFieldMode);
    if (m_bDepthOfFieldUsesObject)
    {
        pDOF->FUN_00b8bc80();
    }
    else
    {
        pDOF->FUN_00b8bc20();
    }

    ImageSpaceEffectDepthRadialBlurParams* pDepthRadialBlur =
        (ImageSpaceEffectDepthRadialBlurParams*)
            pEffectList.m_pBase[ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_DEPTH_RADIAL_BLUR];
    pDepthRadialBlur->SetStrength(m_fBlurRadius);
    pDepthRadialBlur->SetDistance(m_fRadialBlurDistance);
    pDepthRadialBlur->SetRange(m_fRadialBlurRange);
    pDepthRadialBlur->FUN_00b8b210(m_eRadialBlurMode);
    pDepthRadialBlur->SetParams(m_fBlurRadius, m_fRadialBlurTransition, m_fRadialBlurStartValue);

    ImageSpaceModifierStrengthState* pMotionBlur =
        (ImageSpaceModifierStrengthState*)
            pEffectList.m_pBase[ImageSpaceManager__ImageSpaceEffectEnum_EFFECT_MOTION_BLUR];
    pMotionBlur->SetStrength(m_fMenuBackgroundBlendValue);
}

#include <math.h>
extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl fabs(double);

extern "C" void* __cdecl memmove(void*, const void*, unsigned);

struct Vec2
{
    float x, y;
    Vec2(float a, float b) : x(a), y(b)
    {}
    Vec2 operator-(const Vec2& b) const
    {
        return Vec2(x - b.x, y - b.y);
    }
    Vec2& operator-=(const Vec2& b)
    {
        x -= b.x;
        y -= b.y;
        return *this;
    }
    float Length() const
    {
        return sqrt(x * x + y * y);
    }
};
struct Vec3
{
    float x, y, z;
};
struct Vec4
{
    float x, y, z, r;
};
struct Matrix
{
    float m[4][4];
};
struct Viewport
{
    float left, right, top, bottom;
};
struct Camera
{
    int unk00;
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
    Matrix unk9C;
    int unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    Viewport unk100;
};
extern Camera* DAT_011f9684;
// Transforms a 3D position with the camera matrix, maps it through the viewport, and computes a capped radius from the input r offset.
// @fnv 0x00b59d30
NiPoint2* FUN_00b59d30(Vec4* apPoint, NiPoint2* apScreenPos, float* radius)
{
    Camera* camera = DAT_011f9684;
    Vec3 position = *(Vec3*)apPoint;
    Viewport vViewport = camera->unk100;
    bool bBehindCamera = false;
    Matrix matrix;
    memmove(&matrix, &camera->unk9C, sizeof(matrix));
    float w = position.x * matrix.m[3][0] + position.y * matrix.m[3][1] + position.z * matrix.m[3][2] + matrix.m[3][3];
    if (w < 0.0f)
        bBehindCamera = true;
    w = fabs(w);
    float fInvW = 1.0f / w;
    float x = position.x * matrix.m[0][0] + position.y * matrix.m[0][1] + position.z * matrix.m[0][2] + matrix.m[0][3];
    x *= fInvW;
    float y = position.x * matrix.m[1][0] + position.y * matrix.m[1][1] + position.z * matrix.m[1][2] + matrix.m[1][3];
    y *= fInvW;
    if ((x >= -1.0f && x <= 1.0f && y >= -1.0f && y <= 1.0f) || !bBehindCamera)
    {
        position.z += apPoint->r;
        float newW =
            position.x * matrix.m[3][0] + position.y * matrix.m[3][1] + position.z * matrix.m[3][2] + matrix.m[3][3];
        Vec2 vInitial(x, 1.0f - y);
        float nextX =
            position.x * matrix.m[0][0] + position.y * matrix.m[0][1] + position.z * matrix.m[0][2] + matrix.m[0][3];
        nextX /= newW;
        float nextY =
            position.x * matrix.m[1][0] + position.y * matrix.m[1][1] + position.z * matrix.m[1][2] + matrix.m[1][3];
        nextY /= newW;
        Vec2 vNext(nextX, 1.0f - nextY);
        Vec2 vDifference = vInitial;
        vDifference -= vNext;
        float size = vDifference.Length();
        size = size * 0.5;
        *radius = size;
        if (*radius > 0.5f)
            *radius = 0.5f;
    }
    else
    {
        *radius = 0.3f;
    }
    position.x = (vViewport.right - vViewport.left) * 0.5 * x;
    NiPoint2 result;
    result.x = position.x + (vViewport.right + vViewport.left) * 0.5;
    position.x = (vViewport.top - vViewport.bottom) * 0.5 * y;
    result.y = position.x + (vViewport.top + vViewport.bottom) * 0.5;
    result.y = 1.0f - result.y;
    if (result.x > 1.0f)
        result.x = 1.0f;
    else if (result.x < 0.0f)
        result.x = 0.0f;
    if (result.y > 1.0f)
        result.y = 1.0f;
    else if (result.y < 0.0f)
        result.y = 0.0f;
    if (bBehindCamera)
    {
        if (result.x <= 0.0f)
            result.x = 0.0f;
        else if (result.x > 0.0f)
            result.x = 1.0f;
    }
    *apScreenPos = result;
    return apScreenPos;
}

void __cdecl FUN_00b59d30(int a1, int* a2, float* a3);
class FUN_00b8b760_cls
{
  public:
    int unk00;
    void FUN_00b8b000(float a1, float a2, float a3, float a4, float a5, int* out);
    void FUN_00b8b760(float a1, float a2, float a3, float a4, float a5, int a6);
};
// Calls FUN_00b59d30 with a6 and local, then passes a3 and a5 adjusted by a6's float bits to FUN_00b8b000.
// @fnv 0x00b8b760
void FUN_00b8b760_cls::FUN_00b8b760(float a1, float a2, float a3, float a4, float a5, int a6)
{
    int local[2];
    FUN_00b59d30(a6, local, &a5 + 1);
    FUN_00b8b000(a1, a2, *(float*)&a6 + a3, a4, *(float*)&a6 + a5, local);
}

namespace fnv_00b8b8d0 {
struct Point3
{
    float x, y, z;
    float Length() const
    {
        return sqrtf(x * x + y * y + z * z);
    }
};
extern char* DAT_011f917c;
struct ImageSpaceDistanceEffect
{
    void FUN_00b8b0d0(float strength, int mode, float duration, float nearDistance, float farDistance);
    void SetDistanceEffect(float strength, int mode, float duration, const Point3* position);
};
// Computes the distance from the position at DAT_011f917c + 0x8c and passes it as both bounds to FUN_00b8b0d0.
// @fnv 0x00b8b8d0
void ImageSpaceDistanceEffect::SetDistanceEffect(float strength, int mode, float duration, const Point3* position)
{
    const Point3 worldPosition = *reinterpret_cast<const Point3*>(DAT_011f917c + 0x8c);
    const volatile Point3 sample = *position;
    const Point3 delta = {sample.x - worldPosition.x, sample.y - worldPosition.y, sample.z - worldPosition.z};
    const float distance = delta.Length();
    FUN_00b8b0d0(strength, mode, duration, distance, distance);
}
}  // namespace fnv_00b8b8d0

namespace fnv_00b8bb70 {
class NiPoint3
{
  public:
    float x, y, z;
    __forceinline NiPoint3 operator-(const NiPoint3& o) const
    {
        NiPoint3 r;
        r.x = x - o.x;
        r.y = y - o.y;
        r.z = z - o.z;
        return r;
    }
};

class NiCamera
{
  public:
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    NiPoint3 pos;
};

extern NiCamera* DAT_011f917c;
static __forceinline float Dot(NiPoint3 a, NiPoint3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Computes the distance between the camera position and a given point, storing the result in both elements of the output array.
// @fnv 0x00b8bb70
void __stdcall FUN_00b8bb70(NiPoint3* apPoint, float* out)
{
    NiPoint3 g = DAT_011f917c->pos;
    NiPoint3 pPoint = *apPoint;
    NiPoint3 d = pPoint - g;
    float l = sqrtf(Dot(d, d));
    out[0] = l;
    out[1] = l;
}
}  // namespace fnv_00b8bb70

extern __declspec(thread) int BSAudioThreadContext;

class FUN_00b8cb30_cls
{
  public:
    void FUN_00b8cb30(int mode, int idx, float* arr, float w);
};

// Sets BSAudioThreadContext to 0x27, selects a float by mode, applies two operations from arr and blends toward the result using w, then restores the context.
// @fnv 0x00b8cb30
void FUN_00b8cb30_cls::FUN_00b8cb30(int mode, int aiIndex, float* apValues, float afWeight)
{
    int iSavedContext = BSAudioThreadContext;
    BSAudioThreadContext = 0x27;

    float* p = 0;
    switch (mode)
    {
    case 0:
        p = (float*)((char*)this + aiIndex * 4 + 0x50);
        break;
    case 1:
        p = (float*)((char*)this + aiIndex * 4 + 0x14);
        break;
    case 3:
        p = (float*)((char*)this + aiIndex * 4 + 0x78);
        break;
    }

    float fValue = *p;
    float fAccum = 0.0f;
    float t = fAccum;
    for (int i = 0; i < 2; i++)
    {
        float a = apValues[i];
        t = fAccum;
        switch (i)
        {
        case 0:
            t = a * fValue;
            break;
        case 1:
            t = a + fValue;
            break;
        }
        fValue = t;
    }

    *p = *p - (float)(*p - t) * afWeight;

    BSAudioThreadContext = iSavedContext;
}

// Adjustor thunk for FUN_00b8bd80: "sub ecx, 0x6c; jmp FUN_00b8bd50".
//
// MSVC emits a this-adjusting thunk for a virtual that a class inherits from a
// secondary base: the thunk receives the secondary base sub-object pointer
// (this + 0x6c), moves it back to the derived object (sub ecx, 0x6c) and
// tail jumps to the final overrider.
//
// The subtracted constant is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 26 int members (4 + 26 * 4 = 0x6c).
// Both bases declare the same virtual function, the derived class redeclares
// it and only defines its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_00b8bd80();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8bd80();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8bd80
    virtual void FUN_00b8bd80();
};

Derived::Derived()
{}

namespace fnv_00b8bfd0 {
// Adjustor thunk: sub ecx,0x6c; jmp <base implementation>
// PrimaryBase = vptr + 26 int fields = 4 + 104 = 0x6c bytes.
struct PrimaryBase
{
    virtual void FUN_00b8bfd0();
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
};

struct SecondaryBase
{
    virtual void FUN_00b8bfd0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00b8bfd0
    virtual void FUN_00b8bfd0();
};

Derived::Derived()
{}
}  // namespace fnv_00b8bfd0

void* __cdecl FUN_00aa13e0(unsigned int size);
inline void* __cdecl operator new(unsigned int size)
{
    return FUN_00aa13e0(size);
}
void __cdecl operator delete(void*);
struct TLSData
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int currentHeap;
};

extern __declspec(thread) TLSData g_tlsData;

class AutoMemContext
{
  public:
    int m_iOldTag;

    AutoMemContext(int newTag)
    {
        m_iOldTag = g_tlsData.currentHeap;
        g_tlsData.currentHeap = newTag;
    }

    ~AutoMemContext()
    {
        g_tlsData.currentHeap = m_iOldTag;
    }
};

class PartialScreenGeometryReceiver : public ImageSpaceManager
{
  public:
    void FUN_00b8c3b0(float a1, float a2, NiPointer<NiScreenElements>& a3);
};

// Creates NiScreenElements, sets rectangle bounds and data using a1 and a2, then assigns the elements to a3.
// @fnv 0x00b8c3b0
void PartialScreenGeometryReceiver::FUN_00b8c3b0(float afWidth, float afHeight,
                                                 NiPointer<NiScreenElements>& apScreenElements)
{
    AutoMemContext memContext(0x27);
    NiPointer<NiScreenElementsData> spScreenData(new NiScreenElementsData(false, false, 1, 1, 1, 4, 1, 2, 1));
    this->m_pMenuBackgroundScreenElements = ::new NiScreenElements(spScreenData);
    float width = afWidth * 2.0f;
    float height = afHeight * -2.0;
    this->m_pMenuBackgroundScreenElements->GetData()->FUN_00a87ae0(4, 0, 0);
    this->m_pMenuBackgroundScreenElements->GetData()->SetRectangleBounds(0, DAT_01012054, 1.0f, width, height);
    this->m_pMenuBackgroundScreenElements->GetData()->FUN_00a87900();
    this->m_pMenuBackgroundScreenElements->GetData()->FUN_00a88130(0, 0, 0.0f, 0.0f, afWidth, afHeight);
    this->m_pMenuBackgroundScreenElements->UpdateSceneObject();
    NiUpdateData updateData = {0.0f, false, false, false, false, false};
    this->m_pMenuBackgroundScreenElements->Update(updateData);
    this->m_pMenuBackgroundScreenElements->SetName(GeometryString("Interface Effect Partial Screen Trishape"));
    apScreenElements = this->m_pMenuBackgroundScreenElements;
}
