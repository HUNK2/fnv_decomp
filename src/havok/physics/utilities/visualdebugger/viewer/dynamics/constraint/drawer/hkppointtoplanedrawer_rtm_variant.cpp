
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppointtoplanedrawer_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppointtoplanedrawer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppointtoplanedrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkppointtoplanedrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>

struct B_00de7580
{
    __m128 unk00;
    __m128 unk10;
    __m128 unk20;
    __m128 unk30;
    unsigned int unk40;
    float unk44;
};

struct Arg_00de7580
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    B_00de7580* unk0c;
};

__declspec(align(16)) struct V4_00de7580
{
    float x;
    float y;
    float z;
    float w;
};

struct Transform_00de7580
{
    V4_00de7580 column0;
    V4_00de7580 column1;
    V4_00de7580 column2;
    V4_00de7580 column3;
};

struct Vec4_00de7580
{
    __m128 unk00;
    void FUN_00c7f640(Transform_00de7580* a1, __m128* a2);
};

struct Render_00de7580
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void draw(void*, void*, void*, int, int);
};

struct FUN_00e10a10_Obj
{
    void FUN_00e10a10(Render_00de7580* a1);
};

typedef void(__thiscall* VF5_00de7580)(void* self, void* p1, void* p2, void* p3, int p4, int p5);

__m128* PackColorBigEndian(float a, float b, float c, float d);

struct ArgHolder_00de7580
{
    Arg_00de7580* const value;
};

struct FUN_00de7580_cls
{
    __m128 unk00;
    __m128 unk10;
    __m128 unk20;
    __m128 unk30;
    Vec4_00de7580 unk40;
    Vec4_00de7580 unk50;
    __m128 unk60;
    __m128 unk70;
    __m128 unk80;
    __m128 unk90;
    __m128 unkA0;
    __m128 unkB0;
    FUN_00e10a10_Obj unkC0;

    void FUN_00de47e0(Arg_00de7580* a1, Transform_00de7580* a2, Transform_00de7580* a3);
    void FUN_00de44c0(int a1, int a2);
    void FUN_00de4530(int a1, int a2);
    void FUN_00de7580(ArgHolder_00de7580 a1, Render_00de7580* a2, int a3, int a4);
};

// @fnv 0x00de7580
void FUN_00de7580_cls::FUN_00de7580(ArgHolder_00de7580 a1, Render_00de7580* a2, int a3, int a4)
{
    Transform_00de7580 v44;
    Transform_00de7580 v80;
    V4_00de7580 result;
    B_00de7580* b = a1.value->unk0c;

    unkC0.FUN_00e10a10(a2);
    FUN_00de47e0(a1.value, &v44, &v80);
    unk50.FUN_00c7f640(&v44, &b->unk30);
    unk40.FUN_00c7f640(&v80, &b->unk20);
    FUN_00de44c0(a3, a4);
    FUN_00de4530(a3, a4);

    float t = b->unk44;
    __m128 d = _mm_sub_ps(unk50.unk00, unk40.unk00);
    __m128 sq = _mm_mul_ps(d, d);
    __m128 len2 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    len2 = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), len2);
    __m128 inv = _mm_rsqrt_ss(len2);
    __m128 xi = _mm_mul_ss(_mm_mul_ss(len2, inv), inv);
    __m128 yy = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), inv), _mm_sub_ss(_mm_set_ss(3.0f), xi));
    __m128 mask = _mm_cmpeq_ss(len2, _mm_set_ss(0.0f));
    __m128 s = _mm_andnot_ps(mask, yy);
    __m128 sv = _mm_shuffle_ps(s, s, 0);
    __m128 nrm = _mm_mul_ps(sv, d);
    _mm_store_ps(&result.x, nrm);
    __m128 tv = _mm_load_ss(&t);
    tv = _mm_shuffle_ps(tv, tv, 0);
    __m128 res = _mm_add_ps(unk40.unk00, _mm_mul_ps(tv, _mm_load_ps(&result.x)));

    _mm_store_ps(&result.x, res);
    a2->draw(&unk40, &result, PackColorBigEndian(0.0f, 0.5f, 1.0f, 1.0f), a3, a4);
    a2->draw(&result, &unk50, (void*)0xffff0000, a3, a4);
}
