// Source layout: TESIcon. PC corrections are in generate_headers.py.
#ifndef FNV_TESICON_H
#define FNV_TESICON_H
#include "layout_support.h"
#include "TESTexture.h"
#pragma pack(push, 4)
class TESIcon : public TESTexture
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESIcon) == 0xC);
#endif
