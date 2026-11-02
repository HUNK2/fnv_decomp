// Source layout: NiProperty. PC corrections are in generate_headers.py.
#ifndef FNV_NIPROPERTY_H
#define FNV_NIPROPERTY_H
#include "layout_support.h"
#include "NiObjectNET.h"
#pragma pack(push, 4)
class NiProperty : public NiObjectNET
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiProperty) == 0x18);
#endif
