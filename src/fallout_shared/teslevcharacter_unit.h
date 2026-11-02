// fallout_shared/teslevcharacter_unit.h: declares TESObject, ShortPoint3, TESBoundObject__BOUND_DATA, TESBoundObject, TESBoundAnimObject and more
#ifndef FNV_TESLEVCHARACTER_UNIT_H
#define FNV_TESLEVCHARACTER_UNIT_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "teslevcharacter_TESForm.h"
#include "TESGlobal.h"
#include "layout_support.h"
class TESActorBase;
class BGSLoadFormBuffer;
class BSFileEntry;
class LeveledObject;
class ContainerItemExtra;
class ShortPoint3;
class TESBoundAnimObject;
class TESBoundObject__BOUND_DATA;
class TESLevCharacter;
class TESLeveledList;
class TESModel;
class TESModelTextureSwap;
class TESFormList;
class FileEntryList;
class DistantTreeTextureInfo;
class TESObject : public TESForm
{
  public:
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(TESObject) == 36);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pOwningList) == 24);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pPreviousObject) == 28);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pNextObject) == 32);
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
};
FNV_STATIC_ASSERT(sizeof(ShortPoint3) == 6);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, y) == 2);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, z) == 4);
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
FNV_STATIC_ASSERT(sizeof(TESBoundObject__BOUND_DATA) == 12);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMax) == 6);
class TESBoundObject : public TESObject
{
  public:
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
};
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 48);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, TESBoundObjectBounds) == 36);
class TESBoundAnimObject : public TESBoundObject
{
  public:
};
FNV_STATIC_ASSERT(sizeof(TESBoundAnimObject) == 48);
class TESLeveledList : public BaseFormComponent
{
  public:
    LeveledObject* CreateLeveledObject(unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    void FUN_0042e680(unsigned char);
    void InitItem(TESForm* form);
    void LoadGame(BGSLoadFormBuffer* buffer);
    BSSimpleList<LeveledObject*> leveledList;  // +0x4, 8 bytes
    unsigned char m_pChanceGlobal;             // +0xC, 1 bytes
    unsigned char m_ucChanceNone;              // +0xD, 1 bytes
    unsigned char layoutPaddingE[2];
    TESGlobal* m_pLevelGlobal;                       // +0x10, 4 bytes
    BSSimpleList<LeveledObject*> m_kLeveledObjects;  // +0x14, 8 bytes
};
FNV_STATIC_ASSERT(sizeof(TESLeveledList) == 28);
FNV_STATIC_ASSERT(offsetof(TESLeveledList, leveledList) == 4);
FNV_STATIC_ASSERT(offsetof(TESLeveledList, m_pChanceGlobal) == 12);
FNV_STATIC_ASSERT(offsetof(TESLeveledList, m_ucChanceNone) == 13);
FNV_STATIC_ASSERT(offsetof(TESLeveledList, m_pLevelGlobal) == 16);
FNV_STATIC_ASSERT(offsetof(TESLeveledList, m_kLeveledObjects) == 20);
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
class TESModel : public BaseFormComponent
{
  public:
    static void LoadModelData(TESModel*, TESFile*);
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
class TESModelTextureSwap : public TESModel
{
  public:
    void InitItem(TESForm* form);
    bool ParseTextureSwapData(void*, unsigned int, unsigned int);
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
};
FNV_STATIC_ASSERT(sizeof(TESModelTextureSwap) == 32);
FNV_STATIC_ASSERT(offsetof(TESModelTextureSwap, TextureSwapNodeAccessor) == 24);
class TESLevCharacter : public TESBoundAnimObject, public TESLeveledList, public TESModelTextureSwap
{
  public:
    bool Load(TESFile*);
    TESActorBase* pTemplate;  // +0x6C, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(TESLevCharacter) == 112);
FNV_STATIC_ASSERT(offsetof(TESLevCharacter, pTemplate) == 108);
class TESLevCreature : public TESBoundObject, public TESLeveledList, public TESModelTextureSwap
{
  public:
    TESActorBase* pTemplate;
    virtual void InitItem();
};
FNV_STATIC_ASSERT(sizeof(TESLevCreature) == 112);
FNV_STATIC_ASSERT(offsetof(TESLevCreature, pTemplate) == 108);
class TESLevItem : public TESBoundObject, public TESLeveledList
{
  public:
    void LoadGame(BGSLoadFormBuffer* buffer);
};
FNV_STATIC_ASSERT(sizeof(TESLevItem) == 76);
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class ContainerItemExtra
{
  public:
    ContainerItemExtra();
    bool Load(TESFile*);
    unsigned char data[12];
};
class LeveledObject
{
  public:
    unsigned short level;
    unsigned short pad;
    TESForm* form;
    ContainerItemExtra* extra;
    void SwapEndian();
};
extern LeveledObject* DAT_011c8e64;
extern "C" void* memset(void*, int, unsigned int);
void* operator new(unsigned int);
extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)
#endif
