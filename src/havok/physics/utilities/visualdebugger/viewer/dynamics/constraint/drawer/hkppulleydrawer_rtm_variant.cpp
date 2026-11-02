
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppulleydrawer_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppulleydrawer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppulleydrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppulleydrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_load_ps1(const float*);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);

typedef float hkReal;
extern double DAT_01011598;

struct hkTransform;
struct hkRotation;

struct hkVector4
{
    __m128 m_vComponents;
    void set(hkReal x, hkReal y, hkReal z, hkReal w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    void setMul4(hkReal r, const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(_mm_load_ps1(&r), v.m_vComponents);
    }
    void setMul4_b(hkReal r, const hkVector4& v)
    {
        __m128 s = _mm_load_ss(&r);
        s = _mm_shuffle_ps(s, s, 0);
        m_vComponents = _mm_mul_ps(s, v.m_vComponents);
    }
    void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    void FUN_00c7f640(const hkTransform& transform, const hkVector4& position);
    void FUN_00c7f700(const hkRotation& rotation, const hkVector4& direction);
};

struct hkRotation
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};

struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};

struct hkpEntity
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec;
    hkRotation m_rotation;
};

struct hkpPulleyConstraintData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    hkVector4 m_kTranslationA;
    hkVector4 m_kTranslationB;
    hkVector4 unk40;
    hkVector4 m_kFixedPivotA;
    hkVector4 m_kFixedPivotB;
    hkReal unk70;
    hkReal m_fRopeLength;
};

struct hkpConstraintInstance
{
    int unk00;
    int unk04;
    int unk08;
    hkpPulleyConstraintData* m_data;
    int unk10;
    int unk14;
    hkpEntity* m_pEntityB;
};

struct VecAddress
{
    const hkVector4* p;
    VecAddress(const hkVector4* a) : p(a)
    {}
};

struct hkDebugDisplayHandler
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual int DisplayLine(const hkVector4& start, VecAddress end, unsigned int color, int id, int tag);
};

struct DebugDisplayHandlerHolder
{
    void FUN_00e10a10(hkDebugDisplayHandler* displayHandler);
};

template <class T> inline T hkMax2(T a, T b)
{
    return a > b ? a : b;
}

struct ConstraintVisualizer
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    hkVector4 m_vVectorAtOffset40;
    hkVector4 m_vVectorAtOffset50;
    hkVector4 unk60;
    hkVector4 unk70;
    hkVector4 unk80;
    hkVector4 unk90;
    hkVector4 unka0;
    hkVector4 unkb0;
    DebugDisplayHandlerHolder m_kDisplayGeometry;

    void FUN_00de47e0(hkpConstraintInstance* constraint, hkTransform& refLocalToWorld, hkTransform& attLocalToWorld);
    void FUN_00de44c0(int id, int tag);
    void FUN_00de4530(int id, int tag);
    void FUN_00de6550(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int id, int tag);
};

// @fnv 0x00de6550
void ConstraintVisualizer::FUN_00de6550(hkpConstraintInstance* constraint, hkDebugDisplayHandler* displayHandler, int id,
                                   int tag)
{
    hkpPulleyConstraintData* pulley = constraint->m_data;
    m_kDisplayGeometry.FUN_00e10a10(displayHandler);
    {
        hkTransform refLocalToWorld;
        hkTransform attLocalToWorld;
        FUN_00de47e0(constraint, refLocalToWorld, attLocalToWorld);
        m_vVectorAtOffset50.FUN_00c7f640(refLocalToWorld, pulley->m_kTranslationB);
        m_vVectorAtOffset40.FUN_00c7f640(attLocalToWorld, pulley->m_kTranslationA);
    }
    FUN_00de44c0(id, tag);
    FUN_00de4530(id, tag);

    displayHandler->DisplayLine(pulley->m_kFixedPivotA, VecAddress(&pulley->m_kFixedPivotB), 0xffc0c0c0, id, tag);
    displayHandler->DisplayLine(m_vVectorAtOffset40, VecAddress(&pulley->m_kFixedPivotA), 0xffffffff, id, tag);

    int numRopes = int(hkMax2(pulley->m_fRopeLength, 1.0f));
    hkVector4 offset;
    offset.set(0.07f, 0.0f, 0.0f, 0.0f);
    offset.FUN_00c7f700(constraint->m_pEntityB->m_rotation, offset);
    hkVector4 start;
    start.setMul4_b(hkReal((numRopes - 1) * DAT_01011598), offset);
    for (int i = 0; i < numRopes; i++)
    {
        hkVector4 delta;
        delta.setMul4(hkReal(i), offset);
        delta.add4(start);
        hkVector4 ropeStart;
        ropeStart.setAdd4(m_vVectorAtOffset50, delta);
        hkVector4 ropeEnd;
        ropeEnd.setAdd4(delta, pulley->m_kFixedPivotB);
        displayHandler->DisplayLine(ropeStart, VecAddress(&ropeEnd), 0xffffffff, id, tag);
    }
}
