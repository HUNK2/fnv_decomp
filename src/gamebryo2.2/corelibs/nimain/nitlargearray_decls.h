// gamebryo2.2/corelibs/nimain/nitlargearray_decls.h: declares NiFormArray
#ifndef NITLARGEARRAY_DECLS_H
#define NITLARGEARRAY_DECLS_H

#include "TESForm.h"
#include "TESTopicInfo.h"
#include "NiFixedString.h"
#include "NiRefObject.h"
#include "MemoryManager.h"
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
NiFixedString* __cdecl FUN_00a63ae0(unsigned int count);
extern MemoryManager g_memoryManager;

class ActorCombatGroup;
template <> class NiTMallocInterface<ActorCombatGroup*>
{
  public:
    static ActorCombatGroup** Allocate(unsigned short size);
    static void Deallocate(ActorCombatGroup** pointer);
};

template <> class NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >
{
  public:
    void** m_ppVirtualMethodTable;
    TESTopicInfo** m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    TESTopicInfo* RemoveAt(unsigned int index);
    void Compact();
};

template <> class NiTLargeArray<NiFixedString, NiTNewInterface<NiFixedString> >
{
  public:
    void** m_ppVirtualMethodTable;
    NiFixedString* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void RemoveAll();
    void SetSize(unsigned int size);
};
extern NiFixedString EmptyFS;

template <> class NiTMallocInterface<unsigned int>
{
  public:
    static unsigned int* Allocate(unsigned int size);
    static void Deallocate(unsigned int* pointer);
};

template <> class NiTLargeArray<unsigned int, NiTMallocInterface<unsigned int> >
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void RemoveAll();
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, const unsigned int& value);
    unsigned int SetAtGrow(unsigned int index, const unsigned int& value);
};
class NiFormArray
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void SetSize(unsigned int index, unsigned int* value);
};
template <> class NiTLargeArray<TESForm*, NiTMallocInterface<TESForm*> >
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void SetSize(unsigned int size);
};
#endif
