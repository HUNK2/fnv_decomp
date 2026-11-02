
// src/havok/animation/animation/rig/hkapose.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/rig/hkapose.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

typedef short hkInt16;
typedef unsigned int hkUint32;

extern "C" __m128 DAT_010c71e0;

struct VectorComponentValue
{
    __m128 m_vValue;
};

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void add4(const hkVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(const VectorComponentValue& s, const hkVector4& b)
    {
        m_vComponents =
            _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), b.m_vComponents));
    }
    __forceinline void setBroadcast3(const hkVector4& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        const __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        VectorComponentValue r;
        r.m_vValue = _mm_add_ss(z, xySum);
        return r;
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline const hkVector4& getImag() const
    {
        return m_vec;
    }
    void FUN_00c66320(const hkQuaternion& q0, const hkQuaternion& q1);
};

__forceinline void SetRotatedDirection(hkVector4& out, const hkQuaternion& quat, const hkVector4& direction)
{
    hkVector4 qreal;
    qreal.setBroadcast3(quat.m_vec);
    hkVector4 q2minus1;
    q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), DAT_010c71e0);

    hkVector4 ret;
    ret.setMul4(q2minus1, direction);

    VectorComponentValue imagDotDir = quat.getImag().dot3(direction);
    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    out.setAdd4(ret, ret);
}

struct hkQsTransform
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;

    __forceinline void SetProduct(const hkQsTransform& t1, const hkQsTransform& t2)
    {
        hkVector4 rotated;
        SetRotatedDirection(rotated, t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(rotated, t1.m_vTranslation);
        m_rotation.FUN_00c66320(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
};

template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
};
struct hkaSkeleton
{
    int unk00;
    int unk04;
    int unk08;
    hkArray<hkInt16> m_kParentIndices;
};
struct SkeletonPoseData
{
    enum
    {
        F_BONE_MODEL_DIRTY = 0x2,
        F_BONE_INTERNAL_FLAG1 = 0x8
    };
    const hkaSkeleton* m_pSkeleton;
    hkArray<hkQsTransform> m_pLocalPose;
    hkArray<hkQsTransform> m_pModelPose;
    hkArray<hkUint32> m_pBoneFlags;
    __forceinline int isFlagOn(int i, hkUint32 f) const
    {
        return m_pBoneFlags[i] & f;
    }
    __forceinline void setFlag(int i, hkUint32 f)
    {
        m_pBoneFlags[i] |= f;
    }
    __forceinline void clearFlag(int i, hkUint32 f)
    {
        m_pBoneFlags[i] &= ~f;
    }
    const hkQsTransform& FUN_00cda180(int boneIdx);
};

// @fnv 0x00cda180
const hkQsTransform& SkeletonPoseData::FUN_00cda180(int boneIdx)
{
    int ancestorIdx = boneIdx;
    while (isFlagOn(ancestorIdx, F_BONE_MODEL_DIRTY))
    {
        const hkInt16 parentIdx = m_pSkeleton->m_kParentIndices[ancestorIdx];
        if (parentIdx == -1)
        {
            m_pModelPose[ancestorIdx] = m_pLocalPose[ancestorIdx];
            clearFlag(ancestorIdx, F_BONE_MODEL_DIRTY);
            break;
        }
        setFlag(ancestorIdx, F_BONE_INTERNAL_FLAG1);
        ancestorIdx = parentIdx;
    }

    for (int i = ancestorIdx + 1; i <= boneIdx; ++i)
    {
        if (isFlagOn(i, F_BONE_INTERNAL_FLAG1))
        {
            const hkInt16 parentIdx = m_pSkeleton->m_kParentIndices[i];
            m_pModelPose[i].SetProduct(m_pModelPose[parentIdx], m_pLocalPose[i]);
            clearFlag(i, F_BONE_MODEL_DIRTY | F_BONE_INTERNAL_FLAG1);
        }
    }
    return m_pModelPose[boneIdx];
}
