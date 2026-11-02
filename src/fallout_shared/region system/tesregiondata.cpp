// fallout_shared/region system/tesregiondata.cpp: TESRegionData, RegionSource (8 functions)

#include "tesregiondata_decls.h"

// Copies the override form type and priority from the given data into this region data, returning false if data is null.
// @fnv 0x004f1560
bool TESRegionData::ApplyEntry(RegionDataEntry* data)
{
    if (!data)
        return false;
    reinterpret_cast<TESForm*>(this)->SetFormType(static_cast<ENUM_FORM_ID>(data->bOverride));
    SetPriority(data->m_ucRegionPriority);
    return true;
}

extern int DAT_01023ac4;

// Sets the object's vtable pointer to DAT_01023ac4 and initialises the bytes at offsets 4, 5 and 6 to 0, 0 and 50, returning pThis.
// @fnv 0x004f1400
void* __fastcall InitVTableAndFields(void* pThis)
{
    *(int**)pThis = &DAT_01023ac4;
    *((char*)pThis + 4) = 0;
    *((char*)pThis + 6) = 50;
    *((char*)pThis + 5) = 0;
    return pThis;
}

struct FUN_004f15c0_shell : public TESRegionData
{
    bool FUN_004f15c0(unsigned char);
};

// Stores acPriority at offset 6 of this object and returns true when acPriority is at most 100, otherwise returns false.
// @fnv 0x004f15c0
bool FUN_004f15c0_shell::FUN_004f15c0(unsigned char acPriority)
{
    if (acPriority <= 100)
    {
        *((unsigned char*)this + 6) = acPriority;
        return true;
    }
    return false;
}

void __cdecl operator delete(void*);
void* __fastcall FUN_004f14a0(void* pThis);

struct FUN_004f1430_shell
{
    void* __thiscall FUN_004f1430(unsigned int flags);
};

// Calls FUN_004f14a0 on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x004f1430
void* __thiscall FUN_004f1430_shell::FUN_004f1430(unsigned int flags)
{
    FUN_004f14a0(this);
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_004f14a0_shell
{
    int* value;
    void FUN_004f14a0();
};

// @fnv 0x004f14a0
void __thiscall FUN_004f14a0_shell::FUN_004f14a0()
{
    value = &DAT_01023ac4;
}

struct FUN_004f15a0_shell : public TESForm
{
    void FUN_004f15a0(int);
};

// @fnv 0x004f15a0
void FUN_004f15a0_shell::FUN_004f15a0(int aType)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<int*>(this) + 1) = static_cast<unsigned char>(aType);
}

struct FUN_004f1460
{
    virtual void Dummy();
    bool bOverride;
    bool m_bHasRegionData;
    unsigned char m_ucRegionPriority;
    FUN_004f1460(const FUN_004f1460& other);
};
// @fnv 0x004f1460
FUN_004f1460::FUN_004f1460(const FUN_004f1460& other)
{
    bOverride = other.bOverride;
    m_ucRegionPriority = other.m_ucRegionPriority;
    m_bHasRegionData = other.m_bHasRegionData;
}

#include <string.h>
bool __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int, const void*, unsigned int);

struct RegionSaveData
{
    unsigned int m_eRegionDataId;
    bool bOverride;
    unsigned char m_ucRegionPriority;
    unsigned short unk06;
    void FUN_00503210();
};

struct RegionSource
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual unsigned int GetType();
    bool FUN_004f1540();
    unsigned char FUN_005bb4d0();
    void WriteSaveData();
};

// @fnv 0x004f14c0
void RegionSource::WriteSaveData()
{
    RegionSaveData data;
    memset(&data, 0, sizeof(data));
    data.m_eRegionDataId = GetType();
    data.bOverride = FUN_004f1540();
    data.m_ucRegionPriority = FUN_005bb4d0();
    if (FUN_00401500())
        data.FUN_00503210();
    AppendChunk(0x54414452, &data, sizeof(data));
    if (FUN_00401500())
        data.FUN_00503210();
}
