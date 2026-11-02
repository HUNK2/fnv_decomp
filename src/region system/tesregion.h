// Reconstructed source layout for TESRegion.
// the TESForm base is 0x18 on PC, so m_kDiffuseColor sits at +0x2C.
// Covers getter 0x005d8a70, which returns the pointer to the member color.
#ifndef FNV_TESREGION_H
#define FNV_TESREGION_H


#include "layout_support.h"
#include "TESForm.h"

// 32-bit RGBA color (4 floats, 16 bytes).
class NiColor
{
  public:
    float r;
    float g;
    float b;
    float a;
};
FNV_STATIC_ASSERT(sizeof(NiColor) == 0x10);

class RegionDataList;
class RegionPointList;
class TESWorldSpace;
class TESWeather;

// TESRegion extends the 0x18-byte TESForm base with region state.
#pragma pack(push, 4)
class TESRegion : public TESForm
{
  public:
    RegionDataList* m_pRegionDataList;                 // +0x18
    BSSimpleList<RegionPointList*>* pRegionPointList;  // +0x1C
    TESWorldSpace* m_pContainingWorldspace;            // +0x20
    TESWeather* m_pRegionWeather;                      // +0x24
    float fWeatherChance;                              // +0x28
    NiColor m_kDiffuseColor;                           // +0x2C

// @fnv 0x005d8a70
    NiColor* GetDiffuseColor()
    {
        return &m_kDiffuseColor;
    }
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESRegion) == 0x3C);

#endif
