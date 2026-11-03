// fallout_shared/teseyes.cpp: TESEyes, Holder (13 functions)

#include <malloc.h>
#include "TESForm.h"

class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;
    TESFullName();
};

class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> FullNameComponent;
    TESTexture();
};

class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture* texture, TESFile* file);
};

class TESEyes : public TESForm, public TESFullName, public TESTexture
{
  public:
    char cFlags;
    TESEyes();
    void ResetFormData();
    virtual bool Load(TESFile* file);
};

// @fnv 0x005fc050
TESEyes::TESEyes()
{
    SetFormType(ENUM_FORM_ID_EYES_ID);
    ResetFormData();
}

struct FUN_005fc4d0_shell
{
    char pad[0x30];
    char cFlags;
    bool IsFlagSet();
};
// @fnv 0x005fc4d0
bool FUN_005fc4d0_shell::IsFlagSet()
{
    return (cFlags & 1) ? true : false;
}

struct FUN_005fc4f0_shell
{
    void SetFlag(bool aFlag);
};

// Sets or clears bit 0 of the byte at offset 0x30 of this object according to aFlag.
// @fnv 0x005fc4f0
void FUN_005fc4f0_shell::SetFlag(bool aFlag)
{
    if (aFlag)
        ((char*)this)[0x30] |= 1;
    else
        ((char*)this)[0x30] &= 0xfffffffe;
}

struct FUN_005fc530_shell
{
    char m[0x31];
    bool IsNotFlag2Set();
};

// @fnv 0x005fc530
bool FUN_005fc530_shell::IsNotFlag2Set()
{
    if (m[0x30] & 2)
        return false;
    return true;
}

struct FUN_005fc590_shell
{
    char pad[0x30];
    char cFlags;
    bool IsFlag4Clear();
};

// @fnv 0x005fc590
bool FUN_005fc590_shell::IsFlag4Clear()
{
    if (cFlags & 4)
        return false;
    return true;
}

struct FUN_005fc420_shell
{
    bool IsNotEqual(TESForm* apCompare);
};

struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm* apForm);
};

// @fnv 0x005fc420
bool FUN_005fc420_shell::IsNotEqual(TESForm* apCompare)
{
    TESEyes* pcomp = dynamic_cast<TESEyes*>(apCompare);
    if (pcomp == 0)
        return true;
    if (reinterpret_cast<FUN_005e79a0_t*>(this)->TESForm_CompareAllComponents(pcomp))
        return true;
    if (reinterpret_cast<FUN_005fc4d0_shell*>(pcomp)->IsFlagSet() !=
        reinterpret_cast<FUN_005fc4d0_shell*>(this)->IsFlagSet())
        return true;
    if (reinterpret_cast<FUN_005fc530_shell*>(pcomp)->IsNotFlag2Set() !=
        reinterpret_cast<FUN_005fc530_shell*>(this)->IsNotFlag2Set())
        return true;
    if (reinterpret_cast<FUN_005fc590_shell*>(pcomp)->IsFlag4Clear() !=
        reinterpret_cast<FUN_005fc590_shell*>(this)->IsFlag4Clear())
        return true;
    return false;
}

void _Deallocate(void*);
struct Holder
{
    void FUN_005fc120();
    void* ReleaseIfFlagged(unsigned int);
};
// Calls FUN_005fc120, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x005fc0f0
void* Holder::ReleaseIfFlagged(unsigned int flags)
{
    FUN_005fc120();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct TESForm_StartForm
{
    char _pad[0x18];
    void M();
};
struct TESForm_CloseForm
{
    void M();
};
struct S_00487010
{
    char _pad[0x0C];
    void TESFullName_Save();
};
struct FUN_0048e370_obj
{
    char _pad[0x0C];
    void TESTexture_Save(unsigned int);
};
void __cdecl FUN_004858f0(unsigned int, unsigned char);
struct FUN_005fc1d0_Obj : TESForm_CloseForm, TESForm_StartForm
{
    S_00487010 s;
    FUN_0048e370_obj t;
    char cFlags;
    void TESEyes_SaveForm();
};
// @fnv 0x005fc1d0
void FUN_005fc1d0_Obj::TESEyes_SaveForm()
{
    TESForm_StartForm::M();
    s.TESFullName_Save();
    t.TESTexture_Save(0x4E4F4349);
    FUN_004858f0(0x41544144, cFlags);
    TESForm_CloseForm::M();
}

struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm* apForm);
};
struct FUN_005fc550_shell
{
    void FUN_005fc550(bool flag);
};
struct FUN_005fc5b0_shell
{
    void FUN_005fc5b0(bool flag);
};
struct FUN_005fc3a0_shell
{
    void CopyFromEyes(TESForm* apCopy);
};
// @fnv 0x005fc3a0
void FUN_005fc3a0_shell::CopyFromEyes(TESForm* apCopy)
{
    TESEyes* eyes = dynamic_cast<TESEyes*>(apCopy);
    if (!eyes)
        return;
    ((FUN_005e78f0_t*)this)->TESForm_CopyAllComponents(apCopy);
    ((FUN_005fc4f0_shell*)this)->SetFlag(((FUN_005fc4d0_shell*)eyes)->IsFlagSet());
    ((FUN_005fc550_shell*)this)->FUN_005fc550(((FUN_005fc530_shell*)eyes)->IsNotFlag2Set());
    ((FUN_005fc5b0_shell*)this)->FUN_005fc5b0(((FUN_005fc590_shell*)eyes)->IsFlag4Clear());
}

struct TESNPC;
struct TESHairRaceResult;
struct TESHairCanBeNPCData
{
    TESHairRaceResult* TESNPC_GetRace();
};
struct LH
{
    bool IsInList(TESNPC*&);
};
struct TESDataHandler
{
    BSSimpleList<TESNPC*>* GetBGSRecipeCategoryList();
};
struct TESActorBase
{
    int GetSex();
};
struct TESNPC : public TESActorBase
{
    TESHairCanBeNPCData* TESNPC_GetRace();
};
struct FUN_005fc5f0_shell : public TESEyes
{
    bool CanBeNPC(TESNPC* npc);
};
// @fnv 0x005fc5f0
bool FUN_005fc5f0_shell::CanBeNPC(TESNPC* npc)
{
    bool result = false;
    if (npc && npc->TESNPC_GetRace())
    {
        TESNPC* race = (TESNPC*)this;
        if (((LH*)((TESDataHandler*)npc->TESNPC_GetRace())->GetBGSRecipeCategoryList())->IsInList(race))
        {
            switch (npc->GetSex())
            {
            case 0:
                if (((FUN_005fc530_shell*)this)->IsNotFlag2Set())
                    result = true;
                break;
            case 1:
                if (((FUN_005fc590_shell*)this)->IsFlag4Clear())
                    result = true;
                break;
            }
        }
    }
    return result;
}

namespace fnv_005fc550 {
struct FUN_005fc550_shell
{
    char pad[0x30];
    char cFlags;
    void FUN_005fc550(bool aFlag);
};

// Sets or clears bit 2 of cFlags depending on aFlag: clears it when aFlag is true, sets it otherwise.
// @fnv 0x005fc550
void FUN_005fc550_shell::FUN_005fc550(bool aFlag)
{
    if (aFlag)
        cFlags &= ~2;
    else
        cFlags |= 2;
}
}  // namespace fnv_005fc550

namespace fnv_005fc5b0 {
struct FUN_005fc5b0_shell
{
    char pad[0x30];
    char cFlags;
    void FUN_005fc5b0(bool aFlag);
};

// Clears bit 4 of cFlags when aFlag is true, otherwise sets bit 4.
// @fnv 0x005fc5b0
void FUN_005fc5b0_shell::FUN_005fc5b0(bool aFlag)
{
    if (aFlag)
        cFlags &= ~4;
    else
        cFlags |= 4;
}
}  // namespace fnv_005fc5b0

struct FUN_005fc220_shell : public TESEyes
{
    bool LoadEyes(TESFile*);
};

struct TESFileX
{
    int GetTESForm();
};

// Loads a TESEyes record from the file, handling EDID, OBND, FULL, ICON and DATA chunks, and returns false if the record type is not 0xb.
// @fnv 0x005fc220
bool FUN_005fc220_shell::LoadEyes(TESFile* apFile)
{
    if (((TESFileX*)apFile)->GetTESForm() != 0xb)
        return false;
    LoadRecordHeader(apFile);
    int chunkid;
    while ((chunkid = apFile->GetChunkID()) != 0)
    {
        switch (chunkid)
        {
        case 0x44494445: {
            char* pEditorId = (char*)_alloca(apFile->GetChunkSize());
            apFile->GetChunkData(pEditorId, 0x200);
            SetEditorID_AtRuntime(pEditorId);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, apFile);
            break;
        case 0x4e4f4349:
            TESTextureLoader::ReadTextureData(this, apFile);
            break;
        case 0x41544144:
            apFile->GetChunkData(&cFlags, 1);
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}
