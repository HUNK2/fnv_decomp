
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkphingelimitsdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
} __m128;

extern "C"
{
    __m128 __cdecl _mm_add_ps(__m128, __m128);
    __m128 __cdecl _mm_mul_ps(__m128, __m128);
    __m128 __cdecl _mm_load_ss(const float*);
    __m128 __cdecl _mm_shuffle_ps(__m128, __m128, int);
    void __cdecl _mm_store_ps(float*, __m128);
}

static __forceinline __m128 splat(const float& f)
{
    __m128 t = _mm_load_ss(&f);
    return _mm_shuffle_ps(t, t, 0);
}

static __forceinline __m128 splatRounded(double f)
{
    float scalar = (float)f;
    __m128 t = _mm_load_ss(&scalar);
    return _mm_shuffle_ps(t, t, 0);
}

struct Visitor
{
    void** vt;
};

struct Src
{
    int u00;
    int u04;
    int u08;
    unsigned char* m0c;
};

struct Mat4
{
    __m128 r0, r1, r2, r3;
};
struct Mat3
{
    __m128 r0, r1, r2;
};

struct Vec
{
    __m128 v;
    void FUN_00c7f640(Mat4* m, void* p);
    void FUN_00c7f700(Mat3* m, void* p);
};

struct Holder
{
    void* p;
    void FUN_00e10a10(Visitor* a);
};

extern const double DAT_0106d4c8;

struct T
{
    float f00;
    float u04, u08, u0c, u10, u14, u18;
    float f1c;
    __m128 m20;
    __m128 m30;
    Vec m40;
    Vec m50;
    Mat3 m60;
    Mat3 m90;
    Holder mc;
    void FUN_00de47e0(Src* a, Mat4* b, Mat4* c);
    void FUN_00de44c0(int a, int b);
    void FUN_00de4530(int a, int b);
    void FUN_00de6d80(Src* a1, Visitor* a2, int a3, int a4);
};

int __cdecl PackColorBigEndian(float a, float b, float c, float d);

typedef void(__thiscall* DrawFn)(Visitor*, void*, void*, int, int, int);

// @fnv 0x00de6d80
void T::FUN_00de6d80(Src* a1, Visitor* a2, int a3, int a4)
{
    struct Work
    {
        Vec va;
        Vec vb;
        Mat4 matA;
        Mat4 matB;
        __m128 buf[12];
    } w;
    unsigned char* e = a1->m0c;
    mc.FUN_00e10a10(a2);
    FUN_00de47e0(a1, &w.matA, &w.matB);
    m50.FUN_00c7f640(&w.matA, e + 0x90);
    m40.FUN_00c7f640(&w.matB, e + 0x50);
    FUN_00de44c0(a3, a4);
    FUN_00de4530(a3, a4);
    w.vb.FUN_00c7f700(&m90, e + ((((int)e[0xa2] + 1) % 3) + 6) * 16);
    w.va.FUN_00c7f700(&m90, e + ((((int)e[0xa2] + 2) % 3) + 6) * 16);
    float s = f1c * f00;
    float t = s;
    float sd = s + t;
    float s2 = (float)(DAT_0106d4c8 * s);
    __m128 base = m50.v;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            __m128 x = i ? w.vb.v : w.va.v;
            __m128* __restrict ptry = i ? &w.va.v : &w.vb.v;
            __m128 y = *ptry;
            __m128* p = &w.buf[i * 6 + (j + 1) * 2 + 1];
            _mm_store_ps((float*)(p - 1), base);
            _mm_store_ps((float*)p, base);
            float ty = (float)((double)j * 1.4f * s);
            _mm_store_ps((float*)(p - 1), _mm_add_ps(_mm_mul_ps(splat(sd), x), p[-1]));
            _mm_store_ps((float*)p, _mm_add_ps(_mm_mul_ps(splat(s2), x), p[0]));
            _mm_store_ps((float*)(p - 1), _mm_add_ps(_mm_mul_ps(splatRounded(ty), y), p[-1]));
            _mm_store_ps((float*)p, _mm_add_ps(_mm_mul_ps(splatRounded(ty), y), p[0]));
        }
    }
    __m128* q = w.buf;
    int n = 6;
    do
    {
        DrawFn* slot = (DrawFn*)&a2->vt[9];
        (*slot)(a2, q, q + 1, PackColorBigEndian(0.8f, 0.8f, 0.8f, 1.0f), a3, a4);
        q += 2;
    } while (--n);
    DrawFn* slot = (DrawFn*)&a2->vt[9];
    (*slot)(a2, &m40, &m20, PackColorBigEndian(0.3f, 0.3f, 0.8f, 1.0f), a3, a4);
}
