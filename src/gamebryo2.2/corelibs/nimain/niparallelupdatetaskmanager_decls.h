// gamebryo2.2/corelibs/nimain/niparallelupdatetaskmanager_decls.h: declares Interface, Main, NiParallelUpdateTaskManager
#ifndef NIPARALLELUPDATETASKMANAGER_DECLS_H
#define NIPARALLELUPDATETASKMANAGER_DECLS_H


class Interface
{
  public:
    enum enumMenus
    {
        MessageMenu = 0x3e9,
        DialogueMenu = 0x3f1,
        Menu_3f6 = 0x3f6,
        Menu_41e = 0x41e,
        VATSMenu = 0x420,
        Menu_424 = 0x424,
        Menu_432 = 0x432,
        Menu_438 = 0x438,
        Menu_439 = 0x439,
        Menu_43a = 0x43a,
        Menu_43b = 0x43b
    };

    static bool GetSelectedTargetIndex(enumMenus menu);
    static bool IsMenuActive(enumMenus menu, unsigned int flags);
    static bool IsPipboyMenuActive();
    static bool IsConsoleActive();
    static bool IsPipboyMenuOpen();
    bool FUN_007014a0(bool);
};

class Main
{
  public:
    void RunFrame();
    void RefreshAfterSave();
};

class NiParallelUpdateTaskManager
{
  public:
    void DispatchParallelUpdates();
};

// The packet has no identities for these menu-state globals and helper.
extern bool DAT_011dea28;
extern bool DAT_011dea29;
extern bool DAT_011dea2b;
extern Interface* DAT_011d8804;
bool FUN_0070edf0();

#endif
