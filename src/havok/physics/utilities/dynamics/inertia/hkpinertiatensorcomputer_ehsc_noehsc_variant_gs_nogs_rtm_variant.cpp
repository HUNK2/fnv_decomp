// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_ehsc_noehsc_variant_gs_nogs_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_ehsc_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS- /EHs-c- /Gy (unit lists /MT /O2 /GS /EHs-c- /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Object
{
};
void __cdecl FUN_00cebdf0(float* source, float value, Object* destination);
void __cdecl FUN_00cebe50(float* source, float scale, Object* destination);
struct Receiver
{
    void FUN_00cecc90(float value);
};
struct State
{
    int first;
    int count;
    int context;
};
void FUN_00cebbb0(void* state, float zero, void* receiver);
int __cdecl ApplyLimitToReceiver(int owner, int context, int count, float limit, Receiver* receiver, float value);
struct FUN_00cebe80_Struct
{
    float unk00;
    float unk04;
    float unk08;
};
void __cdecl FUN_00cebe80(FUN_00cebe80_Struct* pThis, float fScale, float* pMatrix);
void __cdecl AddInertiaTensor(float* param_1, float fScale, float* pMatrix);
struct FUN_00cec6b0_cls
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
    float m_64;
    float m_68;
    float m_6C;
    float m_70;
    float m_74;
    float m_78;
    float m_7C;
    float m_80;
    float m_84;
    float m_88;

    void FUN_00cec6b0(float a1, float b, float* p, float* M);
};
struct CECCD0Value
{
    float m_uiFilterValue;

    void set(float v);
    void ScaleValue(float scale);
};
struct S_00ced230_T
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
    float unk70;
    float unk74;
    float unk78;
};
static inline float S_MaxGT(float x, float y)
{
    return (x > y) ? x : y;
}
static inline float S_MaxLT(float x, float y)
{
    return (x < y) ? y : x;
}
void __cdecl FUN_00ced230(float afDivisor, S_00ced230_T* pData);
struct S_00cee1c0_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* p, unsigned int size);
};
struct S_00cee1c0_Router
{
    unsigned int cursor;
    int unk04;
    int unk08;
    int unk0C;
    S_00cee1c0_Heap* heap;
};
struct S_00cee1c0_Arr
{
    unsigned int* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    unsigned int* m_pTrailingData;
};
S_00cee1c0_Router* FUN_00c85750();
float __cdecl FUN_00cedec0(S_00cee1c0_Arr* arr, int unk, float value);
void __cdecl ProcessArrayWithValue(unsigned int* source, int count, int unk, float value);
namespace fnv_anon_00cec3d0 {}
using namespace fnv_anon_00cec3d0;
namespace fnv_anon_00cec3d0 {
struct S00cec3d0_Base
{
    int A;
    int B;
    int C;
    float P1;
    float Pa;
    float Pb;
    float m_fComponent0;
    float m_fComponent1;
    float m_fComponent2;
    float m_fComponent3;
    float m_fComponent4;
    float m_fComponent5;
    float m_fComponent6;

    __declspec(noinline) void FUN_00cec000(const float* v);
};
}
struct S00cec3d0_Face : S00cec3d0_Base
{
    float Fa;
    float Fb;
    float Fc;
    float m_fVertex0X;
    float m_fVertex0Y;
    float m_fVertex0Z;
    float m_fVertex1X;
    float m_fVertex1Y;
    float m_fVertex1Z;
    float m_fVertex2X;
    float m_fVertex2Y;
    float m_fVertex2Z;

    void FUN_00cec3d0(const float* verts, const float* n);
};
static inline float S00cec3d0_Sqr(float x)
{
    return x * x;
}
static inline float S00cec3d0_Cube(float x)
{
    return x * x * x;
}
void S00cec3d0_Base::FUN_00cec000(const float* v)
{
    P1 = v[A] * v[B];
    Pa = v[A];
}
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_setzero_ps();
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
}
struct Vector
{
    union
    {
        __m128 q;
        struct
        {
            float x, y, z, w;
        };
    };
    Vector()
    {}
    Vector(const Vector& other) : q(other.q)
    {}
    void operator=(const Vector& other)
    {
        q = other.q;
    }
    void set(float x, float y, float z, float w)
    {
        q = _mm_setr_ps(x, y, z, w);
    }
    float& operator()(int i)
    {
        return q.m128_f32[i];
    }
    int maxAxisSecond() const
    {
        if (x < y)
            return y < z ? 2 : 1;
        return x < z ? 2 : 0;
    }
    int maxAxis() const
    {
        if (x < y)
        {
            if (z > y)
                return 2;
            return 1;
        }
        if (z > x)
            return 2;
        return 0;
    }
};
struct Matrix
{
    Vector c0, c1, c2;
};
struct Transform
{
    Vector columns[4];
};
struct Bounds
{
    Vector lo, hi;
};
extern const Vector DAT_01017d10;
void FUN_00d5ac50(char*, Matrix*, Vector*, Vector*, Vector*);
struct Shape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void getAabb(const Transform*, float, Bounds*);
};
void FUN_00cedae0(Shape* shape, const Matrix* input, Vector* outA, Vector* outB);
struct MotionLike
{
    int unk00;
    float field04;
    int unk08;
    int unk0c;
    __m128 field10;
    __m128 field20;
    __m128 field30;
    __m128 field40;
    __m128 field50;
    __m128 field60;
    __m128 field70;
    __m128 field80;
    float field90;
};
void FUN_00cebdb0(const MotionLike* source, MotionLike* destination);
extern "C" __m128 _mm_load_ss(const float*);
struct Sub
{
    void Multiply(const Vector* p);
};
struct Owner
{
    int unk00;
    float m04;
    int unk08, unk0c, unk10, unk14, unk18, unk1c;
    Sub m20;
};
static void FUN_00cebfd0(Owner* self, float value);
Owner* volatile g_owner;
volatile float g_value;
Owner* volatile g_sink;
void caller();
struct __declspec(align(16)) S00ceccf0_Vec
{
    __m128 q;
    void set(__m128 v)
    {
        q = v;
    }
    __m128 get() const
    {
        return q;
    }
    void operator=(const S00ceccf0_Vec& o)
    {
        q = o.q;
    }
};
struct __declspec(align(16)) S00ceccf0_Mat
{
    S00ceccf0_Vec c0;
    S00ceccf0_Vec c1;
    S00ceccf0_Vec c2;
    void Subtract(const S00ceccf0_Mat& o);
    S00ceccf0_Mat& operator=(const S00ceccf0_Mat& o)
    {
        c0 = o.c0;
        c1 = o.c1;
        c2 = o.c2;
        return *this;
    }
};
struct S00ceccf0_Out
{
    float m_00;
    float m_04;
    int unk08;
    int unk0c;
    S00ceccf0_Vec m_10;
    S00ceccf0_Mat m_20;
};
extern const double DAT_010cbf40;
static __declspec(noinline) void __cdecl FUN_00ceba60(float a, float b, S00ceccf0_Out* out)
{
    out->m_10.set(_mm_setzero_ps());
    out->m_00 = a * b;
    out->m_04 = a + b;
}
void(__cdecl* g_S00ceccf0_fp)(float, float, S00ceccf0_Out*) = &FUN_00ceba60;
static __declspec(noinline) void FUN_00cebfd0(S00ceccf0_Out* out, float value)
{
    out->m_00 *= value;
    out->m_04 *= value;
}
int __cdecl FUN_00ceccf0(float start, float span, float t, S00ceccf0_Out* out);
// Incident-edge walk: detach edges touching `unk`, recurse to the other end,
// then fold the node's inertia diagonal with the children's sum and max.
// Local array is an inplace hkArray (cap 16, dont-free flag 0x80000000).
struct Edge
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int n14;
    int n18;
};
struct __declspec(align(16)) Mat3
{
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
};
struct ShapeIface
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void getInertia(Mat3* out);
};
struct Node
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;
    int unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    int unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    ShapeIface shape;
    int unkE4;
    char kind;
    bool isStatic() const
    {
        return kind == 5 || kind == 4;
    }
    ShapeIface* getMotion()
    {
        return &shape;
    }
    void FUN_00ca8920(Mat3* m);
};
struct LocalArr
{
    Edge** m_data;
    int m_iElementCount;
    int m_cap;
    Edge* storage[16];
};
void __cdecl ResizeAudioStream(void* heap, void* array, int elemSize);
__forceinline void releaseArr(LocalArr* a)
{
    S_00cee1c0_Router* router = FUN_00c85750();
    S_00cee1c0_Heap* heap = router->heap;
    int cap = a->m_cap;
    a->m_iElementCount = 0;
    if ((cap & 0x80000000) == 0)
        heap->Free(a->m_data, (cap & 0x3fffffff) * 4);
}
__forceinline float fMinimumInputValue(float a, float b)
{
    return a > b ? a : b;
}
__forceinline float fTargetUpperBound(float a, float b)
{
    return a < b ? a : b;
}
float __cdecl FUN_00cedec0(S_00cee1c0_Arr* arr, int unk, float value);
typedef union __declspec(intrin_type) __declspec(align(16)) __m128i
{
    int m128i_i32[4];
} __m128i;
extern "C" __m128i _mm_cvtsi32_si128(int);
__m128 _mm_castsi128_ps(__m128i);
extern "C" void _mm_store_ps(float*, __m128);
struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};
struct Probe
{
    unsigned char flag;
    unsigned char status1;
    unsigned char status2;
    unsigned char status3;
    int next;
    int previous;
    int index;
};
struct Track
{
    int stage;
    int frame;
    int sequence;
    int timer;
    int interpolation;
    void FUN_00d76ca0();
    void FUN_00d77200(void* state, Probe* probe);
    int FUN_00d74e10();
    void FUN_00d762f0();
    float GetMass();
    double FUN_00d752e0();
    __m128* FUN_00d75600();
    __m128* FUN_00d75560();
    void FUN_00d77be0(float scale);
    void FUN_00d76940();
};
struct RowMatrix
{
    __m128 row0, row1, row2;
    void Multiply(const Vec4* weight);
};
struct Receiver2
{
    float time;
    float enabled;
    float pad08;
    float pad0c;
    __m128 translation;
    RowMatrix matrix;
};
struct Status
{
    void FUN_00d74d40();
};
extern float DAT_011b153c;
extern double DAT_01020998;
extern double DAT_010cbf50;
extern double DAT_010cbf48;
inline __m128 scalarVector(float x)
{
    __m128 result = {x};
    return result;
}
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _ReadWriteBarrier();
int __cdecl FUN_00cebbb0(void* state, float value, Receiver2* receiver);
struct S_00ced310_V
{
    float x, y, z, w;
};
struct S_00ced310_M
{
    S_00ced310_V c0, c1, c2;
};
static __forceinline float S_Max(float a, float b)
{
    return a > b ? a : b;
}
static __forceinline void S_SetZero(S_00ced310_M* m)
{
    __m128 z = _mm_setzero_ps();
    _ReadWriteBarrier();
    _mm_store_ps(&m->c0.x, z);
    _mm_store_ps(&m->c1.x, z);
    _mm_store_ps(&m->c2.x, z);
}
void __cdecl SetDiagonal(S_00ced310_M* m);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_set_ps1(float);
}
struct S_00ced090_Elem
{
    float unk00;
    float unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
};
struct S_00ced090_Out
{
    float unk00;
    float unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};
struct S_00ced090_State
{
    S_00ced090_Elem* first;
    int count;
};
struct __declspec(align(16)) S_00ced090_V4
{
    float x, y, z, w;
};
struct S_00ced090_Mat
{
    S_00ced090_V4 r0, r1, r2;
    void FUN_00cd5880(void* xf);
};
struct S_00ced090_Vec
{
    S_00ced090_V4 v;
    void FUN_00c7f640(void* a, void* b);
};
struct S_00ced090_Inertia
{
    S_00ced090_V4 r0, r1, r2;
    void FUN_00cd5140(S_00ced090_Mat* m);
};
void __cdecl AddInertiaTensor(S_00ced090_Vec* d, float m, S_00ced090_Mat* mat);
int __cdecl FUN_00ced090(S_00ced090_State* s, S_00ced090_Out* out);
extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);
extern __declspec(thread) int DAT_012722b4;
struct S00cf0f40_Guard
{
    int m_saved;
    S00cf0f40_Guard()
    {
        m_saved = DAT_012722b4;
        DAT_012722b4 = 0x10;
    }
    ~S00cf0f40_Guard()
    {
        DAT_012722b4 = m_saved;
    }
};
struct S00cf0f40_Stream
{
    int unk00;
    unsigned int m_pos;
    unsigned int(__cdecl* m_read)(S00cf0f40_Stream* self, void* dst, unsigned int size, unsigned int* comp,
                                  unsigned int n);
    unsigned int BinaryRead(void* p, unsigned int size, unsigned int* comp, unsigned int n)
    {
        unsigned int r = m_read(this, p, size, comp, n);
        m_pos += r;
        return r;
    }
};
inline unsigned int S00cf0f40_Load(S00cf0f40_Stream& s, unsigned int* p, unsigned int n)
{
    unsigned int uiSize = sizeof(unsigned int);
    return s.BinaryRead(p, n * sizeof(unsigned int), &uiSize, 1);
}
struct S00cf0f40_Owner
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    unsigned char unk1E4;
    unsigned char m_1e5;
    unsigned char unk1E6;
    unsigned char unk1E7;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    S00cf0f40_Stream* m_stream;
};
struct S00cf0f40_Vec
{
    unsigned int x, y, z, w;
};
struct S00cf0f40_Arr;
inline S_00cee1c0_Heap& S00cf0f40_heap(S_00cee1c0_Router* r)
{
    return *r->heap;
}
void __cdecl FUN_00c908c0(S_00cee1c0_Heap* heap, void* arr, int cap, int elemSize);
struct S00cf0f40_Arr
{
    S00cf0f40_Vec* m_data;
    int m_iElementCount;
    int m_capFlags;

    int getCapacity() const
    {
        return m_capFlags & 0x3fffffff;
    }
    void ClearAndRelease()
    {
        S_00cee1c0_Heap& heap = S00cf0f40_heap(FUN_00c85750());
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0)
            heap.Free(m_data, getCapacity() * sizeof(S00cf0f40_Vec));
        m_data = 0;
        m_capFlags = 0x80000000;
    }
    void reserve(int n)
    {
        S_00cee1c0_Heap& heap = S00cf0f40_heap(FUN_00c85750());
        int cap = getCapacity();
        if (cap < n)
        {
            int nc = cap * 2;
            FUN_00c908c0(&heap, this, n < nc ? nc : n, sizeof(S00cf0f40_Vec));
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
inline void S00cf0f40_Swap4(void* p)
{
    unsigned int t;
    memcpy(&t, p, 4);
    t = _byteswap_ulong(t);
    memcpy(p, &t, 4);
}
unsigned int __cdecl FUN_00cf0f40(S00cf0f40_Owner* owner, S00cf0f40_Arr* arr);

#include <math.h>
extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_setzero_ps();
    __m128 _mm_load_ss(const float*);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}

typedef __m128 hkQuadReal;
typedef float hkReal;

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
    __forceinline const hkQuadReal& getQuad() const
    {
        return m_vValue;
    }

  private:
    hkQuadReal m_vValue;
};
typedef const VectorComponentValue& hkSimdRealParameter;

class hkVector4
{
  public:
    __forceinline hkVector4()
    {}
    __forceinline hkVector4(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(hkReal a, hkReal b, hkReal c, hkReal d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void mul4(hkSimdRealParameter s)
    {
        m_vComponents = _mm_mul_ps(s.broadcast(), m_vComponents);
    }
    __forceinline void setCross(const hkVector4& v0, const hkVector4& v1)
    {
        hkQuadReal cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        hkQuadReal cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline VectorComponentValue length3() const
    {
        return _mm_sqrt_ss(this->dot3(*this).getQuad());
    }
    __forceinline VectorComponentValue lengthInverse3() const
    {
        const hkQuadReal half = _mm_set_ss(0.5f);
        const hkQuadReal three = _mm_set_ss(3.0f);
        const hkQuadReal zero = _mm_set_ss(0.0f);
        const hkQuadReal len2 = this->dot3(*this).getQuad();
        const hkQuadReal len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const hkQuadReal approx = _mm_rsqrt_ss(len2);
        const hkQuadReal refined =
            _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize3()
    {
        hkQuadReal lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    __forceinline hkReal& operator()(int a)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[a];
    }
    hkQuadReal m_vComponents;
};

class hkQuaternion
{
  public:
    __forceinline hkQuaternion()
    {}
    void FUN_00cb2450(const hkVector4& axis, hkReal angle);
    hkVector4 m_vec;
};

class hkMatrix3
{
  public:
    __forceinline hkMatrix3()
    {}
    __forceinline hkVector4& getColumn(int x)
    {
        return (&m_kColumn0)[x];
    }
    __forceinline const hkVector4& getColumn(int x) const
    {
        return (&m_kColumn0)[x];
    }
    __forceinline hkReal& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }
    __forceinline void operator=(const hkMatrix3& a)
    {
        m_kColumn0 = a.getColumn(0);
        m_kColumn1 = a.getColumn(1);
        m_kColumn2 = a.getColumn(2);
    }
    __forceinline void setZero()
    {
        hkVector4 zero;
        zero.setZero4();
        getColumn(0) = zero;
        getColumn(1) = zero;
        getColumn(2) = zero;
    }
    __forceinline void setIdentity()
    {
        setZero();
        hkReal one = 1.0f;
        (*this)(0, 0) = one;
        (*this)(1, 1) = one;
        (*this)(2, 2) = one;
    }
    void Multiply(hkSimdRealParameter s);
    hkVector4 m_kColumn0, m_kColumn1, m_kColumn2;
};
class hkRotation : public hkMatrix3
{
  public:
    void FUN_00cb2d90(const hkQuaternion& q);
};
class hkTransform
{
  public:
    __forceinline hkTransform()
    {}
    __forceinline void setTranslation(const hkVector4& t)
    {
        m_vTranslation = t;
    }
    __forceinline void SetBodyOrientation(const hkQuaternion& q)
    {
        m_rotation.FUN_00cb2d90(q);
    }
    __forceinline void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};

struct hkpMassProperties
{
    __forceinline hkpMassProperties() : m_iBufferSize(0.0f), m_fViscosityFriction(0.0f)
    {
        m_kCenterOfMass1.setZero4();
        m_kInertiaTensor.setZero();
    }
    hkReal m_iBufferSize;
    hkReal m_fViscosityFriction;
    hkVector4 m_kCenterOfMass1;
    hkMatrix3 m_kInertiaTensor;
};
struct MassPropertiesTransform
{
    __forceinline MassPropertiesTransform()
    {
        m_kMotionTransform.setIdentity();
    }
    hkpMassProperties m_kProperties;
    hkTransform m_kMotionTransform;
};

struct RouterHeapAllocatorProvider
{
    __forceinline S_00cee1c0_Heap& get(const void*)
    {
        return S00cf0f40_heap(FUN_00c85750());
    }
};

template <typename T> class HavokElementArray
{
  public:
    __forceinline HavokElementArray(T* ptr, int size, int capacity)
        : m_data(ptr), m_iElementCount(size), m_iCapacityState(capacity | 0x80000000)
    {}
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void clear()
    {
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(S_00cee1c0_Heap& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.Free(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline T& _expandOne(S_00cee1c0_Heap& alloc)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        T* t = m_data + m_iElementCount;
        for (int i = 0; i < 1; ++i)
            ::new (t + i) T;
        return m_data[m_iElementCount++];
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T> class hkArray : public HavokElementArray<T>
{
  public:
    __forceinline hkArray(T* ptr, int size, int capacity) : HavokElementArray<T>(ptr, size, capacity)
    {}
    __forceinline ~hkArray()
    {
        ClearAndRelease();
    }
    __forceinline void ClearAndRelease()
    {
        this->_clearAndDeallocate(RouterHeapAllocatorProvider().get(this));
    }
    __forceinline T& AllocatePair()
    {
        return this->_expandOne(RouterHeapAllocatorProvider().get(this));
    }
};
template <typename T, unsigned N> class hkInplaceArray : public hkArray<T>
{
  public:
    __forceinline explicit hkInplaceArray(int size = 0) : hkArray<T>(m_kStorage, size, N)
    {}
    __forceinline ~hkInplaceArray()
    {}
    T m_kStorage[N];
};

extern const hkVector4 DAT_01268390;
float __cdecl ClampedAcos(float);
int __cdecl FUN_00ced090(const hkArray<MassPropertiesTransform>& elements, hkpMassProperties& result);
namespace MathUtilities {
__forceinline hkReal fabs(hkReal r)
{
    return ::fabsf(r);
}
}

// @fnv 0x00cef6d0
__declspec(noinline) int __cdecl FUN_00cef6d0(const hkVector4& startAxis, const hkVector4& endAxis, hkReal radius,
                                              hkReal mass, hkpMassProperties& result)
{
    if (!(mass <= 0.0f))
    {
        if (radius <= 0.0f)
            return 1;
        hkVector4 axis;
        axis.setSub4(endAxis, startAxis);
        const hkReal height = axis.length3();
        hkTransform cylinderBaseTransform;
        if (height > 0.0f)
        {
            axis.normalize3();
            hkVector4 canonicalZ(DAT_01268390);
            if (MathUtilities::fabs(axis.dot3(canonicalZ)) < 0.99999f)
            {
                hkVector4 rotAxis;
                rotAxis.setCross(canonicalZ, axis);
                rotAxis.normalize3();
                hkQuaternion q;
                q.FUN_00cb2450(rotAxis, ClampedAcos(axis.dot3(canonicalZ)));
                cylinderBaseTransform.SetBodyOrientation(q);
            }
            else
            {
                cylinderBaseTransform.setIdentity();
            }
            hkVector4 centre;
            centre.setAdd4(startAxis, endAxis);
            centre.mul4(0.5f);
            cylinderBaseTransform.setTranslation(centre);
            const hkReal volume = (hkReal)(3.1415927410125732421875 * radius * radius * height);
            const hkReal massCopy = mass;
            hkInplaceArray<MassPropertiesTransform, 1> elements(0);
            MassPropertiesTransform& el = elements.AllocatePair();
            el.m_kMotionTransform = cylinderBaseTransform;
            el.m_kProperties.m_kCenterOfMass1.set(0.0f, 0.0f, 0.0f, 0.0f);
            el.m_kProperties.m_kInertiaTensor.setIdentity();
            el.m_kProperties.m_kInertiaTensor(0, 0) =
                (hkReal)(radius * radius * 0.25 + height / 2.0 * height / 2.0 / 3.0);
            el.m_kProperties.m_kInertiaTensor(1, 1) = el.m_kProperties.m_kInertiaTensor(0, 0);
            el.m_kProperties.m_kInertiaTensor(2, 2) = (hkReal)(radius * radius * 0.5);
            el.m_kProperties.m_kInertiaTensor.Multiply(massCopy);
            el.m_kProperties.m_kCenterOfMass1.setZero4();
            el.m_kProperties.m_iBufferSize = volume;
            el.m_kProperties.m_fViscosityFriction = massCopy;
            FUN_00ced090(elements, result);
            return 0;
        }
    }
    return 1;
}
