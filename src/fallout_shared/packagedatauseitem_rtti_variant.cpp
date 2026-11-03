
// src/fallout_shared/packagedatauseitem_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESPackageData, TESUseItemPackageData). The skeleton of src/fallout_shared/packagedatauseitem.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

// src/fallout_shared/packagedatauseitem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedatauseitem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl FUN_004856d0(int);
struct LocationDescriptor
{
    void Save(int);
};
struct TESPackageData
{
    virtual ~TESPackageData();  // the original class is polymorphic (rtti_variants.py)
    void Save(int);
};
struct TESUseItemPackageData
{
    virtual ~TESUseItemPackageData();  // the original class is polymorphic (rtti_variants.py)
    TESPackageData base;
    LocationDescriptor* m_pPackageTarget;
    void TESUseItemPackageData_Save();
};
struct FUN_0067c7a0_shell : TESUseItemPackageData
{
    void FUN_0067c7d0();
    void* FUN_0067c7a0(unsigned int flags);
};
struct FUN_0067ad70
{
    virtual ~FUN_0067ad70();
};
struct LocationShell
{
    ~LocationShell();
};
struct FUN_0067c7d0 : FUN_0067ad70
{
    LocationShell* m_pPackageTarget;
    virtual ~FUN_0067c7d0();
};
