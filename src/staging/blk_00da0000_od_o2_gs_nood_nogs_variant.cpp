
// src/staging/blk_00da0000_od_o2_gs_nood_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00da0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00da0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct __declspec(align(16)) hkVector4DA0
{
    __m128 m_vComponents;
};

struct hkTransformDA0
{
    hkVector4DA0 m_kColumn0;
    hkVector4DA0 m_kColumn1;
    hkVector4DA0 m_kColumn2;
    hkVector4DA0 m_vTranslation;
};

struct hkArrayDA0
{
    hkVector4DA0* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

// @fnv 0x00da0ce0
void __cdecl FUN_00da0ce0(const hkTransformDA0& t, hkArrayDA0& points)
{
    for (int i = 0; i < points.m_iElementCount; i++)
    {
        __m128 v = points.m_data[i].m_vComponents;
        __m128 r = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), t.m_kColumn1.m_vComponents),
                              _mm_mul_ps(_mm_shuffle_ps(v, v, 0), t.m_kColumn0.m_vComponents));
        r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), t.m_kColumn2.m_vComponents));
        points.m_data[i].m_vComponents = _mm_add_ps(r, t.m_vTranslation.m_vComponents);
    }
}
