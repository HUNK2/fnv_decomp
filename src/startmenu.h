// Hand-authored partial StartMenu layout for the members this translation unit
// list box members whose generated headers are not in the canonical set are kept
// as documented padding. A canonical generated header supersedes this file.
#ifndef FNV_STARTMENU_H
#define FNV_STARTMENU_H

#include "startmenu_decls.h"
#include "layout_support.h"
#include "Menu.h"
#pragma pack(push, 4)
class StartMenu : public Menu
{
  public:
    class UserOption;
    class Option;
    class OptionManager
    {
      public:
        unsigned int m_uiFirstValue;
        unsigned int m_uiSecondValue;
        OptionManager();
        static OptionManager* Instance();
    };
    int GetClass();
    TileMenu* GetMenuTitle();
    bool IsStartMenuActive();
    enum Flag
    {
        FLAG_INGAME = 1,
        FLAG_OPTIONS_DIRTY = 2,
        FLAG_FORCE_RELOAD = 4,
        FLAG_SAVE_MODE = 8,
        FLAG_FADE_IN = 16,
        FLAG_SAVE_OPTIONS = 32,
        FLAG_RESET_HUD_OPACITY = 64,
        FLAG_DLC_NEEDS_UPDATE = 128,
        FLAG_NEW_DLC_INSTALLED = 256,
        FLAG_SEARCHING_DLC = 512,
        FLAG_DLC_WAIT_MESSAGE = 1024,
        FLAG_SYSUTILSAVECOMPLETE = 2048,
        FLAG_ACTION_MAPPING = 4096,
        FLAG_DELETE_MODE = 8192,
        FLAG_SAVE_WAIT_MESSAGE = 16384,
        FLAG_SAVE_WAIT_SAVING = 32768,
        FLAG_SHOWING_CREDITS = 65536,
        FLAG_DONT_FORCE_BACK = 131072,
        FLAG_SAVELOAD_BACKOUT = 262144,
        FLAG_IIS_PREFADE = 524288,
        FLAG_LOADING_SAVEGAMES = 1048576,
        FLAG_LIVE_MENU = 2097152,
        FLAG_RESTART_REQUIRED = 4194304,
        FLAG_MOUNT_DLC = 8388608,
        FLAG_DLC_CORRUPT_MESSAGE = 16777216,
        FLAG_USER_PRESSED_START = 33554432,
        FLAG_USER_IS_ACTION_MAPPING = 67108864,
        FLAG_MEM_CARD_REMOVED = 134217728,
        FLAG_SAVE_SAVING = 268435456,
        FLAG_MISSING_CONTENT = 536870912
    };
    bool IsFlagSet(Flag aFlag);
    Tile* m_pTiles[23];  // +0x28
    unsigned char layoutListBoxMain[48];
    unsigned char layoutListBoxSettings[48];
    unsigned char layoutListBoxConfirm[48];
    ListBox<Option*> m_kDownloadOptions;  // +0x114 m_kDownloadOptions
    unsigned char layoutListBoxDownloads[48];
    unsigned char layoutListBoxSaveLoad[48];
    StartMenu::UserOption* m_pUserOption;  // +0x1A4
    unsigned int uiFlags;                  // +0x1A8
    float m_fMenuTimer;                    // +0x1AC
};
#pragma pack(pop)
FNV_STATIC_ASSERT(offsetof(StartMenu, m_pTiles) == 0x28);
FNV_STATIC_ASSERT(offsetof(StartMenu, m_pUserOption) == 0x1A4);
FNV_STATIC_ASSERT(offsetof(StartMenu, uiFlags) == 0x1A8);
FNV_STATIC_ASSERT(offsetof(StartMenu, m_fMenuTimer) == 0x1AC);
extern StartMenu::OptionManager* DAT_011daac4;
// @fnv 0x007cb4d0
int StartMenu::GetClass()
{
    return 0x3f5;
}
// @fnv 0x00403df0
TileMenu* StartMenu::GetMenuTitle()
{
    return this ? pMenu : 0;
}
// @fnv 0x007ce8f0
bool StartMenu::IsStartMenuActive()
{
    return Interface::GetSelectedTargetIndex(Interface::START_MENU) && IsFlagSet(FLAG_ACTION_MAPPING) &&
           m_kDownloadOptions.IsSelected(m_kDownloadOptions.vfn_4());
}
// @fnv 0x007cb710
StartMenu::OptionManager* StartMenu::OptionManager::Instance()
{
    if (!DAT_011daac4)
        DAT_011daac4 = new OptionManager;
    return DAT_011daac4;
}
#endif
