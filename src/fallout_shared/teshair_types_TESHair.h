// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESHAIR_H
#define FNV_TESHAIR_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESTexture.h"
#include "layout_support.h"
class BSFileEntry;
class TESHair;
class TESModel;
class TESNPC;
class TESFile;
class FileEntryList;
#pragma pack(push, 4)
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
    // void __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*()
    // bool __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*(CHUNK_ID, const char*)
    // void __cdecl FileEntryList::*(TESFile*, TESForm*, const char*)
    // void __cdecl FileEntryList::*(FileEntryList*)
    // unsigned char __cdecl FileEntryList::*()
    // BSFileEntry** __cdecl FileEntryList::*()
    // void* __cdecl FileEntryList::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
#pragma pack(push, 4)
class TESModel : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    // TESModel
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*(CHUNK_ID, CHUNK_ID)
    // void __cdecl TESModel::*(BaseFormComponent*)
    // bool __cdecl TESModel::*(BaseFormComponent*)
    // void __cdecl TESModel::*(CHUNK_ID)
    // GetModelLength
    // bool __cdecl TESModel::*(CHUNK_ID)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // bool __cdecl TESModel::*()
    // char __cdecl TESModel::*()
    // void __cdecl TESModel::*(char)
    // bool __cdecl TESModel::*()
    // void __cdecl TESModel::*(bool)
    // unsigned int __cdecl TESModel::*()
    // void __cdecl TESModel::*(unsigned int)
    // bool __cdecl TESModel::*()
    // FileEntryList* __cdecl TESModel::*()
    // TESModel& __cdecl TESModel::*(const TESModel&)
    // void __cdecl TESModel::*()
    TESModel();
    static void LoadModelData(TESModel* model, TESFile* file);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
#pragma pack(push, 4)
class TESHair : public TESForm, public TESFullName, public TESModel, public TESTexture
{
  public:
    // base TESForm at +0x0, size 24
    // base TESFullName at +0x18, size 12
    // base TESModel at +0x24, size 24
    // base TESTexture at +0x3C, size 12
    char cFlags;  // +0x48, 1 bytes
    unsigned char layoutPadding49[3];
    // TESHair
    // void __cdecl TESHair::*()
    // void __cdecl TESHair::*()
    // void __cdecl TESHair::*()
    // bool __cdecl TESHair::*(TESFile*)
    // void __cdecl TESHair::*(TESForm*)
    // bool __cdecl TESHair::*(TESForm*)
    // bool __cdecl TESHair::*()
    // void __cdecl TESHair::*(bool)
    // bool __cdecl TESHair::*()
    // void __cdecl TESHair::*(bool)
    // bool __cdecl TESHair::*()
    // void __cdecl TESHair::*(bool)
    // bool __cdecl TESHair::*()
    // void __cdecl TESHair::*(bool)
    // bool __cdecl TESHair::*(TESNPC*)
    // TESHair& __cdecl TESHair::*(const TESHair&)
    // void __cdecl TESHair::*()
    TESHair();
    virtual bool Load(TESFile* file);
    virtual bool IsValidForNPC(TESNPC* npc);
    void ResetFormData();
    bool FUN_005fdf60();
    bool IsFlag4Clear();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESHair) == 76);
FNV_STATIC_ASSERT(offsetof(TESHair, cFlags) == 72);
#endif
