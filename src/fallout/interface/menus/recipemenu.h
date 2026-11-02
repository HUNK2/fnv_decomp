#ifndef FNV_RECIPEMENU_UNIT_H
#define FNV_RECIPEMENU_UNIT_H

#include "recipemenu_types_RecipeMenu.h"

// @fnv 0x007833e0
void RecipeMenu::AssignTileByID(int tileID, Tile* tile)
{
    if (tileID >= 0 && tileID < 14)
        m_pTiles[tileID] = tile;
}
#endif
