// Source layout: MagicCaster. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_MAGICCASTER_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_MAGICCASTER_H
#include "interface_rebase_layout_support.h"
class MagicCaster
{
  public:
    MagicEffectCollection* apTargetLight;         // +0x4
    MagicCaster__State eState;  // +0x8
    virtual void CastSpellOnCaster(SpellItem* spell, bool immediate);
};
FNV_STATIC_ASSERT(sizeof(MagicCaster) == 0xC);
FNV_STATIC_ASSERT(offsetof(MagicCaster, apTargetLight) == 0x4);
FNV_STATIC_ASSERT(offsetof(MagicCaster, eState) == 0x8);
#endif
