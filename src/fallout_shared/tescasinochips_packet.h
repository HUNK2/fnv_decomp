// Unit-local header for fallout_shared/tescasinochips.cpp.
// Class layouts (TESObject through TESCasinoChips) are copied verbatim from
// canonical); EndianConvertibleData and TESCasino are copied verbatim from
// comments).
#ifndef FNV_TESCASINOCHIPS_PACKET_H
#define FNV_TESCASINOCHIPS_PACKET_H

class TESFile;
class BGSImpactData
{
  public:
    void ReadTypedData(TESFile*, void*, unsigned short);
};
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"

#include "TESFullName.h"
#include "TESIcon.h"
#include "TESTexture.h"
#include "layout_support.h"
// with BGSDefaultObjectManager::IsFormInitialized (0x004013e0) through
// identical-COMDAT folding. The canonical TESForm.h does not declare it yet,
// so it is declared on this shim, following the accepted TESFileFormInt
// precedent in tessound.cpp.
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
};
// TESFile::GetFormVersion is not declared in the bundled TESFile.h; its
// mangled name (TESFileFormVersion::GetFormVersion, 0x00403570) shows the
// canonical declaration site, so it is declared on this shim.
struct TESFileFormVersion : public TESFile
{
    unsigned short GetFormVersion();
};
// TESFullName::LoadFullNameChunk is not declared in the bundled TESFullName.h;
// declared here on a shim following the accepted TESRecipe precedent.

// TESTexture::ReadTextureData is not declared in the bundled TESTexture.h;
// declared here on a shim following the TESFullNameLoader precedent.
struct TESTextureLoader : public TESTexture
{
    static void ReadTextureData(TESTexture* apTexture, TESFile* apFile);
};
class BGSDestructibleObjectForm;
class BGSMessageIcon;
class BGSPickupPutdownSounds;
class BSFileEntry;
class CollisionComponent;
class ShortPoint3;
class TESBoundObject__BOUND_DATA;
class TESCasinoChips;
class TESModel;
class TESModelTextureSwap;
class TESFormList;
class FileEntryList;
class TESValueForm;
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
    TESBoundObject();
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
    // PC vtable order (BaseFormComponent slots 0-3 first) follows the
    // community reverse-engineered declaration (JIP LN NVSE / JohnnyGuitar
    // NVSE Bethesda/TESModel.hpp): destructor, GetModelFilePath, SetModelFilePath,
    // GetAsModelMaterialSwap. SetModelFilePath at slot 6 (+0x18) is the virtual
    // called by the MODL/MOD2/MOD3/MOD4 chunk handlers.
    virtual ~TESModel();
    virtual const char* GetModelFilePath() const;
    virtual void SetModelFilePath(const char* apPath);
    virtual TESModelTextureSwap* GetAsModelMaterialSwap() const;
    static void LoadModelData(TESModel* apModel, TESFile* apFile);
    static void LoadTextureSwapData(TESModel* apModel, TESFile* apFile);
    // TESModel
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*(CHUNK_ID, CHUNK_ID)
    // void __cdecl TESModel::*(BaseFormComponent*)
    // bool __cdecl TESModel::*(BaseFormComponent*)
    // void __cdecl TESModel::*(CHUNK_ID)
    // GetModelLength
    // GetModelFilePath
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
    TESModelTextureSwap();
    void InitItem(TESForm* apForm);
    void LoadTextureSwapChunk(char* apBuffer, unsigned int auiSize, unsigned short ausVersion);
    bool ParseTextureSwapData(void*, unsigned int, unsigned int);
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
class BGSMessageIcon : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    TESIcon Icon;  // +0x4, 12 bytes
    BGSMessageIcon();
    static void LoadMessageIconChunk(BGSMessageIcon* apIcon, TESFile* apFile);
    // BGSMessageIcon
    // void __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*(CHUNK_ID)
    // void __cdecl BGSMessageIcon::*(BGSMessageIcon*, TESFile*)
    // void __cdecl BGSMessageIcon::*(BaseFormComponent*)
    // bool __cdecl BGSMessageIcon::*(BaseFormComponent*)
    // TESIcon* __cdecl BGSMessageIcon::*()
    // const char* __cdecl BGSMessageIcon::*()
    // unsigned int __cdecl BGSMessageIcon::*()
    // void __cdecl BGSMessageIcon::*(const char*)
    // BGSMessageIcon& __cdecl BGSMessageIcon::*(const BGSMessageIcon&)
    // void* __cdecl BGSMessageIcon::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSMessageIcon) == 16);
FNV_STATIC_ASSERT(offsetof(BGSMessageIcon, Icon) == 4);
#pragma pack(push, 4)
class TESValueForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned int iValue;  // +0x4, 4 bytes
    TESValueForm();
    virtual ~TESValueForm();
    // TESValueForm
    // void __cdecl TESValueForm::*()
    // void __cdecl TESValueForm::*()
    // void __cdecl TESValueForm::*()
    // void __cdecl TESValueForm::*()
    // void __cdecl TESValueForm::*(BaseFormComponent*)
    // bool __cdecl TESValueForm::*(BaseFormComponent*)
    // void __cdecl TESValueForm::*(int)
    // SaveGame
    // LoadGame
    // TESValueForm& __cdecl TESValueForm::*(const TESValueForm&)
    // void* __cdecl TESValueForm::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESValueForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESValueForm, iValue) == 4);
#pragma pack(push, 4)
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    CollisionComponent* pData;  // +0x4, 4 bytes
    BGSDestructibleObjectForm();
    virtual ~BGSDestructibleObjectForm();
    void InitItem(TESForm* apForm);
    static void LoadDestructibleData(BGSDestructibleObjectForm* apForm, TESFile* apFile);
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
class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    TESSound* m_pPickupSound;   // +0x4, 4 bytes
    TESSound* m_pPutdownSound;  // +0x8, 4 bytes
    BGSPickupPutdownSounds();
    virtual ~BGSPickupPutdownSounds();
    void InitItem(TESForm* apForm);
    void SetPickupSound(TESSound* apSound);
    void SetPutdownSound(TESSound* apSound);
    // BGSPickupPutdownSounds
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*(TESFile*)
    // void __cdecl BGSPickupPutdownSounds::*(BaseFormComponent*)
    // bool __cdecl BGSPickupPutdownSounds::*(BaseFormComponent*)
    // void __cdecl BGSPickupPutdownSounds::*(TESForm*)
    // GetPickupSound
    // GetPutdownSound
    // void __cdecl BGSPickupPutdownSounds::*(TESSound*)
    // void __cdecl BGSPickupPutdownSounds::*(TESSound*)
    // BGSPickupPutdownSounds& __cdecl BGSPickupPutdownSounds::*(const BGSPickupPutdownSounds&)
    // void* __cdecl BGSPickupPutdownSounds::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSPickupPutdownSounds) == 12);
FNV_STATIC_ASSERT(offsetof(BGSPickupPutdownSounds, m_pPickupSound) == 4);
FNV_STATIC_ASSERT(offsetof(BGSPickupPutdownSounds, m_pPutdownSound) == 8);
#pragma pack(push, 4)
class TESCasinoChips : public TESBoundObject,
                       public TESFullName,
                       public TESModelTextureSwap,
                       public TESIcon,
                       public BGSMessageIcon,
                       public TESValueForm,
                       public BGSDestructibleObjectForm,
                       public BGSPickupPutdownSounds
{
  public:
    // base TESBoundObject at +0x0, size 48
    // base TESFullName at +0x30, size 12
    // base TESModelTextureSwap at +0x3C, size 32
    // base TESIcon at +0x5C, size 12
    // base BGSMessageIcon at +0x68, size 16
    // base TESValueForm at +0x78, size 8
    // base BGSDestructibleObjectForm at +0x80, size 8
    // base BGSPickupPutdownSounds at +0x88, size 12
    BSStringT<char> m_kPrimaryString;  // +0x94, 8 bytes
    TESCasinoChips();
    virtual void ClearData();
    virtual void InitItem();
    bool Load(TESFile* apFile);
    // TESCasinoChips
    // void __cdecl TESCasinoChips::*()
    // void __cdecl TESCasinoChips::*()
    // bool __cdecl TESCasinoChips::*(TESFile*)
    // void __cdecl TESCasinoChips::*()
    // void __cdecl TESCasinoChips::*(TESForm*)
    // bool __cdecl TESCasinoChips::*(TESForm*)
    // void __cdecl TESCasinoChips::*()
    // void __cdecl TESCasinoChips::*()
    // NiAVObject* __cdecl TESCasinoChips::*(TESObjectREFR*, bool)
    // const char* __cdecl TESCasinoChips::*()
    // void __cdecl TESCasinoChips::*(const char*)
    // bool __cdecl TESCasinoChips::*()
    // void __cdecl TESCasinoChips::*(bool)
    // unsigned short __cdecl TESCasinoChips::*(unsigned int)
    // SaveGame
    // LoadGame
    // TESCasinoChips& __cdecl TESCasinoChips::*(const TESCasinoChips&)
    // void __cdecl TESCasinoChips::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESCasinoChips) == 156);
FNV_STATIC_ASSERT(offsetof(TESCasinoChips, m_kPrimaryString) == 148);
// TESModel and TESModelTextureSwap are already defined above and are not
// repeated. Real method declarations used by this unit are added.
#pragma pack(push, 4)
class EndianConvertibleData
{
  public:
    float EndianFloatValue;                // +0x0, 4 bytes
    float EndianMixedData;                 // +0x4, 4 bytes
    int FloatPairAndFourIntegerRecord;     // +0x8, 4 bytes
    int FloatPairAndFiveIntegerRecord;     // +0xC, 4 bytes
    int FloatAndSixIntegerRecord;          // +0x10, 4 bytes
    int SevenIntegerRecord;                // +0x14, 4 bytes
    int SevenIntegerRecordFromNextOffset;  // +0x18, 4 bytes
    int m_iFourthRecordValue;              // +0x1C, 4 bytes
    int m_iFifthRecordValue;               // +0x20, 4 bytes
    int m_iSixthRecordValue;                       // +0x24, 4 bytes
    int m_iFourthIntegerValue;             // +0x28, 4 bytes
    unsigned int IntegerEndianRecord;      // +0x2C, 4 bytes
    unsigned int uiChunkType;              // +0x30, 4 bytes
    bool m_bEndianFlag;                    // +0x34, 1 bytes
    unsigned char layoutPadding35[3];
    void Endian();
    // void __cdecl EndianConvertibleData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(EndianConvertibleData) == 56);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, EndianFloatValue) == 0);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, EndianMixedData) == 4);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, FloatPairAndFourIntegerRecord) == 8);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, FloatPairAndFiveIntegerRecord) == 12);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, FloatAndSixIntegerRecord) == 16);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, SevenIntegerRecord) == 20);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, SevenIntegerRecordFromNextOffset) == 24);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, m_iFourthRecordValue) == 28);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, m_iFifthRecordValue) == 32);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, m_iSixthRecordValue) == 36);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, m_iFourthIntegerValue) == 40);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, IntegerEndianRecord) == 44);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, uiChunkType) == 48);
FNV_STATIC_ASSERT(offsetof(EndianConvertibleData, m_bEndianFlag) == 52);
#pragma pack(push, 4)
class TESCasino : public TESForm, public TESFullName
{
  public:
    // base TESForm at +0x0, size 24
    // base TESFullName at +0x18, size 12
    TESModelTextureSwap m_kModelTextureSwaps[10];  // +0x24, 320 bytes
    TESTexture m_kIconTextures[11];                // +0x164, 132 bytes
    EndianConvertibleData data;                    // +0x1E8, 56 bytes
    bool Load(TESFile* apFile);
    void ReadTypedData(TESFile* apFile, void* apData, unsigned short ausSize);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESCasino) == 544);
FNV_STATIC_ASSERT(offsetof(TESCasino, m_kModelTextureSwaps) == 36);
FNV_STATIC_ASSERT(offsetof(TESCasino, m_kIconTextures) == 356);
FNV_STATIC_ASSERT(offsetof(TESCasino, data) == 488);
#endif
