// fallout/interface/menus/quantitymenu.h
//
// Recovered declarations for the quantity-menu family. The sleep/wait menu
// keeps one tile pointer per TILE_INDEX slot and ignores ids outside the
// table; Menu::AssignTileByID is the shared slot each menu overrides.
#ifndef FNV_QUANTITYMENU_H
#define FNV_QUANTITYMENU_H


#include "Menu.h"

class SleepWaitMenu : public Menu
{
    enum TILE_INDEX
    {
        TI_HOW_MANY_TEXT,
        TI_SCROLLBAR,
        TI_HOURS_TEXT,
        TI_TIME_TEXT,
        TI_WAIT_BUTTON,
        TI_CANCEL_BUTTON,
        NUM_TILES
    };

    Tile* m_pTiles[NUM_TILES];  // +0x28
    static SleepWaitMenu* ms_pInventoryMenu;
    float m_fCameraTransitionTime;  // +0x40
    bool m_bState1;                 // +0x44
    bool m_bState2;                 // +0x45
    bool m_bState3;                 // +0x46
    float m_fWaitTime;              // +0x48
    static int ms_iState;

  public:
    // Menu::AssignTileByID
    void AssignTileByID(int index, Tile* tile);
};

#endif  // FNV_QUANTITYMENU_H
