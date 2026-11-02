// Source layout: TESChildCell. PC corrections are in generate_headers.py.
#ifndef TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_TESCHILDCELL_H
#define TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_TESCHILDCELL_H

#include "tesconditionfunctions_conditionfn_dep_layout_support.h"
class TESChildCell
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0
};
FNV_STATIC_ASSERT(sizeof(TESChildCell) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESChildCell, m_ppVirtualMethodTable) == 0x0);
#endif
