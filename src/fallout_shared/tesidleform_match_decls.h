// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESIDLEFORM_H
#define FNV_TESIDLEFORM_H

class TESConditionItem;
#include "layout_support.h"
#include "BaseFormComponent.h"
#include "PerkEntryConditionSet.h"
#include "TESForm.h"
#include "layout_support.h"
class BSFileEntry;
class IdleAnimationData;
class NiFormArray;
class TESIdleForm;
class TESObjectREFR;
class IdleReplayDelayEntry;
class TESModel;
class TESModelAnim;
class FileEntryList;
template <class T> class BSSimpleList;
class TESTopic;
class TESTopicInfo
{
  public:
    BSSimpleList<TESTopic*>* GetAddTopicList(void);
};
#pragma pack(push, 4)
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
    // void __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*()
    // bool __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*(CHUNK_ID, const char*)
    // void __cdecl FileEntryList::*(TESFile*, TESForm*, const char*)
    // void __cdecl FileEntryList::*(FileEntryList*)
    // unsigned char __cdecl FileEntryList::*()
    // BSFileEntry** __cdecl FileEntryList::*()
    // void* __cdecl FileEntryList::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
#pragma pack(push, 4)
class TESModel : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    virtual void InitializeComponent(void);
    virtual const char* GetModelFilePath(void);
    static void LoadModelData(TESModel*, TESFile*);
    // TESModel
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*(CHUNK_ID, CHUNK_ID)
    // void __cdecl TESModel::*(BaseFormComponent*)
    // bool __cdecl TESModel::*(BaseFormComponent*)
    // void __cdecl TESModel::*(CHUNK_ID)
    // GetModelLength
    // GetModelFilePath
    // bool __cdecl TESModel::*(CHUNK_ID)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // bool __cdecl TESModel::*()
    // char __cdecl TESModel::*()
    // void __cdecl TESModel::*(char)
    // bool __cdecl TESModel::*()
    // void __cdecl TESModel::*(bool)
    // unsigned int __cdecl TESModel::*()
    // void __cdecl TESModel::*(unsigned int)
    // bool __cdecl TESModel::*()
    // FileEntryList* __cdecl TESModel::*()
    // TESModel& __cdecl TESModel::*(const TESModel&)
    // void __cdecl TESModel::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
#pragma pack(push, 4)
class TESModelAnim : public TESModel
{
  public:
    // base TESModel at +0x0, size 24
    // TESModelAnim
    // void __cdecl TESModelAnim::*()
    // TESModelAnim& __cdecl TESModelAnim::*(const TESModelAnim&)
    // void __cdecl TESModelAnim::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModelAnim) == 24);
#pragma pack(push, 4)
class IdleAnimationData
{
  public:
    unsigned char m_ucAnimationGroupSection;  // +0x0, 1 bytes
    unsigned char m_ucLoopingMin;             // +0x1, 1 bytes
    unsigned char m_ucLoopingMax;             // +0x2, 1 bytes
    unsigned char layoutPadding3[1];
    unsigned short m_usReplayDelay;  // +0x4, 2 bytes
    unsigned char m_ucIdleFlags;     // +0x6, 1 bytes
    unsigned char layoutPadding7[1];
    void SwapEndian();
    // void __cdecl IdleAnimationData::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(IdleAnimationData) == 8);
FNV_STATIC_ASSERT(offsetof(IdleAnimationData, m_ucAnimationGroupSection) == 0);
FNV_STATIC_ASSERT(offsetof(IdleAnimationData, m_ucLoopingMin) == 1);
FNV_STATIC_ASSERT(offsetof(IdleAnimationData, m_ucLoopingMax) == 2);
FNV_STATIC_ASSERT(offsetof(IdleAnimationData, m_usReplayDelay) == 4);
FNV_STATIC_ASSERT(offsetof(IdleAnimationData, m_ucIdleFlags) == 6);
#pragma pack(push, 4)
class TESIdleForm : public TESForm, public TESModelAnim
{
  public:
    // base TESForm at +0x0, size 24
    // base TESModelAnim at +0x18, size 24
    PerkEntryConditionSet Conditions;         // +0x30, 8 bytes
    IdleAnimationData data;          // +0x38, 8 bytes
    NiFormArray* m_pParentPath;      // +0x40, 4 bytes
    TESIdleForm* m_pParentIdleForm;  // +0x44, 4 bytes
    TESIdleForm* m_pIdleForm;        // +0x48, 4 bytes
    void ResetFormData(void);
    void ClearData(void);
    void UnregisterIdleForm();
    bool IsFlag40Set();
    NiFormArray* AssignParentPath();
    bool FUN_005ff1d0();
    unsigned int GetChildCount();
    TESIdleForm* GetChildByIndex(unsigned int);
    bool Load(TESFile* file);
    void InitItem(void);
    bool HasMissingPathArray(void);
    void BuildIdleParentPath(NiFormArray* array);
    bool IsIdleFile(void);
    TESIdleForm* FindIdleFormForObject(TESObjectREFR* actionRef, TESObjectREFR* targetRef,
                                       BSSimpleList<IdleReplayDelayEntry*>* replayDelays);
    bool IsValidForReferences(TESObjectREFR* actionRef, TESObjectREFR* targetRef, bool recurseUp);
    // TESIdleForm
    // void __cdecl TESIdleForm::*()
    // void __cdecl TESIdleForm::*()
    // void __cdecl TESIdleForm::*()
    // void __cdecl TESIdleForm::*(TESForm*)
    // bool __cdecl TESIdleForm::*(TESForm*)
    // TESForm* __cdecl TESIdleForm::*(bool, NiTPointerMap<TESForm *,TESForm *>*)
    // bool __cdecl TESIdleForm::*(TESFile*)
    // void __cdecl TESIdleForm::*()
    // void __cdecl TESIdleForm::*()
    // bool __cdecl TESIdleForm::*()
    // void __cdecl TESIdleForm::*(NiFormArray*)
    // bool __cdecl TESIdleForm::*(NiFormArray*)
    // TESIdleForm* __cdecl TESIdleForm::*()
    // void __cdecl TESIdleForm::*(TESIdleForm*)
    // TESIdleForm* __cdecl TESIdleForm::*()
    // void __cdecl TESIdleForm::*(TESIdleForm*)
    // NiFormArray* __cdecl TESIdleForm::*()
    // NiFormArray* __cdecl TESIdleForm::*()
    // ANIM_GROUP_SECTION __cdecl TESIdleForm::*()
    // void __cdecl TESIdleForm::*(ANIM_GROUP_SECTION)
    // bool __cdecl TESIdleForm::*()
    // void __cdecl TESIdleForm::*(bool)
    // bool __cdecl TESIdleForm::*()
    // void __cdecl TESIdleForm::*(bool)
    // bool __cdecl TESIdleForm::*()
    // void __cdecl TESIdleForm::*(bool)
    // unsigned char __cdecl TESIdleForm::*()
    // unsigned char __cdecl TESIdleForm::*()
    // unsigned char __cdecl TESIdleForm::*()
    // unsigned short __cdecl TESIdleForm::*()
    // void __cdecl TESIdleForm::*(unsigned char)
    // void __cdecl TESIdleForm::*(unsigned char)
    // void __cdecl TESIdleForm::*(unsigned short)
    // bool __cdecl TESIdleForm::*()
    // TESIdleForm* __cdecl TESIdleForm::*(TESObjectREFR*, TESObjectREFR*, BSSimpleList<IdleReplayDelayEntry *>*)
    // bool __cdecl TESIdleForm::*(TESObjectREFR*, TESObjectREFR*, bool)
    // unsigned int __cdecl TESIdleForm::*()
    // TESIdleForm* __cdecl TESIdleForm::*(unsigned int)
    // unsigned int __cdecl TESIdleForm::*(TESIdleForm*)
    // void __cdecl TESIdleForm::*(unsigned int, TESIdleForm*)
    // void __cdecl TESIdleForm::*(TESIdleForm*, TESIdleForm*)
    // void __cdecl TESIdleForm::*(unsigned int)
    // void __cdecl TESIdleForm::*(TESIdleForm*)
    // bool __cdecl TESIdleForm::*(TESIdleForm*)
    // void __cdecl TESIdleForm::*()
    // NiFormArray* __cdecl TESIdleForm::*()
    // TESIdleForm& __cdecl TESIdleForm::*(const TESIdleForm&)
    // void __cdecl TESIdleForm::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESIdleForm) == 76);
FNV_STATIC_ASSERT(offsetof(TESIdleForm, Conditions) == 48);
FNV_STATIC_ASSERT(offsetof(TESIdleForm, data) == 56);
FNV_STATIC_ASSERT(offsetof(TESIdleForm, m_pParentPath) == 64);
FNV_STATIC_ASSERT(offsetof(TESIdleForm, m_pParentIdleForm) == 68);
FNV_STATIC_ASSERT(offsetof(TESIdleForm, m_pIdleForm) == 72);
class BGSPerkEntry;
class BGSCameraShot;
class TESObjectANIO : public TESIdleForm
{
};
class NiFormArray
{
  public:
    unsigned int GetSize();
    TESForm*& FUN_00877a30(unsigned int);
    unsigned int GetIndexOfForm(TESForm*);
    void SetSize(unsigned int, unsigned int*);
    void Compact();
    void SetFormAtIndex(unsigned int, TESForm*);
};
class BGSTextureSet;
class BGSImpactData
{
  public:
    BGSTextureSet* GetDecalTextureSet() const;
    void ReadTypedData(TESFile*, void*, unsigned short);
};
int __cdecl Warning(const char*, ...);
class TESFileFormInt
{
  public:
    int GetTESForm();
};
class FUN_005a71d0
{
  public:
    unsigned int parent;
    unsigned int previous;
    void FUN_00462230();
};
extern "C" void* __cdecl memset(void*, int, unsigned int);
extern "C" void* __cdecl _alloca(unsigned int);
class TESDataHandler
{
  public:
    bool FUN_004516b0();
    bool FUN_004226e0();
};
class IdleAnimationManager
{
  public:
    void AddIdleToArray(TESIdleForm*);
    bool FUN_00843150();
    NiFormArray* GetIdleArray(TESForm*);
    NiFormArray* GetFormArray(TESIdleForm*);
};
extern TESDataHandler* g_dataHandler;
extern IdleAnimationManager* DAT_011cb6a0;
#endif
