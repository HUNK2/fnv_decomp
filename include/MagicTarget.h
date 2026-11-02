// Source layout: MagicTarget. PC corrections are in generate_headers.py.
#ifndef FNV_MAGICTARGET_H
#define FNV_MAGICTARGET_H
#include "layout_support.h"
#pragma pack(push, 4)
class MagicTarget
{
  public:
    bool m_bLeadingFlag;  // +0x4
    bool m_bSecondFlag;         // +0x5
    unsigned short layoutPadding6;
    BSSimpleList<MagicEffectContext*> m_kActiveEffectList;  // +0x8
    virtual bool AddEffectToTarget(MagicCaster* caster, MagicItem* spell, ActiveEffect* effect, bool immediate);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MagicTarget) == 0x10);
FNV_STATIC_ASSERT(offsetof(MagicTarget, m_bLeadingFlag) == 0x4);
FNV_STATIC_ASSERT(offsetof(MagicTarget, m_bSecondFlag) == 0x5);
FNV_STATIC_ASSERT(offsetof(MagicTarget, m_kActiveEffectList) == 0x8);
#endif
