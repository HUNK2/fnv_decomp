
#include "statsmenu_decls.h"

// @fnv 0x0071f660
int StatsMenu::GetClass()
{
    return 1003;
}

// @fnv 0x0071fa50
void StatsMenu::AssignTileByID(int id, Tile* tile)
{
    if (id >= 0 && id < 60)
        m_pTiles[id] = tile;
}

// @fnv 0x007dc040
bool StatsMenu::SetTileFlashing(Tile* tile, unsigned int flashing)
{
    if (flashing)
        tile->SetTraitFade(4009, 255.0f, 0.0f, 1.0f, Tile::FADE);
    else
    {
        tile->UpdateTrait(4009);
        tile->Set(4009, 255);
    }
    return true;
}

// @fnv 0x007db2c0
StatsMenu::BodyPartDisplay::BodyPartDisplay()
{
    m_iBodyPartCount = 0;
    memset(m_auiBodyPartValues, -1, sizeof(m_auiBodyPartValues));
}
