#ifndef FNV_COMBATFORMULAS_DEPENDENCIES_H
#define FNV_COMBATFORMULAS_DEPENDENCIES_H

#include "combatformulas_decls.h"
#include "combatformulas_actor.h"
#include "combatformulas_weapon.h"
class TESAmmoInitCalls
{
  public:
    void* FUN_00923000();
};
union SETTING_VALUE
{
    float f;
    int i;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
    SETTING_VALUE* Int();
};
class EffectSetting
{
  public:
    TESSound* GetBoltSound();
};
class PathingRequest
{
  public:
    float GetTargetRadius();
};
class MiddleHighProcess
{
  public:
    float GetThirdProcessFloat();
    ActorValue::Index GetWeaponForm();
    char _pdbpad_1[199];
    char DeadDetectList_padc7_padc7_padc7[8];
    char RefListChairBed_padcf_padcf_padcf[8];
    float m_kNinthUnshownMember;
    float m_kEighthUnshownMember;
    bool m_bPackageStateFlag2;
    bool m_bPackageStateFlag;
    bool m_bPackageStateFlag3;
    bool m_bPackageStateFlag4;
    char PackageReference[24];
    char m_kPackageTargetPosition[12];
    int m_ePackageObjectType;
    void* m_pPackageIdleForm;
    bool m_kSecondUnshownMember;
    char _pdbpad_111[3];
    void* pWeapon;
    void* pAmmo;
    char m_pQueuedWeaponFile[4];
    char m_pWeaponData[4];
    bool m_bFirstWeaponFlag;
    bool m_bSecondWeaponFlag;
    bool m_bThirdWeaponFlag;
    bool m_bFourthWeaponFlag;
    bool m_bFifthWeaponFlag;
    bool m_bSixthWeaponFlag;
    bool m_bSeventhWeaponFlag;
    char _pdbpad_12b[1];
    void* m_pActorNode;
    void* m_pActorObject;
    bool m_bFirstActorFlag;
    bool m_bAdditionalActorFlag;
    char _pdbpad_136[2];
    char m_pCharacterController[4];
    char m_cCharacterControllerState;
    unsigned char m_ucFurnitureInteractionState;
    char _pdbpad_13e[2];
    void* m_pFurnitureReference;
    unsigned char m_ucFurnitureMarkerIndex;
    char _pdbpad_145[3];
    char FurnitureMarker[16];
    void* m_pCombatTarget;
    void* m_pEquippedWeapon;
    void* m_pFirstMagicItem;
    void* m_pSecondMagicItem;
    bool m_bWeaponOut;
    char _pdbpad_169[3];
    void* m_pEffectShader;
    float m_fFirstEffectShaderValue;
    float m_fSecondEffectShaderValue;
    void* m_pFaceGenAnimationData;
    bool m_bFirstFaceGenFlag;
    bool m_kSixthUnshownMember;
    bool m_bThirdFaceGenFlag;
    bool m_kSeventhUnshownMember;
    bool m_kFifthUnshownMember;
    char _pdbpad_181[3];
    unsigned int m_uiAnimationStateFlags;
    bool m_bAiming;
    bool m_bAimStateFlag;
    bool m_bCombatStateFlag;
    bool m_bFourthStateFlag;
    unsigned char m_ucProcessState;
    bool m_bEquipStateFlag;
    char _pdbpad_18e[2];
    int m_iIdleState;
    void* m_pCurrentIdleForm;
    float m_fIdleAnimationTime;
    bool m_kThirdUnshownMember;
    bool m_kFourthUnshownMember;
    char _pdbpad_19e[2];
    void* m_pLipSyncAnimation;
    unsigned int m_uiLipSyncState;
    int m_iProjectileCount;
    void* m_pArrowProjectileList;
    char m_kDeferredHideLimbList[8];
    void* m_pActiveEffectList;
    void* m_pMagicTarget;
    void* pCurrentAnimation;
    char m_apAnimGroupSequences[12];
    float m_fAnimationTime;
    float m_fAnimationSpeed;
    unsigned char m_ucAnimationState;
    bool m_bFirstAnimationFlag;
    bool m_bAnimationStateFlag;
    char _pdbpad_1db[1];
    char m_apBodyPartNodes[60];
    void* m_pFirstAttachedObject;
    void* m_pSecondAttachedObject;
    char m_pLightingProperty[4];
    void* m_pBound;
    bool m_kFieldAfterWeaponFlags;
    char _pdbpad_229[1];
    short m_sBoundDataValue;
    unsigned int m_kEleventhUnshownMember;
    void* m_pkPaddedFloatRecordList;
    float m_kTenthUnshownMember;
    float m_fFirstFaceGenValue;
    float m_fSecondFaceGenValue;
    void* m_pData;
    int m_iFaceGenNodeIndex;
    void* m_pFirstFaceGenNode;
    void* m_pSecondFaceGenNode;
    void* m_pFaceGenObject;
    void* m_pAdditionalFaceGenData;
    unsigned int m_uiFaceGenDataFlags;
};
extern SettingT_GameSettingCollection_ DAT_011ce2c0;
extern SettingT_GameSettingCollection_ DAT_011cece8;
extern SettingT_GameSettingCollection_ DAT_011ceef0;
extern SettingT_GameSettingCollection_ DAT_011cf21c;
extern SettingT_GameSettingCollection_ DAT_011cf350;
extern SettingT_GameSettingCollection_ DAT_011cf6c0;
extern SettingT_GameSettingCollection_ DAT_011cf810;
extern SettingT_GameSettingCollection_ DAT_011cf888;
extern SettingT_GameSettingCollection_ DAT_011cfbf0;
extern PlayerCharacter* g_thePlayer;
extern const double runtimeInitializationDouble2;
float GetWeaponHealthConditionMultiplier(float);
float GetArmorConditionFactor(float);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
void FUN_005330e0(float&, float, float);
float RandomFloat(float, float);
void ApplyPerkModifiers(int, Actor*, ...);
class CombatWeaponCritical
{
  public:
    float ProcessActorAction();
};
enum AMMO_EFFECT_TYPE
{
    AMMO_EFFECT_TYPE_AMMO_EFFECT_DAM = 0
};
class TESAmmoEffect
{
  public:
    static float ApplyAmmoEffects(AMMO_EFFECT_TYPE, BSSimpleList<TESAmmoEffect*>*, float);
};
#endif
