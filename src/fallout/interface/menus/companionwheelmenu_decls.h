// fallout/interface/menus/companionwheelmenu_decls.h: declares Menu, InterfaceManager, CompanionWheelMenu
#ifndef COMPANIONWHEELMENU_DECLS_H
#define COMPANIONWHEELMENU_DECLS_H
class Menu
{
  public:
    Menu();
    virtual ~Menu();
    char storage[60];
};
class FUN_007642f0
{
  public:
    FUN_007642f0();
    ~FUN_007642f0();
    char storage[48];
};
class FUN_0076bda0
{
  public:
    FUN_0076bda0();
    char storage[32];
};
class InterfaceManager
{
  public:
    char storage[228];
    unsigned char menuState;
};
InterfaceManager* FUN_004b7210();
class CompanionWheelMenu : public Menu
{
  public:
    CompanionWheelMenu();
    virtual ~CompanionWheelMenu();
    FUN_007642f0 first;
    FUN_0076bda0 second;
    unsigned int state;
};
#endif
