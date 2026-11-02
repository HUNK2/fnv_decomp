// Source layout: TESScriptableForm. PC corrections are in generate_headers.py.
#ifndef FNV_TESSCRIPTABLEFORM_H
#define FNV_TESSCRIPTABLEFORM_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;  // +0x4
    bool m_bHasScript;      // +0x8
    unsigned char layoutPadding9;
    unsigned short layoutPaddingA;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESScriptableForm) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESScriptableForm, m_pFormScript) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESScriptableForm, m_bHasScript) == 0x8);
#endif
