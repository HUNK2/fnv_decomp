// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESREGIONDATALIST_H
#define FNV_TESREGIONDATALIST_H

#include "layout_support.h"
#include "layout_support.h"
class TESRegionData;
class RegionDataList;
class RegionDataList : public BSSimpleList<TESRegionData*>
{
  public:
    // base BSSimpleList<TESRegionData *> at +0x0, size 8
    bool m_bDataFlag;  // +0x8, 1 bytes
    unsigned char layoutPadding9[3];
    void Clear();
    // RegionDataList
    // void __cdecl RegionDataList::*()
    // bool __cdecl RegionDataList::*(TESRegionData*)
    // RemoveRDL
    // void __cdecl RegionDataList::*()
    // RegionDataList* __cdecl RegionDataList::*(RegionDataList*)
    // TESRegionData* __cdecl RegionDataList::*(const REGION_DATA_ID)
    // bool __cdecl RegionDataList::*()
    // void __cdecl RegionDataList::*(const RegionDataList&)
    // void __cdecl RegionDataList::*()
    // void* __cdecl RegionDataList::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(RegionDataList) == 12);
FNV_STATIC_ASSERT(offsetof(RegionDataList, m_bDataFlag) == 8);
#endif
