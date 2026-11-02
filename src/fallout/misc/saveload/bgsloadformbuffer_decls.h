// fallout/misc/saveload/bgsloadformbuffer_decls.h: declares SaveLoadFile, PackedFormID, BGSSaveLoadFormInfo, FormChangeMask, FormLoadContext and more
#ifndef FNV_BGSLOADFORMBUFFER_DECLS_H
#define FNV_BGSLOADFORMBUFFER_DECLS_H

#include "layout_support.h"
#include "TESForm.h"

class SaveLoadFile
{
  public:
    void AdvancePosition(unsigned int bytes);
};

TESForm* GetFormByID(unsigned int formID);

#pragma pack(push, 1)

class PackedFormID
{
  public:
    PackedFormID();
    unsigned int GetNumericID();
    void SetFormNumericID(unsigned int numericID);
    bool IsZero();

    unsigned char m_ucIDByte0;
    unsigned char m_ucIDByte1;
    unsigned char m_ucIDByte2;
};

class BGSSaveLoadFormInfo
{
  public:
    BGSSaveLoadFormInfo();
    ENUM_FORM_ID GetFormType();
    void SetFormType(ENUM_FORM_ID formType);
    void InitSaveGameFormTypes();

    unsigned char cData;
};

class FormChangeMask
{
  public:
    FormChangeMask();
    bool ContainsAnyFlags(int flags);
    bool CheckFlagsExact(int flags);
    bool CheckFlagsExclusive(int flags);
    void SetFlags(int flags);
    void AddFlags(int flags);
    void RemoveFlags(int flags);
    FormChangeMask GetDifference(int flags);
    operator int();
    const char* GetFullFlagName(int flags, unsigned int, bool);
    const char* GetShortFlagName(int flags, unsigned int);
    bool IsFlagSetForType(int, unsigned int, unsigned int);
    bool HasFormChanged(TESForm* form);
    FormChangeMask CombineFlags(FormChangeMask, FormChangeMask, unsigned int, bool);

  protected:
    int iFlags;
};

class FormLoadContext
{
  public:
    FormLoadContext();
    void Endian();

    PackedFormID m_kFormIDIndex;
    FormChangeMask m_pDeathItem;
    BGSSaveLoadFormInfo FormInfo;
    unsigned char cVersion;
};

#pragma pack(pop)

class BGSLoadGameBuffer
{
  public:
    BGSLoadGameBuffer();
    ~BGSLoadGameBuffer();
    void ResetReadPosition();
    void SetBuffer(char* buffer, unsigned int size, unsigned int position);
    char* GetCurrentBufferPointer();
    virtual unsigned char GetVersion();
    char* LoadString(char* string);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int bytes);
    void ReadElementData(void* data, unsigned int size, unsigned int flags);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    void ReadDataBlock(void* data, unsigned int size);

  protected:
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};

class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
  public:
    BGSLoadFormBuffer();
    bool IsFlag2Set();
    int LoadHeader(SaveLoadFile* file);
    int ReadFormData(SaveLoadFile* file);
    void SkipData(SaveLoadFile* file, unsigned int size);
    unsigned int GetFormID();
    void SetForm(TESForm* form);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    ENUM_FORM_ID GetFormType();
    FormChangeMask GetChangeFlags();
    void SetChangeFlags(FormChangeMask changeFlags);
    FormChangeMask GetOldChangeFlags();
    void SetOldChangeFlags(FormChangeMask oldChangeFlags);
    void SetVersion(unsigned char version);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool skipForm);
    bool GetSkipForm();
    void SetFormPending(bool formPending);
    bool GetFormPending();
    void SetRevertOnly(bool revertOnly);
    bool GetRevertOnly();
    void SetReconstructedForm(bool reconstructedForm);
    bool GetReconstructedForm();
    void SetCellChanged(bool cellChanged);
    bool GetCellChanged();
    ~BGSLoadFormBuffer();

  protected:
    unsigned int iFormID;
    FormLoadContext Header;
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    FormChangeMask m_cReservedBytes;
};

#endif
