
// src/fallout_shared/doorlock_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESActorBase). The skeleton of src/fallout_shared/doorlock.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "layout_support.h"
#include "doorlock_decls.h"
class TESObjectCELL;
class LockExtraData;
class TESGlobal;
class TESClass;
class TESActorBase;
class InventoryChanges;
#pragma pack(push, 4)
class DoorAccessData
{
  public:
    TESObjectCELL* m_pSourceCell;       // +0x0, 4 bytes
    TESObjectCELL* m_pDestinationCell;  // +0x4, 4 bytes
    LockExtraData* m_pTeleportData;         // +0x8, 4 bytes
    TESForm* m_pKeyForm;                // +0xC, 4 bytes
    int m_iLockLevel;                   // +0x10, 4 bytes
    TESGlobal* m_pLockLevelGlobal;      // +0x14, 4 bytes
    DoorAccessData(TESObjectREFR* pRef);
    ~DoorAccessData();
    void SetDoorReference(TESObjectREFR* pRef);
    bool ReadState98();
    bool CanActorUseDoor(const PathingActorData* pActorData, bool bFlag);
    bool CanActorOpenDoor(const PathingActorData* pActorData, bool bFlag);
    bool CanUnlockDoor(const PathingActorData* pActorData, TESObjectREFR* pRef, bool& bNeedsKey);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DoorAccessData) == 24);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pSourceCell) == 0);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pDestinationCell) == 4);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pTeleportData) == 8);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pKeyForm) == 12);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_iLockLevel) == 16);
FNV_STATIC_ASSERT(offsetof(DoorAccessData, m_pLockLevelGlobal) == 20);
// Minimal callee declarations (codegen only; layouts remain with owning units).
class TESForm
{
  public:
    virtual ~TESForm();  // the original class is polymorphic (rtti_variants.py)
  public:
    ENUM_FORM_ID GetFormType() const;
};
class TESFaction : public TESForm
{
};
class TESGlobalValueReader
{
  public:
    float GetValue();
};
class TESGlobal : public TESGlobalValueReader
{
};
class TESActorBaseData
{
  public:
    int GetFactionRank(TESFaction* pFaction, bool m_bFaceGenDataValid);
};
class TESActorBase : public TESForm
{
  public:
    TESClass* GetClass();
};
class TESClass
{
  public:
    bool IsGuard();
};
class DoorCell
{
  public:
    bool IsOwnedByActor(TESActorBase* m_pActorBaseFormItem);
    TESForm* GetOwner();
};
struct FactionOwnership
{
    TESFaction* pFaction;
    int m_iRank;
};
struct IgnoreLocals
{
    TESActorBase* m_pActorBaseFormItem;
    TESClass* pClass;
};
struct KeySearch
{
    int iCount;
};
class TESKey;
#pragma pack(push, 4)
class LockExtraData
{
  public:
    unsigned char m_uiLockState;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    TESKey* pKey;  // +0x4, 4 bytes
    char cFlags;   // +0x8, 1 bytes
    unsigned char layoutPadding9[3];
    unsigned int m_uiLockDifficulty;  // +0xC, 4 bytes
    unsigned int m_uiLockValue;       // +0x10, 4 bytes
    int GetLockLevel(TESObjectREFR* pRef);
    bool IsLocked();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(LockExtraData) == 20);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockState) == 0);
FNV_STATIC_ASSERT(offsetof(LockExtraData, pKey) == 4);
FNV_STATIC_ASSERT(offsetof(LockExtraData, cFlags) == 8);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockDifficulty) == 12);
FNV_STATIC_ASSERT(offsetof(LockExtraData, m_uiLockValue) == 16);
class FUN_00411b00 : public LockExtraData
{
  public:
    FUN_00411b00();
};
struct DoorLockCtorLocals
{
    ExtraRadioData* pRadioData;
    LockExtraData* pSourceLock;
};
class TESBoundObject : public TESForm
{
};
class TESKey : public TESBoundObject
{
};
class InventoryChanges
{
  public:
    bool FindItemInInventory(TESBoundObject* pItem, int iArg1, int iArg2, int& iOut, unsigned int uiArg,
                             TESObjectREFR* pRef);
};
extern TESBoundObject* g_pLockpickItem;

class Actor
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual TESForm* vf1a4();
    TESForm* FUN_007af430();
};
extern Actor* g_thePlayer;
class DoorLock5021c0 : public DoorAccessData
{
  public:
    bool FUN_005021c0(Actor* ref, bool b);
};
// @fnv 0x005021c0
bool DoorLock5021c0::FUN_005021c0(Actor* ref, bool b)
{
    bool r7 = false;
    if (m_pKeyForm && ref)
    {
        r7 = true;
        TESForm* obj5 = ref->vf1a4();
        if (!obj5)
            obj5 = ref->FUN_007af430();
        TESActorBase* base = 0;
        switch (obj5->GetFormType())
        {
        case 0x2a:
        case 0x2b:
            base = dynamic_cast<TESActorBase*>((TESBoundObject*)obj5);
            break;
        }
        if (m_pKeyForm != obj5)
        {
            TESFaction* fac = 0;
            if (m_pKeyForm && m_pKeyForm->GetFormType() == 8)
                fac = (TESFaction*)m_pKeyForm;
            int rank5 = 0;
            if (!fac || !b)
            {
                if (!m_pLockLevelGlobal || m_pLockLevelGlobal->GetValue() == 0.0)
                    r7 = false;
            }
            if (fac && base)
            {
                rank5 = ((TESActorBaseData*)((char*)base + 0x30))->GetFactionRank(fac, ref == g_thePlayer);
                if (rank5 < m_iLockLevel)
                    r7 = false;
            }
        }
    }
    return r7;
}
