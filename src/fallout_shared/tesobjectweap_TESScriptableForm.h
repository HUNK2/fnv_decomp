// Unit-private declaration copy of supplied include/TESScriptableForm.h.
// Source layout: TESScriptableForm. PC corrections are in generate_headers.py.
#ifndef FNV_TESOBJECTWEAP_PRIVATE_TESSCRIPTABLEFORM_H
#define FNV_TESOBJECTWEAP_PRIVATE_TESSCRIPTABLEFORM_H

#include "tesobjectweap_layout_support.h"
#include "tesobjectweap_BaseFormComponent.h"
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;  // +0x4
    bool m_bHasScript;      // +0x8
    unsigned char layoutPadding9[3];
};
FNV_STATIC_ASSERT(sizeof(TESScriptableForm) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESScriptableForm, m_pFormScript) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESScriptableForm, m_bHasScript) == 0x8);
#endif
