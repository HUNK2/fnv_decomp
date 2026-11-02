// Source layout: MagicCaster. PC corrections are in generate_headers.py.
#ifndef FNV_MAGICCASTER_H
#define FNV_MAGICCASTER_H
#include "layout_support.h"
#pragma pack(push, 4)
class MagicCaster
{
  public:
    MagicEffectCollection* apTargetLight;         // +0x4
    MagicCaster__State eState;  // +0x8
    virtual void CastSpellOnCaster(SpellItem* spell, bool immediate);
    virtual void CastSpellAtTarget(SpellItem* spell, MagicTarget* target, bool immediate);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MagicCaster) == 0xC);
FNV_STATIC_ASSERT(offsetof(MagicCaster, apTargetLight) == 0x4);
FNV_STATIC_ASSERT(offsetof(MagicCaster, eState) == 0x8);
#endif
