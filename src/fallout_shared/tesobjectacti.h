// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESOBJECTACTI_H
#define FNV_TESOBJECTACTI_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESScriptableForm.h"
#include "layout_support.h"
class BGSDestructibleObjectForm;
class BGSOpenCloseForm;
class BGSTalkingActivator;
class BSFileEntry;
class CollisionComponent;
class ShortPoint3;
class TESBoundAnimObject;
class TESBoundObject__BOUND_DATA;
class TESMagicTargetForm;
class TESModel;
class TESModelTextureSwap;
class TESObjectACTI;
class TESFormList;
class FileEntryList;
class TESWaterForm;
class DistantTreeTextureInfo;
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
class TESBoundAnimObject : public TESBoundObject
{
  public:
    // base TESBoundObject at +0x0, size 48
    // TESBoundAnimObject
    // void __cdecl TESBoundAnimObject::*()
    // bool __cdecl TESBoundAnimObject::*()
    // void __cdecl TESBoundAnimObject::*(NiAVObject*, bool)
    // bool __cdecl TESBoundAnimObject::*(const char*)
    // TESBoundAnimObject& __cdecl TESBoundAnimObject::*(const TESBoundAnimObject&)
    // void __cdecl TESBoundAnimObject::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundAnimObject) == 48);
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
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
#pragma pack(push, 4)
class TESModelTextureSwap : public TESModel
{
  public:
    // base TESModel at +0x0, size 24
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
    // TESModelTextureSwap
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*(CHUNK_ID, CHUNK_ID, CHUNK_ID)
    // bool __cdecl TESModelTextureSwap::*(void*&, unsigned int&)
    // bool __cdecl TESModelTextureSwap::*(void*, unsigned int, unsigned int)
    // void __cdecl TESModelTextureSwap::*(TESModelTextureSwap*, TESFile*)
    // void __cdecl TESModelTextureSwap::*(TESForm*)
    // void __cdecl TESModelTextureSwap::*(BaseFormComponent*)
    // bool __cdecl TESModelTextureSwap::*(BaseFormComponent*)
    // BSSimpleList<DistantTreeTextureInfo *>* __cdecl TESModelTextureSwap::*()
    // DistantTreeTextureInfo* __cdecl TESModelTextureSwap::*(int)
    // void __cdecl TESModelTextureSwap::*()
    // void __cdecl TESModelTextureSwap::*(const char*, int, BGSTextureSet*)
    // void __cdecl TESModelTextureSwap::*(int)
    // int __cdecl TESModelTextureSwap::*(NiAVObject*, const NiFixedString&)
    // void __cdecl TESModelTextureSwap::*(NiAVObject*)
    // bool __cdecl TESModelTextureSwap::*(NiAVObject*, BSMap<int,DistantTreeTextureInfo *>*, int&)
    // bool __cdecl TESModelTextureSwap::*(TESForm*, TESObjectREFR*)
    // TESModelTextureSwap* __cdecl TESModelTextureSwap::*()
    // TESModelTextureSwap& __cdecl TESModelTextureSwap::*(const TESModelTextureSwap&)
    // void __cdecl TESModelTextureSwap::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModelTextureSwap) == 32);
FNV_STATIC_ASSERT(offsetof(TESModelTextureSwap, TextureSwapNodeAccessor) == 24);
#pragma pack(push, 4)
class TESMagicTargetForm
{
  public:
    // bool __cdecl TESMagicTargetForm::*(TESForm*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESMagicTargetForm) == 1);
#pragma pack(push, 4)
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    CollisionComponent* pData;  // +0x4, 4 bytes
    // BGSDestructibleObjectForm
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(BGSDestructibleObjectForm*, TESFile*)
    // void __cdecl BGSDestructibleObjectForm::*(BaseFormComponent*)
    // bool __cdecl BGSDestructibleObjectForm::*(BaseFormComponent*)
    // void __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // CollisionComponent* __cdecl BGSDestructibleObjectForm::*()
    // unsigned char __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(unsigned int)
    // bool __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // BGSDestructibleObjectForm* __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // int __cdecl BGSDestructibleObjectForm::*(TESForm*, TESModel*)
    // TESModel* __cdecl BGSDestructibleObjectForm::*(TESForm*, int)
    // bool __cdecl BGSDestructibleObjectForm::*()
    // bool __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(bool)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, float, bool)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BGSExplosion*, unsigned int, TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BGSDebris*, unsigned int, TESObjectREFR*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // bool __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, bool)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BSSimpleArray<NiNode *,1024>&)
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // bool __cdecl BGSDestructibleObjectForm::*(NiAVObject*)
    // void __cdecl BGSDestructibleObjectForm::*(TESBoundObject*, IO_TASK_PRIORITY, QueuedFile*)
    // void __cdecl BGSDestructibleObjectForm::*(TESBoundObject*)
    // void __cdecl BGSDestructibleObjectForm::*()
    // bool __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // CalculateDangerousExplosionHealth
    // float __cdecl BGSDestructibleObjectForm::*(unsigned char, float, float, BGSExplosion**)
    // void __cdecl BGSDestructibleObjectForm::*(IDebugText*, TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(IDebugText*, TESObjectREFR*)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, float)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // NiTMap<TESObjectREFR *,unsigned int>* __cdecl BGSDestructibleObjectForm::*()
    // float __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(float)
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // BGSDestructibleObjectForm& __cdecl BGSDestructibleObjectForm::*(const BGSDestructibleObjectForm&)
    // void* __cdecl BGSDestructibleObjectForm::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 8);
FNV_STATIC_ASSERT(offsetof(BGSDestructibleObjectForm, pData) == 4);
#pragma pack(push, 4)
class BGSOpenCloseForm
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
    // BGSOpenCloseForm* __cdecl BGSOpenCloseForm::*(TESForm*)
    // bool __cdecl BGSOpenCloseForm::*(TESForm*)
    // bool __cdecl BGSOpenCloseForm::*(NiNode*)
    // void __cdecl BGSOpenCloseForm::*(TESObjectREFR*, TESObjectREFR*, BGSOpenCloseForm*)
    // void __cdecl BGSOpenCloseForm::*(TESObjectREFR*, NiControllerSequence*)
    // bool __cdecl BGSOpenCloseForm::*(TESObjectREFR*, NiControllerSequence*)
    // bool __cdecl BGSOpenCloseForm::*(TESObjectREFR*, bool, bool)
    // BGSOpenCloseForm::OPEN_STATE __cdecl BGSOpenCloseForm::*(TESObjectREFR*)
    // void __cdecl BGSOpenCloseForm::*(TESObjectREFR*)
    // BGSOpenCloseForm
    // BGSOpenCloseForm& __cdecl BGSOpenCloseForm::*(const BGSOpenCloseForm&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSOpenCloseForm) == 4);
FNV_STATIC_ASSERT(offsetof(BGSOpenCloseForm, m_ppVirtualMethodTable) == 0);
#pragma pack(push, 4)
class TESObjectACTI : public TESBoundAnimObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESScriptableForm,
                      public BGSDestructibleObjectForm,
                      public BGSOpenCloseForm,
                      public TESMagicTargetForm
{
  public:
    // base TESBoundAnimObject at +0x0, size 48
    // base TESFullName at +0x30, size 12
    // base TESModelTextureSwap at +0x3C, size 32
    // base TESScriptableForm at +0x5C, size 12
    // base BGSDestructibleObjectForm at +0x68, size 8
    // base BGSOpenCloseForm at +0x70, size 4
    // base TESMagicTargetForm at +0x74, size 1
    TESSound* m_pSoundEffect;                  // +0x74, 4 bytes
    TESSound* m_pLoopSound;                    // +0x78, 4 bytes
    TESSound* pRadioTemplate;                  // +0x7C, 4 bytes
    TESWaterForm* m_pWaterForm;                // +0x80, 4 bytes
    BGSTalkingActivator* m_pTalkingActivator;  // +0x84, 4 bytes
    BSStringT<char> m_kActivationPrompt;       // +0x88, 8 bytes
    void ResetFormData();
    // TESObjectACTI
    // void __cdecl TESObjectACTI::*()
    // void __cdecl TESObjectACTI::*()
    // bool __cdecl TESObjectACTI::*(TESFile*)
    // void __cdecl TESObjectACTI::*()
    // void __cdecl TESObjectACTI::*(TESForm*)
    // bool __cdecl TESObjectACTI::*(TESForm*)
    // void __cdecl TESObjectACTI::*()
    // void __cdecl TESObjectACTI::*(bool)
    // void __cdecl TESObjectACTI::*(bool)
    // void __cdecl TESObjectACTI::*(bool)
    // bool __cdecl TESObjectACTI::*()
    // void __cdecl TESObjectACTI::*(bool)
    // bool __cdecl TESObjectACTI::*()
    // TESWaterForm* __cdecl TESObjectACTI::*()
    // void __cdecl TESObjectACTI::*(TESWaterForm*)
    // BGSTalkingActivator* __cdecl TESObjectACTI::*()
    // void __cdecl TESObjectACTI::*(BGSTalkingActivator*)
    // BSStringT<char> __cdecl TESObjectACTI::*()
    // void __cdecl TESObjectACTI::*(BSStringT<char>)
    // bool __cdecl TESObjectACTI::*(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int)
    // void __cdecl TESObjectACTI::*(BGSSaveFormBuffer*)
    // void __cdecl TESObjectACTI::*(BGSLoadFormBuffer*)
    // TESSound* __cdecl TESObjectACTI::*()
    // void __cdecl TESObjectACTI::*(TESSound*)
    // TESSound* __cdecl TESObjectACTI::*()
    // void __cdecl TESObjectACTI::*(TESSound*)
    // TESSound* __cdecl TESObjectACTI::*()
    // void __cdecl TESObjectACTI::*(TESSound*)
    // TESObjectACTI& __cdecl TESObjectACTI::*(const TESObjectACTI&)
    // void __cdecl TESObjectACTI::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObjectACTI) == 144);
FNV_STATIC_ASSERT(offsetof(TESObjectACTI, m_pSoundEffect) == 116);
FNV_STATIC_ASSERT(offsetof(TESObjectACTI, m_pLoopSound) == 120);
FNV_STATIC_ASSERT(offsetof(TESObjectACTI, pRadioTemplate) == 124);
FNV_STATIC_ASSERT(offsetof(TESObjectACTI, m_pWaterForm) == 128);
FNV_STATIC_ASSERT(offsetof(TESObjectACTI, m_pTalkingActivator) == 132);
FNV_STATIC_ASSERT(offsetof(TESObjectACTI, m_kActivationPrompt) == 136);
#endif
