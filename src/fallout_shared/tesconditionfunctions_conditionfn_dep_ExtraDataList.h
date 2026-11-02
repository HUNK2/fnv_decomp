// Source layout: ExtraDataList. PC corrections are in generate_headers.py.
#ifndef TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_EXTRADATALIST_H
#define TESCONDITIONFUNCTIONS_CONDITIONFN_DEP_EXTRADATALIST_H

#include "tesconditionfunctions_conditionfn_dep_layout_support.h"
#include "tesconditionfunctions_conditionfn_dep_BaseExtraList.h"
class ExtraDataList : public BaseExtraList
{
  public:
    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges* changes);
};
FNV_STATIC_ASSERT(sizeof(ExtraDataList) == 0x20);
#endif
