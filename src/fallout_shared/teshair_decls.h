// fallout_shared/teshair_decls.h: declares TESActorBase, TESHairRaceResult, TESHairCanBeNPCData, TESTextureLoader, TESFileFormInt
#ifndef FNV_TESHAIR_DECLS_H
#define FNV_TESHAIR_DECLS_H


#include "TESForm.h"

class TESActorBase;
enum SEX
{
    eSex_Male = 0,
    eSex_Female = 1
};
class TESActorBase
{
  public:
    SEX GetSex() const;
};

class BGSQuestObjective;
template <> class BSSimpleList<BGSQuestObjective*>
{
  public:
    BGSQuestObjective* m_item;
    BSSimpleList<BGSQuestObjective*>* m_pkNext;
    bool IsInList(BGSQuestObjective*& item);
};

class TESHairRaceResult
{
  public:
    BSSimpleList<BGSQuestObjective*>* FUN_0045bb80();
};

class TESHairCanBeNPCData
{
  public:
    TESHairRaceResult* FUN_004ac110();
};

class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture* texture, TESFile* file);
};

class TESFileFormInt
{
  public:
    int GetTESForm();
};

#endif
