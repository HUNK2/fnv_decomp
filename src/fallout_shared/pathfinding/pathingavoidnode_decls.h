// fallout_shared/pathfinding/pathingavoidnode_decls.h: declares NavMesh, NavMeshTriangleReference

class NavMeshTriangle;
class EdgeExtraInfo;
template <class T, int N> class BSSimpleArray
{
  public:
    NavMeshTriangle* FUN_00558dd0(unsigned short index);
};
class NavMesh
{
    char padding[0x38];
    BSSimpleArray<NavMeshTriangle, 1024> triangles;

  public:
    NavMeshTriangle* GetTriangle(unsigned short index);
};
class NavMeshTriangleReference
{
    NavMesh* mesh;
    unsigned short triangle;

  public:
    NavMeshTriangle* FUN_006a78d0() const;
};
