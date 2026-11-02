// fallout/interface/menumanager_decls.h: declares Menu, MenuSystem, MenuClassArray, CompanionWheelMenu, ContainerMenu and more
#ifndef FNV_MENUMANAGER_DECLS_H
#define FNV_MENUMANAGER_DECLS_H

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
int __cdecl Warning(const char*, ...);
class Menu
{
    unsigned char layout[0x28];
};
class MenuSystem
{
  public:
    MenuSystem();
    static MenuSystem* Instance(bool create);
    Menu* GetMenuById(int menuClass);
    void ResizeMenuByClassArray();
};
extern MenuSystem* DAT_011d8d54;
class ActorCombatGroup;
template <class T> class NiTMallocInterface;
template <class T, class Allocator> class NiTArray
{
  public:
    void SetSize(unsigned int size);
};
class MenuClassArray : public NiTArray<ActorCombatGroup*, NiTMallocInterface<ActorCombatGroup*> >
{
};
extern MenuClassArray g_menuByClassArray;
// Constructor at 0x0075f070; runtime allocation is 0x80 bytes.
class FUN_0075f070 : public Menu
{
  public:
    FUN_0075f070();

  private:
    unsigned char layoutExtension[0x58];
};
// Constructor at 0x007a8a10; runtime allocation is 0x94 bytes.
class CompanionWheelMenu : public Menu
{
  public:
    CompanionWheelMenu();

  private:
    unsigned char layoutExtension[0x6c];
};
// Constructor at 0x0071f240; runtime allocation is 0x54 bytes.
class ContainerMenu : public Menu
{
  public:
    ContainerMenu();

  private:
    unsigned char layoutExtension[0x2c];
};
// Constructor at 0x00796740; runtime allocation is 0x230 bytes.
class MapMenu : public Menu
{
  public:
    MapMenu();

  private:
    unsigned char layoutExtension[0x208];
};
// Constructor at 0x0077fa00; runtime allocation is 0x124 bytes.
class InventoryMenu : public Menu
{
  public:
    InventoryMenu();

  private:
    unsigned char layoutExtension[0xfc];
};
// Constructor at 0x0071f340; runtime allocation is 0x2a4 bytes.
class FUN_0071f340 : public Menu
{
  public:
    FUN_0071f340();

  private:
    unsigned char layoutExtension[0x27c];
};
// Constructor at 0x0076bb40; runtime allocation is 0x278 bytes.
class FUN_0076bb40 : public Menu
{
  public:
    FUN_0076bb40();

  private:
    unsigned char layoutExtension[0x250];
};
// Constructor at 0x00788440; runtime allocation is 0x5c0 bytes.
class FUN_00788440 : public Menu
{
  public:
    FUN_00788440();

  private:
    unsigned char layoutExtension[0x598];
};
// Constructor at 0x0075b0d0; runtime allocation is 0x10c bytes.
class FUN_0075b0d0 : public Menu
{
  public:
    FUN_0075b0d0();

  private:
    unsigned char layoutExtension[0xe4];
};
// Constructor at 0x0072ceb0; runtime allocation is 0x120 bytes.
class BarterMenu : public Menu
{
  public:
    BarterMenu();

  private:
    unsigned char layoutExtension[0xf8];
};
// Constructor at 0x007617a0; runtime allocation is 0x13c bytes.
class FUN_007617a0 : public Menu
{
  public:
    FUN_007617a0();

  private:
    unsigned char layoutExtension[0x114];
};
// Constructor at 0x007bfb30; runtime allocation is 0x4c bytes.
class SleepWaitMenu : public Menu
{
  public:
    SleepWaitMenu();

  private:
    unsigned char layoutExtension[0x24];
};
// Constructor at 0x007cb330; runtime allocation is 0x1d4 bytes.
class FUN_007cb330 : public Menu
{
  public:
    FUN_007cb330();

  private:
    unsigned char layoutExtension[0x1ac];
};
// Constructor at 0x0078d930; runtime allocation is 0xe4 bytes.
class LockPickMenu : public Menu
{
  public:
    LockPickMenu();

  private:
    unsigned char layoutExtension[0xbc];
};
// Constructor at 0x00720a10; runtime allocation is 0x44 bytes.
class FUN_00720a10 : public Menu
{
  public:
    FUN_00720a10();

  private:
    unsigned char layoutExtension[0x1c];
};
// Constructor at 0x0073acb0; runtime allocation is 0x3c bytes.
class BookMenu : public Menu
{
  public:
    BookMenu();

  private:
    unsigned char layoutExtension[0x14];
};
// Constructor at 0x00784a40; runtime allocation is 0xcc bytes.
class LevelUpMenu : public Menu
{
  public:
    LevelUpMenu();

  private:
    unsigned char layoutExtension[0xa4];
};
// Constructor at 0x007ac1f0; runtime allocation is 0x1a4 bytes.
class RaceSexMenu : public Menu
{
  public:
    RaceSexMenu();

  private:
    unsigned char layoutExtension[0x17c];
};
// Constructor at 0x007b5400; runtime allocation is 0x8c bytes.
class RepairMenu : public Menu
{
  public:
    RepairMenu();

  private:
    unsigned char layoutExtension[0x64];
};
// Constructor at 0x00783310; runtime allocation is 0x90 bytes.
class ItemModMenu : public Menu
{
  public:
    ItemModMenu();

  private:
    unsigned char layoutExtension[0x68];
};
// Constructor at 0x007b7400; runtime allocation is 0xa0 bytes.
class RepairServicesMenu : public Menu
{
  public:
    RepairServicesMenu();

  private:
    unsigned char layoutExtension[0x78];
};
// Constructor at 0x007654f0; runtime allocation is 0x1dc bytes.
class HackingMenu : public Menu
{
  public:
    HackingMenu();

  private:
    unsigned char layoutExtension[0x1b4];
};
// Constructor at 0x007577f0; runtime allocation is 0xfc bytes.
class ComputersMenu : public Menu
{
  public:
    ComputersMenu();

  private:
    unsigned char layoutExtension[0xd4];
};
// Constructor at 0x0071fbf0; runtime allocation is 0x160 bytes.
class FUN_0071fbf0 : public Menu
{
  public:
    FUN_0071fbf0();

  private:
    unsigned char layoutExtension[0x138];
};
// Constructor at 0x00720040; runtime allocation is 0x144 bytes.
class VATSMenu : public Menu
{
  public:
    VATSMenu();

  private:
    char layoutExtension_pad28[128];
    void* m_pAdditionalHudTile;
    bool m_bStateFlag8;
    char layoutExtension_padad[3];
    char m_acMenuText[48];
    float m_fOverrideActionPoints;
    float m_fValue1;
    float m_fValue2;
    float m_fValue3;
    float m_fValue4;
    float m_fValue5;
    bool m_bFirstFlag;
    bool m_bStateFlag1;
    bool m_bStateFlag2;
    bool m_bStateFlag3;
    float m_fHitChance;
    void* m_pTargetChance;
    bool m_bStateFlag4;
    char layoutExtension_pad105[3];
    void* m_pSelectedChance;
    bool m_bStateFlag5;
    bool m_bStateFlag9;
    bool m_bAdditionalStateFlag;
    bool m_bStateFlag10;
    bool m_bStateFlag6;
    char layoutExtension_pad111[3];
    unsigned int m_uiTargetCount;
    bool m_bStateFlag7;
    char layoutExtension_pad119[3];
    char m_acTargetText[40];
};
// Constructor at 0x00753230; runtime allocation is 0x88 bytes.
class TraitMenu : public Menu
{
  public:
    TraitMenu();

  private:
    unsigned char layoutExtension[0x60];
};
// Constructor at 0x00720170; runtime allocation is 0x1e4 bytes.
class FUN_00720170 : public Menu
{
  public:
    FUN_00720170();

  private:
    unsigned char layoutExtension[0x1bc];
};
// Constructor at 0x00754b40; runtime allocation is 0x88 bytes.
class CharGenMenu : public Menu
{
  public:
    CharGenMenu();

  private:
    unsigned char layoutExtension[0x60];
};
// Constructor at 0x00720550; runtime allocation is 0x230 bytes.
class FUN_00720550 : public Menu
{
  public:
    FUN_00720550();

  private:
    unsigned char layoutExtension[0x208];
};
// Constructor at 0x007e7a80; runtime allocation is 0x88 bytes.
class TraitSelectMenu : public Menu
{
  public:
    TraitSelectMenu();

  private:
    unsigned char layoutExtension[0x60];
};
// Constructor at 0x007c06f0; runtime allocation is 0x158 bytes.
class SlotMachineMenu : public Menu
{
  public:
    SlotMachineMenu();

  private:
    unsigned char layoutExtension[0x130];
};
// Constructor at 0x007315e0; runtime allocation is 0xe70 bytes.
class BlackJackMenu : public Menu
{
  public:
    BlackJackMenu();

  private:
    unsigned char layoutExtension[0xe48];
};
// Constructor at 0x007e6780; runtime allocation is 0x8c bytes.
class RouletteMenu : public Menu
{
  public:
    RouletteMenu();

  private:
    unsigned char layoutExtension[0x64];
};
// Constructor at 0x007b8d30; runtime allocation is 0x4014 bytes.
class LoveTesterMenu : public Menu
{
  public:
    LoveTesterMenu();

  private:
    unsigned char layoutExtension[0x3fec];
};
// Constructor at 0x0073b7e0; runtime allocation is 0xe88 bytes.
class CaravanMenu : public Menu
{
  public:
    CaravanMenu();

  private:
    unsigned char layoutExtension[0xe60];
};
// Constructor at 0x00726df0; runtime allocation is 0x104 bytes.
class RecipeMenu : public Menu
{
  public:
    RecipeMenu();

  private:
    unsigned char layoutExtension[0xdc];
};
// Constructor at 0x0071fa80; runtime allocation is 0x5c bytes.
class MessageMenu : public Menu
{
  public:
    MessageMenu();

  private:
    unsigned char layoutExtension[0x34];
};
#endif
