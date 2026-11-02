
// src/havok/physics/collide/query/castutil/hkpsimpleworldraycaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/castutil/hkpsimpleworldraycaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
struct S_00cfa890_Vector4
{
    float x, y, z, w;
    __m128& q()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& q() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }

    __forceinline void _setRotatedDir(const S_00cfa890_Vector4* r, const S_00cfa890_Vector4& b)
    {
        const __m128 b0 = _mm_shuffle_ps(b.q(), b.q(), _MM_SHUFFLE(0, 0, 0, 0));
        const __m128 r0 = _mm_mul_ps(r[0].q(), b0);
        const __m128 b1 = _mm_shuffle_ps(b.q(), b.q(), _MM_SHUFFLE(1, 1, 1, 1));
        const __m128 r1 = _mm_mul_ps(r[1].q(), b1);
        const __m128 b2 = _mm_shuffle_ps(b.q(), b.q(), _MM_SHUFFLE(2, 2, 2, 2));
        const __m128 r2 = _mm_mul_ps(r[2].q(), b2);
        q() = _mm_add_ps(_mm_add_ps(r0, r1), r2);
    }

    __forceinline void _setRotatedInverseDir(const S_00cfa890_Vector4* r, const __m128& b)
    {
        __m128 c0 = r[0].q();
        __m128 c1 = r[1].q();
        __m128 c2 = r[2].q();
        {
            __m128 tmp = _mm_unpacklo_ps(c0, c1);
            __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, _MM_SHUFFLE(3, 2, 1, 0));
            c0 = _mm_movelh_ps(tmp, c2);
            c1 = _mm_movehl_ps(c0, tmp);
            c1 = _mm_shuffle_ps(c1, c2, _MM_SHUFFLE(3, 1, 1, 0));
            c2 = ctmp;
        }
        const __m128 b0 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(0, 0, 0, 0));
        const __m128 r0 = _mm_mul_ps(c0, b0);
        const __m128 b1 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(1, 1, 1, 1));
        const __m128 r1 = _mm_mul_ps(c1, b1);
        const __m128 b2 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(2, 2, 2, 2));
        const __m128 r2 = _mm_mul_ps(c2, b2);
        q() = _mm_add_ps(_mm_add_ps(r0, r1), r2);
    }

    __forceinline void _setTransformedInversePos(const S_00cfa890_Vector4* t, const S_00cfa890_Vector4& b)
    {
        __m128 t0 = _mm_sub_ps(b.q(), t[3].q());
        _setRotatedInverseDir(t, t0);
    }
};

struct S_00cfa890_Bool
{
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct S_00cfa890_RayInput
{
    S_00cfa890_Vector4 m_vFrom;
    S_00cfa890_Vector4 m_vTo;
    int m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
    int unk28;
    int unk2C;
};

struct S_00cfa890_ShapeRayInput
{
    S_00cfa890_Vector4 m_vFrom;
    S_00cfa890_Vector4 m_vTo;
    unsigned int m_uiFilterInfo;
};

struct S_00cfa890_Collidable;

struct S_00cfa890_Output
{
    S_00cfa890_Vector4 m_vHitNormal;
    float m_fHitFraction;
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
    const S_00cfa890_Collidable* m_pRootCollidable;
};

struct S_00cfa890_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual S_00cfa890_Bool RayCast(const S_00cfa890_ShapeRayInput& input, S_00cfa890_Output& output) const;
};

struct S_00cfa890_Collidable
{
    const S_00cfa890_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S_00cfa890_Collidable* m_parent;
    const S_00cfa890_Vector4* getTransform() const
    {
        return (const S_00cfa890_Vector4*)m_pMotionState;
    }
};

struct S_00cfa890_Handle
{
    int m_iOwnerObjectOffset;
    char unk04;
    signed char m_iOwnerOffset;
    void* getOwner() const
    {
        return (char*)this + m_iOwnerOffset;
    }
};

struct S_00cfa890_Filter
{
    virtual void v00();
    virtual S_00cfa890_Bool IsCollisionEnabled(const S_00cfa890_RayInput& input,
                                               const S_00cfa890_Collidable& col) const;
};

struct S_00cfa890_RayCaster
{
    void* vtbl;
    const S_00cfa890_RayInput* m_pRayCastInput;
    const S_00cfa890_Filter* m_iFilter;
    S_00cfa890_Output* m_result;
    S_00cfa890_ShapeRayInput m_kShapeRayInput;

    float RayCastCollidable(const S_00cfa890_Handle* broadPhaseHandle, int castIndex);
};

// Transforms the ray into the collidable's local space, tests its shape for a hit, and stores the hit fraction and root collidable in m_result.
// @fnv 0x00cfa890
float S_00cfa890_RayCaster::RayCastCollidable(const S_00cfa890_Handle* broadPhaseHandle, int castIndex)
{
    const S_00cfa890_Collidable* col = (const S_00cfa890_Collidable*)broadPhaseHandle->getOwner();
    const S_00cfa890_Shape* shape = col->m_pCollisionShape;
    if (shape)
    {
        if (m_iFilter->IsCollisionEnabled(m_pRayCastInput[castIndex], *col))
        {
            const S_00cfa890_Vector4* pTransform = col->getTransform();
            m_kShapeRayInput.m_vFrom._setTransformedInversePos(pTransform, m_pRayCastInput[castIndex].m_vFrom);
            m_kShapeRayInput.m_vTo._setTransformedInversePos(pTransform, m_pRayCastInput[castIndex].m_vTo);
            m_kShapeRayInput.m_uiFilterInfo = m_pRayCastInput[castIndex].m_uiFilterInfo;
            S_00cfa890_Bool hit = shape->RayCast(m_kShapeRayInput, *m_result);
            if (hit)
            {
                m_result->m_pRootCollidable = col;
                m_result->m_vHitNormal._setRotatedDir(pTransform, m_result->m_vHitNormal);
            }
        }
    }
    return m_result->m_fHitFraction;
}
