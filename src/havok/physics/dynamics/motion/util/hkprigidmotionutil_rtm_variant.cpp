// src/havok/physics/dynamics/motion/util/hkprigidmotionutil_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/motion/util/hkprigidmotionutil.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/dynamics/motion/util/hkprigidmotionutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/util/hkprigidmotionutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void _ReadWriteBarrier();
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;
extern "C"
{
    __m128 _mm_set1_ps(float);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_load_ps(const volatile float*);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_setzero_ps();
}

static __forceinline __m128 broadcast(float f)
{
    __m128 v = _mm_load_ss(&f);
    return _mm_shuffle_ps(v, v, 0);
}
extern const __m128 DAT_010ec7f0;

struct StubMatrix
{
    void __thiscall FUN_00cd4ba0(const void* rot);
};

struct SubItem
{
    int unk00;
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
    union
    {
        __m128 unk40;
        struct
        {
            float unk40_x;
            float unk40_y;
            float unk40_z;
            float unk4C;
        };
    };
    union
    {
        __m128 unk50;
        struct
        {
            float unk50_x;
            float unk50_y;
            float unk50_z;
            float unk5C;
        };
    };
};

struct SourceItem
{
    int unk00;
    int unk04;
    unsigned char unk08;
    char unk09;
    char unk0A;
    char unk0B;
    int unk0C;
    SubItem sub;  // 0x10
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
    int unkB0;
    float unkB4;
    float unkB8;
    char unkBC;
    char unkBD;
    unsigned char unkBE;
    char unkBF;
    __m128 unkC0;
    __m128 unkD0;
    __m128 unkE0;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    short unk11C;
    short unk11E;
};

struct ContextA0
{
    float unk00;
    int unk04;
    float unk08;
};

struct OutputHeader
{
    unsigned char unk00;
    char unk01, unk02, unk03;
    int unk04;
    union
    {
        int unk08;
        float scalar08;
    };
    int unk0C;
};
union OutputCell
{
    __m128 vector;
    OutputHeader header;
    struct
    {
        float x, y, z, w;
    };
};
struct TargetItem
{
    OutputCell cells[8];
};

// @fnv 0x00d29830
TargetItem* __cdecl FUN_00d29830(ContextA0* a0, SourceItem** a1, int a2, int a3, TargetItem* a4)
{
    int count = a2 - 1;
    if (count >= 0)
    {

        OutputCell* last = &a4->cells[7];
        do
        {
            SourceItem* item = (SourceItem*)((char*)*a1 + a3);
            switch (item->unk08)
            {
            case 0:
            case 3:
            case 6: {
                float dt = a0->unk08;
                float d1 = 1.0f - dt * item->unkB4;

                __m128 s1 = broadcast(0.0f > d1 ? 0.0f : d1);
                item->unkD0 = _mm_mul_ps(s1, item->unkD0);
                _ReadWriteBarrier();

                float d2 = 1.0f - dt * item->unkB8;

                __m128 s2 = broadcast(0.0f > d2 ? 0.0f : d2);
                item->unkE0 = _mm_mul_ps(s2, item->unkE0);

                SubItem* sub = &item->sub;
                ((StubMatrix*)&last[-2].vector)->FUN_00cd4ba0(sub);
                a4->cells[0].header.unk00 = 0;
                last[-4].vector = _mm_load_ps((const volatile float*)&item->unkC0);
                last[-6].vector = item->unkD0;

                float ldt = (a0->unk00 - sub->unk4C) * sub->unk5C;
                __m128 dtv = broadcast(ldt);
                __m128 inv_dt = _mm_sub_ps(DAT_010ec7f0, dtv);
                last[-3].vector = _mm_add_ps(_mm_mul_ps(inv_dt, sub->unk40), _mm_mul_ps(dtv, sub->unk50));

                __m128 v = item->unkE0;
                __m128 c1 =
                    _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), _mm_load_ps((const volatile float*)&last[-1].vector));
                __m128 c0 =
                    _mm_mul_ps(_mm_shuffle_ps(v, v, 0x00), _mm_load_ps((const volatile float*)&last[-2].vector));
                __m128 res = _mm_add_ps(c1, c0);
                __m128 c2 = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), last[0].vector);
                last[-5].vector = _mm_add_ps(res, c2);

                last[-7].header.unk04 = item->unkBE;
                last[-7].header.unk08 = ((int)item->unk11E) << 16;
                break;
            }
            case 7:
                a4->cells[0].header.unk00 = 2;
                goto handle_case_2;
            case 2:
                a4->cells[0].header.unk00 = 0;
            handle_case_2: {
                float dt = a0->unk08;
                float d1 = 1.0f - dt * item->unkB4;

                __m128 s1 = broadcast(0.0f > d1 ? 0.0f : d1);
                item->unkD0 = _mm_mul_ps(s1, item->unkD0);
                _ReadWriteBarrier();

                float d2 = 1.0f - dt * item->unkB8;

                __m128 s2 = broadcast(0.0f > d2 ? 0.0f : d2);
                item->unkE0 = _mm_mul_ps(s2, item->unkE0);

                last[-4].vector = _mm_load_ps((const volatile float*)&item->unkC0);

                float ldt = (a0->unk00 - item->sub.unk4C) * item->sub.unk5C;
                __m128 dtv = broadcast(ldt);
                __m128 inv_dt = _mm_sub_ps(DAT_010ec7f0, dtv);
                last[-3].vector = _mm_add_ps(_mm_mul_ps(inv_dt, item->sub.unk40), _mm_mul_ps(dtv, item->sub.unk50));

                last[-5].vector = item->unkE0;
                last[-6].vector = item->unkD0;

                __m128 zero = _mm_setzero_ps();
                last[-2].vector = zero;
                last[-1].vector = zero;
                last[0].vector = zero;
                *(volatile float*)&last[-2].x = 1.0f;
                *(volatile float*)&last[-1].y = 1.0f;
                *(volatile float*)&last[0].z = 1.0f;

                last[-7].header.unk04 = item->unkBE;
                last[-7].header.unk08 = ((int)item->unk11E) << 16;
                break;
            }
            case 5: {
                __m128 zero = _mm_setzero_ps();
                last[-7].header.scalar08 = 0.0f;
                a4->cells[0].header.unk00 = 1;
                last[-4].vector = zero;
                last[-6].vector = zero;
                last[-5].vector = zero;
                last[-3].vector = zero;
                last[-2].vector = zero;
                last[-1].vector = zero;
                last[0].vector = zero;
                break;
            }
            case 4: {
                a4->cells[0].header.unk00 = 1;
                __m128 zero = _mm_setzero_ps();
                last[-4].vector = zero;
                last[-3].vector = item->sub.unk50;
                last[-5].vector = item->unkE0;
                last[-6].vector = item->unkD0;
                last[-2].vector = zero;
                last[-1].vector = zero;
                last[0].vector = zero;
                *(volatile float*)&last[-2].x = 1.0f;
                *(volatile float*)&last[-1].y = 1.0f;
                *(volatile float*)&last[0].z = 1.0f;
                last[-7].header.unk08 = ((int)item->unk11E) << 16;
                break;
            }
            default:
                break;
            }

            a1++;
            a4++;
            last += 8;
        } while (--count >= 0);
    }
    return a4;
}

#include <math.h>
namespace ApplyAccumulatorsPrivate {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;

extern "C"
{
    __m128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_rcp_ps(__m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_cmpeq_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
}

typedef float hkReal;
typedef float hkTime;
typedef __m128 hkQuadReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef short hkInt16;
typedef unsigned int hkUint32;
typedef long hkLong;

// zeroElement, the identity transform.
extern const hkReal DAT_010c7948[];
extern const double DAT_010ce4b0;
extern const double DAT_010ce4a8;
extern const double DAT_010ce4a0;
extern const double DAT_010ce498;
extern const double DAT_010ce488;
extern const hkQuadReal DAT_010cbf80;
extern const hkUint32 DAT_01017d10[4];
extern const hkUint32 DAT_010cbf90[4][4];
extern const hkQuadReal DAT_01268370[4];

class hkBool
{
  public:
    __forceinline hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }

  private:
    char m_cBooleanValue;
};

class hkHalf
{
  public:
    __forceinline operator float() const
    {
        union
        {
            int i;
            float f;
        } u;
        u.i = (m_uiFilterValue << 16);
        return u.f;
    }

  private:
    hkInt16 m_uiFilterValue;
};

class QuantizedFloat8
{
  public:
    __forceinline operator float() const
    {
        return DAT_010c7948[m_uiFilterValue];
    }
    hkUint8 m_uiFilterValue;
};

template <typename ENUM, typename STORAGE> class hkEnum
{
  public:
    __forceinline operator ENUM() const
    {
        return static_cast<ENUM>(m_kStorage);
    }
    __forceinline hkBool operator==(ENUM e) const
    {
        return m_kStorage == static_cast<STORAGE>(e);
    }

  private:
    STORAGE m_kStorage;
};

template <typename TYPE> class ValueWrapper
{
  public:
    __forceinline TYPE val() const
    {
        return m_kStorage;
    }
    __forceinline operator TYPE() const
    {
        return val();
    }

  private:
    TYPE m_kStorage;
};

class VectorComponentValue
{
  public:
    __forceinline VectorComponentValue(const hkQuadReal& x) : m_vValue(x)
    {}
    __forceinline VectorComponentValue(hkReal x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }

  private:
    hkQuadReal m_vValue;
};
typedef const VectorComponentValue& hkSimdRealParameter;

class Vector4Comparison
{
  public:
    __forceinline int GetLaneMask() const
    {
        return _mm_movemask_ps(m_uiMask);
    }

  private:
    hkQuadReal m_uiMask;
    friend class hkVector4;
};

namespace MathUtilities {
__forceinline hkQuadReal quadReciprocal(hkQuadReal r)
{
    hkQuadReal e = _mm_rcp_ps(r);
    return _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, r), e));
}
__forceinline hkReal sqrt(hkReal r)
{
    return sqrtf(r);
}
__forceinline hkReal sqrtInverse(hkReal r)
{
    return 1.0f / MathUtilities::sqrt(r);
}
template <typename T> __forceinline T max2(T x, T y)
{
    return x > y ? x : y;
}
template <typename T> __forceinline T min2(T x, T y)
{
    return x < y ? x : y;
}
}

class hkRotation;

class hkVector4
{
  public:
    __forceinline hkQuadReal& getQuad()
    {
        return m_vComponents;
    }
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void zeroElement(int i)
    {
        m_vComponents = _mm_and_ps(m_vComponents, reinterpret_cast<const hkQuadReal*>(DAT_010cbf90)[i]);
    }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void mul4(const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void mul4(hkSimdRealParameter s)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
    }
    __forceinline void setMul4(hkSimdRealParameter r, const hkVector4& v1)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
    }
    __forceinline void addMul4(hkSimdRealParameter r, const hkVector4& v1)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
    }
    __forceinline Vector4Comparison compareLessThan4(const hkVector4& a) const
    {
        Vector4Comparison m;
        m.m_uiMask = _mm_cmplt_ps(m_vComponents, a.m_vComponents);
        return m;
    }
    __forceinline Vector4Comparison compareEqual4(const hkVector4& a) const
    {
        Vector4Comparison m;
        m.m_uiMask = _mm_cmpeq_ps(m_vComponents, a.m_vComponents);
        return m;
    }
    __forceinline void setAbs4(const hkVector4& v)
    {
        m_vComponents = _mm_and_ps(v.m_vComponents, *(const hkQuadReal*)&DAT_01017d10);
    }
    __forceinline void _setMul3(const hkRotation& a, const hkVector4& b);
    __forceinline void _setRotatedDir(const hkRotation& r, const hkVector4& v)
    {
        _setMul3(r, v);
    }
    void FUN_00c7f700(const hkRotation& r, const hkVector4& v);
    __forceinline void _setRotatedInverseDir(const hkRotation& r, const hkVector4& b);
    __forceinline void setRotatedInverseDir(const hkRotation& t, const hkVector4& v)
    {
        _setRotatedInverseDir(t, v);
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline VectorComponentValue dot4(const hkVector4& a) const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        hkQuadReal sum0 = _mm_add_ps(_mm_shuffle_ps(x2, x2, 0x4e), x2);
        hkQuadReal sum1 = _mm_shuffle_ps(sum0, sum0, 0xb1);
        return _mm_add_ps(sum0, sum1);
    }
    __forceinline VectorComponentValue lengthSquared3() const
    {
        return this->dot3(*this);
    }
    __forceinline VectorComponentValue lengthSquared4() const
    {
        return this->dot4(*this);
    }
    __forceinline void setReciprocal4(const hkVector4& vec)
    {
        m_vComponents = MathUtilities::quadReciprocal(vec.m_vComponents);
    }
    void FUN_005611c0();  // hkVector4::normalize4
    __forceinline hkReal& operator()(int a)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[a];
    }
    hkQuadReal m_vComponents;
};

class hkQuaternion;

class hkMatrix3
{
  public:
    __forceinline const hkVector4& getColumn(int x) const
    {
        return (&m_kColumn0)[x];
    }
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};

class hkRotation : public hkMatrix3
{
  public:
    void FUN_00cb2d90(const hkQuaternion& q);  // hkRotation::set
};

__forceinline void hkVector4::_setMul3(const hkRotation& a, const hkVector4& b)
{
    const hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0);
    const hkQuadReal r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const hkQuadReal r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const hkQuadReal r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    hkQuadReal c0 = r.getColumn(0).m_vComponents;
    hkQuadReal c1 = r.getColumn(1).m_vComponents;
    hkQuadReal c2 = r.getColumn(2).m_vComponents;
    {
        hkQuadReal _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, 0xd4);
        c2 = _ctmp;
    }
    const hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0);
    const hkQuadReal r0 = _mm_mul_ps(c0, b0);
    const hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const hkQuadReal r1 = _mm_mul_ps(c1, b1);
    const hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const hkQuadReal r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

class hkQuaternion
{
  public:
    __forceinline hkQuaternion()
    {}
    __forceinline void operator=(const hkQuaternion& q)
    {
        m_vec = q.m_vec;
    }
    void FUN_00c66320(const hkQuaternion& q0, const hkQuaternion& q1);
    __forceinline void normalize()
    {
        m_vec.FUN_005611c0();
    }
    hkVector4 m_vec;
};

class hkTransform
{
  public:
    __forceinline hkRotation& getRotation()
    {
        return m_rotation;
    }
    __forceinline const hkRotation& getRotation() const
    {
        return m_rotation;
    }
    __forceinline void SetBodyOrientation(const hkQuaternion& quatRotation)
    {
        m_rotation.FUN_00cb2d90(quatRotation);
    }
    __forceinline hkVector4& getTranslation()
    {
        return m_vTranslation;
    }
    __forceinline const hkVector4& getColumn(int x) const
    {
        return m_rotation.getColumn(x);
    }
    static __forceinline const hkTransform& GetIdentityTransform()
    {
        return reinterpret_cast<const hkTransform&>(DAT_01268370);
    }
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};

class hkSweptTransform
{
  public:
    hkVector4 m_vCenterOfMass0;
    hkVector4 m_vCenterOfMass1;
    hkQuaternion m_qRotation0;
    hkQuaternion m_qRotation1;
    hkVector4 m_vCenterOfMassLocal;
};

class hkMotionState
{
  public:
    __forceinline hkTransform& getTransform()
    {
        return m_kMotionTransform;
    }
    __forceinline const hkTransform& getTransform() const
    {
        return m_kMotionTransform;
    }
    __forceinline const hkSweptTransform& getSweptTransform() const
    {
        return m_kSweptTransform;
    }
    __forceinline hkSweptTransform& getSweptTransform()
    {
        return m_kSweptTransform;
    }
    hkTransform m_kMotionTransform;
    hkSweptTransform m_kSweptTransform;
    hkVector4 m_kDeltaAngle;
    hkReal m_fObjectRadius;
    hkReal m_fLinearDamping;
    hkReal m_fAngularDamping;
    QuantizedFloat8 m_fSurfaceFriction;
    QuantizedFloat8 m_fRestitution;
    hkUint8 m_uiDeactivationClass;
};

class hkStepInfo
{
  public:
    ValueWrapper<hkTime> m_uiStartTime;
    ValueWrapper<hkTime> m_fEndTime;
    ValueWrapper<hkReal> m_fTimeStep;
    ValueWrapper<hkReal> m_fInverseDeltaTime;
};

struct ConstraintSolverInfo
{
    struct FloatAndHalfRecord
    {
        float m_fFirstFloat;
        float m_fSecondFloat;
        float m_fThirdValue;
        float m_fFourthFloat;
        float m_afFloatPair[2];
        hkHalf m_ahHalfPair[2];
    };
    __declspec(align(16)) float m_iCachedVertexCount;
    float m_fTau;
    float m_fMotorDamping;
    float m_fPostDampingParameter;
    hkVector4 m_kGravity;
    hkVector4 m_kSecondSolverVector;
    hkVector4 m_kTimeStep;
    hkVector4 GetTimeStepFactor;
    float m_fFirstTrailingParameter;
    float m_fSecondTrailingParameter;
    float m_fThirdTrailingParameter;
    float m_fFourthTrailingParameter;
    float m_fContactRestingVelocity;
    FloatAndHalfRecord m_kDeactivationClassInfo[6];
    float m_fTimeStep;
    float m_fInverseDeltaTime;
    int m_iToiEventCount;
    int m_iMicroStepCount;
    float m_fInverseMicroStepCount;
    float m_fInverseStepCount;
    hkBool m_bForceCoherentConstraintOrderingInSolver;
    hkUint8 m_ucDeactivationInactiveFrameSelectFlags[2];
    hkUint8 m_ucDeactivationIntegrateCounter;
    float m_fMaxConstraintViolationSquared;
};

class QuantizedBoundsData
{
  public:
    __forceinline const hkVector4& getSumLinearVel() const
    {
        return getScratch0();
    }
    __forceinline const hkVector4& getSumAngularVel() const
    {
        return getScratch1();
    }
    __forceinline const hkVector4& getScratch0() const
    {
        return m_vCenterOfMass;
    }
    __forceinline const hkVector4& getScratch1() const
    {
        return m_kCoreFromWorldMatrix.getColumn(0);
    }
    hkUint8 m_type;
    hkUint32 m_uiDeactivationClass;
    hkReal m_fGravityFactor;
    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity;
    hkVector4 m_vInverseInertiaAndMass;
    hkVector4 m_vCenterOfMass;
    hkRotation m_kCoreFromWorldMatrix;
};

class hkBaseObject
{
  public:
    virtual ~hkBaseObject();
};

class hkReferencedObject : public hkBaseObject
{
  public:
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class hkpMotion : public hkReferencedObject
{
  public:
    enum MotionType
    {
        MOTION_INVALID,
        MOTION_DYNAMIC,
        MOTION_SPHERE_INERTIA,
        MOTION_BOX_INERTIA,
        MOTION_KEYFRAMED,
        MOTION_FIXED,
        MOTION_THIN_BOX_INERTIA,
        MOTION_CHARACTER,
        MOTION_MAX_ID
    };
    __forceinline const hkTransform& getTransform() const
    {
        return m_kMotionState.getTransform();
    }
    __forceinline int getNumInactiveFrames(int select)
    {
        return m_ausDeactivationNumInactiveFrames[select] & 0x7f;
    }
    __forceinline void incrementNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag)
    {
        int dc = m_ausDeactivationNumInactiveFrames[select];
        dc = dc & 0x7f;
        int newdc = dc + 1 - (dc >> 6);
        dc = newdc | (dc << 7) | (worldDeactivationNumInactiveFramesSelectFlag << 14);
        m_ausDeactivationNumInactiveFrames[select] = hkUint16(dc);
    }
    __forceinline void zeroNumInactiveFramesMt(int select, int worldDeactivationNumInactiveFramesSelectFlag)
    {
        int dc = m_ausDeactivationNumInactiveFrames[select];
        dc = dc & 0x7f;
        dc = (dc << 7) | (worldDeactivationNumInactiveFramesSelectFlag << 14);
        m_ausDeactivationNumInactiveFrames[select] = hkUint16(dc);
    }
    hkEnum<MotionType, hkUint8> m_type;
    hkUint8 m_ucDeactivationIntegrateCounter;
    hkUint16 m_ausDeactivationNumInactiveFrames[2];
    hkMotionState m_kMotionState;
    hkVector4 m_kInertiaAndMassInv;
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    hkVector4 m_akDeactivationReferencePositions[2];
    hkUint32 m_auiDeactivationReferenceOrientations[2];
};

class hkpBoxMotion : public hkpMotion
{
};
class hkpThinBoxMotion : public hkpBoxMotion
{
};

template <typename TYPE> __forceinline TYPE* hkAddByteOffset(TYPE* base, hkLong offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}

extern unsigned int __cdecl PackFloatsToUInt(const hkVector4& qin);

namespace hkVector4Util_S {
__forceinline void unPackInt32IntoQuaternion(hkUint32 ivalue, hkVector4& qout)
{
    int a = ivalue;
    int b = ivalue >> 8;
    int c = ivalue >> 16;
    int d = ivalue >> 24;
    a &= 0xff;
    b &= 0xff;
    c &= 0xff;
    a -= 0x80;
    b -= 0x80;
    c -= 0x80;
    d -= 0x80;
    qout(0) = DAT_010ce488 * (hkReal)a;
    qout(1) = DAT_010ce488 * (hkReal)b;
    qout(2) = DAT_010ce488 * (hkReal)c;
    qout(3) = DAT_010ce488 * (hkReal)d;
}
}

namespace MotionUtilities {

__forceinline void calcTransAtT1(const hkSweptTransform& sweptTrans, hkTransform& transformOut)
{
    const hkQuaternion& qt = sweptTrans.m_qRotation1;
    transformOut.SetBodyOrientation(qt);
    hkVector4 centerShift;
    centerShift._setRotatedDir(transformOut.getRotation(), sweptTrans.m_vCenterOfMassLocal);
    transformOut.getTranslation().setSub4(sweptTrans.m_vCenterOfMass1, centerShift);
}

__forceinline void _clipVelocities(const hkMotionState& motionState, hkVector4& linearVelocity,
                                   hkVector4& angularVelocity)
{
    hkReal linVelSq = linearVelocity.lengthSquared3();
    hkReal angVelSq = angularVelocity.lengthSquared3();
    const hkReal maxLinear = motionState.m_fSurfaceFriction * motionState.m_fSurfaceFriction;
    const hkReal maxAngular = motionState.m_fRestitution * motionState.m_fRestitution;
    if ((linVelSq > maxLinear) || (linVelSq != linVelSq))
    {
        hkReal f = motionState.m_fSurfaceFriction * MathUtilities::sqrtInverse(linVelSq);
        linearVelocity.mul4(f);
        if (linVelSq != linVelSq)
        {
            linearVelocity = hkTransform::GetIdentityTransform().getColumn(0);
        }
    }
    if ((angVelSq > maxAngular) || (angVelSq != angVelSq))
    {
        hkReal f = motionState.m_fRestitution * MathUtilities::sqrtInverse(angVelSq);
        angularVelocity.mul4(f);
        if (angVelSq != angVelSq)
        {
            angularVelocity = hkTransform::GetIdentityTransform().getColumn(0);
        }
    }
}

__forceinline void _stepMotionState(const hkStepInfo& info, hkVector4& linearVelocity, hkVector4& angularVelocity,
                                    hkMotionState& motionState)
{
    {
        hkVector4 absLin;
        absLin.setAbs4(linearVelocity);
        hkVector4 absAng;
        absAng.setAbs4(angularVelocity);

        hkVector4 maxVel;
        maxVel.getQuad() = DAT_010cbf80;
        int mask = absLin.compareLessThan4(maxVel).GetLaneMask() & absAng.compareLessThan4(maxVel).GetLaneMask();
        mask &= linearVelocity.compareEqual4(linearVelocity).GetLaneMask() &
                angularVelocity.compareEqual4(angularVelocity).GetLaneMask();
        if ((mask & 7) != 7)
        {
            linearVelocity = hkTransform::GetIdentityTransform().getColumn(0);
            angularVelocity = hkTransform::GetIdentityTransform().getColumn(0);
        }
    }

    motionState.getSweptTransform().m_vCenterOfMass0 = motionState.getSweptTransform().m_vCenterOfMass1;
    motionState.getSweptTransform().m_vCenterOfMass0(3) = info.m_uiStartTime;

    hkReal linVelSq = linearVelocity.lengthSquared3();
    if (linVelSq > motionState.m_fSurfaceFriction * motionState.m_fSurfaceFriction)
    {
        hkReal f = motionState.m_fSurfaceFriction * MathUtilities::sqrtInverse(linVelSq);
        linearVelocity.mul4(f);
    }

    motionState.getSweptTransform().m_vCenterOfMass1.addMul4(info.m_fTimeStep.val(), linearVelocity);
    motionState.getSweptTransform().m_vCenterOfMass1(3) = info.m_fInverseDeltaTime;

    hkQuaternion newRotation = motionState.getSweptTransform().m_qRotation1;
    motionState.getSweptTransform().m_qRotation0 = newRotation;

    hkReal angle;
    {
        hkQuaternion dq;
        dq.m_vec.setMul4(info.m_fTimeStep * 0.5f, angularVelocity);
        const hkReal pi = 3.14159265358979f;
        hkReal dx2 = hkReal(dq.m_vec.lengthSquared3()) * DAT_010ce4b0;

        const hkReal maxAnglePerStep = MathUtilities::min2(0.9f, info.m_fTimeStep.val() * motionState.m_fRestitution);

        if (dx2 <= maxAnglePerStep * maxAnglePerStep)
        {
            const hkReal dx4 = dx2 * dx2;
            const hkReal w = 1.0f - DAT_010ce4a8 * dx2 - DAT_010ce4a0 * dx4 - DAT_010ce498 * dx2 * dx4;
            dq.m_vec(3) = w;
        }
        else
        {
            hkReal factor = maxAnglePerStep * MathUtilities::sqrtInverse(dx2);
            angularVelocity.mul4(factor);
            dq.m_vec.mul4(factor);

            dx2 = maxAnglePerStep * maxAnglePerStep;
            const hkReal dx4 = dx2 * dx2;
            const hkReal w = 1.0f - DAT_010ce4a8 * dx2 - DAT_010ce4a0 * dx4 - DAT_010ce498 * dx2 * dx4;
            dq.m_vec(3) = w;
        }

        newRotation.FUN_00c66320(dq, newRotation);
        newRotation.normalize();

        motionState.m_kDeltaAngle.setAdd4(dq.m_vec, dq.m_vec);
        angle = MathUtilities::sqrt(dx2) * pi;
        motionState.m_kDeltaAngle(3) = angle;
    }
    motionState.getSweptTransform().m_qRotation1 = newRotation;
    calcTransAtT1(motionState.getSweptTransform(), motionState.getTransform());
}

}

static __forceinline hkReal calcVelocityForDeactivation(const hkpMotion& motion, hkReal radius)
{
    hkReal linVelSqrd = motion.m_kTranslationalVelocity.lengthSquared3();
    hkReal angVelSqrd = motion.m_kAngularVelocity.lengthSquared3();
    hkReal velSqrd = linVelSqrd + radius * radius * angVelSqrd;
    return velSqrd;
}

static __forceinline int hkRigidMotionUtilCheckDeactivation(const ConstraintSolverInfo& si, hkpMotion& motion)
{
    hkUint32 c = motion.m_ucDeactivationIntegrateCounter;
    c += 1;
    motion.m_ucDeactivationIntegrateCounter = hkUint8(c);
    if (c & 3)
    {
        goto END_OF_FUNCTION;
    }
    {
        int select;
        if (c & 15)
        {
            select = 0;
        }
        else
        {
            if (c == 0x100)
            {
                motion.m_ucDeactivationIntegrateCounter = 0xff;
                goto END_OF_FUNCTION;
            }
            motion.m_ucDeactivationIntegrateCounter = 0;
            select = 1;
        }

        hkReal radius = MathUtilities::min2(1.0f, motion.m_kMotionState.m_fObjectRadius);
        {
            hkReal velSqrd = calcVelocityForDeactivation(motion, radius);
            hkReal& maxDeactVel = motion.m_akDeactivationReferencePositions[select](3);
            maxDeactVel = MathUtilities::max2(maxDeactVel, velSqrd);
        }

        hkVector4& refPosition = motion.m_akDeactivationReferencePositions[select];
        hkUint32& refOrientation = motion.m_auiDeactivationReferenceOrientations[select];
        const hkSweptTransform& sweptTransform = motion.m_kMotionState.getSweptTransform();
        const hkVector4& currentPosition = sweptTransform.m_vCenterOfMass1;
        const hkQuaternion& currentRotation = sweptTransform.m_qRotation1;

        while (1)
        {
            const ConstraintSolverInfo::FloatAndHalfRecord& di =
                si.m_kDeactivationClassInfo[motion.m_kMotionState.m_uiDeactivationClass];
            {
                hkReal maxSqrd = di.m_afFloatPair[select];
                hkVector4 transDist;
                transDist.setSub4(refPosition, currentPosition);
                const hkReal distSqrd = transDist.lengthSquared3();
                if (distSqrd > maxSqrd)
                {
                    break;
                }
            }
            {
                hkQuaternion refQ;
                hkVector4Util_S::unPackInt32IntoQuaternion(refOrientation, refQ.m_vec);
                hkReal maxSqrd = di.m_ahHalfPair[select];
                hkVector4 dist;
                dist.setSub4(refQ.m_vec, currentRotation.m_vec);
                const hkReal distSqrd = dist.lengthSquared4();
                if (distSqrd > maxSqrd)
                {
                    break;
                }
            }
            motion.incrementNumInactiveFramesMt(select, si.m_ucDeactivationInactiveFrameSelectFlags[select]);
            goto END_OF_FUNCTION;
        }

        motion.zeroNumInactiveFramesMt(select, si.m_ucDeactivationInactiveFrameSelectFlags[select]);
        {
            hkVector4 pos = currentPosition;
            pos.zeroElement(3);
            refPosition = pos;
        }
        refOrientation = PackFloatsToUInt(currentRotation.m_vec);
    }
END_OF_FUNCTION:
    return MathUtilities::max2(motion.getNumInactiveFrames(0), motion.getNumInactiveFrames(1));
}

// @fnv 0x00d29bf0
extern "C" int __cdecl FUN_00d29bf0(const ConstraintSolverInfo& solverInfo, const hkStepInfo& info,
                                    const QuantizedBoundsData* accumulators, hkpMotion* const* motions, int numMotions,
                                    int motionOffset)
{
    const QuantizedBoundsData* accu = accumulators;
    int numInactiveFrames = 0x7fffffff;

    for (int i = numMotions - 1; i >= 0; motions++, accu++, i--)
    {
        hkpMotion* motion = hkAddByteOffset(motions[0], motionOffset);

        hkVector4 integrationLinearVelocity;
        hkVector4 integrationAngularVelocity;
        hkVector4 angularMomentum;

        switch (motion->m_type)
        {
        case hkpMotion::MOTION_INVALID:
        case hkpMotion::MOTION_THIN_BOX_INERTIA: {
            hkpThinBoxMotion* tbm = static_cast<hkpThinBoxMotion*>(motion);
            hkVector4 angVelLocalSpace = accu->m_vAngularVelocity;
            hkVector4 in;
            in.setReciprocal4(tbm->m_kInertiaAndMassInv);
            angVelLocalSpace.mul4(in);
            angularMomentum.FUN_00c7f700(tbm->getTransform().getRotation(), angVelLocalSpace);
        }
        case hkpMotion::MOTION_BOX_INERTIA: {
            motion->m_kTranslationalVelocity = accu->m_vLinearVelocity;
            motion->m_kAngularVelocity._setRotatedDir(motion->getTransform().getRotation(), accu->m_vAngularVelocity);
            integrationLinearVelocity = accu->getSumLinearVel();
            integrationAngularVelocity.FUN_00c7f700(motion->getTransform().getRotation(), accu->getSumAngularVel());
            goto sphereInertia;
        }
        case hkpMotion::MOTION_KEYFRAMED: {
            motion->m_kTranslationalVelocity = motion->m_kTranslationalVelocity;
            motion->m_kAngularVelocity = motion->m_kAngularVelocity;
            integrationLinearVelocity = motion->m_kTranslationalVelocity;
            integrationAngularVelocity = motion->m_kAngularVelocity;
            goto sphereInertia;
        }
        case hkpMotion::MOTION_SPHERE_INERTIA:
        case hkpMotion::MOTION_CHARACTER: {
            motion->m_kTranslationalVelocity = accu->m_vLinearVelocity;
            motion->m_kAngularVelocity = accu->m_vAngularVelocity;
            integrationLinearVelocity = accu->getSumLinearVel();
            integrationAngularVelocity = accu->getSumAngularVel();
        }
        sphereInertia:
            MotionUtilities::_stepMotionState(info, integrationLinearVelocity, integrationAngularVelocity,
                                              motion->m_kMotionState);
        default:
            break;
        }

        if (motion->m_type == hkpMotion::MOTION_THIN_BOX_INERTIA)
        {
            hkpThinBoxMotion* tbm = static_cast<hkpThinBoxMotion*>(motion);
            tbm->m_kTranslationalVelocity = accu->m_vLinearVelocity;
            hkVector4 h;
            h.setRotatedInverseDir(tbm->getTransform().getRotation(), angularMomentum);
            h.mul4(tbm->m_kInertiaAndMassInv);
            tbm->m_kAngularVelocity.FUN_00c7f700(tbm->getTransform().getRotation(), h);
        }
        MotionUtilities::_clipVelocities(motion->m_kMotionState, motion->m_kTranslationalVelocity,
                                         motion->m_kAngularVelocity);
        numInactiveFrames =
            MathUtilities::min2(numInactiveFrames, hkRigidMotionUtilCheckDeactivation(solverInfo, *motion));
    }
    return numInactiveFrames;
}

}

#include <math.h>
namespace ApplyForcesStepPrivate {
extern "C" void _ReadWriteBarrier(void);
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;
extern "C"
{
    __m128 _mm_load_ss(const float*);
    __m128 _mm_load_ps(const volatile float*);
    void _mm_store_ps(float*, __m128);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_cmplt_ps(__m128, __m128);
    __m128 _mm_cmpeq_ps(__m128, __m128);
    __m128 _mm_rcp_ps(__m128);
    int _mm_movemask_ps(__m128);
}

struct Vec
{
    __m128 quad;
};
struct Quat
{
    union
    {
        __m128 quad;
        struct
        {
            float x, y, z, w;
        };
    };
};
struct __declspec(align(16)) Vec4f
{
    float x, y, z, w;
    __m128& q()
    {
        return *(__m128*)this;
    }
};
struct Transform;
struct FUN_004b4ab0_Class : Vec4f
{
    Vec4f* FUN_004b4ab0(const Transform*, const Vec4f*);
};
struct FUN_005611c0_t : Vec4f
{
    void FUN_005611c0();
};
struct Quaternion : FUN_005611c0_t
{
    void FUN_00c66320(Vec4f*, Vec4f*);
};
struct Transform
{
    Vec axisX, axisY, axisZ, translation;
    void FUN_00cb2d90(void*);
};
struct Sweep
{
    Vec previousCenter, center;
    Quat previousRotation, rotation;
    Vec localCenter;
};
struct MotionState : Transform
{
    Sweep sweep;
    Vec deltaAngle;
    float radius, linearDamping, angularDamping;
    unsigned char maxLinear, maxAngular, deactivationClass, unused;
};
struct Motion
{
    void* vtable;
    unsigned short memorySize, references;
    unsigned char type, deactivationCounter;
    unsigned short inactive[2], flags;
    MotionState state;
    Vec inverseInertia, linearVelocity, angularVelocity;
    Vec referencePosition[2];
    unsigned int referenceOrientation[2];
    unsigned int userData;
    unsigned short properties;
    short gravityFactor;
};
struct TimeInterval
{
    float startTime, endTime, deltaTime, invDeltaTime;
};
struct DeactivationClass
{
    float unk00, unk04, unk08, unk0c;
    float positionThreshold[2];
    short rotationThreshold[2];
};
struct SolverInfo
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    DeactivationClass deactivation[6];
    unsigned char unk10c, unk10d, unk10e, unk10f;
    int unk110, unk114, unk118, unk11c, unk120;
    unsigned char unk124, selectFlags[2];
};
extern float DAT_010c7948[];

extern const double DAT_010ce4a0 = (double)0.130529f;
extern const double DAT_010ce498 = (double)0.044408f;
extern const double DAT_010ce488;

extern Vec DAT_01268370;
extern Vec DAT_01017d10;
extern Vec DAT_010cbf80;
extern Vec DAT_010cbfc0;
unsigned int __cdecl PackFloatsToUInt(Quat*);
struct RotationVector : Vec4f
{
    void FUN_00c7f700(Transform*, Vec4f*);
};

static __forceinline __m128 splat(float b)
{
    __m128 t = _mm_load_ss(&b);
    return _mm_shuffle_ps(t, t, 0);
}
static __forceinline float maxf2(float a, float b)
{
    return a > b ? a : b;
}
static __forceinline float maxVelocity(const unsigned char& index)
{
    return DAT_010c7948[index];
}
static __forceinline const float& maxVelocityRef(const unsigned char& index)
{
    return DAT_010c7948[index];
}
static __forceinline float& elem(Vec& v, int i)
{
    return ((float*)&v.quad)[i];
}
static __forceinline float lengthSquared3(const __m128& a)
{
    __m128 v = _mm_mul_ps(a, a);
    __m128 y = _mm_shuffle_ps(v, v, 0x55);
    __m128 z = _mm_shuffle_ps(v, v, 0xaa);
    float r;
    _mm_store_ss(&r, _mm_add_ss(z, _mm_add_ss(y, v)));
    return r;
}
static __forceinline bool validVelocities(Motion* motion)
{
    const Vec& l = motion->linearVelocity;
    const Vec& a = motion->angularVelocity;
    __m128 fMinimumInputValue = DAT_010cbf80.quad;
    int bits = _mm_movemask_ps(_mm_cmplt_ps(_mm_and_ps(l.quad, DAT_01017d10.quad), fMinimumInputValue));
    bits &= _mm_movemask_ps(_mm_cmplt_ps(_mm_and_ps(a.quad, DAT_01017d10.quad), fMinimumInputValue));
    bits &= _mm_movemask_ps(_mm_cmpeq_ps(l.quad, l.quad));
    bits &= _mm_movemask_ps(_mm_cmpeq_ps(a.quad, a.quad));
    return (bits & 7) == 7;
}
static __forceinline void clampVelocities(Motion* motion)
{
    MotionState* s = &motion->state;
    float maxAngularSquare = maxVelocity(s->maxAngular) * maxVelocity(s->maxAngular);

    __m128 linear = motion->linearVelocity.quad;
    float linearSquare = lengthSquared3(linear);
    float angularSquare = lengthSquared3(motion->angularVelocity.quad);
    float maxLinearSquare = maxVelocity(s->maxLinear) * maxVelocity(s->maxLinear);
    if (linearSquare > maxLinearSquare || linearSquare != linearSquare)
    {
        float inverse = 1.0f / (float)sqrt(linearSquare);
        motion->linearVelocity.quad = _mm_mul_ps(splat(inverse * maxVelocity(s->maxLinear)), linear);
        if (linearSquare != linearSquare)
            motion->linearVelocity.quad = DAT_01268370.quad;
    }
    if (angularSquare > maxAngularSquare || angularSquare != angularSquare)
    {
        float inverse = 1.0f / (float)sqrt(angularSquare);
        motion->angularVelocity.quad =
            _mm_mul_ps(splat(inverse * maxVelocity(s->maxAngular)), motion->angularVelocity.quad);
        if (angularSquare != angularSquare)
            motion->angularVelocity.quad = DAT_01268370.quad;
    }
}
static __forceinline float minf2(float a, float b)
{
    return b < a ? b : a;
}
static __forceinline float minf(float a, float b)
{
    return a > b ? b : a;
}
static __forceinline void updateTransform(const Sweep& history, Transform& world)
{
    world.FUN_00cb2d90((void*)&history.rotation);
    __m128 local = history.localCenter.quad;
    __m128 y = _mm_mul_ps(_mm_shuffle_ps(local, local, 0x55), world.axisY.quad);
    __m128 x = _mm_mul_ps(_mm_shuffle_ps(local, local, 0), world.axisX.quad);
    __m128 z = _mm_mul_ps(_mm_shuffle_ps(local, local, 0xaa), world.axisZ.quad);
    world.translation.quad = _mm_sub_ps(history.center.quad, _mm_add_ps(_mm_add_ps(y, x), z));
}

static __forceinline void integrateMotion(Motion* motion, const TimeInterval* step)
{
    MotionState* s = &motion->state;
    if (!validVelocities(motion))
    {
        motion->linearVelocity.quad = DAT_01268370.quad;
        motion->angularVelocity.quad = DAT_01268370.quad;
    }
    s->sweep.previousCenter.quad = s->sweep.center.quad;
    elem(s->sweep.previousCenter, 3) = step->startTime;
    __m128 linear = motion->linearVelocity.quad;
    float speedSquare = lengthSquared3(linear);
    if (speedSquare > maxVelocity(s->maxLinear) * maxVelocity(s->maxLinear))
    {
        float inverse = 1.0f / (float)sqrt(speedSquare);
        motion->linearVelocity.quad = _mm_mul_ps(splat(inverse * maxVelocity(s->maxLinear)), linear);
    }
    float dt = step->deltaTime;
    s->sweep.center.quad = _mm_add_ps(_mm_mul_ps(splat(dt), motion->linearVelocity.quad), s->sweep.center.quad);
    elem(s->sweep.center, 3) = step->invDeltaTime;
    Quaternion rotation;
    *(Quat*)&rotation = s->sweep.rotation;
    s->sweep.previousRotation.quad = rotation.q();
    __m128 angular = motion->angularVelocity.quad;
    Vec4f angle;
    angle.q() = _mm_mul_ps(splat((float)(step->deltaTime * 0.5)), angular);
    float halfSquare = (float)(lengthSquared3(angle.q()) * (4.0 / (3.1415927410125732 * 3.1415927410125732)));
    float limit = minf(maxVelocity(s->maxAngular) * step->deltaTime, 0.9f);
    float limitSquare = limit * limit;
    if (halfSquare <= limitSquare)
    {
        float fourth = halfSquare * halfSquare;
        angle.w = (float)((1.0 - ((double)0.822948f) * halfSquare - DAT_010ce4a0 * fourth) -
                          (halfSquare * DAT_010ce498) * fourth);
    }
    else
    {
        float root = (float)sqrt(halfSquare);
        float inverse = 1.0f / root;
        float factor = inverse * limit;
        motion->angularVelocity.quad = _mm_mul_ps(splat(factor), angular);
        angle.q() = _mm_mul_ps(splat(factor), angle.q());
        halfSquare = limit * limit;
        float h = halfSquare;
        float fourth = h * h;
        angle.w = (float)((1.0 - ((double)0.822948f) * h - DAT_010ce4a0 * fourth) - (h * DAT_010ce498) * fourth);
    }
    rotation.FUN_00c66320(&angle, &rotation);
    rotation.FUN_005611c0();
    s->deltaAngle.quad = _mm_add_ps(angle.q(), angle.q());
    ((float*)&s->deltaAngle)[3] = (float)((float)sqrt(halfSquare) * 3.1415927410125732);
    s->sweep.rotation.quad = rotation.q();
    updateTransform(s->sweep, *s);
}
static __forceinline void applyGravity(Motion* motion, const Vec* gravity, __m128 gravityFactor)
{
    __m128 impulse = _mm_mul_ps(_mm_shuffle_ps(gravityFactor, gravityFactor, 0), gravity->quad);
    motion->linearVelocity.quad = _mm_add_ps(impulse, motion->linearVelocity.quad);
}
static __forceinline void mul4(Vec& v, float s)
{
    __m128 t = _mm_load_ss(&s);
    v.quad = _mm_mul_ps(_mm_shuffle_ps(t, t, 0), v.quad);
}
static __forceinline void applyDamping(Motion* motion, const TimeInterval* step)
{
    float delta = step->deltaTime;
    float zero = 0.0f;
    float linear = 1.0f - motion->state.linearDamping * delta;
    mul4(motion->linearVelocity, zero > linear ? zero : linear);
    float angular = 1.0f - motion->state.angularDamping * delta;
    mul4(motion->angularVelocity, zero > angular ? zero : angular);
}

static __forceinline bool rotationMoved(Motion* motion, const DeactivationClass* config, int which)
{
    unsigned int packed = motion->referenceOrientation[which];
    Vec4f previous;
    previous.x = (float)(((int)(packed & 255) - 128) * DAT_010ce488);
    previous.y = (float)(((int)((packed >> 8) & 255) - 128) * DAT_010ce488);
    previous.z = (float)(((int)((packed >> 16) & 255) - 128) * DAT_010ce488);
    previous.w = (float)(DAT_010ce488 * (float)((int)(packed >> 24) - 128));
    __m128 difference = _mm_sub_ps(previous.q(), motion->state.sweep.rotation.quad);
    difference = _mm_mul_ps(difference, difference);
    __m128 pair = _mm_add_ps(_mm_shuffle_ps(difference, difference, 0x4e), difference);
    float square;
    _mm_store_ss(&square, _mm_add_ps(_mm_shuffle_ps(pair, pair, 0xb1), pair));
    int thresholdBits = (int)config->rotationThreshold[which] << 16;
    float threshold = *(float*)&thresholdBits;
    _ReadWriteBarrier();
    return square > threshold;
}
template <class T> struct Ref
{
    T* p;
    T* operator->() const
    {
        return p;
    }
    operator T*() const
    {
        return p;
    }
};
struct MotionList
{
    Motion** p;
    Motion* operator*() const
    {
        return *p;
    }
    void next()
    {
        ++p;
    }
};

// @fnv 0x00d28a30
extern "C" int __cdecl FUN_00d28a30(Ref<const SolverInfo> info, const TimeInterval* step, Ref<const Vec> gravity,
                                    MotionList motions, int count, int offset)
{
    int minimum = 0x7fffffff;
    for (int remaining = count - 1; remaining >= 0; motions.next(), --remaining)
    {
        Motion* motion = (Motion*)((char*)*motions + offset);
        int gravityBits = (int)motion->gravityFactor << 16;
        __m128 gravityFactor = _mm_load_ss((float*)&gravityBits);
        switch (motion->type)
        {
        case 6: {
            applyGravity(motion, gravity, gravityFactor);
            applyDamping(motion, step);
            FUN_004b4ab0_Class localAngular;
            localAngular.FUN_004b4ab0(&motion->state, (const Vec4f*)&motion->angularVelocity);
            __m128 inertia = motion->inverseInertia.quad;
            __m128 reciprocal = _mm_rcp_ps(inertia);
            reciprocal =
                _mm_sub_ps(_mm_add_ps(reciprocal, reciprocal), _mm_mul_ps(_mm_mul_ps(reciprocal, inertia), reciprocal));
            localAngular.q() = _mm_mul_ps(reciprocal, localAngular.q());
            RotationVector momentum;
            momentum.FUN_00c7f700(&motion->state, &localAngular);
            integrateMotion(motion, step);
            FUN_004b4ab0_Class transformed;
            transformed.FUN_004b4ab0(&motion->state, &momentum);
            transformed.q() = _mm_mul_ps(transformed.q(), motion->inverseInertia.quad);
            ((RotationVector*)&motion->angularVelocity)->FUN_00c7f700(&motion->state, &transformed);
            clampVelocities(motion);
            break;
        }
        default:
            applyGravity(motion, gravity, gravityFactor);
        case 7:
            applyDamping(motion, step);
        case 4:
            integrateMotion(motion, step);
            break;
        case 5:
            continue;
        }
        unsigned int counter = (unsigned int)motion->deactivationCounter + 1;
        motion->deactivationCounter = (unsigned char)counter;
        if ((counter & 3) == 0)
        {
            int which;
            if ((counter & 15) != 0)
                which = 0;
            else if (counter == 256)
            {
                motion->deactivationCounter = 255;
                goto counters;
            }
            else
            {
                motion->deactivationCounter = 0;
                which = 1;
            }
            float radius = minf2(motion->state.radius, 1.0f);
            float energy = lengthSquared3(motion->linearVelocity.quad) +
                           radius * radius * lengthSquared3(motion->angularVelocity.quad);
            float& refW = ((float*)&motion->referencePosition[which])[3];
            refW = maxf2(refW, energy);
            Vec* reference = &motion->referencePosition[which];
            Quat* rotation = &motion->state.sweep.rotation;
            __m128 difference = _mm_sub_ps(reference->quad, motion->state.sweep.center.quad);
            const DeactivationClass* config = &info->deactivation[motion->state.deactivationClass];
            if (lengthSquared3(difference) > config->positionThreshold[which])
                goto reset;
            if (rotationMoved(motion, config, which))
            {
            reset:
                motion->inactive[which] =
                    (unsigned short)((unsigned short)((unsigned short)info->selectFlags[which] << 7) |
                                     (unsigned short)(motion->inactive[which] & 127))
                    << 7;
                Vec4f center = *(Vec4f*)&motion->state.sweep.center;
                reference->quad = _mm_and_ps(center.q(), DAT_010cbfc0.quad);
                motion->referenceOrientation[which] = PackFloatsToUInt(rotation);
            }
            else
            {
                int count = motion->inactive[which] & 127;
                motion->inactive[which] =
                    (unsigned short)((count - (count >> 6) + 1) |
                                     (unsigned short)((unsigned short)((unsigned short)info->selectFlags[which] << 7) |
                                                      (unsigned short)count)
                                         << 7);
            }
        }
    counters:
        int inactive1 = motion->inactive[1] & 127;
        int inactive0 = motion->inactive[0] & 127;
        int inactive = inactive0 > inactive1 ? inactive0 : inactive1;
        if (minimum >= inactive)
            minimum = inactive;
    }
    return minimum;
}
}
