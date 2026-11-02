
// src/havok/common/base/types/geometry/aabb/hkaabbutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/types/geometry/aabb/hkaabbutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_xor_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_load_ps1(const float* p);

extern const __m128 DAT_01017d10;
extern const __m128 DAT_010c44d0;

struct hkVector4D262
{
    __m128 m_vComponents;

    void operator=(const hkVector4D262& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setAbs4(const hkVector4D262& v)
    {
        m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10);
    }
    void setNeg4(const hkVector4D262& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
    void add4(const hkVector4D262& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    void setAdd4(const hkVector4D262& a, const hkVector4D262& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void setBroadcastMul(int i, const hkVector4D262& v, const hkVector4D262& col);
    __forceinline void _setTransformedPos(const struct hkTransformD262& t, const hkVector4D262& b);
};

struct hkTransformD262
{
    hkVector4D262 m_kColumn0;
    hkVector4D262 m_kColumn1;
    hkVector4D262 m_kColumn2;
    hkVector4D262 m_vTranslation;
};

__forceinline void hkVector4D262::_setTransformedPos(const hkTransformD262& t, const hkVector4D262& b)
{
    const __m128 r0 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00), t.m_kColumn0.m_vComponents);
    const __m128 r1 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55), t.m_kColumn1.m_vComponents);
    const __m128 r2 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa), t.m_kColumn2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.m_vTranslation.m_vComponents));
}

struct hkAabbD262
{
    hkVector4D262 m_kMinimumCorner;
    hkVector4D262 m_kMaximumCorner;
};

// Transforms a local-space AABB (center, halfExtents, extraRadius) into world space via localToWorld and writes the result to aabbOut.
// @fnv 0x00d26230
void __cdecl FUN_00d26230(const hkTransformD262& localToWorld, const hkVector4D262& halfExtents,
                          const hkVector4D262& center, float extraRadius, hkAabbD262& aabbOut)
{
    hkVector4D262 vHeX;
    vHeX.m_vComponents = _mm_shuffle_ps(halfExtents.m_vComponents, halfExtents.m_vComponents, 0x00);
    hkVector4D262 vHeY;
    vHeY.m_vComponents = _mm_shuffle_ps(halfExtents.m_vComponents, halfExtents.m_vComponents, 0x55);
    hkVector4D262 vHeZ;
    vHeZ.m_vComponents = _mm_shuffle_ps(halfExtents.m_vComponents, halfExtents.m_vComponents, 0xaa);

    hkVector4D262 transformedX;
    transformedX.m_vComponents = _mm_mul_ps(vHeX.m_vComponents, localToWorld.m_kColumn0.m_vComponents);
    hkVector4D262 transformedY;
    transformedY.m_vComponents = _mm_mul_ps(vHeY.m_vComponents, localToWorld.m_kColumn1.m_vComponents);
    hkVector4D262 transformedZ;
    transformedZ.m_vComponents = _mm_mul_ps(vHeZ.m_vComponents, localToWorld.m_kColumn2.m_vComponents);

    transformedX.setAbs4(transformedX);
    transformedY.setAbs4(transformedY);
    transformedZ.setAbs4(transformedZ);

    hkVector4D262 extra;
    extra.m_vComponents = _mm_load_ps1(&extraRadius);
    transformedZ.add4(extra);

    hkVector4D262 max;
    max.setAdd4(transformedX, transformedY);
    max.add4(transformedZ);

    hkVector4D262 min;
    min.setNeg4(max);

    hkVector4D262 vCenter;
    vCenter._setTransformedPos(localToWorld, center);

    max.add4(vCenter);
    min.add4(vCenter);

    aabbOut.m_kMaximumCorner = max;
    aabbOut.m_kMinimumCorner = min;
}

extern "C"
{
    __m128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, __m128);
    __m128 _mm_add_ps(__m128 a, __m128 b);
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    __m128 _mm_mul_ps(__m128 a, __m128 b);
    __m128 _mm_sub_ss(__m128 a, __m128 b);
    __m128 _mm_mul_ss(__m128 a, __m128 b);
    __m128 _mm_rsqrt_ss(__m128 a);
    __m128 _mm_cmpeq_ss(__m128 a, __m128 b);
    __m128 _mm_andnot_ps(__m128 a, __m128 b);
    __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm8);
    __m128 _mm_set_ss(float a);
    __m128 _mm_set_ps1(float a);
}

static const __declspec(align(16)) float g_quadOne[4] = {1.0f, 1.0f, 1.0f, 1.0f};

struct hkRotationq;

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void setInterpolate4(const hkVector4q& a, const hkVector4q& b, const hkVector4q& t)
    {
        const __m128 one = *(const __m128*)g_quadOne;
        const __m128 weight = t.m_vComponents;
        __m128 weighted = b.m_vComponents;
        weighted = _mm_mul_ps(weighted, weight);
        m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(one, weight), a.m_vComponents), weighted);
    }

    __forceinline void SetRotatedDirection(const hkRotationq& r, const hkVector4q& b);

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }

    __forceinline void sub4(const hkVector4q& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }
};

struct hkQuaternionq
{
    hkVector4q m_vec;

    __forceinline void normalize()
    {
        __m128 dot = _mm_mul_ps(m_vec.m_vComponents, m_vec.m_vComponents);
        dot = _mm_add_ps(dot, _mm_shuffle_ps(dot, dot, 0x4e));
        dot = _mm_add_ps(dot, _mm_shuffle_ps(dot, dot, 0xb1));

        const __m128 e = _mm_rsqrt_ss(dot);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 half = _mm_set_ss(0.5f);

        const __m128 lenSqE2 = _mm_mul_ss(_mm_mul_ss(dot, e), e);
        const __m128 isZero = _mm_cmpeq_ss(dot, zero);
        const __m128 invLen = _mm_andnot_ps(isZero, _mm_mul_ss(_mm_mul_ss(half, e), _mm_sub_ss(three, lenSqE2)));
        m_vec.m_vComponents = _mm_mul_ps(m_vec.m_vComponents, _mm_shuffle_ps(invLen, invLen, 0));
    }
    __forceinline void normalizeLoop()
    {
        __m128 dot = _mm_mul_ps(m_vec.m_vComponents, m_vec.m_vComponents);
        dot = _mm_add_ps(dot, _mm_shuffle_ps(dot, dot, 0x4e));
        dot = _mm_add_ps(dot, _mm_shuffle_ps(dot, dot, 0xb1));

        const __m128 e = _mm_rsqrt_ss(dot);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 half = _mm_set_ss(0.5f);

        const __m128 lenSqE2 = _mm_mul_ss(_mm_mul_ss(dot, e), e);
        const __m128 isZero = _mm_cmpeq_ss(dot, zero);
        const __m128 invLen = _mm_andnot_ps(isZero, _mm_mul_ss(_mm_mul_ss(half, e), _mm_sub_ss(three, lenSqE2)));
        m_vec.m_vComponents = _mm_mul_ps(m_vec.m_vComponents, _mm_shuffle_ps(invLen, invLen, 0));
    }
};

struct hkRotationq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;

    void FUN_00cb2d90(const hkQuaternionq& q);
    __forceinline const hkVector4q& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
};

struct hkTransformq
{
    hkRotationq m_rotation;
    hkVector4q m_vTranslation;
};

__forceinline void hkVector4q::SetRotatedDirection(const hkRotationq& r, const hkVector4q& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

class hkSweptTransformq
{
  public:
    hkVector4q m_vCenterOfMass0;
    hkVector4q m_vCenterOfMass1;
    hkQuaternionq m_qRotation0;
    hkQuaternionq m_qRotation1;
    hkVector4q m_vCenterOfMassLocal;

    __forceinline float getBaseTime() const
    {
        return m_vCenterOfMass0(3);
    }
    __forceinline float getInvDeltaTime() const
    {
        return m_vCenterOfMass1(3);
    }

    __forceinline void EvaluateTransformAtTime(const float& time, hkTransformq& transformOut) const
    {
        float t = (time - m_vCenterOfMass0(3)) * m_vCenterOfMass1(3);
        hkVector4q t4;
        t4.m_vComponents = _mm_set_ps1(t);

        hkQuaternionq q;
        q.m_vec.setInterpolate4(m_qRotation0.m_vec, m_qRotation1.m_vec, t4);
        q.normalize();
        transformOut.m_rotation.FUN_00cb2d90(q);

        transformOut.m_vTranslation.setInterpolate4(m_vCenterOfMass0, m_vCenterOfMass1, t4);
        hkVector4q centerShift;
        centerShift.SetRotatedDirection(transformOut.m_rotation, m_vCenterOfMassLocal);
        transformOut.m_vTranslation.sub4(centerShift);
    }
    __forceinline void approxTransformAtLoop(const float& time, hkTransformq& transformOut) const
    {
        float t = (time - m_vCenterOfMass0(3)) * m_vCenterOfMass1(3);
        hkVector4q t4;
        __m128 weight = _mm_set_ps1(t);

        hkQuaternionq q;
        __m128 left = _mm_sub_ps(*(const __m128*)g_quadOne, weight);
        left = _mm_mul_ps(left, m_qRotation0.m_vec.m_vComponents);
        t4.m_vComponents = weight;
        __m128 right = _mm_mul_ps(_mm_load_ps(t4.m_vComponents.m128_f32), m_qRotation1.m_vec.m_vComponents);
        q.m_vec.m_vComponents = _mm_add_ps(left, right);

        q.normalizeLoop();
        transformOut.m_rotation.FUN_00cb2d90(q);

        transformOut.m_vTranslation.setInterpolate4(m_vCenterOfMass0, m_vCenterOfMass1, t4);
        hkVector4q centerShift;
        centerShift.SetRotatedDirection(transformOut.m_rotation, m_vCenterOfMassLocal);
        transformOut.m_vTranslation.sub4(centerShift);
    }
};

struct hkMotionStateq
{
    hkTransformq m_kMotionTransform;
    hkSweptTransformq m_kSweptTransform;
    hkVector4q m_kDeltaAngle;
};

struct SweptSampleInfo
{
    hkTransformq m_frame;
    void FUN_00cb21e0(const hkMotionStateq* motionState);
};

struct SweptTransformSamples
{
    const hkMotionStateq* m_kMotionState;
    int unk04;
    int unk08;
    int unk0C;
    hkTransformq m_kTransforms[4];
    int m_numQsTransforms;
    int unk114;
    int unk118;
    int unk11C;
    hkTransformq m_kMotionTransform;
    SweptSampleInfo m_info;
};

// Stores motionState and sample info in out, then evaluates swept transforms at times based on delta angle, filling m_kTransforms and m_numQsTransforms.
// @fnv 0x00cbec90
void FUN_00cbec90(const hkMotionStateq* motionState, SweptTransformSamples* out)
{
    out->m_kMotionState = motionState;
    out->m_info.FUN_00cb21e0(motionState);

    const hkSweptTransformq& swept = motionState->m_kSweptTransform;
    swept.EvaluateTransformAtTime(swept.m_vCenterOfMass0(3), out->m_kMotionTransform);

    if (swept.getInvDeltaTime() != 0.0f)
    {
        float deltaTime = 1.0f / swept.getInvDeltaTime();
        float angle = motionState->m_kDeltaAngle.m_vComponents.m128_f32[3];

        if (angle <= 0.39269909262657166)
        {
            out->m_kTransforms[0] = out->m_kMotionTransform;
            float fScale = 1.0f - angle * angle * 0.5;
            out->m_kTransforms[0].m_vTranslation(3) = 1.0f / fScale;
            out->m_numQsTransforms = 1;
        }
        else if (angle <= 0.78539818525314331)
        {
            float time = swept.getBaseTime() + deltaTime * 0.5;
            swept.EvaluateTransformAtTime(time, out->m_kTransforms[0]);
            float fScale = 1.0f - angle * angle * 0.25 * 0.5;
            out->m_kTransforms[0].m_vTranslation(3) = 1.0f / fScale;
            out->m_numQsTransforms = 1;
        }
        else
        {
            out->m_numQsTransforms = 0;
            float numSteps = (angle + 0.39269909262657166) / 0.39269909262657166;
            float invNumSteps = 1.0f / numSteps;
            for (float i = 1.0f; i < numSteps; i += 2.0)
            {
                float time = swept.getBaseTime() + i * invNumSteps * deltaTime;
                hkTransformq& t = out->m_kTransforms[out->m_numQsTransforms++];
                swept.approxTransformAtLoop(time, t);
                t.m_vTranslation(3) = 1.0824f;
            }
        }
    }
    else
    {
        out->m_numQsTransforms = 0;
    }
}
