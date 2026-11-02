// Private declaration copy; original: relay_work/queue/queue008/01_fallout_shared_magic_effectsetting_cpp/include/PerkData.h
// Source layout: PerkData. PC corrections are in generate_headers.py.
#ifndef FNV_PERKDATA_H
#define FNV_PERKDATA_H

#include "statsmenu_layout_support.h"
class PerkData
{
  public:
    bool m_bTrait;                // +0x0
    unsigned char cLevel;         // +0x1
    unsigned char m_ucRankCount;  // +0x2
    bool bPlayable;               // +0x3
    bool bHidden;                 // +0x4
};
FNV_STATIC_ASSERT(sizeof(PerkData) == 0x5);
FNV_STATIC_ASSERT(offsetof(PerkData, m_bTrait) == 0x0);
FNV_STATIC_ASSERT(offsetof(PerkData, cLevel) == 0x1);
FNV_STATIC_ASSERT(offsetof(PerkData, m_ucRankCount) == 0x2);
FNV_STATIC_ASSERT(offsetof(PerkData, bPlayable) == 0x3);
FNV_STATIC_ASSERT(offsetof(PerkData, bHidden) == 0x4);
#endif
