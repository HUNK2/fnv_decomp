// Source layout: NiMemObject. PC corrections are in generate_headers.py.
#ifndef FNV_NIMEMOBJECT_H
#define FNV_NIMEMOBJECT_H
#include "layout_support.h"
#pragma pack(push, 4)
class NiMemObject
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiMemObject) == 0x1);
#endif
