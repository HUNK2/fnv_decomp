// fallout_shared/packagedatauseweapon_decls.h: declares TESObjectWEAP, TESObjectREFR, ExtraDataList, LocationDescriptor, PackageTargetRecord and more
#ifndef FNV_PACKAGEDATAUSEWEAPON_DECLS_H
#define FNV_PACKAGEDATAUSEWEAPON_DECLS_H


#include "TESForm.h"

class BSFileEntry;
class TESBoundObject;
class ExtraDataList;
class TESObjectWEAP : public TESForm
{
};

// API declarations only: these objects are neither allocated nor inspected here.
class TESObjectREFR
{
  public:
    int GetBoundingRadius();
    TESBoundObject* GetObjectReference();
    ExtraDataList* GetExtraData();
};

class ExtraDataList
{
  public:
    TESObjectREFR* GetTargetObjectReference();
};

class LocationDescriptor
{
  public:
    BSFileEntry* SetLocRef();
    TESObjectREFR* GetLocationReference();
};

enum PACK_TARG_TYPE
{
    PACK_TARG_REFERENCE = 0
};

class PackageTargetRecord
{
  public:
    unsigned char m_uiTargetType;
    unsigned char layoutPadding1[3];
    union
    {
        TESObjectREFR* m_pWorldReferenceInfo;
        TESForm* pObject;
        TESForm* pTargetForm;
    };
    int iValue;
    float m_fTargetValue;

    PackageTargetRecord();
    void SetTargetKind(PACK_TARG_TYPE type);
    void SetTargetObjectReference(TESObjectREFR* reference);
    void InitItem(TESForm* item);
};

class TESPackageData
{
  public:
    void** m_ppVirtualMethodTable;
};

class TESUseWeaponPackageData : public TESPackageData
{
  public:
    PackageTargetRecord* m_pUseTarget;
    LocationDescriptor* m_pTargetLocation;
    bool m_bFlag1;
    bool m_bFlag2;
    bool m_bFlag3;
    bool m_bFlag4;
    bool m_bFlag5;
    bool m_bFlag6;
    unsigned short m_usValue1;
    unsigned short m_usValue2;
    unsigned short m_usValue3;
    float m_fValue1;
    float m_fValue2;
    TESObjectWEAP* pWeapon;

    void InitItem(TESForm* item);
};

class ActorPackageData
{
  public:
    void** m_ppVirtualMethodTable;
};

class UseWeaponActorPackageData : public ActorPackageData
{
  public:
    TESObjectREFR* m_pUseTarget;
    void SetReferenceTarget(TESObjectREFR* reference);
};

extern TESBoundObject* DAT_011ca244;
extern TESBoundObject* DAT_011ca248;

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* pointer);

FNV_STATIC_ASSERT(sizeof(PackageTargetRecord) == 0x10);
FNV_STATIC_ASSERT(sizeof(TESUseWeaponPackageData) == 0x24);
FNV_STATIC_ASSERT(offsetof(TESUseWeaponPackageData, m_pUseTarget) == 4);
FNV_STATIC_ASSERT(offsetof(TESUseWeaponPackageData, pWeapon) == 0x20);
FNV_STATIC_ASSERT(sizeof(UseWeaponActorPackageData) == 8);
FNV_STATIC_ASSERT(offsetof(UseWeaponActorPackageData, m_pUseTarget) == 4);

#endif
