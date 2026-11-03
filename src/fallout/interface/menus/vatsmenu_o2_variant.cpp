
// src/fallout/interface/menus/vatsmenu_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/interface/menus/vatsmenu.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "vatsmenu_decls.h"
struct ItemListElement;
struct ItemList
{
    ItemListElement** FUN_006815c0();
    void FUN_0063f7b0();
};
struct ItemListContainer
{
    char pad[8];
    ItemList items;
    ~ItemListContainer();
};
struct TargetList
{
    ItemListContainer** FUN_006815c0();
    void FUN_0063f7b0();
};
struct GlobalObject2_0096a2d0
{
    int x;
};
extern GlobalObject2_0096a2d0 g_011db150;
void FUN_007f6920();
struct FUN_007ebd30_This
{
    char pad[0x374];
    float fValue;
    float __thiscall FUN_007ebd30();
};
extern int DAT_011db0d4;
void __cdecl FUN_007f3bd0(int a1);
struct ArrSI
{
    unsigned int GetFlags();
};
extern int DAT_011f2250;
struct Caller007efa10
{
    void __thiscall UpdateQueueEntry(int a1, int a2, int a3);
};
struct FUN_007ef710_This
{
    char _pad[0xF8];
    bool m_bFirstFlag;
    bool __thiscall HandleKey(int aiKey);
};
struct Tile;
struct FUN_0070ec70_This
{
    int __thiscall FUN_0070ec70();
};
void* __cdecl FUN_004b7210();
struct FUN_007ef760_Owner
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3(int, int);
    void __thiscall HandleMousewheel(int aiID, Tile* apTarget);
};
struct Vec2Tmp
{
    float x;
    float y;
    Vec2Tmp DivideBy(float) const;
};
struct TESObjectREFR
{
};
struct BSSimpleList
{
    bool FUN_008256d0();
    ItemListContainer** FUN_006815c0();
    BSSimpleList* FUN_00726070();
};
struct StandIn
{
    BSSimpleList* FindListEntryForTarget(TESObjectREFR* apTarget);
};
struct Tile;
struct Menu
{
    Tile* CreateTileFromTemplate(Tile*, char const*, Tile*);
};
void __cdecl _FNV_Warning(char const*);
void __cdecl _FUN_007037e0();
void __cdecl ShutdownVats();
Tile* FUN_007f4830(Tile* apParent, char const* axName);
struct Tile;
Tile* __cdecl FindNamedTile(Tile*, char const*);
void __cdecl _FNV_Warning(char const*);
void __cdecl _FUN_007037e0();
void __cdecl ShutdownVats();
Tile* __cdecl FUN_007f4890(Tile* a1, char const* a2);
struct AnimIdle
{
    int GetSection();
};
class GameTimerRecord
{
    char _d;
};
extern GameTimerRecord g_timeGlobal;
struct DAT_Pointee_7f4bb0
{
    char pad[0x10F];
    unsigned char flag;
    char pad2[4];
    int t;
};
bool FUN_007f4bb0();
struct Tile;
struct ListBox
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Tile* v5(int);
    int GetFilteredCount(int);
    Tile* FUN_007f6fb0();
};
