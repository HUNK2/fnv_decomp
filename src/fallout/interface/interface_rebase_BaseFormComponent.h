// Source layout: BaseFormComponent. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_BASEFORMCOMPONENT_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_BASEFORMCOMPONENT_H
#include "interface_rebase_layout_support.h"
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
