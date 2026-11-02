// Shadow header for matching: verbatim copy of the canonical
// PathingLocation layout plus the member declarations needed by this unit.
// Layout and offsets are unchanged; methods do not affect layout.
#ifndef FNV_PATHINGLOCATION_H
#define FNV_PATHINGLOCATION_H

#include "layout_support.h"
#include "NiPoint3.h"
class NavMeshPtr;
#pragma pack(push, 4)
class PathingLocation
{
  public:
    void** m_ppVirtualMethodTable;                                                   // +0x0
    NiPoint3 Location;                                                 // +0x4
    const NavMeshInfo* m_pLocationNavMesh;                             // +0x10
    const BSSimpleArray<NavMeshInfo_const*, 1024>* pNavMeshInfoArray;  // +0x14
    TESObjectCELL* pCell;                                              // +0x18
    TESWorldSpace* m_pContainingWorldspace;                            // +0x1C
    unsigned int m_uiPathingFlags;                                     // +0x20
    unsigned short m_usTriangleID;                                     // +0x24
    unsigned char uiFlags;                                             // +0x26
    unsigned char layoutPadding27[1];
    void ResetLocation();
    TESObjectCELL* GetContainingCell();
    bool ResolveNavMesh(NavMeshPtr&);
    bool FindNavMeshTriangle(NavMeshPtr&, unsigned short&);
    PathingLocation& operator=(const PathingLocation&);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingLocation) == 0x28);
FNV_STATIC_ASSERT(offsetof(PathingLocation, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(PathingLocation, Location) == 0x4);
FNV_STATIC_ASSERT(offsetof(PathingLocation, m_pLocationNavMesh) == 0x10);
FNV_STATIC_ASSERT(offsetof(PathingLocation, pNavMeshInfoArray) == 0x14);
FNV_STATIC_ASSERT(offsetof(PathingLocation, pCell) == 0x18);
FNV_STATIC_ASSERT(offsetof(PathingLocation, m_pContainingWorldspace) == 0x1C);
FNV_STATIC_ASSERT(offsetof(PathingLocation, m_uiPathingFlags) == 0x20);
FNV_STATIC_ASSERT(offsetof(PathingLocation, m_usTriangleID) == 0x24);
FNV_STATIC_ASSERT(offsetof(PathingLocation, uiFlags) == 0x26);
#endif
