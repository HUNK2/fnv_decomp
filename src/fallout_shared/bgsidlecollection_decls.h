// fallout_shared/bgsidlecollection_decls.h: declares TESObjectANIO, TESIdleForm, TESFormInitFlag, Actor
#ifndef FALLOUT_SHARED_BGSIDLECOLLECTION_DECLS_H
#define FALLOUT_SHARED_BGSIDLECOLLECTION_DECLS_H

#include "TESForm.h"
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    unsigned int GetSize();
    void SetAt(unsigned int, T&);
    unsigned int Add(T&);
};
#include "bgsidlecollection_types_BGSIdleCollection.h"

class TESObjectANIO : public TESForm
{
};

class TESIdleForm : public TESObjectANIO
{
  public:
    bool IsIdleFile();
    bool IsValidForReferences(TESObjectREFR*, TESObjectREFR*, bool);
};

class TESFormInitFlag
{
  public:
    static TESForm* GetFormByID(unsigned int formID);
};

extern "C" const char kBGSIdleCollectionMissingIdle[];
extern "C" const char kBGSIdleCollectionMissingAnim[];
int Warning(const char* format, ...);

class Actor
{
  public:
    bool HasIdleInFormArray(TESIdleForm*);
};
bool FUN_00479e20(unsigned int);
template <int N> struct EndianSizeTag
{
};
void BSEndian(unsigned int*, EndianSizeTag<4>);
void* operator new[](unsigned int);
void operator delete[](void*);
extern "C" void* memset(void*, int, unsigned int);
#endif
