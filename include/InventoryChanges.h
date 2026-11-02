// Source layout: InventoryChanges. PC corrections are in generate_headers.py.
#ifndef FNV_INVENTORYCHANGES_H
#define FNV_INVENTORYCHANGES_H
#include "layout_support.h"
#pragma pack(push, 4)
class InventoryChanges
{
  public:
    BSSimpleList<InventoryStackRecord*>* m_pEntryList;  // +0x0
    TESObjectREFR* pRef;                      // +0x4
    float m_fTotalWeight;                     // +0x8
    float m_fArmorWeight;                     // +0xC
    bool m_bChanged;                          // +0x10
    unsigned char layoutPadding11;
    unsigned short layoutPadding12;
    InventoryChanges(TESObjectREFR* reference);
    static InventoryChanges* CreateForReference(TESObjectREFR* reference);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(InventoryChanges) == 0x14);
FNV_STATIC_ASSERT(offsetof(InventoryChanges, m_pEntryList) == 0x0);
FNV_STATIC_ASSERT(offsetof(InventoryChanges, pRef) == 0x4);
FNV_STATIC_ASSERT(offsetof(InventoryChanges, m_fTotalWeight) == 0x8);
FNV_STATIC_ASSERT(offsetof(InventoryChanges, m_fArmorWeight) == 0xC);
FNV_STATIC_ASSERT(offsetof(InventoryChanges, m_bChanged) == 0x10);
#endif
