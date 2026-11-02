// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSIDLECOLLECTION_H
#define FNV_BGSIDLECOLLECTION_H

#include "layout_support.h"
#include "BaseFormComponent.h"
class BGSIdleCollection;
class TESIdleForm;
#pragma pack(push, 4)
class BGSIdleCollection : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned char m_ucIdleCount;  // +0x4, 1 bytes
    unsigned char m_ucPickType;   // +0x5, 1 bytes
    unsigned char layoutPadding6[2];
    TESIdleForm** m_ppIdleForms;  // +0x8, 4 bytes
    float m_fIdleChance;          // +0xC, 4 bytes
    unsigned int GetAvailableIdles(Actor*, TESObjectREFR*, BSSimpleArray<TESIdleForm*, 1024>*);
    void Load(TESFile* file);
    void InitializeComponent();
    void InitItem(TESForm* form);
    void RemoveIdleEntry(unsigned int index);
    int GetPickType();
    // BGSIdleCollection
    // void __cdecl BGSIdleCollection::*()
    // void __cdecl BGSIdleCollection::*()
    // void __cdecl BGSIdleCollection::*()
    // void __cdecl BGSIdleCollection::*(BaseFormComponent*)
    // bool __cdecl BGSIdleCollection::*(BaseFormComponent*)
    // void __cdecl BGSIdleCollection::*()
    // void __cdecl BGSIdleCollection::*(TESForm*)
    // void __cdecl BGSIdleCollection::*(TESFile*)
    // bool __cdecl BGSIdleCollection::*(CHUNK_ID)
    // int __cdecl BGSIdleCollection::*()
    // TESIdleForm* __cdecl BGSIdleCollection::*(unsigned int)
    // BGSIdleCollection::PICK_TYPE __cdecl BGSIdleCollection::*()
    // void __cdecl BGSIdleCollection::*(BGSIdleCollection::PICK_TYPE)
    // bool __cdecl BGSIdleCollection::*()
    // void __cdecl BGSIdleCollection::*(bool)
    // void __cdecl BGSIdleCollection::*(TESIdleForm*, unsigned int)
    // void __cdecl BGSIdleCollection::*(unsigned int)
    // void __cdecl BGSIdleCollection::*(unsigned int, unsigned int)
    // bool __cdecl BGSIdleCollection::*(Actor*, TESObjectREFR*)
    // unsigned int __cdecl BGSIdleCollection::*(Actor*, TESObjectREFR*, BSSimpleArray<TESIdleForm *,1024>*)
    // BGSIdleCollection& __cdecl BGSIdleCollection::*(const BGSIdleCollection&)
    // void* __cdecl BGSIdleCollection::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSIdleCollection) == 16);
FNV_STATIC_ASSERT(offsetof(BGSIdleCollection, m_ucIdleCount) == 4);
FNV_STATIC_ASSERT(offsetof(BGSIdleCollection, m_ucPickType) == 5);
FNV_STATIC_ASSERT(offsetof(BGSIdleCollection, m_ppIdleForms) == 8);
FNV_STATIC_ASSERT(offsetof(BGSIdleCollection, m_fIdleChance) == 12);
#endif
