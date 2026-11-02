// fallout/interface/menus/playernameentrymenu_decls.h: declares PlayerNameEntryMenu
#pragma once


const char* __cdecl FUN_007ab810();
void __cdecl FUN_007ab7c0();

class PlayerNameEntryMenu
{
  public:
    void UpdateDialog();
    void Finish(const char* name);
};
