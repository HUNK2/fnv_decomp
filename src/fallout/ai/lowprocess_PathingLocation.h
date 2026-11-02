// Source layout: PathingLocation. PC corrections are in generate_headers.py.
#ifndef FNV_PATHINGLOCATION_H
#define FNV_PATHINGLOCATION_H
#include "lowprocess_support.h"
#include "lowprocess_NiPoint3.h"
#pragma pack(push, 4)
class PathingLocation
{
  public:
    PathingLocation(TESObjectREFR*);
    ~PathingLocation();
    virtual void vfn_0();
    NiPoint3 Location;                                                 // +0x4
    const NavMeshInfo* m_pLocationNavMesh;                             // +0x10
    const BSSimpleArray<NavMeshInfo_const*, 1024>* pNavMeshInfoArray;  // +0x14
    TESObjectCELL* pCell;                                              // +0x18
    TESWorldSpace* m_pContainingWorldspace;                            // +0x1C
    unsigned int m_uiPathingFlags;                                     // +0x20
    unsigned short m_usTriangleID;                                     // +0x24
    unsigned char uiFlags;                                             // +0x26
    void ResetLocation();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingLocation) == 0x28);
FNV_STATIC_ASSERT(offsetof(PathingLocation, Location) == 0x4);
FNV_STATIC_ASSERT(offsetof(PathingLocation, m_pLocationNavMesh) == 0x10);
FNV_STATIC_ASSERT(offsetof(PathingLocation, pNavMeshInfoArray) == 0x14);
FNV_STATIC_ASSERT(offsetof(PathingLocation, pCell) == 0x18);
FNV_STATIC_ASSERT(offsetof(PathingLocation, m_pContainingWorldspace) == 0x1C);
FNV_STATIC_ASSERT(offsetof(PathingLocation, m_uiPathingFlags) == 0x20);
FNV_STATIC_ASSERT(offsetof(PathingLocation, m_usTriangleID) == 0x24);
FNV_STATIC_ASSERT(offsetof(PathingLocation, uiFlags) == 0x26);
#endif
