
// src/staging/blk_00dc0000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00dc0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00dc0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
#include <math.h>
inline void* __cdecl operator new(unsigned int, void* location) throw()
{
    return location;
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};
struct hkVector4
{
    __m128 m_vComponents;
};

struct VectorComponentValue
{
    __m128 m_vValue;
    VectorComponentValue(__m128 x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct Contact
{
    hkVector4 m_kPoint;
    hkVector4 m_vHitNormal;
};

struct MemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* m_pStreamAllocator;
};

extern MemoryRouter* __cdecl FUN_00c85750() throw();
extern void __cdecl ResizeAudioStream(void* heap, void* array, int elemSize) throw();

template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void AddBack(const T& t)
    {
        MemoryRouter* router = FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pStreamAllocator, this, sizeof(T));
        new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
};

extern int __cdecl FUN_00dd6380(hkArray<hkVector4>* planes, int skip1, int skip2, int plane, Contact* contact);

extern float DAT_0104da48;
extern float DAT_0109afc4;
extern double DAT_01032980;
extern __m128 DAT_010c7160;

// @fnv 0x00dd66d0
hkBool __cdecl FUN_00dd66d0(const hkVector4* direction, hkArray<hkVector4>* planes, int skip1, int skip2,
                            hkVector4* position, hkArray<Contact>* contacts)
{
    float best = DAT_0104da48;
    bool found = false;
    for (int i = 0; i < planes->m_iElementCount; i++)
    {
        if (i == skip1 || i == skip2)
            continue;
        __m128 products = _mm_mul_ps(planes->m_data[i].m_vComponents, direction->m_vComponents);
        __m128 denomv = _mm_add_ss(_mm_shuffle_ps(products, products, 0xaa),
                                   _mm_add_ss(_mm_shuffle_ps(products, products, 0x55), products));
        float denom = VectorComponentValue(denomv);
        if (DAT_0109afc4 < denom)
        {
            position->m_vComponents.m128_f32[3] = 1.0f;
            __m128 dot = _mm_mul_ps(planes->m_data[i].m_vComponents, position->m_vComponents);
            __m128 sum = _mm_add_ps(_mm_shuffle_ps(dot, dot, 0x4e), dot);
            sum = _mm_add_ps(_mm_shuffle_ps(sum, sum, 0xb1), sum);
            float num = VectorComponentValue(_mm_sub_ss(DAT_010c7160, sum));
            float absDenom = (float)fabs(denom);
            float dist = num / absDenom;
            if (dist < best + DAT_01032980)
            {
                Contact contact;
                if (FUN_00dd6380(planes, skip1, skip2, i, &contact) == 0)
                {
                    found = true;
                    float diff = dist - best;
                    if ((float)fabs(diff) < DAT_01032980)
                    {
                        contacts->AddBack(contact);
                    }
                    else
                    {
                        contacts->m_iElementCount = 0;
                        contacts->AddBack(contact);
                        best = dist;
                    }
                }
            }
        }
    }
    return found;
}

extern "C" void __cdecl Atan2(float, float);

static inline float Dot3(__m128 a, __m128 b)
{
    __m128 v = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    float f;
    _mm_store_ss(&f, _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), s));
    return f;
}

// @fnv 0x00ddd5a0
void __cdecl FUN_00ddd5a0(const float* a, const float* b, const float* c)
{
    __m128 scale = _mm_load_ps(c);
    float fB = Dot3(_mm_load_ps(b), scale);
    float fA = Dot3(_mm_load_ps(a), scale);
    Atan2(fB, fA);
}

extern __m128 DAT_010c44d0;

struct S00dd2fd0_cls
{
    __m128 m_00;
};

// @fnv 0x00dd2fd0
static __declspec(noinline) void FUN_00dd2fd0(S00dd2fd0_cls* self, __m128* out, __m128* a1, __m128* a2)
{
    __m128 d = _mm_sub_ps(*a1, self->m_00);
    __m128 r = _mm_rcp_ps(d);
    __m128 t = _mm_mul_ps(_mm_mul_ps(r, d), r);
    r = _mm_sub_ps(_mm_add_ps(r, r), t);
    *a2 = _mm_mul_ps(*a1, r);
    *out = _mm_mul_ps(self->m_00, r);
    *out = _mm_xor_ps(*out, DAT_010c44d0);
}

void S00dd2fd0_wrap(S00dd2fd0_cls* self, __m128* out, __m128* a1, __m128* a2)
{
    FUN_00dd2fd0(self, out, a1, a2);
}
