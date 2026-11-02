// src/havok/physics/collide/util/welding/hkpmeshweldingutility_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/collide/util/welding/hkpmeshweldingutility.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


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

extern "C"
{
    __m128 _mm_load_ss(const float*);
    __m128 _mm_set_ss(float);
    __m128 _mm_set_ps1(float);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    double __cdecl fabs(double);
}

extern char DAT_010d7f80;
extern char DAT_010d7f50;
extern const double DAT_0103c7c8;

class hkSimdRealW
{
  public:
    hkSimdRealW(const __m128& x) : m_vValue(x)
    {}
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }

  private:
    __m128 m_vValue;
};

class hkBoolW
{
  public:
    inline hkBoolW()
    {}
    inline hkBoolW(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    inline hkBoolW& operator=(bool e)
    {
        m_cBooleanValue = static_cast<char>(e);
        return *this;
    }

  private:
    char m_cBooleanValue;
};

template <typename ENUM, typename STORAGE> class hkEnumW
{
  public:
    operator ENUM() const
    {
        return static_cast<ENUM>(m_kStorage);
    }
    hkBoolW operator==(ENUM e) const
    {
        return m_kStorage == static_cast<STORAGE>(e);
    }
    hkBoolW operator!=(ENUM e) const
    {
        return m_kStorage != static_cast<STORAGE>(e);
    }

  private:
    STORAGE m_kStorage;
};

enum hkpShapeTypeW
{
    HK_SHAPE_TRIANGLE_W = 3
};
enum hkCollectionTypeW
{
    COLLECTION_LIST_W = 1,
    COLLECTION_EXTENDED_MESH_W = 2,
    COLLECTION_TRISAMPLED_HEIGHTFIELD_W = 4,
    COLLECTION_USER_W = 5,
    COLLECTION_SIMPLE_MESH_W = 6
};

struct hkRotationW;
struct hkTransformW;

// hkVector4 (hkSseVector4.inl)
struct hkVector4W
{
    __m128 m_vComponents;

    inline void SetAllComponents(float a)
    {
        m_vComponents = _mm_set_ps1(a);
    }
    inline void setSub4(const hkVector4W& v0, const hkVector4W& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    inline void setMin4(const hkVector4W& a, const hkVector4W& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    inline void setMax4(const hkVector4W& a, const hkVector4W& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    inline void setCross(const hkVector4W& v0, const hkVector4W& v1)
    {
        __m128 cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    inline hkSimdRealW dot3(const hkVector4W& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    inline hkSimdRealW lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = this->dot3(*this).getQuad();
        const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const __m128 approx = _mm_rsqrt_ss(len2);
        const __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    inline void normalize3()
    {
        __m128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    inline void _setMul3(const hkRotationW& a, const hkVector4W& b);
    inline void _setRotatedDir(const hkRotationW& r, const hkVector4W& v)
    {
        _setMul3(r, v);
    }
    inline void _setTransformedPos(const hkTransformW& t, const hkVector4W& b);
};

struct hkRotationW
{
    hkVector4W m_kColumn0;
    hkVector4W m_kColumn1;
    hkVector4W m_kColumn2;
    const hkVector4W& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
};

struct hkTransformW
{
    hkRotationW m_rotation;
    hkVector4W m_vTranslation;
    hkTransformW()
    {}
    const hkRotationW& getRotation() const
    {
        return m_rotation;
    }
    const hkVector4W& getTranslation() const
    {
        return m_vTranslation;
    }
    void FUN_00cb22f0(const hkTransformW& bTa, const hkTransformW& bTc);
};

inline void hkVector4W::_setMul3(const hkRotationW& a, const hkVector4W& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

inline void hkVector4W::_setTransformedPos(const hkTransformW& t, const hkVector4W& b)
{
    const hkRotationW& r = t.getRotation();
    __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    __m128 r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    __m128 r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    __m128 r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.getTranslation().m_vComponents));
}

struct hkAabbW
{
    hkVector4W m_kMinimumCorner;
    hkVector4W m_kMaximumCorner;
    hkAabbW()
    {}
    inline hkAabbW(const hkVector4W& p0, const hkVector4W& p1)
    {
        setEmpty();
        includePoint(p0);
        includePoint(p1);
    }
    inline void setEmpty()
    {
        m_kMinimumCorner.SetAllComponents(3.40282e+38f);
        m_kMaximumCorner.SetAllComponents(-3.40282e+38f);
    }
    inline void includePoint(const hkVector4W& point)
    {
        m_kMinimumCorner.setMin4(m_kMinimumCorner, point);
        m_kMaximumCorner.setMax4(m_kMaximumCorner, point);
    }
};

struct hkpTriangleShapeW
{
    int vtbl;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    hkEnumW<hkpShapeTypeW, unsigned int> m_type;
    int unk10, unk14, unk18, unk1c;
    hkVector4W m_kVertexA;
    hkVector4W m_kVertexB;
    hkVector4W m_kVertexC;
    hkpShapeTypeW getType() const
    {
        return m_type;
    }
    const hkVector4W& getVertex(int i) const
    {
        return (&m_kVertexA)[i];
    }
};

struct hkInplaceArrayW
{
    unsigned int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned int m_kStorage[128];
    inline hkInplaceArrayW(int size)
    {
        m_data = m_kStorage;
        m_iElementCount = size;
        m_iCapacityState = 128 | 0x80000000;
    }
    inline ~hkInplaceArrayW()
    {
        S_00ddecf0_Heap& alloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(unsigned int));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    unsigned int& operator[](int i)
    {
        return m_data[i];
    }
};

struct hkEntryW
{
    float a, b, c;
};

struct hkHistogramW
{
    float m_fScalar;
    hkEntryW* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    inline hkHistogramW(bool zeroTolerance)
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
        m_fScalar = zeroTolerance ? 0.0f : 3.14159265f;
    }
    inline ~hkHistogramW()
    {
        S_00ddecf0_Heap& alloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(hkEntryW));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    float FUN_00dded60();
    void InsertKey(float t0, float t1, float angle);
};

struct hkpShapeContainerW
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual const hkpTriangleShapeW* GetShapeForKey(unsigned int key, QueryBuffer& buffer) const;
};

struct hkpBvTreeShapeW
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual const hkpShapeContainerW* GetShapeContainer() const;
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void GetAabbHits(const hkAabbW& aabb, hkInplaceArrayW& hits) const;
};

struct hkShapeInfoW
{
    hkTransformW m_kMotionTransform;
    const hkpBvTreeShapeW* m_pCollisionShape;
};

struct hkShapeInfoArrayW
{
    hkShapeInfoW* m_data;
    int m_iElementCount;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    hkShapeInfoW& operator[](int i)
    {
        return m_data[i];
    }
};

struct hkpShapeCollectionContainerW
{
    virtual void v0();
    virtual void v1();
    virtual int GetFirstKey() const;
    virtual int GetNextShapeKey(int) const;
    virtual void v4();
    virtual const hkpTriangleShapeW* GetShapeForKey(int, QueryBuffer&) const;
};

struct hkpShapeCollectionW
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void SetWeldingMode(int weldingType);
    virtual void SetWeldingInfo(int key, unsigned int weldingInfo);
    int unk04;
    int unk08;
    int unk0c;
    hkpShapeCollectionContainerW m_container;
    hkBoolW m_bDisableWelding;
    hkEnumW<hkCollectionTypeW, unsigned char> m_eCollectionType;
};

struct TextFormat
{
    char* data;
    int size;
    int capacityFlags;
    void FUN_00cb1600(char*, int);
    TextFormat* FUN_00cc01c0(const char*);
    void FUN_00cc00e0();
};

struct ErrorManager
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int Report(int, unsigned, char*, const char*, int);
};

// hkpMeshWeldingUtility::calcAntiClockwiseTriangleNormal
__declspec(noinline) void __cdecl FUN_00ddd620(const hkVector4W& v0, const hkVector4W& v1, const hkVector4W& v2,
                                               hkVector4W& normal)
{
    hkVector4W e0;
    e0.setSub4(v1, v0);
    hkVector4W e1;
    e1.setSub4(v2, v1);
    normal.setCross(e0, e1);
    normal.normalize3();
}
hkBoolW __cdecl FUN_00ddcf60(const hkVector4W& v0, const hkVector4W& v1, const hkpTriangleShapeW* triangle);
float __cdecl FUN_00ddd5a0(const hkVector4W& normal, const hkVector4W& perp, const hkVector4W& otherNormal);
void __cdecl GenerateTrianglePlanes(hkVector4W* planes, const hkpTriangleShapeW* triangle, float tolerance);
hkBoolW __cdecl FUN_00ddd0b0(const hkVector4W& a, const hkVector4W& b, int numPlanes, const hkVector4W* planes,
                             float& tmin, float& tmax);
int __cdecl FindAngleIndex(float angle);
unsigned int __cdecl FUN_00ddcdd0(unsigned int combined, int edgeIndex, unsigned int code);

// hkIsEdgeInTrianglePlane
__declspec(noinline) hkBoolW __cdecl IsDotProductBelowThreshold(const hkVector4W& edge, const hkVector4W& normal)
{
    __m128 product = _mm_mul_ps(edge.m_vComponents, normal.m_vComponents);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(product, product, 85), product);
    sum = _mm_add_ss(_mm_shuffle_ps(product, product, 170), sum);
    float scalar;
    _mm_store_ss(&scalar, sum);
    float magnitude = (float)fabs((double)scalar);
    return hkBoolW(magnitude < DAT_0103c7c8);
}

// @fnv 0x00dddcd0
void __cdecl FUN_00dddcd0(const hkTransformW& transform, hkpShapeCollectionW* collection, int weldingType,
                          hkShapeInfoArrayW& allShapes, bool weldOpenEdges)
{
    if (collection->m_eCollectionType != COLLECTION_LIST_W &&
        collection->m_eCollectionType != COLLECTION_EXTENDED_MESH_W &&
        collection->m_eCollectionType != COLLECTION_SIMPLE_MESH_W &&
        collection->m_eCollectionType != COLLECTION_TRISAMPLED_HEIGHTFIELD_W &&
        collection->m_eCollectionType != COLLECTION_USER_W)
    {
        QueryBuffer messageStorage;
        char* message = reinterpret_cast<char*>(&messageStorage);
        TextFormat formatted;
        formatted.FUN_00cb1600(message, 512);
        formatted.FUN_00cc01c0(&DAT_010d7f80);
        ((ErrorManager*)DAT_01268360)->Report(1, 0x3f508c6a, message, &DAT_010d7f50, 271);
        formatted.FUN_00cc00e0();
        return;
    }

    collection->SetWeldingMode(weldingType);
    if (weldingType == 6)
        return;
    collection->m_bDisableWelding = true;
    hkpShapeCollectionContainerW* container = &collection->m_container;
    for (int key = container->GetFirstKey(); key != -1; key = container->GetNextShapeKey(key))
    {
        QueryBuffer buffer;
        const hkpTriangleShapeW* triangle = container->GetShapeForKey(key, buffer);
        if (triangle->getType() != HK_SHAPE_TRIANGLE_W)
            continue;

        unsigned int weldingInfo = 0;
        hkVector4W triangleNormal;
        FUN_00ddd620(triangle->getVertex(0), triangle->getVertex(1), triangle->getVertex(2), triangleNormal);

        for (int edgeIndex = 0; edgeIndex < 3; edgeIndex++)
        {
            hkHistogramW histogram(weldOpenEdges);
            hkVector4W v0 = triangle->getVertex(edgeIndex);
            hkVector4W v1 = triangle->getVertex((edgeIndex + 1) % 3);
            hkVector4W v2 = triangle->getVertex((edgeIndex + 2) % 3);

            for (int shapeIndex = 0; shapeIndex < allShapes.GetLogicalSize(); shapeIndex++)
            {
                const hkShapeInfoW& info = allShapes[shapeIndex];
                const hkpBvTreeShapeW* bvTree = allShapes[shapeIndex].m_pCollisionShape;
                hkTransformW t;
                t.FUN_00cb22f0(info.m_kMotionTransform, transform);

                hkVector4W normal;
                normal._setRotatedDir(t.getRotation(), triangleNormal);
                hkVector4W a;
                a._setTransformedPos(t, v0);
                hkVector4W b;
                b._setTransformedPos(t, v1);
                hkVector4W c;
                c._setTransformedPos(t, v2);
                hkVector4W edge;
                edge.m_vComponents = _mm_sub_ps(b.m_vComponents, a.m_vComponents);
                edge.normalize3();

                hkInplaceArrayW hits(0);
                bvTree->GetAabbHits(hkAabbW(a, b), hits);

                for (int j = 0; j < hits.GetLogicalSize(); j++)
                {
                    unsigned int hitKey = hits[j];
                    const hkpShapeContainerW* shapeContainer = bvTree->GetShapeContainer();
                    QueryBuffer shapeBuffer;
                    const hkpTriangleShapeW* other = shapeContainer->GetShapeForKey(hitKey, shapeBuffer);
                    if (other->getType() != HK_SHAPE_TRIANGLE_W)
                        continue;

                    if (hkUtilDDCE::FUN_00ddced0(*(const hkTransformHolderDDCE*)triangle,
                                                 *(const hkTransformHolderDDCE*)other)
                            .m_cBooleanValue ||
                        FUN_00ddcf60(b, c, other) || FUN_00ddcf60(c, a, other))
                        continue;

                    hkVector4W otherNormal;
                    FUN_00ddd620(other->getVertex(0), other->getVertex(1), other->getVertex(2), otherNormal);
                    if (!IsDotProductBelowThreshold(edge, otherNormal))
                        continue;

                    hkVector4W perp;
                    perp.setCross(edge, normal);
                    perp.normalize3();
                    float angle = FUN_00ddd5a0(normal, perp, otherNormal);

                    hkVector4W planes[5];
                    GenerateTrianglePlanes(planes, other, 0.05f);
                    float tmin, tmax;
                    if (FUN_00ddd0b0(a, b, 5, planes, tmin, tmax))
                        histogram.InsertKey(tmin, tmax, angle);
                }
            }
            weldingInfo = (unsigned short)FUN_00ddcdd0(weldingInfo, edgeIndex, FindAngleIndex(histogram.FUN_00dded60()));
        }
        collection->SetWeldingInfo(key, weldingInfo);
    }
}
