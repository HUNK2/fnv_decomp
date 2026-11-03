// fallout_shared/facegen/bsfacegenanimationdata.h: declares RotationValues, MiddleHighProcess, BSFaceGenAnimationData
#ifndef FNV_BSFACEGENANIMATIONDATA_H
#define FNV_BSFACEGENANIMATIONDATA_H

#include "bsfacegenanimationdata_types_BS_FACEGEN_EXPRESSION.h"
#include "bsfacegenanimationdata_types_BS_FACEGEN_PHONEME.h"
#include "bsfacegenanimationdata_types_BS_FACEGEN_CUSTOM_MORPH.h"
class RotationValues
{
  public:
    float BSFaceGenKeyframeMultiple_GetQuantity(unsigned int index);
    char storage[0x34];
};
class MiddleHighProcess
{
  public:
    char prefix_pad0[200];
    char m_kReferenceList[8];
    char m_kSecondaryReferenceList[8];
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
    char prefix_pad111[3];
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
    char prefix_pad12b[1];
    void* m_pActorNode;
    void* m_pActorObject;
    bool m_bFirstActorFlag;
    bool m_bAdditionalActorFlag;
    char prefix_pad136[2];
    char m_pCharacterController[4];
    char m_cCharacterControllerState;
    unsigned char m_ucFurnitureInteractionState;
    char prefix_pad13e[2];
    void* m_pFurnitureReference;
    unsigned char m_ucFurnitureMarkerIndex;
    char prefix_pad145[3];
    char FurnitureMarker[16];
    void* m_pCombatTarget;
    void* m_pEquippedWeapon;
    void* m_pFirstMagicItem;
    void* m_pSecondMagicItem;
    bool m_bWeaponOut;
    char prefix_pad169[3];
    void* m_pEffectShader;
    float m_fFirstEffectShaderValue;
    float m_fSecondEffectShaderValue;
    void* m_pFaceGenAnimationData;
    bool m_bFirstFaceGenFlag;
    bool m_kSixthUnshownMember;
    bool m_bThirdFaceGenFlag;
    bool m_kSeventhUnshownMember;
    bool m_kFifthUnshownMember;
    char prefix_pad181[3];
    unsigned int m_uiAnimationStateFlags;
    bool m_bAiming;
    bool m_bAimStateFlag;
    bool m_bCombatStateFlag;
    bool isSummonedCreature;
    bool BeginIdleAnimation();
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
class BSFaceGenAnimationData
{
  public:
    char prefix[0x74];
    RotationValues expressionValues;
    char expressionTail[0x34];
    RotationValues phonemeValues;
    RotationValues customMorphValues;
    char morphTail[0x47];
    bool forceUpdate;
    bool mustUpdate;
    bool flag18d;
    bool dead;
    bool GetDead();
    bool GetChanged();
    void SetModified(bool value);
    float GetExpressionWeight(BS_FACEGEN_EXPRESSION expression);
    float GetPhonemeWeight(BS_FACEGEN_PHONEME phoneme);
    float GetCustomMorphWeight(BS_FACEGEN_CUSTOM_MORPH morph);
};
// @fnv 0x00649b80
bool MiddleHighProcess::BeginIdleAnimation()
{
    return isSummonedCreature;
}
// @fnv 0x00649bc0
bool BSFaceGenAnimationData::GetDead()
{
    return dead;
}
// @fnv 0x008d87e0
bool BSFaceGenAnimationData::GetChanged()
{
    return mustUpdate;
}
// @fnv 0x00649ba0
void BSFaceGenAnimationData::SetModified(bool value)
{
    mustUpdate = value;
}
// @fnv 0x006499e0
float BSFaceGenAnimationData::GetExpressionWeight(BS_FACEGEN_EXPRESSION expression)
{
    return expression < BS_FACEGEN_EXPRESSION_BS_FG_EXPRESSION_COUNT ? expressionValues.BSFaceGenKeyframeMultiple_GetQuantity(expression) : 0.0f;
}
// @fnv 0x00649aa0
float BSFaceGenAnimationData::GetPhonemeWeight(BS_FACEGEN_PHONEME phoneme)
{
    return phoneme < BS_FACEGEN_PHONEME_BS_FG_PHONEME_COUNT ? phonemeValues.BSFaceGenKeyframeMultiple_GetQuantity(phoneme) : 0.0f;
}
// @fnv 0x00649b10
float BSFaceGenAnimationData::GetCustomMorphWeight(BS_FACEGEN_CUSTOM_MORPH morph)
{
    return morph < BS_FACEGEN_CUSTOM_MORPH_BS_FG_CUSTOM_MORPH_COUNT ? customMorphValues.BSFaceGenKeyframeMultiple_GetQuantity(morph) : 0.0f;
}
#endif
