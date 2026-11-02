// Source layout: TESDescription. PC corrections are in generate_headers.py.
#ifndef TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_TESDESCRIPTION_H
#define TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_TESDESCRIPTION_H

#include "tesconditionfunctions_conditionfn_dep_layout_support.h"
#include "tesconditionfunctions_conditionfn_dep_BaseFormComponent.h"
class TESDescription : public BaseFormComponent
{
  public:
    unsigned long m_uiDescriptionFileOffset;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESDescription) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESDescription, m_uiDescriptionFileOffset) == 0x4);
#endif
