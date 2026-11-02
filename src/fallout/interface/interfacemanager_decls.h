// fallout/interface/interfacemanager_decls.h: declares SettingT_GameSettingCollection_, SystemColorManager, SoftSystemColor, InterfaceManager
#ifndef FNV_INTERFACEMANAGER_DECLS_H
#define FNV_INTERFACEMANAGER_DECLS_H

union SETTING_VALUE
{
    unsigned int color;
    int integer;
    float real;
    char* string;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Int();
};
class SystemColorManager
{
  public:
    class SoftSystemColor
    {
      public:
        unsigned char padding[12];
        SettingT_GameSettingCollection_* setting;
        unsigned int GetColor();
    };
};
class FORenderedMenu;
class InterfaceManager
{
  public:
    unsigned char padding[0x16c];
    FORenderedMenu* renderedMenu;
    unsigned int padding170;
    FORenderedMenu* pipboyRenderedMenu;
    static bool IsPipboyMenuActive();
    FORenderedMenu* GetActiveRenderedMenu();
};
#endif
