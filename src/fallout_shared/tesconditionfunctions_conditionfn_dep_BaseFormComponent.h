// Source layout: BaseFormComponent. PC corrections are in generate_headers.py.
#ifndef TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_BASEFORMCOMPONENT_H
#define TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_BASEFORMCOMPONENT_H
#include "tesconditionfunctions_conditionfn_dep_layout_support.h"
class BaseFormComponent
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};
FNV_STATIC_ASSERT(sizeof(BaseFormComponent) == 0x4);
#endif
