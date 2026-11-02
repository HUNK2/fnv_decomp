// fallout_shared/teslevitem_decls.h: declares SettingT_GameSettingCollection_, ContainerItemExtra, LeveledObject, TESLeveledList, TESLevItem
#ifndef TESLEVITEM_DECLS_H
#define TESLEVITEM_DECLS_H

union SETTING_VALUE
{
    int i;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Int();
};
class GlobalObject2_0040c150 : public SettingT_GameSettingCollection_
{
};
extern GlobalObject2_0040c150 g_011c8f00;
#include "TESForm.h"
class ContainerItemExtra
{
  public:
    unsigned int data[3];
    static void* operator new(unsigned int);
    static void operator delete(void*);
    ContainerItemExtra();
    bool Load(TESFile*);
};
class LeveledObject
{
  public:
    unsigned short level;
    unsigned short pad;
    TESForm* form;
    unsigned short count;
    unsigned short pad2;
    void SwapEndian();
};
class TESLeveledList
{
  public:
    unsigned char bytes[13];
    unsigned char flags;
    unsigned char pad[2];
    unsigned int global;
    LeveledObject* CreateLeveledObject(unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    void FUN_0042e680(unsigned char);
    void InitItem(TESForm* owner);
};
class TESLevItem : public TESForm
{
  public:
    unsigned char bound[24];
    TESLeveledList list;
    int GetMaxLevelDifference();
    bool Load(TESFile*);
    virtual void InitItem();
};
extern LeveledObject* DAT_011c8f1c;
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl _alloca(unsigned int);
#endif
