// fallout/interface/menus/surgerymenu_decls.h: declares SurgeryMenu, PerkEntryHandler
#ifndef SURGERYMENU_DECLS_H
#define SURGERYMENU_DECLS_H

class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
};
class GlobalObject2_0096a2d0;
extern GlobalObject2_0096a2d0 g_011dae48;
extern void* DAT_011dada4;
class SurgeryMenu
{
  public:
    class PerkEntryHandler
    {
      public:
        void RefreshPerkState();
    };
    static void UpdatePerkEntries();
};
#endif
