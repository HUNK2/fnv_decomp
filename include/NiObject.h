// Source layout: NiObject. PC corrections are in generate_headers.py.
#ifndef FNV_NIOBJECT_H
#define FNV_NIOBJECT_H
#include "layout_support.h"
#include "NiRefObject.h"
#pragma pack(push, 4)
class NiObject : public NiRefObject
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiObject) == 0x8);
#endif
