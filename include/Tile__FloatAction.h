// Source layout: Tile::FloatAction. PC corrections are in generate_headers.py.
#ifndef FNV_TILE__FLOATACTION_H
#define FNV_TILE__FLOATACTION_H

#include "layout_support.h"
#include "Tile__Action.h"
#pragma pack(push, 4)
class Tile__FloatAction : public Tile__Action
{
  public:
    float fValue;  // +0xC
    float GetStoredFloatValue();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Tile__FloatAction) == 0x10);
FNV_STATIC_ASSERT(offsetof(Tile__FloatAction, fValue) == 0xC);
#endif
