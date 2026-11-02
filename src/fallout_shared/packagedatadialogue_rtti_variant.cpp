
// src/fallout_shared/packagedatadialogue_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESDialoguePackageData, TESPackageData). The skeleton of src/fallout_shared/packagedatadialogue.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "packagedatadialogue_decls_rtti_variant.h"
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
