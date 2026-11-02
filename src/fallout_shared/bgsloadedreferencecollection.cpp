// fallout_shared/bgsloadedreferencecollection.cpp: LoadedReferenceMap, BGSLoadedReferenceCollection, TESContainer (4 functions)

#include "bgsloadedreferencecollection.h"

// Inserts pRef into the map by its form ID if absent, increments iCount and records the current timestamp.
// @fnv 0x00526bd0
bool LoadedReferenceMap::AddReference(TESObjectREFR* pRef)
{
    TESObjectREFR* existing = 0;
    if (GetAt(pRef->GetFormID(), existing))
        return false;

    SetAt(pRef->GetFormID(), pRef);
    iCount++;
    m_uiLastUpdateTime = g_timeGlobal.GetTimeStamp();
    return true;
}

struct S_00526b40
{
    void FUN_00526b70();
    void* FUN_00526b40(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_00526b70, then frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00526b40
void* S_00526b40::FUN_00526b40(unsigned int flags)
{
    this->FUN_00526b70();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct TESSound;
struct ExtraRadioData;
struct TESObjectSTAT;

extern TESObjectSTAT* DAT_011ca264;

TESObjectREFR* __fastcall _FNV_GetObjectReference(TESObjectREFR* object);
unsigned int __fastcall _FNV_GetFormType(TESForm* object);

struct TESContainer
{
    static bool __cdecl IsValidContainerType(unsigned char type);
};

struct FUN_00526c40_Class
{
    bool RemoveSound(TESSound* reference);
};

struct TESObjectREFR_ext
{
    ExtraRadioData* GetExtraRadioData();
};

struct BGSLoadedReferenceCollection
{
    unsigned char pad0[0x18];
    FUN_00526c40_Class member18;
    unsigned char pad1[0x47];
    FUN_00526c40_Class member60;
    unsigned char pad2[0x17];
    FUN_00526c40_Class member78;
    unsigned char pad3[0x17];
    FUN_00526c40_Class member90;
    unsigned char pad4[0x17];
    FUN_00526c40_Class memberA8;

    char* GetFieldByType(unsigned int type);
    void FUN_005270b0(TESObjectREFR* apRef);
};

// Gets the form type of apRef's base object and adds apRef to the collection's per-type lists based on that type and extra data.
// @fnv 0x005270b0
void BGSLoadedReferenceCollection::FUN_005270b0(TESObjectREFR* apRef)
{
    unsigned int eformType;

    eformType = _FNV_GetFormType(_FNV_GetObjectReference(apRef));

    if (TESContainer::IsValidContainerType((unsigned char)eformType))
    {
        LoadedReferenceMap* prefMap;

        member18.RemoveSound(reinterpret_cast<TESSound*>(apRef));
        prefMap = reinterpret_cast<LoadedReferenceMap*>(GetFieldByType(eformType));
        if (prefMap)
            reinterpret_cast<FUN_00526c40_Class*>(prefMap)->RemoveSound(reinterpret_cast<TESSound*>(apRef));
    }

    if (eformType == 0x1B)
        member60.RemoveSound(reinterpret_cast<TESSound*>(apRef));

    if (eformType == 0x2A || eformType == 0x2B)
        member78.RemoveSound(reinterpret_cast<TESSound*>(apRef));

    if (_FNV_GetObjectReference(apRef) == reinterpret_cast<void*>(DAT_011ca264))
        member90.RemoveSound(reinterpret_cast<TESSound*>(apRef));

    if (eformType == 0x51)
        member90.RemoveSound(reinterpret_cast<TESSound*>(apRef));

    if (eformType == 0x1C && reinterpret_cast<TESObjectREFR_ext*>(apRef)->GetExtraRadioData())
        memberA8.RemoveSound(reinterpret_cast<TESSound*>(apRef));
}

struct Base_00527840
{
    virtual ~Base_00527840();
    void FUN_00438af0();
};

struct FUN_00526b70 : Base_00527840
{
    ~FUN_00526b70();
};

// Destructor that calls FUN_00438af0 on the base object.
// @fnv 0x00526b70
FUN_00526b70::~FUN_00526b70()
{
    FUN_00438af0();
}
