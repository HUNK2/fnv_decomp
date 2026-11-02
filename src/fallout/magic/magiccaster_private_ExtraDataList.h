// Source layout: ExtraDataList. PC corrections are in generate_headers.py.
#ifndef FNV_MAGICCASTER_PRIVATE_EXTRADATALIST_H
#define FNV_MAGICCASTER_PRIVATE_EXTRADATALIST_H

#include "magiccaster_private_layout_support.h"
#include "magiccaster_private_BaseExtraList.h"
class ExtraDataList : public BaseExtraList
{
  public:
    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges* changes);
};
FNV_STATIC_ASSERT(sizeof(ExtraDataList) == 0x20);
#endif
