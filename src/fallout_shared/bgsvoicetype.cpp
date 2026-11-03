// fallout_shared/bgsvoicetype.cpp: BGSVoiceType (6 functions)

#include "bgsvoicetype_decls.h"
// Loads a BGSVoiceType record from a TESFile, handling EDID, OBND and DATA chunks, and returns false if the form type is not 0x5d.
// @fnv 0x005f01a0
bool BGSVoiceType::Load(TESFile* file)
{
    if (file->GetTESForm() != 0x5d)
        return false;
    LoadRecordHeader(file);
    unsigned int chunk;
    char* buffer;
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445:
            buffer = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(buffer, 512);
            SetEditorID(buffer);
            break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4d414e44:
            file->GetChunkData(&Data, 1);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct TESForm_StartForm
{
    void M();
};
struct TESForm_CloseForm
{
    void M();
};
struct B1_4fe
{
    void ClearData();
};
bool __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int, void*, unsigned int);
struct FUN_005f0140_obj : TESForm
{
    B1_4fe unk18;
    void BGSVoiceType_SaveForm();
};
// @fnv 0x005f0140
void FUN_005f0140_obj::BGSVoiceType_SaveForm()
{
    ((TESForm_StartForm*)this)->M();
    if (FUN_00401500())
        unk18.ClearData();
    AppendChunk(0x4d414e44, &unk18, 1);
    if (FUN_00401500())
        unk18.ClearData();
    ((TESForm_CloseForm*)this)->M();
}

// ---------------------------------------------------------------------------
// BGSVoiceType::~BGSVoiceType  (FUN_005f00d0)
//
// The real class chain behind this destructor is
//
//     TESForm  <-  BGSDehydrationStage  <-  BGSVoiceType
//
// The pack header only carries the flattened "BGSVoiceType : public TESForm"
// form (and without any destructor on TESForm), so the missing intermediate
// base is restored here.  The intermediate base owns the non trivial
// destructor that the compiler emits as the tail call of this function, and
// carries the TESForm::ClearData() helper that the destructor body invokes.
//
// Layout of the reconstructed object:
//     +0x00  vptr
//     +0x04  TESForm::formFields[20]
//     +0x18  char Data
//     +0x1c  BSS unk1c          (non trivial destructor -> compiler cleanup)
// ---------------------------------------------------------------------------

struct BGSDehydrationStage : public TESForm
{
    void ClearData();
    ~BGSDehydrationStage();
};

struct BSS
{
    char* unk00;
    ~BSS();
};

struct FUN_005f00d0 : public BGSDehydrationStage
{
    char Data;
    BSS unk1c;
    ~FUN_005f00d0();
};

// @fnv 0x005f00d0
FUN_005f00d0::~FUN_005f00d0()
{
    ClearData();
}

struct FUN_005f00a0
{
    virtual ~FUN_005f00a0();
};
// The destructor body is empty.
// @fnv 0x005f00a0
FUN_005f00a0::~FUN_005f00a0()
{}

extern "C" void* __cdecl FUN_00ec43fb(void* p, long vf, void* src, void* tgt, int isRef);
extern char DAT_01183028;
extern char DAT_01186318;
struct FUN_004851b0_call
{
    void TESForm_CopyAllComponents(TESForm* form);
};
struct FUN_005f02a0_shell : BGSDehydrationStage
{
    void BGSVoiceType_CopyFrom(TESForm* form);
};
// If FUN_00ec43fb resolves a source from form, copies its Data member to this and calls TESForm_CopyAllComponents(form).
// @fnv 0x005f02a0
void FUN_005f02a0_shell::BGSVoiceType_CopyFrom(TESForm* form)
{
    FUN_005f00d0* src = (FUN_005f00d0*)FUN_00ec43fb(form, 0, &DAT_01183028, &DAT_01186318, 0);
    if (!src)
    {
        return;
    }
    ((FUN_005f00d0*)this)->Data = src->Data;
    ((FUN_004851b0_call*)this)->TESForm_CopyAllComponents(form);
}

struct BGSVoiceType_shell : BGSVoiceType
{
    bool BGSVoiceType_Compare(TESForm* form);
    bool TESForm_CompareAllComponents(TESForm* form);
};

// Returns true if form is not a BGSVoiceType, its Data differs, or TESForm_CompareAllComponents(voice) is true; otherwise false.
// @fnv 0x005f02f0
bool BGSVoiceType_shell::BGSVoiceType_Compare(TESForm* form)
{
    BGSVoiceType* voice = dynamic_cast<BGSVoiceType*>(form);
    if (!voice)
        return true;
    if (Data != voice->Data)
        return true;
    if (TESForm_CompareAllComponents(voice))
        return true;
    return false;
}
