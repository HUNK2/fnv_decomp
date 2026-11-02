#ifndef FNV_OBJ_REFR_H
#define FNV_OBJ_REFR_H

#include "layout_support.h"
#include "NiPoint3_decl_grenadeprojectile.h"
#pragma pack(push, 4)
class PlacedObjectInfo
{
  public:
    TESBoundObject* m_pPlacedObject;  // +0x0
    NiPoint3 Angle;                    // +0x4
    NiPoint3 Location;                 // +0x10
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PlacedObjectInfo) == 0x1C);
FNV_STATIC_ASSERT(offsetof(PlacedObjectInfo, m_pPlacedObject) == 0x0);
FNV_STATIC_ASSERT(offsetof(PlacedObjectInfo, Angle) == 0x4);
FNV_STATIC_ASSERT(offsetof(PlacedObjectInfo, Location) == 0x10);
#endif
