// src/havok/common/geometryutilities/misc/hkgeometryutils_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/common/geometryutilities/misc/hkgeometryutils_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/common/geometryutilities/misc/hkgeometryutils_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/geometryutilities/misc/hkgeometryutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/common/geometryutilities/misc/hkgeometryutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/geometryutilities/misc/hkgeometryutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <math.h>
struct hkMemory
{
    virtual ~hkMemory() throw();
    virtual void* allocate(int size) throw();
    virtual void* unk_slot2() throw();
    virtual void* allocateChunk(int* inoutSize) throw();
    virtual void deallocate(void* p, int size) throw();
};
struct hkThreadMemory
{
    int pad00;
    int pad04;
    int pad08;
    int pad0c;
    hkMemory* m_pMemoryAllocator;
};
void* __cdecl FUN_00c85750() throw();
__forceinline hkThreadMemory* getThreadMemory() throw()
{
    return (hkThreadMemory*)FUN_00c85750();
}
void __cdecl FUN_00c90940(void* mem, void* array, int elemSize) throw();
void __cdecl FUN_00c908c0(void* mem, void* array, int reqCapacity, int elemSize) throw();
extern const float DAT_01016248;
extern const float DAT_01017718;
extern const float DAT_01011d78;
extern const __m128 DAT_010c71a0;
extern const __m128 DAT_010c71e0;

class CapsuleScalar
{
    __m128 value;

  public:
    CapsuleScalar()
    {}
    CapsuleScalar(float x)
    {
        value = _mm_load_ss(&x);
    }
    CapsuleScalar(const __m128& x) : value(x)
    {}
    operator float() const
    {
        float x;
        _mm_store_ss(&x, value);
        return x;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
    __forceinline const __m128& quad() const
    {
        return value;
    }
};

struct hkTransform;
struct hkQuaternion;
struct __declspec(align(16)) hkVector4
{
    __m128 m_vComponents;
    hkVector4() throw()
    {}
    __forceinline void broadcast(int i)
    {
        m_vComponents = _mm_shuffle_ps(m_vComponents, m_vComponents, 0);
    }
    __forceinline void multiply(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void accumulate(const hkVector4& a, const hkVector4& c)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, c.m_vComponents));
    }
    __forceinline void scaledAdd(const hkVector4& a, const hkVector4& c, const hkVector4& s)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(c.m_vComponents, s.m_vComponents));
    }

    __forceinline void set(float x, float y, float z, float w = 0)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void scaledAdd(const hkVector4& a, const hkVector4& b, const CapsuleScalar& s)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(s.splat(), b.m_vComponents));
    }

    hkVector4(__m128 q) throw() : m_vComponents(q)
    {}
    __forceinline hkVector4(const hkVector4& r) throw() : m_vComponents(r.m_vComponents)
    {}
    __forceinline hkVector4& operator=(const hkVector4& r) throw()
    {
        _mm_store_ps((float*)&m_vComponents, r.m_vComponents);
        return *this;
    }
    void FUN_00c7f640(const hkTransform& t, const hkVector4& v) throw();
    __forceinline void SetTransformedPoint(const hkTransform& t, const hkVector4& v) throw()
    {
        FUN_00c7f640(t, v);
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b) throw()
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b) throw()
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(float s) throw()
    {
        __m128 scalar = _mm_load_ss(&s);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), m_vComponents);
    }
    __forceinline void mulReal(float s) throw()
    {
        float scalarValue = (float)(double)s;
        __m128 scalar = _mm_load_ss(&scalarValue);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(scalar, scalar, 0), m_vComponents);
    }
    __forceinline CapsuleScalar dot3(const hkVector4& a) const throw()
    {
        __m128 m = _mm_mul_ps(_mm_load_ps((const float*)&m_vComponents), a.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
        sum = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), sum);
        return CapsuleScalar(sum);
    }
    __forceinline float length3() const throw()
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 xY = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), xY);
        sum = _mm_sqrt_ss(sum);
        float res;
        _mm_store_ss(&res, sum);
        return res;
    }
    __forceinline void normalize3() throw()
    {
        __m128 lenSq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(lenSq, lenSq, 0x55), lenSq);
        sum = _mm_add_ss(_mm_shuffle_ps(lenSq, lenSq, 0xaa), sum);
        __m128 r = _mm_rsqrt_ss(sum);
        __m128 nr = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), r),
                               _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(sum, r), r)));
        __m128 zero = _mm_set_ss(0.0f);
        __m128 mask = _mm_cmpeq_ss(sum, zero);
        nr = _mm_andnot_ps(mask, nr);
        nr = _mm_shuffle_ps(nr, nr, 0);
        m_vComponents = _mm_mul_ps(m_vComponents, nr);
    }
    __forceinline void setCross(const hkVector4& a, const hkVector4& b) throw()
    {
        __m128 a1 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9);
        __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2);
        __m128 a2 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2);
        __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9);
        m_vComponents = _mm_sub_ps(_mm_mul_ps(a1, b1), _mm_mul_ps(a2, b2));
    }
    __forceinline void setRotatedCached(const hkQuaternion& q, const hkVector4& v, const __m128& yz,
                                        const __m128& zx) throw();
    __forceinline void SetRotatedDirection(const hkQuaternion& q, const hkVector4& v) throw();
};
struct __declspec(align(16)) hkQuaternion
{
    hkVector4 m_vec;
    void FUN_00cb2450(const hkVector4& axis, float angle) throw();
};
__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& q, const hkVector4& v) throw()
{
    hkVector4 offset;
    offset.m_vComponents = DAT_010c71e0;
    hkVector4 real;
    real.m_vComponents = _mm_shuffle_ps(q.m_vec.m_vComponents, q.m_vec.m_vComponents, 0xff);
    hkVector4 factor;
    factor.scaledAdd(offset, real, real);
    hkVector4 result;
    result.multiply(v, factor);
    hkVector4 dot;
    dot.m_vComponents = q.m_vec.dot3(v).quad();
    dot.broadcast(0);
    result.accumulate(dot, q.m_vec);
    hkVector4 cross;
    cross.setCross(q.m_vec, v);
    result.accumulate(real, cross);
    setAdd4(result, result);
}
__forceinline void hkVector4::setRotatedCached(const hkQuaternion& q, const hkVector4& v, const __m128& yz,
                                               const __m128& zx) throw()
{
    hkVector4 offset;
    offset.m_vComponents = DAT_010c71e0;
    hkVector4 real;
    real.m_vComponents = _mm_shuffle_ps(q.m_vec.m_vComponents, q.m_vec.m_vComponents, 0xff);
    hkVector4 factor;
    factor.scaledAdd(offset, real, real);
    hkVector4 result;
    result.multiply(v, factor);
    hkVector4 dot;
    dot.m_vComponents = q.m_vec.dot3(v).quad();
    dot.broadcast(0);
    result.accumulate(dot, q.m_vec);
    hkVector4 cross;
    __m128 qY = _mm_shuffle_ps(q.m_vec.m_vComponents, q.m_vec.m_vComponents, 0xc9);
    __m128 qZ = _mm_shuffle_ps(q.m_vec.m_vComponents, q.m_vec.m_vComponents, 0xd2);
    cross.m_vComponents = _mm_sub_ps(_mm_mul_ps(qY, zx), _mm_mul_ps(qZ, yz));
    result.accumulate(real, cross);
    setAdd4(result, result);
}
struct __declspec(align(16)) hkRotation
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    __forceinline void setIdentity() throw()
    {
        __m128 zero = _mm_setzero_ps();
        m_kColumn0.m_vComponents = zero;
        ((float*)&m_kColumn0)[0] = 1.0f;
        m_kColumn1.m_vComponents = zero;
        ((float*)&m_kColumn1)[1] = 1.0f;
        m_kColumn2.m_vComponents = zero;
        ((float*)&m_kColumn2)[2] = 1.0f;
    }
};
struct __declspec(align(16)) hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArray() throw()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void release(hkMemory& memory) throw()
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            memory.deallocate(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    ~hkArray() throw()
    {
        release(*getThreadMemory()->m_pMemoryAllocator);
    }
    __forceinline void reserve(int n) throw()
    {
        hkThreadMemory* memory = getThreadMemory();
        if ((m_iCapacityState & 0x3fffffff) < n)
        {
            FUN_00c908c0(memory->m_pMemoryAllocator, this, n, sizeof(T));
        }
    }
    __forceinline T& AllocatePair() throw()
    {
        hkThreadMemory* memory = getThreadMemory();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            FUN_00c90940(memory->m_pMemoryAllocator, this, sizeof(T));
        }
        return m_data[m_iElementCount];
    }
    static __forceinline void fillOne(T* dst, int n, const T& val)
    {
        for (int i = 0; i < n; ++i)
            dst[i] = val;
    }
    __forceinline void AddBack(const T& val) throw()
    {
        hkThreadMemory* memory = getThreadMemory();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            FUN_00c90940(memory->m_pMemoryAllocator, this, sizeof(T));
        fillOne(m_data + m_iElementCount, 1, val);
        ++m_iElementCount;
    }
    static __forceinline void copyItems(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            dst[i].m_vComponents = src[i].m_vComponents;
        }
    }
    __forceinline hkArray& operator=(const hkArray& other) throw()
    {
        hkMemory* memory = getThreadMemory()->m_pMemoryAllocator;
        if ((m_iCapacityState & 0x3fffffff) < other.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
            {
                memory->deallocate(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
            }
            int reqBytes = other.m_iElementCount * sizeof(T);
            m_data = (T*)memory->allocateChunk(&reqBytes);
            m_iCapacityState = reqBytes / (int)sizeof(T);
        }
        m_iElementCount = other.m_iElementCount;
        T* dst = m_data;
        const T* src = other.m_data;
        copyItems(dst, src, m_iElementCount);
        return *this;
    }
};
struct Triangle
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iMaterialIndex;
    __forceinline void set(int a, int b, int c) throw()
    {
        m_kPointA = a;
        m_kPointB = b;
        m_iThirdValue = c;
        m_iMaterialIndex = -1;
    }
};
struct hkGeometry
{
    hkArray<hkVector4> m_kVertices;
    hkArray<Triangle> m_uiTriangleCount;
    void* operator new(size_t size) throw()
    {
        return getThreadMemory()->m_pMemoryAllocator->allocate(size);
    }
};
static __forceinline void appendCapsuleEnd(hkGeometry* geom, int numSides, int startVertex, Triangle& tri)
{
    if (numSides > 0)
    {
        hkArray<Triangle>& triangles = geom->m_uiTriangleCount;
        int i = 1;
        int remaining = numSides;
        do
        {
            tri.m_kPointB = startVertex + i - 1;
            tri.m_kPointA = startVertex + i % numSides;
            tri.m_iThirdValue = startVertex + numSides;
            triangles.AddBack(tri);
            ++i;
        } while (--remaining);
    }
}
// @fnv 0x00da16d0
void __cdecl FUN_00da16d0(const hkVector4& top, const hkVector4& bottom, float radius, int numHeightSegments,
                          int numSides, const hkTransform& transform, hkGeometry*& outGeom) throw()
{
    const int halfSides = numSides >> 1;
    hkArray<hkVector4> localVertices;
    hkVector4 axis;
    axis.setSub4(bottom, top);
    float len = axis.length3();
    hkTransform localTransform;
    if (len > 0.0f)
    {
        axis.normalize3();
        hkVector4 zAxis;
        zAxis.m_vComponents = DAT_010c71a0;
        float dotZ = zAxis.dot3(axis);
        if (fabsf(dotZ) < 0.99999f)
        {
            hkVector4 yAxis;
            yAxis.setCross(axis, zAxis);
            yAxis.normalize3();
            localTransform.m_rotation.m_kColumn0.setCross(yAxis, axis);
            localTransform.m_rotation.m_kColumn1.m_vComponents = yAxis.m_vComponents;
            localTransform.m_rotation.m_kColumn2.m_vComponents = axis.m_vComponents;
        }
        else
        {
            localTransform.m_rotation.setIdentity();
        }
    }
    else
    {
        localTransform.m_rotation.setIdentity();
    }
    hkVector4 center;
    center.setAdd4(bottom, top);
    center.mul4(0.5f);
    localTransform.m_vTranslation = center;
    double halfLen;
    int numVerts = (numHeightSegments + halfSides * 2 - 1) * numSides + 2;
    hkVector4 topCenter;
    {
        float scalar = (float)(-len * 0.5);
        topCenter.set(0, 0, scalar, 0);
    }
    halfLen = len * 0.5;
    hkVector4 bottomCenter;
    {
        float scalar = (float)halfLen;
        bottomCenter.set(0, 0, scalar, 0);
    }
    hkVector4 axisDelta;
    axisDelta.setSub4(bottomCenter, topCenter);
    hkVector4 unitZ;
    unitZ.set(0.0f, 0.0f, 1.0f, 0.0f);
    hkVector4 unitX;
    unitX.set(1.0f, 0.0f, 0.0f, 0.0f);
    hkVector4 negUnitY;
    negUnitY.set(0.0f, -1.0f, 0.0f, 0.0f);
    localVertices.reserve(numVerts);
    hkVector4 pt;
    double apexHeight = halfLen + radius;
    // Top apex
    {
        float apex = (float)apexHeight;
        pt.set(0.0f, 0.0f, apex, 0.0f);
        pt.SetTransformedPoint(localTransform, pt);
        localVertices.AddBack(pt);
    }
    int i, j;
    // Top hemisphere rings
    for (i = halfSides - 1; i >= 0; --i)
    {
        float angle = (float)((float)i / (float)halfSides * 3.1415927410125732421875 * 0.5);
        hkQuaternion qY;
        qY.FUN_00cb2450(negUnitY, angle);
        hkVector4 v3;
        v3.SetRotatedDirection(qY, unitX);

        j = 0;
        if (numSides > 0)
        {
            __m128 yz;
            (void)yz;
            __m128 zx = _mm_shuffle_ps(v3.m_vComponents, v3.m_vComponents, 0xd2);
            yz = _mm_shuffle_ps(v3.m_vComponents, v3.m_vComponents, 0xc9);
            for (; j < numSides; ++j)
            {
                float sideAngle = (float)((float)j / (float)numSides * 3.1415927410125732421875 * 2.0);
                hkQuaternion sideRotation;
                sideRotation.FUN_00cb2450(unitZ, sideAngle);
                hkVector4 radial;
                radial.setRotatedCached(sideRotation, v3, yz, zx);

                float radiusScale = radius;
                pt.scaledAdd(bottomCenter, radial, radiusScale);
                pt.SetTransformedPoint(localTransform, pt);
                localVertices.AddBack(pt);
            }
        }
    }
    // Cylinder body
    const hkVector4& cylinderAxis = unitX;
    for (j = numHeightSegments - 1; j > 0; --j)
    {
        for (i = 0; i < numSides; ++i)
        {
            float sideAngle = (float)((float)i / (float)numSides * 3.1415927410125732421875 * 2.0);
            hkQuaternion sideRotation;
            sideRotation.FUN_00cb2450(unitZ, sideAngle);
            hkVector4 radial;
            radial.SetRotatedDirection(sideRotation, cylinderAxis);

            float vRing = (float)j / (float)numHeightSegments;
            hkVector4 segCenter;
            segCenter.scaledAdd(topCenter, axisDelta, vRing);
            float radiusScale = radius;
            pt.scaledAdd(segCenter, radial, radiusScale);
            pt.SetTransformedPoint(localTransform, pt);
            localVertices.AddBack(pt);
        }
    }
    // Bottom hemisphere
    for (i = 0; i < halfSides; ++i)
    {
        float angle = (float)(-(float)i / (float)halfSides * 3.1415927410125732421875 * 0.5);
        hkQuaternion qY;
        qY.FUN_00cb2450(negUnitY, angle);
        hkVector4 v3;
        v3.SetRotatedDirection(qY, unitX);
        for (j = 0; j < numSides; ++j)
        {
            float sideAngle = (float)((float)j / (float)numSides * 3.1415927410125732421875 * 2.0);
            hkQuaternion sideRotation;
            sideRotation.FUN_00cb2450(unitZ, sideAngle);
            hkVector4 radial;
            radial.SetRotatedDirection(sideRotation, v3);

            float radiusScale = radius;
            pt.scaledAdd(topCenter, radial, radiusScale);
            pt.SetTransformedPoint(localTransform, pt);
            localVertices.AddBack(pt);
        }
    }
    // Bottom apex
    {
        float apex = (float)(-apexHeight);
        pt.set(0.0f, 0.0f, apex, 0.0f);
        pt.SetTransformedPoint(localTransform, pt);
        localVertices.AddBack(pt);
    }
    hkGeometry* geom = new hkGeometry();
    geom->m_kVertices = localVertices;
    for (int i = 0; i < geom->m_kVertices.m_iElementCount; ++i)
    {
        geom->m_kVertices.m_data[i].SetTransformedPoint(transform, geom->m_kVertices.m_data[i]);
    }
    Triangle tri;
    tri.m_iMaterialIndex = -1;
    int startVertex = 1;
    if (numSides > 0)
    {
        hkArray<Triangle>& triangles = geom->m_uiTriangleCount;
        int i = 1;
        int remaining = numSides;
        do
        {
            tri.m_kPointA = 0;
            tri.m_kPointB = i;
            tri.m_iThirdValue = i % numSides + 1;
            triangles.AddBack(tri);
            ++i;
        } while (--remaining);
    }
    for (j = 0; j < numHeightSegments + halfSides * 2 - 2; ++j)
    {
        {
            if (numSides > 0)
            {
                hkArray<Triangle>& triangles = geom->m_uiTriangleCount;
                int i = 1;
                int remaining = numSides;
                do
                {
                    tri.m_kPointA = startVertex + i - 1;
                    tri.m_kPointB = startVertex + i - 1 + numSides;
                    tri.m_iThirdValue = startVertex + i % numSides + numSides;
                    triangles.AddBack(tri);
                    tri.m_kPointB = startVertex + i - 1;
                    tri.m_kPointA = startVertex + i % numSides;
                    tri.m_iThirdValue = startVertex + numSides + i % numSides;
                    triangles.AddBack(tri);
                    ++i;
                } while (--remaining);
            }
            startVertex += numSides;
        }
    }
    appendCapsuleEnd(geom, numSides, startVertex, tri);
    outGeom = geom;
}
