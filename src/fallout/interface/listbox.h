// fallout/interface/listbox.h: declares StartMenu, TileListBoxCalls
#ifndef FNV_LISTBOX_MATCH_UNIT_H
#define FNV_LISTBOX_MATCH_UNIT_H


#include "listbox_decls.h"
#include "layout_support.h"
#include "ListBoxBase.h"
#include "listbox_types_Tile.h"
#include "listbox_types_BGSSaveLoadFileEntry.h"

class BGSNote;
class InventoryStackRecord;
class StartMenu
{
  public:
    class Option;
};
template <class T> class ListBoxItem;

template <class T> class ListBox : public ListBoxBase
{
  public:
    BSSimpleList<ListBoxItem<T>*> items;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    unsigned char padding1E[2];
    float m_fFirstListValue;
    float m_fSecondListValue;
    float m_fThirdListValue;
    unsigned short usFlags;
    unsigned char padding2E[2];

    unsigned int AddItem(unsigned int mask);
    bool Highlight(Tile* tile);
    void ResetItems();
    bool IsEnabled();
    unsigned int GetVisibleEntryCount();
    void Initialize(Tile* container, const char* templateName);
    bool SetSelection(Tile* tile);
    bool SetSelection(Tile* tile, int mode);
    T GetSelectedData();
    T GetSelectedData(Tile* tile);
};

class TileListBoxCalls : public Tile
{
  public:
    float GetFloat(int trait);
};

int __cdecl GetTileValueID(const char* name, int index);
Tile* __cdecl FindNamedTile(Tile* tile, const char* name);

extern "C" const char kListBoxEnabled[] = "_enabled";
extern "C" const char kListBoxNumFiltered[] = "_number_of_visible_items";
extern "C" const char kListBoxScrollbar[] = "child(lb_scrollbar)";

template <>
// @fnv 0x007d87b0
unsigned int ListBox<BGSSaveLoadFileEntry*>::GetVisibleEntryCount()
{
    return m_pListTile != 0
               ? (unsigned int)((TileListBoxCalls*)m_pListTile)->GetFloat(GetTileValueID(kListBoxNumFiltered, -1))
               : 0;
}

template <>
// @fnv 0x007d8d60
bool ListBox<BGSSaveLoadFileEntry*>::SetSelection(Tile* tile)
{
    return SetSelection(tile, 0);
}

template <>
// @fnv 0x007a1910
PerkForm* ListBox<PerkForm*>::GetSelectedData()
{
    return GetSelectedData(m_pSelectedTile);
}

template <>
// @fnv 0x0075a0d0
void ListBox<unsigned int>::Initialize(Tile* container, const char* templateName)
{
    m_pListTile = container;
    pTemplateName = templateName;
    m_pHighlightedTile = FindNamedTile(m_pListTile, kListBoxScrollbar);
}

template <>
// @fnv 0x007cc5d0
unsigned int ListBox<StartMenu::Option*>::AddItem(unsigned int mask)
{
    return ((unsigned int)m_pListTile & mask) != 0;
}

// @fnv 0x00418900
SoundPlaybackHandle& SoundPlaybackHandle::operator=(const SoundPlaybackHandle& other)
{
    soundID = other.soundID;
    success = other.success;
    state = other.state;
    return *this;
}

template <>
// @fnv 0x007d7630
bool ListBox<BGSSaveLoadFileEntry*>::IsEnabled()
{
    return m_pListTile && m_pListTile->IsVisible();
}

template <>
// @fnv 0x00730ed0
bool ListBox<InventoryStackRecord*>::Highlight(Tile* tile)
{
    if (IsEnabled() && (!tile || (((ListBox_int_*)this)->ContainsKey(tile) &&
                                  tile->ContainsTrait(GetTileValueID(kListBoxEnabled, -1)))))
    {
        m_pSelectedTile = tile;
        ResetItems();
        return true;
    }
    else
    {
        return false;
    }
}
template <>
// @fnv 0x00764a00
bool ListBox<int>::Highlight(Tile* tile)
{
    if (IsEnabled() && (!tile || (((ListBox_int_*)this)->ContainsKey(tile) &&
                                  tile->ContainsTrait(GetTileValueID(kListBoxEnabled, -1)))))
    {
        m_pSelectedTile = tile;
        ResetItems();
        return true;
    }
    else
    {
        return false;
    }
}
template <>
// @fnv 0x007a3170
bool ListBox<BGSNote*>::Highlight(Tile* tile)
{
    if (IsEnabled() && (!tile || (((ListBox_int_*)this)->ContainsKey(tile) &&
                                  tile->ContainsTrait(GetTileValueID(kListBoxEnabled, -1)))))
    {
        m_pSelectedTile = tile;
        ResetItems();
        return true;
    }
    else
    {
        return false;
    }
}
template <>
// @fnv 0x007a4ce0
bool ListBox<BGSQuestObjective*>::Highlight(Tile* tile)
{
    if (IsEnabled() && (!tile || (((ListBox_int_*)this)->ContainsKey(tile) &&
                                  tile->ContainsTrait(GetTileValueID(kListBoxEnabled, -1)))))
    {
        m_pSelectedTile = tile;
        ResetItems();
        return true;
    }
    else
    {
        return false;
    }
}

#endif
