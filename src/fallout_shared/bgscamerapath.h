// Unit-local header for fallout_shared/bgscamerapath.cpp.
#ifndef FNV_BGSCAMERAPATH_UNIT_H
#define FNV_BGSCAMERAPATH_UNIT_H

#include "layout_support.h"
class TESConditionItem;
#include "PerkEntryConditionSet.h"
#include "TESForm.h"
class BGSCameraPath;
class BGSCameraShot;
class NiFormArray
{
  public:
    unsigned int GetIndexOfForm(TESForm*);
    unsigned int GetSize();
    TESForm*& FUN_00877a30(unsigned int index);
    void SetSize(unsigned int size, unsigned int* oldSize);
    void Compact();
    void SetFormAtIndex(unsigned int index, TESForm* form);
};
class CameraShotData;
#pragma pack(push, 4)
class CameraShotData
{
  public:
    unsigned char cFlags;  // +0x0, 1 bytes
    // void __cdecl CameraShotData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CameraShotData) == 1);
FNV_STATIC_ASSERT(offsetof(CameraShotData, cFlags) == 0);
class TESConditionInit
{
  public:
    void InitItem(TESForm* form);
};
#pragma pack(push, 4)
class BGSCameraPath : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    PerkEntryConditionSet Conditions;                         // +0x18, 8 bytes
    BSSimpleList<BGSCameraShot*> m_kCameraShotList;  // +0x20, 8 bytes
    CameraShotData data;                             // +0x28, 1 bytes
    unsigned char layoutPadding29[3];
    NiFormArray* m_pPathArray;           // +0x2C, 4 bytes
    BGSCameraPath* m_pFirstCameraPath;   // +0x30, 4 bytes
    BGSCameraPath* m_pSecondCameraPath;  // +0x34, 4 bytes
    BGSCameraPath();
    bool Load(TESFile*);
    bool HasMissingPathArray();
    NiFormArray* GetEntryObject();
    void ResetFormData();
    void ClearData();
    void AssignParentPath(BGSCameraPath* parent);
    virtual void InitItem();
    BGSCameraPath* GetPrevPath();
    void SetPathArray(NiFormArray* paths);
    int HasNameForWarning();
    BSSimpleList<BGSCameraShot*>* GetShotList();
    PerkEntryConditionSet* GetConditions();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSCameraPath) == 56);
FNV_STATIC_ASSERT(offsetof(BGSCameraPath, Conditions) == 24);
FNV_STATIC_ASSERT(offsetof(BGSCameraPath, m_kCameraShotList) == 32);
FNV_STATIC_ASSERT(offsetof(BGSCameraPath, data) == 40);
FNV_STATIC_ASSERT(offsetof(BGSCameraPath, m_pPathArray) == 44);
FNV_STATIC_ASSERT(offsetof(BGSCameraPath, m_pFirstCameraPath) == 48);
FNV_STATIC_ASSERT(offsetof(BGSCameraPath, m_pSecondCameraPath) == 52);
class CameraPathManager
{
  public:
    NiFormArray* GetPathArray();
    void AddCameraPath(BGSCameraPath*);
};
extern CameraPathManager* DAT_011ca700;
BGSCameraPath* __cdecl GetTextureResourcePath();
class BGSImpactData
{
  public:
    void ReadTypedData(TESFile*, void*, unsigned short);
};
class FUN_005a71d0
{
  public:
    unsigned int parent, previous;
    void FUN_00462230();
};
class ScriptVariableInfo;
class TESTopicInfo;
template <class T> class NiTMallocInterface;
template <class T, class A> class NiTLargeArray;
template <> class NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >
{
  public:
    TESTopicInfo* RemoveAt(unsigned int);
};
template <> class BSSimpleList<ScriptVariableInfo*>
{
  public:
    void AddTail(ScriptVariableInfo* const&);
};
class CameraFileFormType
{
  public:
    ENUM_FORM_ID GetTESForm();
};
class TESSound;
class BGSAcousticSpace
{
  public:
    void SetDawnSound(TESSound*);
};
class CameraCondition
{
  public:
    void Load(TESFile*);
};
#endif
