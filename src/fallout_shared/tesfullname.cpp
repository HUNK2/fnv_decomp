
// src/fallout_shared/tesfullname.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesfullname.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "TESFullName.h"

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESForm;
struct TESObjectREFR;
struct blob8
{
    char b[8];
};
struct TESDescription : public BaseFormComponent
{
    virtual char* GetDescription(TESForm*, int);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    static void LoadDescriptionAtOffset(TESDescription*, int);
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetDescriptionLength(TESForm*);
    unsigned int GetDescriptionLength();
    static char* GetDescription(TESForm*);
    unsigned long GetDescriptionFileOffset();
    void SetDescriptionFileOffset(unsigned long);
    void LoadDescriptionForForm(TESForm*, int);
    void UnLoadDescription();
    void SetDescription(char*);
    unsigned long m_uiDescriptionFileOffset;
};
typedef char _sizecheck_TESDescription[sizeof(TESDescription) == 8 ? 1 : -1];
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];
struct TESIcon : public TESTexture
{
    virtual char* GetTextureResourcePath();
    void* __vecDelDtor(unsigned int);
};
typedef char _sizecheck_TESIcon[sizeof(TESIcon) == 12 ? 1 : -1];
struct FUN_004870f0_shell : public TESFullName
{
    void CopyFullNameFrom(BaseFormComponent*);
};

struct BSStr
{
    bool Set(char const*, unsigned int);
};
struct FNStub
{
    char const* GetFullName(void);
};

// Casts apCopyFC to TESFullName and, if successful, copies its full name into this object's BSStr at offset 4.
// @fnv 0x004870f0
void FUN_004870f0_shell::CopyFullNameFrom(BaseFormComponent* apCopyFC)
{
    TESFullName* pCopy = dynamic_cast<TESFullName*>(apCopyFC);
    if (!pCopy)
        return;
    ((BSStr*)((char*)this + 4))->Set(((FNStub*)pCopy)->GetFullName(), 0);
}

struct TESForm
{
    virtual ~TESForm();
};
// Casts apObj to TESFullName and returns its full name, or an empty string if the cast fails.
// @fnv 0x00482720
const char* FUN_00482720(TESForm* apObj)
{
    TESFullName* pFullName = dynamic_cast<TESFullName*>(apObj);
    return pFullName ? ((FNStub*)pFullName)->GetFullName() : "";
}

class StringShell487 : public BSStringT<char>
{
  public:
    int StrCmp(const char* pcOther, bool bCaseSensitive) const;
};

class FullNameShell487 : public TESFullName
{
  public:
    unsigned int GetLength() const;
    const char* GetName() const;

    bool CompareFullName(BaseFormComponent* pkComponent);
};

// Compares this full name with another TESFullName component: returns true if lengths differ or names differ case-insensitively, false if equal.
// @fnv 0x00487140
bool FullNameShell487::CompareFullName(BaseFormComponent* pkComponent)
{
    TESFullName* pkOther = dynamic_cast<TESFullName*>(pkComponent);
    if (!pkOther)
        return true;
    if (GetLength() || static_cast<FullNameShell487*>(pkOther)->GetLength())
    {
        if (GetLength() != static_cast<FullNameShell487*>(pkOther)->GetLength())
            return true;
        else if (static_cast<StringShell487*>(&m_kName)->StrCmp(static_cast<FullNameShell487*>(pkOther)->GetName(),
                                                                false))
            return true;
    }
    return false;
}

struct TESFullNameSetter : public TESFullName
{
    void SetName(const char* text);
};

// Reads the FULL chunk from apFile and sets the name on apName via TESFullNameSetter::SetName.
// @fnv 0x00487050
void ReadFullName(TESFullName* apName, TESFile* apFile)
{
    if (!apFile || !apName)
    {
        return;
    }
    unsigned int id = apFile->GetChunkID();
    switch (id)
    {
    case CHUNK_ID_FULL_ID: {
        void* pChunkData;
        if (apFile->GetChunkSize())
        {
            pChunkData = _alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pChunkData, 0);
            ((TESFullNameSetter*)apName)->SetName((const char*)pChunkData);
        }
        else
        {
            ((TESFullNameSetter*)apName)->SetName(0);
        }
    }
    break;
    }
}
