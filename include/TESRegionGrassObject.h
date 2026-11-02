// Source layout: TESRegionGrassObject. PC corrections are in generate_headers.py.
#ifndef FNV_TESREGIONGRASSOBJECT_H
#define FNV_TESREGIONGRASSOBJECT_H

#include "layout_support.h"
#include "TESRegionObjectBase.h"
#pragma pack(push, 4)
class TESRegionGrassObject : public TESRegionObjectBase
{
  public:
    TESGrass* pObject;        // +0x4
    TESLandTexture* pParent;  // +0x8
    void AssignLandTexture(TESLandTexture*);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESRegionGrassObject) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESRegionGrassObject, pObject) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESRegionGrassObject, pParent) == 0x8);
#endif
