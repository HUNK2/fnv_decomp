// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>
struct D31Arr
{
    void* data;                     // +0x00
    int count;                      // +0x04
    unsigned int capacityAndFlags;  // +0x08
};
struct D31Pair
{
    void* base;  // +0x00
    int count;   // +0x04
};
struct D31Item
{
    float x, y, z, w;
};
struct D31VtIface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(void* buf, int size);  // vtable +0x10
};
struct D31Tbl2
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    D31VtIface* sub;  // +0x10
};
struct D31Mgr
{
    D31Pair* FUN_00d58d50();         // __thiscall
    void FUN_00d59200(D31Arr* out);  // __thiscall, 1 stack arg
};
struct D31Tbl
{
    void* t;
};
__declspec(align(16)) D31Tbl tbl_0101b330;
D31Tbl2* __cdecl FUN_00c85750();
extern float DAT_0101b31c;
static float FUN_00de3110(int dummy, D31Mgr* mgr);
float __cdecl S00de3110_Entry();

#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier();
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
struct Shape;
struct Transform;
struct ShapeBuffer
{
    __m128 storage000;
    __m128 storage010;
    __m128 storage020;
    __m128 storage030;
    __m128 storage040;
    __m128 storage050;
    __m128 storage060;
    __m128 storage070;
    __m128 storage080;
    __m128 storage090;
    __m128 storage0a0;
    __m128 storage0b0;
    __m128 storage0c0;
    __m128 storage0d0;
    __m128 storage0e0;
    __m128 storage0f0;
    __m128 storage100;
    __m128 storage110;
    __m128 storage120;
    __m128 storage130;
    __m128 storage140;
    __m128 storage150;
    __m128 storage160;
    __m128 storage170;
    __m128 storage180;
    __m128 storage190;
    __m128 storage1a0;
    __m128 storage1b0;
    __m128 storage1c0;
    __m128 storage1d0;
    __m128 storage1e0;
    __m128 storage1f0;
};
struct Collection
{
    virtual void slot0();
    virtual void slot1();
    virtual int first();
    virtual int next(int key);
    virtual void slot4();
    virtual Shape* child(int key, ShapeBuffer& buffer);
};
struct ShapeVTable
{
    void(__thiscall* slot0)(Shape*);
    void(__thiscall* slot1)(Shape*);
    void(__thiscall* slot2)(Shape*);
    void(__thiscall* slot3)(Shape*);
    Collection*(__thiscall* getCollection)(Shape*);
    void(__thiscall* slot5)(Shape*);
    void(__thiscall* slot6)(Shape*);
    void(__thiscall* getBounds)(Shape*, const Transform*, float, struct Bounds*);
};
struct Shape
{
    ShapeVTable* vtable;
    Collection* collection()
    {
        return vtable->getCollection(this);
    }
    unsigned short memorySize;
    unsigned short references;
    int userData;
    int kind;
    union
    {
        float radius;
        Shape* child10;
    };
    Shape* child14;
    Shape* child18;
    int shape1c;
    __m128 point20;
    __m128 point30;
    __m128 point40;
    float FUN_00d571a0();
    struct PlaneArray* FUN_00d58d50();
    void FUN_00d59200(struct PlaneArray*);
};
struct Transform
{
    __m128 rotation0, rotation1, rotation2, translation;
    void FUN_00cb2240(const Transform*, const Transform*);
    void FUN_00c6cd60(const Transform*);
};
struct VectorResult
{
    __m128 value;
    __declspec(noalias) void FUN_00c7f640(const Transform*, const __m128*);
};
__declspec(noinline) void VectorResult::FUN_00c7f640(const Transform* transform, const __m128* point)
{
    __m128 p = *point;
    value =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p, p, 0x55), transform->rotation1),
                              _mm_mul_ps(_mm_shuffle_ps(p, p, 0), transform->rotation0)),
                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p, p, 0xaa), transform->rotation2), transform->translation));
}
struct Allocator
{
    virtual void slot0();
    virtual void* allocate(int bytes);
    virtual void slot2();
    virtual void* allocateChunk(int& bytes);
    virtual void freeChunk(void*, int);
};
extern void FUN_00c90940(void*, void*, int);
extern void FUN_00c908c0(void*, void*, int, int);
struct OutputShape
{
    int field00;
    unsigned short memorySize, references;
    int field08, field0c;
    Transform transform;
    __declspec(noalias) OutputShape* FUN_00d58510(const __m128*, const __m128*, float, int, int);
    __declspec(noalias) OutputShape* FUN_00de1f50(const __m128*);
};
struct OutputArray
{
    OutputShape** data;
    int size;
    unsigned capacity;
    __forceinline void append(OutputShape* shape)
    {
        D31Tbl2* holder = FUN_00c85750();
        if (size == (capacity & 0x3fffffff))
            FUN_00c90940(reinterpret_cast<Allocator*>(holder->sub), this, 4);
        OutputShape** slot = data + size;
        for (int i = 0; i < 1; ++i)
            slot[i] = shape;
        ++size;
    }
};
struct PlaneVector
{
    union
    {
        __m128 quad;
        float m128_f32[4];
    };
    __forceinline operator const __m128&() const
    {
        return quad;
    }
    __forceinline void operator=(const __m128& value)
    {
        quad = value;
    }
    __forceinline void operator=(const PlaneVector& value)
    {
        quad = value.quad;
    }
    __forceinline void setCross(const __m128& a, const __m128& b)
    {
        quad = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
    }
};
struct PlaneArray
{
    PlaneVector* data;
    int size;
    int capacity;
    __forceinline __m128& operator[](int index)
    {
        return data[index].quad;
    }
    __forceinline void reserve(int count)
    {
        D31Tbl2* holder = FUN_00c85750();
        Allocator* a = reinterpret_cast<Allocator*>(holder->sub);
        int old = capacity & 0x3fffffff;
        if (old < count)
        {
            int wanted = 2 * old;
            if (wanted <= count)
                wanted = count;
            FUN_00c908c0(a, this, wanted, 16);
        }
    }
    __forceinline void release()
    {
        D31Tbl2* holder = FUN_00c85750();
        Allocator* a = reinterpret_cast<Allocator*>(holder->sub);
        size = 0;
        if (!(unsigned(capacity) & 0x80000000))
            a->freeChunk(data, (capacity & 0x3fffffff) * 16);
    }
};
static __forceinline PlaneVector* allocatePlaneItems(Allocator& a, int& count)
{
    int bytes = count * 16;
    PlaneVector* p = static_cast<PlaneVector*>(a.allocateChunk(bytes));
    count = bytes / 16;
    return p;
}
struct CallbackEntry
{
    void(__cdecl* callback)(Shape*, const Transform*, OutputArray*, void*);
    int kind;
};
struct CallbackList
{
    int field00, field04;
    CallbackEntry* data;
    int size;
};
extern CallbackList* DAT_01269ce4;
extern bool* FUN_00ceb8d0(bool*, const __m128*, const __m128*, const __m128*, float);
extern const float DAT_01017718;
extern const float DAT_01011d78;
extern float DAT_010c7160;
extern float DAT_010c44d0;
extern const float DAT_01016248;
extern const double DAT_01023b88;
extern float DAT_01017d00;
static __forceinline __m128 dot3(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 q = _mm_shuffle_ps(p, p, 0x55);
    q = _mm_add_ss(q, p);
    p = _mm_shuffle_ps(p, p, 0xaa);
    return _mm_add_ss(p, q);
}
static __forceinline __m128 normalizedUsing(__m128 v, const __m128& zero, const __m128& three, const __m128& half)
{
    __m128 n = dot3(v, v);
    __m128 root = _mm_rsqrt_ss(n);
    __m128 mask = _mm_cmpeq_ss(n, zero);
    n = _mm_mul_ss(_mm_mul_ss(n, root), root);
    __m128 k = _mm_mul_ss(_mm_mul_ss(half, root), _mm_sub_ss(three, n));
    k = _mm_andnot_ps(mask, k);
    return _mm_mul_ps(_mm_shuffle_ps(k, k, 0), v);
}
static __forceinline __m128 normalized(__m128 v)
{
    __m128 n = dot3(v, v);
    __m128 root = _mm_rsqrt_ss(n);
    __m128 zero = _mm_set_ss(DAT_01011d78);
    __m128 three = _mm_set_ss(DAT_01017718);
    __m128 half = _mm_set_ss(DAT_01016248);
    __m128 mask = _mm_cmpeq_ss(n, zero);
    n = _mm_mul_ss(_mm_mul_ss(n, root), root);
    __m128 k = _mm_mul_ss(_mm_mul_ss(half, root), _mm_sub_ss(three, n));
    k = _mm_andnot_ps(mask, k);
    return _mm_mul_ps(_mm_shuffle_ps(k, k, 0), v);
}
static __forceinline __m128 normalizedInit(__m128 v, __m128& zero, __m128& three, __m128& half)
{
    __m128 n = dot3(v, v);
    __m128 root = _mm_rsqrt_ss(n);
    zero = _mm_set_ss(DAT_01011d78);
    three = _mm_set_ss(DAT_01017718);
    half = _mm_set_ss(DAT_01016248);
    __m128 mask = _mm_cmpeq_ss(n, zero);
    n = _mm_mul_ss(_mm_mul_ss(n, root), root);
    __m128 k = _mm_mul_ss(_mm_mul_ss(half, root), _mm_sub_ss(three, n));
    k = _mm_andnot_ps(mask, k);
    return _mm_mul_ps(_mm_shuffle_ps(k, k, 0), v);
}
struct EdgeSwizzles
{
    __m128 c9, d2;
};
static __forceinline __m128 cross3(__m128 a, __m128 b)
{
    EdgeSwizzles y;
    y.c9 = _mm_shuffle_ps(b, b, 0xc9);
    y.d2 = _mm_shuffle_ps(b, b, 0xd2);
    EdgeSwizzles x;
    x.d2 = _mm_shuffle_ps(a, a, 0xd2);
    x.c9 = _mm_shuffle_ps(a, a, 0xc9);
    return _mm_sub_ps(_mm_mul_ps(x.c9, y.d2), _mm_mul_ps(x.d2, y.c9));
}
static __forceinline float getReal(const __m128& value)
{
    float scalar;
    _mm_store_ss(&scalar, value);
    return scalar;
}
static __forceinline void planeDistance(PlaneArray& planes, int index, __m128 p, const float& radius)
{
    PlaneVector* plane = planes.data + index;
    const __m128& normal = *plane;
    __m128 scalar = _mm_load_ss(&radius);
    __m128 r = _mm_shuffle_ps(scalar, scalar, 0);
    __m128 point = _mm_add_ps(_mm_mul_ps(r, normal), p);
    planes.data[index].m128_f32[3] =
        getReal(_mm_sub_ss(*reinterpret_cast<const __m128*>(&DAT_010c7160), dot3(point, normal)));
}
struct Bounds
{
    __m128 minimum, maximum;
};
extern const Transform DAT_01268370;

static __declspec(noinline) float FUN_00de3110(Shape* shape)
{
    PlaneArray* source = shape->FUN_00d58d50();
    PlaneArray vertices;
    vertices.data = 0;
    vertices.size = 0;
    vertices.capacity = 0x80000000;
    shape->FUN_00d59200(&vertices);
    float maximum = DAT_0101b31c;
    int count = source->size;
    for (int v = 0; v < vertices.size; ++v)
    {
        __m128 point = vertices.data[v];
        for (int p = 0; p < count; ++p)
        {
            float distance = source->data[p].m128_f32[3] + _mm_cvtss_f32(dot3(source->data[p], point));
            if (distance > maximum)
                maximum = distance;
        }
    }
    vertices.release();
    return maximum;
}
static __declspec(noinline) void FUN_00de3200(Shape* shape, PlaneArray* planes, float radius)
{
    Bounds bounds;
    shape->vtable->getBounds(shape, &DAT_01268370, radius, &bounds);
    planes->reserve(planes->size + 6);
    int start = planes->size;
    planes->size += 6;
    planes->data[start] = _mm_setr_ps(1.0f, 0.0f, 0.0f, -bounds.maximum.m128_f32[0]);
    planes->data[start + 1] = _mm_setr_ps(0.0f, 1.0f, 0.0f, -bounds.maximum.m128_f32[1]);
    planes->data[start + 2] = _mm_setr_ps(0.0f, 0.0f, 1.0f, -bounds.maximum.m128_f32[2]);
    planes->data[start + 3] = _mm_setr_ps(-1.0f, 0.0f, 0.0f, bounds.minimum.m128_f32[0]);
    planes->data[start + 4] = _mm_setr_ps(0.0f, -1.0f, 0.0f, bounds.minimum.m128_f32[1]);
    planes->data[start + 5] = _mm_setr_ps(0.0f, 0.0f, -1.0f, bounds.minimum.m128_f32[2]);
}
struct StridedVertices
{
    PlaneVector* data;
    int size, stride;
};
struct Geometry
{
    PlaneArray vertices, triangles;
};
extern void FUN_00d5a6a0(const PlaneArray*, PlaneArray*);
extern void FUN_00d5a5e0(const StridedVertices*, Geometry*);
struct ConvexOutput
{
    int field00;
    unsigned short memorySize, references;
    OutputShape* FUN_00de1d20(Geometry*);
};
static __declspec(noinline) OutputShape* FUN_00de3360(PlaneArray* planes, const Transform* transform)
{
    PlaneArray vertices;
    vertices.data = 0;
    vertices.size = 0;
    vertices.capacity = 0x80000000;
    FUN_00d5a6a0(planes, &vertices);
    int count = vertices.size;
    if (count < 1)
    {
        vertices.release();
        return 0;
    }
    PlaneArray transformed;
    transformed.data = 0;
    transformed.size = 0;
    transformed.capacity = 0x80000000;
    transformed.reserve(count);
    transformed.size = count;
    for (int i = 0; i < count; ++i)
        reinterpret_cast<VectorResult*>(&transformed.data[i])->FUN_00c7f640(transform, &vertices.data[i].quad);
    Geometry* geometry = static_cast<Geometry*>(reinterpret_cast<Allocator*>(FUN_00c85750()->sub)->allocate(0x18));
    if (geometry)
    {
        geometry->vertices.data = 0;
        geometry->vertices.size = 0;
        geometry->vertices.capacity = 0x80000000;
        geometry->triangles.data = 0;
        geometry->triangles.size = 0;
        geometry->triangles.capacity = 0x80000000;
    }
    StridedVertices view;
    view.data = transformed.data;
    view.size = transformed.size;
    view.stride = 16;
    FUN_00d5a5e0(&view, geometry);
    ConvexOutput* allocation =
        static_cast<ConvexOutput*>(reinterpret_cast<Allocator*>(FUN_00c85750()->sub)->allocate(0x60));
    allocation->memorySize = 0x60;
    OutputShape* result = allocation->FUN_00de1d20(geometry);
    transformed.release();
    vertices.release();
    return result;
}
struct Processor
{
    int field00, field04;
    float threshold;
    void FUN_00de3520(Shape*, const Transform*, OutputArray*);
};
// @fnv 0x00de3520
void Processor::FUN_00de3520(Shape* shape, const Transform* transform, OutputArray* output)
{
    Transform combined;
    ShapeBuffer buffer;

    switch (shape->kind)
    {
    case 1:
    case 5:
    case 13:
    case 21:
    case 24:
    case 28:
        return;
    case 11: {
        Transform local;
        local.rotation0 = _mm_setzero_ps();
        local.rotation0.m128_f32[0] = 1.0f;
        local.rotation1 = _mm_setzero_ps();
        local.rotation1.m128_f32[1] = 1.0f;
        local.rotation2 = _mm_setzero_ps();
        local.rotation2.m128_f32[2] = 1.0f;
        local.translation = shape->point20;
        combined.FUN_00cb2240(transform, &local);
        FUN_00de3520(shape->child18, &combined, output);
        return;
    }
    case 12:
        combined.FUN_00cb2240(transform, reinterpret_cast<Transform*>(&shape->point20));
        FUN_00de3520(shape->child18, &combined, output);
        return;
    case 15:
        combined.FUN_00cb2240(transform, reinterpret_cast<Transform*>(&shape->point30));
        FUN_00de3520(shape->child14, &combined, output);
        return;
    case 27:
        FUN_00de3520(shape->child10, transform, output);
        return;
    case 8:
    case 10: {
        Collection* collection = shape->collection();
        for (int key = collection->first(); key != -1; key = collection->next(key))
        {
            Shape* child = collection->child(key, buffer);
            FUN_00de3520(child, transform, output);
        }
        return;
    }
    case 7:
    case 9:
    case 22:
    case 23: {
        Collection* collection = shape->collection();
        int key = collection->first();
    top:
        if (!collection || key == -1)
            goto commonExit;
        Shape* child = collection->child(key, buffer);
        FUN_00de3520(child, transform, output);
        key = collection->next(key);
        goto top;
    }
    case 20: {
        if (!(shape->radius > threshold))
            return;
        // The selected collection is embedded at offset 0x10 of its owner.
        struct CollectionOwner
        {
            int field00, field04, field08, field0c;
            Collection collection;
        };
        struct SelectionHeader
        {
            CollectionOwner* owner;
            int* keys;
            int count;
        };
        SelectionHeader* selection = reinterpret_cast<SelectionHeader*>(&shape->point20);
        for (int i = 0; i < selection->count; ++i)
        {
            Shape* child = selection->owner->collection.child(selection->keys[i], buffer);
            FUN_00de3520(child, transform, output);
        }
        return;
    }
    case 2: {
        float additional = shape->FUN_00d571a0();
        float radius = shape->radius;
        if (!(radius > threshold))
            return;
        VectorResult end;
        VectorResult start;
        end.FUN_00c7f640(transform, &shape->point30);
        start.FUN_00c7f640(transform, &shape->point20);
        __m128 ev = end.value;
        __m128 sv = start.value;
        __m128 dv = _mm_sub_ps(ev, sv);
        __m128 nv = normalized(dv);
        __m128 rv = _mm_load_ss(&radius);
        __m128 offset = _mm_mul_ps(nv, _mm_shuffle_ps(rv, rv, 0));
        end.value = _mm_add_ps(ev, offset);
        start.value = _mm_sub_ps(sv, offset);
        D31Tbl2* holder = FUN_00c85750();
        OutputShape* result = static_cast<OutputShape*>(reinterpret_cast<Allocator*>(holder->sub)->allocate(0x90));
        result->memorySize = 0x90;
        result = result->FUN_00d58510(&end.value, &start.value, radius + additional, 9, 1);
        result->transform.FUN_00c6cd60(transform);
        output->append(result);
        return;
    }
    case 4: {
        float radius = shape->radius;
        if (!(radius > threshold))
            return;
        __m128 dimensions = _mm_add_ps(_mm_set1_ps(radius), shape->point20);
        D31Tbl2* holder = FUN_00c85750();
        OutputShape* result = static_cast<OutputShape*>(reinterpret_cast<Allocator*>(holder->sub)->allocate(0x70));
        result->memorySize = 0x70;
        result = result->FUN_00de1f50(&dimensions);
        result->transform.FUN_00c6cd60(transform);
        output->append(result);
        return;
    }
    case 3: {
        PlaneArray planes;
        float radius = shape->radius;
        if (!(radius > threshold))
            return;
        bool degenerate;
        const __m128* a = &shape->point20;
        const __m128* b = &shape->point30;
        const __m128* c = &shape->point40;
        if (*FUN_00ceb8d0(&degenerate, a, b, c, DAT_01017d00))
            return;
        __m128 normZero, normThree, normHalf;
        __m128 pointB = *b;
        __m128 pointA = *a;
        __m128 edge0 = normalizedInit(_mm_sub_ps(pointB, pointA), normZero, normThree, normHalf);
        __m128 pointC = *c;
        __m128 edge1 = normalizedUsing(_mm_sub_ps(pointC, pointB), normZero, normThree, normHalf);
        __m128 edge2 = normalizedUsing(_mm_sub_ps(pointC, *a), normZero, normThree, normHalf);
        __m128 normal = cross3(edge0, edge2);
        planes.data = 0;
        planes.size = 0;
        planes.capacity = 0x80000000;
        int count = 8;
        D31Tbl2* holder = FUN_00c85750();
        PlaneVector* allocation = count > 0 ? allocatePlaneItems(*reinterpret_cast<Allocator*>(holder->sub), count) : 0;
        int capacity = count ? count : 0x80000000;
        planes.data = allocation;
        planes.size = count;
        planes.capacity = capacity;
        planes.reserve(8);
        planes.size = 8;
        planes.data[0] = normal;
        planeDistance(planes, 0, *a, radius);
        planes.data[1] = _mm_xor_ps(normal, *reinterpret_cast<const __m128*>(&DAT_010c44d0));
        planeDistance(planes, 1, *a, radius);
        planes.data[2].setCross(edge0, normal);
        planeDistance(planes, 2, *a, radius);
        planes.data[3].setCross(edge1, normal);
        planeDistance(planes, 3, *b, radius);
        planes.data[4].setCross(normal, edge2);
        planeDistance(planes, 4, *c, radius);
        planes.data[5] = _mm_add_ps(planes.data[3], planes.data[2]);
        planes.data[5] = normalizedUsing(planes.data[5], normZero, normThree, normHalf);
        planeDistance(planes, 5, *b, radius);
        planes.data[6] = _mm_add_ps(planes.data[4], planes.data[3]);
        planes.data[6] = normalizedUsing(planes.data[6], normZero, normThree, normHalf);
        planeDistance(planes, 6, *c, radius);
        planes.data[7] = _mm_add_ps(planes.data[4], planes.data[2]);
        planes.data[7] = normalizedUsing(planes.data[7], normZero, normThree, normHalf);
        planeDistance(planes, 7, *a, radius);
        OutputShape* result = FUN_00de3360(&planes, transform);
        if (result)
            output->append(result);
        planes.release();
        return;
    }
    case 6: {
        PlaneArray planes;
        float radius = shape->radius;
        if (!(radius > threshold))
            return;
        PlaneArray* source = shape->FUN_00d58d50();
        float limit = FUN_00de3110(shape);
        planes.data = 0;
        planes.size = 0;
        planes.capacity = 0x80000000;
        D31Tbl2* holder = FUN_00c85750();
        Allocator* allocator = reinterpret_cast<Allocator*>(holder->sub);
        if ((planes.capacity & 0x3fffffff) < source->size)
        {
            if (!(unsigned(planes.capacity) & 0x80000000))
                allocator->freeChunk(planes.data, (planes.capacity & 0x3fffffff) * 16);
            int bytes = source->size * 16;
            planes.data = static_cast<PlaneVector*>(allocator->allocateChunk(bytes));
            planes.capacity = bytes / 16;
        }
        {
            PlaneVector* dst = planes.data;
            int count = source->size;
            planes.size = count;
            PlaneVector* src = source->data;
            for (int index = 0; index < count; ++index)
                dst[index].quad = src[index].quad;
        }
        float permitted = float(DAT_01023b88 - radius);
        if (limit > permitted)
        {
            int count = source->size;
            for (int i = 0; i < count; ++i)
            {
                float& component = planes[i].m128_f32[3];
                component -= radius;
            }
        }
        FUN_00de3200(shape, &planes, radius);
        OutputShape* result = FUN_00de3360(&planes, transform);
        if (result)
            output->append(result);
        planes.release();
        return;
    }
    default:
        for (int i = 0; i < DAT_01269ce4->size; ++i)
        {
            CallbackEntry* entry = &DAT_01269ce4->data[i];
            if (entry->kind == shape->kind)
                entry->callback(shape, transform, output, this);
        }
    }
commonExit:
    _ReadWriteBarrier();
    return;
}
