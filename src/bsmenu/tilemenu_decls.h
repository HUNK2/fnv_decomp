// bsmenu/tilemenu_decls.h: declares Menu, Interface, TileListBoxCalls
#ifndef TILEMENU_DECLS_H
#define TILEMENU_DECLS_H

class Tile;
class TileMenu;
extern bool DAT_011f308f[];
enum MenuID
{
    kMenuID = 0
};
class Menu
{
  public:
    virtual ~Menu();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual int GetID();
    virtual void v14();
    virtual void v15();
    virtual void OnUpdateUserTrait(int);
    static __forceinline void SetVisible(int id, bool b)
    {
        if (id >= 1001 && id <= 1084)
            DAT_011f308f[id] = b;
    }
    void SetTileMenu(TileMenu*, bool);
    static void SetMenuRootTile(int, Tile*);
    static float GetMenuScale();
    __forceinline void SetModal(int id)
    {
        m_iModalMenuId = id;
    }
    char pad[16];
    int m_iModalMenuId;
    char pad2[8];
    int m_iMenuId;
};
extern bool DAT_011f308f[];
class Interface
{
  public:
    static Menu* GetMenuById(int);
};
void DebugLog(const char*, ...);
class TileListBoxCalls
{
  public:
    float GetFloat(int);
};
#endif
