// fallout_shared/pathfinding/pathbuilder_decls.h: declares PathingRequest, PathingSolution, TESRecipe, PathingLocationProxy

class PathingRequest
{
  public:
    PathingLocation& GetOffsetC();
    bool GetByteAtOffsetA1();
};

class PathingSolution
{
  public:
    int FUN_005a4320();
    void SetByteAtOffset40(int);
    void Clear(bool);
    PathingInfoEntry* GetPathingInfoEntry(PathingInfoEntry&);
};

class TESRecipe
{
  public:
    PerkEntryConditionSet* GetConditions();
};

class PathingLocationProxy
{
  public:
    bool FindContainingTriangle(FindTriangleForLocationFilter* filter);
    const NavMeshInfo* GetAssociatedNavMesh();
    TESObjectCELL* GetContainingCell();
    void* FUN_00441110();
};

class INISettingCollection;
template <> class SettingT<INISettingCollection>
{
  public:
    SETTING_VALUE* Bool();
};

extern SettingT<INISettingCollection> DAT_011d7450;

union SETTING_VALUE
{
    bool b;
    int i;
    float f;
    char* s;
};

class GlobalObject_00869f00
{
  public:
    unsigned int GetSize();
};
template <> class BSSimpleArray<NavMeshEdgeData, 1024>
{
  public:
    unsigned int data[5];
    BSSimpleArray(unsigned int, unsigned int, ScrapHeapBuffer*);
    ~BSSimpleArray();
    NavMeshEdgeData& FUN_006a1440(unsigned int);
};
