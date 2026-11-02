// Source layout: ExtraContainerChanges. PC corrections are in generate_headers.py.
#ifndef FNV_EXTRACONTAINERCHANGES_H
#define FNV_EXTRACONTAINERCHANGES_H
#include "layout_support.h"
#include "BSExtraData_rtti2_extradatalist.h"
#pragma pack(push, 4)
class ExtraContainerChanges : public BSExtraData
{
  public:
    InventoryChanges* pChanges;  // +0xC
    ExtraContainerChanges(InventoryChanges* changes);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ExtraContainerChanges) == 0x10);
FNV_STATIC_ASSERT(offsetof(ExtraContainerChanges, pChanges) == 0xC);
#endif
