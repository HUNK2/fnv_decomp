
// src/staging/blk_00de0000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00de0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00de0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;

extern hkReal DAT_0104da48;
extern hkReal DAT_0104da4c;
extern const void* DAT_0108f288[];

inline void* operator new(size_t, void* p) throw()
{
    return p;
}
inline void operator delete(void*, void*) throw()
{}

class hkVector4
{
  public:
    __m128 m_vComponents;

    inline hkVector4& operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    inline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    inline hkReal length3() const
    {
        const __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        const __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
        hkReal r;
        _mm_store_ss(&r, _mm_sqrt_ss(s));
        return r;
    }
};

struct hkpShape
{
    void* m_vtbl;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    int m_type;
};

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    const hkpShape* getShape() const
    {
        return m_pCollisionShape;
    }
};

struct RootContactPoint
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vHitNormal;
    hkVector4 m_extra[5];
};

class hkpCdPointCollector
{
  public:
    const void** m_vtbl;
    hkReal m_fEarlyOutDistance;
};

class hkpFixedBufferCdPointCollector : public hkpCdPointCollector
{
  public:
    inline hkpFixedBufferCdPointCollector(RootContactPoint* buffer, int capacity)
    {
        m_vtbl = DAT_0108f288;
        m_fEarlyOutDistance = DAT_0104da48;
        m_pPointBuffer = buffer;
        m_pointsArray = buffer;
        m_pRayCursor = capacity;
        m_iPointCount = 0;
    }
    RootContactPoint* m_pPointBuffer;
    RootContactPoint* m_pointsArray;
    int m_pRayCursor;
    int m_iPointCount;
};

struct RealIntegerData
{
    hkReal m_fValue;
    int m_iValue;
    int m_unk08;
    int m_unk0c;
};

struct hkpCollisionDispatcher;

struct CollisionAgentContext
{
    hkpCollisionDispatcher* m_pCollisionDispatcher;
    int m_collisionQuality;
    hkReal m_fScalar;
    void* m_iFilter;
    int m_aiValues[16];
};

struct ShapeSweepParameters : public CollisionAgentContext
{
    hkVector4 m_path;
    hkReal m_fMaxExtraPenetration;
    hkReal m_fStartPointTolerance;
    const RealIntegerData* m_pConfiguration;
};

typedef void(__cdecl* LinearCastFunc)(const hkpCdBody&, const hkpCdBody&, const ShapeSweepParameters&,
                                      hkpCdPointCollector&, hkpCdPointCollector*);

struct hkpAgent2Funcs
{
    LinearCastFunc m_pLinearCastFunc;
    void* m_pQueryPenetrationsFunc;
    void* m_pGetPenetrationsFunc;
    void* m_pCreateFunc;
    void* m_pUpdateFilterFunc;
};

struct hkpCollisionDispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    hkUint8 m_agent2TypeMap[0x20][0x20];
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    hkpAgent2Funcs m_agent2Funcs[64];
};

struct CastSettings
{
    int m_unk00[8];
    hkReal m_fScalar;
    hkReal m_fMaxExtraPenetration;
    hkReal m_fHitDistance;
    int m_maxIterations;
};

struct CastJob
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    const hkpCdBody* m_pBodyA;
    const hkpCdBody* m_pBodyB;
    RootContactPoint* m_hitsA;
    int m_capacityA;
    int m_numHitsA;
    RootContactPoint* m_hitsB;
    int m_capacityB;
    int m_numHitsB;
};

static inline void memCpy16(void* dst, const void* src, int numQuads)
{
    unsigned int* d = (unsigned int*)dst;
    const unsigned int* s = (const unsigned int*)src;
    do
    {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d += 4;
        s += 4;
    } while (--numQuads > 0);
}

// @fnv 0x00df7760
void FUN_00df7760(const CastSettings* settings, const CollisionAgentContext* in, CastJob* jobs, int numJobs)
{
    RootContactPoint shapeB[16];
    RootContactPoint idx[16];
    hkpFixedBufferCdPointCollector collA(idx, 16);
    hkpFixedBufferCdPointCollector collB(shapeB, 16);

    RealIntegerData disp;
    disp.m_iValue = settings->m_maxIterations;
    disp.m_fValue = settings->m_fHitDistance;

    ShapeSweepParameters bufB;
    bufB.m_fMaxExtraPenetration = DAT_0104da4c;
    bufB.m_fScalar = settings->m_fScalar;
    bufB.m_collisionQuality = 0;
    bufB.m_pCollisionDispatcher = in->m_pCollisionDispatcher;
    bufB.m_iFilter = in->m_iFilter;
    bufB.m_pConfiguration = &disp;

    for (int i = 0; i < numJobs; i++)
    {
        CastJob& p = jobs[i];
        const hkpShape* res = p.m_pBodyA->getShape();
        const hkpShape* input = p.m_pBodyB->getShape();
        bufB.m_path.setSub4(p.m_vTo, p.m_vFrom);
        bufB.m_fStartPointTolerance = bufB.m_path.length3();
        bufB.m_fScalar = settings->m_fScalar;
        bufB.m_fMaxExtraPenetration = settings->m_fMaxExtraPenetration;
        new (&collA) hkpFixedBufferCdPointCollector(idx, p.m_capacityA);
        if (p.m_hitsB)
        {
            new (&collB) hkpFixedBufferCdPointCollector(shapeB, p.m_capacityB);
        }
        hkpCollisionDispatcher* func = in->m_pCollisionDispatcher;
        LinearCastFunc bodyA = func->m_agent2Funcs[func->m_agent2TypeMap[res->m_type][input->m_type]].m_pLinearCastFunc;
        bodyA(*p.m_pBodyA, *p.m_pBodyB, bufB, collA, p.m_hitsB ? &collB : 0);

        p.m_numHitsA = (hkUint16)collA.m_iPointCount;
        p.m_numHitsB = (hkUint16)collB.m_iPointCount;
        if (p.m_numHitsA > 0)
        {
            memCpy16(p.m_hitsA, idx, p.m_numHitsA * (sizeof(RootContactPoint) / 16));
        }
        if (p.m_hitsB && p.m_numHitsB > 0)
        {
            memCpy16(p.m_hitsB, shapeB, p.m_numHitsB * (sizeof(RootContactPoint) / 16));
        }
    }
}

struct FinishingFlag
{
    int finishing;
    explicit FinishingFlag(int value) : finishing(value)
    {}
};
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw();
    explicit hkBaseObject(FinishingFlag) throw()
    {}
};
class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short sizeAndFlags;
    short referenceCount;
    explicit hkReferencedObject(FinishingFlag flag) throw() : hkBaseObject(flag)
    {}
};
template <class T> struct SceneArray
{
    T* data;
    int size;
    int capacityAndFlags;
    explicit SceneArray(FinishingFlag) throw()
    {}
};
class hkStringPtr
{
  public:
    const char* text;
    explicit hkStringPtr(FinishingFlag) throw();
};
struct SceneAttribute;
struct SceneMatrix;
struct SceneAnnotation;
class hkxAttributeHolder : public hkReferencedObject
{
  public:
    SceneArray<SceneAttribute> attributes;
    explicit hkxAttributeHolder(FinishingFlag flag) throw() : hkReferencedObject(flag), attributes(flag)
    {}
};
class hkxNode : public hkxAttributeHolder
{
  public:
    hkStringPtr name;
    hkReferencedObject* object;
    SceneArray<SceneMatrix> keyFrames;
    SceneArray<hkxNode*> children;
    SceneArray<SceneAnnotation> annotations;
    hkStringPtr userProperties;
    bool selected;
    bool bone;
    explicit hkxNode(FinishingFlag flag) throw()
        : hkxAttributeHolder(flag), name(flag), keyFrames(flag), children(flag), annotations(flag), userProperties(flag)
    {}
    virtual ~hkxNode() throw();
};

// @fnv 0x00dfd800
void* __cdecl getVtable_hkxNode()
{
    __declspec(align(16)) unsigned char storage[sizeof(hkxNode)];
    new (storage) hkxNode(FinishingFlag(0));
    return *reinterpret_cast<void**>(storage);
}
