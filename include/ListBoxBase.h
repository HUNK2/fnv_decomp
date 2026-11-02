// Source layout: ListBoxBase. PC corrections are in generate_headers.py.
#ifndef FNV_LISTBOXBASE_H
#define FNV_LISTBOXBASE_H
#include "layout_support.h"
#pragma pack(push, 4)
class ListBoxBase
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ListBoxBase) == 0x4);
FNV_STATIC_ASSERT(offsetof(ListBoxBase, m_ppVirtualMethodTable) == 0x0);
#endif
