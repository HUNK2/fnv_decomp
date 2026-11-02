// Source layout: TESHealthForm. PC corrections are in generate_headers.py.
#ifndef FNV_TESHEALTHFORM_H
#define FNV_TESHEALTHFORM_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESHealthForm : public BaseFormComponent
{
  public:
    unsigned int m_uiHealthValue;  // +0x4
    void InitializeComponent();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESHealthForm) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESHealthForm, m_uiHealthValue) == 0x4);
#endif
