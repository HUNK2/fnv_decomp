// Source layout: TESFullName. PC corrections are in generate_headers.py.
#ifndef FNV_TESFULLNAME_H
#define FNV_TESFULLNAME_H

#include "tesfurniture_layout_support.h"
#include "tesfurniture_BaseFormComponent.h"
class TESFullName : public BaseFormComponent
{
  public:
    TESFullName();
    virtual ~TESFullName();
    BSStringT<char> m_kName;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFullName, m_kName) == 0x4);
#endif
