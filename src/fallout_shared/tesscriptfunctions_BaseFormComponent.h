// Source layout: BaseFormComponent. PC corrections are in generate_headers.py.
#ifndef FNV_TESSCRIPTFUNCTIONS_BASEFORMCOMPONENT_H
#define FNV_TESSCRIPTFUNCTIONS_BASEFORMCOMPONENT_H
#include "tesscriptfunctions_layout_support.h"
class BaseFormComponent
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};
FNV_STATIC_ASSERT(sizeof(BaseFormComponent) == 0x4);
FNV_STATIC_ASSERT(__alignof(BaseFormComponent) == 4);
#endif
