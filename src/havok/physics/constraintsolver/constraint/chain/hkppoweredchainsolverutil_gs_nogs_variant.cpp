
// src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil_gs_nogs_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/constraintsolver/constraint/chain/hkppoweredchainsolverutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00df0810_Channel
{
    float value1;
    float value2;
    int unk08;
    int unk0c;
    int unk10;
};
struct FUN_00df0810_Source
{
    unsigned char modes;
    FUN_00df0810_Channel channels[3];
};
struct FUN_00df0810_Dest
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float values[3];
    int unk1c;
};
void __cdecl CopyChannelValue(int index, int channel, FUN_00df0810_Source* sources, FUN_00df0810_Dest* dests);
#include <xmmintrin.h>
static __forceinline void CopyHelper(__m128* d, const void* s)
{
    d[0] = ((__m128*)s)[0];
    d[1] = ((__m128*)s)[1];
    d[2] = ((__m128*)s)[2];
    d[3] = ((__m128*)s)[3];
    d[4] = ((__m128*)s)[4];
    d[5] = ((__m128*)s)[5];
    d[6] = ((__m128*)s)[6];
    d[7] = ((__m128*)s)[7];
    d[8] = ((__m128*)s)[8];
}
struct ObjF
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
    float f0b4;
    float f0b8;
    float f0bc;
    float f0c0;
    float f0c4;
    float f0c8;
    float f0cc;
    float f0d0;
    float f0d4;
    float f0d8;
    float f0dc;
    float f0e0;
    float f0e4;
    float f0e8;
    float f0ec;
    float f0f0;
    float f0f4;
    float f0f8;
    float f0fc;
    float f100;
    float f104;
    float f108;
    float f10c;
    float f110;
    float f114;
    float f118;
    float f11c;
    float f120;
    float f124;
    float f128;
    float f12c;
    float f130;
    float f134;
    float f138;
    float f13c;
    float f140;
    float f144;
    float f148;
    float f14c;
    float f150;
    float f154;
    float f158;
    float f15c;
    float f160;
    float f164;
    float f168;
    float f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
    float f180;
    float f184;
    float f188;
    float f18c;
    float f190;
    float f194;
    float f198;
    float f19c;
    float f1a0;
    float f1a4;
    float f1a8;
    float f1ac;
    float f1b0;
    float f1b4;
    float f1b8;
    float f1bc;
    float f1c0;
    float f1c4;
    float f1c8;
    float f1cc;
    float f1d0;
    float f1d4;
    float f1d8;
    float f1dc;
    float f1e0;
    float f1e4;
    float f1e8;
    float f1ec;
    float f1f0;
    float f1f4;
    float f1f8;
    float f1fc;
    float f200;
    float f204;
    float f208;
    float f20c;
    float f210;
    float f214;
    float f218;
    float f21c;
    float f220;
    float f224;
    float f228;
    float f22c;
    float f230;
    float f234;
    float f238;
    float f23c;
    float f240;
    float f244;
    float f248;
    float f24c;
    float f250;
    float f254;
    float f258;
    float f25c;
    float f260;
    float f264;
    float f268;
    float f26c;
    float f270;
    float f274;
    float f278;
    float f27c;
    float f280;
    float f284;
    float f288;
    float f28c;
    float f290;
    float f294;
    float f298;
    float f29c;
    float f2a0;
    float f2a4;
    float f2a8;
    float f2ac;
    float f2b0;
    float f2b4;
    float f2b8;
    float f2bc;
    float f2c0;
    float f2c4;
    float f2c8;
    float f2cc;
    float f2d0;
    float f2d4;
    float f2d8;
    float f2dc;
    float f2e0;
    float f2e4;
    float f2e8;
    float f2ec;
    float f2f0;
    float f2f4;
    float f2f8;
    float f2fc;
    float f300;
    float f304;
    float f308;
    float f30c;
    float f310;
    float f314;
    float f318;
    float f31c;
    float f320;
    float f324;
    float f328;
    float f32c;
    float f330;
    float f334;
    float f338;
    float f33c;
    float f340;
    float f344;
    float f348;
    float f34c;
    float f350;
    float f354;
    float f358;
    float f35c;
    float f360;
    float f364;
    float f368;
    float f36c;
    float f370;
    float f374;
    float f378;
    float f37c;
    float f380;
    float f384;
    float f388;
    float f38c;
    float f390;
    float f394;
    float f398;
    float f39c;
    float f3a0;
    float f3a4;
    float f3a8;
    float f3ac;
    float f3b0;
    float f3b4;
    float f3b8;
    float f3bc;
};
struct __declspec(align(16)) CBuf
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
};
struct __declspec(align(16)) BufA
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
    float f0b4;
    float f0b8;
    float f0bc;
    float f0c0;
    float f0c4;
    float f0c8;
    float f0cc;
    float f0d0;
    float f0d4;
    float f0d8;
    float f0dc;
    float f0e0;
    float f0e4;
    float f0e8;
    float f0ec;
    float f0f0;
    float f0f4;
    float f0f8;
    float f0fc;
    float f100;
    float f104;
    float f108;
    float f10c;
    float f110;
    float f114;
    float f118;
    float f11c;
    float f120;
    float f124;
    float f128;
    float f12c;
    float f130;
    float f134;
    float f138;
    float f13c;
    float f140;
    float f144;
    float f148;
    float f14c;
    float f150;
    float f154;
    float f158;
    float f15c;
    float f160;
    float f164;
    float f168;
    float f16c;
    float f170;
    float f174;
    float f178;
    float f17c;
};
struct __declspec(align(16)) BufB
{
    float f000;
    float f004;
    float f008;
    float f00c;
    float f010;
    float f014;
    float f018;
    float f01c;
    float f020;
    float f024;
    float f028;
    float f02c;
    float f030;
    float f034;
    float f038;
    float f03c;
    float f040;
    float f044;
    float f048;
    float f04c;
    float f050;
    float f054;
    float f058;
    float f05c;
    float f060;
    float f064;
    float f068;
    float f06c;
    float f070;
    float f074;
    float f078;
    float f07c;
    float f080;
    float f084;
    float f088;
    float f08c;
    float f090;
    float f094;
    float f098;
    float f09c;
    float f0a0;
    float f0a4;
    float f0a8;
    float f0ac;
    float f0b0;
    float f0b4;
    float f0b8;
    float f0bc;
};
extern void __cdecl ResetJacobianRows(int a, int b, void* c, void* d);
extern void __cdecl FUN_00df07c0(int a, void* b);
extern void __cdecl FUN_00e29250(void* a, void* b);
extern void __cdecl FUN_00e29470(void* a, void* b, int c);
extern void __cdecl FUN_00e29380(void* a, void* b);
extern void __cdecl FUN_00e298f0(void* a, void* b);
extern float DAT_0104da4c;
void __cdecl FUN_00df0870(int arg0, ObjF* __restrict obj, int arg2, __m128* arg3, int* arg4);
struct hkVector4
{
    union
    {
        __m128 m_vComponents;
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    };
};
struct hkAabb
{
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};
struct MatrixGroup
{
    char data0[0xc0];
    char data1[0xc0];
    char pad[0x240];
};
struct InputStruct
{
    char pad0[4];
    int count;
    char pad1[0x18];
    MatrixGroup* matrices;
    char pad2[8];
    hkAabb* aabbs;
};
extern "C" void __cdecl FUN_00e29510(void* out, const void* matrix, const void* in);
void __cdecl FUN_00df11a0(InputStruct* a, hkAabb* out);

extern "C" void _ReadBarrier(void);
class ScalarValue
{
    __m128 value;

  public:
    __forceinline ScalarValue(__m128 v) : value(v)
    {}
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
};
class Vector4f
{
    __m128 value;

  public:
    __forceinline Vector4f()
    {}
    __forceinline Vector4f(const Vector4f& v) : value(v.value)
    {}
    __forceinline Vector4f(const __m128& v) : value(v)
    {}
    __forceinline operator __m128() const
    {
        return value;
    }
    __forceinline void operator=(const Vector4f& v)
    {
        value = v.value;
    }
    __forceinline void operator=(const __m128& v)
    {
        value = v;
    }
    __forceinline float& operator()(int i)
    {
        return ((float*)&value)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return ((const float*)&value)[i];
    }
    __forceinline void setZero4()
    {
        value = _mm_setzero_ps();
    }
    __forceinline void setMul4(const Vector4f& a, const Vector4f& b)
    {
        value = _mm_mul_ps(a, b);
    }
    __forceinline void mul4(const Vector4f& b)
    {
        value = _mm_mul_ps(value, b.value);
    }
    __forceinline void add4(const Vector4f& b)
    {
        value = _mm_add_ps(value, b.value);
    }
    __forceinline void sub4(const Vector4f& b)
    {
        value = _mm_sub_ps(value, b.value);
    }
    __forceinline void setBroadcast3clobberW(const Vector4f& a, int i)
    {
        setBroadcast(a, i);
    }
    __forceinline void setBroadcast(const Vector4f& a, int i)
    {
        if (i == 0)
            value = _mm_shuffle_ps(a.value, a.value, 0);
        else if (i == 1)
            value = _mm_shuffle_ps(a.value, a.value, 85);
        else if (i == 2)
            value = _mm_shuffle_ps(a.value, a.value, 170);
        else if (i == 3)
            value = _mm_shuffle_ps(a.value, a.value, 255);
    }
    __forceinline ScalarValue horizontalAdd3() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(value, value, 85), value);
        return _mm_add_ss(_mm_shuffle_ps(value, value, 170), xy);
    }
};
struct Mat3
{
    Vector4f m_kColumn0;
    Vector4f m_kColumn1;
    Vector4f m_kColumn2;
    __forceinline Mat3()
    {}
    __forceinline Vector4f& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    __forceinline const Vector4f& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
    __forceinline float& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }
    __forceinline const float& operator()(int r, int c) const
    {
        return getColumn(c)(r);
    }
    inline void setZero()
    {
        Vector4f zero;
        zero.setZero4();
        m_kColumn0 = zero;
        m_kColumn1 = zero;
        m_kColumn2 = zero;
    }
    inline void _setTranspose(const Mat3& s)
    {
        Mat3& dest = *this;
        dest(0, 0) = s(0, 0);
        dest(1, 1) = s(1, 1);
        dest(2, 2) = s(2, 2);
        dest(3, 0) = 0.0f;
        dest(3, 1) = 0.0f;
        dest(3, 2) = 0.0f;
        dest(1, 0) = s(0, 1);
        dest(0, 1) = s(1, 0);
        dest(2, 0) = s(0, 2);
        dest(0, 2) = s(2, 0);
        dest(2, 1) = s(1, 2);
        dest(1, 2) = s(2, 1);
    }
};
struct Mat6
{
    Mat3 m_iUnknownValue2[2][2];
    __forceinline Mat6()
    {}
    __forceinline void setZero()
    {
        m_iUnknownValue2[0][0].setZero();
        m_iUnknownValue2[0][1].setZero();
        m_iUnknownValue2[1][0].setZero();
        m_iUnknownValue2[1][1].setZero();
    }
};
struct CfmRecord
{
    float linearAdd;
    float linearScale;
    float angularAdd;
    float angularScale;
};
struct BodyRecord
{
    unsigned char kind;
    unsigned int deactivation;
    float gravity;
    Vector4f linearVelocity;
    Vector4f angularVelocity;
    Vector4f inertia;
    Vector4f scratch;
    Mat3 scratchBasis;
};
struct OffsetRecord
{
    unsigned int offset;
    inline const BodyRecord& get(const BodyRecord* base)
    {
        return *(const BodyRecord*)((const char*)base + offset);
    }
};
struct AngularJac
{
    Vector4f a, b;
    __forceinline AngularJac()
    {}
    __forceinline AngularJac(const AngularJac& v)
    {
        b = v.b;
        a = v.a;
    }
    __forceinline float same(const BodyRecord& p, const BodyRecord& q, const AngularJac& j) const
    {
        const AngularJac& self = *this;
        Vector4f aa;
        aa.setMul4(self.a, j.a);
        Vector4f bb;
        bb.setMul4(self.b, j.b);
        aa.mul4(p.inertia);
        bb.mul4(q.inertia);
        aa.add4(bb);
        const float result = aa.horizontalAdd3();
        return result;
    }
};
struct LinearJac
{
    Vector4f rows[3];
    inline AngularJac& angular()
    {
        return *(AngularJac*)&rows[1];
    }
};
static __forceinline float linearSame(const Vector4f& fixedL, const Vector4f& fixedA, const Vector4f& fixedB,
                                      const BodyRecord& p, const BodyRecord& q, const LinearJac& j)
{
    __m128 qInitial;
    _mm_store_ps((float*)&qInitial, q.inertia);
    __m128 pInitial;
    _mm_store_ps((float*)&pInitial, p.inertia);
    _ReadBarrier();
    Vector4f l;
    l.setMul4(fixedL, j.rows[0]);
    Vector4f aa;
    aa.setMul4(fixedA, j.rows[1]);
    Vector4f bb;
    bb.setMul4(fixedB, j.rows[2]);
    Vector4f pm;
    pm.setBroadcast3clobberW(pInitial, 3);
    Vector4f qm;
    qm.setBroadcast3clobberW(qInitial, 3);
    Vector4f pl;
    pl.setMul4(pm, l);
    Vector4f ql;
    ql.setMul4(qm, l);
    aa.mul4(p.inertia);
    bb.mul4(q.inertia);
    pl.add4(ql);
    aa.add4(bb);
    aa.add4(pl);
    const float result = aa.horizontalAdd3();
    return result;
}
class __declspec(align(16)) CachedQuad
{
    __m128 value;

  public:
    __forceinline CachedQuad(const Vector4f& q)
    {
        _mm_store_ps((float*)&value, q);
    }
    __forceinline operator __m128() const
    {
        return value;
    }
};
static __forceinline float angularSame(const CachedQuad& fixedA, const Vector4f& fixedB, const BodyRecord& p,
                                       const BodyRecord& q, const AngularJac& j)
{
    Vector4f aa;
    aa = j.a;
    aa.mul4(Vector4f((__m128)fixedA));
    Vector4f bb;
    bb.setMul4(fixedB, j.b);
    aa.mul4(p.inertia);
    bb.mul4(q.inertia);
    aa.add4(bb);
    const float result = aa.horizontalAdd3();
    return result;
}
struct MatrixTriple
{
    Mat6 lower, lowerInv, upperInv, diagonal, upper;
};
struct MotorAxis
{
    float m_usFlags;
    float m_minImpulse;
    float m_fVelocity;
    float m_fTau;
    float m_fMotorDamping;
};
struct AngularMotorInfo
{
    unsigned char m_ucReferenceTimeSteps;
    MotorAxis m_axes[3];
};
typedef AngularMotorInfo StepRecord;
struct BoolValue
{
    char value;
    __forceinline BoolValue(bool v) : value(v)
    {}
};
extern void __cdecl FUN_00df0870(BoolValue, MatrixTriple*, StepRecord*, Mat6*, Mat6**);
static __forceinline void diagonalAt(int row, const CfmRecord& cfm, const LinearJac* __restrict j,
                                     const AngularJac* __restrict ja, OffsetRecord* offsets, const BodyRecord* base,
                                     Mat6& out)
{
    const int stride = 3;
    const int index = row * stride;
    int r;
    for (r = 0; r < 3; r++)
    {
        if (r < 3)
        {
            Vector4f fl;
            _mm_store_ps((float*)&fl, j[index + r].rows[0]);
            Vector4f fb;
            _mm_store_ps((float*)&fb, j[index + r].rows[2]);
            Vector4f fa;
            _mm_store_ps((float*)&fa, j[index + r].rows[1]);
            Vector4f ab = ja[index + r].b;
            CachedQuad aa(ja[index + r].a);
            const BodyRecord& p = offsets[row].get(base);
            const BodyRecord& q = offsets[row + 1].get(base);
            for (int c = r; c < 3; c++)
            {

                out.m_iUnknownValue2[0][0](c, r) = out.m_iUnknownValue2[0][0](r, c) =
                    linearSame(fl, fa, fb, p, q, j[index + c]);
                out.m_iUnknownValue2[1][1](c, r) = out.m_iUnknownValue2[1][1](r, c) =
                    angularSame(aa, ab, p, q, ja[index + c]);
            }
        }
        out.m_iUnknownValue2[0][0](r, r) *= cfm.linearScale;
        out.m_iUnknownValue2[1][1](r, r) *= cfm.angularScale;
        out.m_iUnknownValue2[0][0](r, r) += cfm.linearAdd;
        out.m_iUnknownValue2[1][1](r, r) += cfm.angularAdd;
    }
    for (r = 0; r < 3; r++)
    {
        AngularJac fixedA = ja[index + r];
        for (int c = 0; c < 3; c++)
        {
            out.m_iUnknownValue2[1][0](r, c) = fixedA.same(offsets[row].get(base), offsets[row + 1].get(base),
                                                           const_cast<LinearJac&>(j[index + c]).angular());
        }
    }
    out.m_iUnknownValue2[0][1]._setTranspose(out.m_iUnknownValue2[1][0]);
}
static __forceinline void innerProducts(const Vector4f* nextPair, AngularJac* nextAngular,
                                        const Vector4f& currentLinear, const Vector4f& jb, const Vector4f& ab,
                                        const BodyRecord& q, Mat6& out, int r)
{
    for (int c = 0; c < 3; c++)
    {
        __m128 initialMass;
        _mm_store_ps((float*)&initialMass, q.inertia);
        _ReadBarrier();
        __m128 nl = nextPair[-1];
        __m128 na = nextPair[0];
        __m128 l = _mm_mul_ps(currentLinear, nl);
        __m128 a = _mm_mul_ps(jb, na);
        initialMass = _mm_shuffle_ps(initialMass, initialMass, 255);
        __m128 lm = _mm_mul_ps(initialMass, l);
        a = _mm_mul_ps(a, q.inertia);
        a = _mm_sub_ps(a, lm);
        float linearSum = Vector4f(a).horizontalAdd3();
        Vector4f al = nextAngular->a;
        out.m_iUnknownValue2[0][0](r, c) = linearSum;
        Vector4f aa;
        aa.setMul4(ab, al);
        aa.mul4(q.inertia);
        out.m_iUnknownValue2[1][1](r, c) = aa.horizontalAdd3();
        Vector4f la;
        la.setMul4(jb, al);
        la.mul4(q.inertia);
        out.m_iUnknownValue2[0][1](r, c) = la.horizontalAdd3();
        Vector4f an;
        an.setMul4(ab, na);
        an.mul4(q.inertia);
        out.m_iUnknownValue2[1][0](r, c) = an.horizontalAdd3();
        ++nextAngular;
        nextPair += 3;
    }
}
static __forceinline void nextAt(int row, LinearJac* j, AngularJac* ja, OffsetRecord* offsets, const BodyRecord* base,
                                 Mat6& out)
{
    const int stride = 3;
    const int index = row * stride;
    const BodyRecord& q = offsets[row + 1].get(base);
    for (int r = 0; r < 3; r++)
    {
        Vector4f jb = j[index + r].rows[2];
        Vector4f ab = ja[index + r].b;

        innerProducts(&j[index + stride].rows[1], ja + index + stride, j[index + r].rows[0], jb, ab, q, out, r);
    }
}
// @fnv 0x00df19e0
void __cdecl FUN_00df19e0(int count, const CfmRecord& cfm, StepRecord* motors, LinearJac* j, AngularJac* __restrict ja,
                          OffsetRecord* offsets, const BodyRecord* base, MatrixTriple* triples, int bufferSize)
{
    Mat6 previous;
    previous.setZero();
    Mat6* upper = &previous;
    int row;
    for (row = 0; row < count; row++)
    {
        diagonalAt(row, cfm, j, ja, offsets, base, triples[row].diagonal);
        if (row < count - 1)
            nextAt(row, j, ja, offsets, base, triples[row].upper);
        else
            triples[row].upper.setZero();
    }
    for (row = 0; row < count; row++)
    {
        BoolValue more(count - 1 - row != 0);
        StepRecord* local = motors + row;
        FUN_00df0870(more, triples + row, local, &previous, &upper);
    }
}

__declspec(align(16)) struct FUN_00df2040_Blk
{
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int dw0c;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1c;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2c;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3c;
    unsigned int dw40;
    unsigned int dw44;
    unsigned int dw48;
    unsigned int dw4c;
    unsigned int dw50;
    unsigned int dw54;
    unsigned int dw58;
    unsigned int dw5c;
    unsigned int dw60;
    unsigned int dw64;
    unsigned int dw68;
    unsigned int dw6c;
    unsigned int dw70;
    unsigned int dw74;
    unsigned int dw78;
    unsigned int dw7c;
    unsigned int dw80;
    unsigned int dw84;
    unsigned int dw88;
    unsigned int dw8c;
    unsigned int dw90;
    unsigned int dw94;
    unsigned int dw98;
    unsigned int dw9c;
    unsigned int dwa0;
    unsigned int dwa4;
    unsigned int dwa8;
    unsigned int dwac;
    unsigned int dwb0;
    unsigned int dwb4;
    unsigned int dwb8;
    unsigned int dwbc;
};

struct FUN_00df0870_Flag
{
    bool b;
};

void __cdecl FUN_00df0870(FUN_00df0870_Flag more, char* elem, const char* dst, FUN_00df2040_Blk* buf, char** outPtr);

// @fnv 0x00df2040
void __cdecl FUN_00df2040(int index, int count, const char* a3, char* a4)
{
    int t = index - 1;
    int i;
    try
    {
        i = (t >= 0) ? t : 0;
    }
    catch (...)
    {
        throw;
    }

    FUN_00df2040_Blk buf;
    char* ptr;
    if (i != 0)
    {
        char* elem = a4 + i * 0x3c0;
        *(__m128*)((char*)&buf + 0x0) = *(__m128*)(elem - 0xc0);
        *(__m128*)((char*)&buf + 0x10) = *(__m128*)(elem - 0xb0);
        *(__m128*)((char*)&buf + 0x20) = *(__m128*)(elem - 0xa0);
        *(__m128*)((char*)&buf + 0x30) = *(__m128*)(elem - 0x90);
        *(__m128*)((char*)&buf + 0x40) = *(__m128*)(elem - 0x80);
        *(__m128*)((char*)&buf + 0x50) = *(__m128*)(elem - 0x70);
        *(__m128*)((char*)&buf + 0x60) = *(__m128*)(elem - 0x60);
        *(__m128*)((char*)&buf + 0x70) = *(__m128*)(elem - 0x50);
        *(__m128*)((char*)&buf + 0x80) = *(__m128*)(elem - 0x40);
        *(__m128*)((char*)&buf + 0x90) = *(__m128*)(elem - 0x30);
        *(__m128*)((char*)&buf + 0xa0) = *(__m128*)(elem - 0x20);
        *(__m128*)((char*)&buf + 0xb0) = *(__m128*)(elem - 0x10);
        ptr = elem - 0x240;
    }
    else
    {
        *(__m128*)((char*)&buf + 0x0) = _mm_setzero_ps();
        *(__m128*)((char*)&buf + 0x10) = _mm_setzero_ps();
        *(__m128*)((char*)&buf + 0x20) = _mm_setzero_ps();
        *(__m128*)((char*)&buf + 0x30) = _mm_setzero_ps();
        *(__m128*)((char*)&buf + 0x40) = _mm_setzero_ps();
        *(__m128*)((char*)&buf + 0x50) = _mm_setzero_ps();
        *(__m128*)((char*)&buf + 0x60) = _mm_setzero_ps();
        *(__m128*)((char*)&buf + 0x70) = _mm_setzero_ps();
        *(__m128*)((char*)&buf + 0x80) = _mm_setzero_ps();
        *(__m128*)((char*)&buf + 0x90) = _mm_setzero_ps();
        *(__m128*)((char*)&buf + 0xa0) = _mm_setzero_ps();
        *(__m128*)((char*)&buf + 0xb0) = _mm_setzero_ps();
        ptr = (char*)&buf;
    }

    for (int k = i; k < count; k++)
    {
        FUN_00df0870_Flag flag;
        flag.b = (count - 1 - k != 0);
        FUN_00df0870(flag, a4 + k * 0x3c0, a3 + k * 0x40, &buf, &ptr);
    }
}
