// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESCLASS_H
#define FNV_TESCLASS_H

typedef int ENUM_FORM_ID;
typedef int ActorValue__Index;
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESDescription.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESTexture.h"
class TESClassData;
class TESAttributes;
class TESClass;
#pragma pack(push, 4)
class TESAttributes : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned char cAttribute[7];  // +0x4, 7 bytes
    unsigned char layoutPaddingB[1];
    // TESAttributes
    // void __cdecl TESAttributes::*()
    // void __cdecl TESAttributes::*()
    // void __cdecl TESAttributes::*()
    // unsigned int __cdecl TESAttributes::*(void*)
    // unsigned int __cdecl TESAttributes::*(void*)
    // void __cdecl TESAttributes::*(BaseFormComponent*)
    // bool __cdecl TESAttributes::*(BaseFormComponent*)
    // unsigned int __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*(ActorValue::Index)
    // void __cdecl TESAttributes::*(ActorValue::Index, unsigned char, bool)
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // unsigned char __cdecl TESAttributes::*()
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // void __cdecl TESAttributes::*(unsigned char)
    // unsigned short __cdecl TESAttributes::*(unsigned int)
    // SaveGame
    // LoadGame
    // TESAttributes& __cdecl TESAttributes::*(const TESAttributes&)
    // void* __cdecl TESAttributes::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESAttributes) == 12);
FNV_STATIC_ASSERT(offsetof(TESAttributes, cAttribute) == 4);
#pragma pack(push, 4)
class TESClassData
{
  public:
    ActorValue__Index m_aeTaggedSkills[4];  // +0x0, 16 bytes
    char m_ucClassFlags;                    // +0x10, 1 bytes
    unsigned char layoutPadding11[3];
    int m_uiField08;            // +0x14, 4 bytes
    unsigned char m_ucField0C;  // +0x18, 1 bytes
    unsigned char m_ucField0D;  // +0x19, 1 bytes
    unsigned char layoutPadding1A[2];
    // void __cdecl TESClassData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESClassData) == 28);
FNV_STATIC_ASSERT(offsetof(TESClassData, m_aeTaggedSkills) == 0);
FNV_STATIC_ASSERT(offsetof(TESClassData, m_ucClassFlags) == 16);
FNV_STATIC_ASSERT(offsetof(TESClassData, m_uiField08) == 20);
FNV_STATIC_ASSERT(offsetof(TESClassData, m_ucField0C) == 24);
FNV_STATIC_ASSERT(offsetof(TESClassData, m_ucField0D) == 25);
#pragma pack(push, 4)
class TESClass : public TESForm, public TESFullName, public TESDescription, public TESTexture, public TESAttributes
{
  public:
    // base TESForm at +0x0, size 24
    // base TESFullName at +0x18, size 12
    // base TESDescription at +0x24, size 8
    // base TESTexture at +0x2C, size 12
    // base TESAttributes at +0x38, size 12
    bool IsGuard();
    TESClassData data;  // +0x44, 28 bytes
    // TESClass
    // void __cdecl TESClass::*()
    // void __cdecl TESClass::*()
    // void __cdecl TESClass::*()
    // bool __cdecl TESClass::*(TESFile*)
    // void __cdecl TESClass::*(TESForm*)
    // bool __cdecl TESClass::*(TESForm*)
    // bool __cdecl TESClass::*()
    // void __cdecl TESClass::*(bool)
    // int __cdecl TESClass::*()
    // ActorValue::Index __cdecl TESClass::*(int)
    // void __cdecl TESClass::*(int, ActorValue::Index)
    // int __cdecl TESClass::*()
    // void __cdecl TESClass::*(int)
    // ActorValue::Index __cdecl TESClass::*()
    // void __cdecl TESClass::*(ActorValue::Index)
    // unsigned char __cdecl TESClass::*()
    // void __cdecl TESClass::*(unsigned char)
    // bool __cdecl TESClass::*()
    // bool __cdecl TESClass::*(ActorValue::Index)
    // unsigned short __cdecl TESClass::*()
    // SaveGame
    // LoadGame
    // void __cdecl TESClass::*(BGSLoadFormBuffer*)
    // TESClassData* __cdecl TESClass::*()
    // TESClass& __cdecl TESClass::*(const TESClass&)
    // void __cdecl TESClass::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESClass) == 96);
FNV_STATIC_ASSERT(offsetof(TESClass, data) == 68);
#endif
