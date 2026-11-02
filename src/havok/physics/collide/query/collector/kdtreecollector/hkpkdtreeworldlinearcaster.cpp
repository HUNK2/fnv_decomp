
// src/havok/physics/collide/query/collector/kdtreecollector/hkpkdtreeworldlinearcaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/kdtreecollector/hkpkdtreeworldlinearcaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ThresholdRecord
{
    unsigned int unk00;
    float value;
};
struct ThresholdHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    ThresholdRecord* record;
    unsigned char* WriteThresholdFlag(unsigned char* output);
};
// Writes 1 to output when record->value is below 1.0f, otherwise 0, and returns output.
// @fnv 0x00d983f0
unsigned char* ThresholdHolder::WriteThresholdFlag(unsigned char* pucOutput)
{
    unsigned char result;
    if (record->value < 1.0f)
        result = 1;
    else
        result = 0;
    *pucOutput = result;
    return pucOutput;
}

struct CpuScalar
{
    unsigned int unk00;
    float value;
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    CpuScalar* value;
    float FUN_00d98420();
};
// @fnv 0x00d98420
float CpuObject::FUN_00d98420()
{
    return value->value;
}

struct hkBoolD984
{
    char m_cBooleanValue;
    hkBoolD984()
    {}
    hkBoolD984(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkpShapeD984
{
    int unk00, unk04, unk08;
    int m_type;
};

struct hkCdBodyD984
{
    const hkpShapeD984* m_pCollisionShape;
};

struct hkpCollisionInputD984;

typedef void(__cdecl* GetPenetrationsFuncD984)(const hkCdBodyD984& bodyA, const hkCdBodyD984& bodyB,
                                               const hkpCollisionInputD984& input, void* collector,
                                               void* startCollector);

struct hkpAgentFuncsD984
{
    GetPenetrationsFuncD984 m_pQueryPenetrationsFunc;
    void* m_getClosestPointsFunc;
    void* m_pLinearCastFunc;
    void* m_bIsFlipped;
    void* m_bIsPredictive;
};

struct hkpCollisionDispatcherD984
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C;
    int unk030, unk034, unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C;
    int unk090, unk094, unk098, unk09C, unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC, unk0E0, unk0E4, unk0E8, unk0EC;
    int unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C;
    int unk150, unk154, unk158, unk15C, unk160, unk164, unk168, unk16C, unk170, unk174, unk178, unk17C;
    int unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C;
    unsigned char m_agent2TypeMap[32][32];
    int unk5A0, unk5A4, unk5A8, unk5AC, unk5B0, unk5B4, unk5B8, unk5BC, unk5C0, unk5C4, unk5C8, unk5CC;
    int unk5D0, unk5D4, unk5D8, unk5DC, unk5E0, unk5E4, unk5E8, unk5EC, unk5F0, unk5F4, unk5F8, unk5FC;
    int unk600, unk604, unk608, unk60C, unk610, unk614, unk618, unk61C, unk620, unk624, unk628, unk62C;
    int unk630, unk634, unk638, unk63C, unk640, unk644, unk648, unk64C, unk650, unk654, unk658, unk65C;
    int unk660, unk664, unk668, unk66C, unk670, unk674, unk678, unk67C, unk680, unk684, unk688, unk68C;
    int unk690, unk694, unk698, unk69C, unk6A0, unk6A4, unk6A8, unk6AC, unk6B0, unk6B4, unk6B8, unk6BC;
    int unk6C0, unk6C4, unk6C8, unk6CC, unk6D0, unk6D4, unk6D8, unk6DC, unk6E0, unk6E4, unk6E8, unk6EC;
    int unk6F0, unk6F4, unk6F8, unk6FC, unk700, unk704, unk708, unk70C, unk710, unk714, unk718, unk71C;
    int unk720, unk724, unk728, unk72C, unk730, unk734, unk738, unk73C, unk740, unk744, unk748, unk74C;
    int unk750, unk754, unk758, unk75C, unk760, unk764, unk768, unk76C, unk770, unk774, unk778, unk77C;
    int unk780, unk784, unk788, unk78C, unk790, unk794, unk798, unk79C, unk7A0, unk7A4, unk7A8, unk7AC;
    int unk7B0, unk7B4, unk7B8, unk7BC, unk7C0, unk7C4, unk7C8, unk7CC, unk7D0, unk7D4, unk7D8, unk7DC;
    int unk7E0, unk7E4, unk7E8, unk7EC, unk7F0, unk7F4, unk7F8, unk7FC, unk800, unk804, unk808, unk80C;
    int unk810, unk814, unk818, unk81C, unk820, unk824, unk828, unk82C, unk830, unk834, unk838, unk83C;
    int unk840, unk844, unk848, unk84C, unk850, unk854, unk858, unk85C, unk860, unk864, unk868, unk86C;
    int unk870, unk874, unk878, unk87C, unk880, unk884, unk888, unk88C, unk890, unk894, unk898, unk89C;
    int unk8A0, unk8A4, unk8A8, unk8AC, unk8B0, unk8B4, unk8B8, unk8BC, unk8C0, unk8C4, unk8C8, unk8CC;
    int unk8D0, unk8D4, unk8D8, unk8DC, unk8E0, unk8E4, unk8E8, unk8EC, unk8F0, unk8F4, unk8F8, unk8FC;
    int unk900, unk904, unk908, unk90C, unk910, unk914, unk918, unk91C, unk920, unk924, unk928, unk92C;
    int unk930, unk934, unk938, unk93C, unk940, unk944, unk948, unk94C, unk950, unk954, unk958, unk95C;
    int unk960, unk964, unk968, unk96C, unk970, unk974, unk978, unk97C, unk980, unk984, unk988, unk98C;
    int unk990, unk994, unk998, unk99C, unk9A0, unk9A4, unk9A8;
    hkpAgentFuncsD984 m_agent2Funcs[1];
};

struct hkpCollisionInputD984
{
    hkpCollisionDispatcherD984* m_pCollisionDispatcher;
};

class hkpCollisionFilterD984
{
  public:
    virtual void V0();
    virtual hkBoolD984 IsCollisionEnabled(const hkCdBodyD984& a, const hkCdBodyD984& b) const;
};

class FUN_00d98430_cls
{
  public:
    int unk00, unk04;
    hkpCollisionFilterD984* m_iFilter;
    void* m_kCollector;
    void* m_startCollector;
    const hkCdBodyD984* m_pBodyA;
    int m_iAgentTypeA;
    int unk1C;
    hkpCollisionInputD984 m_pRayCastInput;

    hkBoolD984 QueryPenetrations(const hkCdBodyD984& bodyB);
};

// Checks if collision is enabled between m_pBodyA and bodyB, then dispatches the penetration query via the agent function table.
// @fnv 0x00d98430
hkBoolD984 FUN_00d98430_cls::QueryPenetrations(const hkCdBodyD984& bodyB)
{
    const hkpShapeD984* shapeB = bodyB.m_pCollisionShape;
    if (shapeB && m_pBodyA != &bodyB && m_iFilter->IsCollisionEnabled(*m_pBodyA, bodyB))
    {
        hkpCollisionDispatcherD984* pDispatcher = m_pRayCastInput.m_pCollisionDispatcher;
        pDispatcher->m_agent2Funcs[pDispatcher->m_agent2TypeMap[m_iAgentTypeA][shapeB->m_type]]
            .m_pQueryPenetrationsFunc(*m_pBodyA, bodyB, m_pRayCastInput, m_kCollector, m_startCollector);
        return true;
    }
    return false;
}
