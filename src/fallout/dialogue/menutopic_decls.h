// fallout/dialogue/menutopic_decls.h: declares MiscStatManager, MenuTopicText, MenuTopicActorValueOwner, MenuTopicPlayer

class MiscStatManager
{
  public:
    enum MiscStat
    {
        MS_COUNT = 43
    };
    static void AddMiscStat(MiscStat, int);
};

#ifndef FNV_MENUTOPIC_EXTENSIONS_H
#define FNV_MENUTOPIC_EXTENSIONS_H
class MobileObject;
class PlayerCharacter;
#include "menutopic_layout.h"
#include "menutopic_tesfullname.h"
#include "menutopic_tesobjectrefr.h"
#include "menutopic_testopic.h"
#include "menutopic_testopicinfo.h"
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern PlayerCharacter* g_thePlayer;
int __cdecl Warning(const char*, ...);
class MenuTopicText
{
  public:
    void FUN_00965250();
};
class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*>* GetLinkToList();
};
class MenuTopicActorValueOwner
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual int GetActorValue(int);
};
class MenuTopicPlayer
{
  public:
    unsigned char padding[0xa4];
    MenuTopicActorValueOwner actorValues;
};
class GlobalObject2_0040c150
{
  public:
    int* Int();
};
extern GlobalObject2_0040c150 g_011d0dc8;
#endif
