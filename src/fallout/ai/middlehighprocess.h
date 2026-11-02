// Reconstructed source: fallout/ai/middlehighprocess.h
// MiddleHighProcess inline accessors (Doc Speech30 aid segment).
//
// Layout note: the MiddleHighProcess/FurnitureMark data members below are
// class comes from the canonical MiddleLowProcess.h chain. The enum below is
// from canonical BaseProcess.h (StopIdleAnimation overrides its slot). Out-of-line NiPointer<bhkCharacterController>
// operations follow the skyobject.h precedent (declared here, defined in a
// separate engine translation unit).
#ifndef FNV_MIDDLEHIGHPROCESS_H
#define FNV_MIDDLEHIGHPROCESS_H


#include "middlehighprocess_vslots.h"
#include "ActorPackageContext.h"
#include "MiddleLowProcess.h"
#include "NiPoint3.h"
#include "layout_support.h"

class Actor;
class ActiveEffect;
class Animation;
class ArrowProjectile;
class BSAnimGroupSequence;
class BSBound;
class ActorSupportClass;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSShaderPPLightingProperty;
class BooleanFloatQuery;
class InventoryStackRecord;
class LipSyncAnimation;
class MagicItem;
class MagicTarget;
class MiddleHighProcess__DeferredHideLimb;
class NiAVObject;
class NiNode;
class TargetDoorController;
class QueuedFile;
class PaddedFloatRecord;
class TESEffectShader;
class TESIdleForm;
class TESObjectWEAP;
class bhkCharacterController;

enum RESET_3D_FLAGS
{
    RESET_3D_FLAGS_RESET_MODEL = 1,
    RESET_3D_FLAGS_RESET_SKIN = 2,
    RESET_3D_FLAGS_RESET_HEAD = 4,
    RESET_3D_FLAGS_RESET_FACE = 8,
    RESET_3D_FLAGS_RESET_SCALE = 16
};

#pragma pack(push, 4)
class FurnitureMark
{
  public:
    NiPoint3 Position;            // +0x0, 12 bytes
    unsigned short m_usMarkerId;  // +0xC, 2 bytes
    unsigned char m_ucFlags;      // +0xE, 1 bytes
    unsigned char layoutPaddingF[1];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FurnitureMark) == 16);
FNV_STATIC_ASSERT(offsetof(FurnitureMark, Position) == 0);
FNV_STATIC_ASSERT(offsetof(FurnitureMark, m_usMarkerId) == 12);
FNV_STATIC_ASSERT(offsetof(FurnitureMark, m_ucFlags) == 14);

// Engine smart-pointer operations used below stay out of line; the PC engine
// bodies are separate functions rather than inlined template code.
template <> class NiPointer<bhkCharacterController>
{
  public:
    bhkCharacterController* m_pObject;
    ~NiPointer();
    operator bhkCharacterController*() const;
    NiPointer& operator=(const NiPointer& apPointer);
};

#pragma pack(push, 4)
class MiddleHighProcess : public MiddleLowProcess
{
  public:
    // base MiddleLowProcess at +0x0, size 200
    BSSimpleList<TESObjectREFR*> m_kReferenceList;           // +0xC8, 8 bytes
    BSSimpleList<TESObjectREFR*> m_kSecondaryReferenceList;  // +0xD0, 8 bytes
    float m_kNinthUnshownMember;                             // +0xD8, 4 bytes
    float m_kEighthUnshownMember;                            // +0xDC, 4 bytes
    bool m_bPackageStateFlag2;                               // +0xE0, 1 bytes
    bool m_bPackageStateFlag;                                // +0xE1, 1 bytes
    bool m_bPackageStateFlag3;                               // +0xE2, 1 bytes
    bool m_bPackageStateFlag4;                               // +0xE3, 1 bytes
    ActorPackageContext PackageReference;                           // +0xE4, 24 bytes
    NiPoint3 m_kPackageTargetPosition;                       // +0xFC, 12 bytes
    PACKAGE_OBJECT_TYPE m_ePackageObjectType;                // +0x108, 4 bytes
    TESIdleForm* m_pPackageIdleForm;                         // +0x10C, 4 bytes
    bool m_kSecondUnshownMember;                             // +0x110, 1 bytes
    unsigned char layoutPadding111[3];
    InventoryStackRecord* pWeapon;                         // +0x114, 4 bytes
    InventoryStackRecord* pAmmo;                           // +0x118, 4 bytes
    NiPointer<QueuedFile> m_pQueuedWeaponFile;   // +0x11C, 4 bytes
    NiPointer<ActorSupportClass> m_pWeaponData;  // +0x120, 4 bytes
    bool m_bFirstWeaponFlag;                     // +0x124, 1 bytes
    bool m_bSecondWeaponFlag;                    // +0x125, 1 bytes
    bool m_bThirdWeaponFlag;                     // +0x126, 1 bytes
    bool m_bFourthWeaponFlag;                    // +0x127, 1 bytes
    bool m_bFifthWeaponFlag;                     // +0x128, 1 bytes
    bool m_bSixthWeaponFlag;                     // +0x129, 1 bytes
    bool m_bSeventhWeaponFlag;                   // +0x12A, 1 bytes
    unsigned char layoutPadding12B[1];
    NiNode* m_pActorNode;         // +0x12C, 4 bytes
    NiAVObject* m_pActorObject;   // +0x130, 4 bytes
    bool m_bFirstActorFlag;       // +0x134, 1 bytes
    bool m_bAdditionalActorFlag;  // +0x135, 1 bytes
    unsigned char layoutPadding136[2];
    NiPointer<bhkCharacterController> m_pCharacterController;  // +0x138, 4 bytes
    char m_cCharacterControllerState;                          // +0x13C, 1 bytes
    unsigned char m_ucFurnitureInteractionState;               // +0x13D, 1 bytes
    unsigned char layoutPadding13E[2];
    TESObjectREFR* m_pFurnitureReference;    // +0x140, 4 bytes
    unsigned char m_ucFurnitureMarkerIndex;  // +0x144, 1 bytes
    unsigned char layoutPadding145[3];
    FurnitureMark FurnitureMarker;     // +0x148, 16 bytes
    Actor* m_pCombatTarget;            // +0x158, 4 bytes
    TESObjectWEAP* m_pEquippedWeapon;  // +0x15C, 4 bytes
    MagicItem* m_pFirstMagicItem;      // +0x160, 4 bytes
    MagicItem* m_pSecondMagicItem;     // +0x164, 4 bytes
    bool m_bWeaponOut;                 // +0x168, 1 bytes
    unsigned char layoutPadding169[3];
    TESEffectShader* m_pEffectShader;                 // +0x16C, 4 bytes
    float m_fFirstEffectShaderValue;                  // +0x170, 4 bytes
    float m_fSecondEffectShaderValue;                 // +0x174, 4 bytes
    BSFaceGenAnimationData* m_pFaceGenAnimationData;  // +0x178, 4 bytes
    bool m_bFirstFaceGenFlag;                         // +0x17C, 1 bytes
    bool m_kSixthUnshownMember;                       // +0x17D, 1 bytes
    bool m_bThirdFaceGenFlag;                         // +0x17E, 1 bytes
    bool m_kSeventhUnshownMember;                     // +0x17F, 1 bytes
    bool m_kFifthUnshownMember;                       // +0x180, 1 bytes
    unsigned char layoutPadding181[3];
    unsigned int m_uiAnimationStateFlags;  // +0x184, 4 bytes
    bool m_bAiming;                        // +0x188, 1 bytes
    bool m_bAimStateFlag;                  // +0x189, 1 bytes
    bool m_bCombatStateFlag;               // +0x18A, 1 bytes
    bool m_bFourthStateFlag;               // +0x18B, 1 bytes
    unsigned char m_ucProcessState;        // +0x18C, 1 bytes
    bool m_bEquipStateFlag;                // +0x18D, 1 bytes
    unsigned char layoutPadding18E[2];
    int m_iIdleState;                 // +0x190, 4 bytes
    TESIdleForm* m_pCurrentIdleForm;  // +0x194, 4 bytes
    float m_fIdleAnimationTime;       // +0x198, 4 bytes
    bool m_kThirdUnshownMember;       // +0x19C, 1 bytes
    bool m_kFourthUnshownMember;      // +0x19D, 1 bytes
    unsigned char layoutPadding19E[2];
    LipSyncAnimation* m_pLipSyncAnimation;                                       // +0x1A0, 4 bytes
    unsigned int m_uiLipSyncState;                                               // +0x1A4, 4 bytes
    int m_iProjectileCount;                                                      // +0x1A8, 4 bytes
    BSSimpleList<ArrowProjectile*>* m_pArrowProjectileList;                      // +0x1AC, 4 bytes
    BSSimpleList<MiddleHighProcess__DeferredHideLimb*> m_kDeferredHideLimbList;  // +0x1B0, 8 bytes
    BSSimpleList<ActiveEffect*>* m_pActiveEffectList;                            // +0x1B8, 4 bytes
    MagicTarget* m_pMagicTarget;                                                 // +0x1BC, 4 bytes
    Animation* pCurrentAnimation;                                                // +0x1C0, 4 bytes
    BSAnimGroupSequence* m_apAnimGroupSequences[3];                              // +0x1C4, 12 bytes
    float m_fAnimationTime;                                                      // +0x1D0, 4 bytes
    float m_fAnimationSpeed;                                                     // +0x1D4, 4 bytes
    unsigned char m_ucAnimationState;                                            // +0x1D8, 1 bytes
    bool m_bFirstAnimationFlag;                                                  // +0x1D9, 1 bytes
    bool m_bAnimationStateFlag;                                                  // +0x1DA, 1 bytes
    unsigned char layoutPadding1DB[1];
    NiNode* m_apBodyPartNodes[15];                              // +0x1DC, 60 bytes
    NiAVObject* m_pFirstAttachedObject;                         // +0x218, 4 bytes
    NiAVObject* m_pSecondAttachedObject;                        // +0x21C, 4 bytes
    NiPointer<BSShaderPPLightingProperty> m_pLightingProperty;  // +0x220, 4 bytes
    BSBound* m_pBound;                                          // +0x224, 4 bytes
    bool m_kFieldAfterWeaponFlags;                              // +0x228, 1 bytes
    unsigned char layoutPadding229[1];
    short m_sBoundDataValue;                               // +0x22A, 2 bytes
    unsigned int m_kEleventhUnshownMember;                 // +0x22C, 4 bytes
    BSSimpleList<PaddedFloatRecord*>* m_pkPaddedFloatRecordList;  // +0x230, 4 bytes
    float m_kTenthUnshownMember;                           // +0x234, 4 bytes
    float m_fFirstFaceGenValue;                            // +0x238, 4 bytes
    float m_fSecondFaceGenValue;                           // +0x23C, 4 bytes
    BooleanFloatQuery* m_pData;                            // +0x240, 4 bytes
    int m_iFaceGenNodeIndex;                               // +0x244, 4 bytes
    BSFaceGenNiNode* m_pFirstFaceGenNode;                  // +0x248, 4 bytes
    BSFaceGenNiNode* m_pSecondFaceGenNode;                 // +0x24C, 4 bytes
    NiAVObject* m_pFaceGenObject;                          // +0x250, 4 bytes
    BooleanFloatQuery* m_pAdditionalFaceGenData;           // +0x254, 4 bytes
    unsigned int m_uiFaceGenDataFlags;                     // +0x258, 4 bytes

    bool ClearProcessStateFlags();
    SIT_SLEEP_STATE GetSitSleepState();
    MagicItem* GetSelectedMagicItem();
    void SetSelectedMagicItem(MagicItem* apSpell);
    void SetMagicTarget(MagicTarget* apTarget);
    bool UpdateIdleAnimation();
    bool ResetAlertState();
    bool GetProcessState();
    bool SetProcessStateFlag();
    bool SetActorAlertState();
    void Assign3DObject(NiAVObject* apNode);
    int GetCurrentProcedure();
    void SetCurrentProcedure(int aiIndex);
    bhkCharacterController* GetPhysicsCharacterController();
    void AssignCharacterController(NiPointer<bhkCharacterController> apController);
    void AddDeferredHideLimb(TargetDoorController* apObject);
    void SetFaceAnimationData(TargetDoorController* apObject);
    KNOCK_STATE_ENUM StopIdleAnimation();
    bool IsProcessStateInitialized();
    void InitializeProcessState();
    void ResetActorModel(RESET_3D_FLAGS aeFlags);
    void ClearDetectionFlag();
    BSSimpleList<ArrowProjectile*>* GetArrowProjectiles();
    bool IsAlert();
    bool IsHoldingWeapon();
    void SetSustainedState(bool abSustained);
    void SetIdleAnimationPlayed(bool abPlayed);
    void SetPlayedState(bool abPlayed);
    bool WasIdleAnimationPlayed();
    LipSyncAnimation* GetLipSyncAnimationData();
    float GetAnimationElapsedTime();
    void AdvanceMovementTimer(float afDelta);
    float GetAnimationRemainingTime();
    void SetKnockdownStage(int aiStage);
    void AttachFaceGenerationNode(BSFaceGenNiNode* apNode);
    BSFaceGenNiNode* GetFaceGenHeadNode();
    void SetFaceGenHeadNode(BSFaceGenNiNode* apNode);
    NiAVObject* GetAnimationObject();
    NiAVObject* GetActorSceneObject();
    NiAVObject* GetSceneRoot();
    void SetCurrentIdle(TESIdleForm* apIdle);
    BooleanFloatQuery* RefreshActorRuntimeData();
    void SetAnimationNode(NiAVObject* apAnims);
    BSFaceGenNiNode* GetFacialAnimationNode();
    bool IsActorInCombat();
    void SetBoundingBox(BSBound* apBound);
    bool IsAnimationPlaying();
    Animation* GetAnimation();
    void AssignEffectShader(TESEffectShader* apShader);
    void UpdateEffectShader(unsigned int auiTime);
    float GetLightIntensity();
    BSBound* GetObjectBounds();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MiddleHighProcess) == 604);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kReferenceList) == 200);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kSecondaryReferenceList) == 208);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kNinthUnshownMember) == 216);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kEighthUnshownMember) == 220);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bPackageStateFlag2) == 224);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bPackageStateFlag) == 225);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bPackageStateFlag3) == 226);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bPackageStateFlag4) == 227);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, PackageReference) == 228);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kPackageTargetPosition) == 252);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_ePackageObjectType) == 264);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pPackageIdleForm) == 268);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kSecondUnshownMember) == 272);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, pWeapon) == 276);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, pAmmo) == 280);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pQueuedWeaponFile) == 284);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pWeaponData) == 288);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bFirstWeaponFlag) == 292);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bSecondWeaponFlag) == 293);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bThirdWeaponFlag) == 294);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bFourthWeaponFlag) == 295);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bFifthWeaponFlag) == 296);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bSixthWeaponFlag) == 297);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bSeventhWeaponFlag) == 298);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pActorNode) == 300);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pActorObject) == 304);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bFirstActorFlag) == 308);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bAdditionalActorFlag) == 309);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pCharacterController) == 312);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_cCharacterControllerState) == 316);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_ucFurnitureInteractionState) == 317);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pFurnitureReference) == 320);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_ucFurnitureMarkerIndex) == 324);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, FurnitureMarker) == 328);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pCombatTarget) == 344);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pEquippedWeapon) == 348);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pFirstMagicItem) == 352);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pSecondMagicItem) == 356);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bWeaponOut) == 360);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pEffectShader) == 364);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_fFirstEffectShaderValue) == 368);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_fSecondEffectShaderValue) == 372);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pFaceGenAnimationData) == 376);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bFirstFaceGenFlag) == 380);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kSixthUnshownMember) == 381);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bThirdFaceGenFlag) == 382);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kSeventhUnshownMember) == 383);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kFifthUnshownMember) == 384);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_uiAnimationStateFlags) == 388);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bAiming) == 392);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bAimStateFlag) == 393);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bCombatStateFlag) == 394);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bFourthStateFlag) == 395);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_ucProcessState) == 396);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bEquipStateFlag) == 397);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_iIdleState) == 400);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pCurrentIdleForm) == 404);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_fIdleAnimationTime) == 408);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kThirdUnshownMember) == 412);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kFourthUnshownMember) == 413);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pLipSyncAnimation) == 416);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_uiLipSyncState) == 420);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_iProjectileCount) == 424);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pArrowProjectileList) == 428);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kDeferredHideLimbList) == 432);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pActiveEffectList) == 440);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pMagicTarget) == 444);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, pCurrentAnimation) == 448);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_apAnimGroupSequences) == 452);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_fAnimationTime) == 464);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_fAnimationSpeed) == 468);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_ucAnimationState) == 472);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bFirstAnimationFlag) == 473);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_bAnimationStateFlag) == 474);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_apBodyPartNodes) == 476);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pFirstAttachedObject) == 536);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pSecondAttachedObject) == 540);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pLightingProperty) == 544);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pBound) == 548);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kFieldAfterWeaponFlags) == 552);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_sBoundDataValue) == 554);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kEleventhUnshownMember) == 556);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pkPaddedFloatRecordList) == 560);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_kTenthUnshownMember) == 564);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_fFirstFaceGenValue) == 568);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_fSecondFaceGenValue) == 572);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pData) == 576);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_iFaceGenNodeIndex) == 580);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pFirstFaceGenNode) == 584);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pSecondFaceGenNode) == 588);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pFaceGenObject) == 592);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_pAdditionalFaceGenData) == 596);
FNV_STATIC_ASSERT(offsetof(MiddleHighProcess, m_uiFaceGenDataFlags) == 600);

// @fnv 0x008d8120
MagicItem* MiddleHighProcess::GetSelectedMagicItem()
{
    return m_pFirstMagicItem;
}

// @fnv 0x008d8140
void MiddleHighProcess::SetSelectedMagicItem(MagicItem* apSpell)
{
    m_pFirstMagicItem = apSpell;
}

// @fnv 0x008d8180
void MiddleHighProcess::SetMagicTarget(MagicTarget* apTarget)
{
    m_pMagicTarget = apTarget;
}

// @fnv 0x008d81a0
bool MiddleHighProcess::UpdateIdleAnimation()
{
    return m_bWeaponOut;
}

// @fnv 0x008d8220
bool MiddleHighProcess::ResetAlertState()
{
    return m_bFirstWeaponFlag;
}

// @fnv 0x008d8270
bool MiddleHighProcess::GetProcessState()
{
    return m_bFourthWeaponFlag;
}

// @fnv 0x008d8290
bool MiddleHighProcess::SetProcessStateFlag()
{
    return m_bFifthWeaponFlag;
}

// @fnv 0x008d82d0
bool MiddleHighProcess::SetActorAlertState()
{
    return m_bSeventhWeaponFlag;
}

// @fnv 0x008d82f0
void MiddleHighProcess::Assign3DObject(NiAVObject* apNode)
{
    m_pActorObject = apNode;
}

// @fnv 0x008d8420
int MiddleHighProcess::GetCurrentProcedure()
{
    return PackageReference.GetProcedureIndex();
}

// @fnv 0x008d8440
void MiddleHighProcess::SetCurrentProcedure(int aiIndex)
{
    PackageReference.AddToProcedureIndex(aiIndex);
}

// @fnv 0x008d8480
bhkCharacterController* MiddleHighProcess::GetPhysicsCharacterController()
{
    return m_pCharacterController;
}

// @fnv 0x008d84a0
void MiddleHighProcess::AssignCharacterController(NiPointer<bhkCharacterController> apController)
{
    m_pCharacterController = apController;
}

// @fnv 0x008d8500
void MiddleHighProcess::AddDeferredHideLimb(TargetDoorController* apObject)
{
    m_pDetectionData60 = apObject;
}

// @fnv 0x00407800
void MiddleHighProcess::SetFaceAnimationData(TargetDoorController* apObject)
{
    m_pDetectionData64 = apObject;
}

// @fnv 0x008d8540
KNOCK_STATE_ENUM MiddleHighProcess::StopIdleAnimation()
{
    return (KNOCK_STATE_ENUM)m_cCharacterControllerState;
}

// @fnv 0x008d8600
bool MiddleHighProcess::IsProcessStateInitialized()
{
    return m_bFirstFaceGenFlag;
}

// @fnv 0x008d8680
void MiddleHighProcess::InitializeProcessState()
{
    m_pFaceGenAnimationData = 0;
}

// @fnv 0x008d8740
void MiddleHighProcess::ResetActorModel(RESET_3D_FLAGS aeFlags)
{
    m_ucProcessState |= aeFlags;
}

// @fnv 0x008d87a0
void MiddleHighProcess::ClearDetectionFlag()
{
    m_ucProcessState = 0;
}

// @fnv 0x008d8800
BSSimpleList<ArrowProjectile*>* MiddleHighProcess::GetArrowProjectiles()
{
    return m_pArrowProjectileList;
}

// @fnv 0x008d8840
bool MiddleHighProcess::IsAlert()
{
    return m_kFieldAfterWeaponFlags;
}

// @fnv 0x008d8860
bool MiddleHighProcess::IsHoldingWeapon()
{
    return m_bFirstAnimationFlag;
}

// @fnv 0x008d8880
void MiddleHighProcess::SetSustainedState(bool abSustained)
{
    m_bFirstAnimationFlag = abSustained;
}

// @fnv 0x008d88a0
void MiddleHighProcess::SetIdleAnimationPlayed(bool abPlayed)
{
    m_kThirdUnshownMember = abPlayed;
}

// @fnv 0x008d88e0
void MiddleHighProcess::SetPlayedState(bool abPlayed)
{
    m_kFourthUnshownMember = abPlayed;
}

// @fnv 0x008d8900
bool MiddleHighProcess::WasIdleAnimationPlayed()
{
    return m_kFourthUnshownMember;
}

// @fnv 0x008d8920
LipSyncAnimation* MiddleHighProcess::GetLipSyncAnimationData()
{
    return m_pLipSyncAnimation;
}

// @fnv 0x008d89c0
float MiddleHighProcess::GetAnimationElapsedTime()
{
    return m_fFirstFaceGenValue;
}

// @fnv 0x008d89e0
void MiddleHighProcess::AdvanceMovementTimer(float afDelta)
{
    m_fSecondFaceGenValue = afDelta;
}

// @fnv 0x008d8a00
float MiddleHighProcess::GetAnimationRemainingTime()
{
    return m_fSecondFaceGenValue;
}

// @fnv 0x008d8a80
void MiddleHighProcess::SetKnockdownStage(int aiStage)
{
    m_iFaceGenNodeIndex = aiStage;
}

// @fnv 0x008d8aa0
void MiddleHighProcess::AttachFaceGenerationNode(BSFaceGenNiNode* apNode)
{
    m_pFirstFaceGenNode = apNode;
}

// @fnv 0x008d8ac0
BSFaceGenNiNode* MiddleHighProcess::GetFaceGenHeadNode()
{
    return m_pSecondFaceGenNode;
}

// @fnv 0x008d8ae0
void MiddleHighProcess::SetFaceGenHeadNode(BSFaceGenNiNode* apNode)
{
    m_pSecondFaceGenNode = apNode;
}

// @fnv 0x008d8b00
NiAVObject* MiddleHighProcess::GetAnimationObject()
{
    return m_pFaceGenObject;
}

// @fnv 0x008d8c20
NiAVObject* MiddleHighProcess::GetActorSceneObject()
{
    return m_pSecondAttachedObject;
}

// @fnv 0x00502430
NiAVObject* MiddleHighProcess::GetSceneRoot()
{
    return m_pActorObject;
}

// @fnv 0x00505e50
void MiddleHighProcess::SetCurrentIdle(TESIdleForm* apIdle)
{
    m_pPackageIdleForm = apIdle;
}

// @fnv 0x00521630
BooleanFloatQuery* MiddleHighProcess::RefreshActorRuntimeData()
{
    return m_pData;
}

// @fnv 0x00521710
void MiddleHighProcess::SetAnimationNode(NiAVObject* apAnims)
{
    m_pFaceGenObject = apAnims;
}

// @fnv 0x005224a0
BSFaceGenNiNode* MiddleHighProcess::GetFacialAnimationNode()
{
    return m_pFirstFaceGenNode;
}

// @fnv 0x00566950
bool MiddleHighProcess::IsActorInCombat()
{
    return m_bEquipStateFlag;
}

// @fnv 0x005c8a30
void MiddleHighProcess::SetBoundingBox(BSBound* apBound)
{
    m_pBound = apBound;
}

// @fnv 0x005ce8f0
bool MiddleHighProcess::IsAnimationPlaying()
{
    return m_bSecondWeaponFlag;
}

// @fnv 0x00602150
Animation* MiddleHighProcess::GetAnimation()
{
    return pCurrentAnimation;
}

// @fnv 0x007ac9d0
void MiddleHighProcess::AssignEffectShader(TESEffectShader* apShader)
{
    m_pEffectShader = apShader;
}

// @fnv 0x0087d7d0
void MiddleHighProcess::UpdateEffectShader(unsigned int auiTime)
{
    m_uiLipSyncState = auiTime;
}

// @fnv 0x008f7710
float MiddleHighProcess::GetLightIntensity()
{
    return m_fFirstEffectShaderValue;
}

// @fnv 0x009ee020
BSBound* MiddleHighProcess::GetObjectBounds()
{
    return m_pBound;
}

// @fnv 0x008d8310
bool MiddleHighProcess::ClearProcessStateFlags()
{
    return reinterpret_cast<MiddleHighProcessVirtualSlots*>(this)->GetInterruptPackage();
}

// @fnv 0x008d8b20
SIT_SLEEP_STATE MiddleHighProcess::GetSitSleepState()
{
    if ((reinterpret_cast<MiddleHighProcessVirtualSlots*>(this)->GetQueuedIdleFlags() & 8) &&
        (m_ucFurnitureInteractionState == 4 || m_ucFurnitureInteractionState == 9))
        return (SIT_SLEEP_STATE)(m_ucFurnitureInteractionState + 1);
    else
        return (SIT_SLEEP_STATE)m_ucFurnitureInteractionState;
}

#endif
