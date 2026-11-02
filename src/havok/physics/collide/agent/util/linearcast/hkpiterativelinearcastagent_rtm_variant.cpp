// src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/util/linearcast/hkpiterativelinearcastagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _ReadWriteBarrier();

struct __declspec(align(16)) hkVector4
{
    union
    {
        __m128 quad;
        struct
        {
            float x, y, z, w;
        };
        float lanes[4];
    };

    __forceinline const float& component(int k) const
    {
        return lanes[k];
    }
    __forceinline float& component(int k)
    {
        return lanes[k];
    }
    __forceinline void SetAllComponents(float v)
    {
        __m128 t = _mm_load_ss(&v);
        quad = _mm_shuffle_ps(t, t, 0);
    }
};

struct __declspec(align(16)) hkTransform
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;
    hkVector4 m_center0;
    hkVector4 m_center1;
    hkVector4 m_qRotation0;
    hkVector4 m_qRotation1;
    hkVector4 m_centerLocal;
    hkVector4 m_kDeltaAngle;
    float m_fSphereRadius;
    float m_linearLimit;
    float m_fAngularLimit;
    float m_timeFactor;
    void FUN_00d431b0(const void* src);
};

struct hkpShape
{
    void* vtable;
    int unk04;
    int unk08;
    int m_type;
};

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_kMotionState;
    const hkpCdBody* m_parent;
};

struct __declspec(align(16)) hkContactPoint
{
    __forceinline float distanceValue() const
    {
        return m_vSeparatingNormal.w;
    }
    __forceinline void assignDistance(float value)
    {
        m_vSeparatingNormal.component(3) = value;
    }
    __forceinline void assignPlane(const hkVector4& value, float distance)
    {
        m_vSeparatingNormal.quad = value.quad;
        assignDistance(distance);
    }

    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
};

struct __declspec(align(16)) RootContactPoint
{
    hkContactPoint m_kPoint;
    const hkpCdBody* m_pRootCollidableA;
    const hkpCdBody* m_pRootCollidableB;
};

struct hkpCdPointCollector
{
    virtual void unk_dtor();
    virtual void AddCdPoint(const RootContactPoint& point) = 0;
    float m_fEarlyOutDistance;
};

extern float DAT_0104da48;
extern char DAT_010cebe0;
struct __declspec(align(16)) hkpSimpleClosestContactCollector
{
    void* m_ppVirtualMethodTable;
    float m_fEarlyOutDistance;
    bool m_bHit;
    hkContactPoint m_kHitPoint;
    __forceinline hkpSimpleClosestContactCollector()
    {
        m_fEarlyOutDistance = m_kHitPoint.m_vSeparatingNormal.w = DAT_0104da48;
        m_ppVirtualMethodTable = &DAT_010cebe0;
        m_bHit = false;
    }
};

typedef void (*hkpLinearCastFunc)(const hkpCdBody*, const hkpCdBody*, const void*, hkpCdPointCollector*) throw();

struct hkpLinearCastPath
{
    float m_minDistance;
    int m_numIterations;
};

struct __declspec(align(16)) CollisionAgentContext
{
    void* m_pCollisionDispatcher;
    int unk04;
    float m_fScalar;
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
};

struct __declspec(align(16)) ShapeSweepParameters : public CollisionAgentContext
{
    hkVector4 m_step;
    float m_extraPenetration;
    float m_fMaxExtraPenetration;
    hkpLinearCastPath* m_path;
};

__forceinline float dot3(const hkVector4& a, const hkVector4& b)
{
    __m128 mul = _mm_mul_ps(a.quad, b.quad);
    __m128 shuf1 = _mm_shuffle_ps(mul, mul, 0x55);
    __m128 shuf2 = _mm_shuffle_ps(mul, mul, 0xaa);
    __m128 sum = _mm_add_ss(shuf1, mul);
    sum = _mm_add_ss(shuf2, sum);
    float res;
    _mm_store_ss(&res, sum);
    return res;
}

struct hkpIterativeLinearCastAgent
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void CastImpl(const hkpCdBody*, const hkpCdBody*, const void*, hkpSimpleClosestContactCollector*);
    void FUN_00daf540(const hkpCdBody* bodyA, const hkpCdBody* bodyB, const ShapeSweepParameters* input,
                      hkpCdPointCollector* castCollector, hkpCdPointCollector* startCollector);
};

// @fnv 0x00daf540
void hkpIterativeLinearCastAgent::FUN_00daf540(const hkpCdBody* bodyA, const hkpCdBody* bodyB,
                                               const ShapeSweepParameters* input, hkpCdPointCollector* castCollector,
                                               hkpCdPointCollector* startCollector)
{
    hkpSimpleClosestContactCollector localCastCollector;
    CollisionAgentContext linearInput = *input;
    linearInput.m_fScalar += input->m_fMaxExtraPenetration;
    CastImpl(bodyA, bodyB, &linearInput, &localCastCollector);
    if (!localCastCollector.m_bHit)
        return;

    RootContactPoint hitPoint;
    hitPoint.m_kPoint.m_vContactPosition.quad = localCastCollector.m_kHitPoint.m_vContactPosition.quad;
    hitPoint.m_pRootCollidableB = bodyB;
    hitPoint.m_pRootCollidableA = bodyA;
    hitPoint.m_kPoint.m_vSeparatingNormal.quad = localCastCollector.m_kHitPoint.m_vSeparatingNormal.quad;

    const float& distance = localCastCollector.m_kHitPoint.m_vSeparatingNormal.w;
    if (distance < input->m_fScalar && startCollector)
        startCollector->AddCdPoint(hitPoint);

    hkVector4 step;
    step.quad = input->m_step.quad;
    float closing = dot3(step, localCastCollector.m_kHitPoint.m_vSeparatingNormal);
    float endpoint = distance + closing;
    if (endpoint > 0.0f)
        return;
    if (0.0 <= closing + input->m_extraPenetration)
        return;
    const hkpLinearCastPath* path = input->m_path;
    if (path->m_minDistance >= distance)
    {
        if (distance > 0.0f)
        {
            float t = distance / (distance - endpoint);
            if (t > castCollector->m_fEarlyOutDistance)
                return;
            hitPoint.m_kPoint.assignDistance(t);
        }
        else
        {
            hitPoint.m_kPoint.assignDistance(0.0f);
        }
        castCollector->AddCdPoint(hitPoint);
        return;
    }

    hitPoint.m_kPoint.assignDistance(distance / (distance - endpoint));
    hkpSimpleClosestContactCollector projectedDistance;
    hkTransform motion;
    motion.FUN_00d431b0(bodyA->m_kMotionState);
    hkpCdBody movedBody;
    movedBody.m_parent = bodyA;
    movedBody.m_kMotionState = &motion;
    movedBody.m_pCollisionShape = bodyA->m_pCollisionShape;
    movedBody.m_uiCollisionShapeKey = 0xffffffff;
    int iterations = path->m_numIterations;
    while (--iterations >= 0)
    {
        projectedDistance.m_kHitPoint.m_vSeparatingNormal.w = DAT_0104da48;
        projectedDistance.m_fEarlyOutDistance = DAT_0104da48;
        projectedDistance.m_bHit = false;
        hkVector4 delta;
        float broadcast = hitPoint.m_kPoint.distanceValue();
        delta.SetAllComponents(broadcast);
        motion.m_vTranslation.quad = _mm_add_ps(_mm_mul_ps(delta.quad, step.quad),
                                                ((const hkTransform*)bodyA->m_kMotionState)->m_vTranslation.quad);
        CastImpl(&movedBody, bodyB, &linearInput, &projectedDistance);

        step.quad = input->m_step.quad;
        float approach = dot3(input->m_step, projectedDistance.m_kHitPoint.m_vSeparatingNormal);
        if (approach >= 0.0f)
            return;
        float roundedSpeed = -approach;
        float oldFraction = hitPoint.m_kPoint.distanceValue();
        float travel = oldFraction * roundedSpeed;
        float separation = projectedDistance.m_kHitPoint.distanceValue();
        if (separation + travel > roundedSpeed)
            return;
        float newFraction = oldFraction + separation / roundedSpeed;
        if (newFraction > castCollector->m_fEarlyOutDistance)
            return;
        hitPoint.m_kPoint.m_vContactPosition.quad = projectedDistance.m_kHitPoint.m_vContactPosition.quad;
        hitPoint.m_kPoint.assignPlane(projectedDistance.m_kHitPoint.m_vSeparatingNormal, newFraction);
        if (input->m_path->m_minDistance >= separation)
            break;
    }
    castCollector->AddCdPoint(hitPoint);
}
