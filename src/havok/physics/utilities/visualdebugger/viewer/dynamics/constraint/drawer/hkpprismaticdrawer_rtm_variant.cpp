
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprismaticdrawer_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprismaticdrawer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprismaticdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpprismaticdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    };
};
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);

static __forceinline __m128 addScaled(__m128 base, __m128 dir, double d)
{
    float x = (float)d;
    __m128 s = _mm_load_ss(&x);
    return _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s, s, 0), dir), base);
}

struct Vec
{
    __m128 value;
    void FUN_00c7f640(const void*, const Vec*);
    void FUN_00c7f700(const void*, const Vec*);
};
struct Matrix
{
    Vec col0, col1, col2, col3;
};
struct Shape
{
    int unk000, unk004, unk008, unk00c;
    int unk010, unk014, unk018, unk01c;
    int unk020, unk024, unk028, unk02c;
    int unk030, unk034, unk038, unk03c;
    int unk040, unk044, unk048, unk04c;
    Vec unk050, unk060, unk070, unk080, unk090, unk0a0, unk0b0;
    float unk0c0, unk0c4, unk0c8, unk0cc;
};
struct Input
{
    int unk000, unk004, unk008;
    Shape* unk00c;
};
struct Draw
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void line(const Vec*, const Vec*, unsigned int, int, int);
};
struct Member
{
    void FUN_00e10a10(Draw*);
};
struct Simulation
{
    float unk000, unk004, unk008, unk00c;
    float unk010, unk014, unk018, unk01c;
    float unk020, unk024, unk028, unk02c;
    float unk030, unk034, unk038, unk03c;
    Vec unk040, unk050, unk060, unk070, unk080, unk090, unk0a0, unk0b0;
    Member unk0c0;
    void FUN_00de47e0(Input*, Matrix*, Matrix*);
    void FUN_00de44c0(int, int);
    void FUN_00de4530(int, int);
    void FUN_00de7730(Input*, Draw*, int, int);
};
extern "C" unsigned int __cdecl PackColorBigEndian(float, float, float, float);

// @fnv 0x00de7730
void Simulation::FUN_00de7730(Input* input, Draw* draw, int a, int b)
{
    Shape* shape = input->unk00c;
    unk0c0.FUN_00e10a10(draw);
    Matrix transform0, transform1;
    FUN_00de47e0(input, &transform0, &transform1);
    unk050.FUN_00c7f640(&transform0, &shape->unk090);
    unk040.FUN_00c7f640(&transform1, &shape->unk050);
    FUN_00de44c0(a, b);
    FUN_00de4530(a, b);
    Vec dir0, dir1;
    dir0.FUN_00c7f700(&unk090, &shape->unk060);
    dir1.FUN_00c7f700(&unk090, &shape->unk070);
    draw->line(&unk040, &unk050, 0xffff0000, a, b);
    Vec from, to;
    if (shape->unk0cc != 3.402820018375656e38)
    {
        float x0 = (float)(double)shape->unk0cc;
        __m128 s0 = _mm_load_ss(&x0);
        float x1 = (float)(double)shape->unk0c8;
        from.value = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s0, s0, 0), dir0.value), unk050.value);
        __m128 s1 = _mm_load_ss(&x1);
        to.value = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s1, s1, 0), dir0.value), unk050.value);
        draw->line(&to, &from, PackColorBigEndian(0.0f, 0.5f, 1.0f, 1.0f), a, b);
    }
    else
    {
        float limit = unk01c * unk000;
        from.value = addScaled(unk050.value, dir0.value, limit);
        to.value = addScaled(unk050.value, dir0.value, -limit);
        draw->line(&to, &from, PackColorBigEndian(0.0f, 0.5f, 1.0f, 1.0f), a, b);
    }
    __m128 centre = addScaled(unk050.value, dir0.value, shape->unk0c8);
    float other = shape->unk0cc;
    float scale = unk01c * unk000;
    from.value = addScaled(centre, dir1.value, 0.5 * scale);
    to.value = addScaled(centre, dir1.value, -0.5 * scale);
    draw->line(&from, &to, 0xffffffff, a, b);
    __m128 s = _mm_load_ss(&other);
    centre = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s, s, 0), dir0.value), unk050.value);
    scale = unk01c * unk000;
    from.value = addScaled(centre, dir1.value, 0.5 * scale);
    to.value = addScaled(centre, dir1.value, -0.5 * scale);
    draw->line(&from, &to, 0xffffffff, a, b);
}
