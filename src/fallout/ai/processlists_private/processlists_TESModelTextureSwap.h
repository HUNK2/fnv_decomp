// Unit-private PC declarations from public JohnnyGuitar TESModelTextureSwap.hpp.
#ifndef FNV_PROCESSLISTS_TESMODELTEXTURESWAP_H
#define FNV_PROCESSLISTS_TESMODELTEXTURESWAP_H

#include "processlists_TESModel.h"
struct DistantTreeTextureInfo;
class TESModelTextureSwap : public TESModel
{
  public:
    TESModelTextureSwap();
    virtual ~TESModelTextureSwap();
    BSSimpleList<DistantTreeTextureInfo*> kTextureSwaps;  // +0x18
};
FNV_STATIC_ASSERT(sizeof(TESModelTextureSwap) == 0x20);
FNV_STATIC_ASSERT(offsetof(TESModelTextureSwap, kTextureSwaps) == 0x18);
#endif
