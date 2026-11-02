// fallout/magic/concussioneffect_decls.h: declares MagicTarget, MagicProjectile, ActorMover, ActorSecondSubobject, Actor and more
#ifndef CONCUSSIONEFFECT_DECLS_H
#define CONCUSSIONEFFECT_DECLS_H

class Actor;
class MagicCaster;
class MagicItem;
class EffectItem;
class BaseProcess;
class PlayerCharacter;
class SoundPlaybackHandle;
class BSAudio;
class TESImageSpaceModifier;
class NiAVObject;
class MagicTarget
{
  public:
    Actor* GetOwnerActor() const;
};
class MagicProjectile
{
  public:
    void Process(float);
};
class ActorMover
{
  public:
    unsigned int GetCurrentMoveModeType();
};
class ActorSecondSubobject
{
  public:
    virtual void vfn_0()
    {}
    virtual void vfn_4()
    {}
    virtual int vfn_8(int);
};
class Actor
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
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
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual bool HasHealth(bool);
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual bool vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual bool IsPlayerRef();
    float FUN_008be870();
    BaseProcess* GetProcess();
    char layoutPadding04[0xa0];
    ActorSecondSubobject second;
};
class ActiveEffect
{
  public:
    virtual void vfn_00()
    {}
    virtual void vfn_04()
    {}
    virtual void vfn_08()
    {}
    virtual void vfn_0c()
    {}
    virtual void vfn_10()
    {}
    virtual void vfn_14()
    {}
    virtual void vfn_18()
    {}
    virtual void vfn_1c()
    {}
    virtual void vfn_20()
    {}
    virtual void vfn_24()
    {}
    virtual void vfn_28()
    {}
    virtual void vfn_2c()
    {}
    virtual void vfn_30()
    {}
    virtual void vfn_34()
    {}
    virtual void vfn_38()
    {}
    virtual void vfn_3c()
    {}
    virtual void vfn_40()
    {}
    virtual void CopyFrom(ActiveEffect*)
    {}
    float m_fEffectMagnitude;
    MagicItem* pSpell;
    EffectItem* pEffect;
    unsigned char layoutPadding10[0x18];
    MagicCaster* m_pEffectInstance;
    unsigned char layoutPadding2c[0x1c];
};
class ConcussionEffect : public ActiveEffect
{
  public:
    float m_fPackageValue;
    ConcussionEffect(MagicCaster*, MagicItem*, EffectItem*);
    virtual ActiveEffect* Copy();
    void ApplyConcussion(Actor* target);
    virtual bool IsEffectValid(MagicTarget* target);
    virtual void Update(float deltaTime);
};
union SETTING_VALUE
{
    float value;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
class PlayerCharacter
{
  public:
    bool IsSleepingOrResting();
};
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    unsigned int stateWord;
    unsigned int eState;
    bool Play(bool);
    ~SoundPlaybackHandle();
};
class BSAudio
{
  public:
    SoundPlaybackHandle GetSoundHandleByEditorID(const char*, unsigned int);
};
class TESImageSpaceModifier
{
  public:
    static TESImageSpaceModifier* GetConcussionModifier();
};
class ImageSpaceModifierInstanceForm
{
  public:
    static ImageSpaceModifierInstanceForm* Trigger(TESImageSpaceModifier*, float, NiAVObject*);
};
class BaseProcess
{
  public:
    virtual void vfn_00()
    {}
    virtual void vfn_04()
    {}
    virtual void vfn_08()
    {}
    virtual void vfn_0c()
    {}
    virtual void vfn_10()
    {}
    virtual void vfn_14()
    {}
    virtual void vfn_18()
    {}
    virtual void vfn_1c()
    {}
    virtual void vfn_20()
    {}
    virtual void vfn_24()
    {}
    virtual void vfn_28()
    {}
    virtual void vfn_2c()
    {}
    virtual void vfn_30()
    {}
    virtual void vfn_34()
    {}
    virtual void vfn_38()
    {}
    virtual void vfn_3c()
    {}
    virtual void vfn_40()
    {}
    virtual void vfn_44(Actor*, int, int, int, int, int);
};
BSAudio* FUN_00453a70();
void* __cdecl operator new(unsigned int);
extern SettingT_GameSettingCollection_ DAT_011d1ba4;
extern SettingT_GameSettingCollection_ DAT_011cf834;
extern bool DAT_011dbe50;
extern PlayerCharacter* g_thePlayer;
#endif
