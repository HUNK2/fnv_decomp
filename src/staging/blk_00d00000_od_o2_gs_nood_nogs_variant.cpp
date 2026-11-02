
// src/staging/blk_00d00000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00d00000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d00000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_add_ps(__m128, __m128);

struct hkVector4f
{
    float x;
    float y;
    float z;
    float w;
};

union hkQuadVector
{
    hkVector4f v;
    __m128 q;
};

struct hkTransformf
{
    hkVector4f m_kColumn0;
    hkVector4f m_kColumn1;
    hkVector4f m_kColumn2;
    hkVector4f m_vTranslation;
};

struct hkAabbf
{
    hkVector4f m_kMinimumCorner;
    hkVector4f m_kMaximumCorner;
};

struct hkTransform
{
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_vTranslation;
    void FUN_00cb23e0(const hkTransform& t);
};

union hkAabbQ
{
    hkAabbf f;
    struct
    {
        __m128 m_kMinimumCorner;
        __m128 m_kMaximumCorner;
    } q;
};

class hkpPhantom
{
  public:
    virtual ~hkpPhantom();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual int getType() const;
};

class hkpShapePhantom : public hkpPhantom
{
  public:
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
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    hkTransformf m_kMotionState;
    void FUN_00c9e910(const hkTransform& t);
};

class hkpAabbPhantom : public hkpPhantom
{
  public:
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
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    hkAabbf m_kBounds;
    void FUN_00cf24a0(const hkAabbQ& aabb);
};

// @fnv 0x00d05df0
void __cdecl FUN_00d05df0(hkpPhantom* phantom, const hkTransform& transform)
{
    switch (phantom->getType())
    {
    case 1:
    case 2: {
        hkpShapePhantom* sp = static_cast<hkpShapePhantom*>(phantom);
        hkQuadVector c0;
        hkQuadVector c1;
        hkQuadVector c2;
        hkQuadVector t;
        c0.v = sp->m_kMotionState.m_kColumn0;
        c1.v = sp->m_kMotionState.m_kColumn1;
        c2.v = sp->m_kMotionState.m_kColumn2;
        t.v = sp->m_kMotionState.m_vTranslation;
        hkTransform current;
        current.m_kColumn0 = c0.q;
        current.m_kColumn1 = c1.q;
        current.m_kColumn2 = c2.q;
        current.m_vTranslation = t.q;
        current.FUN_00cb23e0(transform);
        sp->FUN_00c9e910(current);
        break;
    }
    case 0: {
        hkpAabbPhantom* ap = static_cast<hkpAabbPhantom*>(phantom);
        hkAabbQ aabb;
        aabb.f = ap->m_kBounds;
        aabb.q.m_kMinimumCorner = _mm_add_ps(transform.m_vTranslation, aabb.q.m_kMinimumCorner);
        aabb.q.m_kMaximumCorner = _mm_add_ps(transform.m_vTranslation, aabb.q.m_kMaximumCorner);
        ap->FUN_00cf24a0(aabb);
        break;
    }
    }
}
