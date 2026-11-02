// Pragma-free compatible canonical declaration copy; original header is unchanged.
// Source layout: MobileObject. PC corrections are in generate_headers.py.
#ifndef CONDITIONFN_MOBILEOBJECT_DECLARATIONS_H
#define CONDITIONFN_MOBILEOBJECT_DECLARATIONS_H

#include "tesconditionfunctions_conditionfn_dep_layout_support.h"
#include "tesconditionfunctions_conditionfn_dep_TESObjectREFR.h"
class MobileObject : public TESObjectREFR
{
  public:
    BaseProcess* m_pBaseProcess;        // +0x68
    TESObjectREFR* m_pLinkedReference;  // +0x6C
    MobileObject* m_pMobileObject;      // +0x70
    float ProcessReferenceState;        // +0x74
    float ReferenceMobileState;         // +0x78
    bool m_bFirstFlag;                  // +0x7C
    bool m_bSecondBooleanValue;              // +0x7D
    bool m_bThirdFlag;                  // +0x7E
    bool m_bFourthBooleanValue;                // +0x7F
    bool m_bFifthFlag;                  // +0x80
    bool m_bSixthFlag;                  // +0x81
    bool m_bSeventhFlag;                // +0x82
    bool m_bEighthFlag;                 // +0x83
    char m_cCharacterValue;             // +0x84
    bool m_bNinthFlag;                  // +0x85
    bool m_bTenthFlag;                  // +0x86
    bool m_bThirdActorFlag;             // +0x87
    virtual void StartHighProcess(void);
    virtual void Unk_91(void);
    virtual void Unk_92(void);
    virtual void Unk_93(void);
    virtual void Unk_94(void);
    virtual void Unk_95(void);
    virtual void Unk_96(void);
    virtual void Unk_97(void);
    virtual void Unk_98(void);
    virtual void Unk_99(void);
    virtual void Unk_9A(void);
    virtual void Unk_9B(void);
    virtual void Unk_9C(void);
    virtual void Unk_9D(void);
    virtual void Unk_9E(void);
    virtual void Unk_9F(void);
    virtual void Unk_A0(void);
    virtual void Unk_A1(void);
    virtual void Unk_A2(void);
    virtual void Unk_A3(void);
    virtual void Unk_A4(void);
    virtual void Unk_A5(void);
    virtual void Unk_A6(void);
    virtual void Unk_A7(void);
    virtual void Unk_A8(void);
    virtual void Unk_A9(void);
    virtual void Unk_AA(void);
    virtual void Unk_AB(void);
    virtual void Unk_AC(void);
    virtual void Unk_AD(void);
    virtual void Unk_AE(void);
    virtual float AdjustRot(unsigned int arg1);
    virtual void Unk_B0(void);
    virtual void Unk_B1(void);
    virtual void Unk_B2(void);
    virtual void Unk_B3(void);
    virtual void Unk_B4(void);
    virtual void Unk_B5(void);
    virtual void Unk_B6(void);
    virtual void Unk_B7(void);
    virtual void Unk_B8(void);
    virtual void Unk_B9(void);
    virtual void Unk_BA(void);
    virtual void Unk_BB(void);
    virtual void Unk_BC(void);
    virtual void Unk_BD(void);
    virtual void Unk_BE(void);
    virtual void Unk_BF(void);
    virtual void Unk_C0(void);
    bool GetShouldUseEmotionAnimation() const;
    bool HasSaidTopicInfo(TESTopicInfo* info);
};
FNV_STATIC_ASSERT(sizeof(MobileObject) == 0x88);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_pBaseProcess) == 0x68);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_pLinkedReference) == 0x6C);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_pMobileObject) == 0x70);
FNV_STATIC_ASSERT(offsetof(MobileObject, ProcessReferenceState) == 0x74);
FNV_STATIC_ASSERT(offsetof(MobileObject, ReferenceMobileState) == 0x78);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_bFirstFlag) == 0x7C);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_bSecondBooleanValue) == 0x7D);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_bThirdFlag) == 0x7E);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_bFourthBooleanValue) == 0x7F);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_bFifthFlag) == 0x80);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_bSixthFlag) == 0x81);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_bSeventhFlag) == 0x82);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_bEighthFlag) == 0x83);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_cCharacterValue) == 0x84);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_bNinthFlag) == 0x85);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_bTenthFlag) == 0x86);
FNV_STATIC_ASSERT(offsetof(MobileObject, m_bThirdActorFlag) == 0x87);
#endif
