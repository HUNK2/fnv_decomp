// Source layout: MagicTarget. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_MAGICTARGET_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_MAGICTARGET_H
#include "interface_rebase_layout_support.h"
class MagicTarget
{
  public:
    bool m_bLeadingFlag;  // +0x4
    bool m_bSecondFlag;         // +0x5
    unsigned char layoutPadding6[2];
    BSSimpleList<MagicEffectContext*> m_kActiveEffectList;  // +0x8
    virtual bool AddEffectToTarget(MagicCaster* caster, MagicItem* spell, ActiveEffect* effect, bool immediate);
};
FNV_STATIC_ASSERT(sizeof(MagicTarget) == 0x10);
FNV_STATIC_ASSERT(offsetof(MagicTarget, m_bLeadingFlag) == 0x4);
FNV_STATIC_ASSERT(offsetof(MagicTarget, m_bSecondFlag) == 0x5);
FNV_STATIC_ASSERT(offsetof(MagicTarget, m_kActiveEffectList) == 0x8);
#endif
