// Source layout: TESFullName. PC corrections are in generate_headers.py.
#ifndef FNV_TESFULLNAME_H
#define FNV_TESFULLNAME_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESFullName : public BaseFormComponent
{
  public:
    const char* GetFullName();
    BSStringT<char> m_kName;  // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFullName, m_kName) == 0x4);
#endif
