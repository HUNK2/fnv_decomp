// fallout/interface/menus/mapmenu.h: declares MapMenu
#ifndef FALLOUT_INTERFACE_MENUS_MAPMENU_H
#define FALLOUT_INTERFACE_MENUS_MAPMENU_H

// World map menu (MapMenu, a 560-byte Menu subclass). This unit recovers only
// the class-id accessor found at 0x00796a40; the remaining layout belongs to
// the other MapMenu units.
class MapMenu
{
  public:
    int GetClass();
};

#endif
