// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSBIPEDMODELLIST_H
#define FNV_BGSBIPEDMODELLIST_H
#include "layout_support.h"
#include "BaseFormComponent.h"
class BGSBipedModelList;
class BGSListForm;
#pragma pack(push, 4)
class BGSBipedModelList : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BGSListForm* pListForm;  // +0x4, 4 bytes
    // BGSBipedModelList
    // void __cdecl BGSBipedModelList::*()
    // void __cdecl BGSBipedModelList::*()
    // void __cdecl BGSBipedModelList::*()
    // void __cdecl BGSBipedModelList::*()
    // void __cdecl BGSBipedModelList::*(BaseFormComponent*)
    // bool __cdecl BGSBipedModelList::*(BaseFormComponent*)
    // void __cdecl BGSBipedModelList::*(TESForm*)
    // bool __cdecl BGSBipedModelList::*(TESForm*)
    // BGSBipedModelList* __cdecl BGSBipedModelList::*(TESForm*)
    // BGSListForm* __cdecl BGSBipedModelList::*()
    BGSListForm* GetList();
    // void __cdecl BGSBipedModelList::*(BGSListForm*)
    // BGSBipedModelList& __cdecl BGSBipedModelList::*(const BGSBipedModelList&)
    // void* __cdecl BGSBipedModelList::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSBipedModelList) == 8);
FNV_STATIC_ASSERT(offsetof(BGSBipedModelList, pListForm) == 4);
#endif
