// src/havok/physics/collide/util/welding/hkpmeshweldingutility_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/util/welding/hkpmeshweldingutility.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/util/welding/hkpmeshweldingutility.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/util/welding/hkpmeshweldingutility.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Record
{
    float x, y, key;
};
struct ComparisonResult
{
    bool value;
    ComparisonResult(bool result) : value(result)
    {}
    operator bool() const
    {
        return value;
    }
};
__declspec(noinline) ComparisonResult FUN_00ddcda0(const Record& left, const Record& right)
{
    return ComparisonResult(left.key > right.key);
}
inline void SwapRecords(Record& first, Record& second)
{
    __declspec(align(16)) Record temp = second;
    second = first;
    first = temp;
}
void FUN_00ddeb70(Record* records, int left, int right, int comparator);
struct DynamicArray
{
    void SpliceElements(int a, int b, int c, int d, int e);
    void FUN_00ddecb0(int a, int b, int c, int d);
};
struct S_00ddecf0_Key
{
    float t;
    float a;
    float b;
};
struct S_00ddecf0_Heap;
struct S_00ddecf0_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00ddecf0_Heap* m_pStreamAllocator;
    S_00ddecf0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00ddecf0_Router* FUN_00c85750();
struct S_00ddecf0_Array
{
    S_00ddecf0_Key* m_data;
    int m_iElementCount;
    void FUN_00ddecd0(S_00ddecf0_Heap& heap, int index, const S_00ddecf0_Key& key);
};
struct S_00ddecf0
{
    int unk0;
    S_00ddecf0_Array m_keys;
    void InsertKey(float t, float a, float b);
};
extern double DAT_010cd5a8;
extern double DAT_0101ff40;
float FUN_00ddd7e0(int a1, int* pOut, float* pF);
int GetIndexForValue(int aiArg);
struct Iface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual Iface* GetSub();
    virtual void* Query(void* key, void* out);
};
struct FlagTag
{
    bool m_bValue;
    FlagTag(bool value) : m_bValue(value)
    {}
    FlagTag(const FlagTag& other) : m_bValue(other.m_bValue)
    {}
};
struct Mgr
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void Write(unsigned int hash, FlagTag value);
    virtual void Read(bool* out, unsigned int hash);
};
extern Mgr* DAT_01268360;
__declspec(align(16)) struct QueryBuffer
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
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
};
int FUN_00dde4c0(Iface* self, void* a, void* b, int idx, int zero, int* out);
bool* CheckSubQueries(bool* result, void* key, Iface* self);
void* FUN_00c908c0(void* alloc, void* arr, int numElems, int elemSize);
void FUN_00d2cc70(void* dst, const void* src, int numBytes);
inline void* operator new(unsigned int, void* p)
{
    return p;
}
struct S_00ddeab0_Elem
{
    int a, b, c;
    S_00ddeab0_Elem()
    {}
};
struct S_00ddeab0
{
    S_00ddeab0_Elem* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void GrowArrayCapacity(void* alloc, int numElems)
    {
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < numElems)
        {
            int cap2 = cap + cap;
            int newcap = (numElems < cap2) ? cap2 : numElems;
            FUN_00c908c0(alloc, this, newcap, 12);
        }
    }

    void SpliceElements(void* alloc, int index, int numdel, const S_00ddeab0_Elem* p, int numtoinsert);
};
struct S_00ddecd0
{
    void FUN_00ddecb0(int a, int b, int c, int flag);
    void FUN_00ddecd0(int a, int b, int c);
};
struct FourFloatVector
{
    float x, y, z, w;
};
struct Transform
{
    int pad[8];
    FourFloatVector v0;
    FourFloatVector v1;
    FourFloatVector v2;
};
struct ObjInner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Transform* GetTransform(void* p1, void* buffer);
};
struct ObjOuter
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ObjInner* GetInner();
};
struct LocalBuffer
{
    __declspec(align(16)) int data[125];
};
char* IsDegenerateTriangle(char* out, const FourFloatVector* v0, const FourFloatVector* v1, const FourFloatVector* v2,
                           float eps);
int FUN_00dde4c0(ObjOuter* p2, Transform* trans, void* p1, int i, void* p3, int* outLocal);
int __cdecl CheckTransformAndProcess(void* p1, ObjOuter* pOuter, void* p3, short* outWord);
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmple_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" int _mm_movemask_ps(__m128 a);
extern const float DAT_01017d00;
extern const __m128 DAT_01017d10;
class hkBoolDDCE
{
  public:
    hkBoolDDCE(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }

    char m_cBooleanValue;
};
struct hkVector4DDCE
{
    __m128 m_vComponents;

    bool equals3(const hkVector4DDCE& v) const
    {
        __m128 t = _mm_sub_ps(m_vComponents, v.m_vComponents);
        t = _mm_and_ps(t, DAT_01017d10);
        const __m128 eps = _mm_load_ps1(&DAT_01017d00);
        return (_mm_movemask_ps(_mm_cmple_ps(t, eps)) & 7) == 7;
    }
};
struct hkTransformHolderDDCE
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkVector4DDCE m_kColumn0;
    hkVector4DDCE m_kColumn1;
    hkVector4DDCE m_kColumn2;
};
struct hkUtilDDCE
{
    static hkBoolDDCE FUN_00ddced0(const hkTransformHolderDDCE& kA, const hkTransformHolderDDCE& kB);
};
struct FUN_00ddea00_src
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
    unsigned int unk40;
};
__declspec(align(16)) struct FUN_00ddea00_tmp
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
};
__declspec(align(16)) struct FUN_00ddea00_cls
{
    __m128 m_v00;
    __m128 m_v10;
    __m128 m_v20;
    __m128 m_v30;
    unsigned int m_i40;

    FUN_00ddea00_cls* CopyFromSource(const FUN_00ddea00_src* src);
};
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" void _mm_store_ss(float*, __m128);
int __cdecl FUN_00ddd6f0(const __m128* a, const __m128* b, int index, __m128* out, int* result);
extern "C"
{

    __m128 _mm_set_ss(float);

    __m128 _mm_sub_ps(__m128, __m128);

    __m128 _mm_mul_ps(__m128, __m128);

    __m128 _mm_mul_ss(__m128, __m128);

    __m128 _mm_add_ss(__m128, __m128);

    __m128 _mm_sub_ss(__m128, __m128);

    __m128 _mm_shuffle_ps(__m128, __m128, int);

    __m128 _mm_rsqrt_ss(__m128);

    __m128 _mm_cmpeq_ss(__m128, __m128);

    __m128 _mm_andnot_ps(__m128, __m128);
}
extern const float DAT_01011d78;
extern const float DAT_01017718;
extern const float DAT_01016248;
struct ScalarNormal
{
    __m128 q;
    ScalarNormal(__m128 value) : q(value)
    {}
    __m128 broadcast() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
struct NormalVector
{
    __m128 q;
    __forceinline void difference(const NormalVector& a, const NormalVector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void cross(const NormalVector& a, const NormalVector& b)
    {
        __m128 pos = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 201), _mm_shuffle_ps(b.q, b.q, 210));
        __m128 neg = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 210), _mm_shuffle_ps(b.q, b.q, 201));
        q = _mm_sub_ps(pos, neg);
    }
    __forceinline ScalarNormal dot(const NormalVector& v) const
    {
        __m128 square = _mm_mul_ps(q, v.q);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(square, square, 85), square);
        return ScalarNormal(_mm_add_ss(_mm_shuffle_ps(square, square, 170), sum));
    }
    __forceinline ScalarNormal inverseLength() const
    {
        __m128 half = _mm_set_ss(DAT_01016248);
        __m128 three = _mm_set_ss(DAT_01017718);
        __m128 zero = _mm_set_ss(DAT_01011d78);
        __m128 len = dot(*this).q;
        __m128 mask = _mm_cmpeq_ss(len, zero);
        __m128 approx = _mm_rsqrt_ss(len);
        __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, approx), approx));
        return ScalarNormal(_mm_andnot_ps(mask, _mm_mul_ss(_mm_mul_ss(half, approx), correction)));
    }
    __forceinline void normalize()
    {
        q = _mm_mul_ps(inverseLength().broadcast(), q);
    }
};
void FUN_00ddd620(const NormalVector* a, const NormalVector* b, const NormalVector* c, NormalVector* out);
struct S_00ddecf0_Heap
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
    template <typename T> __forceinline void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem * (int)sizeof(T));
    }
};
extern const double DAT_010290b8;
__declspec(nothrow) S_00ddecf0_Router* FUN_00c85750();
void __cdecl ResizeAudioStream(void* heap, void* arr, int elemSize) throw();
struct KeyLess
{
};
void __cdecl FUN_00ddeb70(S_00ddecf0_Key* keys, int left, int right, KeyLess cmp) throw();
template <typename T, typename L> inline void quickSort(T* pArr, int size, L cmpLess)
{
    if (size > 1)
        FUN_00ddeb70(pArr, 0, size - 1, cmpLess);
}
extern "C" double __cdecl fabs(double);
__declspec(noinline) ComparisonResult __cdecl AreZDiffering(const S_00ddecf0_Key& a, const S_00ddecf0_Key& b) throw()
{
    float delta = a.b - b.b;
    float distance = (float)fabs(delta);
    bool same = distance < DAT_01017d00;
    return ComparisonResult(!same);
}
struct ArrayAllocator
{
    __forceinline S_00ddecf0_Heap& get(const void*) const
    {
        return FUN_00c85750()->heap();
    }
};
template <typename T> struct SpanStorage
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline SpanStorage() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int capacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void dispose(S_00ddecf0_Heap& alloc)
    {
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            alloc._bufFree<T>(m_data, capacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void append(S_00ddecf0_Heap& alloc, const T& value)
    {
        if (m_iElementCount == capacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        T* dest = m_data + m_iElementCount;
        new (dest) T(value);
        ++m_iElementCount;
    }
};
template <typename T, typename A = ArrayAllocator> struct hkArray : SpanStorage<T>
{
    __forceinline hkArray()
    {}
    __forceinline ~hkArray()
    {
        dispose(A().get(this));
    }
    __forceinline void AddBack(const T& value)
    {
        append(A().get(this), value);
    }
};
static inline float clamp(float x, float lo, float hi)
{
    if (x < lo)
        return lo;
    if (x > hi)
        return hi;
    return x;
}
struct Track : public S_00ddecf0
{
    float FUN_00dded60();
};
// FUN_00ddcf60 - "point A is close to one of the three points of the shape
// AND point B is close to one of them as well" test.
//
// The shape object holds three 4-float points at +0x20 / +0x30 / +0x40.
// A point counts as a hit when the x/y/z components of the difference are not
// (movmskps + "and 7" + "cmp 7").
//
// The result byte is written through the first argument; the argument pointer
// is handed back to the caller.
struct Vec4
{
    __m128 v;
};
struct Shape
{
    float unk00, unk04, unk08, unk0c;
    float unk10, unk14, unk18, unk1c;
    Vec4 p0, p1, p2;
};
volatile unsigned char* __cdecl FUN_00ddcf60(volatile unsigned char* out, const Vec4* a, const Vec4* b, const Shape* s);
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    void _mm_store_ss(float*, __m128);
    float __cdecl Atan2(float y, float x);
}
struct hkVector4q
{
    __m128 m_vComponents;

    hkVector4q()
    {}
    hkVector4q(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }

    __forceinline void normalize3()
    {
        __m128 p = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                              _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
        r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }

    __forceinline void setCross(const hkVector4q& a, const hkVector4q& b)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }

    __forceinline float dot3(const hkVector4q& v) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        s = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
        float r;
        _mm_store_ss(&r, s);
        return r;
    }
};
static __forceinline float hkAtan2(float y, float x)
{
    return Atan2(y, x);
}
void __cdecl FUN_00ddd620_triNormal(const hkVector4q& a, const hkVector4q& b, const hkVector4q& c,
                                    hkVector4q& normalOut);
float FUN_00ddd7e0(const hkVector4q* v, float* sinOut, float* cosOut);
extern "C" __m128 _mm_load_ps(float const* _A);
extern "C" void _mm_store_ps(float* _V, __m128 _A);
struct __declspec(align(16)) Row
{
    float x, y, z, w;
};
struct __declspec(align(16)) Matrix44
{
    Row row0, row1, row2, row3;
};
struct __declspec(align(16)) Item
{
    Matrix44 transform;
    int payload;
};
struct S00dde760_PoolState
{
    char* cursor;
    int unk04;
    int unk08;
    int unk0c;
    S_00ddecf0_Heap* allocator;
};
struct S00dde760_ScratchVector
{
    Item* elements;
    unsigned int size;
    unsigned int encodedCapacity;
    char* originalCursor;
};
extern "C" Matrix44 DAT_01268370;
extern "C" void __cdecl FUN_00dddcd0(const Matrix44*, int, int, S00dde760_ScratchVector*, int);
void __cdecl FUN_00dde760(int a, int b, int c, int d);

extern "C" ::__m128(_mm_setr_ps)(float, float, float, float);
extern "C" ::__m128(_mm_add_ps)(::__m128, ::__m128);

extern float DAT_010141cc;
extern const char str_010d7fc8[];
extern const char str_010d8004[];
extern const char str_010d8014[];
extern const char str_010d7f50[];

struct S00dde4c0_Vec
{
    ::__m128 q;
    __forceinline void setAll3(float v)
    {
        q = (_mm_setr_ps)(v, v, v, ::DAT_01011d78);
    }
};
struct S00dde4c0_Tri
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S00dde4c0_Vec v[3];
};
struct S00dde4c0_Aabb
{
    S00dde4c0_Vec mn;
    S00dde4c0_Vec mx;
};

struct S00dde4c0_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int type;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int data;
};
struct S00dde4c0_Src
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual S00dde4c0_Shape* getShape(int index, void* buffer);
};
struct S00dde4c0_Mesh
{
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual S00dde4c0_Src* getSource();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void query(S00dde4c0_Aabb* aabb, void* outArray);
};
struct S00dde4c0_Out
{
    ::__m128 a;
    ::__m128 b;
    ::__m128 c;
    ::__m128 d;
    ::__m128 e;
    ::__m128 f;
};

struct S00dde4c0_Array
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_kStorage[128];
    __forceinline S00dde4c0_Array()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000080;
    }
    __forceinline void finish()
    {
        release(::FUN_00c85750()->heap());
    }
    __forceinline void release(::S_00ddecf0_Heap& a)
    {
        m_iElementCount = 0;
        if (!(m_iCapacityState & 0x80000000))
            a._bufFree<int>(m_data, m_iCapacityState & 0x3fffffff);
    }
};
struct S00dde4c0_Buf
{
    int b[128];
};

struct S00dde4c0_Str
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void FUN_00cb1600(void* buf, int n);
    S00dde4c0_Str& FUN_00cc01c0(const char* s);
    S00dde4c0_Str& FUN_00cc02d0(int v);
    void FUN_00cc00e0();
};
struct S00dde4c0_Err
{
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void report(int a, unsigned int id, const char* msg, const char* file, int line);
};

int __cdecl FUN_00ddd6f0(const S00dde4c0_Vec* tri, const void* shape, int idx, S00dde4c0_Out* out, int* winding);
unsigned int __cdecl FUN_00ddcdd0(unsigned int f, unsigned int idx, unsigned int v);

// @fnv 0x00dde4c0
int __cdecl FUN_00dde4c0(S00dde4c0_Mesh* mesh, S00dde4c0_Tri* tri, int skip, int idx, int checkWinding,
                         unsigned short* flags)
{
    const S00dde4c0_Vec* verts = tri->v;
    S00dde4c0_Array hits;
    {
        S00dde4c0_Aabb aabb;
        struct BoundsWork
        {
            S00dde4c0_Vec center;
            S00dde4c0_Vec lo;
        } work;
        work.center = verts[idx % 3];
        float eps = DAT_010141cc;
        work.lo.setAll3(-eps);
        ::__m128 low = work.lo.q;
        S00dde4c0_Vec hi;
        hi.setAll3(eps);
        aabb.mn.q = (_mm_add_ps)(low, work.center.q);
        aabb.mx.q = (_mm_add_ps)(hi.q, work.center.q);
        mesh->query(&aabb, &hits);
    }
    bool first = true;
    for (int i = hits.m_iElementCount - 1; i >= 0; i--)
    {
        int other = hits.m_data[i];
        if (other == skip)
            continue;
        S00dde4c0_Buf buffer;
        S00dde4c0_Shape* shape = mesh->getSource()->getShape(other, &buffer);
        if (shape->type != 3)
            continue;
        int winding[2];
        S00dde4c0_Out out;
        if (FUN_00ddd6f0(verts, &shape->data, idx, &out, winding) != 4)
            continue;
        if (checkWinding && winding[0] != (winding[1] + 1) % 3)
        {
            if (first)
            {
                S00dde4c0_Str sb;
                sb.FUN_00cb1600(&buffer, 0x200);
                sb.FUN_00cc01c0(str_010d7fc8)
                    .FUN_00cc02d0(skip)
                    .FUN_00cc01c0(str_010d8004)
                    .FUN_00cc02d0(other)
                    .FUN_00cc01c0(str_010d8014);
                ((S00dde4c0_Err*)::DAT_01268360)->report(1, 0xabba751e, (const char*)&buffer, str_010d7f50, 0x2c9);
                sb.FUN_00cc00e0();
            }
            first = false;
        }
        *flags = (unsigned short)FUN_00ddcdd0(*flags, idx, ::GetIndexForValue((int)&out));
    }
    int result = !first;
    hits.finish();
    return result;
}
