// bscore/memorymanager_identity.h: declares TESActorBase, Actor, TESFile, BSExtraData, BaseExtraList and more
#ifndef FNV_MEMORYMANAGER_IDENTITY_H
#define FNV_MEMORYMANAGER_IDENTITY_H


class PerkEntryConditionSet;

enum SEX
{
    SEX_MALE = 0,
    SEX_FEMALE = 1
};

class TESActorBase
{
  public:
    SEX GetSex();
};

class Actor
{
  public:
    TESActorBase* GetActorBase();
    SEX GetSex();
};

void operator delete(void* pointer) throw();
void FNV_DeleteBuffer(void* pointer);

class TESFile
{
  public:
    unsigned char layoutPadding0[0x420];
    char* m_pDecompressedFormBuffer;
    unsigned int m_uiAuxBufferSize;
    void ClearDecompressedFormBuffer();
};

class BSExtraData
{
  public:
    unsigned char layoutPadding0[12];
};

class BaseExtraList
{
  public:
    BSExtraData* GetExtraData(unsigned char type);
    BSExtraData* AddExtra(BSExtraData* extra);
};

class ExtraHealth : public BSExtraData
{
  public:
    float fHealthPercent;
    static void* operator new(unsigned int size);
    static void operator delete(void* pointer);
    ExtraHealth(float health);
};

class ExtraDataList : public BaseExtraList
{
  public:
    void SetExtraHealth(float health);
};

class TESQuest
{
  public:
    PerkEntryConditionSet* GetConditions();
};

class TESActorBaseData
{
  public:
    unsigned char layoutPadding0[4];
    unsigned int m_uiActorFlags;
    bool GetFlag(unsigned int flag) const;
};

#endif
