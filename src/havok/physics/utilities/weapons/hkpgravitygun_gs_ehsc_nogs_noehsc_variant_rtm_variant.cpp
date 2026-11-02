// src/havok/physics/utilities/weapons/hkpgravitygun_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/weapons/hkpgravitygun_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/utilities/weapons/hkpgravitygun_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/weapons/hkpgravitygun.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/weapons/hkpgravitygun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpgravitygun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpGravityGun.h"
struct FUN_00e45fb0_class
{
    void FUN_00e45e60(int);
    void FUN_00e45fb0(int, int, int);
};
struct DDCC60World
{
    void removeReference();
};
struct FUN_00e45fc0_class
{
    unsigned char m_unknown[0x20];
    DDCC60World** m_kExternalLinks;
    int m_sReferenceCount;

    void RemoveAllReferences(int);
};
struct hkFinishLoadedObjectFlagE463
{
    int m_bFinishing;
};
template <class T> class hkArrayE463
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayE463() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
class FUN_00e466a0
{
  public:
    FUN_00e466a0(hkFinishLoadedObjectFlagE463 flag);
    virtual ~FUN_00e466a0();

    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    hkUint8 m_type;
    const char* m_name;
    hkUint8 m_uiKeyboardKey;
    hkArrayE463<void*> m_kListeners;
};
class hkpRigidBodyE463;
class FUN_00e46300 : public FUN_00e466a0
{
  public:
    hkArrayE463<hkpRigidBodyE463*> m_kPickedBodies;

    FUN_00e46300(hkFinishLoadedObjectFlagE463 flag);
    virtual ~FUN_00e46300();
};
#include <xmmintrin.h>
extern double DAT_01016408;
struct Body_e45e
{
    int unk[0x1a0 / 4];
    __m128 m_kInertiaAndMassInv;
    void FUN_00ca88e0(float mass);
    void FUN_00c905b0();
    float getMassInv() const
    {
        float w;
        _mm_store_ss(&w, _mm_shuffle_ps(m_kInertiaAndMassInv, m_kInertiaAndMassInv, 0xff));
        return w;
    }
};
struct World_e45e
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    Body_e45e** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    Body_e45e* FUN_00e45e60(int index);
};

struct ObjE45
{
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
    unsigned short unk28;
    unsigned char unk2a;
    void OnTrigger(int);
};

struct MotionE45
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
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void SetCollisionShape(const hkVector4& impulse);
};

struct BodyE45
{
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
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    MotionE45 m_pMotionState;
    void FUN_00c9c1d0();
};

struct ViewE45
{
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
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    __m128 m_kTranslationalVelocity;
};

extern double DAT_01011588;
extern "C" void _ReadWriteBarrier(void);

static inline __m128 bcastE45(const float& f)
{
    __m128 s = _mm_load_ss(&f);
    return _mm_shuffle_ps(s, s, 0);
}

struct hkpGravityGunE45 : public hkpGravityGun
{
    ObjE45* FUN_00e45e60(int);
    BodyE45* FUN_00e45a60(int, int, int);
    void FUN_00e45ee0(int dirSlot, int viewSlot, int p3Slot);
};

// @fnv 0x00e45ee0
void hkpGravityGunE45::FUN_00e45ee0(int dirSlot, int viewSlot, int p3Slot)
{
    union
    {
        __m128 q;
        float f[4];
    } v;
    if (m_kPickedBodies.m_iElementCount != 0)
    {
        ObjE45* body = FUN_00e45e60(0);
        v.q = _mm_mul_ps(bcastE45(m_fHoldDistance), *(const __m128*)dirSlot);
        v.f[1] = (float)(v.f[1] + DAT_01011588);
        v.q = _mm_add_ps(((const ViewE45*)viewSlot)->m_kTranslationalVelocity, v.q);
        body->OnTrigger((int)&v);
        body->unk2a = 6;
    }
    else
    {
        BodyE45* body = FUN_00e45a60(dirSlot, viewSlot, p3Slot);
        if (body)
        {
            __m128 dir = *(const __m128*)dirSlot;
            v.q = dir;
            v.q = _mm_mul_ps(bcastE45(m_fPickAngle), v.q);
            body->FUN_00c9c1d0();
            body->m_pMotionState.SetCollisionShape(*(const hkVector4*)&v);
        }
    }
}

#include <xmmintrin.h>
extern const __m128 DAT_010ec7f0;
extern const __m128 DAT_01017d10;
struct hkSimdRealEx
{
    __m128 m_vValue;
    __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    hkSimdRealEx(const __m128& v) : m_vValue(v)
    {}
    operator float() const
    {
        float value;
        _mm_store_ss(&value, m_vValue);
        return value;
    }
    hkSimdRealEx(float f)
    {
        m_vValue = _mm_load_ss(&f);
    }
};
struct hkVector4Ex : public hkVector4
{
    hkVector4Ex()
    {}
    hkVector4Ex(const hkVector4Ex& a)
    {
        *(__m128*)this = *(__m128*)&a;
    }
    hkVector4Ex& operator=(const hkVector4Ex& a)
    {
        *(__m128*)this = *(__m128*)&a;
        return *this;
    }
    __declspec(noinline) void FUN_00c7f640(const hkTransform& t, const hkVector4& in)
    {
        __m128 v = *(__m128*)&in;
        __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), *(__m128*)&t.m_rotation.m_kColumn1);
        __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), *(__m128*)&t.m_rotation.m_kColumn0);
        __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), *(__m128*)&t.m_rotation.m_kColumn2);
        *(__m128*)this = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, *(__m128*)&t.m_vTranslation));
    }
    void setAddMul4(const hkVector4& a, const hkVector4& b, const hkSimdRealEx& s)
    {
        __m128 sv = s.broadcast();
        *(__m128*)this = _mm_add_ps(*(__m128*)&a, _mm_mul_ps(sv, *(__m128*)&b));
    }
    void setInterpolate4(const hkVector4& a, const hkVector4& b, const hkSimdRealEx& t)
    {
        __m128 tv = t.broadcast();
        __m128 one_minus_t = _mm_sub_ps(DAT_010ec7f0, tv);
        *(__m128*)this = _mm_add_ps(_mm_mul_ps(one_minus_t, *(__m128*)&a), _mm_mul_ps(tv, *(__m128*)&b));
    }
    bool equals4(const hkVector4& a, float eps = 0.001f) const
    {
        __m128 diff = _mm_sub_ps(*(__m128*)this, *(__m128*)&a);
        __m128 absDiff = _mm_and_ps(diff, DAT_01017d10);
        __m128 eps_v = _mm_set1_ps(eps);
        return (_mm_movemask_ps(_mm_cmple_ps(absDiff, eps_v)) & 0xf) == 0xf;
    }
    hkSimdRealEx lengthSquared3() const
    {
        __m128 v = *(__m128*)this;
        __m128 mul = _mm_mul_ps(v, v);
        __m128 shuf1 = _mm_shuffle_ps(mul, mul, 0x55);
        __m128 add1 = _mm_add_ss(shuf1, mul);
        __m128 shuf2 = _mm_shuffle_ps(mul, mul, 0xaa);
        __m128 add2 = _mm_add_ss(shuf2, add1);
        return hkSimdRealEx(add2);
    }
};
struct hkpMotion
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0c();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1c();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2c();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3c();
    virtual void SetTranslationalVelocity(const hkVector4&);
    virtual void SetRotationalVelocity(const hkVector4&);
    int unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    hkVector4Ex m_vContactPosition;  // 0x60
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    hkVector4Ex m_kTranslationalVelocity;  // 0xd0
    hkVector4Ex m_kAngularVelocity;        // 0xe0
};
struct hkpRigidBody
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, selfUnk6c;
    int unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac;
    int unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc;
    int unkd0, unkd4, unkd8, unkdc;
    hkpMotion m_pMotionState;  // 0xe0
    void FUN_00c9c1d0();
};
struct hkpGravityGunEx : public hkpGravityGun
{
    __declspec(noinline) void FUN_00e45c90(float dTime, const hkTransform& transform, hkpRigidBody* otherRb);
};
// @fnv 0x00e45c90
__declspec(noinline) void hkpGravityGunEx::FUN_00e45c90(float dTime, const hkTransform& transform,
                                                        hkpRigidBody* otherRb)
{
    for (int i = 0; i < m_kPickedBodies.m_iElementCount; ++i)
    {
        const double gain = 0.4f;
        float invDTime = (float)(gain / dTime);
        hkVector4Ex localPos;
        localPos.setAddMul4(m_kGrabPosition, m_kTargetPosition, (float)i);
        hkVector4Ex targetPos;
        targetPos.FUN_00c7f640(transform, localPos);
        hkpRigidBody* rb = (hkpRigidBody*)m_kPickedBodies.m_data[i];
        hkVector4Ex newLinearVelocity = rb->m_pMotionState.m_kTranslationalVelocity;
        newLinearVelocity.setInterpolate4(rb->m_pMotionState.m_kTranslationalVelocity,
                                          otherRb->m_pMotionState.m_kTranslationalVelocity, 0.8f);
        __m128 deltaPos = _mm_sub_ps(*(__m128*)&targetPos, *(__m128*)&rb->m_pMotionState.m_vContactPosition);
        __m128 invDTimeVec = hkSimdRealEx(invDTime).broadcast();
        *(__m128*)&newLinearVelocity = _mm_add_ps(_mm_mul_ps(deltaPos, invDTimeVec), *(__m128*)&newLinearVelocity);
        if (!newLinearVelocity.equals4(rb->m_pMotionState.m_kTranslationalVelocity))
        {
            rb->FUN_00c9c1d0();
            rb->m_pMotionState.SetTranslationalVelocity(newLinearVelocity);
        }
        const float minSq = 1.0f;
        hkVector4Ex newAngularVelocity;
        *(__m128*)&newAngularVelocity =
            _mm_mul_ps(hkSimdRealEx(0.8f).broadcast(), *(__m128*)&rb->m_pMotionState.m_kAngularVelocity);
        if (float(newAngularVelocity.lengthSquared3()) > minSq)
        {
            if (!newAngularVelocity.equals4(rb->m_pMotionState.m_kAngularVelocity))
            {
                rb->FUN_00c9c1d0();
                rb->m_pMotionState.SetRotationalVelocity(newAngularVelocity);
            }
        }
    }
}
