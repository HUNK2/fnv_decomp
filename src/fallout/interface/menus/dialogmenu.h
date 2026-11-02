// fallout/interface/menus/dialogmenu.h: declares DialogMenu
#ifndef FNV_DIALOGMENU_H
#define FNV_DIALOGMENU_H

class Tile;
class DialogMenu
{
  public:
    virtual int GetClass();
    virtual void AssignTileByID(int id, Tile* tile);

  private:
    unsigned char menuState[44];
    Tile* m_pTiles[4];
};

// @fnv 0x007618f0
int DialogMenu::GetClass()
{
    return 0x3F1;
}

// @fnv 0x00761900
void DialogMenu::AssignTileByID(int id, Tile* tile)
{
    if (id >= 0 && id < 4)
        m_pTiles[id] = tile;
}

#endif
