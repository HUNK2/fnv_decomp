// fallout_shared/bgsradiation.cpp: BGSRadiationStage (10 functions)

#include "bgsradiation_decls.h"
#include <typeinfo>
#include <new>
#include "bgsradiation_types_BGSRadiationStage.h"
#undef IsFormInitialized

// @fnv 0x00591c80
void BGSRadiationStage::ClearData()
{
    ClearStageData(this);
}

#pragma pack(push, 4)
union RadiationLevelValue
{
    __int64 value;
    struct
    {
        unsigned int low;
        unsigned int high;
    } words;
};
#pragma pack(pop)

// @fnv 0x00592220
BGSRadiationStage* BGSRadiationStage::GetStageForLevel(float level)
{
    struct SearchState
    {
        unsigned int index;
        unsigned int result;
    };
    SearchState searchState;
    searchState.result = 0;
    searchState.index = 0;
    for (; searchState.index < DAT_011ca87c && searchState.result == 0; ++searchState.index)
    {
        BGSRadiationStage* stage = FUN_005922a0(searchState.index);
        if (stage != 0)
        {
            RadiationLevelValue value;
            value.words.low = (unsigned int)(reinterpret_cast<NiAVObject*>(stage)->GetParent());
            value.words.high = 0;
            if (level >= value.value)
                searchState.result = (unsigned int)stage;
        }
    }
    return reinterpret_cast<BGSRadiationStage*>(searchState.result);
}

#pragma pack(push, 4)
struct InsertStageLocals
{
    BGSRadiationStage** oldArray;
    unsigned int index;
    unsigned char pad0;
    unsigned char pad1;
    unsigned char pad2;
    unsigned char newCount;
    unsigned int newIndex;
    unsigned char pad3;
    unsigned char pad4;
    unsigned char pad5;
    unsigned char inserted;
    BGSRadiationStage** m_ppNewArray;
};
#pragma pack(pop)

// Inserts stage into the global radiation stage array ordered by condition value, reallocating the array and updating the count.
// @fnv 0x00592010
void InsertRadiationStage(BGSRadiationStage* stage)
{
    InsertStageLocals locals;
    locals.newCount = DAT_011ca87c + 1;
    locals.m_ppNewArray =
        reinterpret_cast<BGSRadiationStage**>(BGSDehydrationStage::AllocateStageArray(locals.newCount));
    locals.newIndex = 0;
    locals.inserted = false;
    for (locals.index = 0; locals.index < DAT_011ca87c; ++locals.index)
    {
        if (*(unsigned int*)reinterpret_cast<BGSCameraPath*>(stage)->GetConditions() >
                *(unsigned int*)reinterpret_cast<BGSCameraPath*>(DAT_011ca880[locals.index])->GetConditions() &&
            !locals.inserted)
        {
            locals.m_ppNewArray[locals.newIndex] = stage;
            ++locals.newIndex;
            locals.inserted = true;
        }
        locals.m_ppNewArray[locals.newIndex] = DAT_011ca880[locals.index];
        ++locals.newIndex;
    }
    if (!locals.inserted)
    {
        locals.m_ppNewArray[locals.newIndex] = stage;
        ++locals.newIndex;
    }
    locals.oldArray = DAT_011ca880;
    ::operator delete(locals.oldArray);
    DAT_011ca87c = locals.newCount;
    DAT_011ca880 = locals.m_ppNewArray;
}

// @fnv 0x00591ca0
void BGSRadiationStage::InitItem()
{
    if (GetInitialized())
    {
    }
    else
    {
        unsigned int formID = reinterpret_cast<BGSDehydrationStage*>(this)->FUN_00441110();
        if (formID != 0)
        {
            TESForm::RemapFormIDForFile(formID, GetFile(-1));
            reinterpret_cast<BGSDehydrationStage*>(this)->FUN_0050f9a0(
                dynamic_cast<SpellItem*>(TESForm::GetFormByID(formID)));
        }
        SetInitializationState(true);
        InsertRadiationStage(this);
    }
}

#pragma pack(push, 4)
struct RemoveStageLocals
{
    BGSRadiationStage** oldArray;
    unsigned int oldIndex;
    unsigned int newIndex;
    unsigned int index;
    unsigned char padding0;
    unsigned char padding1;
    unsigned char padding2;
    unsigned char found;
    unsigned int newCount;
    BGSDehydrationStage** replacement;
};
#pragma pack(pop)

// Removes the given stage from the global stage array, rebuilding the array without it and updating the count.
// @fnv 0x00592110
void BGSRadiationStage::ClearStageData(BGSRadiationStage* stage)
{
    RemoveStageLocals locals;
    if (DAT_011ca87c == 0)
    {
    }
    else
    {
        locals.found = 0;
        locals.index = 0;
        for (; locals.found == 0 && locals.index < DAT_011ca87c; ++locals.index)
        {
            if (DAT_011ca880[locals.index] == stage)
                locals.found = 1;
        }
        if (locals.found == 0)
        {
        }
        else
        {
            locals.newCount = DAT_011ca87c - 1;
            locals.replacement = BGSDehydrationStage::AllocateStageArray(locals.newCount);
            if (locals.replacement != 0)
            {
                locals.newIndex = 0;
                locals.oldIndex = 0;
                for (; locals.oldIndex < DAT_011ca87c; ++locals.oldIndex)
                {
                    if (DAT_011ca880[locals.oldIndex] != stage)
                    {
                        locals.replacement[locals.newIndex] =
                            reinterpret_cast<BGSDehydrationStage*>(DAT_011ca880[locals.oldIndex]);
                        ++locals.newIndex;
                    }
                }
            }
            locals.oldArray = DAT_011ca880;
            ::operator delete(locals.oldArray);
            DAT_011ca87c = locals.newCount;
            DAT_011ca880 = reinterpret_cast<BGSRadiationStage**>(locals.replacement);
        }
    }
}

#include <malloc.h>
// Reads a radiation stage record from the file: validates the 0x5a form type, clears data, loads the header, then handles EDID, OBND and DATA chunks.
// @fnv 0x00591ec0
bool BGSRadiationStage::Load(TESFile* file)
{
    unsigned char ucFormType = file->GetTESForm();
    if (ucFormType != 0x5a)
        return false;
    ClearData();
    LoadRecordHeader(file);
    SetInitializationState(false);
    unsigned int uiChunkID;
    while ((uiChunkID = file->GetChunkID()) != 0)
    {
        switch (uiChunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(
                file, reinterpret_cast<BGSCameraPath*>(this)->GetConditions(), 8);
            break;
        }
        if (uiChunkID == 0x41544144 && file->IsEndianConversionRequired())
            reinterpret_cast<FUN_005a71d0*>(&data)->FUN_00462230();
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct Unnamed_00591bf0
{
    void __thiscall FUN_00591c20();
    void* __thiscall FUN_00591bf0(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_00591c20, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00591bf0
void* __thiscall Unnamed_00591bf0::FUN_00591bf0(unsigned int flags)
{
    FUN_00591c20();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};
void* __cdecl __memcpy(void*, const void*, unsigned int);
struct FUN_00591d30_t
{
    void CopyFrom(TESForm* apCopy);
};
// @fnv 0x00591d30
void FUN_00591d30_t::CopyFrom(TESForm* apCopy)
{
    BGSRadiationStage* pcopy = dynamic_cast<BGSRadiationStage*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->FUN_004851b0(pcopy);
    __memcpy(((BGSCameraPath*)this)->GetConditions(), ((BGSCameraPath*)pcopy)->GetConditions(), 8);
}

struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm*);
};
int __cdecl _memcmp(const void*, const void*, unsigned int);
struct FUN_00591d90_shell : BGSRadiationStage
{
    bool FUN_00591d90(TESForm* apCompare);
};
// @fnv 0x00591d90
bool FUN_00591d90_shell::FUN_00591d90(TESForm* apCompare)
{
    BGSRadiationStage* pOtherStage = dynamic_cast<BGSRadiationStage*>(apCompare);
    if (!pOtherStage)
        return true;
    if (((FUN_005e79a0_t*)this)->FUN_00485270(pOtherStage))
        return true;
    if (_memcmp(((BGSCameraPath*)this)->GetConditions(), ((BGSCameraPath*)pOtherStage)->GetConditions(), 8))
        return true;
    return false;
}

class B591C20Form
{
  public:
    virtual ~B591C20Form();
    virtual void ClearData();

    unsigned char m_cFormType;
    unsigned int m_iFormFlags;
    unsigned int m_iFormID;
    void* m_pkSourceFile;
    void* m_pkNextSourceFile;
};

class FUN_00591c20_ListForm : public B591C20Form
{
  public:
    virtual ~FUN_00591c20_ListForm();
    virtual void ClearData();

    void* m_pkFirstItem;
    void* m_pkNextItem;
    unsigned int m_uiAddedCount;
};

// @fnv 0x00591c20
FUN_00591c20_ListForm::~FUN_00591c20_ListForm()
{
    ClearData();
}
