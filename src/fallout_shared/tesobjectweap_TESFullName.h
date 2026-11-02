// Unit-private declaration copy of supplied include/TESFullName.h.
// Source layout: TESFullName. PC corrections are in generate_headers.py.
#ifndef FNV_TESOBJECTWEAP_PRIVATE_TESFULLNAME_H
#define FNV_TESOBJECTWEAP_PRIVATE_TESFULLNAME_H

#include "tesobjectweap_layout_support.h"
#include "tesobjectweap_BaseFormComponent.h"
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFullName, m_kName) == 0x4);
#endif
