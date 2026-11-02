// fallout/interface/menus/repairmenu_packet.h: declares Tile, TileListBoxCalls, Menu, ListBox_ItemChange___, InventoryMenu and more
#ifndef REPAIRMENU_PACKET_H
#define REPAIRMENU_PACKET_H

class Menu;
class Tile
{
  public:
    float GetFloat(int);
    void Set(int, float, bool);
    void SetTraitFloat(int, float);
    static float GetInterfaceScale();
    Tile* ReadFile(const char*);
    Menu* GetMenu();
    static Menu* FindMenuById(int);
};
class TileListBoxCalls
{
  public:
    float GetFloat(int);
};
class Menu
{
  public:
    virtual ~Menu();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual int GetID();
    Tile* pMenu;
    char pad[0x20];
    void SetTileMenu(class TileMenu*, bool);
    void SetMenuVisibility(bool);
};
class ListBox_ItemChange___
{
  public:
    char pad[0x30];
    void Initialize(Tile*, const char*);
    void FUN_007a1930(bool);
};
class InventoryMenu
{
  public:
    void FUN_00867a20();
};
class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    BSSimpleList* GetNext();
};
class RepairMenu : public Menu
{
  public:
    Tile* m_pTiles[13];
    ListBox_ItemChange___ m_kRepairList;
    char padding[0x274 - 0x8c];
    float movement;
    int GetClass();
    void UpdateRepairList();
    static Tile* Create();
    bool FUN_007b5730();
};
class InterfaceManager
{
  public:
    Tile* FUN_00586150();
};
InterfaceManager* FUN_004b7210();
int FUN_007b5720();
int Warning(const char*, ...);
float FUN_004a4240();
void FUN_004169a0(float, float&, float&);
extern bool DAT_011d9e91;
extern RepairMenu* DAT_011da75c;
extern int DAT_011da754;
#endif
