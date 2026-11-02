// src/staging/blk_00da0000_od_o2_nood_variant_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/staging/blk_00da0000_od_o2_nood_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/staging/blk_00da0000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00da0000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/staging/blk_00da0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"
struct ScratchBlock
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
    unsigned char unk30;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
};
void __cdecl FUN_00da6fd0(ScratchBlock* block);
class ScratchOwner
{
  public:
    void AddEntry(ScratchBlock* block, int a, int b);
};
void __cdecl FUN_00da7020(ScratchOwner* owner);
struct FinishingFlag
{
    int m_bFinishing;
};
struct S00da0780_Member
{
    S00da0780_Member(FinishingFlag flag);  // FUN_00cb0a70
    int m_iWordAt00;
};
class __declspec(align(16)) S00da0780_Object
{
  public:
    S00da0780_Object(FinishingFlag flag) : m_kMember(flag)
    {}
    virtual void vf00();
    int unk04;
    S00da0780_Member m_kMember;
    int unk0C;
};
const void* __cdecl FUN_00da0780();
#include <xmmintrin.h>
__declspec(align(16)) struct FUN_00da7180_cls
{
    __m128 m_v00;
    __m128 m_v10;
    float m_f20;
    unsigned int m_i24;
    float m_f28;
    unsigned int m_i2C;
    unsigned int m_i30;

    FUN_00da7180_cls* FUN_00da7180(const FUN_00da7180_cls* src);
};
