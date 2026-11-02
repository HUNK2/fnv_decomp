// fallout/interface/menus/bartermenu_decls.h: declares MapMenu
#ifndef FNV_BARTERMENU_DECLS_H
#define FNV_BARTERMENU_DECLS_H

class Tile;
class MapMenu
{
  public:
    unsigned char menuLayout[0x28];
    Tile* m_pTiles[22];
    void AssignTileByID(int index, Tile* tile);
};
#endif
