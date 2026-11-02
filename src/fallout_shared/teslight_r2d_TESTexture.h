// Source layout: TESTexture. PC corrections are in generate_headers.py.
#ifndef FNV_TESLIGHT_R2D_TESTEXTURE_H
#define FNV_TESLIGHT_R2D_TESTEXTURE_H

#include "layout_support.h"
#include "BaseFormComponent.h"
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> FullNameComponent;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESTexture) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESTexture, FullNameComponent) == 0x4);
#endif
