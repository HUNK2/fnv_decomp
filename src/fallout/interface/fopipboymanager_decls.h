// Private PC declarations for this unit. Offsets and call signatures follow the PC disassembly.
#ifndef FOPIPBOYMANAGER_DECLS_H
#define FOPIPBOYMANAGER_DECLS_H

#include <stddef.h>
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
};
struct NiRTTI
{
    const char* name;
    const NiRTTI* base;
};
class ThreeByThreeMatrix
{
  public:
    float m[3][3];
    ThreeByThreeMatrix();
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix&) const;
};
class NiUpdateData
{
  public:
    float time;
    bool updateControllers;
    bool isMultiThreaded;
    bool updateGeomorphs;
    bool updateBounds;
    bool updateTransforms;
    NiUpdateData(float, bool, bool);
};
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3(float, float, float);
};
class NiDirectionalLight
{
  public:
    void FUN_004bc280(const NiPoint3&);
};
class PathingGraphNode
{
  public:
    void FUN_006b0570(const NiPoint3&);
};
class NiPointLight : public NiDirectionalLight
{
  public:
    void SetEffectColor(const NiPoint3&);
    void FUN_0050c630(float);
    void FUN_0050c660(float);
    void FUN_0050c690(float);
    void FUN_0050dd20(float);
    void FUN_0050dd50(const NiPoint3&);
};
class BGSBodyPart
{
  public:
    const char* GetPartName();
};
class NiNode;
class NiProperty
{
  public:
    void FUN_0068c9f0(float);
};
class BSShaderProperty : public NiProperty
{
  public:
    void SetAlpha(float);
};
class NiGeometry;
unsigned int FUN_004af350();
unsigned int FUN_00438220();
class NiAVObject
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual NiNode* IsSceneNode();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual NiGeometry* IsGeometry();
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
    virtual NiAVObject* GetObjectByName(const NiFixedString&);
    NiNode* GetParent();
    void Update(const NiUpdateData&);
    void UpdateSceneObject();
    void FUN_00450f90(bool);
    NiProperty* GetProperty(unsigned int);
    const ThreeByThreeMatrix& GetRotate() const;
    void SetLocalRotation(const ThreeByThreeMatrix&);
    void SetLocalRotation(float, float, float, float);
};
class NiGeometry : public NiAVObject
{
};
class NiNode : public NiAVObject
{
  public:
    NiAVObject* FUN_0045bc00(unsigned int);
    NiAVObject* GetAt(unsigned int);
    unsigned int FUN_00453470();
};
NiAVObject* NiDynamicCast(const NiRTTI*, NiAVObject*);
extern NiRTTI DAT_011f4428;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
};
class ActorValueOwner
{
  public:
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
};
union SETTING_VALUE
{
    float f;
    bool b;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT_GameSettingCollection_ DAT_011db33c, DAT_011db34c;
class StatsMenu
{
  public:
    static float GetChartScale();
};
class PlayerCharacter
{
  public:
    unsigned char prefix[0xa4];
    ActorValueOwner actorValues;
    NiNode* GetNode(bool);
};
extern PlayerCharacter* g_thePlayer;
class RgbaColor
{
  public:
    float r, g, b, a;
    RgbaColor(float, float, float, float);
};
class INISettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
extern SettingT<INISettingCollection> DAT_011db2cc;
extern SettingT_GameSettingCollection_ DAT_011db2dc, DAT_011db328, DAT_011db274;
extern NiRTTI DAT_011f4acc;
class FOPipboyManager;
class Interface
{
  public:
    unsigned char interfaceState[0x174];
    FOPipboyManager* pPipboyManager;
    FOPipboyManager* GetPipboyManager();
    static Interface* FUN_004b7210();
    NiNode* GetRoot();
};
class SystemColorManager
{
  public:
    static SystemColorManager* GetSingleton();
    bool GetColor(unsigned int, RgbaColor&);
};
class FORenderedMenu
{
  public:
    unsigned char beforeScreen[4];
    NiPointer<NiAVObject> screen;
    char beforeFlicker_pad8[4];
    char m_pScreenGeometry[4];
    char m_pDefaultTexture[4];
    char m_pRenderedMenuObject[4];
    void* m_pFourthMenuObject;
    char m_pMenuLight[4];
    void* m_pSecondaryMenuObject;
    char m_pMenuLightParameters[4];
    bool bInitialized;
    bool m_bUseMenuImageSpaceEffects;
    bool m_bEnableFlicker;
    char beforeFlicker_pad2b[1];
    char m_kScreenLightColor[12];
    float fScreenLightBaseIntensity;
    float flicker, blurRadius, blurIntensity, scanlineScale;
    bool doScanlines;
    char renderedTail_pad4d[3];
    float m_fBurstElapsedTime;
    float fBurstDuration;
    float m_fBurstIntensity;
    float m_fBurstSoundChance;
    bool m_bBurstSoundPlayed;
    char renderedTail_pad61[3];
    float m_fShudderIntensity;
    float m_fShudderDuration;
    float m_fShudderFrequency;
    float m_fVerticalHoldDuration;
    bool m_bVerticalHoldActive;
    char renderedTail_pad75[3];
    float m_fVerticalHoldSpeed;
    float m_fVerticalHoldRate;
    float m_fVerticalHoldChance;
    float m_fShudderChance;
    float m_fPulseRadiusIntensity;
    float m_fPulseBrightenIntensity;
    float m_fPulseRate;
    bool m_bPulseActive;
    bool m_bShudderActive;
    char renderedTail_pad96[2];
    float m_fDistortHorizontalScale;
    float m_fDistortVerticalScale;
    float fDistortDuration;
    float m_fDistortTimeRemaining;
    char BackgroundColor[16];
    bool m_bMenuLightEnabled;
    bool m_bMenuLightCreated;
    char renderedTail_padba[2];
    char m_pMenuLightShadowNode[4];
    char m_kMenuLightColor[16];
    bool m_bMenuLightVisible;
    bool m_bMenuLightShadowed;
    bool m_bMenuLightAttached;
    char renderedTail_padd3[1];
    char m_pMenuLightNode[4];
    bool CreateMenuLight(const char*, class ShadowSceneNode*);
    void OnMenuOpen();
};
class FOPipboyManager : public FORenderedMenu
{
  public:
    NiPointer<NiNode> m_pPipBoyObject0;
    NiPointer<NiNode> m_pPipBoyObject1;
    NiPointer<NiAVObject> m_pPipBoyObject2;
    void* m_pScreenGeometry;
    NiPointer<NiAVObject> m_cPipBoyButtonAvailability[3];
    NiPointer<NiAVObject> m_pButtonGlowObjects[3];
    NiPointer<NiAVObject> m_pGaugeObjects[3];
    float m_fChartFirstPoint[3];
    float m_fChartSecondPoint[3];
    float m_fGaugeValues2[3];
    float m_fTabKnobPositions[5];
    bool m_bUseMenuImageSpaceEffects;
    float m_fPipBoyAlpha;
    float m_fPipBoyTargetAlpha;
    bool m_bPipBoyFadeActive;
    unsigned int backgroundHum[3];
    bool b1stPersonLightOn;
    bool b3rdPersonLightOn;
    void OnMenuOpen();
    bool IsUnk28Set();
    void FUN_00705fc0(NiNode*);
    void FUN_004dc540(NiNode*);
    void FUN_007fc2d0(NiAVObject*);
    void SetScreen(NiAVObject*);
    void InitializeMenuLight();
    void SetScreenLightFlickerIntensity(float);
    void SetIntensity(float);
    void SetQuad(const RgbaColor&);
    void FUN_007f7fb0(const RgbaColor&);
    void SetBlurIntensity(float);
    void FUN_00444020(float);
    void SetScanlines(bool, float);
    void FUN_00810530(bool);
    void SetPipBoyObjectVisibility(bool, bool, bool);
    void UpdateScrollKnob();
    void UpdatePipBoyButton();
    void SetDataGlowEnabled(bool);
    float m_fFirstPersonLightIntensity;
    float m_fThirdPersonLightIntensity;
    bool m_bPipBoyLightEnabled;
    char _pdbpad_16d[3];
};
typedef char FOPipboyManagerButtonsOffset[(offsetof(FOPipboyManager, m_cPipBoyButtonAvailability) == 0xe8) ? 1 : -1];
typedef char FOPipboyManagerKnobsOffset[(offsetof(FOPipboyManager, m_pGaugeObjects) == 0x100) ? 1 : -1];
typedef char FOPipboyManagerLightOffset[(offsetof(FOPipboyManager, b1stPersonLightOn) == 0x160) ? 1 : -1];
typedef char InterfacePipboyManagerOffset[(offsetof(Interface, pPipboyManager) == 0x174) ? 1 : -1];
typedef char NiUpdateDataSize[(sizeof(NiUpdateData) == 12) ? 1 : -1];
typedef char NiMatrix3Size[(sizeof(ThreeByThreeMatrix) == 36) ? 1 : -1];
extern SettingT_GameSettingCollection_ DAT_011db514;
#endif
