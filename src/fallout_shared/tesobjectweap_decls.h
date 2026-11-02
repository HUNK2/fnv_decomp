// fallout_shared/tesobjectweap_decls.h: declares TESFullName, TESTexture, TESIcon, TESScriptableForm, TESHealthForm and more
#ifndef TESOBJECTWEAP_DECLS_H
#define TESOBJECTWEAP_DECLS_H

#include "layout_support.h"
class SpellItem;
class Script;
class MagicItem;
class BSFileEntry;
class TESLandTexture;
class TESFormList;
class FileEntryList;
class DistantTreeTextureInfo;
class NiAVObject;
class QueuedFile;
enum ActorValue__Index
{
    ActorValue__Index_None = -1
};
#include "BaseFormComponent.h"
#include "TESForm.h"

#include "layout_support.h"
class BGSAmmoForm;
class BGSBipedModelList;
class BGSClipRoundsForm;
class BGSDestructibleObjectForm;
class BGSEquipType;
class BGSImpactDataSet;
class BGSMessageIcon;
class BGSPickupPutdownSounds;
class BGSPreloadable;
class BGSProjectile;
class BGSRepairItemList;
class BSFileEntry;
class CollisionComponent;
class EnchantmentItem;
class ShortPoint3;
class WeaponProperties;
class WeaponCriticalData;
class WeaponVATSData;
class TESAttackDamageForm;
class TESBoundObject__BOUND_DATA;
class TESEffectShader;
class TESEnchantableForm;
class TESModel;
class TESModelTextureSwap;
class TESObjectIMOD;
class TESFormList;
class TESObjectSTAT;
class TESObjectWEAP;
class FileEntryList;
class TESValueForm;
class TESWeightForm;
class DistantTreeTextureInfo;
enum MagicSystem__CastingType
{
    MagicSystem__CastingType_CAST_ONCE = 0,
    MagicSystem__CastingType_WHEN_USED = 1,
    MagicSystem__CastingType_WHEN_STRIKES = 2,
    MagicSystem__CastingType_CONSTANT_EFFECT = 3,
    MagicSystem__CastingType_CASTING_COUNT = 4
};
enum BGSEquipType__EQUIP_TYPE
{
    BGSEquipType__EQUIP_TYPE_ET_NONE = -1,
    BGSEquipType__EQUIP_TYPE_ET_BIG_GUN = 0,
    BGSEquipType__EQUIP_TYPE_ET_ENERGY_WEAPON = 1,
    BGSEquipType__EQUIP_TYPE_ET_SMALL_GUN = 2,
    BGSEquipType__EQUIP_TYPE_ET_MELEE_WEAPON = 3,
    BGSEquipType__EQUIP_TYPE_ET_UNARMED_WEAPON = 4,
    BGSEquipType__EQUIP_TYPE_ET_THROWN_WEAPON = 5,
    BGSEquipType__EQUIP_TYPE_ET_MINE = 6,
    BGSEquipType__EQUIP_TYPE_ET_BODY_WEAR = 7,
    BGSEquipType__EQUIP_TYPE_ET_HEAD_WEAR = 8,
    BGSEquipType__EQUIP_TYPE_ET_HAND_WEAR = 9,
    BGSEquipType__EQUIP_TYPE_ET_CHEMS = 10,
    BGSEquipType__EQUIP_TYPE_ET_STIMPACK = 11,
    BGSEquipType__EQUIP_TYPE_ET_FOOD = 12,
    BGSEquipType__EQUIP_TYPE_ET_ALCOHOL = 13,
    BGSEquipType__EQUIP_TYPE_ET_COUNT = 14
};
enum WEAPONHITBEHAVIOR
{
    WEAPONHITBEHAVIOR_WHB_NORMAL = 0,
    WEAPONHITBEHAVIOR_WHB_DISMEMBER_ONLY = 1,
    WEAPONHITBEHAVIOR_WHB_EXPLODE_ONLY = 2,
    WEAPONHITBEHAVIOR_WHB_NO_DISMEMBER_OR_EXPLODE = 3
};
enum WEAPON_RUMBLE_PATTERN
{
    WEAPON_RUMBLE_PATTERN_RUMBLE_CONSTANT = 0,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PERIODIC_SQUARE = 1,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PERIODIC_TRIANGLE = 2,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PERIODIC_SAWTOOTH = 3,
    WEAPON_RUMBLE_PATTERN_RUMBLE_PATTERN_COUNT = 4
};
enum WEAPON_MOD_EFFECT
{
    WEAPON_MOD_EFFECT_WEAPON_MOD_NONE = 0,
    WEAPON_MOD_EFFECT_WEAPON_MOD_INCREASE_WEAPON_DAMAGE = 1,
    WEAPON_MOD_EFFECT_WEAPON_MOD_INCREASE_CLIP_SIZE = 2,
    WEAPON_MOD_EFFECT_WEAPON_MOD_DECREASE_SPREAD = 3,
    WEAPON_MOD_EFFECT_WEAPON_MOD_DECREASE_WEIGHT = 4,
    WEAPON_MOD_EFFECT_WEAPON_MOD_AMMO_REGEN_SHOT = 5,
    WEAPON_MOD_EFFECT_WEAPON_MOD_AMMO_REGEN_SECONDS = 6,
    WEAPON_MOD_EFFECT_WEAPON_MOD_EQUIP_SPEED = 7,
    WEAPON_MOD_EFFECT_WEAPON_MOD_FIRE_SPEED = 8,
    WEAPON_MOD_EFFECT_WEAPON_MOD_PROJECTILE_SPEED = 9,
    WEAPON_MOD_EFFECT_WEAPON_MOD_MAX_HEALTH = 10,
    WEAPON_MOD_EFFECT_WEAPON_MOD_SILENCE = 11,
    WEAPON_MOD_EFFECT_WEAPON_MOD_SPLIT_BEAM = 12,
    WEAPON_MOD_EFFECT_WEAPON_MOD_VATS_BONUS = 13,
    WEAPON_MOD_EFFECT_WEAPON_MOD_IRON_SITES = 14,
    WEAPON_MOD_EFFECT_WEAPON_MOD_VATS_SPECIAL_ATTACK = 15,
    WEAPON_MOD_EFFECT_WEAPON_MOD_EFFECT_COUNT = 16
};
enum SOUND_LEVEL
{
    SOUND_LEVEL_SOUND_LEVEL_LOUD = 0,
    SOUND_LEVEL_SOUND_LEVEL_NORMAL = 1,
    SOUND_LEVEL_SOUND_LEVEL_SILENT = 2,
    SOUND_LEVEL_SOUND_LEVEL_COUNT = 3
};
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;
    TESFullName();
    ~TESFullName();
};
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> FullNameComponent;
    static void ReadTextureData(TESTexture*, TESFile*);
};
class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;
    bool m_bHasScript;
    unsigned char padding[3];
    TESScriptableForm();
    void SetScript(Script*);
    void InitItem(TESForm*);
};
class TESHealthForm : public BaseFormComponent
{
  public:
    unsigned int m_uiHealthValue;
    TESHealthForm();
    ~TESHealthForm();
};
#pragma pack(push, 4)
class TESObject : public TESForm
{
  public:
    TESFormList* m_pOwningList;
    TESObject* m_pPreviousObject;
    TESObject* m_pNextObject;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObject) == 36);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pOwningList) == 24);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pPreviousObject) == 28);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pNextObject) == 32);
#pragma pack(push, 4)
class ShortPoint3
{
  public:
    short x;
    short y;
    short z;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ShortPoint3) == 6);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, y) == 2);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, z) == 4);
#pragma pack(push, 4)
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;
    ShortPoint3 m_kBoundMax;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject__BOUND_DATA) == 12);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMax) == 6);
#pragma pack(push, 4)
class TESBoundObject : public TESObject
{
  public:
    TESBoundObject();
    ~TESBoundObject();
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 48);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, TESBoundObjectBounds) == 36);
#pragma pack(push, 4)
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
#pragma pack(push, 4)
class TESModel : public BaseFormComponent
{
  public:
    TESModel();
    ~TESModel();
    virtual void vfn_10(int, class QueuedFile*);
    virtual void vfn_14();
    virtual void SetModelFilePath(const char*);
    unsigned int GetModelLength() const;
    static void LoadModelData(TESModel*, TESFile*);
    static void LoadTextureSwapData(TESModel*, TESFile*);
    BSStringT<char> m_kModelFilePath;
    FileEntryList m_pTextureSwapData;
    unsigned char cFlags;
    unsigned char layoutPadding15[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
#pragma pack(push, 4)
class TESModelTextureSwap : public TESModel
{
  public:
    TESModelTextureSwap();
    ~TESModelTextureSwap();
    bool ParseTextureSwapData(void*, unsigned int, unsigned int);
    void InitItem(TESForm*);
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModelTextureSwap) == 32);
FNV_STATIC_ASSERT(offsetof(TESModelTextureSwap, TextureSwapNodeAccessor) == 24);
#pragma pack(push, 4)
class TESEnchantableForm : public BaseFormComponent
{
  public:
    TESEnchantableForm();
    void SetCastingType(MagicSystem__CastingType);
    void SetFormEnchanting(EnchantmentItem*);
    void FUN_00483170(unsigned short);
    void InitItem(TESForm*);
    EnchantmentItem* m_pEnchantment;
    unsigned short m_usEnchantmentAmount;
    unsigned char layoutPaddingA[2];
    MagicSystem__CastingType m_eCastingType;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESEnchantableForm) == 16);
FNV_STATIC_ASSERT(offsetof(TESEnchantableForm, m_pEnchantment) == 4);
FNV_STATIC_ASSERT(offsetof(TESEnchantableForm, m_usEnchantmentAmount) == 8);
FNV_STATIC_ASSERT(offsetof(TESEnchantableForm, m_eCastingType) == 12);
#pragma pack(push, 4)
class TESValueForm : public BaseFormComponent
{
  public:
    TESValueForm();
    ~TESValueForm();
    unsigned int iValue;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESValueForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESValueForm, iValue) == 4);
#pragma pack(push, 4)
class TESWeightForm : public BaseFormComponent
{
  public:
    TESWeightForm();
    ~TESWeightForm();
    float fWeight;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESWeightForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESWeightForm, fWeight) == 4);
#pragma pack(push, 4)
class TESAttackDamageForm : public BaseFormComponent
{
  public:
    TESAttackDamageForm();
    ~TESAttackDamageForm();
    unsigned short m_usAttackDamage;
    unsigned char layoutPadding6[2];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESAttackDamageForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESAttackDamageForm, m_usAttackDamage) == 4);
#pragma pack(push, 4)
class BGSAmmoForm : public BaseFormComponent
{
  public:
    BGSAmmoForm();
    void InitItem(TESForm*);
    void SetAmmo(class TESAmmo*);
    TESForm* m_pAmmo;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSAmmoForm) == 8);
FNV_STATIC_ASSERT(offsetof(BGSAmmoForm, m_pAmmo) == 4);
#pragma pack(push, 4)
class BGSClipRoundsForm : public BaseFormComponent
{
  public:
    BGSClipRoundsForm();
    ~BGSClipRoundsForm();
    unsigned char m_ucClipRounds;
    unsigned char layoutPadding5[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSClipRoundsForm) == 8);
FNV_STATIC_ASSERT(offsetof(BGSClipRoundsForm, m_ucClipRounds) == 4);
#pragma pack(push, 4)
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();
    void InitItem(TESForm*);
    static void LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
    CollisionComponent* pData;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 8);
FNV_STATIC_ASSERT(offsetof(BGSDestructibleObjectForm, pData) == 4);
#pragma pack(push, 4)
class BGSRepairItemList : public BaseFormComponent
{
  public:
    BGSRepairItemList();
    ~BGSRepairItemList();
    void InitItem(TESForm*);
    void SetRepairItemList(class BGSListForm*);
    BGSListForm* pListForm;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSRepairItemList) == 8);
FNV_STATIC_ASSERT(offsetof(BGSRepairItemList, pListForm) == 4);
#pragma pack(push, 4)
class BGSEquipType : public BaseFormComponent
{
  public:
    BGSEquipType();
    void SetEquipType(BGSEquipType__EQUIP_TYPE);
    BGSEquipType__EQUIP_TYPE m_eEquipType;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSEquipType) == 8);
FNV_STATIC_ASSERT(offsetof(BGSEquipType, m_eEquipType) == 4);
#pragma pack(push, 4)
class BGSPreloadable : public BaseFormComponent
{
  public:
    BGSPreloadable();
    virtual void QueueResourceLoad(int, class QueuedFile*);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSPreloadable) == 4);
#pragma pack(push, 4)
class BGSMessageIcon : public BaseFormComponent
{
  public:
    BGSMessageIcon();
    ~BGSMessageIcon();
    static void LoadMessageIconChunk(BGSMessageIcon*, TESFile*);
    TESIcon Icon;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSMessageIcon) == 16);
FNV_STATIC_ASSERT(offsetof(BGSMessageIcon, Icon) == 4);
#pragma pack(push, 4)
class BGSBipedModelList : public BaseFormComponent
{
  public:
    BGSBipedModelList();
    ~BGSBipedModelList();
    void InitItem(TESForm*);
    void SetBipedModelList(class BGSListForm*);
    BGSListForm* pListForm;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSBipedModelList) == 8);
FNV_STATIC_ASSERT(offsetof(BGSBipedModelList, pListForm) == 4);
#pragma pack(push, 4)
class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();
    void InitItem(TESForm*);
    void SetPickupSound(TESSound*);
    void SetPutdownSound(TESSound*);
    TESSound* m_pPickupSound;
    TESSound* m_pPutdownSound;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSPickupPutdownSounds) == 12);
FNV_STATIC_ASSERT(offsetof(BGSPickupPutdownSounds, m_pPickupSound) == 4);
FNV_STATIC_ASSERT(offsetof(BGSPickupPutdownSounds, m_pPutdownSound) == 8);
#pragma pack(push, 4)
class WeaponProperties
{
  public:
    char eType;
    unsigned char layoutPadding1[3];
    float fSpeed;
    float ActorTypeValueEntry;
    unsigned char cFlags;
    unsigned char m_ucGripAnimation;
    unsigned char m_ucAmmoUse;
    unsigned char m_ucReloadAnimation;
    float m_fMinimumSpread;
    float fBodyPartChance;
    float m_fUnknownFloat;
    float AmmunitionData;
    unsigned char m_ucSubtype;
    unsigned char layoutPadding21[3];
    BGSProjectile* pProjectile;
    unsigned char m_ucBaseVATSChance;
    unsigned char m_ucAttackAnimation;
    unsigned char m_ucProjectileCount;
    unsigned char m_ucFourthByte;
    float m_fMinimumRange;
    float m_fMaximumRange;
    WEAPONHITBEHAVIOR m_eHitBehavior;
    unsigned int WeaponAttackData;
    float m_fAnimationAttackMultiplier;
    float m_fOverrideActionPoints;
    float m_fLeftRumbleMotorStrength;
    float m_fRightRumbleMotorStrength;
    float m_fRumbleDuration;
    float m_fOverrideDamageToWeaponMultiplier;
    float m_fAttackShotsPerSecond;
    float fWeaponDamageMultiplier;
    float WeaponCombatData;
    float WeaponHandlingData;
    float WeaponFiringData;
    ActorValue__Index m_eWeaponSkill;
    WEAPON_RUMBLE_PATTERN m_eRumblePattern;
    float WeaponFiringParameters;
    float m_fLimbDamageMultiplier;
    ActorValue__Index m_eResistanceType;
    float m_fSightUsage;
    float m_fMinimumSemiAutomaticFireDelay;
    float m_fMaximumSemiAutomaticFireDelay;
    float m_fFourthModifierValue;
    WEAPON_MOD_EFFECT m_eFirstWeaponModEffect;
    WEAPON_MOD_EFFECT m_eSecondWeaponModEffect;
    WEAPON_MOD_EFFECT m_eThirdWeaponModEffect;
    float m_fModValueA1;
    float m_fModValueA2;
    float m_fModValueA3;
    unsigned char m_ucPowerAttackAnimationOverride;
    unsigned char layoutPaddingA5[3];
    unsigned int m_uiStrengthRequirement;
    char m_cUnknownByte;
    char m_cReloadAnimationMod;
    unsigned char layoutPaddingAE[2];
    float FlaggedFloatData;
    float m_fKillImpulse;
    float m_fModValueB1;
    float m_fModValueB2;
    float m_fModValueB3;
    float FourFloatsAndUnsignedInteger;
    unsigned int m_uiSkillRequirement;
    void Endian();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(WeaponProperties) == 204);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, eType) == 0);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, fSpeed) == 4);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, ActorTypeValueEntry) == 8);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, cFlags) == 12);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucGripAnimation) == 13);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucAmmoUse) == 14);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucReloadAnimation) == 15);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fMinimumSpread) == 16);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, fBodyPartChance) == 20);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fUnknownFloat) == 24);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, AmmunitionData) == 28);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucSubtype) == 32);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, pProjectile) == 36);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucBaseVATSChance) == 40);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucAttackAnimation) == 41);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucProjectileCount) == 42);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucFourthByte) == 43);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fMinimumRange) == 44);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fMaximumRange) == 48);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eHitBehavior) == 52);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, WeaponAttackData) == 56);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fAnimationAttackMultiplier) == 60);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, fWeaponDamageMultiplier) == 88);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fOverrideActionPoints) == 64);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fLeftRumbleMotorStrength) == 68);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fRightRumbleMotorStrength) == 72);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fRumbleDuration) == 76);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fOverrideDamageToWeaponMultiplier) == 80);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fAttackShotsPerSecond) == 84);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, WeaponCombatData) == 92);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, WeaponHandlingData) == 96);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, WeaponFiringData) == 100);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eWeaponSkill) == 104);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eRumblePattern) == 108);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, WeaponFiringParameters) == 112);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fLimbDamageMultiplier) == 116);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eResistanceType) == 120);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fSightUsage) == 124);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fMinimumSemiAutomaticFireDelay) == 128);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fMaximumSemiAutomaticFireDelay) == 132);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fFourthModifierValue) == 136);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eFirstWeaponModEffect) == 140);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eSecondWeaponModEffect) == 144);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_eThirdWeaponModEffect) == 148);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fModValueA1) == 152);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fModValueA2) == 156);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fModValueA3) == 160);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_ucPowerAttackAnimationOverride) == 164);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_uiStrengthRequirement) == 168);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_cUnknownByte) == 172);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_cReloadAnimationMod) == 173);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, FlaggedFloatData) == 176);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fKillImpulse) == 180);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fModValueB1) == 184);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fModValueB2) == 188);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_fModValueB3) == 192);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, FourFloatsAndUnsignedInteger) == 196);
FNV_STATIC_ASSERT(offsetof(WeaponProperties, m_uiSkillRequirement) == 200);
#pragma pack(push, 4)
class WeaponCriticalData
{
  public:
    void FUN_00535aa0();
    unsigned short m_usCriticalDamage;
    unsigned char layoutPadding2[2];
    float m_fCriticalChanceMultiplier;
    bool m_bEffectOnDeath;
    unsigned char layoutPadding9[3];
    SpellItem* pEffect;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(WeaponCriticalData) == 16);
FNV_STATIC_ASSERT(offsetof(WeaponCriticalData, m_usCriticalDamage) == 0);
FNV_STATIC_ASSERT(offsetof(WeaponCriticalData, m_fCriticalChanceMultiplier) == 4);
FNV_STATIC_ASSERT(offsetof(WeaponCriticalData, m_bEffectOnDeath) == 8);
FNV_STATIC_ASSERT(offsetof(WeaponCriticalData, pEffect) == 12);
#pragma pack(push, 4)
class WeaponVATSData
{
  public:
    void FUN_0067ff10();
    SpellItem* m_pVATSAttackSpell;
    float m_fSkill;
    float m_fDamageMultiplier;
    float m_fActionPointCost;
    bool bSilent;
    bool m_bModRequired;
    unsigned char cFlags;
    unsigned char layoutPadding13[1];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(WeaponVATSData) == 20);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, m_pVATSAttackSpell) == 0);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, m_fSkill) == 4);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, m_fDamageMultiplier) == 8);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, m_fActionPointCost) == 12);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, bSilent) == 16);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, m_bModRequired) == 17);
FNV_STATIC_ASSERT(offsetof(WeaponVATSData, cFlags) == 18);
#pragma pack(push, 4)
class TESObjectWEAP : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESEnchantableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public TESHealthForm,
                      public TESAttackDamageForm,
                      public BGSAmmoForm,
                      public BGSClipRoundsForm,
                      public BGSDestructibleObjectForm,
                      public BGSRepairItemList,
                      public BGSEquipType,
                      public BGSPreloadable,
                      public BGSMessageIcon,
                      public BGSBipedModelList,
                      public BGSPickupPutdownSounds
{
  public:
    TESObjectWEAP();
    virtual ~TESObjectWEAP();
    void ResetFormData();
    virtual void ClearData();
    virtual void InitItem();
    bool Load(TESFile*);
    void QueueResourceLoad(int, class QueuedFile*, bool);
    unsigned char GetDamageForActor(bool, bool, Actor*);
    ActorValue__Index GetResistance();
    BGSProjectile* GetProjectileData(Actor*);
    class TESAmmo* GetCurrentAmmo(Actor*);
    unsigned char GetAmmoPerShot();
    float GetModdedWeaponValue(WEAPON_MOD_EFFECT, unsigned char);
    bool GetHasScope();
    int GetReloadAnim(bool);
    void FUN_0051f4b0(BGSProjectile*);
    SpellItem* GetField1CC();
    void FUN_0051f4f0(SpellItem*);
    SpellItem* GetVATSSpecialEffect();
    void FUN_0051f530(SpellItem*);
    TESEffectShader* GetScopeEffect();
    void SetEffectShader(TESEffectShader*);
    void SetNPCsUseAmmo(bool);
    void SetModItem(unsigned char, TESObjectIMOD*);
    void SetModObject(unsigned char, TESObjectSTAT*);
    void FUN_00521580(unsigned char);
    TESSound* GetAttackSound(bool);
    void SetAttackSound(TESSound*);
    void SetDistantAttackSound(TESSound*);
    void SetModAttackSound(TESSound*);
    TESSound* GetModDistantAttackSound();
    void FUN_00521650(TESSound*);
    void SetAttackFailSound(TESSound*);
    void SetMeleeBlockSound(TESSound*);
    void SetIdleSound(TESSound*);
    void SetEquipSound(TESSound*);
    void SetUnequipSound(TESSound*);
    void Set1stPersonObject(TESObjectSTAT*);
    void SetAttackSound2(TESSound*);
    void SetModAttackSound2(TESSound*);
    void SetModDistantAttackSound2(TESSound*);
    void SetImpactDataSet(BGSImpactDataSet*);
    WeaponProperties data;
    WeaponCriticalData m_kCriticalData;
    TESModel m_kModel;
    TESModel m_kModel1stPerson;
    TESModel m_kModel3rdPerson;
    TESEffectShader* m_pWeaponEffectShader;
    TESSound* m_pWeaponSound1;
    TESSound* m_pWeaponSound2;
    TESSound* m_pWeaponSound3;
    TESSound* m_pWeaponSound4;
    TESSound* m_pWeaponSound5;
    TESSound* m_pWeaponSound6;
    TESSound* m_pWeaponSound7;
    TESSound* m_pWeaponSound8;
    TESSound* m_pWeaponUnequipSound;
    TESSound* m_pWeaponEquipSound;
    TESSound* m_pWeaponPickupSound;
    TESSound* m_pWeaponDropSound;
    BGSImpactDataSet* m_pImpactDataSet;
    TESObjectSTAT* p1stPersonObject;
    TESObjectSTAT* p1stPersonMod1Object;
    TESObjectSTAT* p1stPersonMod2Object;
    TESObjectSTAT* p1stPersonMod3Object;
    TESObjectSTAT* p1stPersonMod12Object;
    TESObjectSTAT* p1stPersonMod23Object;
    TESObjectSTAT* p1stPersonMod13Object;
    TESObjectSTAT* p1stPersonMod123Object;
    TESModelTextureSwap m_kWeaponModTextureSwap1;
    TESModelTextureSwap m_kWeaponModTextureSwap2;
    TESModelTextureSwap m_kWeaponModTextureSwap3;
    TESModelTextureSwap m_kWeaponModTextureSwap4;
    TESModelTextureSwap m_kWeaponModTextureSwap5;
    TESModelTextureSwap m_kWeaponModTextureSwap6;
    TESModelTextureSwap m_kWeaponModTextureSwap7;
    TESObjectIMOD* m_pWeaponMod1;
    TESObjectIMOD* m_pWeaponMod2;
    TESObjectIMOD* m_pWeaponMod3;
    BSStringT<char> m_kEmbeddedWeaponNodeName;
    SOUND_LEVEL m_eSoundLevel;
    BSStringT<char> VATSAttackName;
    WeaponVATSData m_kVATSData;
    bool m_bHasReloadAnimation;
    unsigned char layoutPadding385[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObjectWEAP) == 904);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, data) == 244);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kCriticalData) == 448);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kModel) == 464);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kModel1stPerson) == 488);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kModel3rdPerson) == 512);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponEffectShader) == 536);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound1) == 540);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound2) == 544);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound3) == 548);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound4) == 552);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound5) == 556);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound6) == 560);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound7) == 564);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponSound8) == 568);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponUnequipSound) == 572);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponEquipSound) == 576);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponPickupSound) == 580);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponDropSound) == 584);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pImpactDataSet) == 588);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonObject) == 592);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod1Object) == 596);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod2Object) == 600);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod3Object) == 604);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod12Object) == 608);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod23Object) == 612);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod13Object) == 616);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, p1stPersonMod123Object) == 620);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap1) == 624);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap2) == 656);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap3) == 688);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap4) == 720);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap5) == 752);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap6) == 784);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kWeaponModTextureSwap7) == 816);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponMod1) == 848);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponMod2) == 852);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_pWeaponMod3) == 856);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kEmbeddedWeaponNodeName) == 860);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_eSoundLevel) == 868);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, VATSAttackName) == 872);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_kVATSData) == 880);
FNV_STATIC_ASSERT(offsetof(TESObjectWEAP, m_bHasReloadAnimation) == 900);
class TESFileFormVersion : public TESFile
{
  public:
    unsigned short GetFormVersion();
};
class TESFileChunkData16 : public TESFile
{
  public:
    bool GetChunkData(unsigned short*);
};

class TESAmmo : public TESBoundObject
{
  public:
    unsigned char GetByteAtOffsetB0();
};
class BGSProjectile : public TESBoundObject, public TESFullName, public TESModel, public BGSPreloadable
{
};
class BGSImpactDataSet : public TESForm, public BGSPreloadable
{
};
class TESEffectShader : public TESForm
{
};
class SpellItem : public TESForm
{
};
class TESSound : public TESBoundObject
{
};
class TESObjectSTAT : public TESBoundObject
{
};
class TESObjectIMOD : public TESBoundObject
{
};
class ModelLoader
{
  public:
    void ProcessModelRequest(TESModel*, int, class QueuedFile*, int, bool, bool, bool);
};
extern ModelLoader* g_modelLoader;
class TES
{
  public:
    static int GetModelResourceType(TESObject*);
};
class TESFormInitFlag : public TESForm
{
  public:
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int);
};
class BGSImpactData : public TESForm
{
  public:
    void ReadTypedData(TESFile*, void*, unsigned short);
};
class ActorValue
{
  public:
    static bool IsSkill(ActorValue__Index);
};
bool FUN_0066eba0(ActorValue__Index);
int Warning(const char*, ...);
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl _alloca(unsigned int);

union SETTING_VALUE
{
    bool b;
    int i;
    float f;
    char* s;
};
class INISettingCollection;
template <class Collection> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
extern SettingT<INISettingCollection> DAT_011c94d0;
#endif
