// fallout_shared/pathfinding/pathinglocation_decls.h: declares TESForm, TESObjectCELL, PathingLocation, NavMeshInfo, TESWorldSpace and more

#define NiPoint3 NiPoint3Layout
#define BSSimpleArray BSSimpleArrayLayout
#define NiPointer NiPointerLayout
#define TESObjectCELL TESObjectCELLLayout
#define PathingLocation PathingLocationLayout
#include "PathingLocation.h"
#undef PathingLocation
#undef TESObjectCELL
#undef BSSimpleArray
#undef NiPointer
#undef NiPoint3
#include "pathinglocation_templates.h"
class TESObjectCELL;
class BGSLoadGameBuffer;
class TESForm
{
  public:
    virtual void vfn_0();
    static TESForm* GetFormByID(unsigned int);
    bool IsDeleted() const;
    bool GetDisabled();
};
class TESObjectCELL : public TESForm
{
  public:
    bool IsOutdoorCell();
};

#pragma pack(push, 4)
class PathingLocation
{
  public:
    void** m_ppVirtualMethodTable;
    NiPoint3 Location;
    const NavMeshInfo* m_pLocationNavMesh;
    const BSSimpleArray<NavMeshInfo_const*, 1024>* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    unsigned char layoutPadding27[1];

    PathingLocation();
    void LoadGame(BGSLoadGameBuffer*);
    bool IsPathingLocationValid();
    bool HasPathingLocation();
    bool FUN_006a9520();
    bool IsPathingLocationFlagSet();
    bool GetAllMeshesReachable();
    void SetAllMeshesReachable(bool);
    bool HasValidTriangle();
    void ResetLocation();
    TESObjectCELL* GetContainingCell();
    bool ResolveNavMesh(NavMeshPtr&);
    bool FindNavMeshTriangle(NavMeshPtr&, unsigned short&);
    PathingLocation(const NiPoint3&, TESObjectREFR*);
    PathingLocation& operator=(const PathingLocation&);
    void SetLocationData(const NiPoint3&, TESObjectCELL*, TESWorldSpace*);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingLocation) == 0x28);

class NavMeshInfo
{
  public:
    bool ResolveNavMesh(NavMeshPtr&);
    bool FUN_0068f320() const;
};

class TESWorldSpace : public TESForm
{
  public:
    TESObjectCELL* GetCellByKey(unsigned int);
};

class TESObjectREFR
{
  public:
    TESWorldSpace* GetParentWorldSpace();
};

class LowProcess
{
  public:
    TESObjectREFR* GetTarget();
    int GetPackageObjectType();
};

class InventoryStackRecord;

#include "pathinglocation_packet.h"
