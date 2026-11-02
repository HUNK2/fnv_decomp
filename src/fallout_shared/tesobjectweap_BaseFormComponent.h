// Unit-private declaration copy of supplied include/BaseFormComponent.h.
// Source layout: BaseFormComponent. PC corrections are in generate_headers.py.
#ifndef FNV_TESOBJECTWEAP_PRIVATE_BASEFORMCOMPONENT_H
#define FNV_TESOBJECTWEAP_PRIVATE_BASEFORMCOMPONENT_H
#include "tesobjectweap_layout_support.h"
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
