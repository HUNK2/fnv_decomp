// fallout/ai/processlists_private/processlists_TESModel.h: declares FileEntryList, TESModel
#ifndef PROCESSLISTS_PRIVATE_TESMODEL_H
#define PROCESSLISTS_PRIVATE_TESMODEL_H

#include "processlists_BaseFormComponent.h"
class BSFileEntry;
class TESModelTextureSwap;
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;
    BSFileEntry** m_ppFileEntries;
};
class TESModel : public BaseFormComponent
{
  public:
    TESModel();
    virtual ~TESModel();
    virtual const char* GetModelFilePath() const;
    virtual void SetModelFilePath(const char* path);
    virtual TESModelTextureSwap* GetAsModelMaterialSwap() const;
    BSStringT<char> m_kModelFilePath;
    FileEntryList m_pTextureSwapData;
    unsigned char cFlags;
};
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
FNV_STATIC_ASSERT(sizeof(TESModel) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 0xc);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 0x14);
#endif
