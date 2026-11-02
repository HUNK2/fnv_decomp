
// src/havok/physics/collide/query/castutil/hkpworldraycaster.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/castutil/hkpworldraycaster.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128;

extern "C" __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_add_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_sub_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_shuffle_ps(__m128 _A, __m128 _B, unsigned int _Imm8);
extern "C" __m128 _mm_unpacklo_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_unpackhi_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_movelh_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_movehl_ps(__m128 _A, __m128 _B);

class hkBool
{
  public:
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkRotation;
class hkTransform;

class hkVector4
{
  public:
    __m128 m_vComponents;
    hkVector4& operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline void _setRotatedInverseDir(const hkRotation& r, const hkVector4& b);
    __forceinline void SetTransformedPosition(const hkTransform& a, const hkVector4& b);
};

class hkRotation
{
  public:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};

class hkTransform
{
  public:
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};

__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    __m128 v = b.m_vComponents;
    __m128 c0 = r.m_kColumn0.m_vComponents;
    __m128 c1 = r.m_kColumn1.m_vComponents;
    __m128 c2 = r.m_kColumn2.m_vComponents;
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
    c0 = _mm_movelh_ps(tmp, c2);
    c1 = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(c1, c2, 0xd4);
    c2 = ctmp;
    __m128 r1 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1);
    __m128 r0 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), c0);
    __m128 r2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), r2);
}

__forceinline void hkVector4::SetTransformedPosition(const hkTransform& a, const hkVector4& b)
{
    hkVector4 t0;
    t0.m_vComponents = _mm_sub_ps(b.m_vComponents, a.m_vTranslation.m_vComponents);
    _setRotatedInverseDir(a.m_rotation, t0);
}

class hkpCdBody;
class hkpRayHitCollector;
struct ShapeRayCastQuery;

class hkpShape
{
  public:
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void castRayWithCollector(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                      hkpRayHitCollector& collector) const = 0;
};

class hkpCdBody
{
  public:
    const hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBody* m_parent;
    const hkpShape* getShape() const
    {
        return m_pCollisionShape;
    }
    const hkTransform& getTransform() const
    {
        return *(const hkTransform*)m_pMotionState;
    }
};

class hkpCollidable : public hkpCdBody
{
};

struct hkpTypedBroadPhaseHandle
{
    unsigned int m_iOwnerObjectOffset;
    signed char m_type;
    signed char m_iOwnerOffset;
    void* getOwner() const
    {
        return (void*)((char*)this + m_iOwnerOffset);
    }
};

struct WorldRayCastInput
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    hkBool m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
};

struct ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    unsigned int m_uiFilterInfo;
};

class hkpRayHitCollector
{
  public:
    void* m_vtbl;
    float m_fEarlyOutHitFraction;
};

class hkpRayCollidableFilter
{
  public:
    virtual void v00() = 0;
    virtual hkBool IsCollisionEnabled(const WorldRayCastInput& input, const hkpCollidable& collidable) const = 0;
};

class hkpWorldRayCaster
{
  public:
    void* m_vtbl;
    const WorldRayCastInput* m_pRayCastInput;
    const hkpRayCollidableFilter* m_iFilter;
    hkpRayHitCollector* m_pCollectorBase;
    int m_iCollectorStriding;
    ShapeRayCastQuery m_kShapeRayInput;

    float CastRay(const hkpTypedBroadPhaseHandle* broadPhaseHandle, int castIndex);
};

// @fnv 0x00cbf710
float hkpWorldRayCaster::CastRay(const hkpTypedBroadPhaseHandle* broadPhaseHandle, int castIndex)
{
    const hkpCollidable* col = (const hkpCollidable*)broadPhaseHandle->getOwner();
    const hkpShape* shape = col->getShape();

    hkpRayHitCollector* collector = (hkpRayHitCollector*)((char*)m_pCollectorBase + m_iCollectorStriding * castIndex);

    if (shape)
    {
        const WorldRayCastInput& input = m_pRayCastInput[castIndex];
        if (m_iFilter->IsCollisionEnabled(input, *col))
        {
            const hkTransform& trans = col->getTransform();
            m_kShapeRayInput.m_vFrom.SetTransformedPosition(trans, m_pRayCastInput->m_vFrom);
            m_kShapeRayInput.m_vTo.SetTransformedPosition(trans, input.m_vTo);
            m_kShapeRayInput.m_uiFilterInfo = input.m_uiFilterInfo;
            shape->castRayWithCollector(m_kShapeRayInput, *col, *collector);
        }
    }
    return collector->m_fEarlyOutHitFraction;
}
