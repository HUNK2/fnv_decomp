// fallout_shared/tesglobal.cpp: TESGlobal, TESImageSpace (8 functions)

#include "tesglobal_layout.h"
#include "tesglobal_decls.h"
#include <malloc.h>

#define FNV_FOURCC(a, b, c, d)                                                                                         \
    ((unsigned int)(a) | ((unsigned int)(b) << 8) | ((unsigned int)(c) << 16) | ((unsigned int)(d) << 24))

// Reads a TESGlobal record from the file, handling EDID, OBND, FNAM and FLTV chunks until the chunk list ends.
// @fnv 0x005a64b0
bool TESGlobal::Load(TESFile* file)
{
    if (file->GetTESForm() != 6)
        return false;

    LoadRecordHeader(file);

    int chunkID;
    while ((chunkID = (int)file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case FNV_FOURCC('E', 'D', 'I', 'D'): {
            char* buffer = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(buffer, 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case FNV_FOURCC('O', 'B', 'N', 'D'):
            readOBNDSubRecord(file);
            break;
        case FNV_FOURCC('F', 'N', 'A', 'M'):
            file->GetChunkData(&cType, 1);
            break;
        case FNV_FOURCC('F', 'L', 'T', 'V'):
            file->GetChunkData((unsigned int*)&fValue);
            break;
        }
        if (!file->NextChunk())
            break;
    }

    return true;
}

#include "tesglobal_imagespace.h"

// @fnv 0x0052b310
TESImageSpace::TESImageSpace()
{
    SetFormType((ENUM_FORM_ID)0x53);
    TESImageSpace::ResetFormData();
}

struct BSStr
{
    bool Set(char const*, unsigned int);
};

struct FUN_005a63a0_shell
{
    BSStr m_str;
    bool SetString(char const* a1);
};

// Calls Set on the BSStr at offset 0x18 with the given string and a length of 0, then returns true.
// @fnv 0x005a63a0
bool __thiscall FUN_005a63a0_shell::SetString(char const* apString)
{
    ((BSStr*)((char*)this + 0x18))->Set(apString, 0);
    return 1;
}

void _Deallocate(void*);
struct S_5a63c0
{
    void FUN_005a63f0();
    void* Destroy(unsigned int flags);
};
// Calls FUN_005a63f0, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x005a63c0
void* S_5a63c0::Destroy(unsigned int flags)
{
    FUN_005a63f0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct TESForm_StartForm
{
    void M();
};
struct TESForm_CloseForm
{
    void M();
};
void __cdecl FUN_004858f0(unsigned int, unsigned char);
void __cdecl _FUN_00485910(unsigned int, float);
struct FUN_005a6460_standin
{
    char _p0[32];
    unsigned char _b20;
    char _p1[3];
    float _f24;
    void TESGlobal_SaveForm();
};
// Calls M on this, then passes the byte at offset 0x20 and the float at offset 0x24 to FUN_004858f0 and _FUN_00485910, then calls M again.
// @fnv 0x005a6460
void FUN_005a6460_standin::TESGlobal_SaveForm()
{
    ((TESForm_StartForm*)this)->M();
    FUN_004858f0(0x4D414E46, _b20);
    _FUN_00485910(0x56544C46, _f24);
    ((TESForm_CloseForm*)this)->M();
}

struct FUN_005e78f0_t
{
    void TESForm_CopyAllComponents(TESForm*);
};
struct BSFaceGenModelMap
{
    bool TESGlobal_GetType();
};
struct TESGlobalValueReader
{
    float GetValue();
};
struct FUN_005a65e0_shell : TESGlobal
{
    void TESGlobal_CopyFrom(TESForm* apCopy);
};
// @fnv 0x005a65e0
void FUN_005a65e0_shell::TESGlobal_CopyFrom(TESForm* apCopy)
{
    TESGlobal* pCopy = dynamic_cast<TESGlobal*>(apCopy);
    if (!pCopy)
        return;
    reinterpret_cast<FUN_005e78f0_t*>(this)->TESForm_CopyAllComponents(apCopy);
    cType = reinterpret_cast<BSFaceGenModelMap*>(pCopy)->TESGlobal_GetType();
    fValue = reinterpret_cast<TESGlobalValueReader*>(pCopy)->GetValue();
}

struct FUN_005e79a0_t
{
    bool TESForm_CompareAllComponents(TESForm*);
};
struct FUN_005a6640_shell : TESGlobal
{
    bool IsNotEqual(TESForm* apCompare);
};
// Compares this global with apCompare: returns true if apCompare is not a TESGlobal or differs by TESForm_CompareAllComponents, TESGlobal_GetType or GetValue; false otherwise.
// @fnv 0x005a6640
bool FUN_005a6640_shell::IsNotEqual(TESForm* apCompare)
{
    TESGlobal* pComp = dynamic_cast<TESGlobal*>(apCompare);
    if (!pComp)
        return true;
    if (((FUN_005e79a0_t*)this)->TESForm_CompareAllComponents(pComp))
        return true;
    if (((char)((BSFaceGenModelMap*)this)->TESGlobal_GetType()) != ((char)((BSFaceGenModelMap*)pComp)->TESGlobal_GetType()))
        return true;
    if (((TESGlobalValueReader*)this)->GetValue() != ((TESGlobalValueReader*)pComp)->GetValue())
        return true;
    return false;
}

struct FUN_00483710_t
{
    void FUN_00483710();
};

struct FUN_004037d0
{
    ~FUN_004037d0();
};

struct FUN_00483630
{
    virtual void Vb();
    char _p4[0x14];
    ~FUN_00483630();
};

struct FUN_005a63f0 : FUN_00483630
{
    virtual ~FUN_005a63f0();
    FUN_004037d0 m_18;
};

// @fnv 0x005a63f0
FUN_005a63f0::~FUN_005a63f0()
{
    ((FUN_00483710_t*)this)->FUN_00483710();
}
