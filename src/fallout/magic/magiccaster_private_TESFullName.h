// Source layout: TESFullName. PC corrections are in generate_headers.py.
#ifndef FNV_MAGICCASTER_PRIVATE_TESFULLNAME_H
#define FNV_MAGICCASTER_PRIVATE_TESFULLNAME_H

#include "magiccaster_private_layout_support.h"
#include "magiccaster_private_BaseFormComponent.h"
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFullName, m_kName) == 0x4);
#endif
