// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESREGIONPOINTLIST_H
#define FNV_TESREGIONPOINTLIST_H

#include "layout_support.h"
#include "layout_support.h"
class NiPoint2;
class RegionPoint;
class RegionPointList;
class TESRegionPointList__ScaleResult;
class NiPoint2
{
  public:
    float x;  // +0x0, 4 bytes
    float y;  // +0x4, 4 bytes
    // NiPoint2
    // operator[]
    // bool __cdecl NiPoint2::*(const NiPoint2&)
    // bool __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2 __cdecl NiPoint2::*(const NiPoint2&)
    // operator-
    // operator*
    // NiPoint2 __cdecl NiPoint2::*(float)
    // NiPoint2 __cdecl NiPoint2::*(const NiPoint2&, const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(float)
    // NiPoint2& __cdecl NiPoint2::*(float)
    // float __cdecl NiPoint2::*()
    // float __cdecl NiPoint2::*()
    // float __cdecl NiPoint2::*(const NiPoint2&)
    // float __cdecl NiPoint2::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiPoint2::*(const char*)
};
FNV_STATIC_ASSERT(sizeof(NiPoint2) == 8);
FNV_STATIC_ASSERT(offsetof(NiPoint2, x) == 0);
FNV_STATIC_ASSERT(offsetof(NiPoint2, y) == 4);
class RegionPointList : public BSSimpleList<RegionPoint*>
{
  public:
    // base BSSimpleList<RegionPoint *> at +0x0, size 8
    TESRegionPointList__ScaleResult* m_pScaleResult;  // +0x8, 4 bytes
    bool m_bOwnsPointMemory;                          // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
    NiPoint2 m_kMinimums;                  // +0x10, 8 bytes
    NiPoint2 Maximums;                     // +0x18, 8 bytes
    unsigned int m_uiDistanceInsideAtMax;  // +0x20, 4 bytes
    unsigned int iCount;                   // +0x24, 4 bytes
    RegionPointList(bool owns);
    ~RegionPointList();
    void SetDistanceInsideAtMax(unsigned int value);
    bool ReadPointsFromFile(TESFile*);
    bool FUN_004f81e0(bool);
    // RegionPointList
    // void __cdecl RegionPointList::*()
    // void __cdecl RegionPointList::*()
    // bool __cdecl RegionPointList::*(TESFile*)
    // unsigned int __cdecl RegionPointList::*()
    // void __cdecl RegionPointList::*(unsigned int)
    // bool __cdecl RegionPointList::*(RegionPoint*, float)
    // bool __cdecl RegionPointList::*(RegionPoint*, float)
    // bool __cdecl RegionPointList::*(RegionPoint*, float)
    // void __cdecl RegionPointList::*()
    // bool __cdecl RegionPointList::*(RegionPoint*, RegionPoint*, float, float)
    // void __cdecl RegionPointList::*(RegionPoint*)
    // RegionPoint* __cdecl RegionPointList::*(RegionPoint*, float)
    // float __cdecl RegionPointList::*()
    // float __cdecl RegionPointList::*()
    // float __cdecl RegionPointList::*()
    // float __cdecl RegionPointList::*()
    // unsigned int __cdecl RegionPointList::*()
    // bool __cdecl RegionPointList::*(const NiPoint2&, const NiPoint2&)
    // RegionPointList* __cdecl RegionPointList::*(RegionPointList*)
    // bool __cdecl RegionPointList::*(bool)
    // bool __cdecl RegionPointList::*(RegionPoint*, float)
    // bool __cdecl RegionPointList::*(bool)
    // bool __cdecl RegionPointList::*(RegionPoint*)
    // float __cdecl RegionPointList::*(RegionPoint*, float)
    // RegionPoint* __cdecl RegionPointList::*(RegionPoint*)
    // bool __cdecl RegionPointList::*(RegionPoint*, RegionPoint*)
    // float __cdecl RegionPointList::*(RegionPoint*)
    // void __cdecl RegionPointList::*(const RegionPointList&)
    // void __cdecl RegionPointList::*()
    // void* __cdecl RegionPointList::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(RegionPointList) == 40);
FNV_STATIC_ASSERT(offsetof(RegionPointList, m_pScaleResult) == 8);
FNV_STATIC_ASSERT(offsetof(RegionPointList, m_bOwnsPointMemory) == 12);
FNV_STATIC_ASSERT(offsetof(RegionPointList, m_kMinimums) == 16);
FNV_STATIC_ASSERT(offsetof(RegionPointList, Maximums) == 24);
FNV_STATIC_ASSERT(offsetof(RegionPointList, m_uiDistanceInsideAtMax) == 32);
FNV_STATIC_ASSERT(offsetof(RegionPointList, iCount) == 36);
#endif
