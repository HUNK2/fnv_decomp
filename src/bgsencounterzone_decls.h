// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSENCOUNTERZONE_H
#define FNV_BGSENCOUNTERZONE_H

#include "bgsencounterzone_layout_support.h"
#include "bgsencounterzone_TESForm.h"
class BGSEncounterZone;
class EncounterZoneData;
class CellDetachData;
class EncounterZoneData
{
  public:
    void Endian();
    TESForm* m_pOwnerForm;              // +0x0, 4 bytes
    char m_cRank;                       // +0x4, 1 bytes
    unsigned char m_ucByteBeforeFlags;  // +0x5, 1 bytes
    char cFlags;                        // +0x6, 1 bytes
    unsigned char layoutPadding7[1];
    // void __cdecl EncounterZoneData::*()
};
FNV_STATIC_ASSERT(sizeof(EncounterZoneData) == 8);
FNV_STATIC_ASSERT(offsetof(EncounterZoneData, m_pOwnerForm) == 0);
FNV_STATIC_ASSERT(offsetof(EncounterZoneData, m_cRank) == 4);
FNV_STATIC_ASSERT(offsetof(EncounterZoneData, m_ucByteBeforeFlags) == 5);
FNV_STATIC_ASSERT(offsetof(EncounterZoneData, cFlags) == 6);
class CellDetachData
{
  public:
    unsigned int m_uiDetachTime;                 // +0x0, 4 bytes
    unsigned int m_uiFirstValueAfterDetachTime;  // +0x4, 4 bytes
    unsigned int DetachTimeRecord;               // +0x8, 4 bytes
    unsigned short m_usDetachRecordValue;        // +0xC, 2 bytes
    unsigned char layoutPaddingE[2];
    // void __cdecl CellDetachData::*()
};
FNV_STATIC_ASSERT(sizeof(CellDetachData) == 16);
FNV_STATIC_ASSERT(offsetof(CellDetachData, m_uiDetachTime) == 0);
FNV_STATIC_ASSERT(offsetof(CellDetachData, m_uiFirstValueAfterDetachTime) == 4);
FNV_STATIC_ASSERT(offsetof(CellDetachData, DetachTimeRecord) == 8);
FNV_STATIC_ASSERT(offsetof(CellDetachData, m_usDetachRecordValue) == 12);
class BGSEncounterZone : public TESForm
{
  public:
    unsigned short GetCalculatedLevel();
    bool QMatchPCBelowMin();
    unsigned char GetByteAt1D();
    BGSEncounterZone();
    virtual ~BGSEncounterZone();
    void ResetFormData();
    bool Load(TESFile* file);
    virtual void InitItem();
    static void CreateDefaultEncounterZone();
    static BGSEncounterZone* ms_pDefaultEncounterZone;
    // base TESForm at +0x0, size 24
    EncounterZoneData Data;   // +0x18, 8 bytes
    CellDetachData GameData;  // +0x20, 16 bytes
    // BGSEncounterZone
    // void __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*()
    // bool __cdecl BGSEncounterZone::*(TESFile*)
    // void __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*(TESForm*)
    // bool __cdecl BGSEncounterZone::*(TESForm*)
    // TESForm* __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*(TESForm*)
    // int __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*(int)
    // unsigned char __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*(unsigned char)
    // bool __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*(bool)
    // bool __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*(bool)
    // unsigned int __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*(unsigned int)
    // unsigned int __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*(unsigned int)
    // bool __cdecl BGSEncounterZone::*(TESObjectCELL*)
    // unsigned short __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*(unsigned int)
    // unsigned short __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*()
    // bool __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*(BGSSaveFormBuffer*)
    // void __cdecl BGSEncounterZone::*(BGSLoadFormBuffer*)
    // void __cdecl BGSEncounterZone::*(BGSLoadFormBuffer*)
    // void __cdecl BGSEncounterZone::*()
    // void __cdecl BGSEncounterZone::*()
    // BGSEncounterZone* __cdecl BGSEncounterZone::*()
    // BGSEncounterZone& __cdecl BGSEncounterZone::*(const BGSEncounterZone&)
    // void __cdecl BGSEncounterZone::*()
};
FNV_STATIC_ASSERT(sizeof(BGSEncounterZone) == 48);
FNV_STATIC_ASSERT(offsetof(BGSEncounterZone, Data) == 24);
FNV_STATIC_ASSERT(offsetof(BGSEncounterZone, GameData) == 32);
#endif