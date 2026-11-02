// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_FASTNAVMESHEDGEHANDLE_H
#define FNV_FASTNAVMESHEDGEHANDLE_H

#include "layout_support.h"
class NavMeshEdgeData;
class CompactNavMeshEdgeReference;
class NavMesh;
#pragma pack(push, 4)
class CompactNavMeshEdgeReference
{
  public:
    NavMesh* m_pLocationNavMesh;    // +0x0, 4 bytes
    unsigned short m_usTriangleID;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    // CompactNavMeshEdgeReference
    // CompactNavMeshEdgeReference& __cdecl CompactNavMeshEdgeReference::*(const CompactNavMeshEdgeReference&)
    // bool __cdecl CompactNavMeshEdgeReference::*(const CompactNavMeshEdgeReference&)
    // bool __cdecl CompactNavMeshEdgeReference::*(const CompactNavMeshEdgeReference&)
    // unsigned __int64 __cdecl CompactNavMeshEdgeReference::*()
    // void __cdecl CompactNavMeshEdgeReference::*(char*, unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CompactNavMeshEdgeReference) == 8);
FNV_STATIC_ASSERT(offsetof(CompactNavMeshEdgeReference, m_pLocationNavMesh) == 0);
FNV_STATIC_ASSERT(offsetof(CompactNavMeshEdgeReference, m_usTriangleID) == 4);
#pragma pack(push, 4)
class NavMeshEdgeData : public CompactNavMeshEdgeReference
{
  public:
    // base CompactNavMeshEdgeReference at +0x0, size 8
    int m_iEdgeIndex;  // +0x8, 4 bytes
    // NavMeshEdgeData
    // NavMeshEdgeData& __cdecl NavMeshEdgeData::*(const NavMeshEdgeData&)
    // bool __cdecl NavMeshEdgeData::*(const NavMeshEdgeData&)
    // bool __cdecl NavMeshEdgeData::*(const NavMeshEdgeData&)
    // unsigned __int64 __cdecl NavMeshEdgeData::*()
    // void __cdecl NavMeshEdgeData::*(char*, unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NavMeshEdgeData) == 12);
FNV_STATIC_ASSERT(offsetof(NavMeshEdgeData, m_iEdgeIndex) == 8);
#endif
