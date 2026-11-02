// Private declaration copy; original: relay_work/queue/queue058/01_fallout_interface_menus_statsmenu_cpp/include/ListBoxBase.h
// Source layout: ListBoxBase. PC corrections are in generate_headers.py.
#ifndef FNV_LISTBOXBASE_H
#define FNV_LISTBOXBASE_H
#include "statsmenu_layout_support.h"
class ListBoxBase
{
  public:
    virtual bool SetSelectedTile(Tile* tile);
    virtual Tile* GetSelectedTile();
    virtual Tile* HandleKeyboardInput(int inputCode);
    virtual bool IsParentMenu(Menu* menu);
    virtual void ScrollToHighlight();
    virtual Tile* GetItemTile(int index, bool countFromTop);
    virtual void Destroy(bool doFree);
    virtual void ClearList();
};
FNV_STATIC_ASSERT(sizeof(ListBoxBase) == 0x4);
#endif
