// Source layout: BaseFormComponent. PC corrections are in generate_headers.py.
#ifndef FNV_BASEFORMCOMPONENT_H
#define FNV_BASEFORMCOMPONENT_H
#include "layout_support.h"
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
