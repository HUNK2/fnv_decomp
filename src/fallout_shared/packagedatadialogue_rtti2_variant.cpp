// src/fallout_shared/packagedatadialogue_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESDialoguePackageData, TESPackageData). The skeleton of src/fallout_shared/packagedatadialogue.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.


#include "packagedatadialogue_decls_rtti2_packagedatadialogue.h"
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
    virtual ~TESPackageData();  // the original class is polymorphic (rtti_variants.py)
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

struct DialogueTargetComparison : LocationDescriptor
{
    bool IsDifferentFrom(DialogueTargetComparison*);
};

struct DialoguePackageComparison : TESDialoguePackageData
{
    DialogueTargetComparison* m_pTargetLocation;
    unsigned char m_bFirstFlag;
    unsigned char m_bFollowingFlag;
    float m_fFloatValue;
    unsigned char m_bThirdFlag;
    int m_iTrailingValue;

    bool FUN_0067b470(void*);
};

// @fnv 0x0067b470
bool DialoguePackageComparison::FUN_0067b470(void* object)
{
    DialoguePackageComparison* other = reinterpret_cast<DialoguePackageComparison*>(
        dynamic_cast< ::TESDialoguePackageData*>(static_cast< ::TESPackageData*>(object)));

    if (other == 0)
        return true;

    if (m_fFirstFloat != other->m_fFirstFloat)
        return true;

    if (m_fFloatValue != other->m_fFloatValue)
        return true;

    if (m_bFirstFlag != other->m_bFirstFlag)
        return true;

    if (pMenuTopicEntry != other->pMenuTopicEntry)
        return true;

    if (m_pTargetLocation != 0)
    {
        if (m_pTargetLocation->IsDifferentFrom(other->m_pTargetLocation))
            return true;
    }
    else if (other->m_pTargetLocation != 0)
    {
        return true;
    }

    if (m_bFollowingFlag != other->m_bFollowingFlag)
        return true;

    if (m_bThirdFlag != other->m_bThirdFlag)
        return true;

    if (m_iTrailingValue != other->m_iTrailingValue)
        return true;

    return false;
}
