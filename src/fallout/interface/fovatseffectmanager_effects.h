// fallout/interface/fovatseffectmanager_effects.h: declares TESModel, TESDescription, TESFullName, TESIcon, SettingT_GameSettingCollection_ and more
#ifndef FNV_FOVATSEFFECTMANAGER_EFFECTS_H
#define FNV_FOVATSEFFECTMANAGER_EFFECTS_H

#include "TESForm.h"
class TESObjectLIGH;
class TESEffectShader;
class TESModel : public BaseFormComponent
{
  public:
    BSStringT<char> m_kModelFilePath;
    unsigned char textureCount;
    void** textureOffsets;
    unsigned char flags;
    TESModel();
    ~TESModel();
};
class TESDescription : public BaseFormComponent
{
  public:
    unsigned long m_uiDescriptionFileOffset;
    TESDescription();
};
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;
    TESFullName();
    ~TESFullName();
};
class TESIcon : public BaseFormComponent
{
  public:
    BSStringT<char> cTexture;
    TESIcon();
    ~TESIcon();
};
union SETTING_VALUE
{
    float f;
    int i;
    const char* s;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
class GlobalObject_0040e0b0;
extern GlobalObject_0040e0b0 g_011c36c0;
extern GlobalObject_0040e0b0 g_011c37e8;
class EffectSetting : public TESForm, public TESModel, public TESDescription, public TESFullName, public TESIcon
{
  public:
    bool (*m_pEffectSettingCallback)(EffectSetting*, void*);
    void* m_pPredicateData;
    struct EndianSwappableData
    {
        unsigned int iFlags;
        float m_fBaseCost;
        TESForm* m_pAssociatedForm;
        int m_iAssociatedSkill;
        int m_iResistanceActorValue;
        short m_sCounterEffectCount;
        TESObjectLIGH* apTargetLight;
        float fSpeed;
        TESEffectShader* m_pEffectShader;
        TESEffectShader* m_pEnchantEffectShader;
        TESSound* m_pCastSound;
        TESSound* m_pBoltSound;
        TESSound* m_pContactSound;
        TESSound* m_pAreaEffectSound;
        float m_fEnchantmentFactor;
        float m_fBarterFactor;
        int m_eEffectTypeItem;
        int m_iAssociatedActorValue;
    } data;
    BSSimpleList<EffectSetting*> counterEffects;
    int m_iActorValue;
    int m_iEffectID;
    EffectSetting();
    virtual ~EffectSetting();
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent*);
    virtual bool CompareWithBase(BaseFormComponent*);
};
FNV_STATIC_ASSERT(sizeof(TESModel) == 0x18);
FNV_STATIC_ASSERT(sizeof(EffectSetting) == 0xb0);
FNV_STATIC_ASSERT(offsetof(EffectSetting, data) == 0x58);
#endif
