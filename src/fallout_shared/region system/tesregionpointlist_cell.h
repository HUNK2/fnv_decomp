// fallout_shared/region system/tesregionpointlist_cell.h: declares TESRegionList, TESRegionPointList_CellExtraList, TESObjectCELL

class TESRegionList
{
  public:
    unsigned char layout[16];
    TESRegionList(int);
};
class TESRegionPointList_CellExtraList
{
  public:
    TESRegionList* FUN_0041bce0();
    void SetRegionList(TESRegionList*);
};
class TESObjectCELL
{
  public:
    unsigned char prefix[0x28];
    TESRegionPointList_CellExtraList extraData;
    bool IsCellInterior() const;
    TESRegionList* GetRegionList(bool);
};
