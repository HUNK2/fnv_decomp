// fallout/magic/magictarget_decls.h: declares TESForm, TESObjectREFR, TESSoundFile, TESTopicInfo, TESRecipe and more
#ifndef FNV_MAGICTARGET_DECLS_H
#define FNV_MAGICTARGET_DECLS_H

class MagicTarget;
class MagicCaster;
class MagicItem;
class ActiveEffect;
class EffectItem;
class EffectSetting;
class Actor;
class PlayerCharacter;
class TESObjectREFR;
class ExtraDataList;
class TESBoundObject;
class BGSPerkEntry;
class PerkButtonEntry;
class TESActorBase;
class TESIdleForm;
namespace ActorValue {
enum Index
{
    None = -1
};
}
enum ENUM_FORM_ID
{
    FORM_NONE = 0
};
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short length, capacity;
    ~BSStringT();
    const char* String();
};
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    T& GetItem();
    BSSimpleList* GetNext();
    bool IsEmpty();
    void Insert(T, int(__cdecl*)(T, T));
};
class TESForm
{
  public:
    virtual void vfn_0();
    unsigned int GetFormID();
    ENUM_FORM_ID GetFormType() const;
    static TESForm* GetFormByID(unsigned int);
};
class TESObjectREFR
{
  public:
    virtual ~TESObjectREFR();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    ExtraDataList* GetExtraData();
    const char* GetFullName();
};
class TESSoundFile
{
  public:
    const char* GetSoundFile() const;
};
class TESTopicInfo
{
  public:
    TESActorBase* GetSpeaker();
};
class TESRecipe
{
  public:
    void SetSkill(int);
};
class BGSImpactData
{
  public:
    void SetSound1(class TESSound*);
};
class Script
{
  public:
    static bool GetLocalData(TESForm*, ExtraDataList*, unsigned int);
};
class EffectSetting
{
  public:
    bool FUN_007df1b0();
    bool GetFlag(unsigned int) const;
    bool EffectSetting_IsFlagSet(unsigned int);
    int GetArchetype();
};
class EffectItem
{
  public:
    char effectLayout[0x14];
    EffectSetting* setting;
    int GetAffectedActorValue();
    bool IsScriptBasedEffect();
    EffectSetting* GetEffectSetting();
    bool FUN_008231f0();
    bool IsHostile();
    BSStringT<char> GetEffectName();
    int GetMagnitude();
    int GetDuration();
    bool Compare(EffectItem*);
};
class EffectItemList
{
  public:
    EffectItem* GetScriptEffect();
};
class MagicItem
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual bool Unk_04();
    virtual void Unk_05(bool);
    virtual int GetType();
    virtual bool Unk_07();
    virtual bool Unk_08();
    char fullName[8];
    EffectItemList effectList;
};
class AlchemyItem : public MagicItem
{
  public:
    virtual ~AlchemyItem();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    int FUN_004030b0();
};
class IngredientItem : public MagicItem
{
};
class SpellItem
{
  public:
    bool FUN_00823c20();
};
class ActiveEffect
{
  public:
    virtual ~ActiveEffect();
    virtual ActiveEffect* Clone();
    virtual void Unk_02();
    virtual void Unk_03(float);
    virtual void SaveGame(unsigned int);
    virtual void LoadGame(unsigned int);
    virtual void Unk_06(unsigned int);
    virtual void Unk_07(unsigned int);
    virtual void Unk_08(unsigned int);
    virtual void Unk_09(unsigned int);
    virtual void Unk_0A(unsigned int);
    virtual void CopyTo(ActiveEffect*);
    virtual bool Unk_0C(unsigned int);
    virtual bool Unk_0D(unsigned int);
    virtual bool ResetCasterIfSame(MagicCaster*);
    virtual bool Unk_0F();
    virtual void Unk_10(unsigned int);
    virtual void CopyFrom(ActiveEffect*);
    virtual bool Unk_12(unsigned int);
    virtual bool IsEffectValid(MagicTarget*);
    EffectSetting* GetEffectSetting();
    float GetFloatAtOffset1C();
    float FUN_007df1f0();
    void FUN_00804cb0(float);
    void FUN_004f5d90(float);
    void FUN_00693d50(float);
    bool IsFlagged();
    bool FUN_008240f0();
    bool GetByteAtOffset17();
    bool FUN_007df210();
    bool FUN_00705cf0();
    void SetFlag(bool);
    bool FUN_00833c20();
    bool IsFlag200Set();
    void UpdateEffect(float);
    void SetEffectiveness(float);
    void Dispel(bool);
};
class ValueAndConditionsEffect : public ActiveEffect
{
};
class LimbConditionEffect : public ActiveEffect
{
};
bool GetLimbConditionEffectInitialized();
class ActorValueOwner
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual int GetActorValue(unsigned int);
};
class PlayerCharacter
{
  public:
    char baseLayout[0xa4];
    ActorValueOwner actorValues;
};
extern PlayerCharacter* g_thePlayer;
void DebugLog(const char*, ...);
void ApplyPerkModifiers(int, Actor*, ...);
int GetStatusResult();
bool FUN_0040dfa0(EffectItem*, EffectItem*);
// Getter bodies are folded in the original executable. These expressions use
// their existing canonical bindings while retaining each receiver's layout.
#define EFFECT_ITEM(e) ((EffectItem*)((TESForm*)(e))->GetFormID())
#define EFFECT_SPELL(e) ((MagicItem*)((BSSimpleArray<ParentSpaceNode, 1024>*)(e))->GetSize())
class ParentSpaceNode;
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    unsigned int GetSize();
};
class BSFileEntry;
class LocationDescriptor
{
  public:
    BSFileEntry* SetLocRef();
};
class ActorMover
{
  public:
    unsigned int GetCurrentMoveModeType();
};
class LowProcess
{
  public:
    TESObjectREFR* GetActiveCombatTarget();
};
class PlayerQuestData
{
  public:
    class Date* GetLogDate();
};
class TESSpellList
{
  public:
    static bool RemoveSpell(BSFileEntry*);
};
class StartMenu
{
  public:
    const char* GetMenuTitle();
};
extern StartMenu DAT_011d1fc8, DAT_011d3c04;
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
class Interface
{
  public:
    static bool ShowMessage(const char*, int, const char*, const char*, float, bool);
};
class TESImageSpaceModifier : public TESForm
{
};
class BGSDefaultObjectManager
{
  public:
    static TESForm* GetDefaultObjectByIndex(int);
};
class ImageSpaceModifierInstanceForm
{
  public:
    static ImageSpaceModifierInstanceForm* ApplyImageSpaceModifier(TESImageSpaceModifier*, float, class NiAVObject*);
};
extern "C" int sprintf(char*, const char*, ...);
extern "C" int _mbsicmp(const unsigned char*, const unsigned char*);
class TESResponse
{
  public:
    TESResponse* GetNext();
};
class MagicTargetFormDispatch
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
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual bool GetIsReference();
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
    virtual MagicTarget* GetMagicTarget();
};
class MagicEffectCollection;
class MagicCaster
{
  public:
    MagicCaster();
    MagicEffectCollection* apTargetLight;
    unsigned int eState;
    virtual void CastSpellOnCaster(SpellItem*, bool);
    virtual void CastSpellOnSelf(SpellItem*, bool);
    virtual void CastSpellAtLocation(SpellItem*, bool);
    virtual void CastMagicItem(MagicItem*, bool, MagicTarget*, float, bool);
    virtual void CastSpellAtTarget(SpellItem*, MagicTarget*, bool);
    virtual void CastMagicItemOnObject(MagicItem*, TESBoundObject*, bool);
    virtual MagicTarget* GetSpellTarget();
    virtual void UpdateCastState();
    virtual void CompleteCast();
    virtual void SpellCast(MagicItem*, bool);
    virtual bool CanCast(MagicItem*, float*, int*, bool);
    virtual TESObjectREFR* GetCasterReference();
    virtual class NiNode* GetMagicNode();
    virtual MagicItem* GetSelectedMagicItem();
    virtual bool HasActiveEffect(ActiveEffect*);
    virtual float GetCasterEffectiveness(bool, float);
    virtual void SetSelectedMagicItem(MagicItem*);
    virtual MagicTarget* GetCurrentMagicTarget();
    virtual void SetMagicTarget(MagicTarget*);
    virtual ActiveEffect* CreateActiveEffect(MagicItem*, EffectItem*, TESBoundObject*);
};
class MagicSystem
{
  public:
    static SpellItem* GetPipBoyLightSpell();
    static SpellItem* ms_pPipBoyLightSpell;
};
class MagicTargetActorDispatch
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
    virtual void vfn_d0();
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
    virtual void vfn_2e8();
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
};
#endif
