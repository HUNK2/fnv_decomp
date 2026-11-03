
// src/fallout_shared/packagedataescort.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataescort.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void _Deallocate(void*);
struct TESEscortPackageData
{
    void FUN_0067bca0();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_0067bca0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0067bc30
void* TESEscortPackageData::DestroyIfFlagged(unsigned int flags)
{
    FUN_0067bca0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct TESForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct LocationDescriptor;
struct TESPackageData;
struct FUN_0067ad20_shell
{
    void __thiscall FUN_0067ad20();
};
extern int DAT_01068960;

struct FUN_0067bc60_shell
{
    void* m_vtbl;
    int m_flags;
    TESForm* m_form;
    FUN_0067bc60_shell* __thiscall ConstructFromForm(TESForm** pForm);
};

// Calls the base constructor, sets the vtable to DAT_01068960, clears m_flags, stores *pForm into m_form and returns this.
// @fnv 0x0067bc60
FUN_0067bc60_shell* __thiscall FUN_0067bc60_shell::ConstructFromForm(TESForm** pForm)
{
    ((FUN_0067ad20_shell*)this)->FUN_0067ad20();
    m_vtbl = &DAT_01068960;
    m_flags = 0;
    m_form = *pForm;
    return this;
}

namespace fnv_0067bec0 {
struct IntegerData
{
    int m_iValue;
};
bool FUN_00401500();
void AppendChunk(int, void*, int);
struct BipedModelForm
{
    void Endian();
};
struct LocationDescriptor
{
    void Save(int);
};
void* memset(void*, int, unsigned int);
struct TESEscortPackageData
{
    void* base;
    LocationDescriptor* m_pPackageTarget;
    int m_iValue;
    void TESEscortPackageData_Save();
};
// @fnv 0x0067bec0
void TESEscortPackageData::TESEscortPackageData_Save()
{
    IntegerData valueBlock;
    memset(&valueBlock, 0, 4);
    valueBlock.m_iValue = m_iValue;
    if (FUN_00401500())
        ((BipedModelForm*)&valueBlock)->Endian();
    AppendChunk(0x32454b50, &valueBlock, 4);
    if (FUN_00401500())
        ((BipedModelForm*)&valueBlock)->Endian();
    if (m_pPackageTarget)
        m_pPackageTarget->Save(0x32444c50);
}
}  // namespace fnv_0067bec0

namespace fnv_0067bf40 {
struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
struct FUN_0067fb60_holder
{
    void FUN_0067fb60(void*);
};
struct TESEscortPackageData
{
    void* pBase;
    void* m_pPackageTarget;
    void FUN_0067bf40(BGSSaveFormBuffer* buffer);
};
// @fnv 0x0067bf40
void TESEscortPackageData::FUN_0067bf40(BGSSaveFormBuffer* buffer)
{
    buffer->SaveData(reinterpret_cast<char*>(this) + 8, 4, 0);
    bool hasLocation = (m_pPackageTarget != 0) ? true : false;
    buffer->SaveData(reinterpret_cast<char*>(&hasLocation), 1, 0);
    if (hasLocation)
        reinterpret_cast<FUN_0067fb60_holder*>(m_pPackageTarget)->FUN_0067fb60(buffer);
}
}  // namespace fnv_0067bf40

struct LocationDescriptor
{
    void* m_vtbl;
    int m_flags;
    ~LocationDescriptor();
};
struct FUN_0067ad70_cls
{
    virtual ~FUN_0067ad70_cls();
    LocationDescriptor* m_pLoc;
};
struct FUN_0067bca0 : FUN_0067ad70_cls
{
    ~FUN_0067bca0();
};
// @fnv 0x0067bca0
FUN_0067bca0::~FUN_0067bca0()
{
    delete m_pLoc;
}

namespace fnv_0067c330 {
void* __cdecl operator new(unsigned int);
struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
    unsigned char ReadTypedData(bool*, unsigned int);
};
struct LocationDescriptor
{
    LocationDescriptor();
    ~LocationDescriptor();
    void FUN_0067fbe0(BGSLoadFormBuffer*);
    int pad[3];
};
struct FUN_0067c330_shell
{
    void* m_base;
    LocationDescriptor* m_pPackageTarget;
    void FUN_0067c330(BGSLoadFormBuffer* buffer);
};
// @fnv 0x0067c330
void FUN_0067c330_shell::FUN_0067c330(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData((void*)((char*)this + 8), 4);
    unsigned char hasLocation = 0;
    buffer->ReadTypedData((bool*)&hasLocation, 1);
    if (hasLocation)
    {
        m_pPackageTarget = new LocationDescriptor;
        m_pPackageTarget->FUN_0067fbe0(buffer);
    }
}
}  // namespace fnv_0067c330

struct FUN_0067f030 : LocationDescriptor
{
    int unk08;
    FUN_0067f030();
    ~FUN_0067f030();
    void FUN_0067f4d0(LocationDescriptor* pSource, int flags);
};

struct TESPackageData
{
    void* unk00;
    FUN_0067f030* m_pLoc;
    TESForm* m_form;
};

struct FUN_0067bd30_shell : FUN_0067ad70_cls
{
    TESForm* m_form;
    void LoadPackageData(BGSLoadFormBuffer* pBuffer);
};

extern const int DAT_0119bdec;
extern const int DAT_0119be60;
extern TESPackageData* __cdecl FUN_00ec43fb(BGSLoadFormBuffer* pBuffer, int arg2, const void* arg3, const void* arg4,
                                            int arg5);

// @fnv 0x0067bd30
void FUN_0067bd30_shell::LoadPackageData(BGSLoadFormBuffer* pBuffer)
{
    TESPackageData* pData = FUN_00ec43fb(pBuffer, 0, &DAT_0119bdec, &DAT_0119be60, 0);
    if (pData != 0)
    {
        if (m_pLoc != 0)
        {
            delete m_pLoc;
            m_pLoc = 0;
        }
        if (pData->m_pLoc != 0)
        {
            m_pLoc = new FUN_0067f030();
            ((FUN_0067f030*)m_pLoc)->FUN_0067f4d0(pData->m_pLoc, 0);
        }
        m_form = pData->m_form;
    }
}
