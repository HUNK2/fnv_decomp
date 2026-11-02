// Source layout: TESTexture. PC corrections are in generate_headers.py.
#ifndef TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_TESTEXTURE_H
#define TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_TESTEXTURE_H

#include "tesconditionfunctions_conditionfn_dep_layout_support.h"
#include "tesconditionfunctions_conditionfn_dep_BaseFormComponent.h"
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> FullNameComponent;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESTexture) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESTexture, FullNameComponent) == 0x4);
#endif
