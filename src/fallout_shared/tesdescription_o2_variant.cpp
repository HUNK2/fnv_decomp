
// src/fallout_shared/tesdescription_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesdescription.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesdescription_decls.h"
extern "C" unsigned char DAT_011c54ba;
unsigned char FUN_00401500();
struct TESObjectREFR;
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
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
struct FUN_00482c80_shell : public TESDescription
{
    void ClearParsedXML();
};
extern "C" unsigned char DAT_011c54ba;
unsigned char FUN_00401500();
struct BSStr
{
    bool Set(char const*, unsigned int);
};
extern int DAT_011c5490;
void __cdecl WriteDescChunk(void*, int);
struct FUN_00482cb0_shell
{
    void __thiscall TESDescription_Save();
};

// Adjustor thunk: the secondary-base (+0x3c) vtable entry for an override defined on the derived class.

class D1CC0Primary
{
  public:
    virtual void FUN_00501cc0(unsigned int uiValue);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
};

class D1CC0Secondary
{
  public:
    virtual void FUN_00501cc0(unsigned int uiValue);
};

class D1CC0Derived : public D1CC0Primary, public D1CC0Secondary
{
  public:
    D1CC0Derived();
// @fnv 0x00501cc0
    virtual void FUN_00501cc0(unsigned int uiValue);
};

D1CC0Derived::D1CC0Derived()
{}

// [thunk] this-adjustor (-0x84) for the secondary-base vtable slot of the TESObjectBOOK
// GetSaveSize override at 0x515220. The override replaces the same virtual in both bases, so the
// compiler emits this thunk with the vtable that the out-of-line constructor below instantiates;
// the override body itself lives elsewhere.
struct BookPrimaryBase
{
    virtual void Slot0();
    virtual unsigned short FUN_00515430(unsigned int auiChangeFlags);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    BookPrimaryBase() throw();
};
struct BookSaveSizeBase
{
    virtual unsigned short FUN_00515430(unsigned int auiChangeFlags);
    BookSaveSizeBase() throw();
};
struct TESObjectBOOKStandIn : BookPrimaryBase, BookSaveSizeBase
{
// @fnv 0x00515430
    virtual unsigned short FUN_00515430(unsigned int auiChangeFlags);
    TESObjectBOOKStandIn() throw();
};
TESObjectBOOKStandIn::TESObjectBOOKStandIn() throw()
{}
