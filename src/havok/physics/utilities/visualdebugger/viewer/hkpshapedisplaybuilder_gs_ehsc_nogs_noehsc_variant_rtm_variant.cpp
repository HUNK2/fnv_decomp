// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/hkpshapedisplaybuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00ddfcd0_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int nbytes);
};
struct S_00ddfcd0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddfcd0_Allocator* m_pStreamAllocator;
    S_00ddfcd0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00ddfcd0_Router* FUN_00c85750();
struct S_00ddfcd0_RefObj
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S_00ddfcd0_RefObj() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~S_00ddfcd0_RefObj() throw()
    {}
    void* operator new(unsigned int nbytes)
    {
        S_00ddfcd0_RefObj* b = static_cast<S_00ddfcd0_RefObj*>(FUN_00c85750()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    void operator delete(void*)
    {}
};
struct S_00ddfcd0_Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00ddfcd0_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
struct S_00ddfcd0_Obj : S_00ddfcd0_RefObj
{
    S_00ddfcd0_Array m_ppData;
    S_00ddfcd0_Obj() throw()
    {}
    virtual ~S_00ddfcd0_Obj() throw();
};
S_00ddfcd0_RefObj* FUN_00ddfcd0();

#include <xmmintrin.h>
class Scalar
{
    __m128 value;

  public:
    __forceinline Scalar(const __m128& v) : value(v)
    {}
    __forceinline Scalar(float f)
    {
        value = _mm_load_ss(&f);
    }
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, value);
        return f;
    }
    __forceinline const __m128& quad() const
    {
        return value;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
struct Transform;
class Vector
{
    __m128 q;

  public:
    __forceinline Vector()
    {}
    __forceinline Vector(const Vector& v) : q(v.q)
    {}
    __forceinline void operator=(const Vector& v)
    {
        q = v.q;
    }
    __forceinline void operator=(const __m128& v)
    {
        q = v;
    }
    __forceinline operator __m128() const
    {
        return q;
    }
    __forceinline float& operator()(int n)
    {
        return reinterpret_cast<float*>(&q)[n];
    }
    __forceinline const float& operator()(int n) const
    {
        return reinterpret_cast<const float*>(&q)[n];
    }
    __forceinline void setZero4()
    {
        q = _mm_setzero_ps();
    }
    __forceinline void set(float a, float b, float c, float d = 0)
    {
        q = _mm_setr_ps(a, b, c, d);
    }
    __forceinline void setSub4(const Vector& a, const Vector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void setAdd4(const Vector& a, const Vector& b)
    {
        q = _mm_add_ps(a.q, b.q);
    }
    __forceinline void add4(const Vector& b)
    {
        q = _mm_add_ps(q, b.q);
    }
    __forceinline void mul4(const Vector& b)
    {
        q = _mm_mul_ps(q, b.q);
    }
    __forceinline void mul4(const Scalar& x)
    {
        q = _mm_mul_ps(x.broadcast(), q);
    }
    __forceinline int getMajorAxis() const;
    __forceinline Scalar dot3(const Vector& b) const
    {
        __m128 s = _mm_mul_ps(q, b.q);
        __m128 y = _mm_shuffle_ps(s, s, 0x55), z = _mm_shuffle_ps(s, s, 0xaa);
        return _mm_add_ss(z, _mm_add_ss(y, s));
    }
    __forceinline Scalar length3() const
    {
        return _mm_sqrt_ss(dot3(*this).quad());
    }
    void FUN_00c7f640(const Transform&, const Vector&);
    __forceinline void SetTransformedPoint(const Transform& m, const Vector& p)
    {
        FUN_00c7f640(m, p);
    }
    static __forceinline const Vector& getZero();
};
extern Vector DAT_01267e30, DAT_01017d10;
__forceinline int Vector::getMajorAxis() const
{
    Vector v;
    v = _mm_and_ps(q, (__m128)DAT_01017d10);
    return v(0) < v(1) ? (v(1) < v(2) ? 2 : 1) : (v(0) < v(2) ? 2 : 0);
}
__forceinline const Vector& Vector::getZero()
{
    return DAT_01267e30;
}
struct Basis
{
    Vector a, b, c;
    __forceinline Vector& column(int i)
    {
        return (&a)[i];
    }
    __forceinline float& operator()(int r, int c)
    {
        return column(c)(r);
    }
    __forceinline void setZero()
    {
        a.setZero4();
        b.setZero4();
        c.setZero4();
    }
    __forceinline void setIdentity()
    {
        setZero();
        float unit = 1;
        (*this)(0, 0) = unit;
        (*this)(1, 1) = unit;
        (*this)(2, 2) = unit;
    }
};
struct Rotation : Basis
{
};
struct Transform
{
    Rotation rotation;
    Vector translation;
    void FUN_00c6cd60(const Transform&);
    __forceinline Transform& operator=(const Transform& m)
    {
        FUN_00c6cd60(m);
        return *this;
    }
    void FUN_00cb2240(const Transform&, const Transform&);
    __forceinline void SetProduct(const Transform& a, const Transform& b)
    {
        FUN_00cb2240(a, b);
    }
    __forceinline void setIdentity()
    {
        rotation.setIdentity();
        translation.setZero4();
    }
    __forceinline void setTranslation(const Vector& p)
    {
        translation = p;
    }
    static __forceinline const Transform& GetIdentityTransform();
};
extern Transform DAT_01268370;
__forceinline const Transform& Transform::GetIdentityTransform()
{
    return DAT_01268370;
}
class SphereRec
{
    Vector pos;

  public:
    __forceinline SphereRec()
    {}
    __forceinline SphereRec(const Vector& p, float r)
    {
        pos = p;
        pos(3) = r;
    }
    __forceinline const Vector& getPosition() const
    {
        return pos;
    }
};
struct Bounds
{
    Vector m_kMinimumCorner, m_kMaximumCorner;
};
struct ShapeBuffer
{
    __declspec(align(16)) char bytes[512];
};
struct HeapView
{
    virtual void f0();
    virtual void f4();
    virtual void f8();
    virtual void fc();
    virtual void ReleaseBlock(void*, int);
};
void FUN_00c908c0(S_00ddfcd0_Allocator*, void*, int, int);
void FUN_00c90940(S_00ddfcd0_Allocator*, void*, int);
template <class T> __forceinline void copyRange(T* p, int n, const T& v)
{
    for (int i = 0; i < n; ++i)
        p[i] = v;
}
template <class T> class ArrayBase
{
  public:
    T* data;
    int size, capacity;

  public:
    __forceinline ArrayBase() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline ~ArrayBase()
    {}
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
    __forceinline T* begin()
    {
        return data;
    }
    __forceinline const T* begin() const
    {
        return data;
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline void reserve(S_00ddfcd0_Allocator& heap, int n)
    {
        int cap = getCapacity();
        if (cap < n)
        {
            int twice = 2 * cap;
            int next = n < twice ? twice : n;
            FUN_00c908c0(&heap, this, next, sizeof(T));
        }
    }
    __forceinline T* expandBy(S_00ddfcd0_Allocator& heap, int n)
    {
        int old = size;
        reserve(heap, size + n);
        size += n;
        return data + old;
    }
    __forceinline void SetSizeAndGrow(S_00ddfcd0_Allocator& heap, int n)
    {
        reserve(heap, n);
        size = n;
    }
    __forceinline void AddBack(S_00ddfcd0_Allocator& heap, const T& v)
    {
        if (size == (capacity & 0x3fffffff))
            FUN_00c90940(&heap, this, sizeof(T));
        copyRange(data + size, 1, v);
        ++size;
    }
    __forceinline void clear()
    {
        size = 0;
    }
    __forceinline void release(S_00ddfcd0_Allocator& heap)
    {
        size = 0;
        if ((capacity & 0x80000000) == 0)
            ((HeapView*)&heap)->ReleaseBlock(data, (capacity & 0x3fffffff) * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
};
__forceinline void* operator new(unsigned int, void* p)
{
    return p;
}
template <class T> struct Array : ArrayBase<T>
{
    __forceinline Array()
    {}
    __forceinline ~Array()
    {
        release(FUN_00c85750()->heap());
    }
    __forceinline T* expandBy(int n)
    {
        return ArrayBase<T>::expandBy(FUN_00c85750()->heap(), n);
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        ArrayBase<T>::SetSizeAndGrow(FUN_00c85750()->heap(), n);
    }
    __forceinline void AddBack(const T& v)
    {
        ArrayBase<T>::AddBack(FUN_00c85750()->heap(), v);
    }
};
template <class T> struct LocalArray : Array<T>
{
    T* saved;
    __forceinline LocalArray(int n)
    {
        S_00ddfcd0_Router* r = FUN_00c85750();
        T* p = (T*)r->unk0;
        r->unk0 = (int)p + ((n * sizeof(T) + 127) & ~127);
        data = p;
        capacity = n | 0x80000000;
        saved = p;
    }
    __forceinline ~LocalArray()
    {
        T* p = saved;
        if (p == data)
            clear();
        FUN_00c85750()->unk0 = (int)p;
    }
};
struct Mesh
{
    struct Triangle
    {
        int a, b, c, material;
        __forceinline void set(int x, int y, int z, int m = -1)
        {
            a = x;
            b = y;
            c = z;
            material = m;
        }
    };
    Array<Vector> m_kVertices;
    Array<Triangle> m_uiTriangleCount;
    __forceinline void* operator new(unsigned int n)
    {
        return FUN_00c85750()->heap().AllocateMemoryBlock(n);
    }
};
struct FUN_00cce5e0 : Mesh
{
    FUN_00cce5e0();
};
struct Strided
{
    const float* data;
    int count, stride;
    __forceinline Strided(const ArrayBase<Vector>& a)
        : data((const float*)a.begin()), count(a.GetLogicalSize()), stride(sizeof(Vector))
    {}
};
struct MeshUtility
{
    static __forceinline void ConvertStridedToMesh(const Strided& s, Mesh& m);
};
void FUN_00d5a5e0(const Strided&, Mesh&);
__forceinline void MeshUtility::ConvertStridedToMesh(const Strided& s, Mesh& m)
{
    FUN_00d5a5e0(s, m);
}
struct RefObject
{
    virtual ~RefObject()
    {}
    unsigned short GetAllocationSize, refs;
    __forceinline void* operator new(unsigned int n)
    {
        RefObject* p = (RefObject*)FUN_00c85750()->heap().AllocateMemoryBlock(n);
        p->GetAllocationSize = (unsigned short)n;
        return p;
    }
};
struct Display : RefObject
{
    Mesh* geometry;
    Transform transform;
    int displayType;
    __forceinline Mesh* getGeometry()
    {
        return geometry;
    }
    __forceinline Transform& getTransform()
    {
        return transform;
    }
};
struct FUN_00e0af50 : Display
{
    SphereRec sphere;
    int sides, rings;
    FUN_00e0af50(const SphereRec&, int, int);
};
struct FUN_00d22dc0 : Display
{
    Vector top, bottom;
    float radius;
    int sides, segments;
    FUN_00d22dc0(const Vector&, const Vector&, float, int, int);
};
struct FUN_00d58510 : Display
{
    Vector top, bottom;
    float radius;
    int sides, segments;
    FUN_00d58510(const Vector&, const Vector&, float, int, int);
};
struct FUN_00de1f50 : Display
{
    Vector half;
    FUN_00de1f50(const Vector&);
};
struct FUN_00de4f20 : Display
{
    Vector normal, center, perp, extent;
    FUN_00de4f20(const Vector&, const Vector&, const Vector&, const Vector&);
};
struct FUN_00de1d20 : Display
{
    FUN_00de1d20(Mesh*);
};
struct BaseShape;
struct Container
{
    virtual void f0();
    virtual void f4();
    virtual unsigned int GetFirstKey() const;
    virtual unsigned int GetNextShapeKey(unsigned int) const;
    virtual void f10();
    virtual const BaseShape* GetShapeForKey(unsigned int, ShapeBuffer&) const;
    int unk04;
};
struct Bool
{
    char value;
    __forceinline operator bool() const
    {
        return value != 0;
    }
};
struct BaseShape
{
    virtual void f0();
    virtual void f4();
    virtual void f8();
    virtual void fc();
    virtual const Container* GetShapeContainer() const;
    virtual void f14();
    virtual void f18();
    virtual void getAabb(const Transform&, float, Bounds&) const;
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual int getNumCollisionSpheres() const;
    virtual const SphereRec* getCollisionSpheres(SphereRec*) const;
    virtual float GetHeightAtGridPoint(int, int) const;
    virtual Bool IsTriangleWindingFlipped() const;
    int unk04, unk08, type;
    __forceinline int getType() const
    {
        return type;
    }
};
struct Convex : BaseShape
{
    float radius;
    __forceinline float getRadius() const
    {
        return radius;
    }
};
struct BallShape : Convex
{
};
struct MultiBallShape : BaseShape
{
    int count;
    Vector points[8];
    __forceinline const Vector* getSpheres() const
    {
        return points;
    }
    __forceinline int getNumSpheres() const
    {
        return count;
    }
};
struct PlaneShape : BaseShape
{
    Vector plane;
    __forceinline const Vector& getPlane() const
    {
        return plane;
    }
};
struct CapsuleShape : Convex
{
    Vector endpoints[2];
    __forceinline const Vector& getVertex(int i) const
    {
        return endpoints[i];
    }
};
struct CylinderShape : Convex
{
    Vector endpoints[2];
    __forceinline const Vector& getVertex(int i) const
    {
        return endpoints[i];
    }
    float FUN_00d571a0() const;
    __forceinline float GetCylinderRadius() const
    {
        return FUN_00d571a0();
    }
};
struct RayShape : BaseShape
{
    struct Ray
    {
        Vector m_kRayStart, m_kRayEnd;
    };
    Array<Ray> rays;
    float penetration;
    __forceinline const Array<Ray>& getRays() const
    {
        return rays;
    }
};
struct CenteredPointBounds : Convex
{
    Vector half;
    __forceinline const Vector& getHalfExtents() const
    {
        return half;
    }
};
struct TranslateShape : Convex
{
    int unk14;
    const BaseShape* child;
    int unk1c;
    Vector translation;
    __forceinline const Vector& getTranslation() const
    {
        return translation;
    }
    __forceinline const BaseShape* GetShapeForKey() const
    {
        return child;
    }
};
struct ConvexTransformShape : Convex
{
    int unk14;
    const BaseShape* child;
    int unk1c;
    Transform transform;
    __forceinline const Transform& getTransform() const
    {
        return transform;
    }
    __forceinline const BaseShape* GetShapeForKey() const
    {
        return child;
    }
};
struct TransformShape : BaseShape
{
    int unk10;
    const BaseShape* child;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    Transform transform;
    __forceinline const Transform& getTransform() const
    {
        return transform;
    }
    __forceinline const BaseShape* GetShapeForKey() const
    {
        return child;
    }
};
struct BoundingShape : BaseShape
{
    const BaseShape* child;
    __forceinline const BaseShape* getBoundingVolumeShape() const
    {
        return child;
    }
};
struct ChildInfo
{
    const BaseShape* shape;
    int unk04, unk08, unk0c;
};
struct ListShape : BaseShape, Container
{
    Array<ChildInfo> entries;
    __forceinline const BaseShape* getChildShapeInl(int i) const
    {
        return entries[i].shape;
    }
};
struct TriangleShape : Convex
{
    Vector vertices[3], extrusion;
    __forceinline const Vector& getVertex(int i) const
    {
        return vertices[i];
    }
    __forceinline const Vector& getExtrusion() const
    {
        return extrusion;
    }
};
struct ConvexVerticesShape : Convex
{
};
struct CollectionShape : BaseShape, Container
{
};
struct PieceShape : Convex
{
    Vector* vertices;
    int vertexCount;
    int unk1c;
    const CollectionShape* m_pDisplayMesh;
    const unsigned int* m_pIndexData;
    int m_iIndexCount;
};
struct HeightShape : BaseShape
{
    int m_iXResolution, m_iZResolution, unk18, unk1c;
    Vector m_kHeightScaleVector;
    __forceinline float getHeightAt(int a, int b) const
    {
        return GetHeightAtGridPoint(a, b);
    }
    __forceinline Bool getTriangleFlip() const
    {
        return IsTriangleWindingFlipped();
    }
};
struct Node
{
    int unk00, unk04;
    struct Env
    {
        int m_iFirstValue, m_iSecondValue;
    } m_kEnvironment;
    Display* current;
    Display* FUN_00ddfc30(Array<Display*>&);
    __forceinline Display* GetCurrentDisplay(Array<Display*>& a)
    {
        return FUN_00ddfc30(a);
    }
    void FUN_00ddfd10(const BaseShape*, const Transform&, Array<Display*>&);
};
struct UserBuilders
{
    int unk00, unk04;
    struct Entry
    {
        void(__cdecl* f)(const BaseShape*, const Transform&, Array<Display*>&, Node*);
        int type;
    };
    Array<Entry> m_kBuilderEntries;
    static __forceinline UserBuilders& GetMonitorStream();
};
extern UserBuilders* DAT_01269ce0;
__forceinline UserBuilders& UserBuilders::GetMonitorStream()
{
    return *DAT_01269ce0;
}

// @fnv 0x00ddfd10
void Node::FUN_00ddfd10(const BaseShape* shape, const Transform& mat, Array<Display*>& out)
{
    switch (shape->getType())
    {
    case 1: {
        const BallShape* s = static_cast<const BallShape*>(shape);
        Vector zero;
        zero.setZero4();
        SphereRec sphere(zero, s->getRadius());
        FUN_00e0af50* g = new FUN_00e0af50(sphere, m_kEnvironment.m_iSecondValue, m_kEnvironment.m_iFirstValue);
        g->getTransform() = mat;
        out.AddBack(g);
        break;
    }
    case 21: {
        const MultiBallShape* s = static_cast<const MultiBallShape*>(shape);
        const Vector* points = s->getSpheres();
        for (int i = 0; i < s->getNumSpheres(); ++i)
        {
            SphereRec sphere(Vector::getZero(), points[i](3));
            FUN_00e0af50* g = new FUN_00e0af50(sphere, m_kEnvironment.m_iSecondValue, m_kEnvironment.m_iFirstValue);
            g->getTransform().setIdentity();
            g->getTransform().setTranslation(points[i]);
            out.AddBack(g);
        }
        break;
    }
    case 28: {
        const PlaneShape* s = static_cast<const PlaneShape*>(shape);
        const Vector& plane = s->getPlane();
        Bounds bounds;
        s->getAabb(Transform::GetIdentityTransform(), 0.001f, bounds);
        Vector ext;
        ext.setSub4(bounds.m_kMaximumCorner, bounds.m_kMinimumCorner);
        Vector axis;
        axis.setZero4();
        axis(ext.getMajorAxis()) = 1;
        ext.mul4(0.5f);
        Vector center(ext);
        center.add4(bounds.m_kMinimumCorner);
        FUN_00de4f20* g = new FUN_00de4f20(plane, axis, center, ext);
        g->getTransform() = mat;
        out.AddBack(g);
        break;
    }
    case 5: {
        const CapsuleShape* s = static_cast<const CapsuleShape*>(shape);
        FUN_00d22dc0* g = new FUN_00d22dc0(s->getVertex(1), s->getVertex(0), s->getRadius(), 6, 1);
        g->getTransform() = mat;
        out.AddBack(g);
        break;
    }
    case 2: {
        const CylinderShape* s = static_cast<const CylinderShape*>(shape);
        Vector a;
        a.SetTransformedPoint(mat, s->getVertex(1));
        Vector b;
        b.SetTransformedPoint(mat, s->getVertex(0));
        FUN_00d58510* g = new FUN_00d58510(a, b, s->FUN_00d571a0(), 9, 1);
        g->getTransform() = mat;
        out.AddBack(g);
        break;
    }
    case 24: {
        const RayShape* s = static_cast<const RayShape*>(shape);
        Display* display = GetCurrentDisplay(out);
        Mesh* mesh = display->getGeometry();
        int base = 0;
        for (int i = 0; i < s->getRays().GetLogicalSize(); ++i)
        {
            RayShape::Ray ray = s->getRays()[i];
            Vector* a = mesh->m_kVertices.expandBy(1);
            *a = ray.m_kRayStart;
            a->SetTransformedPoint(mat, *a);
            Vector* b = mesh->m_kVertices.expandBy(1);
            *b = ray.m_kRayStart;
            Vector offset;
            offset.set(0.01f, 0, 0, 0);
            b->add4(offset);
            Vector* c = mesh->m_kVertices.expandBy(1);
            *c = ray.m_kRayEnd;
            c->SetTransformedPoint(mat, *c);
            Mesh::Triangle* t = mesh->m_uiTriangleCount.expandBy(1);
            t->set(base, base + 1, base + 2);
            base += 3;
        }
        break;
    }
    case 4: {
        const CenteredPointBounds* s = static_cast<const CenteredPointBounds*>(shape);
        FUN_00de1f50* g = new FUN_00de1f50(s->getHalfExtents());
        g->getTransform() = mat;
        out.AddBack(g);
        break;
    }
    case 11: {
        const TranslateShape* s = static_cast<const TranslateShape*>(shape);
        Transform local;
        local.setIdentity();
        local.setTranslation(s->getTranslation());
        Transform result;
        result.SetProduct(mat, local);
        FUN_00ddfd10(s->GetShapeForKey(), result, out);
        break;
    }
    case 12: {
        const ConvexTransformShape* s = static_cast<const ConvexTransformShape*>(shape);
        Transform result;
        result.SetProduct(mat, s->getTransform());
        FUN_00ddfd10(s->GetShapeForKey(), result, out);
        break;
    }
    case 15: {
        const TransformShape* s = static_cast<const TransformShape*>(shape);
        Transform result;
        result.SetProduct(mat, s->getTransform());
        FUN_00ddfd10(s->GetShapeForKey(), result, out);
        break;
    }
    case 27:
        FUN_00ddfd10(static_cast<const BoundingShape*>(shape)->getBoundingVolumeShape(), mat, out);
        break;
    case 8:
    case 10: {
        const Container* c = shape->GetShapeContainer();
        ShapeBuffer buffer;
        for (unsigned int key = c->GetFirstKey(); key != 0xffffffff; key = c->GetNextShapeKey(key))
        {
            const BaseShape* child = c->GetShapeForKey(key, buffer);
            FUN_00ddfd10(child, mat, out);
        }
        break;
    }
    case 9: {
        const ListShape* s = static_cast<const ListShape*>(shape);
        for (unsigned int key = s->GetFirstKey(); key != 0xffffffff; key = s->GetNextShapeKey(key))
        {
            const BaseShape* child = s->getChildShapeInl(key);
            FUN_00ddfd10(child, mat, out);
        }
        break;
    }
    case 7:
    case 14:
    case 16:
    case 22:
    case 23: {
        const Container* c = shape->GetShapeContainer();
        ShapeBuffer buffer;
        for (unsigned int key = c->GetFirstKey(); key != 0xffffffff; key = c->GetNextShapeKey(key))
        {
            const BaseShape* child = c->GetShapeForKey(key, buffer);
            FUN_00ddfd10(child, mat, out);
        }
        break;
    }
    case 3: {
        const TriangleShape* s = static_cast<const TriangleShape*>(shape);
        Mesh* mesh = GetCurrentDisplay(out)->getGeometry();
        int base = mesh->m_kVertices.GetLogicalSize();
        Vector* v = mesh->m_kVertices.expandBy(3);
        v[0].SetTransformedPoint(mat, s->getVertex(0));
        v[1].SetTransformedPoint(mat, s->getVertex(1));
        v[2].SetTransformedPoint(mat, s->getVertex(2));
        Mesh::Triangle* t = mesh->m_uiTriangleCount.expandBy(1);
        t->set(base, base + 1, base + 2);
        if (s->getExtrusion().length3() > 0)
        {
            Vector a;
            a.setAdd4(s->getVertex(0), s->getExtrusion());
            Vector b;
            b.setAdd4(s->getVertex(1), s->getExtrusion());
            Vector c;
            c.setAdd4(s->getVertex(2), s->getExtrusion());
            Vector* e = mesh->m_kVertices.expandBy(3);
            e[0].SetTransformedPoint(mat, a);
            e[1].SetTransformedPoint(mat, b);
            e[2].SetTransformedPoint(mat, c);
            Mesh::Triangle* et = mesh->m_uiTriangleCount.expandBy(7);
            et[0].set(base + 3, base + 1, base);
            et[1].set(base + 3, base + 4, base + 1);
            et[2].set(base + 4, base + 5, base + 1);
            et[3].set(base + 5, base + 2, base + 1);
            et[4].set(base + 5, base, base + 2);
            et[5].set(base + 5, base + 3, base);
            et[6].set(base + 5, base + 4, base + 3);
        }
        break;
    }
    case 6: {
        const ConvexVerticesShape* s = static_cast<const ConvexVerticesShape*>(shape);
        int count = s->getNumCollisionSpheres();
        LocalArray<SphereRec> points(count);
        points.SetSizeAndGrow(count);
        const SphereRec* p = s->getCollisionSpheres(points.begin());
        Array<Vector> transformed;
        transformed.SetSizeAndGrow(count);
        for (int i = 0; i < count; ++i)
            transformed.data[i].SetTransformedPoint(mat, p[i].getPosition());
        Mesh* mesh = new Mesh;
        MeshUtility::ConvertStridedToMesh(transformed, *mesh);
        FUN_00de1d20* g = new FUN_00de1d20(mesh);
        out.AddBack(g);
        break;
    }
    case 20: {
        const PieceShape* s = static_cast<const PieceShape*>(shape);
        Mesh* mesh = new FUN_00cce5e0;
        ShapeBuffer buffer;
        for (int i = 0; i < s->m_iIndexCount; ++i)
        {
            const TriangleShape* child =
                static_cast<const TriangleShape*>(s->m_pDisplayMesh->GetShapeForKey(s->m_pIndexData[i], buffer));
            Mesh::Triangle* t = mesh->m_uiTriangleCount.expandBy(1);
            int base = mesh->m_kVertices.GetLogicalSize();
            t->set(base, base + 1, base + 2);
            for (int j = 0; j < 3; ++j)
            {
                Vector* v = mesh->m_kVertices.expandBy(1);
                v->SetTransformedPoint(mat, child->getVertex(j));
            }
        }
        FUN_00de1d20* g = new FUN_00de1d20(mesh);
        out.AddBack(g);
        break;
    }
    case 13: {
        const HeightShape* s = static_cast<const HeightShape*>(shape);
        Mesh* mesh = GetCurrentDisplay(out)->getGeometry();
        Vector scale = s->m_kHeightScaleVector;
        for (int i = 0; i < s->m_iXResolution - 1; ++i)
            for (int j = 0; j < s->m_iZResolution - 1; ++j)
            {
                Vector a;
                a.set((float)(float)i + 0.0, s->getHeightAt(i, j), (float)(float)j + 0.0);
                a.mul4(scale);
                Vector b;
                b.set((float)(float)i + 0.0, s->getHeightAt(i, j + 1), (float)(float)j + 1.0);
                b.mul4(scale);
                Vector c;
                c.set((float)(float)i + 1.0, s->getHeightAt(i + 1, j), (float)(float)j + 0.0);
                c.mul4(scale);
                Vector d;
                d.set((float)(float)i + 1.0, s->getHeightAt(i + 1, j + 1), (float)(float)j + 1.0);
                d.mul4(scale);
                int base = mesh->m_kVertices.GetLogicalSize();
                Vector* v = mesh->m_kVertices.expandBy(4);
                v[0].SetTransformedPoint(mat, a);
                v[1].SetTransformedPoint(mat, b);
                v[2].SetTransformedPoint(mat, c);
                v[3].SetTransformedPoint(mat, d);
                if (s->getTriangleFlip())
                {
                    Mesh::Triangle* t = mesh->m_uiTriangleCount.expandBy(2);
                    t[0].set(base, base + 1, base + 3);
                    t[1].set(base, base + 3, base + 2);
                }
                else
                {
                    Mesh::Triangle* t = mesh->m_uiTriangleCount.expandBy(2);
                    t[0].set(base, base + 1, base + 2);
                    t[1].set(base + 3, base + 2, base + 1);
                }
            }
        break;
    }
    default:
        for (int i = 0; i < UserBuilders::GetMonitorStream().m_kBuilderEntries.GetLogicalSize(); ++i)
            if (UserBuilders::GetMonitorStream().m_kBuilderEntries[i].type == shape->getType())
                UserBuilders::GetMonitorStream().m_kBuilderEntries[i].f(shape, mat, out, this);
        break;
    }
}
