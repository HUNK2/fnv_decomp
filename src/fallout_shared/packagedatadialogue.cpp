// fallout_shared/packagedatadialogue.cpp: TESDialoguePackageData, DelStandIn, ConstructorHost (8 functions)

#include "packagedatadialogue_decls.h"
// Resolves the stored topic ID to a TESTopic via the form's file and warns if the topic is missing.
// @fnv 0x0067b590
void TESDialoguePackageData::InitItem(TESForm* form)
{
    unsigned int topicID = (unsigned int)pMenuTopicEntry;
    TESForm::RemapFormIDForFile(topicID, form->GetFile(-1));
    pMenuTopicEntry = dynamic_cast<TESTopic*>(GetFormByID(topicID));
    if (!pMenuTopicEntry && topicID)
        Warning("FORMS: Failed to find topic (%08X) in init for dialogue package data on package '%s' (%08X).", topicID,
                form->GetName(), form->GetFormID());
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0067b1e0(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x0067b1e0
void* DelStandIn::FUN_0067b1e0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct FUN_00670b30
{
    void* __vecDelDtor(unsigned int);
};

struct FUN_0067ad70_cls
{
    virtual ~FUN_0067ad70_cls();
    int field4;
    int field8;
};

struct FUN_0067b280_cls : FUN_0067ad70_cls
{
    FUN_00670b30* data;
    virtual ~FUN_0067b280_cls();
};

// Destructor that deletes the owned data object via its vector deleting destructor.
// @fnv 0x0067b280
FUN_0067b280_cls::~FUN_0067b280_cls()
{
    FUN_00670b30* b = data;
    FUN_00670b30* a = b;
    a ? a->__vecDelDtor(1) : 0;
}

class BGSLoadFormBuffer;
struct FUN_0067fc50_impl
{
    void ResolveObject(BGSLoadFormBuffer*);
};
struct FUN_0067b920_host
{
    int pad0;
    int pad4;
    int pad8;
    FUN_0067fc50_impl* padC;
    void FUN_0067b920(BGSLoadFormBuffer*);
};
// If padC is non-null, forwards apLoadGameBuffer to padC's ResolveObject.
// @fnv 0x0067b920
void FUN_0067b920_host::FUN_0067b920(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (padC != 0)
        padC->ResolveObject(apLoadGameBuffer);
}

struct LocationDescriptor
{
    void Save(int);
};

struct FUN_0067b100_Class
{
    float m_fFirstFloat;
    unsigned int m_uiTopicFormID;
    bool m_bFirstFlag;
    bool m_bFollowingFlag;
    float m_fFloatValue;
    bool m_bThirdFlag;
    int m_iTrailingValue;

    void FUN_0067b100();
};

typedef FUN_0067b100_Class FunctionObject;

void* memset(void*, int, unsigned int);
bool _FUN_00401500();
void _FUN_00485990(int, void*, unsigned int);

struct FUN_0067b630_cls
{
    unsigned int pad0;
    float m_fFirstFloat;
    TESTopic* pMenuTopicEntry;
    LocationDescriptor* m_pTargetLocation;
    bool m_bFirstFlag;
    bool m_bFollowingFlag;
    float m_fFloatValue;
    bool m_bThirdFlag;
    int m_iTrailingValue;

    void SaveTopicData();
};

// @fnv 0x0067b630
void FUN_0067b630_cls::SaveTopicData()
{
    FunctionObject saveData;

    memset(&saveData, 0, 0x18);
    saveData.m_bFirstFlag = m_bFirstFlag;
    saveData.m_fFirstFloat = m_fFirstFloat;
    saveData.m_bFollowingFlag = m_bFollowingFlag;
    saveData.m_bThirdFlag = m_bThirdFlag;
    saveData.m_iTrailingValue = m_iTrailingValue;
    saveData.m_fFloatValue = m_fFloatValue;

    if (pMenuTopicEntry)
        saveData.m_uiTopicFormID = pMenuTopicEntry->GetFormID();

    if (_FUN_00401500())
        saveData.FUN_0067b100();

    _FUN_00485990(0x44444b50, &saveData, 0x18);

    if (_FUN_00401500())
        saveData.FUN_0067b100();

    if (m_pTargetLocation)
        m_pTargetLocation->Save(0x32444c50);
}

struct FUNObj
{
    void FUN_0067fb60(void*);
};

struct SaveFormIDHelper
{
    void SerializeFormData(void*, int);
};

struct BGSSaveFormBuffer : SaveFormIDHelper
{
    void SaveData(void*, int, int);
};

struct TESPackageData
{
    int pad;
};

struct FUN_0067b6f0_cls : TESPackageData
{
    int field4;
    TESTopic* pMenuTopicEntry;
    FUNObj* m_pTargetLocation;
    bool field10;
    bool field11;
    bool field12;
    int field14;
    bool field18;
    int field1c;

    void SavePackageData(BGSSaveFormBuffer*);
};

// Serializes the package fields to the save buffer, then saves the topic and, if a location object exists, saves it too.
// @fnv 0x0067b6f0
void FUN_0067b6f0_cls::SavePackageData(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData(&field4, 4, 0);
    apSaveGameBuffer->SaveData(&field10, 1, 0);
    apSaveGameBuffer->SaveData(&field11, 1, 0);
    apSaveGameBuffer->SaveData(&field12, 1, 0);
    apSaveGameBuffer->SaveData(&field14, 4, 0);
    apSaveGameBuffer->SaveData(&field18, 1, 0);
    apSaveGameBuffer->SaveData(&field1c, 4, 0);
    apSaveGameBuffer->SerializeFormData(pMenuTopicEntry, 0);

    bool bhasLocation = m_pTargetLocation;
    apSaveGameBuffer->SaveData(&bhasLocation, 1, 0);
    if (bhasLocation)
        m_pTargetLocation->FUN_0067fb60(apSaveGameBuffer);
}

struct PairOfBytes
{
    unsigned char first;
    unsigned char second;
};

extern void* UNK_010688ac;

struct ConstructorHost
{
    void* vtable;
    float value04;
    unsigned int value08;
    unsigned int value0C;
    unsigned char value10;
    unsigned char value11;
    float value14;
    unsigned char value18;
    unsigned int value1C;

    void FUN_0067ad20();
    ConstructorHost* Construct(float initial, unsigned int object, PairOfBytes flags, float scale,
                               unsigned char enabled, unsigned int reference);
};

// Calls FUN_0067ad20, sets the vtable, then stores the six arguments into the object's fields and returns this.
// @fnv 0x0067b210
ConstructorHost* ConstructorHost::Construct(float initial, unsigned int object, PairOfBytes flags, float scale,
                                            unsigned char enabled, unsigned int reference)
{
    FUN_0067ad20();
    vtable = &UNK_010688ac;
    value04 = initial;
    value10 = flags.first;
    value08 = object;
    value14 = scale;
    value0C = 0;
    value11 = flags.second;
    value18 = enabled;
    value1C = reference;
    return this;
}

void* __cdecl operator new(unsigned int);

class TESForm;

class BGSLoadFormBuffer
{
  public:
    unsigned int ReadFormIdentifier();
    void ReadTypedData(void* data, unsigned int size);
};

TESForm* __cdecl _GetFormByNumericID(unsigned int formID);

struct TESEatPackageData_
{
    int field0;
    int field4;

    void FUN_0067fbe0(BGSLoadFormBuffer* buffer);
};

struct B0067f030 : TESEatPackageData_
{
    int field8;

    B0067f030();
};

struct FUN_0067b7d0_shell
{
    int field0;
    int field4;
    TESTopic* pMenuTopicEntry;
    LocationDescriptor* m_pTargetLocation;
    unsigned char field10;
    unsigned char field11;
    unsigned char field12;
    unsigned int field14;
    unsigned char field18;
    unsigned int field1c;

    void FUN_0067b7d0(BGSLoadFormBuffer* apLoadGameBuffer);
};

// Reads fields from apLoadGameBuffer, resolves pMenuTopicEntry by form ID, and optionally allocates and reads m_pTargetLocation.
// @fnv 0x0067b7d0
void FUN_0067b7d0_shell::FUN_0067b7d0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    apLoadGameBuffer->ReadTypedData(&field4, 4);
    apLoadGameBuffer->ReadTypedData(&field10, 1);
    apLoadGameBuffer->ReadTypedData(&field11, 1);
    apLoadGameBuffer->ReadTypedData(&field12, 1);
    apLoadGameBuffer->ReadTypedData(&field14, 4);
    apLoadGameBuffer->ReadTypedData(&field18, 1);
    apLoadGameBuffer->ReadTypedData(&field1c, 4);

    pMenuTopicEntry = dynamic_cast<TESTopic*>(_GetFormByNumericID(apLoadGameBuffer->ReadFormIdentifier()));

    bool bhasLocation = false;
    apLoadGameBuffer->ReadTypedData(&bhasLocation, 1);
    if (bhasLocation)
    {
        m_pTargetLocation = (LocationDescriptor*)new B0067f030;
        ((TESEatPackageData_*)m_pTargetLocation)->FUN_0067fbe0(apLoadGameBuffer);
    }
}
