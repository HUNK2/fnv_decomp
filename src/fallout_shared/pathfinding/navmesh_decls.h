// fallout_shared/pathfinding/navmesh_decls.h: declares NiPoint3, NavMeshTriangle, NavMesh
#ifndef FNV_NAVMESH_DECLS_H
#define FNV_NAVMESH_DECLS_H

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3& operator+=(const NiPoint3&);
    NiPoint3& operator*=(float);
};
class NavMeshTriangle
{
  public:
    unsigned short NavMeshTriangle_GetVert(int);
};
extern float DAT_0102f200;
class NavMesh
{
  public:
    NavMeshTriangle* GetTriangle(unsigned short);
    const NiPoint3& FUN_0068f0a0(unsigned short);
    NiPoint3 GetNavMeshData(unsigned short);
};
#endif
