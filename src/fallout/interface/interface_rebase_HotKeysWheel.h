#ifndef FNV_INTERFACE_REBASE_FNV_HOTKEYSWHEEL_H
#define FNV_INTERFACE_REBASE_FNV_HOTKEYSWHEEL_H
#include "interface_rebase_layout_support.h"
class HotkeyWheelDisplay
{
  public:
    Tile* m_pWheelTile;                  // +0x0
    Tile* m_ppHotkeySlotTiles[8];  // +0x4
    bool m_bHasHotkeySelection;    // +0x24
    unsigned char layoutPadding25[3];
    int m_iTileValueIdAtOffset28;  // +0x28
    int m_iTileValueIdAtOffset2C;  // +0x2C
    int m_iTileValueIdAtOffset30;  // +0x30
};
FNV_STATIC_ASSERT(sizeof(HotkeyWheelDisplay) == 0x34);
FNV_STATIC_ASSERT(offsetof(HotkeyWheelDisplay, m_pWheelTile) == 0x0);
FNV_STATIC_ASSERT(offsetof(HotkeyWheelDisplay, m_ppHotkeySlotTiles) == 0x4);
FNV_STATIC_ASSERT(offsetof(HotkeyWheelDisplay, m_bHasHotkeySelection) == 0x24);
FNV_STATIC_ASSERT(offsetof(HotkeyWheelDisplay, m_iTileValueIdAtOffset28) == 0x28);
FNV_STATIC_ASSERT(offsetof(HotkeyWheelDisplay, m_iTileValueIdAtOffset2C) == 0x2C);
FNV_STATIC_ASSERT(offsetof(HotkeyWheelDisplay, m_iTileValueIdAtOffset30) == 0x30);
#endif
