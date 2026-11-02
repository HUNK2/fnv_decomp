// Source layout: TESChildCell. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_TESCHILDCELL_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_TESCHILDCELL_H
#include "interface_rebase_layout_support.h"
class TESChildCell
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0
};
FNV_STATIC_ASSERT(sizeof(TESChildCell) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESChildCell, m_ppVirtualMethodTable) == 0x0);
#endif
