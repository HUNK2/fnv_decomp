// fallout_shared/tesimagespace.cpp: TESImageSpace, ImageSpaceCopyEntry (7 functions)

#include "tesimagespace.h"
#include <malloc.h>
#include <string.h>

// Zeroes out the Data member of the TESImageSpace form using memset.
// @fnv 0x0052b410
void TESImageSpace::ResetFormData()
{
    memset(&Data, 0, sizeof(Data));
}

// Reads a TESImageSpace record from file, handling EDID, OBND and DNAM chunks, and returns false if the form type is not 0x53.
// @fnv 0x0052b440
bool TESImageSpace::Load(TESFile* file)
{
    unsigned char formType;
    int chunk;
    ImageSpaceModifierParameterData data;
    formType = file->GetTESForm();
    if (formType != 0x53)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(buffer, 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4D414E44:  // DNAM
            file->GetChunkData(&data, sizeof(data));
            if (file->GetChunkSize() < sizeof(data))
            {
                memcpy_s(&Data, 0x3C, &data, 0x38);
                Data.m_afFirstParameterSet[14] = 1.0f;
                memcpy_s(&Data.m_afSecondParameterSet, 0x5C, &data.m_afFirstParameterSet[14], 0x5C);
            }
            else
            {
                memcpy_s(&Data, sizeof(data), &data, sizeof(data));
            }
            if (file->IsEndianConversionRequired())
                Data.Endian();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_0052b3b0 : public Base5a
{
    virtual void ClearData();
    ~FUN_0052b3b0();
};
// @fnv 0x0052b3b0
FUN_0052b3b0::~FUN_0052b3b0()
{
    ClearData();
}

bool __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int, char*, unsigned int);
struct TESForm_StartForm
{
    void M();
};
struct TESForm_CloseForm
{
    void M();
};
struct FUN_0052b630_obj
{
    void TESForm_StartForm();
    void TESForm_CloseForm();
    void TESImageSpace_SaveForm();
};
// @fnv 0x0052b630
void FUN_0052b630_obj::TESImageSpace_SaveForm()
{
    TESForm_StartForm();
    if (FUN_00401500())
        ((ImageSpaceModifierParameterData*)((char*)this + 0x18))->Endian();
    AppendChunk(0x4d414e44, (char*)this + 0x18, 0x98);
    if (FUN_00401500())
        ((ImageSpaceModifierParameterData*)((char*)this + 0x18))->Endian();
    TESForm_CloseForm();
}

struct FUN_0052b700_shell : public TESImageSpace
{
    bool TESForm_CompareAllComponents(TESForm*);
    bool TESImageSpace_Compare(TESForm*);
};

// @fnv 0x0052b700
bool FUN_0052b700_shell::TESImageSpace_Compare(TESForm* apCompare)
{
    TESImageSpace* pcomp = dynamic_cast<TESImageSpace*>(apCompare);
    if (!pcomp)
        return true;
    if (TESForm_CompareAllComponents((TESForm*)pcomp))
        return true;
    if (memcmp((char*)this + 0x18, (char*)pcomp + 0x18, 0x98))
        return true;
    return false;
}

void __cdecl _Deallocate(void*);
struct FUN_0052b380_shell : public FUN_0052b3b0
{
    void* DestroyAndDeallocate(unsigned int flags);
};
// Runs the base destructor, then frees this object with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0052b380
void* FUN_0052b380_shell::DestroyAndDeallocate(unsigned int flags)
{
    FUN_0052b3b0::~FUN_0052b3b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct ImageSpaceCopyEntry : public ::TESImageSpace
{
    void TESForm_CopyAllComponents(::TESForm*);
    void TESImageSpace_CopyFrom(::TESForm* apCopy);
};
// Copies the TESImageSpace data from apCopy into this entry after calling TESForm_CopyAllComponents.
// @fnv 0x0052b6a0
void ImageSpaceCopyEntry::TESImageSpace_CopyFrom(::TESForm* apCopy)
{
    ::TESImageSpace* pcopy = dynamic_cast< ::TESImageSpace*>(apCopy);
    if (!pcopy)
        return;
    TESForm_CopyAllComponents(pcopy);
    ::memcpy(&Data, &pcopy->Data, sizeof(Data));
}
