
// src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/response/hkpsimplecollisionresponse.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C"
{
    __m128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_setzero_ps();
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_andnot_ps(__m128, __m128);
}
#include <math.h>

class Scalar
{
    __m128 value;

  public:
    Scalar()
    {}
    Scalar(const __m128& x) : value(x)
    {}
    Scalar(float x)
    {
        value = _mm_load_ss(&x);
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline const __m128& get() const
    {
        return value;
    }
};

extern const __m128 DAT_010ec7f0;
class Vector
{
  public:
    __m128 q;
    __forceinline Vector()
    {}
    __forceinline Vector(const Vector& x) : q(x.q)
    {}
    __forceinline Vector(const __m128& x) : q(x)
    {}
    __forceinline void operator=(const Vector& x)
    {
        q = x.q;
    }
    __forceinline void operator=(const __m128& x)
    {
        q = x;
    }
    __forceinline float& operator()(int i)
    {
        return reinterpret_cast<float*>(&q)[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&q)[i];
    }
    __forceinline void zero()
    {
        q = _mm_setzero_ps();
    }
    __forceinline void subtract(const Vector& a, const Vector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void scale(const Scalar& a)
    {
        q = _mm_mul_ps(a.splat(), q);
    }
    __forceinline void product(const Scalar& a, const Vector& b)
    {
        q = _mm_mul_ps(a.splat(), b.q);
    }
    __forceinline void interpolate(const Vector& a, const Vector& b, const Scalar& t)
    {
        __m128 f = t.splat();
        __m128 inv = _mm_sub_ps(DAT_010ec7f0, f);
        q = _mm_add_ps(_mm_mul_ps(inv, a.q), _mm_mul_ps(f, b.q));
    }
    __forceinline Scalar dot(const Vector& b) const
    {
        __m128 squares = _mm_mul_ps(q, b.q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0x55), squares);
        return _mm_add_ss(_mm_shuffle_ps(squares, squares, 0xaa), xy);
    }
    __forceinline Scalar inverseLength() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 squared = dot(*this).get();
        const __m128 mask = _mm_cmpeq_ss(squared, zero);
        const __m128 rough = _mm_rsqrt_ss(squared);
        const __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, rough), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, rough), rough)));
        return _mm_andnot_ps(mask, refined);
    }
    __forceinline void normalize()
    {
        __m128 inv = inverseLength().splat();
        q = _mm_mul_ps(inv, q);
    }
    __forceinline void cross(const Vector& a, const Vector& b)
    {
        const __m128 qa = a.q;
        const __m128 qb = b.q;
        __m128 forward = _mm_mul_ps(_mm_shuffle_ps(qa, qa, 0xc9), _mm_shuffle_ps(qb, qb, 0xd2));
        __m128 reverse = _mm_mul_ps(_mm_shuffle_ps(qa, qa, 0xd2), _mm_shuffle_ps(qb, qb, 0xc9));
        q = _mm_sub_ps(forward, reverse);
    }
};
struct Matrix
{
    Vector col0, col1, col2;
    __forceinline Vector& column(int i)
    {
        return (&col0)[i];
    }
};
struct Transform
{
    Matrix rotation;
    Vector translation;
};
struct Sweep
{
    Vector center0, center1, rotation0, rotation1, localCenter;
    __forceinline float inverseTime() const
    {
        return center1(3);
    }
    __forceinline float fraction(float t) const
    {
        float f = (t - center0(3)) * inverseTime();
        return f;
    }
};
struct MotionState
{
    Transform transform;
    Sweep swept;
    Vector deltaAngle;
    float radius;
    unsigned short dampingLinear, dampingAngular;
    float timeFactor;
    unsigned int packedRotation;
};
struct Input
{
    Vector relative;
    Matrix inertia;
    Vector inverseMass;
    const Transform* transform;
};
struct Velocity
{
    Vector linear, angular;
};
struct AlignedDynamicArray
{
    Matrix jacobian, inverseJacobian;
    Vector inverseMass;
    float mass;
    const Transform* transform;
};
struct Constraint
{
    AlignedDynamicArray body0, body1;
    Matrix basis, inverseMass, mass;
};
struct Point
{
    Vector position, normal;
    __forceinline const Vector& pos() const
    {
        return position;
    }
    __forceinline const Vector& dir() const
    {
        return normal;
    }
};
struct Params
{
    float friction, restitution, maxImpulse, externalVelocity, extraVelocity, extraSlope;
    unsigned char breached;
};
struct Result
{
    float impulse, velocityA, velocityB;
};
struct RefObject
{
    virtual void slot00();
    unsigned short memorySize, referenceCount;
};
struct Motion : RefObject
{
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void inverseInertia(Matrix&) const;
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void setLinear(const Vector&);
    virtual void setAngular(const Vector&);
    unsigned char type, counter;
    unsigned short inactive0, inactive1;
    MotionState state;
    Vector inverseMass, linear, angular;
    __forceinline const Transform& transform() const
    {
        return state.transform;
    }
    __forceinline MotionState* motionState()
    {
        return &state;
    }
    __forceinline const Vector& linearVelocity() const
    {
        return linear;
    }
    __forceinline const Vector& angularVelocity() const
    {
        return angular;
    }
};
struct Manager
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void begin(const Point&, Input&, Velocity&, Input&, Velocity&);
    virtual void end(const Point&, float, Input&, Velocity&, Input&, Velocity&);
};
extern "C" void __cdecl FUN_00df5950(const Input&, const Input&, const Matrix&, Constraint&);
extern "C" float __cdecl FUN_00df5f80(const Constraint&, Params&, Velocity&, Velocity&);
extern "C" void __cdecl FUN_00df5e80(const Constraint&, Velocity&, Velocity&, Vector&);

static __forceinline void centerAt(const MotionState& ms, float time, Vector& center)
{
    float f = ms.swept.fraction(time);
    center.interpolate(ms.swept.center0, ms.swept.center1, f);
}
static __forceinline void velocityOf(const MotionState& ms, Vector& linear, Vector& angular)
{
    linear.subtract(ms.swept.center1, ms.swept.center0);
    linear.scale(ms.swept.inverseTime());
    angular.product(ms.swept.inverseTime(), ms.deltaAngle);
}
static __forceinline float absolute(float f)
{
    return fabsf(f);
}
static __forceinline void perpendicular(const Vector& normal, Vector& tangent)
{
    int smallest = 0, left = 1, right = 2;
    float x = absolute(normal(0));
    float y = absolute(normal(1));
    float z = absolute(normal(2));
    if (y < x)
    {
        left = 0;
        smallest = 1;
        x = y;
    }
    if (z < x)
    {
        right = smallest;
        smallest = 2;
    }
    tangent.zero();
    tangent(left) = normal(right);
    tangent(right) = -normal(left);
}
static __forceinline void makeBasis(const Vector& normal, Matrix& basis)
{
    basis.column(0) = normal;
    perpendicular(normal, basis.column(1));
    basis.column(1).normalize();
    basis.column(2).cross(normal, basis.column(1));
}

// @fnv 0x00d9f250
extern "C" void __cdecl FUN_00d9f250(const Point& point, float time, Params& params, Motion* a, Motion* b, Manager* mgr,
                                     Result& result)
{
    Input ia;
    {
        ia.inverseMass = a->inverseMass;
        Vector center;
        centerAt(*a->motionState(), time, center);
        ia.relative.subtract(point.pos(), center);
        a->inverseInertia(ia.inertia);
        ia.transform = &a->transform();
    }
    Input ib;
    {
        ib.inverseMass = b->inverseMass;
        Vector center;
        centerAt(*b->motionState(), time, center);
        ib.relative.subtract(point.pos(), center);
        b->inverseInertia(ib.inertia);
        ib.transform = &b->transform();
    }
    Velocity va, vb;
    va.linear = a->linearVelocity();
    va.angular = a->angularVelocity();
    vb.linear = b->linearVelocity();
    vb.angular = b->angularVelocity();
    Velocity oa, ob;
    velocityOf(*a->motionState(), oa.linear, oa.angular);
    velocityOf(*b->motionState(), ob.linear, ob.angular);
    Constraint info;
    Matrix basis;
    makeBasis(point.dir(), basis);
    mgr->begin(point, ia, va, ib, vb);
    FUN_00df5950(ia, ib, basis, info);
    result.impulse = FUN_00df5f80(info, params, va, vb);
    mgr->end(point, result.impulse, ia, va, ib, vb);
    {
        Vector pa, pb;
        FUN_00df5e80(info, oa, vb, pa);
        FUN_00df5e80(info, va, ob, pb);
        result.velocityA = pa(0);
        result.velocityB = pb(0);
    }
    if (a->type != 5)
    {
        a->setLinear(va.linear);
        a->setAngular(va.angular);
    }
    if (b->type != 5)
    {
        b->setLinear(vb.linear);
        b->setAngular(vb.angular);
    }
}

namespace ConstraintInit {
extern "C" void _ReadWriteBarrier(void);
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_div_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_set_ps1(float);
    __m128 _mm_load_ss(float const*);
    __m128 _mm_load_ps1(float const*);
    __m128 _mm_load_ps(float const*);
    void _mm_store_ps(float*, __m128);
}
typedef __m128 hkQuadReal;
typedef float hkReal;
namespace MathUtilities {
template <typename T> inline T max2(T x, T y)
{
    return x > y ? x : y;
}
}
namespace AlgorithmUtilities {
template <typename T> inline void swap(T& x, T& y)
{
    T t(x);
    x = y;
    y = t;
}
}

class RealLane
{
  public:
    hkQuadReal q;
    RealLane()
    {}
    RealLane(const hkQuadReal& v) : q(v)
    {}
    RealLane(float x)
    {
        q = _mm_load_ss(&x);
    }
    const hkQuadReal& quad() const
    {
        return q;
    }
    hkQuadReal spread() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
static __forceinline RealLane operator/(const RealLane& a, const RealLane& b)
{
    return _mm_div_ss(a.quad(), b.quad());
}
static __forceinline void maximumLane(const RealLane& a, const RealLane& b, RealLane& result)
{
    result = _mm_max_ps(a.quad(), b.quad());
}

class hkMatrix3;
class hkVector4
{
  public:
    hkQuadReal m_vComponents;

    void cofactor(const hkVector4& b, const hkVector4& a)
    {
        hkQuadReal p = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                  _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        hkQuadReal n = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                  _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(p, n);
    }
    RealLane inner3(const hkVector4& v) const
    {
        hkQuadReal terms = _mm_mul_ps(m_vComponents, v.m_vComponents);
        hkQuadReal xy = _mm_add_ss(_mm_shuffle_ps(terms, terms, 0x55), terms);
        return _mm_add_ss(_mm_shuffle_ps(terms, terms, 0xaa), xy);
    }
    void scaled(const hkQuadReal& scale, const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(scale, v.m_vComponents);
    }

    hkReal& operator()(int i)
    {
        return ((hkReal*)&m_vComponents)[i];
    }
    const hkReal& operator()(int i) const
    {
        return ((const hkReal*)&m_vComponents)[i];
    }
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    void add4(const hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    void setCross(const hkVector4& v0, const hkVector4& v1)
    {
        const hkQuadReal b = v1.m_vComponents;
        const hkQuadReal a = v0.m_vComponents;
        m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                                   _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
    }
    inline void _setMul3(const hkMatrix3& r, const hkVector4& v);
};
class hkMatrix3
{
  public:
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    const hkVector4& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
    hkReal& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }
    void operator=(const hkMatrix3& m)
    {
        m_kColumn0 = m.m_kColumn0;
        m_kColumn1 = m.m_kColumn1;
        m_kColumn2 = m.m_kColumn2;
    }
    void setZero()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
    }
    void addTo(hkMatrix3& dst) const
    {
        dst.m_kColumn0.m_vComponents = _mm_add_ps(dst.m_kColumn0.m_vComponents, m_kColumn0.m_vComponents);
        dst.m_kColumn1.m_vComponents = _mm_add_ps(dst.m_kColumn1.m_vComponents, m_kColumn1.m_vComponents);
        dst.m_kColumn2.m_vComponents = _mm_add_ps(dst.m_kColumn2.m_vComponents, m_kColumn2.m_vComponents);
    }
    __forceinline void SetProduct(const hkMatrix3& a, const hkMatrix3& b)
    {
        const hkQuadReal c0 = a.m_kColumn0.m_vComponents;
        const hkQuadReal c1 = a.m_kColumn1.m_vComponents;
        const hkQuadReal c2 = a.m_kColumn2.m_vComponents;
        for (int i = 2; i >= 0; i--)
        {
            const hkQuadReal t = b.getColumn(i).m_vComponents;
            const hkQuadReal xb = _mm_shuffle_ps(t, t, 0x00);
            const hkQuadReal yb = _mm_shuffle_ps(t, t, 0x55);
            const hkQuadReal zb = _mm_shuffle_ps(t, t, 0xaa);
            getColumn(i).m_vComponents =
                _mm_add_ps(_mm_add_ps(_mm_mul_ps(xb, c0), _mm_mul_ps(yb, c1)), _mm_mul_ps(zb, c2));
        }
    }
    __forceinline void setMul2(const hkMatrix3& a, const hkMatrix3& b)
    {
        const hkQuadReal& c1 = a.getColumn(1).m_vComponents;
        const hkQuadReal& c0 = a.getColumn(0).m_vComponents;
        const hkQuadReal& c2 = a.getColumn(2).m_vComponents;

        for (int i = 2; i >= 0; i--)
        {
            hkQuadReal t = b.getColumn(i).m_vComponents;
            hkQuadReal x = _mm_shuffle_ps(t, t, 0x00);
            hkQuadReal p = _mm_mul_ps(c0, x);
            hkQuadReal y = _mm_shuffle_ps(t, t, 0x55);
            hkQuadReal q = _mm_mul_ps(c1, y);
            hkQuadReal z = _mm_shuffle_ps(t, t, 0xaa);
            hkQuadReal w = _mm_mul_ps(c2, z);
            getColumn(i).m_vComponents = _mm_add_ps(_mm_add_ps(p, q), w);
        }
    }
    void transpose()
    {
        AlgorithmUtilities::swap(m_kColumn1(0), m_kColumn0(1));
        AlgorithmUtilities::swap(m_kColumn2(0), m_kColumn0(2));
        AlgorithmUtilities::swap(m_kColumn2(1), m_kColumn1(2));
    }
};
inline void hkVector4::_setMul3(const hkMatrix3& r, const hkVector4& v)
{
    hkQuadReal t = v.m_vComponents;
    hkQuadReal xb = _mm_shuffle_ps(t, t, 0x00);
    hkQuadReal r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, xb);
    hkQuadReal yb = _mm_shuffle_ps(t, t, 0x55);
    hkQuadReal r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, yb);
    hkQuadReal zb = _mm_shuffle_ps(t, t, 0xaa);
    hkQuadReal r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, zb);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
static __forceinline hkQuadReal hkCross(const hkQuadReal& a, const hkQuadReal& b)
{
    const hkQuadReal cross0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    const hkQuadReal cross1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(cross0, cross1);
}
extern hkQuadReal DAT_010c7170;
extern const double DAT_010da2b0;
extern const double DAT_010da2a8;
extern const float DAT_010da2a0;
struct BodyInput
{
    hkVector4 m_r;
    hkMatrix3 m_kInverseInertiaMatrix;
    hkVector4 m_vel;
    int m_50;
};
struct BodyResult
{
    hkMatrix3 m_pJacobian;
    hkMatrix3 m_ij;
    hkVector4 m_vel;
    hkReal m_fViscosityFriction;
    int m_74;
    int unk78;
    int unk7C;
};
struct SolverResult
{
    BodyResult m_apEntities[2];
    hkMatrix3 m_axes;
    hkMatrix3 m_kFirstMatrix;
    hkMatrix3 m_kSecondMatrix;
};
static __forceinline hkQuadReal hkDot3q(const hkQuadReal& a, const hkQuadReal& b)
{
    const hkQuadReal x2 = _mm_mul_ps(a, b);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
}
static __forceinline void inverseSymmetric(const hkMatrix3& m, float eps, hkMatrix3& inv)
{

    const hkVector4& central = m.getColumn(0);
    hkVector4 r0;
    r0.cofactor(m.getColumn(2), m.getColumn(1));
    hkVector4 r1;
    r1.cofactor(central, m.getColumn(2));
    hkVector4 r2;
    r2.cofactor(m.getColumn(1), central);
    RealLane minimum(eps * eps * eps);
    RealLane determinant = central.inner3(r0);
    maximumLane(determinant, minimum, determinant);
    RealLane inverse = reinterpret_cast<const RealLane&>(DAT_010c7170) / determinant;
    hkQuadReal factor = inverse.spread();
    inv.getColumn(0).scaled(factor, r0);
    inv.getColumn(1).scaled(factor, r1);
    inv.getColumn(2).scaled(factor, r2);
}
// @fnv 0x00df5950
extern "C" void __cdecl FUN_00df5950(const BodyInput* bodyA, const BodyInput* bodyB, const hkMatrix3& axes,
                                     SolverResult* out)
{
    hkReal sumInvMass = bodyA->m_vel(3) + bodyB->m_vel(3);
    out->m_kFirstMatrix.setZero();
    out->m_kFirstMatrix(0, 0) = sumInvMass;
    out->m_kFirstMatrix(1, 1) = sumInvMass;
    out->m_kFirstMatrix(2, 2) = sumInvMass;
    out->m_axes = axes;
    const BodyInput* body = bodyA;
    for (int i = 0; i < 2; i++)
    {
        BodyResult& bo = out->m_apEntities[i];
        bo.m_pJacobian.m_kColumn0.setCross(body->m_r, axes.m_kColumn0);
        bo.m_pJacobian.m_kColumn1.setCross(body->m_r, axes.m_kColumn1);
        bo.m_pJacobian.m_kColumn2.setCross(body->m_r, axes.m_kColumn2);
        bo.m_ij.SetProduct(body->m_kInverseInertiaMatrix, bo.m_pJacobian);
        bo.m_pJacobian.transpose();
        hkMatrix3 tmp;
        tmp.setMul2(bo.m_pJacobian, bo.m_ij);
        tmp.addTo(out->m_kFirstMatrix);
        bo.m_vel = body->m_vel;
        bo.m_fViscosityFriction = 1.0f / MathUtilities::max2(body->m_vel(3), 1e-11f);
        bo.m_74 = body->m_50;
        body = bodyB;
    }
    hkMatrix3& m = out->m_kFirstMatrix;
    hkMatrix3& inv = out->m_kSecondMatrix;
    inverseSymmetric(m, 1e-11f, inv);
    _ReadWriteBarrier();
    hkMatrix3* __restrict mass = &m;
    hkReal a = (*mass)(0, 0);
    (*mass)(3, 0) = 1.0f / (a < DAT_010da2b0 ? 1e-11f : a);
    hkReal b = (*mass)(2, 2) * (*mass)(1, 1) - (*mass)(1, 2) * (*mass)(2, 1);
    (*mass)(3, 1) = 1.0f / (b < DAT_010da2a8 ? DAT_010da2a0 : b);
}

}
