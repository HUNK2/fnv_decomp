// Authored check-time copy of the canonical generated LowProcess layout.
// Content mirrors include/LowProcess.h; the member declarations appended at
// the end are the canonical generated-header additions requested for
// FNV_LOWPROCESS_H guard keeps this copy conflict-free until the canonical
// header is regenerated and this file retires.
#ifndef FNV_LOWPROCESS_H
#define FNV_LOWPROCESS_H
#include "layout_support.h"
#include "BaseProcess.h"
#include "TimeoutTimer.h"
#include "ActorValueModifierList.h"
#pragma pack(push, 4)
class LowProcess : public BaseProcess
{
  public:
    unsigned char m_uiObjectFlags;  // +0x30
    unsigned char layoutPadding31[3];
    TESBoundObject* m_pCurrentWeapon;  // +0x34
    TimeoutTimer m_kProcessData38;      // +0x38
    TESObjectREFR* pTarget;            // +0x40
    TESObjectREFR* m_pReference40;     // +0x44
    TESObjectREFR* m_pReference44;     // +0x48
    BGSListForm* m_pFormList;          // +0x4C
    short m_sFourthValue;              // +0x50
    unsigned char layoutPadding52[2];
    TESObjectREFR* m_pObjectReference;                     // +0x54
    int m_iValue58;                                        // +0x58
    BSSimpleList<TargetDoorController*> ReferenceListNode;     // +0x5C
    TargetDoorController* m_pDetectionData60;                  // +0x64
    TargetDoorController* m_pDetectionData64;                  // +0x68
    BSSimpleList<TESObjectREFR*> m_kReferenceList68;       // +0x6C
    BSSimpleList<TargetDoorController*> m_kDetectionDataList;  // +0x74
    BSSimpleList<TESObjectREFR*> m_kReferenceList70;       // +0x7C
    TESBoundObject* m_pBoundObject74;                      // +0x84
    TESBoundObject* m_pBoundObject78;                      // +0x88
    PACKAGE_OBJECT_TYPE m_eReferenceTypeInfo;                         // +0x8C
    TESFaction* PackageFactionTarget;                      // +0x90
    ActorValueModifierList m_kActorValueModifiers;                   // +0x94
    float m_fValue88;                                      // +0xA4
    float m_fValue8C;                                      // +0xA8
    float m_fValue90;                                      // +0xAC
    bool m_bHasBoundObject;                                // +0xB0
    unsigned char layoutPaddingB1[3];
    void SetCurrentBoundObject(TESBoundObject*);
    void SetCurrentCombatTarget(TESObjectREFR*);
    TESObjectREFR* GetTarget();
    void SetPackageObjectType(int);
    int GetPackageObjectType();
    TESObjectREFR* GetActiveCombatTarget();
    // Canonical additions requested:
    void SetFlag(bool, unsigned char);
    bool GetFlag(unsigned char);
    void SetAnimationComplete(bool);
    bool IsMovementComplete();
    bool IsCurrentProcessComplete();
    void SetProcessTaskComplete(bool);
    bool IsProcessConditionMet();
    void SetProcessConditionMet(bool);
    bool IsProcessActivityActive();
    void SetProcessModeEnabled(bool);
    bool IsAnimationStateActive();
    void SetAnimationStateActive(bool);
    bool IsCurrentlyAlerted();
    void SetAlert(bool);
    float GetCurrentDetectionAmount();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(LowProcess) == 0xB4);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_uiObjectFlags) == 0x30);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_pCurrentWeapon) == 0x34);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_kProcessData38) == 0x38);
FNV_STATIC_ASSERT(offsetof(LowProcess, pTarget) == 0x40);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_pReference40) == 0x44);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_pReference44) == 0x48);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_pFormList) == 0x4C);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_sFourthValue) == 0x50);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_pObjectReference) == 0x54);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_iValue58) == 0x58);
FNV_STATIC_ASSERT(offsetof(LowProcess, ReferenceListNode) == 0x5C);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_pDetectionData60) == 0x64);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_pDetectionData64) == 0x68);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_kReferenceList68) == 0x6C);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_kDetectionDataList) == 0x74);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_kReferenceList70) == 0x7C);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_pBoundObject74) == 0x84);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_pBoundObject78) == 0x88);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_eReferenceTypeInfo) == 0x8C);
FNV_STATIC_ASSERT(offsetof(LowProcess, PackageFactionTarget) == 0x90);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_kActorValueModifiers) == 0x94);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_fValue88) == 0xA4);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_fValue8C) == 0xA8);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_fValue90) == 0xAC);
FNV_STATIC_ASSERT(offsetof(LowProcess, m_bHasBoundObject) == 0xB0);
#endif
