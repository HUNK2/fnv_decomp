// fallout_shared/bgsstaticcollection_decls.h: declares TESObject, ShortPoint3, TESBoundObject__BOUND_DATA, TESBoundObject, FileEntryList and more
#ifndef FNV_BGSSTATICCOLLECTION_DECLS_H
#define FNV_BGSSTATICCOLLECTION_DECLS_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "layout_support.h"
class BGSStaticCollection;
class BSFileEntry;
class ShortPoint3;
class TESBoundObject__BOUND_DATA;
class TESModel;
class TESModelTextureSwap;
class TESFormList;
class FileEntryList;
class DistantTreeTextureInfo;
#pragma pack(push, 4)
class TESObject : public TESForm
{
  public:
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
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
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
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
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
#pragma pack(push, 4)
class TESModel : public BaseFormComponent
{
  public:
    static void LoadModelData(TESModel* model, TESFile* file);
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
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
    bool ParseTextureSwapData(void* data, unsigned int size, unsigned int version);
    void InitItem(TESForm* form);
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModelTextureSwap) == 32);
FNV_STATIC_ASSERT(offsetof(TESModelTextureSwap, TextureSwapNodeAccessor) == 24);
#pragma pack(push, 4)
class BGSStaticCollection : public TESBoundObject, public TESModelTextureSwap
{
  public:
    virtual bool Load(TESFile* file);
    virtual void InitItem();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSStaticCollection) == 80);
enum BGSStaticCollectionModelChunkID
{
    CHUNK_ID_NO_CHUNK = 0,
    CHUNK_ID_MODL_ID = 0x4c444f4d,
    CHUNK_ID_MODD_ID = 0x44444f4d,
    CHUNK_ID_MOSD_ID = 0x44534f4d,
    CHUNK_ID_MODT_ID = 0x54444f4d,
    CHUNK_ID_MODS_ID = 0x53444f4d
};
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
#endif
