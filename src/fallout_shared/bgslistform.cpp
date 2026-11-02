// fallout_shared/bgslistform.cpp: BGSListForm, ThisHolder (12 functions)

#include "bgslistform_decls.h"

// @fnv 0x0058FB00
void BGSListForm::ClearData()
{
    reinterpret_cast<BSSimpleList<ActorCause*>*>(reinterpret_cast<BGSCameraPath*>(this)->GetConditions())->RemoveAll();
    m_uiFormCount = 0;
}

// @fnv 0x005901C0
void BGSListForm::Revert(BGSLoadFormBuffer* buffer)
{
    TESForm::Revert(buffer);
    if (buffer->GetOldChangeFlags(0x80000000))
        ClearFormList();
}

// @fnv 0x00590010
void BGSListForm::IncludeForm(TESForm* form)
{
    if (form != 0)
    {
        if (!reinterpret_cast<BSSimpleList<BGSQuestObjective*>*>(
                 reinterpret_cast<BGSCameraPath*>(this)->GetConditions())
                 ->IsInList(reinterpret_cast<BGSQuestObjective*&>(form)))
        {
            reinterpret_cast<BSSimpleList<EffectSetting*>*>(reinterpret_cast<BGSCameraPath*>(this)->GetConditions())
                ->AddHead(reinterpret_cast<EffectSetting*&>(form));
            ++m_uiFormCount;
            MarkAsModified(0x80000000);
        }
    }
}

// @fnv 0x00591B70
BGSListForm::BGSListForm()
{
    reinterpret_cast<BSSimpleList<TESForm*>*>(reinterpret_cast<unsigned char*>(this) + 0x18)->FUN_004019f0();
    SetFormType((ENUM_FORM_ID)0x5A);
    reinterpret_cast<BGSRadiationStage*>(this)->ResetFormData();
}

// @fnv 0x00590120
void BGSListForm::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    if (buffer->GetChangeFlags(0x80000000))
    {
        if (m_uiFormCount != 0)
            ClearFormList();

        unsigned int formCount = 0;
        buffer->ReadTypedData(&formCount, 4);
        for (unsigned int index = 0; index < formCount; ++index)
        {
            TESForm* form = TESForm::GetFormByID(buffer->ReadFormIdentifier());
            IncludeForm(form);
        }
    }
}

// @fnv 0x0058FD40
bool BGSListForm::Load(TESFile* file)
{
    LoadRecordHeader(file);
    SetInitializationState(false);

    unsigned int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4d414e4c: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            {
                reinterpret_cast<BSSimpleList<MediaSet*>*>(reinterpret_cast<BGSCameraPath*>(this)->GetConditions())
                    ->AddTail((MediaSet*)formID);
            }
            break;
        }
        default:
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0058FE50
void BGSListForm::InitItem()
{
    if (GetInitialized())
        return;
    BSSimpleList<BGSCameraShot*>* current =
        reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(reinterpret_cast<BGSCameraPath*>(this)->GetConditions());
    BSSimpleList<BGSCameraShot*>* previous = 0;
    TESForm* form;
    while (current != 0 && !current->IsEmpty())
    {
        unsigned int formID = (unsigned int)reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(current)->GetItem();
        RemapFormIDForFile(formID, GetFile(-1));
        form = GetFormByID(formID);
        if (form != 0)
        {
            current->SetItem(reinterpret_cast<BGSCameraShot* const&>(form));
            previous = current;
            current = reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(
                reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(current)->GetNext());
        }
        else
        {
            Warning("MASTERFILE: Unable to find form (%08X) on list form %s (%08X).", formID, GetName(), GetFormID());
            if (previous != 0)
            {
                previous->Remove((BGSCameraShot*)formID);
                current = reinterpret_cast<BSSimpleList<BGSCameraShot*>*>(
                    reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(previous)->GetNext());
            }
            else
            {
                current->RemoveHead();
            }
        }
    }
    SetInitializationState(true);
}

void _Deallocate(void*);
struct FUN_0058fa60_shell
{
    void FUN_0058fa90();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_0058fa90, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0058fa60
void* FUN_0058fa60_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_0058fa90();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct CallTarget_0063f7b0
{
    void _ref_0063f7b0();
};
struct ThisHolder
{
    void FUN_0058ffd0();
};
// @fnv 0x0058ffd0
void ThisHolder::FUN_0058ffd0()
{
    while (*(unsigned int*)((char*)this + 0x20) != 0)
    {
        ((CallTarget_0063f7b0*)((BGSCameraPath*)this)->GetConditions())->_ref_0063f7b0();
        *(unsigned int*)((char*)this + 0x20) = *(unsigned int*)((char*)this + 0x20) - 1;
    }
}

struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
void _FUN_00485910(unsigned int, unsigned int);
struct _ref_006815c0_shell
{
    TESForm** _ref_006815c0();
};
struct _ref_008256d0_shell
{
    bool _ref_008256d0();
};
struct _ref_00726070_shell
{
    PerkEntryConditionSet* _ref_00726070();
};
struct FUN_0058fcc0_shell
{
    void FUN_0058fcc0();
};
// @fnv 0x0058fcc0
void FUN_0058fcc0_shell::FUN_0058fcc0()
{
    ((FUN_004855a0*)this)->M();
    PerkEntryConditionSet* pCondition = ((BGSCameraPath*)this)->GetConditions();
    while (pCondition && !(((_ref_008256d0_shell*)pCondition)->_ref_008256d0()))
    {
        TESForm* pForm = *((_ref_006815c0_shell*)pCondition)->_ref_006815c0();
        unsigned int formID6 = pForm->GetFormID();
        _FUN_00485910(0x4d414e4c, formID6);
        pCondition = ((_ref_00726070_shell*)pCondition)->_ref_00726070();
    }
    ((FUN_00485680*)this)->M();
}

struct BSSimpleListTESRaceSize
{
    int GetSize();
};
struct _ref_008256d0_shell2
{
    bool FUN_008256d0();
};
struct _ref_006815c0_shell2
{
    TESForm** FUN_006815c0();
};
struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm*);
};
struct BSSimpleListGetNext
{
    BSSimpleList<TESForm*>* GetNext();
};
struct FUN_0058fbc0_shell : BGSCameraPath
{
    bool IsNotEqual(TESForm* apCompare);
};

// @fnv 0x0058fbc0
bool FUN_0058fbc0_shell::IsNotEqual(TESForm* apCompare)
{
    BGSListForm* pcompare = dynamic_cast<BGSListForm*>(apCompare);
    if (!pcompare)
        return true;
    if (((BSSimpleListTESRaceSize*)GetConditions())->GetSize() !=
        ((BSSimpleListTESRaceSize*)((BGSCameraPath*)pcompare)->GetConditions())->GetSize())
        return true;
    BSSimpleList<TESForm*>* pCurrentElementNext = (BSSimpleList<TESForm*>*)GetConditions();
    BSSimpleList<TESForm*>* pcomplist = (BSSimpleList<TESForm*>*)((BGSCameraPath*)pcompare)->GetConditions();
    while (pCurrentElementNext && !((_ref_008256d0_shell2*)pCurrentElementNext)->FUN_008256d0() && pcomplist &&
           !((_ref_008256d0_shell2*)pcomplist)->FUN_008256d0())
    {
        if (*((_ref_006815c0_shell2*)pCurrentElementNext)->FUN_006815c0() != *((_ref_006815c0_shell2*)pcomplist)->FUN_006815c0())
            return true;
        pCurrentElementNext = ((BSSimpleListGetNext*)pCurrentElementNext)->GetNext();
        pcomplist = ((BSSimpleListGetNext*)pcomplist)->GetNext();
    }
    if (((FUN_005e79a0_t*)this)->FUN_00485270(pcompare))
        return true;
    return false;
}

struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};
struct SoundListView
{
    void AddTail(char* const&);
};
struct FUN_0058fb30_shell : BGSCameraPath
{
    void CopyConditionsFromListForm(TESForm* apCopy);
};
// Casts apCopy to BGSListForm, appends each of its condition entries to this object's condition list, then calls FUN_004851b0 with the list form.
// @fnv 0x0058fb30
void FUN_0058fb30_shell::CopyConditionsFromListForm(TESForm* apCopy)
{
    BGSListForm* pListForm = dynamic_cast<BGSListForm*>(apCopy);
    if (!pListForm)
        return;
    BSSimpleList<TESForm*>* pCurrentElementNext =
        reinterpret_cast<BSSimpleList<TESForm*>*>(reinterpret_cast<BGSCameraPath*>(pListForm)->GetConditions());
    while (pCurrentElementNext && !reinterpret_cast<_ref_008256d0_shell2*>(pCurrentElementNext)->FUN_008256d0())
    {
        TESForm* pform = reinterpret_cast<_ref_006815c0_shell2*>(pCurrentElementNext)->FUN_006815c0()[0];
        reinterpret_cast<SoundListView*>(GetConditions())->AddTail(reinterpret_cast<char* const&>(pform));
        pCurrentElementNext = reinterpret_cast<BSSimpleList<TESForm*>*>(reinterpret_cast<BSSimpleListGetNext*>(pCurrentElementNext)->GetNext());
    }
    reinterpret_cast<FUN_005e78f0_t*>(this)->FUN_004851b0(reinterpret_cast<TESForm*>(pListForm));
}

struct FUN_0058ff60_shell : BGSCameraPath
{
    int GetConditionIndex(TESForm*);
};

// @fnv 0x0058ff60
int FUN_0058ff60_shell::GetConditionIndex(TESForm* apForm)
{
    int iElementIndex = 0;
    BSSimpleList<TESForm*>* pCurrentElementNext = reinterpret_cast<BSSimpleList<TESForm*>*>(GetConditions());
    while (pCurrentElementNext && !reinterpret_cast<_ref_008256d0_shell*>(pCurrentElementNext)->_ref_008256d0())
    {
        if (reinterpret_cast<_ref_006815c0_shell*>(pCurrentElementNext)->_ref_006815c0()[0] == apForm)
            break;
        iElementIndex++;
        pCurrentElementNext = reinterpret_cast<BSSimpleList<TESForm*>*>(reinterpret_cast<BSSimpleListGetNext*>(pCurrentElementNext)->GetNext());
    }
    if (!pCurrentElementNext)
        iElementIndex = -1;
    return iElementIndex;
}

struct BGSSaveFormBuffer
{
    void SaveData(void* buffer, int size, int flags);
};
struct SaveFormIDHelper
{
    void SerializeFormData(void* buffer, int formID);
};
struct FUN_00484d60_holder
{
    void SaveIfChanged(unsigned int formID);
};
struct FUN_00590080_shell : public BGSListForm
{
    void SaveFormList(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x00590080
void FUN_00590080_shell::SaveFormList(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<FUN_00484d60_holder*>(this)->SaveIfChanged(reinterpret_cast<unsigned int>(apSaveGameBuffer));
    if (reinterpret_cast<BGSLoadFormBuffer*>(apSaveGameBuffer)->GetChangeFlags(0x80000000))
    {
        BSSimpleList<TESForm*>* pCurrentElementNext =
            reinterpret_cast<BSSimpleList<TESForm*>*>(reinterpret_cast<unsigned char*>(this) + 0x18);
        apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x20), 4, 0);
        for (unsigned int i = 0; i < m_uiFormCount; ++i)
        {
            TESForm* pform = reinterpret_cast<_ref_006815c0_shell*>(pCurrentElementNext)->_ref_006815c0()[0];
            pCurrentElementNext = reinterpret_cast<BSSimpleListGetNext*>(pCurrentElementNext)->GetNext();
            reinterpret_cast<SaveFormIDHelper*>(apSaveGameBuffer)->SerializeFormData(pform, 0);
        }
    }
}

class FUN_0058f9d0_base
{
  public:
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_0058f9d0_base();
    virtual ~FUN_0058f9d0_base();
};

struct FUN_0058f9d0_member
{
    int unk00;
    int unk04;
    FUN_0058f9d0_member();
    ~FUN_0058f9d0_member();
};

class FUN_0058f9d0 : public FUN_0058f9d0_base
{
  public:
    FUN_0058f9d0_member m_18;
    int m_20;
    FUN_0058f9d0();
    virtual ~FUN_0058f9d0();
    void Unk_a();
    void Unk_b(int v);
};

// Initializes the object by calling Unk_a, calling Unk_b with 0x55, and setting m_20 to 0.
// @fnv 0x0058f9d0
FUN_0058f9d0::FUN_0058f9d0()
{
    Unk_a();
    Unk_b(0x55);
    m_20 = 0;
}

struct Base_58fa90
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    ~Base_58fa90();
};

struct Member_58fa90
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~Member_58fa90();
};

class FUN_0058fa90_cls : public Base_58fa90
{
  public:
    Member_58fa90 m_18;

    virtual ~FUN_0058fa90_cls();
    void Body();
};

// @fnv 0x0058fa90
FUN_0058fa90_cls::~FUN_0058fa90_cls()
{
    Body();
}

class Base_5effc0
{
  public:
    virtual void v00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    Base_5effc0();
    ~Base_5effc0();
};

class Member_5effc0
{
  public:
    int unk00;

    Member_5effc0();
    ~Member_5effc0();
};

class FUN_005effc0 : public Base_5effc0
{
  public:
    virtual void v00();
    unsigned char m_18;
    Member_5effc0 m_1c;

    FUN_005effc0();
    void Method_5effc0(int aValue);
};

// Initializes the object by calling Method_5effc0 with 0x5d and setting m_18 to 0.
// @fnv 0x005effc0
FUN_005effc0::FUN_005effc0()
{
    Method_5effc0(0x5d);
    m_18 = 0;
}
