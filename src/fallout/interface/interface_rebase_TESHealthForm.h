// Source layout: TESHealthForm. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_CREATURE_TESHEALTHFORM_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_CREATURE_TESHEALTHFORM_H
#include "interface_rebase_layout_support.h"
#include "interface_rebase_BaseFormComponent.h"
class TESHealthForm : public BaseFormComponent
{
  public:
    unsigned int m_uiHealthValue;  // +0x4
    void InitializeComponent();
};
FNV_STATIC_ASSERT(sizeof(TESHealthForm) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESHealthForm, m_uiHealthValue) == 0x4);
#endif
