// Unit-private declaration copy of supplied include/TESHealthForm.h.
// Source layout: TESHealthForm. PC corrections are in generate_headers.py.
#ifndef FNV_TESOBJECTWEAP_PRIVATE_TESHEALTHFORM_H
#define FNV_TESOBJECTWEAP_PRIVATE_TESHEALTHFORM_H

#include "tesobjectweap_layout_support.h"
#include "tesobjectweap_BaseFormComponent.h"
class TESHealthForm : public BaseFormComponent
{
  public:
    unsigned int m_uiHealthValue;  // +0x4
    void InitializeComponent();
};
FNV_STATIC_ASSERT(sizeof(TESHealthForm) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESHealthForm, m_uiHealthValue) == 0x4);
#endif
