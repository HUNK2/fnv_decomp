
// src/fallout/magic/telekinesiseffect_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/magic/telekinesiseffect_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/telekinesiseffect_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/telekinesiseffect.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/magic/telekinesiseffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/telekinesiseffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_0082a510_shell
{
    void FUN_0082a540();
    void* DestroyIfFlagged(unsigned int flags);
};
void __cdecl _Deallocate(void*);
struct FUN_0082aab0_shell
{
    void SetField644(float value);
};
struct FUN_0082af40_shell
{
    float fTelekinesisStrength;  // +0x644
    float GetTelekinesisStrength();
};
struct Actor
{
};
struct ValueModifierEffect
{
    unsigned short __thiscall FUN_00802d90(Actor* apActor);
};
struct TelekinesisEffect : ValueModifierEffect
{
    unsigned short __thiscall FUN_0082b190(Actor* apActor);
};
struct FUN_008df040_shell
{
    unsigned char __thiscall FUN_008df040();
};
extern FUN_008df040_shell* g_TESSaveLoadGame;
struct FUN_0082a670_shell
{
    void __thiscall FUN_0082a670();
    void __thiscall FUN_0082c000();
    void __thiscall StartTelekinesisEffect();
};
void* __cdecl FUN_00703390();
struct Flt
{
    operator unsigned int();
};
struct FUN_0082aa90_shell
{
    unsigned int GetFloatAsUInt();
};
void* __cdecl FUN_004b5a80(void const*);
struct FUN_0082aeb0_shell
{
    void* __thiscall FUN_0082aee0();
    void* __thiscall FUN_0082aeb0();
};

#include <xmmintrin.h>
class NiPoint3T
{
  public:
    float x, y, z;
    NiPoint3T();
    NiPoint3T operator*(float fScalar) const;
};
extern const NiPoint3T g_kZeroPointT;

class NiMatrix3T
{
  public:
    float m_afEntries[3][3];
    NiMatrix3T();
    void SetRotationFromEulerXYZ(float fXAngle, float fYAngle, float fZAngle);
    void GetCol(unsigned int uiCol, NiPoint3T& kCol) const;
};

class hkVector4T
{
  public:
    __m128 m_vComponents;
    hkVector4T();
    void mul4(const class hkSimdRealT& kScale);
};

class hkSimdRealT
{
  public:
    __m128 m_vValue;
    hkSimdRealT(float fValue);
};

void __cdecl FUN_004a3e00(hkVector4T* pkOut, const NiPoint3T* pkIn);

class TelekinesisTargetController
{
  public:
    void Update();
};

class TelekinesisTarget
{
  public:
    float GetMass();
    TelekinesisTargetController* SetLinearVelocity(const hkVector4T& kMotionVelocity);
    void SetVelocity(const NiPoint3T& kMotionVelocity);
};

class PlayerCameraT
{
  public:
    FUN_0082aeb0_shell* GetGrab();
    void ReleaseGrab();
    const NiPoint3T& GetRotation();
};
extern PlayerCameraT* g_pkPlayerCameraT;

class GameSettingTableT
{
  public:
    float& GetValue();
};
extern GameSettingTableT g_kTelekinesisDistanceT;

class TelekinesisEffectT
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    float m_fHitDistance;
    unsigned int unk58;
    bool m_bHolding;

    void FUN_0082afa0();
};

// @fnv 0x0082afa0
void TelekinesisEffectT::FUN_0082afa0()
{
    if (g_pkPlayerCameraT->GetGrab())
    {
        void* pvGrabbed = g_pkPlayerCameraT->GetGrab()->FUN_0082aee0();
        g_pkPlayerCameraT->ReleaseGrab();
        if (pvGrabbed)
        {
            TelekinesisTarget* pkTarget = (TelekinesisTarget*)FUN_004b5a80(pvGrabbed);
            if (m_bHolding)
            {
                NiPoint3T kForward;
                NiMatrix3T kRotationBasis;
                NiPoint3T kAngles = g_pkPlayerCameraT->GetRotation();
                kRotationBasis.SetRotationFromEulerXYZ(kAngles.z, kAngles.x, kAngles.y);
                kRotationBasis.GetCol(1, kForward);
                NiPoint3T kIntersectionOffset = kForward * (g_kTelekinesisDistanceT.GetValue() + m_fHitDistance);
                hkVector4T kMotionVelocity;
                FUN_004a3e00(&kMotionVelocity, &kIntersectionOffset);
                hkSimdRealT kMass(pkTarget->GetMass());
                kMotionVelocity.mul4(kMass);
                pkTarget->SetLinearVelocity(kMotionVelocity)->Update();
            }
            else
            {
                pkTarget->SetVelocity(g_kZeroPointT);
            }
        }
    }
}
