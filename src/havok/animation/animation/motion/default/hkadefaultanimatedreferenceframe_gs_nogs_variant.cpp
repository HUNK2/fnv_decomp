// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00e41080_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    float unk30;

    float __thiscall GetUnk30();
};
#include <xmmintrin.h>
struct E41090Vector4
{
    __m128 m_vComponents;

    void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};
struct E41090Bool
{
    char m_cBooleanValue;
    E41090Bool& operator=(bool b)
    {
        m_cBooleanValue = (char)b;
        return *this;
    }
};
struct FUN_00e41090
{
    FUN_00e41090();

    int unk00;
    int unk04;
    float unk08;
    int unk0C;
    E41090Bool unk10;
    E41090Bool unk11;
    E41090Bool unk12;
    E41090Bool unk13;
    int unk14;
    int unk18;
    int unk1C;
    E41090Vector4 m_vStart;
    E41090Vector4 m_vEnd;
};

#include <math.h>
struct VectorComponentValue
{
    __m128 v;
    VectorComponentValue(__m128 x) : v(x)
    {}
    float getReal() const
    {
        float f;
        _mm_store_ss(&f, v);
        return f;
    }
};
struct hkVector4
{
    __m128 v;
    VectorComponentValue dot3(const hkVector4& a) const
    {
        __m128 m = _mm_mul_ps(v, a.v);
        __m128 y = _mm_shuffle_ps(m, m, 0x55);
        __m128 xy = _mm_add_ss(y, m);
        __m128 z = _mm_shuffle_ps(m, m, 0xaa);
        return VectorComponentValue(_mm_add_ss(z, xy));
    }
    void setCross(const hkVector4& a, const hkVector4& b)
    {
        __m128 ayzx = _mm_shuffle_ps(a.v, a.v, 0xc9);
        __m128 bzxy = _mm_shuffle_ps(b.v, b.v, 0xd2);
        __m128 azxy = _mm_shuffle_ps(a.v, a.v, 0xd2);
        __m128 byzx = _mm_shuffle_ps(b.v, b.v, 0xc9);
        v = _mm_sub_ps(_mm_mul_ps(ayzx, bzxy), _mm_mul_ps(azxy, byzx));
    }
};
struct hkQuaternion
{
    __m128 v;
    void FUN_00c74ac0(const void* a, const void* b) throw();
};

__declspec(noinline) void hkQuaternion::FUN_00c74ac0(const void* pa, const void* pb) throw()
{
    const __m128 a = ((const hkQuaternion*)pa)->v;
    const __m128 b = ((const hkQuaternion*)pb)->v;
    __m128 xyz = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)),
                            _mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)));
    __m128 aw = _mm_shuffle_ps(a, a, 0xff);
    aw = _mm_shuffle_ps(aw, aw, 0);
    xyz = _mm_sub_ps(xyz, _mm_mul_ps(aw, b));
    __m128 bw = _mm_shuffle_ps(b, b, 0xff);
    bw = _mm_shuffle_ps(bw, bw, 0);
    xyz = _mm_add_ps(xyz, _mm_mul_ps(bw, a));
    __m128 prod = _mm_mul_ps(a, b);
    __m128 half = _mm_add_ps(_mm_shuffle_ps(prod, prod, 0x4e), prod);
    __m128 dot = _mm_add_ps(_mm_shuffle_ps(half, half, 0xb1), half);
    dot = _mm_shuffle_ps(dot, dot, 0);
    __m128 upper = _mm_unpackhi_ps(xyz, dot);
    v = _mm_shuffle_ps(xyz, upper, 0xc4);
}

struct hkTransform
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
};
struct hkMemoryAllocator
{
    int unk00;
};
extern "C" void __cdecl FUN_00c908c0(hkMemoryAllocator* mem, void* arr, int newCap, int elemSize) throw();
template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator& a, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&a, this, newSize, sizeof(T));
        }
    }
};
struct Config
{
    const hkTransform* m_kTransforms;
    int m_numQsTransforms;
    float m_fAnimationDuration;
    int m_iValueAfterAnimationDuration;
    bool m_unk10;
    bool m_unk11;
    bool m_unk12;
    bool m_bFlag13;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_vStart;
    hkVector4 m_vEnd;
};
class hkOstream
{
    void* m_ppVirtualMethodTable;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;

  public:
    void FUN_00cb1600(void* buf, int bufLen) throw();
    void FUN_00cc00e0() throw();
    hkOstream& FUN_00cc01c0(const char* str) throw();
    hkOstream& WriteFloat(float val) throw();
    hkOstream(void* buf, int len) throw()
    {
        FUN_00cb1600(buf, len);
    }
    ~hkOstream() throw()
    {
        FUN_00cc00e0();
    }
    hkOstream& operator<<(const char* str) throw()
    {
        return FUN_00cc01c0(str);
    }
    hkOstream& operator<<(float val) throw()
    {
        return WriteFloat(val);
    }
};
class hkError
{
  public:
    virtual ~hkError() throw();
    virtual void unk1() throw();
    virtual void unk2() throw();
    virtual void message(int type, unsigned int id, const char* desc, const char* file, int line) throw();
};
extern hkError* DAT_01268360;
extern int DAT_01268700;
extern int DAT_010e57a4;
extern const char DAT_010ebe28[], DAT_010ebdec[], DAT_010ebdcc[], DAT_01012630[], DAT_010ebde0[], DAT_010ebd70[];
extern "C" void __cdecl FUN_00e41220(const Config* cfg, const void* v1, void* outV, const void* v2) throw();
extern "C" void __cdecl FUN_00e41bf0(void* outTransform, float time, const hkTransform* transforms, int numTransforms,
                                     float duration) throw();
struct MemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    hkMemoryAllocator* m_pStreamAllocator;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" MemoryRouter* __cdecl FUN_00c85750() throw();
extern "C" void __cdecl FUN_00c908c0(hkMemoryAllocator* mem, void* arr, int newCap, int elemSize) throw();
struct QuatHelper
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
};
class FUN_00e41830
{
  public:
    int* m_ppVirtualMethodTable;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_unk08;
    int m_unk0C;
    hkVector4 m_vStart;
    hkVector4 m_vEnd;
    float m_fAnimationDuration;
    hkArray<hkVector4> m_kAnimationVectorSamples;
    FUN_00e41830(const Config& config) throw();
};
static __forceinline float dot3(__m128 a, __m128 b)
{
    __m128 m = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(m, m, 0x55);
    __m128 m_plus_y = _mm_add_ss(y, m);
    __m128 z = _mm_shuffle_ps(m, m, 0xaa);
    __m128 res = _mm_add_ss(z, m_plus_y);
    float out;
    _mm_store_ss(&out, res);
    return out;
}
static __forceinline __m128 cross(const __m128& a, const __m128& b)
{
    __m128 a_yzx = _mm_shuffle_ps(a, a, 0xc9);
    __m128 b_zxy = _mm_shuffle_ps(b, b, 0xd2);
    __m128 a_zxy = _mm_shuffle_ps(a, a, 0xd2);
    __m128 b_yzx = _mm_shuffle_ps(b, b, 0xc9);
    return _mm_sub_ps(_mm_mul_ps(a_yzx, b_zxy), _mm_mul_ps(a_zxy, b_yzx));
}
static __forceinline float my_fabs(float f)
{
    return fabsf(f);
}

struct AngleRotation
{
    __m128 value;
    int FUN_00cb2ca0(const hkVector4* axis, hkVector4* rest, float* angle) throw();
};
static __forceinline __m128 projectAxis(__m128 value, __m128 axis)
{
    __m128 mul = _mm_mul_ps(value, axis);
    __m128 lo = _mm_add_ss(_mm_shuffle_ps(mul, mul, 0x55), mul);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(mul, mul, 0xaa), lo);
    return _mm_mul_ps(_mm_shuffle_ps(sum, sum, 0), axis);
}
extern "C" __declspec(noinline) void __cdecl FUN_00e41220(const Config* cfg, const void* transform, void* prev,
                                                          const void* output) throw()
{
    const hkTransform* pose = (const hkTransform*)transform;
    hkVector4* result = (hkVector4*)output;
    __m128 up = projectAxis(pose->m_vTranslation.v, cfg->m_vStart.v);
    __m128 side = projectAxis(pose->m_vTranslation.v, cross(cfg->m_vStart.v, cfg->m_vEnd.v));
    __m128 front = projectAxis(pose->m_vTranslation.v, cfg->m_vEnd.v);
    result->v = _mm_setzero_ps();
    if (cfg->m_unk11)
        result->v = _mm_add_ps(result->v, front);
    if (cfg->m_unk10)
        result->v = _mm_add_ps(result->v, up);
    if (cfg->m_unk12)
        result->v = _mm_add_ps(result->v, side);
    if (cfg->m_bFlag13)
    {
        hkVector4 rest;
        float angle;
        ((AngleRotation*)&pose->m_rotation)->FUN_00cb2ca0(&cfg->m_vStart, &rest, &angle);
        float previous = ((const hkVector4*)prev)->v.m128_f32[3];
        while (angle - previous > double(3.14159265358979323846f))
            angle -= double(6.28318530717958647692f);
        while (angle - previous < -double(3.14159265358979323846f))
            angle += double(6.28318530717958647692f);
        result->v.m128_f32[3] = angle;
    }
    else
        result->v.m128_f32[3] = 0.0f;
}

// @fnv 0x00e41830
FUN_00e41830::FUN_00e41830(const Config& config) throw() : m_ppVirtualMethodTable(&DAT_010e57a4), m_sReferenceCount(1)
{
    int numSamples =
        config.m_iValueAfterAnimationDuration == -1 ? config.m_numQsTransforms : config.m_iValueAfterAnimationDuration;
    hkArray<hkVector4>& samples = m_kAnimationVectorSamples;
    m_vStart.v = config.m_vStart.v;
    m_vEnd.v = config.m_vEnd.v;
    float duration = config.m_fAnimationDuration;
    m_fAnimationDuration = duration;
    float dt = duration / (float)(numSamples - 1);
    hkVector4 tempV0;
    hkTransform startTransform;
    startTransform.m_vTranslation.v = config.m_kTransforms[0].m_vTranslation.v;
    startTransform.m_rotation.v = config.m_kTransforms[0].m_rotation.v;
    startTransform.m_vScale.v = config.m_kTransforms[0].m_vScale.v;
    {
        hkVector4 outV0;
        tempV0.v = _mm_setzero_ps();
        FUN_00e41220(&config, &DAT_01268700, &tempV0, &outV0);
        tempV0.v = outV0.v;
    }
    if (config.m_bFlag13)
    {
        float dotForward = my_fabs(config.m_vEnd.dot3(tempV0).getReal());
        hkVector4 cr;
        cr.v = cross(config.m_vStart.v, config.m_vEnd.v);
        float dotSide = my_fabs(cr.dot3(tempV0).getReal());
        if (dotForward > 0.01f || dotSide > 0.01f)
        {
            {
                char buf[512];
                hkOstream os(buf, 512);
                os.FUN_00cc01c0(DAT_010ebe28);
                DAT_01268360->message(1, 0xabba9245, (const char*)buf, DAT_010ebdec, 88);
            }
            {
                char buf[512];
                hkOstream os(buf, 512);
                os.FUN_00cc01c0(DAT_010ebdcc)
                    .WriteFloat(dotForward)
                    .FUN_00cc01c0(DAT_01012630)
                    .WriteFloat(dotSide)
                    .FUN_00cc01c0(DAT_010ebde0);
                DAT_01268360->message(1, 0xabba9245, (const char*)buf, DAT_010ebdec, 89);
            }
            {
                char buf[512];
                hkOstream os(buf, 512);
                os.FUN_00cc01c0(DAT_010ebd70);
                DAT_01268360->message(1, 0xabba9245, (const char*)buf, DAT_010ebdec, 90);
            }
        }
    }
    hkMemoryAllocator& mem = FUN_00c85750()->heap();
    const int cap = samples.m_iCapacityState & 0x3fffffff;
    if (cap < numSamples)
    {
        int newCap = cap + cap;
        if (numSamples >= newCap)
        {
            newCap = numSamples;
        }
        FUN_00c908c0(&mem, &samples, newCap, sizeof(hkVector4));
    }
    samples.m_iElementCount = numSamples;
    for (int i = 0; i < numSamples; ++i)
    {
        __m128 unitScale = _mm_set1_ps(1.0f);
        float time = (float)i * dt;
        hkTransform curTransform;
        FUN_00e41bf0(&curTransform, time, config.m_kTransforms, config.m_numQsTransforms, config.m_fAnimationDuration);
        QuatHelper qh;
        qh.m_rotation.FUN_00c74ac0(&curTransform.m_rotation, &startTransform.m_rotation);
        qh.m_vTranslation.v = _mm_sub_ps(curTransform.m_vTranslation.v, startTransform.m_vTranslation.v);
        qh.m_vScale.v = unitScale;
        hkVector4 sampleOut;
        FUN_00e41220(&config, &qh, &tempV0, &sampleOut);
        __m128 sample = sampleOut.v;
        samples.m_data[i].v = sample;
        tempV0.v = sample;
    }
}
