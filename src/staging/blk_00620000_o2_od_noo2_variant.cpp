
// src/staging/blk_00620000_o2_od_noo2_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy (unit src/staging/blk_00620000_o2.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00620000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

#include <xmmintrin.h>
struct Vec16
{
    __m128 unk00;
    void FUN_00628cc0(Vec16* a, Vec16* b);
    int FUN_00458990(int flags);
};

struct Sub16
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void FUN_00458a60(Vec16* out, void* other);
};

struct FUN_00628d10_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Sub16 m_sub;
    void FUN_00458a60(Vec16* out, void* other);
    void FUN_00622570(bool flag);
    FUN_00628d10_cls* FUN_00628d10(FUN_00628d10_cls* a, FUN_00628d10_cls* b);
};

// @fnv 0x00628d10
FUN_00628d10_cls* FUN_00628d10_cls::FUN_00628d10(FUN_00628d10_cls* a, FUN_00628d10_cls* b)
{
    __declspec(align(16)) Vec16 r0;
    __declspec(align(16)) Vec16 r1;
    __declspec(align(16)) Vec16 r2;
    this->FUN_00458a60(&r0, b);
    ((Sub16*)((char*)b + 0x10))->FUN_00458a60(&r1, (char*)this + 0x10);
    r2.FUN_00628cc0(&r0, &r1);
    a->FUN_00622570(r2.FUN_00458990(7) != 0);
    return a;
}
