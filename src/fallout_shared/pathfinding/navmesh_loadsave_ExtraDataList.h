// Source layout: ExtraDataList. PC corrections are in generate_headers.py.
#ifndef FNV_EXTRADATALIST_H
#define FNV_EXTRADATALIST_H

#include "navmesh_loadsave_layout_support.h"
#include "navmesh_loadsave_BaseExtraList.h"
class ExtraDataList : public BaseExtraList
{
  public:
    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges* changes);
};
FNV_STATIC_ASSERT(sizeof(ExtraDataList) == 0x20);
#endif
