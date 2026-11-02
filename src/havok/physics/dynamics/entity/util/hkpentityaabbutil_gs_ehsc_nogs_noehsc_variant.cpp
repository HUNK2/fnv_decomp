
// src/havok/physics/dynamics/entity/util/hkpentityaabbutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/entity/util/hkpentityaabbutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/entity/util/hkpentityaabbutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/entity/util/hkpentityaabbutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct S_00d1b1d0_Item {
    unsigned int m_key;
    int m_uiFilterValue;
};
struct S_00d1b1d0_Less {
    bool operator()(const S_00d1b1d0_Item& a, const S_00d1b1d0_Item& b) const { return a.m_key < b.m_key; }
};
template <typename T>
__forceinline void S_00d1b1d0_swap(T& x, T& y)
{
    __declspec(align(16)) T t(x);
    x = y;
    y = t;
}
void FUN_00d1b1d0(S_00d1b1d0_Item* pItems, int iLow, int iHigh, S_00d1b1d0_Less cmpLess);
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
