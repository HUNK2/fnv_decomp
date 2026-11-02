// Authored unit-local declarations for
// gamebryo2.2/corelibs/nianimation/nigeommorphercontroller.cpp.
// FNV (Gamebryo 2.2 branch) revision of NiGeomMorpherController.
//
// Layout notes (all offsets verified against the matcher task evidence):
// - NiObject (8 bytes), NiMemObject come from the canonical generated
//   headers.
// - NiTimeController (0x34 bytes), NiInterpController (no extra members)
//   m_spMorphTargetData +0x38, m_pInterpolatorItems +0x3C, four bool flags +0x40)
// - NiMorphData (0x18 bytes: m_uiNumTargets +0x8, m_uiNumVertsPerTarget
//   +0xC, m_pMorphTargets +0x10, m_bTargetsAreRelative +0x14) is copied from
// - NiMorphData::MorphTarget (0x10 bytes: m_pkVertexPositions +0x0, m_kName +0x4,
//   m_fMorphWeight +0x8, m_spTargetInterpolator +0xC) follows the Gamebryo
//   2.6 NiMorphData.h layout, which matches the observed PC stride (16) and
//   the out-of-line GetName() (lea eax,[ecx+4]).
#ifndef FNV_NIGEOMMORPHERCONTROLLER_UNIT_H
#define FNV_NIGEOMMORPHERCONTROLLER_UNIT_H


#include "layout_support.h"
#include "NiFixedString.h"
#include "NiMemObject.h"
#include "NiObject.h"
#include "NiRefObject.h"

class CloningProcess;
class RgbaColor;
class NiColorData;
class ColorAnimationKey;
class NiInterpolator;
class NiMorphData;
class NiObjectNET;
class NiPoint3;
class NiStream;
class NiUpdateData;

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
class AnimationKey
{
  public:
    enum KeyType
    {
        NOINTERP,
        LINKEY,
        BEZKEY,
        TCBKEY,
        EULERKEY,
        STEPKEY
    };
    enum KeyContent
    {
        FLOATKEY,
        POSKEY,
        ROTKEY,
        COLORKEY,
        TEXTKEY,
        BOOLKEY
    };
};

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
#pragma pack(push, 4)
class NiTimeController : public NiObject
{
  public:
    unsigned short m_uiObjectFlags;  // +0x8, 2 bytes
    unsigned char m_aucPadA[2];
    float m_fFrequency;                              // +0xC, 4 bytes
    float m_fPhase;                                  // +0x10, 4 bytes
    float m_fLoKeyTime;                              // +0x14, 4 bytes
    float m_fHiKeyTime;                              // +0x18, 4 bytes
    float m_fStartTime;                              // +0x1C, 4 bytes
    float m_fLastTime;                               // +0x20, 4 bytes
    float m_fWeightAdjustedLastTime;                 // +0x24, 4 bytes
    float m_fControllerTime;                         // +0x28, 4 bytes
    NiObjectNET* m_pkTarget;                         // +0x2C, 4 bytes
    NiPointer<NiTimeController> m_spNextController;  // +0x30, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTimeController) == 52);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_uiObjectFlags) == 8);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fControllerTime) == 40);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_pkTarget) == 44);

// NiObjectNET is only needed as an opaque target type here.
class NiObjectNET : public NiObject
{
};

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
#pragma pack(push, 4)
class NiInterpController : public NiTimeController
{
  public:
    static const unsigned short INVALID_INDEX;

    void CopyMemberData(NiInterpController* pkClone, CloningProcess& kCloning);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiInterpController) == 52);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
#pragma pack(push, 4)
class NiMorphData : public NiObject
{
  public:
    class MorphTarget : public NiMemObject
    {
      public:
        NiPoint3* m_pkVertexPositions;                     // +0x0
        NiFixedString m_kName;                             // +0x4
        float m_fMorphWeight;                              // +0x8
        NiPointer<NiInterpolator> m_spTargetInterpolator;  // +0xC

        const NiFixedString& GetName();
    };

    unsigned int m_uiNumTargets;         // +0x8, 4 bytes
    unsigned int m_uiNumVertsPerTarget;  // +0xC, 4 bytes
    MorphTarget* m_pMorphTargets;        // +0x10, 4 bytes
    bool m_bTargetsAreRelative;          // +0x14, 1 bytes
    unsigned char m_aucPad[3];

    inline MorphTarget* GetTarget(unsigned int uiIndex) const
    {
        if (uiIndex < m_uiNumTargets)
            return &(m_pMorphTargets[uiIndex]);
        else
            return 0;
    }
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiMorphData) == 24);
FNV_STATIC_ASSERT(offsetof(NiMorphData, m_uiNumTargets) == 8);
FNV_STATIC_ASSERT(offsetof(NiMorphData, m_pMorphTargets) == 16);
FNV_STATIC_ASSERT(sizeof(NiMorphData::MorphTarget) == 16);
FNV_STATIC_ASSERT(offsetof(NiMorphData::MorphTarget, m_kName) == 4);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
#pragma pack(push, 4)
class NiGeomMorpherController : public NiInterpController
{
  public:
    unsigned short m_uiObjectFlags;  // +0x34, 2 bytes
    unsigned char m_aucPad[2];
    NiPointer<NiMorphData> m_spMorphTargetData;  // +0x38, 4 bytes
    struct InterpItem
    {
        NiPointer<NiInterpolator> m_spControllerInterpolator;
        float m_fWeight;
    };
    InterpItem* m_pInterpolatorItems;  // +0x3C, 4 bytes
    bool m_bUpdateEnabled;             // +0x40, 1 bytes
    bool m_bUpdateNormals;             // +0x41, 1 bytes
    bool m_bNeedsUpdate;               // +0x42, 1 bytes
    bool m_bUpdateBounds;              // +0x43, 1 bytes

    unsigned int GetNumTargets() const;
    unsigned short GetTargetCount() const;
    unsigned short GetTargetIndex(const char* pcID) const;
    unsigned short GetTargetIndex(const NiFixedString& kID) const;
    void CopyMemberData(NiGeomMorpherController* pkClone, CloningProcess& kCloning);
    void SetMorphData(NiMorphData* pkMorphData, bool bCanUpdate);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiGeomMorpherController) == 68);
FNV_STATIC_ASSERT(offsetof(NiGeomMorpherController, m_uiObjectFlags) == 52);
FNV_STATIC_ASSERT(offsetof(NiGeomMorpherController, m_spMorphTargetData) == 56);
FNV_STATIC_ASSERT(offsetof(NiGeomMorpherController, m_pInterpolatorItems) == 60);
FNV_STATIC_ASSERT(offsetof(NiGeomMorpherController, m_bNeedsUpdate) == 66);

int NiStricmp(const char* a, const char* b);

// ---------------------------------------------------------------------------
// RgbaColor / NiColorData / NiInterpolator / NiKeyBasedInterpolator /
// units touch are declared; the virtuals are intentionally omitted so the
// out-of-line definitions below stay linker-visible without emitting a
// second copy of a shared vtable.
// ---------------------------------------------------------------------------
#pragma pack(push, 4)
class RgbaColor
{
  public:
    float r;  // +0x0
    float g;  // +0x4
    float b;  // +0x8
    float a;  // +0xC

    bool FUN_004a4cc0(const RgbaColor&) const;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RgbaColor) == 16);
FNV_STATIC_ASSERT(offsetof(RgbaColor, r) == 0);
FNV_STATIC_ASSERT(offsetof(RgbaColor, a) == 12);

extern const RgbaColor DAT_011a9430;
extern bool DAT_011f3724;

#pragma pack(push, 4)
class NiColorData : public NiObject
{
  public:
    unsigned int m_uiNumKeys;              // +0x8
    ColorAnimationKey* m_pKeyArray;        // +0xC
    AnimationKey::KeyType m_eRequestType;  // +0x10
    unsigned char m_ucKeyDataSize;         // +0x14
    unsigned char m_aucPad[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiColorData) == 24);
FNV_STATIC_ASSERT(offsetof(NiColorData, m_uiNumKeys) == 8);
FNV_STATIC_ASSERT(offsetof(NiColorData, m_eRequestType) == 16);
FNV_STATIC_ASSERT(offsetof(NiColorData, m_ucKeyDataSize) == 20);

#pragma pack(push, 4)
class NiInterpolator : public NiObject
{
  public:
    float m_fLastTime;  // +0x8

    NiInterpolator* FUN_00a5d3f0(CloningProcess& kCloning);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiInterpolator) == 12);

class NiKeyBasedInterpolator : public NiInterpolator
{
};

#pragma pack(push, 4)
class NiColorInterpolator : public NiKeyBasedInterpolator
{
  public:
    RgbaColor m_kColorValue;               // +0xC
    NiPointer<NiColorData> m_spColorData;  // +0x1C
    unsigned int m_uiLastKeyIndex;         // +0x20

    AnimationKey::KeyContent GetColorKeyContent(unsigned short) const;
    unsigned int GetColorKeyCount(unsigned short) const;
    AnimationKey::KeyType GetColorKeyType(unsigned short) const;
    unsigned char GetColorKeySize(unsigned short) const;
    bool IsColorConstant(unsigned short) const;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(offsetof(NiColorInterpolator, m_kColorValue) == 12);
FNV_STATIC_ASSERT(offsetof(NiColorInterpolator, m_spColorData) == 28);

#endif
