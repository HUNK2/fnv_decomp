// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PACKAGETARGET_H
#define FNV_PACKAGETARGET_H
#include "layout_support.h"
#include "lowprocess_TESForm.h"
#include "lowprocess_TESObjectREFR.h"
#include "layout_support.h"
class PackageTargetRecord;
#pragma pack(push, 4)
class PackageTargetRecord
{
  public:
    int GetTargetKind();
    TESObjectREFR* GetReferenceTarget();
    TESForm* GetTargetForm();
    PACKAGE_OBJECT_TYPE GetTargetObjectType();
    int GetCount();

    unsigned char m_uiTargetType;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    union
    {                                  // overlapping CodeView storage
        TESObjectREFR* m_pWorldReferenceInfo;     // +0x4, 4 bytes
        TESForm* pObject;              // +0x4, 4 bytes
        TESForm* pTargetForm;          // +0x4, 4 bytes
        PACKAGE_OBJECT_TYPE eObjType;  // +0x4, 4 bytes
    };
    int iValue;            // +0x8, 4 bytes
    float m_fTargetValue;  // +0xC, 4 bytes
    // PackageTargetRecord
    // void __cdecl PackageTargetRecord::*()
    // PACK_TARG_TYPE __cdecl PackageTargetRecord::*()
    // TESForm* __cdecl PackageTargetRecord::*()
    // PACKAGE_OBJECT_TYPE __cdecl PackageTargetRecord::*()
    // int __cdecl PackageTargetRecord::*()
    // float __cdecl PackageTargetRecord::*()
    // void __cdecl PackageTargetRecord::*(PACK_TARG_TYPE)
    // void __cdecl PackageTargetRecord::*(TESObjectREFR*)
    // void __cdecl PackageTargetRecord::*(TESForm*)
    // void __cdecl PackageTargetRecord::*(PACKAGE_OBJECT_TYPE)
    // void __cdecl PackageTargetRecord::*(int)
    // void __cdecl PackageTargetRecord::*(float)
    // bool __cdecl PackageTargetRecord::*(TESForm*)
    // void __cdecl PackageTargetRecord::*(PackageTargetRecord*)
    // bool __cdecl PackageTargetRecord::*(PackageTargetRecord*)
    // void __cdecl PackageTargetRecord::*(CHUNK_ID)
    // void __cdecl PackageTargetRecord::*(TESForm*)
    // unsigned short __cdecl PackageTargetRecord::*()
    // SaveGame
    // LoadGame
    // InitLoadGame
    // TESObjectREFR* __cdecl PackageTargetRecord::*()
    // void* __cdecl PackageTargetRecord::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PackageTargetRecord) == 16);
FNV_STATIC_ASSERT(offsetof(PackageTargetRecord, m_uiTargetType) == 0);
FNV_STATIC_ASSERT(offsetof(PackageTargetRecord, m_pWorldReferenceInfo) == 4);
FNV_STATIC_ASSERT(offsetof(PackageTargetRecord, pObject) == 4);
FNV_STATIC_ASSERT(offsetof(PackageTargetRecord, pTargetForm) == 4);
FNV_STATIC_ASSERT(offsetof(PackageTargetRecord, eObjType) == 4);
FNV_STATIC_ASSERT(offsetof(PackageTargetRecord, iValue) == 8);
FNV_STATIC_ASSERT(offsetof(PackageTargetRecord, m_fTargetValue) == 12);
#endif
