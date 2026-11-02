
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpconstraintchaindrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpconstraintchaindrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    hkVector4()
    {}
    hkVector4(const hkVector4& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
    void operator=(const hkVector4& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
};
struct hkRotation
{
    hkVector4 c0, c1, c2;
};
struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};

struct RigidBody
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
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    hkTransform m_kMotionTransform;
};

struct StiffSpringInfo
{
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
    hkVector4 m_extra;
};
struct BallSocketInfo
{
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
};
struct PoweredInfo
{
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
    hkVector4 m_kRotationInA;
    hkVector4 m_kRotationInB;
    hkVector4 m_extra;
};

struct ChainData
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType() const;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_pConstraintInfo;
};

struct ChainInstance
{
    int unk00;
    int unk04;
    int unk08;
    ChainData* m_data;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    RigidBody** m_ppRigidBodies;
    int m_iActorEntryCount;
};

struct Vec
{
    hkVector4 v;
    void FUN_00c7f640(const void* m, const hkVector4& p);
};
struct Sub
{
    void FUN_00e10a10(void* a);
};
struct Listener
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void Fire(Vec* a, Vec* b, unsigned c, int d, int e);
};
struct Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_posA;
    hkVector4 m_posB;
    Vec m40;
    Vec m50;
    hkRotation m_kFirstRotation;
    hkRotation m_kSecondRotation;
    Sub mC0;
    void FUN_00de44c0(int a, int b);
    void FUN_00de4530(int a, int b);
    void FireChainConstraints(ChainInstance* c, Listener* l, int a, int b);
};

// @fnv 0x00de6390
void Obj::FireChainConstraints(ChainInstance* apChain, Listener* apListener, int aiArg1, int aiArg2)
{
    ChainData* data = apChain->m_data;
    mC0.FUN_00e10a10(apListener);
    int iPairCount = apChain->m_iActorEntryCount - 1;
    for (int iPair = 0; iPair < iPairCount; iPair++)
    {
        RigidBody* pBodyA = apChain->m_ppRigidBodies[iPair];
        RigidBody* pBodyB = apChain->m_ppRigidBodies[iPair + 1];
        hkTransform transformB = pBodyB->m_kMotionTransform;
        hkTransform transformA = pBodyA->m_kMotionTransform;
        m_kSecondRotation = transformB.m_rotation;
        m_kFirstRotation = transformA.m_rotation;
        m_posB = transformB.m_vTranslation;
        m_posA = transformA.m_vTranslation;
        hkVector4 pivotB;
        hkVector4 pivotA;
        switch (data->getType())
        {
        case 100:
            pivotB = ((StiffSpringInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInB;
            pivotA = ((StiffSpringInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInA;
            break;
        case 101:
            pivotB = ((BallSocketInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInB;
            pivotA = ((BallSocketInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInA;
            break;
        case 102:
            pivotB = ((PoweredInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInB;
            pivotA = ((PoweredInfo*)data->m_pConstraintInfo)[iPair].m_kPivotInA;
            break;
        }
        m50.FUN_00c7f640(&transformB, pivotB);
        m40.FUN_00c7f640(&transformA, pivotA);
        FUN_00de44c0(aiArg1, aiArg2);
        FUN_00de4530(aiArg1, aiArg2);
        apListener->Fire(&m40, &m50, 0xffff0000, aiArg1, aiArg2);
    }
}
