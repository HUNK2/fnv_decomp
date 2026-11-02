// fallout_shared/bgsragdoll.cpp: BGSRagdoll (33 functions)

#include "bgsragdoll_types_BGSRagdoll.h"
#include <malloc.h>

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);

class TESFileLoadView : public TESFile
{
  public:
    unsigned int GetTESForm();
};

class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int formID);
};

int __cdecl Warning(const char*, ...);
void __cdecl operator delete(void*);

class BGSBodyPartData : public TESForm
{
};
class TESActorBase : public TESForm
{
};

// @fnv 0x005edd00
void BGSRagdoll::ResetFormData()
{
    struct InitLocals
    {
        TESObjectREFR* grabName;
        TESObjectREFR* lookName;
        TESObjectREFR* footName;
        unsigned int grabIndex;
        unsigned int lookIndex;
        unsigned int footIndex;
    } locals;

    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter1 = 0.8f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.fHeirGain = 0.17f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter3 = 0.05f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.fVelGain = 0.6f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter5 = 1.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.fSnapGain = 0.1f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter7 = 0.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter8 = 3.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter9 = 0.3f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter10 = 0.3f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter11 = 3.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter12 = 14.0f;
    m_kRagdollAnimationData.m_kRagdollFeedbackData.m_fFeedbackParameter13 = 18.0f;

    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)->Clear(true);

    for (locals.footIndex = 0;
         locals.footIndex <
         reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kFootIKData.m_kFootNames)->GetSize();
         ++locals.footIndex)
    {
        locals.footName =
            reinterpret_cast<NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*>(&m_kFootIKData.m_kFootNames)
                ->GetAt(locals.footIndex);
        ::operator delete(locals.footName);
    }
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kFootIKData.m_kLegData)->Clear(true);
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kFootIKData.m_kFootNames)->Clear(true);

    m_kFootIKData.m_kRagdollFeedbackData.fOnOffGain = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.fGroundAscendingGain = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.fGroundDescendingGain = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.fFootRaisedGain = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.m_fAdditionalFeedbackGain1 = 0.0f;
    m_kFootIKData.m_kRagdollFeedbackData.m_fAdditionalFeedbackGain2 = 0.0f;

    for (locals.lookIndex = 0;
         locals.lookIndex <
         reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kLookIKData.m_kLookNames)->GetSize();
         ++locals.lookIndex)
    {
        locals.lookName =
            reinterpret_cast<NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*>(&m_kLookIKData.m_kLookNames)
                ->GetAt(locals.lookIndex);
        ::operator delete(locals.lookName);
    }
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kLookIKData.m_kHeadData)->Clear(true);
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kLookIKData.m_kLookNames)->Clear(true);

    for (locals.grabIndex = 0;
         locals.grabIndex <
         reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kGrabIKData.m_kGrabNames)->GetSize();
         ++locals.grabIndex)
    {
        locals.grabName =
            reinterpret_cast<NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*>(&m_kGrabIKData.m_kGrabNames)
                ->GetAt(locals.grabIndex);
        ::operator delete(locals.grabName);
    }
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kGrabIKData.m_kGrabArmData)->Clear(true);
    reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kGrabIKData.m_kGrabNames)->Clear(true);

    m_kRagdollFeedbackProfile.m_kRagdollFeedbackData.m_sFirstRagdollFeedbackIndex = -1;
    m_kRagdollFeedbackProfile.m_kRagdollFeedbackData.m_sSecondRagdollFeedbackIndex = -1;
    m_kRagdollFeedbackProfile.m_kRagdollFeedbackData.m_sThirdRagdollFeedbackIndex = -1;
    m_kRagdollAnimationData.bEnabled = false;
    m_kFootIKData.bEnabled = false;
    m_kLookIKData.bEnabled = false;
    m_kGrabIKData.bEnabled = false;
    m_kRagdollFeedbackProfile.bEnabled = false;
    m_pActorBase = 0;
    m_pBodyPartDataCur = 0;
}

// @fnv 0x005ed680
BGSRagdoll::BGSRagdoll()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x63));
    ResetFormData();
}

// @fnv 0x005eea20
void BGSRagdoll::InitItem()
{
    if (GetInitialized())
        return;

    TESForm::ClearData();

    unsigned int formID = reinterpret_cast<unsigned int>(m_pBodyPartDataCur);
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        m_pBodyPartDataCur = dynamic_cast<BGSBodyPartData*>(TESForm::GetFormByID(formID));
        if (!m_pBodyPartDataCur)
            Warning("MASTERFILE: Could not find body part data (%08X) for ragdoll '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }

    formID = reinterpret_cast<unsigned int>(m_pActorBase);
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        m_pActorBase = dynamic_cast<TESActorBase*>(TESForm::GetFormByID(formID));
        if (!m_pActorBase)
            Warning("MASTERFILE: Could not find preview actor (%08X) for ragdoll '%s' (%08X).", formID, GetName(),
                    GetFormID());
    }

    SetInitializationState(true);
}

// Reads a BGSRagdoll record from a TESFile, handling EDID, OBND, MODL/MODT, DATA, XNAM, TNAM, RAFD, RAFB, RAPS and ANAM chunks.
// @fnv 0x005ee640
bool BGSRagdoll::Load(TESFile* file)
{
    if (reinterpret_cast<TESFileLoadView*>(file)->GetTESForm() != 0x63)
        return false;
    LoadRecordHeader(file);
    struct LoadLocals
    {
        char* filename;
        unsigned int i;
        unsigned int count;
        unsigned int body;
        unsigned int preview;
        SaveMetadata saved;
        char* editorID;
        int chunk;
    } locals;
    while ((locals.chunk = file->GetChunkID()) != 0)
    {
        switch (locals.chunk)
        {
        case 0x44494445: {
            locals.editorID = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(locals.editorID, 512);
            SetEditorID_AtRuntime(locals.editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x41544144: {
            file->GetChunkData(&locals.saved, sizeof(locals.saved));
            if (file->IsEndianConversionRequired())
                locals.saved.SwapEndianFourShorts();
            reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)
                ->SetSize(locals.saved.m_usFootIndexCount, true);
            m_kFootIKData.m_kLegData.SetSize(locals.saved.m_usLegDataCount, true);
            m_kLookIKData.m_kHeadData.SetSize(locals.saved.m_usHeadDataCount, true);
            m_kGrabIKData.m_kGrabArmData.SetSize(locals.saved.m_usGrabArmDataCount, true);
            m_kRagdollAnimationData.bEnabled = locals.saved.m_bRagdollAnimationEnabled;
            m_kFootIKData.bEnabled = locals.saved.m_bFootIKEnabled;
            m_kLookIKData.bEnabled = locals.saved.m_bLookIKEnabled;
            m_kGrabIKData.bEnabled = locals.saved.m_bGrabIKEnabled;
            m_kRagdollFeedbackProfile.bEnabled = locals.saved.m_bRagdollFeedbackEnabled;
            break;
        }
        case 0x4d414e58: {
            locals.preview = 0;
            file->GetChunkData(&locals.preview);
            m_pActorBase = reinterpret_cast<TESActorBase*>(locals.preview);
            break;
        }
        case 0x4d414e54: {
            locals.body = 0;
            file->GetChunkData(&locals.body);
            m_pBodyPartDataCur = reinterpret_cast<BGSBodyPartData*>(locals.body);
            break;
        }
        case 0x44464152:
            file->GetChunkData(&m_kRagdollAnimationData.m_kRagdollFeedbackData,
                               sizeof(m_kRagdollAnimationData.m_kRagdollFeedbackData));
            if (file->IsEndianConversionRequired())
                m_kRagdollAnimationData.m_kRagdollFeedbackData.FUN_005ee380();
            break;
        case 0x42464152: {
            file->GetChunkData(
                &reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)
                     ->GetAt(0),
                reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)
                        ->GetSize() *
                    2);
            locals.count =
                reinterpret_cast<BSSimpleArray<SandboxProcedureData, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)
                    ->GetSize();
            if (file->IsEndianConversionRequired())
            {
                for (locals.i = 0; locals.i < locals.count; ++locals.i)
                    BSEndian(
                        &reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(&m_kRagdollAnimationData.m_kFootIndices)
                             ->GetAt(locals.i),
                        EndianSizeTag<2>());
            }
            break;
        }
        case 0x53504152:
            file->GetChunkData(&m_kRagdollFeedbackProfile.m_kRagdollFeedbackData,
                               sizeof(m_kRagdollFeedbackProfile.m_kRagdollFeedbackData));
            if (file->IsEndianConversionRequired())
                m_kRagdollFeedbackProfile.m_kRagdollFeedbackData.FUN_005ee580();
            break;
        case 0x4d414e41: {
            locals.filename = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(locals.filename, 0);
            m_kRagdollFeedbackProfile.m_kAnimationFileName.Set(locals.filename, 0);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

void __fastcall FUN_005ed790(void*);
void __fastcall FUN_005eee30(void*);

// @fnv 0x005ed760
void* __fastcall FUN_005ed760(char* pThis)
{
    *pThis = 0;
    FUN_005ed790(pThis + 4);
    FUN_005eee30(pThis + 0x40);
    return pThis;
}

extern float const g_011c3bb8_arg1;
extern float const g_011d8aa4_arg1;
extern float DAT_010231a8;

// Fills the 15-element float/int block at pThis with constant values and returns pThis.
// @fnv 0x005ed790
void* __fastcall FUN_005ed790(float* pThis)
{
    pThis[0] = g_011c3bb8_arg1;
    pThis[1] = 0.8f;
    pThis[2] = DAT_010231a8;
    pThis[3] = 0.2f;
    pThis[4] = 0.1f;
    pThis[5] = 0.3f;
    pThis[6] = 0.0f;
    pThis[7] = 50.0f;
    pThis[8] = 50.0f;
    pThis[9] = g_011d8aa4_arg1;
    pThis[10] = g_011d8aa4_arg1;
    pThis[11] = 50.0f;
    pThis[12] = 50.0f;
    ((int*)pThis)[13] = 10000;
    ((int*)pThis)[14] = 30000;
    return pThis;
}

struct FUN_005ed8c0
{
    int pad[7];
    FUN_005ed8c0();
};

struct FUN_005eede0
{
    int pad[4];
    FUN_005eede0();
    ~FUN_005eede0();
};

struct FUN_005eefc0
{
    int pad;
    FUN_005eefc0();
};

struct FUN_005ed850
{
    char b0;
    FUN_005ed8c0 m4;
    FUN_005eede0 m20;
    FUN_005eefc0 m30;
    FUN_005ed850();
};

// Initializes the object by setting b0 to 0 and default-constructing the m4, m20 and m30 members.
// @fnv 0x005ed850
FUN_005ed850::FUN_005ed850() : b0(0)
{}

// Sets the first seven floats of pThis to 0.0f and returns pThis.
// @fnv 0x005ed8c0
float* __fastcall FUN_005ed8c0(float* pThis)
{
    pThis[0] = 0.0f;
    pThis[1] = 0.0f;
    pThis[2] = 0.0f;
    pThis[3] = 0.0f;
    pThis[4] = 0.0f;
    pThis[5] = 0.0f;
    pThis[6] = 0.0f;
    return pThis;
}

namespace fnv_005ed910 {
struct FUN_005eede0
{
    int pad[4];
    FUN_005eede0();
    ~FUN_005eede0();
};

struct FUN_005ef380
{
    int pad;
    FUN_005ef380();
};

struct FUN_005ed910
{
    bool b;
    FUN_005eede0 m1;
    FUN_005ef380 m2;
    FUN_005ed910();
};

// Initializes b to false and default-constructs the m1 and m2 members.
// @fnv 0x005ed910
FUN_005ed910::FUN_005ed910() : b(false)
{}
}  // namespace fnv_005ed910

namespace fnv_005ed980 {
struct FUN_005eede0
{
    int pad[4];
    FUN_005eede0();
    ~FUN_005eede0();
};

struct FUN_005ef380
{
    int pad;
    FUN_005ef380();
};

struct FUN_005ed980
{
    bool b;
    FUN_005eede0 m1;
    FUN_005ef380 m2;
    FUN_005ed980();
};

// Constructor that initializes b to false and default-constructs the m1 and m2 members.
// @fnv 0x005ed980
FUN_005ed980::FUN_005ed980() : b(false)
{}
}  // namespace fnv_005ed980

void __fastcall InitDefaults(void*);

struct FUN_005ed9f0
{
    char m_00;
    BSStringT<char> m_04;
    int m_0c;

    FUN_005ed9f0();
};

// Initializes m_00 to 0 and constructs m_0c by calling InitDefaults.
// @fnv 0x005ed9f0
FUN_005ed9f0::FUN_005ed9f0() : m_00(0)
{
    InitDefaults(&m_0c);
}

// Initializes the object's fields: three shorts to -1, a byte to 0, and floats to 0, 0, 0.1, 0, then returns pThis.
// @fnv 0x005eda60
void* __fastcall InitDefaults(char* pThis)
{
    *(short*)(pThis + 0x0) = -1;
    *(short*)(pThis + 0x2) = -1;
    *(short*)(pThis + 0x4) = -1;
    *(char*)(pThis + 0x6) = 0;
    *(float*)(pThis + 0x8) = 0.0f;
    *(float*)(pThis + 0xc) = 0.0f;
    *(float*)(pThis + 0x10) = 0.1f;
    *(float*)(pThis + 0x14) = 0.0f;
    return pThis;
}

// Byte-swaps four consecutive 16-bit values starting at thisPtr via BSEndian.
// @fnv 0x005ee510
void __fastcall SwapEndianFourShorts(unsigned short* thisPtr)
{
    BSEndian(thisPtr, EndianSizeTag<2>());
    BSEndian(thisPtr + 1, EndianSizeTag<2>());
    BSEndian(thisPtr + 2, EndianSizeTag<2>());
    BSEndian(thisPtr + 3, EndianSizeTag<2>());
}

unsigned int __cdecl BSStringLength(const char* apString);
int __cdecl strcpy_s(char* apDest, unsigned int auiSize, const char* apSrc);

struct GlobalObject_00869f00
{
    void Clear(bool abFreeMemory);
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int aiIndex);
};
struct _Mem_20a4
{
    void SetSize(unsigned int auiNewSize, bool abFreeMemory);
};
struct FUN_0069ccf0_obj
{
    GrabIK_DATA__GrabIK_Arm_DATA& FUN_0069ccf0(unsigned int auiIndex);
};

struct FUN_005ed360_shell : GrabIK_DATA
{
    void FUN_005ed360(const GrabIK_DATA& arData);
};

// Clears this object's arrays, resizes them to match arData, copies the arm data and duplicated strings, then copies bEnabled.
// @fnv 0x005ed360
void FUN_005ed360_shell::FUN_005ed360(const GrabIK_DATA& arSource)
{
    ((GlobalObject_00869f00*)((char*)this + 0x14))->Clear(true);
    for (unsigned int ui = 0; ui < ((ArrSI*)((char*)this + 4))->GetFlags(); ui++)
        delete (void*)*((Arr*)((char*)this + 4))->GetAt(ui);
    ((GlobalObject_00869f00*)((char*)this + 4))->Clear(true);

    ((BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024>*)((char*)this + 0x14))
        ->SetSize(((ArrSI*)((char*)&arSource + 0x14))->GetFlags(), true);
    ((_Mem_20a4*)((char*)this + 4))->SetSize(((ArrSI*)((char*)&arSource + 4))->GetFlags(), true);

    for (unsigned int ui = 0; ui < ((ArrSI*)((char*)&arSource + 0x14))->GetFlags(); ui++)
        ((FUN_0069ccf0_obj*)((char*)this + 0x14))->FUN_0069ccf0(ui) =
            ((FUN_0069ccf0_obj*)((char*)&arSource + 0x14))->FUN_0069ccf0(ui);

    for (unsigned int ui = 0; ui < ((ArrSI*)((char*)&arSource + 4))->GetFlags(); ui++)
    {
        unsigned int uiLength = BSStringLength((const char*)*((Arr*)((char*)&arSource + 4))->GetAt(ui)) + 1;
        char* pString = new char[uiLength];
        strcpy_s(pString, uiLength, (const char*)*((Arr*)((char*)&arSource + 4))->GetAt(ui));
        *((Arr*)((char*)this + 4))->GetAt(ui) = (unsigned int)pString;
    }

    bEnabled = arSource.bEnabled;
}

struct FUN_00501c90_shell
{
    int CompareString(const BSStringT<char>* apString, bool abIgnoreCase);
};

struct FUN_005ed4f0_shell : RagdollFeedbackProfile
{
    bool FUN_005ed4f0(const RagdollFeedbackProfile& arData);
};

// @fnv 0x005ed4f0
bool FUN_005ed4f0_shell::FUN_005ed4f0(const RagdollFeedbackProfile& arOther)
{
    bool bret = false;
    if (((FUN_00501c90_shell*)((char*)this + 4))
            ->CompareString((const BSStringT<char>*)((const char*)&arOther + 4), true))
        bret = true;
    if (bret || bEnabled != arOther.bEnabled ||
        *(short*)((char*)this + 0xc) != *(const short*)((const char*)&arOther + 0xc) ||
        *(short*)((char*)this + 0xe) != *(const short*)((const char*)&arOther + 0xe) ||
        *(short*)((char*)this + 0x10) != *(const short*)((const char*)&arOther + 0x10) ||
        *(float*)((char*)this + 0x14) != *(const float*)((const char*)&arOther + 0x14) ||
        *(float*)((char*)this + 0x1c) != *(const float*)((const char*)&arOther + 0x1c) ||
        *(unsigned char*)((char*)this + 0x12) != *(const unsigned char*)((const char*)&arOther + 0x12) ||
        *(float*)((char*)this + 0x20) != *(const float*)((const char*)&arOther + 0x20) ||
        *(float*)((char*)this + 0x18) != *(const float*)((const char*)&arOther + 0x18))
        bret = true;
    return bret;
}

struct BSStringTCharAssign
{
    BSStringT<char>& operator=(const BSStringT<char>& arString);
};

struct FUN_005ed5f0_shell : RagdollFeedbackProfile
{
    void AssignFrom(const RagdollFeedbackProfile& arData);
};

// Copies a string, a flag and several numeric fields from arData into this object.
// @fnv 0x005ed5f0
void FUN_005ed5f0_shell::AssignFrom(const RagdollFeedbackProfile& arSource)
{
    *(BSStringTCharAssign*)((char*)this + 4) = *(const BSStringT<char>*)((const char*)&arSource + 4);
    bEnabled = arSource.bEnabled;
    *(unsigned short*)((char*)this + 0xc) = *(const unsigned short*)((const char*)&arSource + 0xc);
    *(unsigned short*)((char*)this + 0xe) = *(const unsigned short*)((const char*)&arSource + 0xe);
    *(unsigned short*)((char*)this + 0x10) = *(const unsigned short*)((const char*)&arSource + 0x10);
    *(float*)((char*)this + 0x14) = *(const float*)((const char*)&arSource + 0x14);
    *(float*)((char*)this + 0x1c) = *(const float*)((const char*)&arSource + 0x1c);
    *(unsigned char*)((char*)this + 0x12) = *(const unsigned char*)((const char*)&arSource + 0x12);
    *(float*)((char*)this + 0x18) = *(const float*)((const char*)&arSource + 0x18);
    *(float*)((char*)this + 0x20) = *(const float*)((const char*)&arSource + 0x20);
}

namespace fnv_005edfb0 {
struct GlobalObject_00869f00
{
    void Clear(bool abFreeMemory);
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int aiIndex);
};

struct FUN_005edfb0_shell : BGSRagdoll
{
    void ClearRagdollData();
};

// Frees each element of three arrays at offsets 0xb0, 0xd4 and 0xf8, then clears those arrays and the objects at 0x80, 0xc0, 0xe4 and 0x108.
// @fnv 0x005edfb0
void FUN_005edfb0_shell::ClearRagdollData()
{
    ((GlobalObject_00869f00*)((char*)this + 0x80))->Clear(true);

    for (unsigned int ui = 0; ui < ((ArrSI*)((char*)this + 0xb0))->GetFlags(); ui++)
        delete (void*)*((Arr*)((char*)this + 0xb0))->GetAt(ui);
    ((GlobalObject_00869f00*)((char*)this + 0xc0))->Clear(true);
    ((GlobalObject_00869f00*)((char*)this + 0xb0))->Clear(true);

    for (unsigned int ui = 0; ui < ((ArrSI*)((char*)this + 0xd4))->GetFlags(); ui++)
        delete (void*)*((Arr*)((char*)this + 0xd4))->GetAt(ui);
    ((GlobalObject_00869f00*)((char*)this + 0xe4))->Clear(true);
    ((GlobalObject_00869f00*)((char*)this + 0xd4))->Clear(true);

    for (unsigned int ui = 0; ui < ((ArrSI*)((char*)this + 0xf8))->GetFlags(); ui++)
        delete (void*)*((Arr*)((char*)this + 0xf8))->GetAt(ui);
    ((GlobalObject_00869f00*)((char*)this + 0x108))->Clear(true);
    ((GlobalObject_00869f00*)((char*)this + 0xf8))->Clear(true);
}
}  // namespace fnv_005edfb0

void __cdecl BSEndian(unsigned int*, EndianSizeTag<4>);

struct FUN_005ee380_Data
{
    unsigned int uiValue0;
    unsigned int uiValue1;
    unsigned int uiValue2;
    unsigned int uiValue3;
    unsigned int uiValue4;
    unsigned int uiValue5;
    unsigned int uiValue6;
    unsigned int uiValue7;
    unsigned int uiValue8;
    unsigned int uiValue9;
    unsigned int uiValue10;
    unsigned int uiValue11;
    unsigned int uiValue12;
    unsigned int uiValue13;
    unsigned int uiValue14;
    void FUN_005ee380();
};

// Byte-swaps each of the 15 unsigned int fields of this struct via BSEndian.
// @fnv 0x005ee380
void FUN_005ee380_Data::FUN_005ee380()
{
    BSEndian(&uiValue0, EndianSizeTag<4>());
    BSEndian(&uiValue1, EndianSizeTag<4>());
    BSEndian(&uiValue2, EndianSizeTag<4>());
    BSEndian(&uiValue3, EndianSizeTag<4>());
    BSEndian(&uiValue4, EndianSizeTag<4>());
    BSEndian(&uiValue5, EndianSizeTag<4>());
    BSEndian(&uiValue6, EndianSizeTag<4>());
    BSEndian(&uiValue7, EndianSizeTag<4>());
    BSEndian(&uiValue8, EndianSizeTag<4>());
    BSEndian(&uiValue9, EndianSizeTag<4>());
    BSEndian(&uiValue10, EndianSizeTag<4>());
    BSEndian(&uiValue11, EndianSizeTag<4>());
    BSEndian(&uiValue12, EndianSizeTag<4>());
    BSEndian(&uiValue13, EndianSizeTag<4>());
    BSEndian(&uiValue14, EndianSizeTag<4>());
}

void __cdecl BSEndian(unsigned int*, EndianSizeTag<4>);

struct FUN_005ee580_Data
{
    unsigned short usValue0;
    unsigned short usValue1;
    unsigned short usValue2;
    unsigned char ucValue3;
    unsigned int uiValue3;
    unsigned int uiValue4;
    unsigned int uiValue5;
    unsigned int uiValue6;
    void FUN_005ee580();
};

// Byte-swaps the three 16-bit and four 32-bit fields of the struct via BSEndian.
// @fnv 0x005ee580
void FUN_005ee580_Data::FUN_005ee580()
{
    BSEndian(&usValue0, EndianSizeTag<2>());
    BSEndian(&usValue1, EndianSizeTag<2>());
    BSEndian(&usValue2, EndianSizeTag<2>());
    BSEndian(&uiValue3, EndianSizeTag<4>());
    BSEndian(&uiValue4, EndianSizeTag<4>());
    BSEndian(&uiValue5, EndianSizeTag<4>());
    BSEndian(&uiValue6, EndianSizeTag<4>());
}

namespace fnv_005eeb70 {
struct FUN_005092f0_obj
{
    void FUN_004851b0(TESForm* apCopy);
};
struct FUN_00c7a790_obj
{
    void CopyFrom(const FUN_00c7a790_obj& arData);
};
struct FUN_005ecb30_shell : FootIK_DATA
{
    void FUN_005ecb30(const FootIK_DATA& arData);
};
struct FUN_005ecfd0_shell : LookIK_DATA
{
    void FUN_005ecfd0(const LookIK_DATA& arData);
};
struct FUN_005ed360_shell : GrabIK_DATA
{
    void FUN_005ed360(const GrabIK_DATA& arData);
};
struct FUN_005ed5f0_shell : RagdollFeedbackProfile
{
    void AssignFrom(const RagdollFeedbackProfile& arData);
};
struct FUN_005eeb70_shell : BGSRagdoll
{
    void FUN_005eeb70(TESForm* apCopy);
};

// Casts apCopy to BGSRagdoll, then copies its fields and embedded sub-objects into this ragdoll.
// @fnv 0x005eeb70
void FUN_005eeb70_shell::FUN_005eeb70(TESForm* apCopy)
{
    BGSRagdoll* pcopy = dynamic_cast<BGSRagdoll*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005092f0_obj*)this)->FUN_004851b0(apCopy);
    m_pActorBase = pcopy->m_pActorBase;
    m_pBodyPartDataCur = pcopy->m_pBodyPartDataCur;
    m_iRagdollType = pcopy->m_iRagdollType;
    ((FUN_00c7a790_obj*)((char*)this + 0x40))->CopyFrom(*(FUN_00c7a790_obj*)((char*)pcopy + 0x40));
    ((FUN_005ecb30_shell*)((char*)this + 0x90))->FUN_005ecb30(*(FootIK_DATA*)((char*)pcopy + 0x90));
    ((FUN_005ecfd0_shell*)((char*)this + 0xd0))->FUN_005ecfd0(*(LookIK_DATA*)((char*)pcopy + 0xd0));
    ((FUN_005ed360_shell*)((char*)this + 0xf4))->FUN_005ed360(*(GrabIK_DATA*)((char*)pcopy + 0xf4));
    ((FUN_005ed5f0_shell*)((char*)this + 0x118))->AssignFrom(*(RagdollFeedbackProfile*)((char*)pcopy + 0x118));
}
}  // namespace fnv_005eeb70

namespace fnv_005eec60 {
struct FUN_00509540_obj
{
    bool FUN_00485270(TESForm* apCompare);
};
struct FUN_00c74fb0_obj
{
    bool FUN_00c74fb0(const FUN_00c74fb0_obj& arData);
};
struct FUN_005ec920_shell : FootIK_DATA
{
    bool FUN_005ec920(const FootIK_DATA& arData);
};
struct FUN_005ece50_shell : LookIK_DATA
{
    bool FUN_005ece50(const LookIK_DATA& arData);
};
struct FUN_005ed1e0_shell : GrabIK_DATA
{
    bool FUN_005ed1e0(const GrabIK_DATA& arData);
};
struct FUN_005ed4f0_shell : RagdollFeedbackProfile
{
    bool FUN_005ed4f0(const RagdollFeedbackProfile& arData);
};
struct FUN_005eec60_shell : BGSRagdoll
{
    bool FUN_005eec60(TESForm* apCompare);
};

// Compares this BGSRagdoll with apCompare field by field, returning true if any compared member differs or the cast fails.
// @fnv 0x005eec60
bool FUN_005eec60_shell::FUN_005eec60(TESForm* apCompare)
{
    BGSRagdoll* pcomp = dynamic_cast<BGSRagdoll*>(apCompare);
    if (!pcomp)
        return true;
    if (((FUN_00509540_obj*)this)->FUN_00485270(pcomp))
        return true;
    if (m_iRagdollType != pcomp->m_iRagdollType)
        return true;
    if (((FUN_00c74fb0_obj*)((char*)this + 0x40))->FUN_00c74fb0(*(FUN_00c74fb0_obj*)((char*)pcomp + 0x40)))
        return true;
    if (((FUN_005ec920_shell*)((char*)this + 0x90))->FUN_005ec920(*(FootIK_DATA*)((char*)pcomp + 0x90)))
        return true;
    if (((FUN_005ece50_shell*)((char*)this + 0xd0))->FUN_005ece50(*(LookIK_DATA*)((char*)pcomp + 0xd0)))
        return true;
    if (((FUN_005ed1e0_shell*)((char*)this + 0xf4))->FUN_005ed1e0(*(GrabIK_DATA*)((char*)pcomp + 0xf4)))
        return true;
    if (((FUN_005ed4f0_shell*)((char*)this + 0x118))->FUN_005ed4f0(*(RagdollFeedbackProfile*)((char*)pcomp + 0x118)))
        return true;
    if (m_pBodyPartDataCur != pcomp->m_pBodyPartDataCur)
        return true;
    return false;
}
}  // namespace fnv_005eec60

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
    void* FUN_005eede0();
};
extern int DAT_010472d0;

// Sets the object's vtable pointer to DAT_010472d0, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x005eede0
void* AX::FUN_005eede0()
{
    *(int*)this = (int)&DAT_010472d0;
    FUN_006b3eb0(0, 0);
    return this;
}

struct FUN_005edac0_shell
{
    void FUN_005edc30();
    void* FUN_005edac0(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_005edc30 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005edac0
void* FUN_005edac0_shell::FUN_005edac0(unsigned int flags)
{
    this->FUN_005edc30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_005eee10
{
    ~FUN_005eee10();
};
struct FUN_005ef3b0
{
    ~FUN_005ef3b0();
};
struct FUN_005edbd0
{
    char _0[4];
    FUN_005eee10 a;
    char _pad[15];
    FUN_005ef3b0 b;
    ~FUN_005edbd0();
};
// @fnv 0x005edbd0
FUN_005edbd0::~FUN_005edbd0()
{}

namespace fnv_005eee10 {
extern int DAT_010472d0;

struct GlobalObject_00869f00
{
    void Clear(bool);
};

struct FUN_005eee10_shell
{
    int* p;
    void FUN_005eee10();
};

// @fnv 0x005eee10
void FUN_005eee10_shell::FUN_005eee10()
{
    p = &DAT_010472d0;
    ((GlobalObject_00869f00*)this)->Clear(true);
}
}  // namespace fnv_005eee10

namespace fnv_005edb10 {
struct FUN_005eee10
{
    ~FUN_005eee10();
};
struct FUN_005eeff0
{
    ~FUN_005eeff0();
};
struct FUN_005edb10
{
    char _pad0[0x20];
    FUN_005eee10 m20;
    char _pad1[0x0F];
    FUN_005eeff0 m30;
    ~FUN_005edb10();
};
// @fnv 0x005edb10
FUN_005edb10::~FUN_005edb10()
{}
}  // namespace fnv_005edb10

namespace fnv_005edb70 {
struct FUN_005eee10
{
    ~FUN_005eee10();
};
struct FUN_005ef1d0
{
    ~FUN_005ef1d0();
};
struct FUN_005edb70
{
    int _00;
    FUN_005eee10 _04;
    char _pad[15];
    FUN_005ef1d0 _14;
    ~FUN_005edb70();
};
// @fnv 0x005edb70
FUN_005edb70::~FUN_005edb70()
{}
}  // namespace fnv_005edb70

namespace fnv_005ef010 {
struct FUN_005ef010_Item
{
    char b[0x38];
};
struct GlobalObject_00869f00
{
    void Clear(bool b);
};
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void* p, unsigned int n);
};
struct FUN_005ef010_Arr
{
    virtual void v0();
    virtual FUN_005ef010_Item* Allocate(unsigned int n);
    FUN_005ef010_Item* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    void ConstructSpawnItems(FUN_005ef010_Item* p, unsigned int n);
    void FUN_005ef860(unsigned int newAlloc, unsigned int copy);
    void FUN_005ef010(unsigned int aiNewSize, bool abFreeMemory);
};

// @fnv 0x005ef010
void FUN_005ef010_Arr::FUN_005ef010(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        ((GlobalObject_00869f00*)this)->Clear(abFreeMemory);
    }
    else if (aiNewSize > uiAllocSize)
    {
        if (uiAllocSize == 0)
        {
            pBuffer = Allocate(aiNewSize);
            uiAllocSize = aiNewSize;
        }
        else
        {
            FUN_005ef860(aiNewSize, uiSize);
            uiAllocSize = aiNewSize;
        }
        ConstructSpawnItems(pBuffer + uiSize, aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
    else if (aiNewSize < uiSize)
    {
        ((FUN_0072ba80_shell*)this)->FUN_0072ba80(pBuffer + aiNewSize, uiSize - aiNewSize);
        uiSize = aiNewSize;
        if (abFreeMemory && aiNewSize <= uiAllocSize >> 2)
        {
            FUN_005ef860(aiNewSize, aiNewSize);
            uiAllocSize = aiNewSize;
        }
    }
    else
    {
        ConstructSpawnItems(pBuffer + uiSize, aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
}
}  // namespace fnv_005ef010

namespace fnv_005ef1f0 {
struct FUN_005ef1f0_Item
{
    char b[0x28];
};
struct GlobalObject_00869f00
{
    void Clear(bool b);
};
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void* p, unsigned int n);
};
struct FUN_005ef1f0_Arr
{
    virtual void v0();
    virtual FUN_005ef1f0_Item* Allocate(unsigned int n);
    FUN_005ef1f0_Item* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    void ConstructEntries(FUN_005ef1f0_Item* p, unsigned int n);
    void FUN_005efa80(unsigned int newAlloc, unsigned int copy);
    void FUN_005ef1f0(unsigned int aiNewSize, bool abFreeMemory);
};

// @fnv 0x005ef1f0
void FUN_005ef1f0_Arr::FUN_005ef1f0(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        ((GlobalObject_00869f00*)this)->Clear(abFreeMemory);
    }
    else if (aiNewSize > uiAllocSize)
    {
        if (uiAllocSize == 0)
        {
            pBuffer = Allocate(aiNewSize);
            uiAllocSize = aiNewSize;
        }
        else
        {
            FUN_005efa80(aiNewSize, uiSize);
            uiAllocSize = aiNewSize;
        }
        ConstructEntries(pBuffer + uiSize, aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
    else if (aiNewSize < uiSize)
    {
        ((FUN_0072ba80_shell*)this)->FUN_0072ba80(pBuffer + aiNewSize, uiSize - aiNewSize);
        uiSize = aiNewSize;
        if (abFreeMemory && aiNewSize <= uiAllocSize >> 2)
        {
            FUN_005efa80(aiNewSize, aiNewSize);
            uiAllocSize = aiNewSize;
        }
    }
    else
    {
        ConstructEntries(pBuffer + uiSize, aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
}
}  // namespace fnv_005ef1f0

namespace fnv_005ef3d0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};
struct GrabIK_Arm_DATA_005ef3d0
{
    unsigned short data[3];
};
struct BSSimpleArray_005ef3d0
{
    virtual void Destroy(bool);
    virtual GrabIK_Arm_DATA_005ef3d0* Allocate(unsigned int);
    GrabIK_Arm_DATA_005ef3d0* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    void FUN_005efc90(unsigned int, unsigned int);
    void ConstructItems(GrabIK_Arm_DATA_005ef3d0*, unsigned int);
    void FUN_005ef3d0(unsigned int aiNewSize, bool abFreeMemory);
};

// @fnv 0x005ef3d0
void BSSimpleArray_005ef3d0::FUN_005ef3d0(unsigned int aiNewSize, bool abFreeMemory)
{
    if (aiNewSize == 0)
    {
        ((GlobalObject_00869f00*)this)->Clear(abFreeMemory);
    }
    else if (aiNewSize > uiAllocSize)
    {
        if (uiAllocSize == 0)
        {
            pBuffer = Allocate(aiNewSize);
            uiAllocSize = aiNewSize;
        }
        else
        {
            FUN_005efc90(aiNewSize, uiSize);
            uiAllocSize = aiNewSize;
        }
        ConstructItems(pBuffer + uiSize, aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
    else if (aiNewSize < uiSize)
    {
        ((FUN_0072ba80_shell*)this)->FUN_0072ba80(pBuffer + aiNewSize, uiSize - aiNewSize);
        uiSize = aiNewSize;
        if (abFreeMemory && aiNewSize <= uiAllocSize >> 2)
        {
            FUN_005efc90(aiNewSize, aiNewSize);
            uiAllocSize = aiNewSize;
        }
    }
    else
    {
        ConstructItems(pBuffer + uiSize, aiNewSize - uiSize);
        uiSize = aiNewSize;
    }
}
}  // namespace fnv_005ef3d0

namespace fnv_005ee110 {
struct FUN_004855a0
{
    void M();
};

struct FUN_00485680
{
    void M();
};

struct FUN_004891d0_obj
{
    void WriteToBuffer(unsigned int, unsigned int);
};

struct ArrSI
{
    unsigned int GetFlags();
};

struct DA00694f80
{
    unsigned short& GetAt(int);
};

struct FUN_005ee110_String
{
    unsigned int Length();
    operator unsigned int() const;
};

struct FUN_005ee110_shell
{
    void FUN_005ee110();
};

bool __cdecl _FUN_00401500();
void __cdecl _FUN_00485910(unsigned int, unsigned int);
void __cdecl _FUN_00485990(unsigned int, void*, unsigned int);
void __cdecl FUN_00485730(void*, void*, void*);
void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
void __fastcall SwapEndianFourShorts(unsigned short*);

// @fnv 0x005ee110
void FUN_005ee110_shell::FUN_005ee110()
{
    SaveMetadata saveData;

    reinterpret_cast<FUN_004855a0*>(this)->M();

    reinterpret_cast<FUN_004891d0_obj*>(reinterpret_cast<unsigned char*>(this) + 0x18)
        ->WriteToBuffer(0x4c444f4d, 0x54444f4d);

    _FUN_00485910(0x5245564e, 1);

    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(&saveData) + 0x00) =
        reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x80)->GetFlags();

    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(&saveData) + 0x02) =
        reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0xc0)->GetFlags();

    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(&saveData) + 0x04) =
        reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0xe4)->GetFlags();

    *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(&saveData) + 0x06) =
        reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x108)->GetFlags();

    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(&saveData) + 0x08) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x40);

    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(&saveData) + 0x09) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x90);

    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(&saveData) + 0x0a) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0xd0);

    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(&saveData) + 0x0b) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0xf4);

    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(&saveData) + 0x0c) =
        *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x118);

    if (_FUN_00401500())
        SwapEndianFourShorts(reinterpret_cast<unsigned short*>(&saveData));

    _FUN_00485990(0x41544144, &saveData, 0x0e);

    if (_FUN_00401500())
        SwapEndianFourShorts(reinterpret_cast<unsigned short*>(&saveData));

    if (*reinterpret_cast<TESActorBase**>(reinterpret_cast<unsigned char*>(this) + 0x144))
    {
        unsigned int itempint;
        itempint = (*reinterpret_cast<TESActorBase**>(reinterpret_cast<unsigned char*>(this) + 0x144))->GetFormID();
        _FUN_00485910(0x4d414e58, itempint);
    }

    if (*reinterpret_cast<BGSBodyPartData**>(reinterpret_cast<unsigned char*>(this) + 0x140))
    {
        unsigned int itempint;
        itempint = (*reinterpret_cast<BGSBodyPartData**>(reinterpret_cast<unsigned char*>(this) + 0x140))->GetFormID();
        _FUN_00485910(0x4d414e54, itempint);
    }

    if (_FUN_00401500())
        reinterpret_cast<RagdollFeedbackData__RagdollFeedbackSystemData*>(reinterpret_cast<unsigned char*>(this) + 0x44)
            ->FUN_005ee380();

    _FUN_00485990(0x44464152, reinterpret_cast<unsigned char*>(this) + 0x44, 0x3c);

    if (_FUN_00401500())
        reinterpret_cast<RagdollFeedbackData__RagdollFeedbackSystemData*>(reinterpret_cast<unsigned char*>(this) + 0x44)
            ->FUN_005ee380();

    if (reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x80)->GetFlags() > 0)
    {
        FUN_00485730(reinterpret_cast<void*>(0x42464152),
                     &reinterpret_cast<DA00694f80*>(reinterpret_cast<unsigned char*>(this) + 0x80)->GetAt(0),
                     reinterpret_cast<void*>(
                         reinterpret_cast<ArrSI*>(reinterpret_cast<unsigned char*>(this) + 0x80)->GetFlags()));
    }

    if (_FUN_00401500())
        reinterpret_cast<PoseMatching_DATA__PoseMatching_System_DATA*>(reinterpret_cast<unsigned char*>(this) + 0x124)
            ->FUN_005ee580();

    _FUN_00485990(0x53504152, reinterpret_cast<unsigned char*>(this) + 0x124, 0x18);

    if (_FUN_00401500())
        reinterpret_cast<PoseMatching_DATA__PoseMatching_System_DATA*>(reinterpret_cast<unsigned char*>(this) + 0x124)
            ->FUN_005ee580();

    if (reinterpret_cast<FUN_005ee110_String*>(reinterpret_cast<unsigned char*>(this) + 0x11c)->Length())
    {
        FUN_004856f0(0x4d414e41,
                     reinterpret_cast<void*>(
                         reinterpret_cast<FUN_005ee110_String*>(reinterpret_cast<unsigned char*>(this) + 0x11c)
                             ->
                             operator unsigned int()),
                     reinterpret_cast<FUN_005ee110_String*>(reinterpret_cast<unsigned char*>(this) + 0x11c)->Length() +
                         1);
    }

    reinterpret_cast<FUN_00485680*>(this)->M();
}
}  // namespace fnv_005ee110

// RunInner: a thin thiscall wrapper that forwards to a method of the
// sub-object living at offset 0x40 of the owner object.
struct Inner
{
    void Run();
};

struct FUN_005edaf0_cls
{
    int unk00;
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
    int unk3C;
    Inner m_40;
    void RunInner();
};

// @fnv 0x005edaf0
void FUN_005edaf0_cls::RunInner()
{
    m_40.Run();
}

class ObjPrimary
{
  public:
    virtual void v00();
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    ~ObjPrimary();
};

class ObjSecondary
{
  public:
    virtual void v00();
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    ~ObjSecondary();
};

class ObjMemberA
{
  public:
    ObjMemberA();
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    ~ObjMemberA();
};

class ObjMemberB
{
  public:
    ObjMemberB();
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    ~ObjMemberB();
};

class ObjMemberC
{
  public:
    ObjMemberC();
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    ~ObjMemberC();
};

class ObjMemberD
{
  public:
    ObjMemberD();
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    ~ObjMemberD();
};

class ObjMemberE
{
  public:
    ObjMemberE();
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    ~ObjMemberE();
};

class FUN_005edc30 : public ObjPrimary, public ObjSecondary
{
  public:
    void Reset();
    ObjMemberA m_40;
    ObjMemberB m_90;
    ObjMemberC m_d0;
    ObjMemberD m_f4;
    ObjMemberE m_118;
    virtual ~FUN_005edc30();
};

// @fnv 0x005edc30
FUN_005edc30::~FUN_005edc30()
{
    Reset();
}
