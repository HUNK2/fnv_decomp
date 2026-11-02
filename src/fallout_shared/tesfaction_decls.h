#ifndef TESFACTION_DECLS_H
#define TESFACTION_DECLS_H


class ReactionInfo
{
  public:
    char data[12];
    void Endian();
};
class BGSLoadFormBuffer;
#include "tesfaction_types_TESFaction.h"
#include "tesfaction_types_BGSLoadFormBuffer.h"
#include "tesfaction_types_RANK_DATA.h"
#include "TESReactionForm.h"

class TESDataHandler;

class TESFormBufferAccess : public TESForm
{
  public:
    virtual void LoadGame(BGSLoadFormBuffer*);
    virtual void Revert(BGSLoadFormBuffer*);
};

class TESReactionFormBufferAccess : public TESReactionForm
{
  public:
    void InitItem(TESForm*);
    void InitLoadGame(BGSLoadFormBuffer*);
    void FUN_0048ca90(BGSLoadFormBuffer*);
};

struct TESFactionReactionView
{
    TESForm form;
    TESFullName fullName;
    TESReactionFormBufferAccess reaction;
};

FNV_STATIC_ASSERT(offsetof(TESFactionReactionView, reaction) == 0x24);

class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};

class TESDataHandlerAccess
{
  public:
    TESReputation* GetReputation(unsigned int);
};

void* __cdecl Allocate(unsigned int);
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESReactionFormLoader
{
  public:
    BSSimpleList<ReactionInfo*>* GetReactionList();
};
class TESFactionRecordLoader
{
  public:
    void ReadTypedData(TESFile*, void*, unsigned short);
};
#endif
