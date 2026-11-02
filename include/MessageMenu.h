// Source layout: MessageMenu. PC corrections are in generate_headers.py.
#ifndef FNV_MESSAGEMENU_H
#define FNV_MESSAGEMENU_H
#include "layout_support.h"
#include "GameTimerRecord.h"
#include "ListBox_int_.h"
#include "Menu.h"
#pragma pack(push, 4)
class MessageMenu : public Menu
{
  public:
    Tile* m_pTiles[6];              // +0x28
    ListBox_int_ m_kChoiceList;     // +0x40
    GameTimerRecord m_kTimerCalls;          // +0x70
    unsigned int m_uiMessageCount;  // +0x90
    int GetClass();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MessageMenu) == 0x94);
FNV_STATIC_ASSERT(offsetof(MessageMenu, m_pTiles) == 0x28);
FNV_STATIC_ASSERT(offsetof(MessageMenu, m_kChoiceList) == 0x40);
FNV_STATIC_ASSERT(offsetof(MessageMenu, m_kTimerCalls) == 0x70);
FNV_STATIC_ASSERT(offsetof(MessageMenu, m_uiMessageCount) == 0x90);
#endif
