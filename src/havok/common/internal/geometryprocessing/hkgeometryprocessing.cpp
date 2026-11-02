
// src/havok/common/internal/geometryprocessing/hkgeometryprocessing.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/hkgeometryprocessing.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl Deallocate(void*);
extern int DAT_010d9fc4;

struct FUN_00dee620
{
    void* m_pVTable;
    __thiscall FUN_00dee620(int testFlag);
};

// @fnv 0x00dee620
__thiscall FUN_00dee620::FUN_00dee620(int aiFlags)
{
    m_pVTable = &DAT_010d9fc4;
    if (aiFlags & 1)
        Deallocate(this);
}

extern "C" void __cdecl FUN_00dedf10(void*, void*, void*, void*, int, int);
// Forwards the four pointers to FUN_00dedf10 with two trailing int arguments set to 0.
// @fnv 0x00dee5f0
void __cdecl FUN_00dee5f0(void* first, void* second, void* third, void* fourth)
{
    FUN_00dedf10(first, second, third, fourth, 0, 0);
}

struct FUN_00dee6b0_Class
{
    int unk00;
    float unk04;
    float FUN_00dee6b0(int testFlag);
};
// @fnv 0x00dee6b0
float FUN_00dee6b0_Class::FUN_00dee6b0(int testFlag)
{
    return unk04;
}

extern int DAT_010cd664;

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00dee6c0_cls
{
    int m_vptr;

    FUN_00dee6c0_cls* FUN_00dee6c0(unsigned char acFlags);
};

// Sets the vtable pointer and, when acFlags has bit 0 set, frees this 0x40-byte object through the allocator from FUN_00c85750.
// @fnv 0x00dee6c0
FUN_00dee6c0_cls* FUN_00dee6c0_cls::FUN_00dee6c0(unsigned char acFlags)
{
    m_vptr = (int)&DAT_010cd664;
    if (acFlags & 1)
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, 0x40);
    }
    return this;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C"
{
    __m128 _mm_add_ss(__m128 a, __m128 b);
    __m128 _mm_sub_ss(__m128 a, __m128 b);
    __m128 _mm_div_ss(__m128 a, __m128 b);
    __m128 _mm_add_ps(__m128 a, __m128 b);
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    __m128 _mm_mul_ps(__m128 a, __m128 b);
    __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
    __m128 _mm_load_ps1(const float* p);
    void _mm_store_ss(float* p, __m128 a);
}

struct VectorComponentValue
{
    __m128 m_vValue;

    VectorComponentValue()
    {}
    VectorComponentValue(const __m128& r) : m_vValue(r)
    {}
    operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

__forceinline VectorComponentValue operator/(const VectorComponentValue& a, const VectorComponentValue& b)
{
    return _mm_div_ss(a.m_vValue, b.m_vValue);
}

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void sub4(const hkVector4& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, const VectorComponentValue& r)
    {
        m_vComponents =
            _mm_add_ps(a.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), b.m_vComponents));
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        const __m128 z = _mm_shuffle_ps(x2, x2, 0xaa);
        return _mm_add_ss(z, xySum);
    }
    __forceinline VectorComponentValue lengthSquared3() const
    {
        return dot3(*this);
    }
};

extern const hkVector4 DAT_010c7160;

// Computes the squared distance from point a to the segment bc, clamping the projection parameter to [0,1] and storing it in out.
// @fnv 0x00de94b0
float __cdecl FUN_00de94b0(const hkVector4& a, const hkVector4& b, const hkVector4& c, float* pfT)
{
    hkVector4 d1;
    d1.setSub4(b, a);
    hkVector4 vSegmentVec;
    vSegmentVec.setSub4(c, b);
    const VectorComponentValue fLenSq = vSegmentVec.lengthSquared3();
    const VectorComponentValue num = _mm_sub_ss(DAT_010c7160.m_vComponents, vSegmentVec.dot3(d1).m_vValue);
    const float t = num / fLenSq;
    *pfT = t;
    if (t < 0.0f)
    {
        *pfT = 0.0f;
    }
    else if (t > 1.0f)
    {
        *pfT = 1.0f;
    }
    hkVector4 v;
    v.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_load_ps1(pfT), vSegmentVec.m_vComponents), d1.m_vComponents);
    return v.lengthSquared3();
}

namespace fnv_00dea810 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_cmplt_ps(__m128, __m128);
extern "C" __m128 _mm_and_ps(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern "C" __m128 _mm_or_ps(__m128, __m128);

extern float DAT_0104e148;

struct hkVector4Comparisonq
{
    __m128 m_uiMask;
};
struct hkVector4q
{
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void setMul4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAdd4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4q& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline hkVector4Comparisonq compareLessThan4(const hkVector4q& a) const
    {
        hkVector4Comparisonq c;
        c.m_uiMask = _mm_cmplt_ps(m_vComponents, a.m_vComponents);
        return c;
    }
    __forceinline void setSelect4(const hkVector4Comparisonq& comp, const hkVector4q& trueValue,
                                  const hkVector4q& falseValue)
    {
        m_vComponents = _mm_or_ps(_mm_and_ps(comp.m_uiMask, trueValue.m_vComponents),
                                  _mm_andnot_ps(comp.m_uiMask, falseValue.m_vComponents));
    }
    template <int I> __forceinline void setBroadcast(const hkVector4q& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (I << 6) | (I << 4) | (I << 2) | I);
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
};

struct hkFourTransposedPointsq
{
    hkVector4q m_kVertices[3];
};

struct FourPointsArray
{
    hkFourTransposedPointsq* m_data;
    int m_iElementCount;
};

extern hkVector4q DAT_010d9fe0;
extern hkVector4q DAT_010d0fa0;

// Finds the vertex with the maximum dot product against direction, stores it in supportingVertexOut, and packs vertexId into the w component.
// @fnv 0x00dea810
void __cdecl FUN_00dea810(const FourPointsArray& rotatedVertices, const hkVector4q& direction,
                          hkVector4q& supportingVertexOut)
{

    hkVector4q vBestDot;
    vBestDot.set(DAT_0104e148, DAT_0104e148, DAT_0104e148, DAT_0104e148);
    hkVector4q vCurIndices;
    vCurIndices = DAT_010d9fe0;
    hkVector4q vBestIndices;
    vBestIndices.setZero4();

    int i = 0;
    const hkFourTransposedPointsq* p = rotatedVertices.m_data;
    hkVector4q vDirX;
    vDirX.setBroadcast<0>(direction);
    hkVector4q vDirY;
    vDirY.m_vComponents = _mm_shuffle_ps(direction.m_vComponents, direction.m_vComponents, 0x55);
    hkVector4q vDirZ;
    vDirZ.setBroadcast<2>(direction);

    {
        for (; i < rotatedVertices.m_iElementCount * 4; i += 4)
        {
            hkVector4q x;
            x.setMul4(vDirX, p->m_kVertices[0]);
            hkVector4q y;
            y.setMul4(vDirY, p->m_kVertices[1]);
            hkVector4q z;
            z.setMul4(vDirZ, p->m_kVertices[2]);
            hkVector4q dot;
            dot.setAdd4(x, y);
            dot.add4(z);
            hkVector4Comparisonq comp = vBestDot.compareLessThan4(dot);
            vBestDot.setSelect4(comp, dot, vBestDot);
            vBestIndices.setSelect4(comp, vCurIndices, vBestIndices);
            vCurIndices.add4(DAT_010d0fa0);
            ++p;
        }
    }

    int a = (vBestDot(0) > vBestDot(1)) ? 0 : 1;
    int b = (vBestDot(2) > vBestDot(3)) ? 2 : 3;
    int best = (vBestDot(a) > vBestDot(b)) ? a : b;
    int vertexId = (int)vBestIndices(best);

    const hkFourTransposedPointsq& f = rotatedVertices.m_data[(unsigned int)vertexId >> 2];
    int c = vertexId & 3;
    supportingVertexOut.set(f.m_kVertices[0].m_vComponents.m128_f32[c], f.m_kVertices[1].m_vComponents.m128_f32[c],
                            f.m_kVertices[2].m_vComponents.m128_f32[c], 0.0f);
    *(int*)&supportingVertexOut(3) = vertexId | 0x3f000000;
}
}  // namespace fnv_00dea810

extern __m128 DAT_010c71d0;

struct FUN_00dee640_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_vec10;
    float m_fDist20;
    int unk24;
    int unk28;
    int unk2C;
    void* m_pTag30;
    float UpdateNearestDistance(void* pair);
};

// Computes the squared distance from m_vec10 to the midpoint of the pair and updates m_fDist20 and m_pTag30 when it is smaller.
// @fnv 0x00dee640
float FUN_00dee640_cls::UpdateNearestDistance(void* pair)
{
    const __m128* ab = (const __m128*)pair;
    __m128 vMidpoint = _mm_mul_ps(_mm_add_ps(ab[0], ab[1]), DAT_010c71d0);
    __m128 d = _mm_sub_ps(m_vec10, vMidpoint);
    d = _mm_mul_ps(d, d);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(d, d, 0x55), d);
    float fDistSq;
    _mm_store_ss(&fDistSq, _mm_add_ss(_mm_shuffle_ps(d, d, 0xaa), xy));
    if (fDistSq < m_fDist20)
    {
        m_fDist20 = fDistSq;
        m_pTag30 = pair;
    }
    return 1.0f;
}

extern __m128 DAT_01267e30;

struct Vertex
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    __m128 m_vContactPosition;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    __m128 m_vHitNormal;
};

struct Triangle
{
    unsigned int unk00;
    unsigned int unk04;
    Vertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
    unsigned int unk20;
};

struct Edge
{
    Triangle* m_pkTriangle;
    unsigned int m_uiEdgeIndex;

    Edge(Triangle* t, unsigned int i) : m_pkTriangle(t), m_uiEdgeIndex(i)
    {}
    Edge(unsigned int uid)
    {
        m_uiEdgeIndex = uid & 3;
        m_pkTriangle = (Triangle*)(uid & ~3u);
    }
    unsigned int uid() const
    {
        return (unsigned int)m_pkTriangle + m_uiEdgeIndex;
    }
    Edge link() const
    {
        return Edge(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]);
    }
    void bind(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
    void bindSafe(const Edge& other) const
    {
        m_pkTriangle->m_ppLinks[m_uiEdgeIndex] = other.uid();
        if (other.m_pkTriangle)
            other.m_pkTriangle->m_ppLinks[other.m_uiEdgeIndex] = uid();
    }
};

struct PendingBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    int m_40;
    int m_44;
    unsigned int unk48;
    unsigned int unk4C;
};

struct Sub08_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    Vertex* PushFront(PendingBlock* out);
};

struct Sub20_cls
{
    Triangle* FUN_00e241a0(Triangle* node);
};

struct FUN_00e19200_cls
{
    unsigned int unk00;
    unsigned int unk04;
    Sub08_cls m_08;
    Sub20_cls m_20;
    void FUN_00e19200(Triangle* a, const __m128* b, int c);
};

// Creates a new vertex from b, assigns it to three triangles, and rewires their edge links to split t0.
// @fnv 0x00e19200
void FUN_00e19200_cls::FUN_00e19200(Triangle* apTriangle, const __m128* b, int aiUnused)
{
    PendingBlock stBlock;
    stBlock.m_40 = -1;
    stBlock.m_44 = -1;
    Vertex* v = m_08.PushFront(&stBlock);
    v->m_vHitNormal = DAT_01267e30;
    v->m_vContactPosition = *b;
    Triangle* pTriangle1 = m_20.FUN_00e241a0(apTriangle);
    Triangle* pTriangle2 = m_20.FUN_00e241a0(apTriangle);
    apTriangle->m_kVertices[0] = v;
    pTriangle1->m_kVertices[1] = v;
    pTriangle2->m_kVertices[2] = v;
    Edge(pTriangle1, 2).bindSafe(Edge(apTriangle, 2).link());
    Edge(pTriangle2, 0).bindSafe(Edge(apTriangle, 0).link());
    Edge(apTriangle, 0).bind(Edge(pTriangle2, 1));
    Edge(pTriangle1, 0).bind(Edge(pTriangle2, 2));
    Edge(pTriangle1, 1).bind(Edge(apTriangle, 2));
}

namespace fnv_00dea6b0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);

struct S00dea6b0_Vec
{
    __m128 m_vComponents;

    void setSub4(const S00dea6b0_Vec& a, const S00dea6b0_Vec& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const S00dea6b0_Vec& v1, const S00dea6b0_Vec& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    float dot3(const S00dea6b0_Vec& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 res = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
        float r;
        _mm_store_ss(&r, res);
        return r;
    }
};

// Checks if point p lies inside triangle abc by verifying the dot product of each edge cross product with the triangle normal is at least tol.
// @fnv 0x00dea6b0
bool __cdecl FUN_00dea6b0(const S00dea6b0_Vec& p, const S00dea6b0_Vec& a, const S00dea6b0_Vec& b,
                          const S00dea6b0_Vec& c, float afTolerance)
{
    S00dea6b0_Vec ab;
    ab.setSub4(b, a);
    S00dea6b0_Vec vEdgeAC;
    vEdgeAC.setSub4(c, a);
    S00dea6b0_Vec n;
    n.setCross(ab, vEdgeAC);
    {
        S00dea6b0_Vec e0;
        e0.setSub4(a, p);
        S00dea6b0_Vec e1;
        e1.setSub4(b, p);
        S00dea6b0_Vec cr;
        cr.setCross(e0, e1);
        if (cr.dot3(n) < afTolerance)
            return false;
    }
    {
        S00dea6b0_Vec e0;
        e0.setSub4(b, p);
        S00dea6b0_Vec e1;
        e1.setSub4(c, p);
        S00dea6b0_Vec cr;
        cr.setCross(e0, e1);
        if (cr.dot3(n) < afTolerance)
            return false;
    }
    {
        S00dea6b0_Vec e0;
        e0.setSub4(c, p);
        S00dea6b0_Vec e1;
        e1.setSub4(a, p);
        S00dea6b0_Vec cr;
        cr.setCross(e0, e1);
        if (cr.dot3(n) < afTolerance)
            return false;
    }
    return true;
}
}  // namespace fnv_00dea6b0

extern "C"
{
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_setr_ps(float, float, float, float);
}
extern __m128 DAT_01017d10;
extern float DAT_01011d78;

struct CubeVector
{
    __m128 lanes;
    __forceinline void sum(const CubeVector& lhs, const CubeVector& rhs)
    {
        lanes = _mm_add_ps(lhs.lanes, rhs.lanes);
    }
    __forceinline void difference(const CubeVector& lhs, const CubeVector& rhs)
    {
        lanes = _mm_sub_ps(lhs.lanes, rhs.lanes);
    }
    __forceinline void scale(const __m128& k)
    {
        lanes = _mm_mul_ps(k, lanes);
    }
    __forceinline int longestAxis() const
    {
        CubeVector magnitude;
        magnitude.lanes = _mm_and_ps(lanes, DAT_01017d10);
        const float* p = (const float*)&magnitude.lanes;
        if (p[0] < p[1])
            return p[1] < p[2] ? 2 : 1;
        return p[0] < p[2] ? 2 : 0;
    }
    __forceinline float component(int i) const
    {
        return ((const float*)&lanes)[i];
    }
};
struct CubeBox
{
    CubeVector lower;
    CubeVector upper;
    __forceinline void center(CubeVector& dst) const
    {
        dst.sum(lower, upper);
        dst.scale(DAT_010c71d0);
    }
    __forceinline void extent(CubeVector& dst) const
    {
        dst.difference(upper, lower);
        dst.scale(DAT_010c71d0);
    }
};

// Sets lower and upper from the center using the signed extent component with greatest magnitude on x, y, or z.
// @fnv 0x00de9590
void __cdecl FUN_00de9590(CubeBox* box)
{
    CubeVector center;
    CubeVector extent;
    box->extent(extent);
    box->center(center);
    float size = extent.component(extent.longestAxis());
    CubeVector vRadius;
    vRadius.lanes = _mm_setr_ps(size, size, size, DAT_01011d78);
    box->lower.difference(center, vRadius);
    box->upper.sum(center, vRadius);
}

#include <math.h>
extern const float DAT_0104da4c = 1.1920928955078125e-7f;
extern float DAT_0104da48;
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_load_ss(const float*);

// Computes the closest distance between two line segments defined by start and end points, writing clamped parameters to the output pointers.
// @fnv 0x00dea450
float __cdecl FUN_00dea450(const hkVector4& firstStart, const hkVector4& firstEnd, const hkVector4& secondStart,
                           const hkVector4& secondEnd, float* firstParameter, float* secondParameter)
{
    hkVector4 firstDirection;
    firstDirection.setSub4(firstEnd, firstStart);
    hkVector4 separation;
    separation.setSub4(secondStart, firstStart);
    hkVector4 secondDirection;
    secondDirection.setSub4(secondEnd, secondStart);
    float crossDot = firstDirection.dot3(secondDirection);
    float firstOffset = separation.dot3(firstDirection);
    float secondOffset = separation.dot3(secondDirection);
    float firstSquare = firstDirection.lengthSquared3();
    float secondSquare = secondDirection.lengthSquared3();
    float determinant = secondSquare * firstSquare - crossDot * crossDot;
    float magnitude = (float)fabs(determinant);
    if (magnitude > DAT_0104da4c)
    {
        float numerator = firstSquare * secondOffset - crossDot * firstOffset;
        float parameter = -numerator / determinant;
        float clamped = parameter < 0.0f ? 0.0f : (parameter > 1.0f ? 1.0f : parameter);
        *secondParameter = clamped;
        hkVector4 point;
        point.setAddMul4(secondStart, secondDirection, VectorComponentValue(_mm_load_ss(secondParameter)));
        hkVector4 offset;
        offset.setSub4(firstStart, point);
        VectorComponentValue squaredLength = firstDirection.lengthSquared3();
        VectorComponentValue projected = offset.dot3(firstDirection);
        VectorComponentValue s =
            _mm_sub_ss(DAT_010c7160.m_vComponents, _mm_div_ss(projected.m_vValue, squaredLength.m_vValue));
        float rawFirst = s;
        float firstClamped = rawFirst < 0.0f ? 0.0f : (rawFirst > 1.0f ? 1.0f : rawFirst);
        *firstParameter = firstClamped;
        hkVector4 difference;
        difference.m_vComponents =
            _mm_sub_ps(_mm_add_ps(_mm_mul_ps(_mm_set_ps1(*firstParameter), firstDirection.m_vComponents),
                                  firstStart.m_vComponents),
                       point.m_vComponents);
        VectorComponentValue result = _mm_sqrt_ss(difference.dot3(difference).m_vValue);
        return result;
    }
    *secondParameter = 0.0f;
    *firstParameter = 0.0f;
    return DAT_0104da48;
}

extern const float DAT_0101622c;
struct Vec4
{
    __m128 value;
};
// @fnv 0x00de9b90
Vec4 __cdecl FUN_00de9b90(const Vec4& a, const Vec4& b, const Vec4& c, const Vec4& d)
{
    __m128 scale = _mm_load_ss(&DAT_0101622c);
    __m128 cv = c.value;
    __m128 dv = d.value;
    __m128 bv = b.value;
    __m128 cd = _mm_add_ps(cv, dv);
    __m128 av = a.value;
    __m128 ab = _mm_add_ps(av, bv);
    __m128 sum = _mm_add_ps(cd, ab);
    scale = _mm_shuffle_ps(scale, scale, 0);
    Vec4 result;
    result.value = _mm_mul_ps(sum, scale);
    return result;
}

extern "C"
{
    __m128 _mm_set_ss(float);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
}
extern const float DAT_01012054, DAT_01012068, DAT_0106c2e0;

class ScalarValue
{
    __m128 value;

  public:
    ScalarValue()
    {}
    ScalarValue(const __m128& x) : value(x)
    {}
    ScalarValue(float x) : value(_mm_load_ss(&x))
    {}
    operator float() const
    {
        float x;
        _mm_store_ss(&x, value);
        return x;
    }
    __forceinline const __m128& lanes() const
    {
        return value;
    }
    __forceinline __m128 spread() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
inline ScalarValue operator+(const ScalarValue& x, const ScalarValue& y)
{
    return _mm_add_ss(x.lanes(), y.lanes());
}
inline ScalarValue operator/(const ScalarValue& x, const ScalarValue& y)
{
    return _mm_div_ss(x.lanes(), y.lanes());
}
inline ScalarValue operator-(const ScalarValue& x)
{
    return _mm_sub_ss(DAT_010c7160.m_vComponents, x.lanes());
}

class GeomVector
{
  public:
    __m128 data;
    GeomVector()
    {}
    GeomVector(const __m128& x) : data(x)
    {}
    __forceinline GeomVector(const GeomVector& x) : data(x.data)
    {}
    __forceinline void operator=(const GeomVector& x)
    {
        data = x.data;
    }
    __forceinline void difference(const GeomVector& x, const GeomVector& y)
    {
        data = _mm_sub_ps(x.data, y.data);
    }
    __forceinline void cross(const GeomVector& x, const GeomVector& y)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(x.data, x.data, 0xc9), _mm_shuffle_ps(y.data, y.data, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(x.data, x.data, 0xd2), _mm_shuffle_ps(y.data, y.data, 0xc9));
        data = _mm_sub_ps(first, second);
    }
    __forceinline ScalarValue dot(const GeomVector& x) const
    {
        __m128 product = _mm_mul_ps(data, x.data);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    }
    __forceinline ScalarValue magnitude() const
    {
        return _mm_sqrt_ss(dot(*this).lanes());
    }
    __forceinline ScalarValue inverseMagnitude() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 squared = dot(*this).lanes();
        const __m128 empty = _mm_cmpeq_ss(squared, zero);
        const __m128 estimate = _mm_rsqrt_ss(squared);
        const __m128 refined = _mm_mul_ss(_mm_mul_ss(half, estimate),
                                          _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, estimate), estimate)));
        return _mm_andnot_ps(empty, refined);
    }
    __forceinline void normalize()
    {
        __m128 scale = inverseMagnitude().spread();
        data = _mm_mul_ps(scale, data);
    }
    __forceinline float& component(int i)
    {
        return ((float*)&data)[i];
    }
    __forceinline ScalarValue selected(int i) const
    {
        switch (i)
        {
        case 0:
            return data;
        case 1:
            return _mm_shuffle_ps(data, data, 0x55);
        case 2:
            return _mm_shuffle_ps(data, data, 0xaa);
        default:
            return _mm_shuffle_ps(data, data, 0xff);
        }
    }
    __forceinline void addScaled(const GeomVector& base, const GeomVector& direction, const ScalarValue& scale)
    {
        data = _mm_add_ps(base.data, _mm_mul_ps(scale.spread(), direction.data));
    }
    __forceinline void set(float x, float y, float z, float w)
    {
        data = _mm_setr_ps(x, y, z, w);
    }
    __forceinline ScalarValue sum() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(data, data, 0x55), data);
        return _mm_add_ss(_mm_shuffle_ps(data, data, 0xaa), xy);
    }
    __forceinline void scale(const ScalarValue& x)
    {
        data = _mm_mul_ps(x.spread(), data);
    }
};
static __forceinline GeomVector offsetCross(const GeomVector& origin, const GeomVector& a, const GeomVector& b)
{
    GeomVector first;
    first.difference(a, origin);
    GeomVector second;
    second.difference(b, origin);
    GeomVector result;
    result.cross(first, second);
    return result;
}
static __forceinline GeomVector makePlane(const GeomVector& a, const GeomVector& b, const GeomVector& c,
                                          bool normalized)
{
    GeomVector result = offsetCross(a, b, c);
    if (normalized)
        result.normalize();
    result.component(3) = -result.dot(a);
    return result;
}
static __forceinline float doubleArea(const GeomVector& origin, const GeomVector& a, const GeomVector& b)
{
    return offsetCross(origin, a, b).magnitude();
}
float __cdecl FUN_00de9e10(const GeomVector&, const GeomVector&, const GeomVector&, GeomVector&, float*);

// Computes the squared distance from a point to a triangle, returning the closest normal and optional barycentric weights.
// @fnv 0x00de9f10
float __cdecl FUN_00de9f10(const GeomVector& point, const GeomVector& a, const GeomVector& b, const GeomVector& c,
                           GeomVector& normal, GeomVector* weights)
{
    GeomVector plane = makePlane(a, b, c, true);
    float distance = plane.dot(point) + plane.selected(3);
    GeomVector projected;
    projected.addScaled(point, plane, -distance);
    if (offsetCross(projected, a, b).dot(plane) > 0 && offsetCross(projected, b, c).dot(plane) > 0 &&
        offsetCross(projected, c, a).dot(plane) > 0)
    {
        normal = plane;
        if (weights)
        {
            weights->set(doubleArea(projected, b, c), doubleArea(projected, c, a), doubleArea(projected, a, b), 0);
            ScalarValue sum = weights->sum();
            if (sum > DAT_0104da4c)
                weights->scale(ScalarValue(DAT_01012068) / sum);
            else
                weights->set(DAT_0106c2e0, DAT_0106c2e0, DAT_0106c2e0, 0);
        }
        if (distance < 0)
            normal.scale(DAT_01012054);
        return distance * distance;
    }
    else
    {
        GeomVector normals[3];
        float fractions[3];
        float distances[3];
        distances[0] = FUN_00de9e10(point, a, b, normals[0], &fractions[0]);
        distances[1] = FUN_00de9e10(point, b, c, normals[1], &fractions[1]);
        distances[2] = FUN_00de9e10(point, c, a, normals[2], &fractions[2]);
        int edge =
            distances[0] < distances[1] ? (distances[0] < distances[2] ? 0 : 2) : (distances[1] < distances[2] ? 1 : 2);
        normal = normals[edge];
        if (weights)
        {
            switch (edge)
            {
            case 0:
                weights->set(1 - fractions[0], fractions[0], 0, 0);
                break;
            case 1:
                weights->set(0, 1 - fractions[1], fractions[1], 0);
                break;
            case 2:
                weights->set(fractions[2], 0, 1 - fractions[2], 0);
                break;
            }
        }
        return distances[edge];
    }
}

#include <float.h>
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_div_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_set_ss(float);
    __m128 _mm_setr_ps(float, float, float, float);
    void _mm_store_ss(float*, __m128);
}

struct S00dea980_Vec
{
    __m128 m_vComponents;
};

inline __m128 S00dea980_cross(__m128 a, __m128 b)
{
    __m128 b_yzx = _mm_shuffle_ps(b, b, 0xc9);
    __m128 a_zxy = _mm_shuffle_ps(a, a, 0xd2);
    __m128 a_yzx = _mm_shuffle_ps(a, a, 0xc9);
    __m128 prod1 = _mm_mul_ps(b_yzx, a_zxy);
    __m128 b_zxy = _mm_shuffle_ps(b, b, 0xd2);
    __m128 prod2 = _mm_mul_ps(b_zxy, a_yzx);
    return _mm_sub_ps(prod2, prod1);
}

inline __m128 S00dea980_len2m(__m128 v)
{
    __m128 m = _mm_mul_ps(v, v);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), s);
}

inline __m128 S00dea980_hadd(__m128 v)
{
    __m128 s = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    return _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), s);
}

inline float S00dea980_f(__m128 v)
{
    float s;
    _mm_store_ss(&s, v);
    return s;
}

// @fnv 0x00dea980
float FUN_00dea980(const S00dea980_Vec* apFirst, const S00dea980_Vec* apSecond, const S00dea980_Vec* apThird)
{
    __m128 vFirst = apFirst->m_vComponents;
    __m128 v1 = apSecond->m_vComponents;
    __m128 v2 = apThird->m_vComponents;

    __m128 eSecondFirst = _mm_sub_ps(v1, vFirst);
    __m128 eThirdFirst = _mm_sub_ps(v2, vFirst);

    __m128 cr = S00dea980_cross(eSecondFirst, eThirdFirst);

    float fCrossLength = S00dea980_f(_mm_sqrt_ss(S00dea980_len2m(cr)));
    float fSqrtThree = (float)sqrt(3.0);
    float num = fSqrtThree * (fCrossLength * 2.0f);

    float fLenSqThirdFirst = S00dea980_f(S00dea980_len2m(eThirdFirst));
    float fLenSqSecondThird = S00dea980_f(S00dea980_len2m(_mm_sub_ps(v1, v2)));
    float fLenSqFirstSecond;
    _mm_store_ss(&fLenSqFirstSecond, S00dea980_len2m(_mm_sub_ps(vFirst, v1)));

    __m128 vLengthsSq = _mm_setr_ps(fLenSqFirstSecond, fLenSqSecondThird, fLenSqThirdFirst, 0.0f);
    __m128 vDenominator = S00dea980_hadd(vLengthsSq);

    if (S00dea980_f(vDenominator) > FLT_EPSILON)
    {
        return S00dea980_f(_mm_div_ss(_mm_load_ss(&num), vDenominator));
    }

    return 0.0f;
}

extern float DAT_01016248;
extern __m128 DAT_010ec7f0;
static __forceinline void medianInterpolate(hkVector4& result, const hkVector4& first, const hkVector4& second,
                                            const VectorComponentValue& fraction)
{
    __m128 weight = _mm_shuffle_ps(fraction.m_vValue, fraction.m_vValue, 0);
    __m128 complement = _mm_sub_ps(DAT_010ec7f0, weight);
    result.m_vComponents =
        _mm_add_ps(_mm_mul_ps(complement, first.m_vComponents), _mm_mul_ps(weight, second.m_vComponents));
}
// Interpolates between first and second using a fraction loaded from DAT_01016248.
// @fnv 0x00de9b10
hkVector4 __cdecl FUN_00de9b10(const hkVector4& first, const hkVector4& second)
{
    hkVector4 result;
    medianInterpolate(result, first, second, VectorComponentValue(_mm_load_ss(&DAT_01016248)));
    return result;
}

extern "C" __m128 _mm_load_ps(const float*);

extern const float DAT_0106c2e0;

struct CentroidVector
{
    __m128 value;
};

// @fnv 0x00de9b50
CentroidVector __cdecl FUN_00de9b50(const CentroidVector* apCentroidA, const CentroidVector* apCentroidB,
                                    const CentroidVector* apCentroidC)
{
    __m128 vSum = _mm_load_ps((const float*)&apCentroidA->value);
    __m128 scale = _mm_load_ss(&DAT_0106c2e0);
    __m128 vb = _mm_load_ps((const float*)&apCentroidB->value);

    vSum = _mm_add_ps(vSum, vb);

    __m128 vc = _mm_load_ps((const float*)&apCentroidC->value);
    vSum = _mm_add_ps(vSum, vc);
    vSum = _mm_mul_ps(vSum, _mm_shuffle_ps(scale, scale, 0));

    CentroidVector result;
    result.value = vSum;
    return result;
}
