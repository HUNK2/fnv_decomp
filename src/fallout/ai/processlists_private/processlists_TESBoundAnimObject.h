// Unit-private PC declarations from public JohnnyGuitar TESBoundAnimObject.hpp.
// Declaration/layout facts only; no community implementation bodies.
#ifndef FNV_PROCESSLISTS_TESBOUNDANIMOBJECT_H
#define FNV_PROCESSLISTS_TESBOUNDANIMOBJECT_H
#include "processlists_TESBoundObject.h"
class TESBoundAnimObject : public TESBoundObject
{
  public:
    TESBoundAnimObject();
    virtual ~TESBoundAnimObject();
};
FNV_STATIC_ASSERT(sizeof(TESBoundAnimObject) == 0x30);
#endif
