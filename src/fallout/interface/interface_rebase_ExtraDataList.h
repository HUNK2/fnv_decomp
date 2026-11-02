// Source layout: ExtraDataList. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_EXTRADATALIST_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_PLAYER_EXTRADATALIST_H
#include "interface_rebase_layout_support.h"
#include "interface_rebase_BaseExtraList.h"
class ExtraDataList : public BaseExtraList
{
  public:
    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges* changes);
};
FNV_STATIC_ASSERT(sizeof(ExtraDataList) == 0x20);
#endif
