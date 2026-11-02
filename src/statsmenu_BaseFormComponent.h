// Private declaration copy; original: relay_work/queue/queue058/01_fallout_interface_menus_statsmenu_cpp/include/BaseFormComponent.h
// Source layout: BaseFormComponent. PC corrections are in generate_headers.py.
#ifndef FNV_BASEFORMCOMPONENT_H
#define FNV_BASEFORMCOMPONENT_H
#include "statsmenu_layout_support.h"
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
