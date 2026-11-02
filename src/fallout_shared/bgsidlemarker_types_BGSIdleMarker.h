// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSIDLEMARKER_H
#define FNV_BGSIDLEMARKER_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
class BGSIdleCollection;
class BGSIdleMarker;
class ShortPoint3;
class TESBoundObject__BOUND_DATA;
class TESIdleForm;
class TESFormList;
#pragma pack(push, 4)
class TESObject : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
    // TESObject
    // void __cdecl TESObject::*()
    // NiAVObject* __cdecl TESObject::*()
    // unsigned int __cdecl TESObject::*()
    // TESFormList* __cdecl TESObject::*()
    // unsigned int __cdecl TESObject::*()
    // bool __cdecl TESObject::*()
    // char* __cdecl TESObject::*()
    // void __cdecl TESObject::*(TESFormList*)
    // void __cdecl TESObject::*(TESObject*)
    // void __cdecl TESObject::*(TESObject*)
    // TESObject* __cdecl TESObject::*()
    // TESObject* __cdecl TESObject::*()
    // NiAVObject* __cdecl TESObject::*(NiAVObject*, const char*)
    // const char* __cdecl TESObject::*(TESObjectREFR*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // TESObject& __cdecl TESObject::*(const TESObject&)
    // void __cdecl TESObject::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObject) == 36);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pOwningList) == 24);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pPreviousObject) == 28);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pNextObject) == 32);
#pragma pack(push, 4)
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
    // ShortPoint3
    // short& __cdecl ShortPoint3::*(int)
    // operator=
    // operator==
    // operator!=
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&)
    // operator-
    // operator*
    // ShortPoint3 __cdecl ShortPoint3::*(float)
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&, const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(float)
    // ShortPoint3& __cdecl ShortPoint3::*(float)
    // float __cdecl ShortPoint3::*()
    // short __cdecl ShortPoint3::*()
    // short __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&)
    // float __cdecl ShortPoint3::*()
    // float __cdecl ShortPoint3::*()
    // float __cdecl ShortPoint3::*()
    // void __cdecl ShortPoint3::*(float)
    // void __cdecl ShortPoint3::*(float)
    // void __cdecl ShortPoint3::*(float)
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // void __cdecl ShortPoint3::*(NiStream&)
    // void __cdecl ShortPoint3::*(NiStream&)
    // char* __cdecl ShortPoint3::*(const char*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ShortPoint3) == 6);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, y) == 2);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, z) == 4);
#pragma pack(push, 4)
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject__BOUND_DATA) == 12);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMax) == 6);
#pragma pack(push, 4)
class TESBoundObject : public TESObject
{
  public:
    // base TESObject at +0x0, size 36
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
    // TESBoundObject
    // void __cdecl TESBoundObject::*()
    // bool __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*(NiAVObject*)
    // void __cdecl TESBoundObject::*(TESBoundObject*)
    // NiPoint3 __cdecl TESBoundObject::*()
    // NiPoint3 __cdecl TESBoundObject::*()
    // float __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*(TESFile*)
    // bool __cdecl TESBoundObject::*(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int)
    // bool __cdecl TESBoundObject::*(bool)
    // TESBoundObject& __cdecl TESBoundObject::*(const TESBoundObject&)
    // void __cdecl TESBoundObject::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 48);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, TESBoundObjectBounds) == 36);
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
#pragma pack(push, 4)
class BGSIdleMarker : public TESBoundObject, public BGSIdleCollection
{
  public:
    // base TESBoundObject at +0x0, size 48
    // base BGSIdleCollection at +0x30, size 16
    // BGSIdleMarker
    // void __cdecl BGSIdleMarker::*()
    // bool __cdecl BGSIdleMarker::*(TESFile*)
    // void __cdecl BGSIdleMarker::*()
    // void __cdecl BGSIdleMarker::*(TESForm*)
    // bool __cdecl BGSIdleMarker::*(TESForm*)
    // void __cdecl BGSIdleMarker::*()
    // NiAVObject* __cdecl BGSIdleMarker::*(TESObjectREFR*)
    // void __cdecl BGSIdleMarker::*(TESObjectREFR*)
    // BGSIdleMarker& __cdecl BGSIdleMarker::*(const BGSIdleMarker&)
    // void __cdecl BGSIdleMarker::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSIdleMarker) == 64);
#endif
