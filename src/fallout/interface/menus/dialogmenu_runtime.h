#ifndef FNV_DIALOGMENU_RUNTIME_H
#define FNV_DIALOGMENU_RUNTIME_H

#include "dialogmenu_decls.h"
class MediaSet;
template <> class BSSimpleList<MediaSet*>
{
  public:
    MediaSet* m_item;
    BSSimpleList* m_pkNext;
    void AddTail(MediaSet* const&);
};
void* operator new(unsigned int) throw();
void operator delete(void*) throw();
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
int strcat_s(char*, unsigned int, const char*);
int Warning(const char*, ...);
class DialogueItem
{
  public:
    TESTopicInfo* GetInfo();
    TESQuest* GetQuest();
    TESTopic* GetAudioBackendData();
    TESObjectREFR* SelectDefaultResponseList();
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
    const char* String();
};
union SETTING_VALUE
{
    float f;
    int i;
    const char* s;
    bool b;
};
class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
    float FUN_0084d030();
};
extern TimeGlobal g_timeGlobal;
extern SettingT_GameSettingCollection_ DAT_011d27fc, DAT_011d3fe8;
extern SettingT_GameSettingCollection_ DAT_011d0a24;
extern int DAT_011d9504;
class TileListBoxCalls
{
  public:
    float GetFloat(int);
};
class ActorValueInfo : public TESForm, public TESFullName
{
};
class BGSPerk : public TESForm, public TESFullName
{
};
class BGSImpactDataSet;
class BGSExplosion
{
  public:
    BGSImpactDataSet* FUN_00516bf0();
};
class TESObjectREFR
{
  public:
    TESBoundObject* GetObjectReference();
    ExtraDataList* GetExtraData();
};
class ExtraDataList
{
  public:
    TESPackage* GetPackageOverride();
};
class TESPackage
{
  public:
    enum PTYPE
    {
        Dialogue = 15,
        OtherDialogue = 28
    };
    PTYPE GetPackType();
    float GetPackageFloatValue();
};
int ComputeWeightedValue(float, float, int);
class TESBoundObject
{
  public:
    int GetFormType() const;
};
class TESTopicInfo : public TESForm
{
  public:
    unsigned char infoPadding18[13];
    signed char challengeFlags;
    unsigned char infoPadding26[26];
    TESForm* m_pPerkSkillStat;
    bool FUN_00579200();
    bool IsChallengeFlagSet();
    ActorValueInfo* GetActorValue();
    BGSPerk* GetPerk();
    int GetNextSpeakerType();
    void RunResultScript(bool, MobileObject*);
    void AddTopicList();
    PerkEntryConditionSet* GetInfoConditions();
    bool IsFlagSet();
};
class PerkEntryConditionSet
{
  public:
    BSSimpleList<TESConditionItem*> m_kConditionItems;
};
struct DialogMenuConditionFunction
{
    unsigned short function;
    unsigned short padding;
    ActorValue::Index actorValue;
};
class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*>* GetLinkToList();
};
class TESConditionItem
{
  public:
    float GetConditionValue();
};
class ActorValueOwner
{
  public:
    int GetActorValueAsInteger(ActorValue::Index);
    float GetActorValueFloatByIndex(ActorValue::Index);
};
class MenuTopic
{
  public:
    BSStringT<char> m_kPrompt;
    bool m_bFirstFlag, m_bIsRefusal, m_bThirdFlag;
    BSSimpleList<DialogueResponse*> m_kResponseList;
    TESQuest* pQuest;
    TESTopicInfo* pInfo;
    TESTopic* m_pOriginalTopic;
    BSSimpleList<DialogueResponse*>* m_pCurrentResponseList;
    bool m_bIsRemappedRumor, m_bInfoHasBeenRead;
    TESTopic* pTopic;
    MenuTopic(TESQuest*, TESTopic*, TESTopicInfo*, MobileObject*, bool);
    ~MenuTopic();
    DialogueResponse* GetActiveResponse();
    bool NextResponse();
    void FillResponseList();
};
class TopicMenuController
{
  public:
    MenuTopic* GetSelectedTopic();
    MenuTopic* GetFirstTopic();
    bool SelectTopic(bool);
    bool AdvanceTopic();
    bool FUN_0083e430(int);
    bool ShouldSkipTopic(MenuTopic*);
    bool Initialize(MobileObject*, TESTopic*);
    bool FUN_00833c20();
    void AddHeadIfNotNull(BSSimpleList<MenuTopic*>*);
    void RunTopicResultScript();
    void UpdateTopicList();
    static void IncrementMiscStat(int);
};
class Date;
class PlayerQuestData
{
  public:
    Date* GetLogDate();
};
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
    float Length() const;
};
class BSFaceGenNiNode
{
  public:
    void StopMoving(bool);
};
class MobileObject
{
  public:
    bool FUN_00574900();
    TESPackage* GetCurrentPackage();
    const char* GetFullName();
    void FUN_00934250();
    bool IsInThirdPerson();
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void SetAltered(bool);
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
    virtual bool IsActor();
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
    virtual BSFaceGenNiNode* GetFaceGenNodeBiped(unsigned int);
    virtual BSFaceGenNiNode* GetFaceGenNodeSkinned(unsigned int);
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
    virtual NiPoint3* GetPos();
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
    virtual bool vfn_22c(bool);
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
    virtual void vfn_264(float, DialogueResponse*, bool);
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual bool vfn_274(bool);
    virtual void vfn_278(bool);
    virtual void vfn_27c();
    virtual void vfn_280(PlayerCharacter*, int, int, bool, bool, bool, bool, bool, bool);
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
    virtual PlayerCharacter* vfn_2c8();
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
    virtual int CalculateDisposition(PlayerCharacter*, void*);
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual void vfn_454();
    virtual void vfn_458();
    virtual void vfn_45c();
    virtual void vfn_460();
    virtual void vfn_464();
    virtual void vfn_468();
    virtual void vfn_46c();
    virtual void vfn_470();
    virtual void vfn_474();
    virtual void vfn_478();
    virtual void vfn_47c();
    virtual void vfn_480();
    virtual void vfn_484();
    virtual void RewardXP(unsigned int);
    unsigned char layoutPadding4[0x78];
    bool bDialogueSelected;
};
class BaseProcess
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual bool vfn_24(Actor*, bool);
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
    virtual void SetAltered(bool);
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
    virtual BSFaceGenNiNode* GetFaceGenNodeBiped(unsigned int);
    virtual BSFaceGenNiNode* GetFaceGenNodeSkinned(unsigned int);
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
    virtual NiPoint3* GetPos();
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
    virtual void vfn_22c();
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
    virtual bool vfn_274(bool);
    virtual void vfn_278(bool);
    virtual void vfn_27c();
    virtual void vfn_280(PlayerCharacter*, int, int, bool, bool, bool, bool, bool, bool);
    virtual void vfn_284();
    virtual void vfn_288(Actor*, int);
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
    virtual PlayerCharacter* vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec(void*);
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
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual void vfn_454();
    virtual void vfn_458();
    virtual void vfn_45c();
    virtual void vfn_460();
    virtual void vfn_464();
    virtual void vfn_468();
    virtual void vfn_46c();
    virtual void vfn_470();
    virtual void vfn_474();
    virtual void vfn_478();
    virtual void vfn_47c();
    virtual void vfn_480();
    virtual void vfn_484();
    virtual void vfn_488();
    virtual SoundPlaybackHandle vfn_48c(bool);
    virtual void vfn_490();
    virtual void vfn_494();
    virtual void vfn_498();
    virtual void vfn_49c();
    virtual void vfn_4a0();
    virtual void vfn_4a4();
    virtual void vfn_4a8();
    virtual void vfn_4ac();
    virtual void vfn_4b0();
    virtual void vfn_4b4(float);
    virtual void vfn_4b8();
    virtual void vfn_4bc();
    virtual void vfn_4c0();
    virtual void vfn_4c4();
    virtual void vfn_4c8();
    virtual void vfn_4cc();
    virtual void vfn_4d0();
    virtual void vfn_4d4();
    virtual void vfn_4d8();
    virtual void vfn_4dc();
    virtual void vfn_4e0();
    virtual void vfn_4e4();
    virtual void vfn_4e8();
    virtual void vfn_4ec();
    virtual void vfn_4f0();
    virtual void vfn_4f4();
    virtual void vfn_4f8();
    virtual void vfn_4fc();
    virtual void vfn_500();
    virtual void vfn_504();
    virtual void vfn_508();
    virtual void vfn_50c();
    virtual void vfn_510();
    virtual void vfn_514();
    virtual void vfn_518();
    virtual void vfn_51c();
    virtual void vfn_520();
    virtual void vfn_524(Actor*);
    virtual void vfn_528();
    virtual void vfn_52c();
    virtual void vfn_530();
    virtual void vfn_534();
    virtual void vfn_538();
    virtual void vfn_53c();
    virtual void vfn_540();
    virtual void vfn_544();
    virtual void vfn_548();
    virtual void vfn_54c();
    virtual void vfn_550();
    virtual void vfn_554();
    virtual void vfn_558();
    virtual void vfn_55c();
    virtual void vfn_560();
    virtual void vfn_564();
    virtual void vfn_568();
    virtual void vfn_56c();
    virtual void vfn_570();
    virtual void vfn_574();
    virtual void vfn_578();
    virtual void vfn_57c();
    virtual void vfn_580();
    virtual void vfn_584();
    virtual void vfn_588();
    virtual void vfn_58c();
    virtual void vfn_590();
    virtual void vfn_594();
    virtual void vfn_598();
    virtual void vfn_59c();
    virtual void vfn_5a0();
    virtual void vfn_5a4();
    virtual void vfn_5a8();
    virtual void vfn_5ac();
    virtual void vfn_5b0();
    virtual void vfn_5b4();
    virtual void vfn_5b8();
    virtual void vfn_5bc();
    virtual void vfn_5c0();
    virtual void vfn_5c4();
    virtual void vfn_5c8();
    virtual void vfn_5cc();
    virtual void vfn_5d0();
    virtual void vfn_5d4();
    virtual void vfn_5d8();
    virtual void vfn_5dc();
    virtual void vfn_5e0();
    virtual void vfn_5e4();
    virtual void vfn_5e8();
    virtual void vfn_5ec();
    virtual void vfn_5f0();
    virtual void vfn_5f4();
    virtual void vfn_5f8();
    virtual void vfn_5fc();
    virtual void vfn_600();
    virtual void vfn_604();
    virtual void vfn_608();
    virtual void vfn_60c();
    virtual int vfn_610();
    virtual void vfn_614();
    virtual void vfn_618();
    virtual void vfn_61c();
    virtual void vfn_620();
    virtual void vfn_624();
    virtual void vfn_628();
    virtual void vfn_62c();
    virtual void vfn_630();
    virtual void vfn_634();
    virtual void vfn_638();
    virtual void vfn_63c();
    virtual void vfn_640();
    virtual void vfn_644();
    virtual void vfn_648();
    virtual void vfn_64c();
    virtual void vfn_650(bool);
};
class Actor : public MobileObject
{
  public:
    void SetSpeakingState(bool);
    void StopMoving();
    bool ShouldShowSubtitles();
    static void SetActorDialogueState(unsigned int, bool);
};
class PlayerCharacter : public MobileObject
{
  public:
    unsigned char layoutPadding80[0x24];
    ActorValueOwner actorValueOwner;
    bool FUN_004eaf60();
    void Show1stPerson(bool);
    void FocusOnActor(MobileObject*, float, bool);
    void SetAimingWeapon(bool, bool, bool);
    void UpdatePlayerInventory();
    void UpdateCamera(bool, const bool);
    void UpdatePlayerState();
    bool HasCombatState();
};
extern PlayerCharacter* g_thePlayer;
extern TESTopicInfo* DAT_011d9518;
class TESSoundFile
{
  public:
    const char* GetSoundFile() const;
};
TESTopicInfo* FindFollowupTopicInfo(TESTopicInfo*, bool*, void*, PlayerCharacter*, bool, bool);
FNV_STATIC_ASSERT(sizeof(MenuTopic) == 0x2C);
FNV_STATIC_ASSERT(offsetof(PlayerCharacter, actorValueOwner) == 0xA4);
class InterfaceManager
{
  public:
    class TutorialState
    {
      public:
        bool FUN_00718840(int);
        bool ShowMessage(int, int, unsigned int);
    };
    unsigned char layoutPadding0[0x4D4];
    TutorialState tutorial;
    Tile* FUN_00586150();
};
InterfaceManager* FUN_004b7210();
int FUN_007620e0();
bool FUN_005d4a40();
class TESImageSpaceModifier
{
  public:
    static TESImageSpaceModifier* GetGetHit();
};
class ImageSpaceModifierInstanceForm
{
  public:
    static void Stop(TESImageSpaceModifier*);
};
class ImageSpaceModifierInstanceDOF
{
  public:
    enum DepthOfFieldMode
    {
        Back = 2
    };
    static ImageSpaceModifierInstanceDOF* CreateAndRegister(float, float, DepthOfFieldMode, float, float, float);
    void FUN_005bbd60(bool);
    void FUN_0063f790(float);
};
class INISettingCollection;
template <> class SettingT<INISettingCollection>
{
  public:
    SETTING_VALUE* Bool();
};
extern SettingT<INISettingCollection> DAT_011d8934;
extern SettingT_GameSettingCollection_ DAT_011d46fc;
extern float DAT_011a008c;
extern DialogMenu* DAT_011d9510;
extern int DAT_011d9508;
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    static void EnableAudio();
    static void DeactivateAudio();
};
class DialogMenuInterfaceCalls
{
  public:
    static void SetHUDVisible(bool);
};
FNV_STATIC_ASSERT(offsetof(InterfaceManager, tutorial) == 0x4D4);
class HighProcess
{
  public:
    int GetProcessLevel();
};
extern SettingT_GameSettingCollection_ DAT_011d3ee0, DAT_011d243c, DAT_011d318c;
extern float DAT_011d951c;
extern unsigned int DAT_011d9594;
extern bool DAT_011f21d0, DAT_011f21d1;
float FUN_0040ebd0(float, float);
class DialogMenuAudioCalls
{
  public:
    void EnableAudio();
    void DeactivateAudio();
};
extern bool DAT_011d9514;
extern SettingT_GameSettingCollection_ DAT_011cd450;
#endif
