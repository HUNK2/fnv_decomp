// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_MIDDLEHIGHPROCESS_DECLS_H
#define FNV_MIDDLEHIGHPROCESS_DECLS_H

#include "layout_support.h"
#include "../../../include/Actor_decl_middlehighprocess.h"
#include "ActorPackageContext.h"
#include "MagicTarget.h"
#include "MiddleLowProcess.h"
#include "NiPoint3.h"
#include "layout_support.h"
class Actor;
class TESObjectREFR;
class InventoryStackRecord;
class Animation;
class ArrowProjectile;
class BSAnimGroupSequence;
class BSBound;
class ActorSupportClass;
class BSFaceGenAnimationData;
class BSFaceGenNiNode;
class BSShaderPPLightingProperty;
class FurnitureMark;
class BooleanFloatQuery;
class BipedAnim;
class NiNode;
class LipSyncAnimation;
class MiddleHighProcess;
class MiddleHighProcess__DeferredHideLimb;
class NiAVObject;
class QueuedFile;
class PaddedFloatRecord;
class TESEffectShader;
class TESIdleForm;
class TESObjectWEAP;
class bhkCharacterController;

enum BIPED_BONE
{
    BIPED_BONE_INVALID = 0,
    BIPED_BONE_WEAPON = 1
};
class BipedAnim
{
  public:
    NiNode* GetBoneNode(BIPED_BONE);
};

template <>
NiPointer<BSShaderPPLightingProperty>& NiPointer<BSShaderPPLightingProperty>::operator=(BSShaderPPLightingProperty*);

class TESAmmoInitCalls
{
  public:
    void* FUN_00923000();
};

bool IsValidSandboxProcedure(int aiProcedure);

extern unsigned int(__stdcall* DAT_00fdf1b0)(void*);

#pragma pack(push, 4)
class FurnitureMark
{
  public:
    NiPoint3 Position;            // +0x0, 12 bytes
    unsigned short m_usMarkerId;  // +0xC, 2 bytes
    unsigned char m_ucFlags;      // +0xE, 1 bytes
    unsigned char layoutPaddingF[1];
    // void __cdecl FurnitureMark::*(unsigned int)
    // unsigned int __cdecl FurnitureMark::*()
    // void __cdecl FurnitureMark::*(unsigned int)
    // const NiPoint3& __cdecl FurnitureMark::*()
    // void __cdecl FurnitureMark::*(const NiPoint3&)
    // float __cdecl FurnitureMark::*()
    // void __cdecl FurnitureMark::*(float)
    // void __cdecl FurnitureMark::*(NiStream&)
    // void __cdecl FurnitureMark::*(NiStream&)
    // bool __cdecl FurnitureMark::*(const FurnitureMark&)
    // bool __cdecl FurnitureMark::*(const FurnitureMark&)
    // bool __cdecl FurnitureMark::*(const FurnitureMark&)
    // bool __cdecl FurnitureMark::*(const FurnitureMark&)
    // bool __cdecl FurnitureMark::*(const FurnitureMark&)
    // bool __cdecl FurnitureMark::*(const FurnitureMark&)
    // void __cdecl FurnitureMark::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FurnitureMark) == 16);
FNV_STATIC_ASSERT(offsetof(FurnitureMark, Position) == 0);
FNV_STATIC_ASSERT(offsetof(FurnitureMark, m_usMarkerId) == 12);
FNV_STATIC_ASSERT(offsetof(FurnitureMark, m_ucFlags) == 14);
#pragma pack(push, 4)
class MiddleHighProcess : public MiddleLowProcess
{
  public:
    void FUN_0091db40(Actor* actor);  // declared for the original code (decl_variants.py)

  public:
    FurnitureMark* GetFurnitureMarkerData();
    bool IsFirstActorFlagSet();
    bool IsAdditionalActorFlagSet();
    void CastSpellOnCaster(MagicCaster*, SpellItem*, bool);
    void CastSpellAtTarget(MagicCaster*, SpellItem*, MagicTarget*, bool);
    void SetPixelLightingProperty(BSShaderPPLightingProperty*);
    void FUN_00929260(unsigned char);
    bool FUN_0044b130();
    NiNode* GetActorRootNode(BipedAnim*);
    void UpdateActorAppearance(bool, bool, bool);

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
    // MiddleHighProcess
    // void __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(TESObjectREFR*)
    // void __cdecl MiddleHighProcess::*(MiddleHighProcess*)
    // Update
    // BSSimpleList<ActiveEffect *>* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(MagicCaster*, SpellItem*, bool)
    // void __cdecl MiddleHighProcess::*(MagicCaster*, SpellItem*, MagicTarget*, bool)
    // MagicItem* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(MagicItem*)
    // MagicTarget* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(MagicTarget*)
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(bool)
    // void __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(NiControllerManager*, NiNode*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // bool __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(Actor*)
    // bool __cdecl MiddleHighProcess::*(TESBoundObject*, ExtraDataList*, bool)
    // void __cdecl MiddleHighProcess::*(Actor*, bool, TESBoundObject*, int, ExtraDataList*, bool, bool, bool, bool, bool, bool)
    // void __cdecl MiddleHighProcess::*(TESBoundObject*, ExtraDataList*)
    // void __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(Actor*, bool)
    // void __cdecl MiddleHighProcess::*(bool, BipedAnim*, Animation*, Actor*)
    // void __cdecl MiddleHighProcess::*(bool, BipedAnim*, Animation*, Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // NiAVObject* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(NiAVObject*)
    // NiNode* __cdecl MiddleHighProcess::*(BipedAnim*)
    // NiNode* __cdecl MiddleHighProcess::*(BipedAnim*)
    // NiNode* __cdecl MiddleHighProcess::*(BipedAnim*)
    // NiNode* __cdecl MiddleHighProcess::*(BipedAnim*)
    // NiNode* __cdecl MiddleHighProcess::*(BipedAnim*)
    // NiNode* __cdecl MiddleHighProcess::*(BipedAnim*)
    // bool __cdecl MiddleHighProcess::*()
    // int __cdecl MiddleHighProcess::*(Actor*)
    // Animation* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(AIM_ENUM, BSAnimGroupSequence*)
    // BSAnimGroupSequence* __cdecl MiddleHighProcess::*(AIM_ENUM)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // float __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(float)
    // void __cdecl MiddleHighProcess::*(bool)
    // unsigned char __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(unsigned char)
    // unsigned char __cdecl MiddleHighProcess::*()
    // float __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(Actor*)
    // bool __cdecl MiddleHighProcess::*(Actor*, bool)
    // void __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(TESObjectREFR*)
    // TESPackage* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(TESPackage*, MobileObject*)
    // void __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(int)
    // int __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(int)
    // TESPackage* __cdecl MiddleHighProcess::*()
    // int __cdecl MiddleHighProcess::*()
    // ActorPackageData* __cdecl MiddleHighProcess::*()
    // ActorPackageData* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(int)
    // void __cdecl MiddleHighProcess::*(MobileObject*, int)
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // bhkCharacterController* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(NiPointer<bhkCharacterController>)
    // unsigned short __cdecl MiddleHighProcess::*(MobileObject*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*()
    // KNOCK_STATE_ENUM __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(KNOCK_STATE_ENUM)
    // void __cdecl MiddleHighProcess::*(Actor*, NiPoint3, float)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(bool)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // MagicItem* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(MagicItem*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // Actor* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(TESObjectWEAP*)
    // TESObjectWEAP* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(MobileObject*)
    // unsigned short __cdecl MiddleHighProcess::*(unsigned int, MobileObject*)
    // SaveGame
    // LoadGame
    // InitLoadGame
    // void __cdecl MiddleHighProcess::*(unsigned int, unsigned int, MobileObject*)
    // Revert
    // void __cdecl MiddleHighProcess::*(BGSLoadFormBuffer*)
    // void __cdecl MiddleHighProcess::*(Actor*, Animation*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // TESEffectShader* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(TESEffectShader*)
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(bool, bool, bool)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // float __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(float)
    // float __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(float)
    // void __cdecl MiddleHighProcess::*(TESObjectREFR*, unsigned char, FurnitureMark*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(bool)
    // void __cdecl MiddleHighProcess::*(BSShaderPPLightingProperty*)
    // BSFaceGenAnimationData* __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*(BSSimpleList<ActiveEffect *>*, MagicSystem::FlareType)
    // void __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(bool)
    // BSBound* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(BSBound*)
    // void __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(bool)
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(bool)
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(bool)
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(RESET_3D_FLAGS)
    // void __cdecl MiddleHighProcess::*(RESET_3D_FLAGS)
    // void __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*(RESET_3D_FLAGS)
    // unsigned char __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(ArrowProjectile*)
    // void __cdecl MiddleHighProcess::*(ArrowProjectile*)
    // void __cdecl MiddleHighProcess::*(TESObjectREFR*)
    // BSSimpleList<ArrowProjectile *>* __cdecl MiddleHighProcess::*()
    // TESIdleForm* __cdecl MiddleHighProcess::*()
    // int __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(Actor*, bool)
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(bool)
    // bool __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(bool)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(bool)
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(bool)
    // bool __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*()
    // TESIdleForm* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(TESIdleForm*)
    // void __cdecl MiddleHighProcess::*(LipSyncAnimation*)
    // LipSyncAnimation* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(unsigned int)
    // unsigned int __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(float)
    // void __cdecl MiddleHighProcess::*(float)
    // float __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(float)
    // float __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(float)
    // float __cdecl MiddleHighProcess::*()
    // BooleanFloatQuery* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(BooleanFloatQuery*)
    // void __cdecl MiddleHighProcess::*()
    // BooleanFloatQuery* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(BooleanFloatQuery*)
    // void __cdecl MiddleHighProcess::*()
    // int __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(int)
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // BSFaceGenNiNode* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(BSFaceGenNiNode*)
    // BSFaceGenNiNode* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(BSFaceGenNiNode*)
    // NiAVObject* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(NiAVObject*)
    // void __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // TESObjectREFR* __cdecl MiddleHighProcess::*(Actor*, TESPackage*)
    // TESObjectREFR* __cdecl MiddleHighProcess::*(Actor*, TESPackage*, bool)
    // TESObjectREFR* __cdecl MiddleHighProcess::*(Actor*, bool)
    // bool __cdecl MiddleHighProcess::*(Actor*, int)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(bool)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*, bool, int, bool)
    // void __cdecl MiddleHighProcess::*(Actor*, bool, bool, int)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*, TESObjectREFR*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // bool __cdecl MiddleHighProcess::*(Actor*, float)
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // bool __cdecl MiddleHighProcess::*(Actor*, float, bool)
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*, int, bool)
    // void __cdecl MiddleHighProcess::*(Actor*, bool, bool, int, bool)
    // bool __cdecl MiddleHighProcess::*(Actor*, bool)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*, bool, TESObjectREFR*)
    // bool __cdecl MiddleHighProcess::*(TESObjectREFR*, long)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // SIT_SLEEP_STATE __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(Actor*, SIT_SLEEP_STATE, TESObjectREFR*, unsigned char)
    // bool __cdecl MiddleHighProcess::*(TESObjectREFR*, unsigned int)
    // TESObjectREFR* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(TESObjectREFR*)
    // unsigned int __cdecl MiddleHighProcess::*()
    // unsigned int __cdecl MiddleHighProcess::*()
    // FurnitureMark* __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*()
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // bool __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // BSShaderPPLightingProperty* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(Actor*, bool)
    // void __cdecl MiddleHighProcess::*(Actor*)
    // void __cdecl MiddleHighProcess::*(NiNode*, BGSBodyPartData*)
    // void __cdecl MiddleHighProcess::*(BGSBodyPart::LIMB_ENUM, NiNode*)
    // NiNode* __cdecl MiddleHighProcess::*(BGSBodyPart::LIMB_ENUM)
    // NiAVObject* __cdecl MiddleHighProcess::*()
    // NiAVObject* __cdecl MiddleHighProcess::*()
    // void __cdecl MiddleHighProcess::*(int)
    // void __cdecl MiddleHighProcess::*(BGSBodyPart::LIMB_ENUM, NiNode*, NiAVObject*, bool)
    // void __cdecl MiddleHighProcess::*(Actor*, float)
    // bool __cdecl MiddleHighProcess::*(ANIM_GROUP_ENUM)
    // MiddleHighProcess& __cdecl MiddleHighProcess::*(const MiddleHighProcess&)
    // void __cdecl MiddleHighProcess::*()
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
#endif
