// fallout_shared/bgsdecalmanager_decls.h: declares RgbaColor, ProcessLists, NiRenderer, DecalVtableCall
#ifndef BGSDECALMANAGER_DECLS_H
#define BGSDECALMANAGER_DECLS_H

#include "layout_support.h"
#ifndef FNV_FORCEINLINE
#define FNV_FORCEINLINE inline
#endif

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class TESObjectCELL;
class BSTempEffectSimpleDecal;
class BSFaceGenAnimationData;
class NiProperty;
class NiTexture;
class ParentSpaceNode;
class RgbaColor;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
};
class ImageSpaceEffectParam
{
  public:
    float r;
    float g;
    float b;
    float a;
    ImageSpaceEffectParam(float, float, float, float);
};
class RgbaColor
{
  public:
    float r;
    float g;
    float b;
    float a;
};

template <> class NiPointer<BSFaceGenAnimationData>
{
  public:
    BSFaceGenAnimationData* m_pObject;
    operator BSFaceGenAnimationData*() const;
};
template <> class NiPointer<NiTexture>
{
  public:
    NiTexture* m_pObject;
    ~NiPointer();
};

template <class T, unsigned int N> class BSSimpleArray
{
  public:
    unsigned int GetSize();
};
template <class T> class NiTPointerAllocator
{
};
template <class Allocator, class T> class NiTPointerListBase
{
  public:
    T& GetNext(void*&);
    NiPointer<NiTexture> RemovePos(void*&);
};

class TESTopic;
template <> class BSSimpleList<TESTopic*>
{
  public:
    const char* FUN_0043b1b0();
};
class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*>* GetLinkToList();
};
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};
extern ProcessLists DAT_011c5904;
extern int DAT_011c57ec;
extern unsigned int DAT_011c57f4;
extern "C" const char DAT_0101e1c8[];
extern "C" const char DAT_0101e19c[];
extern "C" const char DAT_0101e174[];

class NiRenderer
{
  public:
    void StartScene();
    void FinishScene();
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
NiRenderer* FUN_0043c4b0();
int __cdecl Warning(const char*, ...);

class DecalVtableCall
{
  public:
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
};

#endif
