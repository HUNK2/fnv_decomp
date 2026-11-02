// Source layout: BaseProcess. PC corrections are in generate_headers.py.
#ifndef FNV_BASEPROCESS_H
#define FNV_BASEPROCESS_H
#include "layout_support.h"
#include "ActorPackageContext.h"
class AnimIdle;
class Animation;
class ArrowProjectile;
class BGSBodyPartData;
class BGSSaveFormBuffer;
class BSAnimGroupSequence;
class BSBound;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSShaderPPLightingProperty;
class Crime;
class DetectionEvent;
class DetectionViewData;
class FurnitureMark;
class BooleanFloatQuery;
class KFModel;
class LipSyncAnimation;
class MuzzleFlash;
class NiAVObject;
class NiControllerManager;
class PathingAvoidNodeArray;
class Projectile;
class TESEffectShader;
class TESIdleForm;
class TESObjectSTAT;
class TESObjectWEAP;
class WadingWaterData;
class bhkCharacterController;
enum KNOCK_STATE_ENUM
{
    KNOCK_STATE_ENUM_KNOCK_STATE_NORMAL = 0,
    KNOCK_STATE_ENUM_KNOCK_STATE_EXPLODE = 1,
    KNOCK_STATE_ENUM_KNOCK_STATE_EXPLODE_LEAD_IN = 2,
    KNOCK_STATE_ENUM_KNOCK_STATE_OUT = 3,
    KNOCK_STATE_ENUM_KNOCK_STATE_OUT_LEAD_IN = 4,
    KNOCK_STATE_ENUM_KNOCK_STATE_QUEUED = 5,
    KNOCK_STATE_ENUM_KNOCK_STATE_GET_UP = 6
};
#pragma pack(push, 4)
class BaseProcess
{
  public:
    ActorPackageContext m_kProcessData;                                                              // +0x4
    float m_fValue2;                                                                          // +0x1C
    float m_fValue1;                                                                          // +0x20
    unsigned int m_uiStateFlags;                                                              // +0x24
    PROCESS_TYPE m_eProcessType;                                                              // +0x28
    CachedValues* m_pCachedValues;                                                            // +0x2C
    virtual ~BaseProcess();                                                                   // slot 0x0
    virtual void Copy(BaseProcess*);                                                          // slot 0x1
    virtual void SetReferenceTarget(TESObjectREFR*);                                          // slot 0x2
    virtual void Update(MobileObject*);                                                       // slot 0x4
    virtual void Update(MobileObject*, float);                                                // slot 0x3
    virtual void SetMobileObjectState(MobileObject*, bool);                                   // slot 0x5
    virtual const NiPoint3 GetActorWorldPosition(Actor*);                                     // slot 0x6
    virtual NiPoint3 GetActorNodePosition(Actor*, int);                                       // slot 0x7
    virtual float GetActorValueAtIndex(Actor*, int);                                          // slot 0x8
    virtual bool CanProcessActor(Actor*, bool);                                               // slot 0x9
    virtual void ResetPackageState();                                                         // slot 0xA
    virtual bool IsLowProcessStateValid();                                                    // slot 0xB
    virtual int GetPackedStateBits0To8();                                                     // slot 0xC
    virtual int GetPackedStateBits9To12();                                                    // slot 0xD
    virtual int GetPackedStateBits13To26();                                                   // slot 0xE
    virtual void SetProcessInteger(int);                                                      // slot 0xF
    virtual int GetProcessInteger();                                                          // slot 0x10
    virtual bool StartIdleAnimation(MobileObject*, TESIdleForm*, int, bool, bool, bool);      // slot 0x11
    virtual void ClearIdleAnimation();                                                        // slot 0x12
    virtual MagicItem* GetCurrentMagicItem();                                                 // slot 0x13
    virtual void SetCurrentMagicItem(MagicItem*);                                             // slot 0x14
    virtual void SetActorMagicItem(Actor*, int);                                              // slot 0x15
    virtual void InitializeProcessState();                                                    // slot 0x16
    virtual void UpdateHealthBar(Actor*);                                                     // slot 0x17
    virtual bool GetIdleDoneOnce();                                                           // slot 0x18
    virtual void MarkIdleDoneOnce(bool);                                                      // slot 0x19
    virtual bool ShouldProcessActor(Actor*);                                                  // slot 0x1A
    virtual void ProcessActorGroupState(Actor*);                                        // slot 0x1B
    virtual bool CanUsePlayerAction(Actor*);                                                  // slot 0x1C
    virtual bool CanPerformActorAction(Actor*, float);                                        // slot 0x1D
    virtual bool IsAsleep();                                                                  // slot 0x1E
    virtual void ProcessSandman(Actor*);                                                      // slot 0x1F
    virtual void ProcessCannibal(Actor*);                                                     // slot 0x20
    virtual void ProcessFurniture(Actor*);                                                    // slot 0x21
    virtual void SetCombatEnabled(bool);                                                      // slot 0x22
    virtual bool FindPackageTarget(Actor*);                                                   // slot 0x23
    virtual TESObjectREFR* GetPackageLocationReference(Actor*, bool);                         // slot 0x24
    virtual TESObjectREFR* GetActorTargetReference(Actor*, bool);                             // slot 0x25
    virtual NiPoint3 GetActorTargetPosition(Actor*, bool);                                    // slot 0x26
    virtual TESObjectCELL* GetTargetCell(Actor*);                                             // slot 0x27
    virtual TESWorldSpace* GetTargetWorldSpace(Actor*);                                       // slot 0x28
    virtual float GetTargetDistance(Actor*);                                                  // slot 0x29
    virtual MobileObject* GetMobileObject();                                                  // slot 0x2A
    virtual void AdvanceProcess();                                                            // slot 0x2B
    virtual bool EvaluateActorPackage(Actor*, TESPackage*, bool);                             // slot 0x2C
    virtual bool FindPackageToEvaluate(Actor*, TESPackage*&);                                 // slot 0x2D
    virtual float GetFirstProcessFloat();                                                     // slot 0x2E
    virtual void SetCurrentSpeed(float);                                                      // slot 0x2F
    virtual void EvaluateCurrentPackage(Actor*);                                              // slot 0x30
    virtual void SelectPackage(Actor*, bool);                                                 // slot 0x31
    virtual void SetPackageForActor(Actor*, TESPackage*, bool);                               // slot 0x32
    virtual bool HasInterruptPackage();                                                       // slot 0x33
    virtual void SetEssentialFlag(bool);                                                      // slot 0x34
    virtual void PlayRandomIdle(Actor*);                                                      // slot 0x35
    virtual void ProcessActorIdle(Actor*);                                                    // slot 0x36
    virtual void PlayIdleAnimation();                                                         // slot 0x37
    virtual void ClearAnimationState();                                                       // slot 0x38
    virtual float GetEssentialDownTimer();                                                    // slot 0x39
    virtual void SetEssentialDownTimer(float);                                                // slot 0x3A
    virtual void ResetEssentialDownTimer();                                                   // slot 0x3B
    virtual DetectionViewData* FindDetectionRecord(Actor*, int, bool, int, int, bool, bool);  // slot 0x3C
    virtual BSSimpleList<DetectionViewData*>* GetDetectionRecords(Actor*);                    // slot 0x3D
    virtual DetectionEvent* FindDetectionEventForActor(Actor*);                               // slot 0x3E
    virtual void AddDetectionEvent(Actor*, NiPoint3, int, int, TESObjectREFR*);               // slot 0x3F
    virtual void RemoveDetectionEvent();                                                      // slot 0x40
    virtual void ClearDetectionEvents();                                                      // slot 0x41
    virtual float GetWeaponScore();                                                           // slot 0x42
    virtual void SetWeaponScore(float);                                                       // slot 0x43
    virtual bool HasCaughtPlayerPickpocketing();                                              // slot 0x44
    virtual void SetIsWeaponReady(bool);                                                      // slot 0x45
    virtual void SetAnimationComplete(bool);                                                  // slot 0x46
    virtual bool IsMovementComplete();                                                        // slot 0x47
    virtual void SetCurrentMovementComplete(bool);                                            // slot 0x48
    virtual bool GetCurrentMovementComplete();                                                // slot 0x49
    virtual TESObjectREFR* GetTarget();                                                       // slot 0x4A
    virtual void SetTarget(TESObjectREFR*);                                                   // slot 0x4B
    virtual TESObjectREFR* GetDoor();                                                         // slot 0x4C
    virtual void SetDoor(TESObjectREFR*);                                                     // slot 0x4D
    virtual void AddDeferredHideLimb(TargetDoorController*);                                      // slot 0x4E
    virtual TargetDoorController* GetObjectToAcquire();                                           // slot 0x4F
    virtual void SetFaceAnimationData(TargetDoorController*);                                     // slot 0x50
    virtual BSFaceGenAnimationData* GetActorFaceGenData(Actor*);                              // slot 0x51
    virtual InventoryStackRecord* GetActiveWeapon();                                                    // slot 0x52
    virtual InventoryStackRecord* GetCurrentAmmo();                                                     // slot 0x53
    virtual bool CanFireWeapon();                                                             // slot 0x54
    virtual void SetAiming(bool);                                                             // slot 0x55
    virtual int GetPackageObjectType();                                                       // slot 0x56
    virtual void SetPackageObjectType(int);                                                   // slot 0x57
    virtual bool SetCurrentArmor(InventoryStackRecord*, NiNode*, bool);                                 // slot 0x58
    virtual bool SetCurrentTorch(InventoryStackRecord*);                                                // slot 0x59
    virtual bool SetCurrentAmmunition(InventoryStackRecord*);                                           // slot 0x5A
    virtual bool SetCurrentShield(InventoryStackRecord*);                                               // slot 0x5B
    virtual void UpdateEquippedItems(Actor*);                                                 // slot 0x5C
    virtual bool IsItemQueued(TESBoundObject*, ExtraDataList*, bool);                         // slot 0x5D
    virtual void ProcessEquipmentRequest(Actor*, bool, TESBoundObject*, int, ExtraDataList*, bool, bool, bool, bool,
                                         bool, bool);                                             // slot 0x5E
    virtual void SetEquippedItem(TESBoundObject*, ExtraDataList*);                                // slot 0x5F
    virtual void ClearQueuedEquipItems();                                                         // slot 0x60
    virtual NiAVObject* GetSceneRoot();                                                           // slot 0x61
    virtual void Assign3DObject(NiAVObject*);                                                     // slot 0x62
    virtual void SetAnimationControllerManager(NiControllerManager*, NiNode*);                                // slot 0x63
    virtual NiNode* GetActorRootNode(BipedAnim*);                                                 // slot 0x64
    virtual NiNode* GetWeaponAttachNode(BipedAnim*);                                              // slot 0x65
    virtual NiNode* GetShieldBone(BipedAnim*);                                                    // slot 0x66
    virtual NiNode* GetQuiverBone(BipedAnim*);                                                    // slot 0x67
    virtual NiNode* GetTorchAttachNode(BipedAnim*);                                               // slot 0x68
    virtual NiNode* GetLeftWeaponBone(BipedAnim*);                                                // slot 0x69
    virtual bool ResetAlertState();                                                               // slot 0x6A
    virtual bool IsAnimationPlaying();                                                            // slot 0x6B
    virtual bool IsAnimationActive();                                                             // slot 0x6C
    virtual bool IsAnimationSequenceActive();                                                     // slot 0x6D
    virtual Animation* GetAnimation();                                                            // slot 0x6E
    virtual bool IsAnimationStateActive();                                                        // slot 0x6F
    virtual void SetAnimationStateActive(bool);                                                   // slot 0x70
    virtual bool IsProcessTaskComplete();                                                                // slot 0x71
    virtual void SetProcessTaskComplete(bool);                                                    // slot 0x72
    virtual void PlayAnimation(bool, BipedAnim*, Animation*, Actor*);                             // slot 0x73
    virtual void SetCurrentBoundObject(TESBoundObject*);                                          // slot 0x74
    virtual TESBoundObject* GetCurrentBoundObject();                                              // slot 0x75
    virtual void RunActorProcessing(Actor*);                                                      // slot 0x76
    virtual void RefreshActorMovement(Actor*, bool);                                              // slot 0x77
    virtual float GetProcessBlendAmount();                                                        // slot 0x78
    virtual void SetAnimationTimer(float);                                                        // slot 0x79
    virtual void SetLocomotionSpeed(float);                                                       // slot 0x7A
    virtual bool IsProcessConditionMet();                                                         // slot 0x7B
    virtual void SelectActorCombatTarget(Actor*);                                                 // slot 0x7C
    virtual bool IsCombatTargetForActor(Actor*, Actor*);                                          // slot 0x7D
    virtual bool CanAttackTarget(Actor*, Actor*);                                                 // slot 0x7E
    virtual bool IsActorTargetValid(Actor*, Actor*);                                              // slot 0x7F
    virtual bool IsCurrentPackageTarget(Actor*);                                                  // slot 0x80
    virtual bool IsValidCombatTarget(Actor*, Actor*);                                             // slot 0x81
    virtual float GetDistanceBetweenActors(Actor*, Actor*);                                       // slot 0x82
    virtual TESPackage* GetRunOncePackage();                                                      // slot 0x83
    virtual void AssignRunOncePackage(TESPackage*, MobileObject*);                                // slot 0x84
    virtual void StopRunOncePackage();                                                            // slot 0x85
    virtual void SetRunOncePackageIndex(int);                                                     // slot 0x86
    virtual int GetCurrentProcedure();                                                            // slot 0x87
    virtual void SetCurrentProcedure(int);                                                        // slot 0x88
    virtual void ClearDialogueItems();                                                            // slot 0x89
    virtual bool IsPackageRunningForActor(Actor*);                                                // slot 0x8A
    virtual TESPackage* GetCurrentPackage();                                                      // slot 0x8B
    virtual void SetCurrentPackageAndTarget(TESPackage*, MobileObject*);                          // slot 0x8C
    virtual void StopPackage();                                                                   // slot 0x8D
    virtual void SetPackageInfoState(int);                                                   // slot 0x8E
    virtual int GetPackageState();                                                                // slot 0x8F
    virtual void SetPackageExecutionState(int);                                                   // slot 0x90
    virtual void ResetCurrentPackage();                                                           // slot 0x91
    virtual DialogueItem* GetCurrentDialogueItem();                                               // slot 0x92
    virtual void SetCurrentDialogueItem(DialogueItem*);                                           // slot 0x93
    virtual void MoveToPosition(Actor*, NiPoint3, float, float, TESObjectREFR*, TESObjectSTAT*);  // slot 0x94
    virtual PathingAvoidNodeArray* GetPathingAvoidNodeArray(Actor*);                              // slot 0x95
    virtual bool IsReferenceAvoided(TESObjectREFR*);                                              // slot 0x96
    virtual void SetAnimationTime(float);                                                         // slot 0x97
    virtual void SetDetectionTarget(TESObjectREFR*);                                          // slot 0x98
    virtual float GetDetectionProgress();                                                         // slot 0x99
    virtual void SetDetectionLevel(float);                                                        // slot 0x9A
    virtual void ClearCurrentTarget();                                                            // slot 0x9B
    virtual ActorPackageData* GetRunOncePackageData();                                            // slot 0x9C
    virtual ActorPackageData* GetCurrentPackageData();                                            // slot 0x9D
    virtual ActorPackageContext* GetCurrentProcessData();                                                // slot 0x9E
    virtual TESPackage* GetOneTimePackage();                                                      // slot 0x9F
    virtual int GetPackageInfoValue();                                                            // slot 0xA0
    virtual void SetAnimationState(int);                                                          // slot 0xA1
    virtual void SetProcessTarget(MobileObject*, int);                                            // slot 0xA2
    virtual bhkCharacterController* GetPhysicsCharacterController();                              // slot 0xA3
    virtual void AssignCharacterController(NiPointer<bhkCharacterController>);                    // slot 0xA4
    virtual void StopActorMovement(Actor*);                                                       // slot 0xA5
    virtual void UpdateActorPackage(Actor*, bool, int, bool);                                     // slot 0xA6
    virtual void EvaluatePackage(Actor*, bool, bool, int);                                        // slot 0xA7
    virtual void ProcessFlee(Actor*);                                                             // slot 0xA8
    virtual void ProcessDialogueTopic(Actor*, TESTopic*, bool, bool, bool, bool);                 // slot 0xA9
    virtual void StartActorInteraction(Actor*);                                                   // slot 0xAA
    virtual void UpdateActorInteraction(Actor*);                                                  // slot 0xAB
    virtual bool IsActorProcessable(Actor*);                                                      // slot 0xAC
    virtual bool IsFurnitureType(TESObjectREFR*, unsigned int);                                   // slot 0xAD
    virtual bool CanDetectActor(Actor*);                                                          // slot 0xAE
    virtual void UpdateActorStateWithOptions(Actor*, bool, bool, int, bool);                                    // slot 0xAF
    virtual WadingWaterData* GetWadingWaterData();                                                // slot 0xB0
    virtual void SetActorDetectionLevel(Actor*, int);                                             // slot 0xB1
    virtual void SetDetectionTimer(float);                                                        // slot 0xB2
    virtual bool IsActorVisibleToActor(Actor*, Actor*, int, bool);                                // slot 0xB3
    virtual bool IsActorDetected(Actor*, Actor*, int);                                            // slot 0xB4
    virtual int GetDetectionCount(Actor*, int);                                                   // slot 0xB5
    virtual bool IsDetectionEnabled();                                                            // slot 0xB6
    virtual void SetActorProcessEnabled(bool);                                                    // slot 0xB7
    virtual void SetActorProcessTime(Actor*, float);                                              // slot 0xB8
    virtual int GetActorReferenceState(Actor*, TESObjectREFR*);                                   // slot 0xB9
    virtual DIALOGUE_EMOTION GetCurrentDialogueEmotion();                                         // slot 0xBA
    virtual void SetDialogueEmotion(DIALOGUE_EMOTION);                                            // slot 0xBB
    virtual void RunDetection(Actor*, float);                                                     // slot 0xBC
    virtual float GetDetectionStrength();                                                         // slot 0xBD
    virtual void ResetDetectionState();                                                           // slot 0xBE
    virtual void UpdateActorLighting(float);                                                      // slot 0xBF
    virtual float UpdateProcessTiming();                                                          // slot 0xC0
    virtual void SetSurfacing(bool);                                                              // slot 0xC1
    virtual bool GetSurfacing();                                                                  // slot 0xC2
    virtual bool IsDetecting();                                                                   // slot 0xC3
    virtual void SetCombatAlerted(bool);                                                          // slot 0xC4
    virtual float GetSecondProcessFloat();                                                        // slot 0xC5
    virtual void SetLipSyncValue(float);                                                          // slot 0xC6
    virtual bool IsCurrentlyAlerted();                                                            // slot 0xC7
    virtual void SetAlert(bool);                                                                  // slot 0xC8
    virtual bool HasCombatStarted();                                                     // slot 0xC9
    virtual void SetIsWeaponDrawn(bool);                                                          // slot 0xCA
    virtual InventoryStackRecord* GetPackageObject(Actor*, PACKAGE_OBJECT_TYPE);                            // slot 0xCB
    virtual void ClearPackageObjectList();                                                        // slot 0xCC
    virtual float GetRadiationRate();                                                             // slot 0xCD
    virtual void SetRadiationRate(float);                                                         // slot 0xCE
    virtual bool ShouldAttackTarget(Actor*, Actor*, bool, bool, ActorCombatGroup*, bool, bool, bool, char, bool, bool, bool,
                                    TESPackage*);                                            // slot 0xCF
    virtual void SetCombatTargetForActor(Actor*, Actor*);                                    // slot 0xD0
    virtual void ReportCrime(Actor*, Actor*, Crime*);                                        // slot 0xD1
    virtual void SetCrimeCategory(int);                                                      // slot 0xD2
    virtual int GetAttackChance(Actor*, float, float, float, bool, bool);                    // slot 0xD3
    virtual void SetActorDetectionState(Actor*, int, bool);                                  // slot 0xD4
    virtual void FinishDying(Actor*);                                                        // slot 0xD5
    virtual bool MoveToTarget(Actor*, float, int);                                           // slot 0xD6
    virtual bool ClearProcessStateFlags();                                                   // slot 0xD7
    virtual bool IsCurrentProcessComplete();                                                 // slot 0xD8
    virtual void SetCurrentProcessComplete(bool);                                                          // slot 0xD9
    virtual int GetActorStateCode(Actor*);                                                   // slot 0xDA
    virtual bool HasActorAlertState();                                                     // slot 0xDB
    virtual void SetDialogueState(bool);                                                     // slot 0xDC
    virtual void SetTalkingState(bool);                                                      // slot 0xDD
    virtual bool IsActorTalking();                                                         // slot 0xDE
    virtual LipSyncAnimation* GetLipSync();                                                  // slot 0xDF
    virtual void AssignLipSyncAnimation(LipSyncAnimation*);                                  // slot 0xE0
    virtual void SetLipSyncEnabled(bool);                                                    // slot 0xE1
    virtual bool GetPlantedExplosive();                                                      // slot 0xE2
    virtual TESIdleForm* GetActiveIdleForm();                                                // slot 0xE3
    virtual void SetCurrentIdle(TESIdleForm*);                                               // slot 0xE4
    virtual void RefreshActorValues(Actor*);                                                 // slot 0xE5
    virtual int GetActorValue(TESActorBase*, ActorValue__Index, Actor*);                     // slot 0xE6
    virtual float GetCurrentActorValue(TESActorBase*, ActorValue__Index, Actor*);            // slot 0xE7
    virtual void AlterActorValue(Actor*, ActorValue__Index, int);                          // slot 0xE9
    virtual void AlterActorValue(Actor*, ActorValue__Index, float);                        // slot 0xE8
    virtual void ApplyActorValue(Actor*, ActorValue__Index, int);                            // slot 0xEB
    virtual void ApplyActorValue(Actor*, ActorValue__Index, float);                          // slot 0xEA
    virtual void InvalidateValue(ActorValue__Index);                                         // slot 0xEC
    virtual void InitializeActiveEffectList();                                               // slot 0xED
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();                              // slot 0xEE
    virtual void DestroyActiveEffectList();                                                  // slot 0xEF
    virtual void CastSpellOnCaster(MagicCaster*, SpellItem*, bool);                          // slot 0xF0
    virtual void CastSpellAtTarget(MagicCaster*, SpellItem*, MagicTarget*, bool);            // slot 0xF1
    virtual MagicItem* GetSelectedMagicItem();                                               // slot 0xF2
    virtual void SetSelectedMagicItem(MagicItem*);                                           // slot 0xF3
    virtual MagicTarget* GetCurrentMagicTarget();                                            // slot 0xF4
    virtual void SetMagicTarget(MagicTarget*);                                               // slot 0xF5
    virtual bool UpdateIdleAnimation();                                                      // slot 0xF6
    virtual void SetBooleanState(bool);                                                      // slot 0xF7
    virtual void Move(MobileObject*, NiPoint3);                                              // slot 0xF8
    virtual int GetAnimAction();                                                             // slot 0xF9
    virtual BSAnimGroupSequence* GetActorProcessTime();                                      // slot 0xFA
    virtual void SetAnimAction(int, BSAnimGroupSequence*);                                   // slot 0xFB
    virtual bool IsAnimationSequencePlaying();                                               // slot 0xFC
    virtual void SetIsAlerted(bool);                                                         // slot 0xFD
    virtual bool IsAimingWeapon();                                                           // slot 0xFE
    virtual bool IsAimingAtActor(Actor*);                                                    // slot 0xFF
    virtual void SetAimingWeapon(bool);                                                        // slot 0x100
    virtual bool IsAlert();                                                                  // slot 0x101
    virtual bool HasAnimationGroup(ANIM_GROUP_ENUM);                                         // slot 0x102
    virtual KNOCK_STATE_ENUM StopIdleAnimation();                                            // slot 0x103
    virtual void SetKnockdownState(KNOCK_STATE_ENUM);                                        // slot 0x104
    virtual void KnockDown(Actor*);                                                          // slot 0x105
    virtual void ApplyKnockback(Actor*, NiPoint3, float);                                    // slot 0x106
    virtual void UpdateActorData(Actor*);                                                    // slot 0x107
    virtual void ProcessActorEvent(Actor*);                                                  // slot 0x108
    virtual void SetAnimationSequence(int, BSAnimGroupSequence*);                            // slot 0x109
    virtual void RefreshActorAnimation(Actor*);                                              // slot 0x10A
    virtual float GetAimAngle();                                                             // slot 0x10B
    virtual void SetAimAngle(float);                                                         // slot 0x10C
    virtual void SetStartShooting(bool);                                                     // slot 0x10D
    virtual unsigned char GetAttackState(Actor*);                                            // slot 0x10E
    virtual void SetBodyPartState(unsigned char);                                            // slot 0x10F
    virtual unsigned char GetProcessStateByte();                                             // slot 0x110
    virtual float GetVisibilityAlpha();                                                      // slot 0x111
    virtual void SetAttackCount(int);                                                        // slot 0x112
    virtual bool IsFirstActorFlagSet();                                                       // slot 0x113
    virtual void SetIsSwimming(bool);                                                        // slot 0x114
    virtual bool IsAdditionalActorFlagSet();                                                           // slot 0x115
    virtual void SetActorMovementState(Actor*, bool);                                        // slot 0x116
    virtual void SetLastKnownPosition(NiPoint3);                                             // slot 0x117
    virtual const NiPoint3* GetLastKnownPosition();                                          // slot 0x118
    virtual void RefreshActorState(Actor*);                                                      // slot 0x119
    virtual void ResetActorModel(int);                                                       // slot 0x11A
    virtual void SetDetectionFlag(int);                                                      // slot 0x11B
    virtual void ClearDetectionFlag();                                                       // slot 0x11C
    virtual bool IsProcessFlagSet(int);                                                      // slot 0x11D
    virtual unsigned char GetCurrentTargetType();                                            // slot 0x11E
    virtual void ClearReferenceRecords(unsigned int);                                        // slot 0x120
    virtual void ClearReferenceRecords(TESObjectREFR*);                                      // slot 0x11F
    virtual TESObjectREFR* GetPreviousReference();                                           // slot 0x121
    virtual void SetActorTargetReference(TESObjectREFR*);                                             // slot 0x122
    virtual SoundPlaybackHandle GetActorSoundHandle(int);                                          // slot 0x123
    virtual void SetActorSoundHandle(int, SoundPlaybackHandle);                                    // slot 0x124
    virtual void StopActorSound(int);                                                        // slot 0x125
    virtual void UpdateMovementStopped(Actor*);                                              // slot 0x126
    virtual bool IsMovementStopped();                                                        // slot 0x127
    virtual void ResetMovementState();                                                       // slot 0x128
    virtual void SetDiveBreathLevel(float);                                                  // slot 0x129
    virtual void StopAllActorSounds();                                                       // slot 0x12A
    virtual float GetDiveBreathLevel();                                                      // slot 0x12B
    virtual float GetMovementTimer();                                                        // slot 0x12C
    virtual void UpdateActorProcess(float);                                                  // slot 0x12D
    virtual bool IsTalking(MobileObject*);                                                   // slot 0x12E
    virtual SIT_SLEEP_STATE GetSitSleepState();                                              // slot 0x12F
    virtual void SetFurnitureState(Actor*, SIT_SLEEP_STATE, TESObjectREFR*, unsigned char);  // slot 0x130
    virtual unsigned int GetFurnitureMarkerID();                                             // slot 0x131
    virtual TESObjectREFR* GetFurnitureReference();                                          // slot 0x132
    virtual void SetFurnitureReference(TESObjectREFR*);                                      // slot 0x133
    virtual unsigned int GetFurnitureMarkerIndex();                                          // slot 0x134
    virtual FurnitureMark* GetFurnitureMarkerData();                                         // slot 0x135
    virtual bool IsFurnitureMarkerValid(Actor*);                                             // slot 0x136
    virtual void AssignAnimation(Actor*, Animation*);                                        // slot 0x137
    virtual bool HasAssignedAnimation();                                                     // slot 0x138
    virtual void SetAnimationEnabled(bool);                                                  // slot 0x139
    virtual bool IsPlayingAnimation();                                                       // slot 0x13A
    virtual void SetProcessConditionMet(bool);                                               // slot 0x13B
    virtual bool IsProcessStateEnabled();                                                    // slot 0x13C
    virtual void SetWeaponOutState(bool);                                                    // slot 0x13D
    virtual BSShaderPPLightingProperty* GetPixelLightingProperty();                          // slot 0x13E
    virtual void SetPixelLightingProperty(BSShaderPPLightingProperty*);                      // slot 0x13F
    virtual void SetDetectionState(Actor*, bool);                                            // slot 0x140
    virtual DetectionViewData* GetDetectionState(Actor*, int);                               // slot 0x141
    virtual DetectionViewData* InsertIntoDetectionArray(Actor*, int);                        // slot 0x142
    virtual float GetLightLevel();                                                           // slot 0x143
    virtual void SetFloatProperty(float);                                                    // slot 0x144
    virtual TESObjectREFR* GetActiveCombatTarget();                                          // slot 0x145
    virtual void SetCurrentCombatTarget(TESObjectREFR*);                                     // slot 0x146
    virtual TESObjectREFR* GetProcessReference();                                            // slot 0x147
    virtual void SetCurrentLocationReference(TESObjectREFR*);                                // slot 0x148
    virtual void UpdateCurrentPackage(Actor*);                                               // slot 0x149
    virtual void SetTalkTarget(Actor*);                                                      // slot 0x14A
    virtual Actor* GetCurrentTalkTarget();                                                     // slot 0x14B
    virtual void SetEquippedWeapon(TESObjectWEAP*);                                          // slot 0x14C
    virtual TESObjectWEAP* GetWeaponForm();                                                  // slot 0x14D
    virtual void SetActorAlpha(float);                                                       // slot 0x14E
    virtual float GetActorAlpha();                                                           // slot 0x14F
    virtual void SetFurnitureMarkerData(TESObjectREFR*, unsigned char, FurnitureMark*);      // slot 0x150
    virtual void ApplyProcessLevelChange(MobileObject*);                                     // slot 0x151
    virtual unsigned short GetSaveSize(unsigned int, MobileObject*);                         // slot 0x152
    virtual void SaveGame(unsigned int, MobileObject*);                                      // slot 0x154
    virtual void SaveGame(BGSSaveFormBuffer*);                                               // slot 0x153
    virtual void LoadGame(unsigned int, unsigned int, MobileObject*);                        // slot 0x156
    virtual void LoadGame(BGSLoadFormBuffer*);                                               // slot 0x155
    virtual void InitLoadGame(unsigned int, unsigned int, MobileObject*);                    // slot 0x158
    virtual void InitLoadGame(BGSLoadFormBuffer*);                                           // slot 0x157
    virtual void FinishLoadGameTES(unsigned int, unsigned int, MobileObject*);               // slot 0x159
    virtual void Revert(unsigned int, MobileObject*);                                        // slot 0x15B
    virtual void Revert(BGSLoadFormBuffer*);                                                 // slot 0x15A
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer*);                                        // slot 0x15C
    virtual TESEffectShader* GetCurrentEffectShader();                                       // slot 0x15D
    virtual void AssignEffectShader(TESEffectShader*);                                       // slot 0x15E
    virtual bool IsProcessStateInitialized();                                                // slot 0x15F
    virtual void UpdateActorAppearance(bool, bool, bool);                                    // slot 0x160
    virtual void RefreshActorProcessState(Actor*);                                           // slot 0x161
    virtual void SetIdleAnimationPlayed(bool);                                               // slot 0x162
    virtual bool IsPlayedState();                                                      // slot 0x163
    virtual void SetPlayedState(bool);                                                       // slot 0x164
    virtual bool WasIdleAnimationPlayed();                                                   // slot 0x165
    virtual void OnPackageChanged(Actor*, TESPackage*);                                      // slot 0x166
    virtual void OnPackageStart(Actor*, TESPackage*);                                        // slot 0x167
    virtual void OnPackageEnd(Actor*, TESPackage*);                                          // slot 0x168
    virtual bool IsProcessActivityActive();                                                  // slot 0x169
    virtual void SetProcessModeEnabled(bool);                                                // slot 0x16A
    virtual float GetLightIntensity();                                                       // slot 0x16B
    virtual void SetUnderwaterBreathTime(float);                                             // slot 0x16C
    virtual float GetThirdProcessFloat();                                                    // slot 0x16D
    virtual void SetWadingWaterLevel(float);                                                 // slot 0x16E
    virtual void UpdateWadingWater(Actor*);                                                  // slot 0x16F
    virtual int GetProcessIndex();                                                           // slot 0x170
    virtual void SetProcessIndex(int);                                                       // slot 0x171
    virtual bool HasActiveEffectOfType(BSSimpleList<ActiveEffect*>*, int);                   // slot 0x172
    virtual void RefreshMagicEffects();                                                      // slot 0x173
    virtual BSSimpleList<SpellItem*>* GetActorSpellList(Actor*, bool);                       // slot 0x174
    virtual void SetCastingState(int);                                                       // slot 0x175
    virtual int GetCurrentAnimAction();                                                      // slot 0x176
    virtual void SetCurrentMoveMode(int);                                                    // slot 0x177
    virtual int GetPendingIdleFlags();                                                       // slot 0x178
    virtual float GetPermanentActorValueFloat(ActorValue__Index);                            // slot 0x179
    virtual float GetDamageActorValue(ActorValue__Index);                                    // slot 0x17A
    virtual float GetTemporaryActorValue(ActorValue__Index);                                 // slot 0x17B
    virtual BSBound* GetObjectBounds();                                                      // slot 0x17C
    virtual void SetBoundingBox(BSBound*);                                                   // slot 0x17D
    virtual void SetIsSitting(bool);                                                         // slot 0x17E
    virtual bool IsActorInCombat();                                                       // slot 0x17F
    virtual void SetCombatState(bool);                                                       // slot 0x180
    virtual bool IsCurrentlyDetected();                                                        // slot 0x181
    virtual BSSimpleList<Actor*>* GetCombatTargetList();                                     // slot 0x182
    virtual void ProcessActorReferences(Actor*, TESObjectREFR*, TESObjectREFR*);             // slot 0x183
    virtual int GetCurrentFadeState();                                                       // slot 0x184
    virtual void AddPostAnimAction(int);                                                     // slot 0x185
    virtual int GetPostAnimationAction();                                                    // slot 0x186
    virtual void ClearPostAnimActions();                                                     // slot 0x187
    virtual void SetProcessState(int);                                                       // slot 0x188
    virtual void SetPreviousReference(TESObjectREFR*);                                       // slot 0x189
    virtual void SetActorProcessState(TESObjectREFR*);                                       // slot 0x18A
    virtual void SetPackageTargetReference(TESObjectREFR*);                                  // slot 0x18B
    virtual void SetCombatTargetReference(TESObjectREFR*);                                   // slot 0x18C
    virtual void ClearHighProcessState(TESObjectREFR*);                                      // slot 0x18D
    virtual void SetLastKnownReference(TESObjectREFR*);                                      // slot 0x18E
    virtual void SetTargetReferenceByIndex(int, TESObjectREFR*);                             // slot 0x18F
    virtual void ClearPackageData();                                                         // slot 0x190
    virtual void ClearCachedTargetReferences(bool);                                          // slot 0x191
    virtual void SetCombatActive(bool);                                                      // slot 0x192
    virtual void ResetCombatState();                                                         // slot 0x193
    virtual void RestorePreviousReference(bool);                                             // slot 0x194
    virtual void SetProcessActive(bool);                                                     // slot 0x195
    virtual void UpdatePlayerAwarenessTimer();                                               // slot 0x196
    virtual float GetCurrentAlpha();                                                         // slot 0x197
    virtual void ResetTargetReferences();                                                    // slot 0x198
    virtual void SetCurrentTargetReference(TESObjectREFR*);                                      // slot 0x199
    virtual bool HasNoPendingEntriesAndExpired();                                            // slot 0x19A
    virtual bool HasNoPendingEntries();                                                      // slot 0x19B
    virtual bool CanUseEquippedWeapon();                                              // slot 0x19C
    virtual TESObjectREFR* GetPrimaryTargetReference();                                      // slot 0x19E
    virtual TESObjectREFR* GetPrimaryTargetReference(int);                                   // slot 0x19D
    virtual int GetCombatTargetCount();                                                      // slot 0x19F
    virtual const char* GetCurrentPackageName();                                             // slot 0x1A0
    virtual void SetIsTalking(bool);                                                         // slot 0x1A1
    virtual bool IsCombatTargetValid();                                                      // slot 0x1A2
    virtual TESObjectREFR* GetRelatedReference();                                            // slot 0x1A3
    virtual bool IsInLastDefaultTargetArray(TESObjectREFR*);                                 // slot 0x1A4
    virtual void SetHasLastDefaultTargetArray(bool);                                         // slot 0x1A5
    virtual bool BeginIdleAnimation();                                                       // slot 0x1A6
    virtual float GetCurrentDetectionAmount();                                               // slot 0x1A7
    virtual void SetLightingAmount(float);                                                   // slot 0x1A8
    virtual void AddArrowProjectile(ArrowProjectile*);                                       // slot 0x1A9
    virtual void UnregisterArrowProjectile(ArrowProjectile*);                                // slot 0x1AA
    virtual void SetArrowTargetReference(TESObjectREFR*);                                    // slot 0x1AB
    virtual BSSimpleList<ArrowProjectile*>* GetArrowProjectiles();                           // slot 0x1AC
    virtual void SetProjectileTarget(Projectile*, TESObjectREFR*);                           // slot 0x1AD
    virtual MuzzleFlash* GetMuzzleFlash();                                                   // slot 0x1AE
    virtual bool GetEnableMuzzleFlash();                                                     // slot 0x1AF
    virtual void EnableMuzzleFlash();                                                        // slot 0x1B0
    virtual void ClearMuzzleFlash();                                                         // slot 0x1B1
    virtual void ApplyBodyPartData(NiNode*, BGSBodyPartData*);                               // slot 0x1B2
    virtual void SetNodeForType(int, NiNode*);                                               // slot 0x1B3
    virtual NiNode* GetNodeByType(int);                                                      // slot 0x1B4
    virtual NiAVObject* GetFirstSceneObject();                                               // slot 0x1B5
    virtual NiAVObject* GetActorSceneObject();                                               // slot 0x1B6
    virtual bool IsHoldingWeapon();                                                          // slot 0x1B7
    virtual void SetSustainedState(bool);                                                    // slot 0x1B8
    virtual void RunActorProcess(Actor*);                                                    // slot 0x1B9
    virtual bool GetProcessState();                                                          // slot 0x1BA
    virtual bool SetProcessStateFlag();                                                      // slot 0x1BB
    virtual bool IsProcessModeEnabled();                                                     // slot 0x1BC
    virtual bool SetActorAlertState();                                                          // slot 0x1BD
    virtual void SetIdleStateFlag(bool);                                                     // slot 0x1BE
    virtual bool IsProcessStateActive();                                                  // slot 0x1BF
    virtual void UpdateReferenceTime(Actor*, float);                                         // slot 0x1C0
    virtual void UpdateActorProcessState(Actor*);                                         // slot 0x1C1
    virtual void SelectAnimationAction(int);                                                 // slot 0x1C2
    virtual void UpdateActorReferences(Actor*);                                              // slot 0x1C3
    virtual void SetProcessReference(MobileObject*);                                         // slot 0x1C4
    virtual void SetMobileObjectTarget(MobileObject*);                                       // slot 0x1C5
    virtual TESIdleForm* GetSelectedIdleForm();                                              // slot 0x1C6
    virtual void SetIdleForm(TESIdleForm*);                                                  // slot 0x1C7
    virtual void SetIdleAnimation(AnimIdle*, KFModel*);                                      // slot 0x1C8
    virtual AnimIdle* GetIdleAnimation();                                                    // slot 0x1C9
    virtual KFModel* GetIdleAnimationModel();                                                // slot 0x1CA
    virtual void ApplyDamageToActor(Actor*, float);                                          // slot 0x1CB
    virtual float GetLastDamage();                                                           // slot 0x1CC
    virtual float GetProcessBlendWeight();                                                   // slot 0x1CD
    virtual void SetLightLevel(float);                                                       // slot 0x1CE
    virtual void AttachWeaponNode(int, NiNode*, NiAVObject*, bool);                          // slot 0x1CF
    virtual void UpdateActorWithTime(Actor*, float);                                         // slot 0x1D0
    virtual void SetLipSyncAnimation(LipSyncAnimation*);                                     // slot 0x1D1
    virtual LipSyncAnimation* GetLipSyncAnimationData();                                     // slot 0x1D2
    virtual void UpdateEffectShader(unsigned int);                                           // slot 0x1D3
    virtual unsigned int GetAnimationState();                                                // slot 0x1D4
    virtual void SetActorMovementRate(float);                                                // slot 0x1D5
    virtual void SetMovementTimer(float);                                                    // slot 0x1D6
    virtual float GetAnimationElapsedTime();                                                 // slot 0x1D7
    virtual void AdvanceMovementTimer(float);                                                // slot 0x1D8
    virtual float GetAnimationRemainingTime();                                               // slot 0x1D9
    virtual void SetWaterLevel(float);                                                       // slot 0x1DA
    virtual float GetControllerPhase();                                                      // slot 0x1DB
    virtual BooleanFloatQuery* RefreshActorRuntimeData();                                    // slot 0x1DC
    virtual void SetProcessObject(BooleanFloatQuery*);                                       // slot 0x1DD
    virtual void ResetHitData();                                                             // slot 0x1DE
    virtual BooleanFloatQuery* GetCurrentObjectData();                                       // slot 0x1DF
    virtual void SetHitData(BooleanFloatQuery*);                                             // slot 0x1E0
    virtual void ResetTargetHitData();                                                       // slot 0x1E1
    virtual int GetSleepSitState();                                                          // slot 0x1E2
    virtual void SetKnockdownStage(int);                                                     // slot 0x1E3
    virtual BSFaceGenNiNode* GetFacialAnimationNode();                                       // slot 0x1E4
    virtual void AttachFaceGenerationNode(BSFaceGenNiNode*);                                 // slot 0x1E5
    virtual BSFaceGenNiNode* GetFaceGenHeadNode();                                           // slot 0x1E6
    virtual void SetFaceGenHeadNode(BSFaceGenNiNode*);                                       // slot 0x1E7
    virtual NiAVObject* GetAnimationObject();                                                // slot 0x1E8
    virtual void SetAnimationNode(NiAVObject*);                                              // slot 0x1E9
    virtual void SetActorTarget(Actor*);                                                     // slot 0x1EA
    virtual void SetLastTargetReference(TESObjectREFR*);                                     // slot 0x1EB
    virtual void ClearTargetReference(TESObjectREFR*);                                       // slot 0x1EC
    PROCESS_TYPE GetProcessLevel();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BaseProcess) == 0x30);
FNV_STATIC_ASSERT(offsetof(BaseProcess, m_kProcessData) == 0x4);
FNV_STATIC_ASSERT(offsetof(BaseProcess, m_fValue2) == 0x1C);
FNV_STATIC_ASSERT(offsetof(BaseProcess, m_fValue1) == 0x20);
FNV_STATIC_ASSERT(offsetof(BaseProcess, m_uiStateFlags) == 0x24);
FNV_STATIC_ASSERT(offsetof(BaseProcess, m_eProcessType) == 0x28);
FNV_STATIC_ASSERT(offsetof(BaseProcess, m_pCachedValues) == 0x2C);
#endif
