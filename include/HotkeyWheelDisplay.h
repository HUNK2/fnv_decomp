#ifndef FNV_HOTKEYSWHEEL_H
#define FNV_HOTKEYSWHEEL_H

#include "layout_support.h"
#pragma pack(push, 4)
class HotkeyWheelDisplay
{
  public:
    Tile* m_pWheelTile;                  // +0x0
    Tile* m_ppHotkeySlotTiles[8];  // +0x4
    bool m_bHasHotkeySelection;    // +0x24
    unsigned char layoutPadding25;
    unsigned short layoutPadding26;
    int m_iTileValueIdAtOffset28;  // +0x28
    int m_iTileValueIdAtOffset2C;  // +0x2C
    int m_iTileValueIdAtOffset30;  // +0x30
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(HotkeyWheelDisplay) == 0x34);
FNV_STATIC_ASSERT(offsetof(HotkeyWheelDisplay, m_pWheelTile) == 0x0);
FNV_STATIC_ASSERT(offsetof(HotkeyWheelDisplay, m_ppHotkeySlotTiles) == 0x4);
FNV_STATIC_ASSERT(offsetof(HotkeyWheelDisplay, m_bHasHotkeySelection) == 0x24);
FNV_STATIC_ASSERT(offsetof(HotkeyWheelDisplay, m_iTileValueIdAtOffset28) == 0x28);
FNV_STATIC_ASSERT(offsetof(HotkeyWheelDisplay, m_iTileValueIdAtOffset2C) == 0x2C);
FNV_STATIC_ASSERT(offsetof(HotkeyWheelDisplay, m_iTileValueIdAtOffset30) == 0x30);
#endif
