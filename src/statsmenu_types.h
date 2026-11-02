// Self-contained private closure; no public implementation bodies copied.
#ifndef FNV_STATSMENU_TYPES_H
#define FNV_STATSMENU_TYPES_H
#include "statsmenu_StatsMenu.h"
#include "statsmenu_PlayerCharacter.h"
#include "statsmenu_types_ActiveEffect.h"
#include "statsmenu_types_EffectItem.h"
#include "statsmenu_types_Tile.h"
#include "statsmenu_types_TESActorBaseData.h"
#include "statsmenu_BGSPerk.h"
#include "statsmenu_types_EffectSetting.h"
// Public JIP GameTiles.h:359-370: TileRect size3C, TileMenu size40.
class TileRect : public Tile
{
  public:
    unsigned int unk38;
};
class TileMenu : public TileRect
{
  public:
    Menu* menu;
};
FNV_STATIC_ASSERT(sizeof(TileRect) == 0x3C);
FNV_STATIC_ASSERT(sizeof(TileMenu) == 0x40);
FNV_STATIC_ASSERT(offsetof(TileRect, unk38) == 0x38);
FNV_STATIC_ASSERT(offsetof(TileMenu, menu) == 0x3C);
extern PlayerCharacter* g_thePlayer;
#endif
