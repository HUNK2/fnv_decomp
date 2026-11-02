// layout; PC equivalence unproven). Layout asserts are preserved; the member declarations
// used by fallout_shared/bgsimpactdata.cpp are added below each class.
#ifndef FNV_TASK_BGSIMPACTDATA_COPY_H
#define FNV_TASK_BGSIMPACTDATA_COPY_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFile.h"
#include "layout_support.h"
class BGSImpactData;
class BGSImpactData__IMPACT_DATA_DATA;
class BGSTextureSet;
class BSFileEntry;
class ImpactDecalData;
class DecalData;
class TESModel;
class FileEntryList;
class TESSound;
enum BGSImpactData__ORIENTATION
{
    BGSImpactData__ORIENTATION_ORIENT_SURFACE_NORMAL = 0,
    BGSImpactData__ORIENTATION_ORIENT_PROJ_VECTOR = 1,
    BGSImpactData__ORIENTATION_ORIENT_PROJ_REFLECT = 2,
    BGSImpactData__ORIENTATION_ORIENT_COUNT = 3
};
enum SOUND_LEVEL
{
    SOUND_LEVEL_SOUND_LEVEL_LOUD = 0,
    SOUND_LEVEL_SOUND_LEVEL_NORMAL = 1,
    SOUND_LEVEL_SOUND_LEVEL_SILENT = 2,
    SOUND_LEVEL_SOUND_LEVEL_COUNT = 3
};
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
    TESModel();
    static void LoadModelData(TESModel* model, TESFile* file);
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
class BGSImpactData__IMPACT_DATA_DATA
{
  public:
    float m_fEffectDuration;                    // +0x0, 4 bytes
    BGSImpactData__ORIENTATION m_eOrientation;  // +0x4, 4 bytes
    float m_fAngleThreshold;                    // +0x8, 4 bytes
    float m_fPlacementRadius;                   // +0xC, 4 bytes
    SOUND_LEVEL m_eSoundLevel;                  // +0x10, 4 bytes
    unsigned char cFlags;                       // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    void Endian();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSImpactData__IMPACT_DATA_DATA) == 24);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__IMPACT_DATA_DATA, m_fEffectDuration) == 0);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__IMPACT_DATA_DATA, m_eOrientation) == 4);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__IMPACT_DATA_DATA, m_fAngleThreshold) == 8);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__IMPACT_DATA_DATA, m_fPlacementRadius) == 12);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__IMPACT_DATA_DATA, m_eSoundLevel) == 16);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__IMPACT_DATA_DATA, cFlags) == 20);
#pragma pack(push, 4)
class ImpactDecalData
{
  public:
    float m_fDecalMinWidth;            // +0x0, 4 bytes
    float m_fDecalMaxWidth;            // +0x4, 4 bytes
    float m_fDecalMinHeight;           // +0x8, 4 bytes
    float m_fDecalMaxHeight;           // +0xC, 4 bytes
    float m_fProjectionDepth;          // +0x10, 4 bytes
    float m_fShininess;                // +0x14, 4 bytes
    float m_fParallaxScale;            // +0x18, 4 bytes
    unsigned char m_ucParallaxPasses;  // +0x1C, 1 bytes
    unsigned char cFlags;              // +0x1D, 1 bytes
    unsigned char layoutPadding1E[2];
    unsigned int iColor;  // +0x20, 4 bytes
    // void __cdecl ImpactDecalData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImpactDecalData) == 36);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fDecalMinWidth) == 0);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fDecalMaxWidth) == 4);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fDecalMinHeight) == 8);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fDecalMaxHeight) == 12);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fProjectionDepth) == 16);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fShininess) == 20);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fParallaxScale) == 24);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_ucParallaxPasses) == 28);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, cFlags) == 29);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, iColor) == 32);
#pragma pack(push, 4)
class DecalData
{
  public:
    ImpactDecalData Data;  // +0x0, 36 bytes
    DecalData();
    ~DecalData();
    ImpactDecalData* GetData();
    bool Load(TESFile* file);
    // void __cdecl DecalData::*()
    // void __cdecl DecalData::*(DecalData*)
    // bool __cdecl DecalData::*(DecalData*)
    // void __cdecl DecalData::*(CHUNK_ID)
    // bool __cdecl DecalData::*(TESFile*)
    // DecalData* __cdecl DecalData::*()
    // float __cdecl DecalData::*()
    // void __cdecl DecalData::*(float)
    // float __cdecl DecalData::*()
    // void __cdecl DecalData::*(float)
    // float __cdecl DecalData::*()
    // void __cdecl DecalData::*(float)
    // float __cdecl DecalData::*()
    // void __cdecl DecalData::*(float)
    // float __cdecl DecalData::*()
    // void __cdecl DecalData::*(float)
    // float __cdecl DecalData::*()
    // void __cdecl DecalData::*(float)
    // bool __cdecl DecalData::*()
    // void __cdecl DecalData::*(bool)
    // bool __cdecl DecalData::*()
    // void __cdecl DecalData::*(bool)
    // bool __cdecl DecalData::*()
    // void __cdecl DecalData::*(bool)
    // float __cdecl DecalData::*()
    // void __cdecl DecalData::*(float)
    // unsigned short __cdecl DecalData::*()
    // void __cdecl DecalData::*(unsigned short)
    // unsigned int __cdecl DecalData::*()
    // void __cdecl DecalData::*(unsigned int)
    // void* __cdecl DecalData::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DecalData) == 36);
FNV_STATIC_ASSERT(offsetof(DecalData, Data) == 0);
#pragma pack(push, 4)
class BGSImpactData__OLD_IMPACT_DATA_DATA
{
  public:
    // The 2008 Load keeps its 56-byte oldData local in the /GS buffer class
    // (security cookie last, above only the this spill), which MSVC 9 does
    // for structs containing an array. The raw overlay below recovers that
    // codegen category; all field offsets and the 56-byte size are unchanged.
    union
    {
        struct
        {
            float m_fDecalMinWidth;                     // +0x0, 4 bytes
            float m_fEffectDuration;                    // +0x4, 4 bytes
            float m_fParallaxScale;                     // +0x8, 4 bytes
            BGSImpactData__ORIENTATION m_eOrientation;  // +0xC, 4 bytes
            unsigned char cFlags;                       // +0x10, 1 bytes
            unsigned char m_ucParallaxPasses;           // +0x11, 1 bytes
            unsigned char layoutPadding12[2];
            float m_fDecalMaxWidth;     // +0x14, 4 bytes
            float m_fProjectionDepth;   // +0x18, 4 bytes
            float m_fDecalMinHeight;    // +0x1C, 4 bytes
            float m_fDecalMaxHeight;    // +0x20, 4 bytes
            float m_fShininess;         // +0x24, 4 bytes
            float m_fAngleThreshold;    // +0x28, 4 bytes
            float m_fPlacementRadius;   // +0x2C, 4 bytes
            unsigned int iColor;        // +0x30, 4 bytes
            SOUND_LEVEL m_eSoundLevel;  // +0x34, 4 bytes
        };
        unsigned int rawChunkData[14];  // +0x0, 56 bytes
    };
    void Endian();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSImpactData__OLD_IMPACT_DATA_DATA) == 56);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fDecalMinWidth) == 0);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fEffectDuration) == 4);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fParallaxScale) == 8);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_eOrientation) == 12);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, cFlags) == 16);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_ucParallaxPasses) == 17);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fDecalMaxWidth) == 20);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fProjectionDepth) == 24);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fDecalMinHeight) == 28);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fDecalMaxHeight) == 32);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fShininess) == 36);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fAngleThreshold) == 40);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_fPlacementRadius) == 44);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, iColor) == 48);
FNV_STATIC_ASSERT(offsetof(BGSImpactData__OLD_IMPACT_DATA_DATA, m_eSoundLevel) == 52);
#pragma pack(push, 4)
class DecalData_d00483710 : public DecalData
{
  public:
    DecalData_d00483710()
    {}
    ~DecalData_d00483710();
};
class BGSImpactData : public TESForm, public TESModel
{
  public:
    // base TESForm at +0x0, size 24
    // base TESModel at +0x18, size 24
    BGSImpactData__IMPACT_DATA_DATA Data;  // +0x30, 24 bytes
    BGSTextureSet* m_pDecalTextureSet;     // +0x48, 4 bytes
    TESSound* m_pPrimaryImpactSound;       // +0x4C, 4 bytes
    TESSound* m_pSecondaryImpactSound;     // +0x50, 4 bytes
    DecalData_d00483710 ImpactDecalInfo;   // +0x54, 36 bytes (destroyed by 0x00483710 in the game)
    BGSImpactData();
    void ResetFormData();
    void InitItem();
    void ReadTypedData(TESFile* file, void* buffer, unsigned short size);
    void SetDecalTextureSet(BGSTextureSet* textureSet);
    void SetSound1(TESSound* sound);
    void SetSound2(TESSound* sound);
    void CopyDecalDataFromTextureSet();
    bool Load(TESFile* file);
    // void __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(TESForm*)
    // bool __cdecl BGSImpactData::*(TESForm*)
    // bool __cdecl BGSImpactData::*(TESFile*)
    // void __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*()
    // bool __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(bool)
    // void __cdecl BGSImpactData::*()
    // float __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(float)
    // float __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(float)
    // float __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(float)
    // float __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(float)
    // float __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(float)
    // float __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(float)
    // float __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(float)
    // float __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(float)
    // bool __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(bool)
    // bool __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(bool)
    // bool __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(bool)
    // float __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(float)
    // unsigned short __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(unsigned short)
    // float __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(float)
    // BGSImpactData::ORIENTATION __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(BGSImpactData::ORIENTATION)
    // unsigned int __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(unsigned int)
    // BGSTextureSet* __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(BGSTextureSet*)
    // TESSound* __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(TESSound*)
    // TESSound* __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(TESSound*)
    // SOUND_LEVEL __cdecl BGSImpactData::*()
    // void __cdecl BGSImpactData::*(int)
    // int __cdecl BGSImpactData::*()
    // BGSImpactData& __cdecl BGSImpactData::*(const BGSImpactData&)
    // void __cdecl BGSImpactData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSImpactData) == 120);
FNV_STATIC_ASSERT(offsetof(BGSImpactData, Data) == 48);
FNV_STATIC_ASSERT(offsetof(BGSImpactData, m_pDecalTextureSet) == 72);
FNV_STATIC_ASSERT(offsetof(BGSImpactData, m_pPrimaryImpactSound) == 76);
FNV_STATIC_ASSERT(offsetof(BGSImpactData, m_pSecondaryImpactSound) == 80);
FNV_STATIC_ASSERT(offsetof(BGSImpactData, ImpactDecalInfo) == 84);
// Unit-local shims for fallout_shared/bgsimpactdata.cpp Load/InitItem,
// following the accepted tessound.h / tesfurniture.h precedents.
// TESFileFormInt recovers the 32-bit GetTESForm the 2008 Load compares with
// layout below version 10. TESFormInitFlag declares IsFormInitialized (reads
// 0x004013e0 through identical-COMDAT folding) and the static
// chunk readers declared on the using class because the closure TESForm.h
// does not declare them. BGSTextureSet/TESSound are minimal polymorphic
// scaffolds so InitItem's dynamic_casts have complete target types; only
// their names matter for codegen and manifest RTTI bindings.
struct TESFileFormInt : public TESFile
{
    int GetTESForm();
};
struct TESFileFormVersion : public TESFile
{
    unsigned short GetFormVersion();
};
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int formID);
};
class BGSTextureSet : public TESForm
{
  public:
    virtual ~BGSTextureSet();
};
class TESSound : public TESForm
{
  public:
    virtual ~TESSound();
};
int Warning(const char* format, ...);
#endif
