// Source layout: ExtraDataList. PC corrections are in generate_headers.py.
#ifndef FNV_EXTRADATALIST_H
#define FNV_EXTRADATALIST_H
#include "layout_support.h"
#include "BaseExtraList.h"
class ExtraDismemberedLimbs;
#pragma pack(push, 4)
class ExtraDataList : public BaseExtraList
{
  public:
    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges* changes);
    ExtraDismemberedLimbs* GetDismemberedLimbs();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraDataList) == 0x20);
#endif
