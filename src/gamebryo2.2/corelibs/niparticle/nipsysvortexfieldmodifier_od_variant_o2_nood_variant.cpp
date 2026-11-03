
// src/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier_od_variant_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier_od_variant.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysvortexfieldmodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void* g_01202688;
void* __cdecl NiPSysVortexFieldModifier_GetRTTI();

// NiPSysVortexFieldModifier_Update: NiPSysFieldModifier-style Update with attenuation - per-particle
// force from FUN_00c26820, scaled by magnitude * dt / dist^attenuation.
extern "C" double __cdecl pow(double, double);

struct TPoint3
{
    float x, y, z;

    TPoint3()
    {}
    TPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}

    TPoint3 operator-(const TPoint3& kPt) const
    {
        return TPoint3(x - kPt.x, y - kPt.y, z - kPt.z);
    }
    bool FUN_004390c0(const TPoint3& kPt) const;
    float FUN_00457990() const;
    void NiPoint3_Unitize();
    TPoint3& FUN_00439180(float fScalar);
    TPoint3& FUN_0063c8a0(const TPoint3& kPt);
};

extern const TPoint3 DAT_011f426c;

struct TMatrix3
{
    float m_afEntries[3][3];

    TPoint3 FUN_004b4500(const TPoint3& kPt) const;
};

struct NiTransform
{
    TMatrix3 m_kOrientation;
    TPoint3 m_kTranslation;
    float m_fScale;

    void FUN_004b4880(NiTransform& kDest) const;
    NiTransform FUN_0062c250(const NiTransform& kXform) const;
};

struct TAVObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    NiTransform m_kWorldSpaceTransform;
};

struct TParticleInfo
{
    TPoint3 m_kValue;
    float m_fXValue;
    float m_fYValue;
    float m_fZValue;
    int unk18;
};

struct TPSysData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    TPoint3* m_pkVertex;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    unsigned short m_usVertices;
    unsigned short unk52;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    TParticleInfo* m_pkParticleInfo;

    unsigned short GetShaderParticleCount() const
    {
        return m_usVertices;
    }
    TPoint3* GetVertices() const
    {
        return m_pkVertex;
    }
    TParticleInfo* GetParticleInfo() const
    {
        return m_pkParticleInfo;
    }
};

inline float NiPow(float fBase, float fExp)
{
    return (float)pow(fBase, fExp);
}

struct TFieldModifier
{
    void* m_pVtbl;
    int m_iRefCount;
    int m_kName;
    unsigned int m_uiUpdateOrder;
    TAVObject* m_pkTarget;
    bool m_bModifierActive;
    TAVObject* m_pkFieldObject;
    float m_fInfluence;
    float m_fFieldAttenuation;
    bool m_bEnableMaxDistance;
    float m_fDistanceLimit;
    float m_fFieldStrength;
    TPoint3 m_kLightVector;

    void NiPSysVortexFieldModifier_Update(float fTime, TPSysData* pkData);
    void FUN_00c269b0(float fTime, TPSysData* pkData);
    void FUN_00c26c00(float fTime, TPSysData* pkData);
    __declspec(noalias) TPoint3 FUN_00c26820(const TPoint3& kFieldPos, const TPoint3& kFieldDir, const TPoint3& kPos);
};

// @fnv 0x00c26de0
void TFieldModifier::NiPSysVortexFieldModifier_Update(float fTime, TPSysData* pkData)
{
    if (m_fInfluence == 0.0f)
        return;
    if (pkData->GetShaderParticleCount() == 0)
        return;
    if (m_kLightVector.FUN_004390c0(DAT_011f426c))
        return;
    if (!m_pkFieldObject)
        return;

    if (m_fFieldAttenuation == 0.0f)
    {
        if (m_bEnableMaxDistance)
            FUN_00c269b0(fTime, pkData);
        else
            FUN_00c26c00(fTime, pkData);
        return;
    }

    NiTransform kFieldXform = m_pkFieldObject->m_kWorldSpaceTransform;
    NiTransform kInvPSys;
    {
        NiTransform kPSysXform = m_pkTarget->m_kWorldSpaceTransform;
        kPSysXform.FUN_004b4880(kInvPSys);
    }

    {
        NiTransform kFieldToPSys = kInvPSys.FUN_0062c250(kFieldXform);
        TPoint3 kFieldPos = kFieldToPSys.m_kTranslation;
        TPoint3 kFieldDir = kFieldToPSys.m_kOrientation.FUN_004b4500(m_kLightVector);
        kFieldDir.NiPoint3_Unitize();

        for (unsigned short i = 0; i < pkData->GetShaderParticleCount(); i++)
        {
            TParticleInfo* pkInfo = &pkData->GetParticleInfo()[i];
            float fDeltaT = fTime - pkInfo->m_fZValue;
            if (fDeltaT != 0.0f)
            {
                TPoint3 kPos = pkData->GetVertices()[i];
                TPoint3 kDiff = kPos - kFieldToPSys.m_kTranslation;
                float fDist = kDiff.FUN_00457990();
                if (fDist != 0.0f)
                {
                    if (!m_bEnableMaxDistance || fDist <= m_fDistanceLimit)
                    {
                        TPoint3 kForce = FUN_00c26820(kFieldPos, kFieldDir, kPos);
                        if (m_fFieldAttenuation == 0.0f)
                            kForce.FUN_00439180(fDeltaT * m_fInfluence);
                        else
                            kForce.FUN_00439180(fDeltaT * m_fInfluence / NiPow(fDist, m_fFieldAttenuation));
                        pkInfo->m_kValue.FUN_0063c8a0(kForce);
                    }
                }
            }
        }
    }
}
