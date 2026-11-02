
// src/fallout/ai/actor_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/fallout/ai/actor.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "Actor.h"

#include <xmmintrin.h>
extern const __m128 DAT_010c71e0;

class hkQuaternionDAD;

class __declspec(align(16)) hkVector4DAD
{
  public:
    __forceinline void SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction);
    inline hkVector4DAD& operator=(const hkVector4DAD& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline void setAdd4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4DAD& a, const hkVector4DAD& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void setCross(const hkVector4DAD& v1, const hkVector4DAD& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setBroadcast3(const hkVector4DAD& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline __m128 dot3(const hkVector4DAD& v) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }

    __m128 m_vComponents;
};

class hkQuaternionDAD
{
  public:
    void FUN_00c66320(const hkQuaternionDAD& q0, const hkQuaternionDAD& q1);  // SetProduct
    const hkVector4DAD& getImag() const
    {
        return m_vec;
    }

    hkVector4DAD m_vec;
};

__forceinline void hkVector4DAD::SetRotatedDirection(const hkQuaternionDAD& quat, const hkVector4DAD& direction)
{
    hkVector4DAD qreal;
    qreal.setBroadcast3(quat.m_vec);
    hkVector4DAD q2minus1;
    q2minus1.m_vComponents = _mm_add_ps(_mm_mul_ps(qreal.m_vComponents, qreal.m_vComponents), DAT_010c71e0);
    hkVector4DAD ret;
    ret.setMul4(q2minus1, direction);
    hkVector4DAD imagDotDir;
    imagDotDir.m_vComponents = quat.getImag().dot3(direction);
    imagDotDir.m_vComponents = _mm_shuffle_ps(imagDotDir.m_vComponents, imagDotDir.m_vComponents, 0);
    hkVector4DAD imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(imagDotDir, quat.getImag());
    ret.addMul4(qreal, imagCrossDir);
    setAdd4(ret, ret);
}

class hkQsTransformDAD
{
  public:
    __forceinline void SetProduct(const hkQsTransformDAD& t1, const hkQsTransformDAD& t2)
    {
        hkVector4DAD temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        m_rotation.FUN_00c66320(t1.m_rotation, t2.m_rotation);
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }

    hkVector4DAD m_vTranslation;
    hkQuaternionDAD m_rotation;
    hkVector4DAD m_vScale;
};

class TransformedPosDAD : public hkVector4DAD
{
  public:
    void FUN_00c7f7a0(const hkQsTransformDAD& a, const hkVector4DAD& b);
};

// @fnv 0x00c7f7a0
void TransformedPosDAD::FUN_00c7f7a0(const hkQsTransformDAD& a, const hkVector4DAD& b)
{
    hkVector4DAD scaled;
    scaled.setMul4(a.m_vScale, b);
    SetRotatedDirection(a.m_rotation, scaled);
    setAdd4(a.m_vTranslation, *this);
}

namespace fnv_00cda340 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
};

extern "C"
{
    __m128 _mm_add_ps(__m128 a, __m128 b);
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    __m128 _mm_mul_ps(__m128 a, __m128 b);
    __m128 _mm_add_ss(__m128 a, __m128 b);
    __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
}

struct VectorComponentValue
{
    __m128 m_vValue;
};

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline VectorComponentValue dot3(const hkVector4& v) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 y = _mm_shuffle_ps(p, p, 0x55);
        __m128 z = _mm_shuffle_ps(p, p, 0xaa);
        VectorComponentValue r;
        r.m_vValue = _mm_add_ss(z, _mm_add_ss(y, p));
        return r;
    }
};

extern hkVector4 DAT_010c71e0;

struct hkQuaternion
{
    hkVector4 m_vec;
    void SetProduct(const hkQuaternion& q0, const hkQuaternion& q1);
};

struct hkQsTransform
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
};

__forceinline void SetRotatedDirection(hkVector4& out, const hkQuaternion& quat, const hkVector4& direction)
{
    const __m128 q = quat.m_vec.m_vComponents;
    const __m128 d = direction.m_vComponents;
    __m128 qreal = _mm_shuffle_ps(q, q, 0xff);
    __m128 ret = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(qreal, qreal), DAT_010c71e0.m_vComponents), d);
    VectorComponentValue imagDotDir = quat.m_vec.dot3(direction);
    ret = _mm_add_ps(ret, _mm_mul_ps(_mm_shuffle_ps(imagDotDir.m_vValue, imagDotDir.m_vValue, 0), q));
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(d, d, 0xd2), _mm_shuffle_ps(q, q, 0xc9)),
                              _mm_mul_ps(_mm_shuffle_ps(d, d, 0xc9), _mm_shuffle_ps(q, q, 0xd2)));
    ret = _mm_add_ps(ret, _mm_mul_ps(qreal, cross));
    out.m_vComponents = _mm_add_ps(ret, ret);
}

struct hkaSkeleton
{
    int unk00;
    int unk04;
    int unk08;
    short* m_kParentIndices;
    int unk10;
    int unk14;
    int unk18;
    int m_iBoneCount;
};

struct SkeletonPoseData
{
    hkaSkeleton* m_pSkeleton;
    hkQsTransform* m_pLocalPose;
    int m_localPoseSize;
    int m_localPoseCapacity;
    hkQsTransform* m_pModelPose;
    int m_modelPoseSize;
    int m_modelPoseCapacity;
    unsigned int* m_pBoneFlags;
    int m_boneFlagsSize;
    int m_boneFlagsCapacity;
    bool m_bPoseFlag;

    void FUN_00cda340();
};

// @fnv 0x00cda340
void SkeletonPoseData::FUN_00cda340()
{
    if (m_bPoseFlag)
        return;

    const int numBones = m_pSkeleton->m_iBoneCount;
    for (int b = 0; b < numBones; b++)
    {
        if (m_pBoneFlags[b] & 2)
        {
            const short parentId = m_pSkeleton->m_kParentIndices[b];
            const hkQsTransform& local = m_pLocalPose[b];
            if (parentId != -1)
            {
                const hkQsTransform& parent = m_pModelPose[parentId];
                hkQsTransform& out = m_pModelPose[b];
                hkVector4 t;
                SetRotatedDirection(t, parent.m_rotation, local.m_vTranslation);
                out.m_vTranslation.m_vComponents = _mm_add_ps(t.m_vComponents, parent.m_vTranslation.m_vComponents);
                out.m_rotation.SetProduct(parent.m_rotation, local.m_rotation);
                out.m_vScale.m_vComponents = _mm_mul_ps(parent.m_vScale.m_vComponents, local.m_vScale.m_vComponents);
            }
            else
            {
                hkQsTransform& out = m_pModelPose[b];
                out.m_vTranslation.m_vComponents = local.m_vTranslation.m_vComponents;
                out.m_rotation.m_vec.m_vComponents = local.m_rotation.m_vec.m_vComponents;
                out.m_vScale.m_vComponents = local.m_vScale.m_vComponents;
            }
            m_pBoneFlags[b] &= ~2u;
        }
    }
    m_bPoseFlag = true;
}
}  // namespace fnv_00cda340
