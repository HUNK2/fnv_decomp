// Declaration-only full xNVSE runtime representation, GameForms.h:1016-1022,1540-1549,2301-2325.
// Requires the reviewed ModelLoader form declarations. No bodies or globals.
#ifndef FNV_MODELLOADER_ACTIVATOR_DECLARATIONS_H
#define FNV_MODELLOADER_ACTIVATOR_DECLARATIONS_H
class TESWaterForm;
class BGSTalkingActivator;
class TESBoundAnimObject : public TESBoundObject
{
  public:
    TESBoundAnimObject();
    ~TESBoundAnimObject();
};
class BGSOpenCloseForm
{
  public:
    virtual void Unk_00(unsigned long arg0, unsigned long arg1);
    virtual void Unk_01(unsigned long arg0, unsigned long arg1);
    virtual bool Unk_02(void);
    BGSOpenCloseForm();
    ~BGSOpenCloseForm();
};
class TESObjectACTI : public TESBoundAnimObject
{
  public:
    TESObjectACTI();
    ~TESObjectACTI();
    TESFullName fullName;
    TESModelTextureSwap modelTextureSwap;
    TESScriptableForm scriptable;
    BGSDestructibleObjectForm destructible;
    BGSOpenCloseForm openClose;
    TESSound* loopingSound;
    TESSound* activationSound;
    TESSound* radioTemplate;
    TESWaterForm* waterType;
    BGSTalkingActivator* radioStation;
    String activationPrompt;
    void SetActivateSound(TESSound* sound);
};
typedef char modelloader_acti_base_size[(sizeof(TESBoundAnimObject) == 0x30) ? 1 : -1];
typedef char modelloader_acti_openclose_size[(sizeof(BGSOpenCloseForm) == 4) ? 1 : -1];
typedef char modelloader_acti_size[(sizeof(TESObjectACTI) == 0x90) ? 1 : -1];
typedef char modelloader_acti_offset_0[(offsetof(TESObjectACTI, fullName) == 0x30) ? 1 : -1];
typedef char modelloader_acti_offset_1[(offsetof(TESObjectACTI, modelTextureSwap) == 0x3c) ? 1 : -1];
typedef char modelloader_acti_offset_2[(offsetof(TESObjectACTI, scriptable) == 0x5c) ? 1 : -1];
typedef char modelloader_acti_offset_3[(offsetof(TESObjectACTI, destructible) == 0x68) ? 1 : -1];
typedef char modelloader_acti_offset_4[(offsetof(TESObjectACTI, openClose) == 0x70) ? 1 : -1];
typedef char modelloader_acti_offset_5[(offsetof(TESObjectACTI, loopingSound) == 0x74) ? 1 : -1];
typedef char modelloader_acti_offset_6[(offsetof(TESObjectACTI, activationSound) == 0x78) ? 1 : -1];
typedef char modelloader_acti_offset_7[(offsetof(TESObjectACTI, radioTemplate) == 0x7c) ? 1 : -1];
typedef char modelloader_acti_offset_8[(offsetof(TESObjectACTI, waterType) == 0x80) ? 1 : -1];
typedef char modelloader_acti_offset_9[(offsetof(TESObjectACTI, radioStation) == 0x84) ? 1 : -1];
typedef char modelloader_acti_offset_10[(offsetof(TESObjectACTI, activationPrompt) == 0x88) ? 1 : -1];
#endif
