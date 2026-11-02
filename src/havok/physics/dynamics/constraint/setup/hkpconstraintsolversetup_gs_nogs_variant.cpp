
// src/havok/physics/dynamics/constraint/setup/hkpconstraintsolversetup_gs_nogs_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct State
{
    int unk00;
    void* owner;
    int unk08;
    int eventCode;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* resetA;
    int unk24;
    void* desiredA;
    void* currentA;
    void* resetB;
    int unk34;
    void* desiredB;
    void* currentB;
    int callbackFlags;
    int unk44;
    volatile float* end;
    volatile float* current;
};
void __cdecl FUN_00d8aac0(void* owner, void* current, int eventCode, int flags);
void __cdecl FUN_00d88340(State* state, int reset);
struct D88310Bool
{
    char m_cBooleanValue;

    D88310Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
struct D88310Stream
{
    int unk00;
    int unk04;
    int unk08;
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pTileTemplate;
};
D88310Bool __cdecl FUN_00d88310(const D88310Stream* stream, const void* unused, int numBlocks);
void __cdecl FUN_00d88300();
struct D88470Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned short amountA;
    unsigned short unk16;
    unsigned short amountB;
    unsigned short unk1a;
};
struct D88470Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned char type;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    D88470Sub* sub;
};
struct D88470Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned int limitA;
    unsigned int initA;
    int unk2c;
    int unk30;
    unsigned int limitB;
    unsigned int initB;
    int unk3c;
    int unk40;
    unsigned int limitSum;
    unsigned int initSum;
};
D88310Bool __cdecl CheckTotalsWithinLimits(D88470Obj* obj, D88470Elem** begin, int count);
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps();
struct hkVector4D886
{
    __m128 m_vComponents;

    hkVector4D886()
    {}
    hkVector4D886(const hkVector4D886& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D886& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};
struct hkpVelocityAccumulatorD886
{
    unsigned char m_type;
    unsigned char m_iValueAtOffset0C;
    unsigned char unk02, unk03;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    unsigned int unk0C;
    hkVector4D886 m_vLinearVelocity;
    hkVector4D886 m_vAngularVelocity;
    hkVector4D886 m_vInverseInertiaAndMass;
    hkVector4D886 m_vCenterOfMass;
    hkVector4D886 m_scratch1;
    hkVector4D886 m_scratch2;
    hkVector4D886 m_scratch3;

    void setFixed()
    {
        m_fGravityFactor = 0.0f;
        m_type = 1;
        m_vInverseInertiaAndMass.setZero4();
        m_vLinearVelocity.setZero4();
        m_vAngularVelocity.setZero4();
        m_vCenterOfMass.setZero4();
        m_scratch1.setZero4();
        m_scratch2.setZero4();
        m_scratch3.setZero4();
    }
};
struct hkpSolverSumVelocitiesD886
{
    hkVector4D886 m_vLinearVelocity;
    hkVector4D886 m_vAngularVelocity;
};
struct hkStepInfoD886;
struct hkpEntityD886
{
    unsigned int unk00[41];
    unsigned int m_uiFilterInfo;
};
struct hkpConstraintSolverResourcesD886
{
    const hkStepInfoD886* m_pStepInfo;
    unsigned int unk04, unk08;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorA;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorB;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorC;
    hkpSolverSumVelocitiesD886* m_sumVelocities;
};
hkpVelocityAccumulatorD886* __cdecl FUN_00d29830(const hkStepInfoD886* pkInfo, hkpEntityD886* const* ppkEntities,
                                                 unsigned int uiNumEntities, int iMotionOffset,
                                                 hkpVelocityAccumulatorD886* pkAccumulatorsOut);
void __cdecl FUN_00d88670(hkpConstraintSolverResourcesD886& kResources, hkpEntityD886* const* ppkEntities,
                          unsigned int uiNumEntities);

typedef hkVector4D886 hkVec4;

struct hkAccum
{
    unsigned char m_type;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    hkVec4 m_vLinearVelocity;
    hkVec4 m_vAngularVelocity;
    hkVec4 m_vInverseInertiaAndMass;
    hkVec4 m_vCenterOfMass;
    hkVec4 m_scratch1;
    hkVec4 m_scratch2;
    hkVec4 m_scratch3;
};

struct D88580World
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* m78;
};

struct D88580Sub
{
    void* unk00;
    void* unk04;
    unsigned char unk08;
    unsigned char m09;
};

struct D88580Entity
{
    int unk00;
    int unk04;
    D88580World* m08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    char* m_a4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    D88580Sub m_e0;
};

void __cdecl FUN_00d29bf0(void* a0, void* a1, hkAccum* acc, D88580Sub** sub, int a4, int a5);
void __cdecl FUN_00d1a330(void* world78, D88580Entity** ent, int count);

// @fnv 0x00d88580
void __cdecl FUN_00d88580(void* a0, void* a1, int offset, D88580Entity** entities, int count)
{
    for (int i = 0; i < count; ++i)
    {
        D88580Entity* entity = entities[i];
        D88580Sub* sub = &entity->m_e0;
        hkAccum acc = *(hkAccum*)(entity->m_a4 + offset);
        acc.m_vCenterOfMass = acc.m_vLinearVelocity;
        acc.m_scratch1 = acc.m_vAngularVelocity;
        unsigned char saved = sub->m09;
        sub->m09 = 0xff;
        FUN_00d29bf0(a0, a1, &acc, &sub, 1, 0);
        FUN_00d1a330(entity->m08->m78, &entity, 1);
        sub->m09 = saved;
    }
}
