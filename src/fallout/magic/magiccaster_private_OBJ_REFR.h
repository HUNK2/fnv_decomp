#ifndef FNV_MAGICCASTER_PRIVATE_OBJ_REFR_H
#define FNV_MAGICCASTER_PRIVATE_OBJ_REFR_H

#include "magiccaster_private_layout_support.h"
#include "magiccaster_private_NiPoint3.h"
class PlacedObjectInfo
{
  public:
    TESBoundObject* m_pPlacedObject;  // +0x0
    NiPoint3 Angle;                    // +0x4
    NiPoint3 Location;                 // +0x10
};
FNV_STATIC_ASSERT(sizeof(PlacedObjectInfo) == 0x1C);
FNV_STATIC_ASSERT(offsetof(PlacedObjectInfo, m_pPlacedObject) == 0x0);
FNV_STATIC_ASSERT(offsetof(PlacedObjectInfo, Angle) == 0x4);
FNV_STATIC_ASSERT(offsetof(PlacedObjectInfo, Location) == 0x10);
#endif
