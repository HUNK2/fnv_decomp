// Unit-private declaration copy of supplied include/TESTexture.h.
// Source layout: TESTexture. PC corrections are in generate_headers.py.
#ifndef FNV_TESOBJECTWEAP_PRIVATE_TESTEXTURE_H
#define FNV_TESOBJECTWEAP_PRIVATE_TESTEXTURE_H

#include "tesobjectweap_layout_support.h"
#include "tesobjectweap_BaseFormComponent.h"
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> FullNameComponent;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESTexture) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESTexture, FullNameComponent) == 0x4);
#endif
