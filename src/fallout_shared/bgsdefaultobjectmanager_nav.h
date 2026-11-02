

class TESChildCell
{
  public:
    TESChildCell();
    virtual void vfn_0();
};
class PathingSolutionBase
{
  public:
    PathingSolutionBase();
    virtual ~PathingSolutionBase();
    unsigned int refs;
};
template <class T, int N> class BSSimpleArray
{
  public:
    BSSimpleArray();
    ~BSSimpleArray();
    unsigned int data[4];
};
template <class T> class NiPointer
{
  public:
    T* ptr;
};
class NavMeshVertex;
class NavMeshTriangle;
class EdgeExtraInfo;
class NavMeshTriangleDoorPortal;
class NavMeshClosedDoorInfo;
class ObstacleUndoData;
class NavMeshStaticAvoidNode;
class NiTMap_unsigned_short_NavMeshPOVData_
{
  public:
    NiTMap_unsigned_short_NavMeshPOVData_(unsigned int);
    ~NiTMap_unsigned_short_NavMeshPOVData_();
    unsigned int data[4];
};
class NiTMap_unsigned_short_NiPointer_ObstacleData___
{
  public:
    NiTMap_unsigned_short_NiPointer_ObstacleData___(unsigned int);
    unsigned int data[4];
};
class NavMeshGrid
{
  public:
    NavMeshGrid();
    unsigned int data[10];
};
class NavMesh : public TESForm, public TESChildCell, public PathingSolutionBase
{
  public:
    NavMesh();
    virtual ~NavMesh();
    virtual void vfn_0();
    void* m_pOwningCell;
    BSSimpleArray<NavMeshVertex, 1024> Vertices;
    BSSimpleArray<NavMeshTriangle, 1024> Triangles;
    BSSimpleArray<EdgeExtraInfo, 1024> m_kEdgeExtraInfo;
    BSSimpleArray<NavMeshTriangleDoorPortal, 1024> m_kDoorPortals;
    BSSimpleArray<NavMeshClosedDoorInfo, 1024> m_kClosedDoorInfo;
    BSSimpleArray<unsigned short, 1024> m_kIndexList;
    NiTMap_unsigned_short_NavMeshPOVData_ POVPointerArray;
    BSSimpleArray<unsigned short, 1024> m_kAdditionalIndexList;
    NavMeshGrid m_kGrid;
    BSSimpleArray<NiPointer<ObstacleUndoData>, 1024> m_kObstacleUndoData;
    NiTMap_unsigned_short_NiPointer_ObstacleData___* pTriangleToObstacleMap;
    BSSimpleArray<unsigned short, 1024> m_kAdditionalData;
    BSSimpleArray<NavMeshStaticAvoidNode, 1024> m_kStaticAvoidNodes;
    void* m_pNavigationMesh;
};
