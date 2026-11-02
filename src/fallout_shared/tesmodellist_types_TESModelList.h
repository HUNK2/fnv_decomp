// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESMODELLIST_H
#define FNV_TESMODELLIST_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "layout_support.h"
class TESModelList;
class FileEntryList;
class FileEntryListCollection;
#pragma pack(push, 4)
class FileEntryListCollection
{
  public:
    unsigned int m_uiFileEntryCount;    // +0x0, 4 bytes
    FileEntryList** m_ppElementArray;  // +0x4, 4 bytes
    FileEntryListCollection* ClearData(unsigned int flags);
    void FUN_00475220();
    void ClearAndDeleteArray();
    // void __cdecl FileEntryListCollection::*()
    // void __cdecl FileEntryListCollection::*(CHUNK_ID)
    // void __cdecl FileEntryListCollection::*(TESModelList*, TESFile*)
    // void __cdecl FileEntryListCollection::*(FileEntryListCollection*)
    // void __cdecl FileEntryListCollection::*()
    // FileEntryList* __cdecl FileEntryListCollection::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryListCollection) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryListCollection, m_uiFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryListCollection, m_ppElementArray) == 4);
#pragma pack(push, 4)
class TESModelList : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSSimpleList<const char*> m_kModelPaths;  // +0x4, 8 bytes
    FileEntryListCollection m_kModelData;     // +0xC, 8 bytes
    void ClearComponent();
    bool HasModels();
    unsigned int BaseFormRecord(unsigned int type);
    ~TESModelList();
    // TESModelList
    // void __cdecl TESModelList::*()
    // void __cdecl TESModelList::*()
    // void __cdecl TESModelList::*()
    // bool __cdecl TESModelList::*(const char*)
    // void __cdecl TESModelList::*(const char*)
    // bool __cdecl TESModelList::*()
    // BSSimpleList<char const *>* __cdecl TESModelList::*()
    // void __cdecl TESModelList::*(CHUNK_ID, CHUNK_ID)
    // void __cdecl TESModelList::*(TESModelList*, TESFile*)
    // void __cdecl TESModelList::*(BaseFormComponent*)
    // bool __cdecl TESModelList::*(BaseFormComponent*)
    // FileEntryListCollection* __cdecl TESModelList::*()
    // TESModelList& __cdecl TESModelList::*(const TESModelList&)
    // void* __cdecl TESModelList::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModelList) == 20);
FNV_STATIC_ASSERT(offsetof(TESModelList, m_kModelPaths) == 4);
FNV_STATIC_ASSERT(offsetof(TESModelList, m_kModelData) == 12);
#endif
