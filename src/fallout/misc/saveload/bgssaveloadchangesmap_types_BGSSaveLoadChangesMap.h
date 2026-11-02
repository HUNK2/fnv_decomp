// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSSAVELOADCHANGESMAP_H
#define FNV_BGSSAVELOADCHANGESMAP_H

#include "layout_support.h"
#include "layout_support.h"
class FormChangeRecord;
class FormChangeMask;
class BGSSaveLoadChangesMap;
#pragma pack(push, 4)
class BGSSaveLoadChangesMapBase
{
  public:
    unsigned int layout[4];
};
class BGSSaveLoadChangesMap : public BGSSaveLoadChangesMapBase
{
  public:
    // base NiTPointerMap<unsigned int,FormChangeRecord *> at +0x0, size 16
    BGSSaveLoadChangesMap();
    void FUN_00845b30(unsigned int hashSize);
    FormChangeRecord* FUN_009a4250(unsigned int formID);
    bool ContainsChangeFlags(unsigned int formID, FormChangeMask flags);
    void AddFormChangeFlags(unsigned int formID, FormChangeMask flags);
    void ApplyFormQuantityChange(unsigned int formID, FormChangeMask flags);
    bool HasFormChanges(unsigned int formID);
    bool ClearChangeFlags(unsigned int formID, FormChangeMask flags);
    bool RemoveAt(unsigned int formID);
    void SetAt(unsigned int formID, FormChangeRecord* changes);
    // BGSSaveLoadChangesMap
    // void __cdecl BGSSaveLoadChangesMap::*()
    // void __cdecl BGSSaveLoadChangesMap::*()
    // FormChangeRecord* __cdecl BGSSaveLoadChangesMap::*(unsigned int)
    // FormChangeMask __cdecl BGSSaveLoadChangesMap::*(unsigned int)
    // bool __cdecl BGSSaveLoadChangesMap::*(unsigned int, FormChangeMask)
    // void __cdecl BGSSaveLoadChangesMap::*(unsigned int, FormChangeMask)
    // void __cdecl BGSSaveLoadChangesMap::*(unsigned int, FormChangeMask)
    // bool __cdecl BGSSaveLoadChangesMap::*(unsigned int)
    // bool __cdecl BGSSaveLoadChangesMap::*(unsigned int, FormChangeMask)
    // BGSSaveLoadChangesMap& __cdecl BGSSaveLoadChangesMap::*(const BGSSaveLoadChangesMap&)
    // void __cdecl BGSSaveLoadChangesMap::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSSaveLoadChangesMap) == 16);
#endif
