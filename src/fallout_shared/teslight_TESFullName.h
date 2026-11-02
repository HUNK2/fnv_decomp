// Source layout: TESFullName. PC corrections are in generate_headers.py.
#ifndef FNV_TESFULLNAME_H
#define FNV_TESFULLNAME_H

class Script;
class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};
#include "layout_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;  // +0x4
    void SetFullName(const char* name);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFullName, m_kName) == 0x4);
#endif
