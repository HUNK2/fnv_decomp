// fallout_shared/extradatalist_packet_rtti_extradatalist.h: declares BaseExtraList, ExtraDataList, TaskQueueInterface, TESPackage
#ifndef FNV_EXTRADATALIST_PACKET_H
#define FNV_EXTRADATALIST_PACKET_H

// Canonical layouts come from include/ (src/fallout_shared has same-named local headers, so the shadowed ones are
// included by path). This unit owns BaseExtraList and ExtraDataList, whose generated headers do not declare every
// member defined here yet, so both are declared as layout-identical supersets of include/BaseExtraList.h and
// include/ExtraDataList.h (their guards are pre-defined).
#include "../../include/layout_support.h"
#define FNV_BASEEXTRALIST_H
#define FNV_EXTRADATALIST_H
class ExtraDismemberedLimbs;
class SeenData;
class LockExtraData;
class TESImageSpaceModifier;
#pragma pack(push, 4)
class BaseExtraList
{
  public:
    void** m_ppVirtualMethodTable;
    BSExtraData* pHead;
    unsigned char iFlags[21];
    unsigned char layoutPadding1D[3];
    BSExtraData* GetExtraData(unsigned char);
    BSExtraData* AddExtra(BSExtraData*);
    bool HasExtraData(unsigned char);
    void RemoveExtra(unsigned char);
    void FUN_0040f740();
};
class ExtraDataList : public BaseExtraList
{
  public:
    ExtraDataList();
    InventoryChanges* GetContainerChangeData();
    void SetContainerChanges(InventoryChanges*);
    bool HasExtraDataType0x2F();
    void RemoveExtraDataType0x15();
    SeenData* FUN_00421910();
    LockExtraData* GetLock();
    TESForm* GetOwnerForm();
    bool IsEmpty();
    ExtraDismemberedLimbs* GetDismemberedLimbs();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BaseExtraList) == 0x20);
FNV_STATIC_ASSERT(sizeof(ExtraDataList) == 0x20);
#include "../../include/TESObjectREFR.h"
#include "Actor.h"
#include "BaseProcess.h"
#include "RecursiveSpinLock.h"
#include "NiMemObject.h"
// No canonical headers yet for these.
class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
};
extern TaskQueueInterface* DAT_011df1a8;
class TESPackage
{
  public:
    virtual ~TESPackage();  // the original class is polymorphic (rtti_variants.py)
  public:
    char prefix[104];
    BSSimpleList<BGSPerkEntry*> list;
    Script* GetNextScript();
};
// include/layout_support.h declares TESObjectCELL, TESDataHandler and TESObjectREFR without these members.
struct FUN_004610d0_shell : public TESDataHandler
{
    BSSimpleList<TESImageSpaceModifier*>* GetTESImageSpaceModifierList();
};
struct FUN_00555bc0_shell : public TESObjectCELL
{
    SeenData* FindSeenData();
};
struct FUN_00569140_shell : public TESObjectREFR
{
    LockExtraData* GetMyLock();
};
struct FUN_00569580_shell : public TESObjectREFR
{
    TESForm* GetOwnerForm();
};
extern void* kVtbl_ExtraDataList[];
#endif
