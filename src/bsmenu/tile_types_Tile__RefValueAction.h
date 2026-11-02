// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TILE_REFVALUEACTION_H
#define FNV_TILE_REFVALUEACTION_H

#include "layout_support.h"
#include "Tile__Action.h"
class Tile__RefValueAction;
class Tile__Value;
#pragma pack(push, 4)
class Tile__RefValueAction : public Tile__Action
{
  public:
    // base Tile::Action at +0x0, size 12
    Tile__Value* m_pReferencedValue;  // +0xC, 4 bytes
    float GetStoredFloatValue();
    // float __cdecl Tile::RefValueAction::*()
    // Tile::Value* __cdecl Tile::RefValueAction::*()
    // RefValueAction
    // Tile::RefValueAction& __cdecl Tile::RefValueAction::*(const Tile::RefValueAction&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Tile__RefValueAction) == 16);
FNV_STATIC_ASSERT(offsetof(Tile__RefValueAction, m_pReferencedValue) == 12);
#endif
