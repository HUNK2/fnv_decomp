// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_CHECKLINEOFSIGHTFILTERWATER_H
#define FNV_CHECKLINEOFSIGHTFILTERWATER_H

#include "layout_support.h"
class CheckLineOfSightFilterWater;
class Pathing__CheckLineOfSightFilter;
#pragma pack(push, 4)
class Pathing__CheckLineOfSightFilter
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
    // CheckLineOfSightFilter
    // Pathing::CheckLineOfSightFilter& __cdecl Pathing::CheckLineOfSightFilter::*(const Pathing::CheckLineOfSightFilter&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Pathing__CheckLineOfSightFilter) == 4);
FNV_STATIC_ASSERT(offsetof(Pathing__CheckLineOfSightFilter, m_ppVirtualMethodTable) == 0);
#pragma pack(push, 4)
class CheckLineOfSightFilterWater : public Pathing__CheckLineOfSightFilter
{
  public:
    // base Pathing::CheckLineOfSightFilter at +0x0, size 4
    bool m_bCheckWater;  // +0x4, 1 bytes
    bool IsLineOfSightClear(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
    unsigned char layoutPadding5[3];
    // CheckLineOfSightFilterWater
    // CheckLineOfSightFilterWater& __cdecl CheckLineOfSightFilterWater::*(const CheckLineOfSightFilterWater&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CheckLineOfSightFilterWater) == 8);
FNV_STATIC_ASSERT(offsetof(CheckLineOfSightFilterWater, m_bCheckWater) == 4);
#endif
