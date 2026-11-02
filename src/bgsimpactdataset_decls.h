// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSIMPACTDATASET_H
#define FNV_BGSIMPACTDATASET_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "bgsimpactdataset_TESForm.h"
class ImpactSwap;
class BGSImpactData;
class BGSImpactDataSet;
class BGSPreloadable;
class QueuedFile;
class BGSPreloadable : public BaseFormComponent
{
  public:
    BGSPreloadable();
    virtual void QueueResourceLoad(int priority, QueuedFile* file);
    // base BaseFormComponent at +0x0, size 4
    // void __cdecl BGSPreloadable::*()
    // void __cdecl BGSPreloadable::*()
    // void __cdecl BGSPreloadable::*(BaseFormComponent*)
    // bool __cdecl BGSPreloadable::*(BaseFormComponent*)
    // BGSPreloadable
    // BGSPreloadable& __cdecl BGSPreloadable::*(const BGSPreloadable&)
};
FNV_STATIC_ASSERT(sizeof(BGSPreloadable) == 4);
class BGSImpactDataSet : public TESForm, public BGSPreloadable
{
  public:
    BGSImpactDataSet();
    virtual ~BGSImpactDataSet();
    void ResetFormData();
    bool Load(TESFile* file);
    virtual void InitItem();
    static void CacheImpactDataSet();
    static void RefreshImpactData(ImpactSwap* swap);
    virtual void QueueResourceLoad(int priority, QueuedFile* file);
    BGSImpactData* GetImpactDataForMaterial(int material);
    static BGSImpactDataSet* ms_pImpactDataSet;
    // base TESForm at +0x0, size 24
    // base BGSPreloadable at +0x18, size 4
    BGSImpactData* m_apImpactData[12];  // +0x1C, 48 bytes
    // BGSImpactDataSet
    // void __cdecl BGSImpactDataSet::*()
    // BGSImpactDataSet::IMPACT_MATERIAL_TYPE __cdecl BGSImpactDataSet::*(MATERIAL_TYPE)
    // void __cdecl BGSImpactDataSet::*()
    // BGSImpactDataSet* __cdecl BGSImpactDataSet::*()
    // void __cdecl BGSImpactDataSet::*()
    // void __cdecl BGSImpactDataSet::*()
    // void __cdecl BGSImpactDataSet::*(TESForm*)
    // bool __cdecl BGSImpactDataSet::*(TESForm*)
    // bool __cdecl BGSImpactDataSet::*(TESFile*)
    // void __cdecl BGSImpactDataSet::*()
    // void __cdecl BGSImpactDataSet::*()
    // GetImpactDataForMaterial
    // void __cdecl BGSImpactDataSet::*(BGSImpactDataSet::IMPACT_MATERIAL_TYPE, BGSImpactData*)
    // void __cdecl BGSImpactDataSet::*()
    // void __cdecl BGSImpactDataSet::*(ImpactSwap*)
    // void __cdecl BGSImpactDataSet::*(IO_TASK_PRIORITY, QueuedFile*)
    // BGSImpactDataSet& __cdecl BGSImpactDataSet::*(const BGSImpactDataSet&)
    // void __cdecl BGSImpactDataSet::*()
};
FNV_STATIC_ASSERT(sizeof(BGSImpactDataSet) == 76);
FNV_STATIC_ASSERT(offsetof(BGSImpactDataSet, m_apImpactData) == 28);
#endif
class ImpactSwap
{
  public:
    const char* GetAltFootstepMaterialName(int);
    BGSImpactData* GetSwappedImpactData(int, BGSImpactData*);
};
extern ImpactSwap* DAT_011ca834;
void __cdecl SetGlobalPointerAtOffset(int, const char*);
void __cdecl FUN_00837500();
