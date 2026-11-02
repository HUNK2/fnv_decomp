
class FindTriangleForLocationFilter;
class PathingLocationProxy : public PathingLocation
{
  public:
    bool IsPathingLocationFlagSet();
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
    TESObjectCELL* GetContainingCell();
    const NavMeshInfo* GetAssociatedNavMesh();
};

class PathingLocationArray
{
  public:
    void ConstructItems(PathingLocation*, unsigned int);
};

class BGSLoadGameBuffer
{
  public:
    void ReadDataBlock(void*, unsigned int);
    unsigned int ReadFormIdentifier();
};
class BGSLoadFormBuffer
{
  public:
    bool ReadFormIdentifier(void*);
};
class Pathing
{
  public:
    NavMeshInfo* FindReferenceByFormId();
};
class TES
{
  public:
    Pathing* GetActiveCell(unsigned int);
};
extern TES* g_TES;
const BSSimpleArray<NavMeshInfo_const*, 1024>* FUN_006d6f40(TESObjectCELL*);
const BSSimpleArray<NavMeshInfo_const*, 1024>* ForwardToPathing(TESWorldSpace*, unsigned int);
class NavMeshPtr
{
  public:
    void* pointer;
    NavMeshPtr();
    ~NavMeshPtr();
};
class NiNode : public TESForm
{
};
class NavMeshBounds
{
  public:
    bool ContainsPoint(const NiPoint3&);
    NiPoint3 FUN_0069c070(const NiPoint3&);
};
class NiFormArray
{
  public:
    TESForm*& FUN_00877a30(unsigned int);
};
class PathBuilderDetailedPathInfos : public BSSimpleArray<unsigned int, 1024>
{
  public:
    PathBuilderDetailedPathInfos();
    ~PathBuilderDetailedPathInfos();
    NavMeshInfo*& GetFirstForm();
};

class NavMesh
{
  public:
    unsigned short FindTriangleForLocation(const NiPoint3&, FindTriangleForLocationFilter*);
};
extern double DAT_0106cd60;
