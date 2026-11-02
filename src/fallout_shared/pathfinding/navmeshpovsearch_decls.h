// fallout_shared/pathfinding/navmeshpovsearch_decls.h: declares NiPoint3, NavMeshBounds, SineCosine, CircularArc, Sphere and more

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
    float GetSquaredXYLength() const;
    void ScaleByInverse(float);
};
class ParentSpaceNode;
template <class T, int N> class BSSimpleArray
{
  public:
    int data[4];
    template <int M> void CopyTo(BSSimpleArray<T, M>*);
    void CopyRecordsTo(BSSimpleArray*);
};
class NavMeshBounds
{
  public:
    NiPoint3 min, max;
    BSSimpleArray<unsigned short, 1024> triangles;
    BSSimpleArray<ParentSpaceNode, 1024> parents;
    void CopyTo(NavMeshBounds*);
};
class SineCosine
{
  public:
    float fCos, fSin;
    SineCosine operator-(const SineCosine&) const;
    bool FUN_006a06f0(const SineCosine&) const;
};
class CircularArc
{
  public:
    SineCosine start, end;
    int direction;
    bool FUN_006a0660(const SineCosine&) const;
};
class Sphere
{
  public:
    NiPoint3 Center;
    float fRadius;
};
enum ANGLE_DIRECTION
{
    CLOCKWISE,
    COUNTERCLOCKWISE
};
class SphereTangent
{
  public:
    ANGLE_DIRECTION direction;
    SineCosine start, end;
};
class SphereTangents
{
  public:
    int count;
    SphereTangent tangents[2];
};
class NavMeshPOVSearch
{
  public:
    static int FindSphereTangents(const Sphere&, const Sphere&, ANGLE_DIRECTION, SphereTangents&);
};
float FUN_004019b0(float);
