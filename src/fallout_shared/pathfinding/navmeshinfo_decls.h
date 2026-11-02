// fallout_shared/pathfinding/navmeshinfo_decls.h: declares NavMeshPtr, NavMeshInfo, PathingLocationData, PathingLocation
#ifndef NAVMESHINFO_DECLS_H
#define NAVMESHINFO_DECLS_H

class NavMesh;
class NiNode;
template <class T> class NiPointer
{
  public:
    T* m_ptr;
    T* operator->() const;
};
class NavMeshPtr : public NiPointer<NavMesh>
{
};
class NavMeshInfo
{
  public:
    char pad[0x54];
    NavMesh* m_pLocationNavMesh;
    bool FUN_0068f320() const;
    bool ResolveNavMesh(NavMeshPtr&);
};
void __cdecl ProcessWithScopedRef(NavMeshPtr&, NavMesh*);
class PathingLocationData
{
  public:
    bool HasNonZeroAtOffset54();
};
class PathingLocation
{
  public:
    char pad[0x10];
    PathingLocationData* data;
    char pad2[0x10];
    unsigned short triangle;
    bool HasValidTriangle();
};
#endif
