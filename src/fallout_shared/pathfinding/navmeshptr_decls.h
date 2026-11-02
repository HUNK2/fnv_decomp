// fallout_shared/pathfinding/navmeshptr_decls.h: declares NavMeshInfo
#ifndef NAVMESHPTR_DECLS_H
#define NAVMESHPTR_DECLS_H

class NavMesh;
class NavMeshPtr;
class NavMeshInfo
{
  public:
    char padding[0x54];
    NavMesh* m_pLocationNavMesh;
    bool AcquireNavMesh(NavMeshPtr& out);
};
void __cdecl ProcessWithScopedRef(NavMeshPtr&, NavMesh*);
#endif
