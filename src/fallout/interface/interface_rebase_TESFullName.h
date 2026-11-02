// Source layout: TESFullName. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_FNV_TESFULLNAME_H
#define FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_FNV_TESFULLNAME_H
#include "interface_rebase_layout_support.h"
#include "interface_rebase_BaseFormComponent.h"
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFullName, m_kName) == 0x4);
#endif
