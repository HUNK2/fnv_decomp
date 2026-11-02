// fallout_shared/packageeventaction.cpp: PackageEventActionData (7 functions)

#include "packageeventaction_decls.h"
#include <malloc.h>
#include <string.h>

// @fnv 0x00680890
PackageEventActionData::PackageEventActionData()
{}

// @fnv 0x0067e190
void PackageEventActionData::InitItem(TESForm* owner)
{
    unsigned int id = (unsigned int)m_item;
    TESForm::RemapFormIDForFile(id, owner->GetFile(-1));
    TESObjectANIO* idle = dynamic_cast<TESObjectANIO*>(GetFormByID(id));
    if (idle)
        m_item = idle;
    else if (id)
    {
        if (((BGSCameraPath*)owner)->HasNameForWarning())
            Warning("MASTERFILE: Unable to find Idle (%08X) on owner object \"%s\".", id, owner->GetName());
        else
            Warning("MASTERFILE: Unable to find Idle (%08X) on owner object (%08X).", id, owner->GetFormID());
        m_item = 0;
    }
    id = (unsigned int)pTopic;
    TESForm::RemapFormIDForFile(id, owner->GetFile(-1));
    TESTopic* topic = dynamic_cast<TESTopic*>(GetFormByID(id));
    if (topic)
        pTopic = topic;
    else if (id)
    {
        if (((BGSCameraPath*)owner)->HasNameForWarning())
            Warning("MASTERFILE: Unable to find Topic (%08X) on owner object \"%s\".", id, owner->GetName());
        else
            Warning("MASTERFILE: Unable to find Topic (%08X) on owner object (%08X).", id, owner->GetFormID());
        pTopic = 0;
    }
    if (m_pkNext)
    {
        int errors;
        int oldWarning = Warning();
        SetWarningState(true);
        BGSMessageWarningAuxiliary(0);
        ((Script*)m_pkNext)->NotifySaveLoadGameOfFormChange();
        ((Script*)m_pkNext)->InitItem(owner);
        ((ScriptHeaderData*)((BGSCameraPath*)m_pkNext)->GetConditions())->m_bQuest = false;
        SetWarningState(false);
        errors = Warning();
        BGSMessageWarningAuxiliary(oldWarning);
        if (errors)
            Warning("MASTERFILE: Errors were encountered during InitItem for result script on eventaction for package",
                    owner->GetName(), owner->GetFormID());
    }
}

// Loads a Script from a TESFile: reads variable, condition, data, reference and item/topic chunks, then discards the script if it has no data.
// @fnv 0x0067dd20
void PackageEventActionData::Load(TESFile* file)
{
    unsigned int id;
    m_item = 0;
    pTopic = 0;
    if (m_pkNext)
    {
        delete (Script*)m_pkNext;
        m_pkNext = 0;
    }
    m_pkNext = (BSSimpleList<TESForm*>*)new Script;
    for (;;)
    {
        bool done = false;
        switch ((int)file->GetChunkID())
        {
        case 0x44534c53:
        case 0x52564353:
            if (file->GetChunkID() == 0x44534c53)
            {
                DAT_011d66ac = new ScriptVariableInfo;
                DAT_011d66ac->Load(file);
                ((Script*)m_pkNext)->GetVariableList()->AddTail(DAT_011d66ac);
            }
            else if (DAT_011d66ac)
            {
                char* name = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(name, 512);
                DAT_011d66ac->m_kName.Set(name, 0);
            }
            break;
        case 0x52484353:
            file->GetChunkData(((BGSCameraPath*)m_pkNext)->GetConditions(), 0);
            if (file->IsEndianConversionRequired())
                ((ScriptHeaderData*)((BGSCameraPath*)m_pkNext)->GetConditions())->Endian();
            break;
        case 0x41444353: {
            unsigned int size = file->GetChunkSize();
            char* data = (char*)_alloca(size);
            memset(data, 0, size);
            file->GetChunkData(data, 0);
            ((Script*)m_pkNext)->SetScriptData(size, data);
            break;
        }
        case 0x4f524353: {
            unsigned int formID;
            ScriptReferencedObject* object = new ScriptReferencedObject;
            file->GetChunkData(&formID);
            object->pForm = (TESForm*)formID;
            ((Script*)m_pkNext)->GetReferencedObjectList()->AddTail(object);
            break;
        }
        case 0x56524353: {
            unsigned int formID;
            ScriptReferencedObject* object = new ScriptReferencedObject;
            file->GetChunkData(&formID);
            object->m_uiFormID = formID;
            ((Script*)m_pkNext)->GetReferencedObjectList()->AddTail(object);
            break;
        }
        break;
        case 0x4d414e49:
            file->GetChunkData(&id);
            m_item = (TESForm*)id;
            break;
        case 0x4d414e54:
            file->GetChunkData(&id);
            pTopic = (TESForm*)id;
            done = true;
            break;
        }
        if (done)
            break;
        file->NextChunk();
    }
    ((Script*)m_pkNext)->SetInitializationState(false);
    if (!((Script*)m_pkNext)->GetData())
    {
        delete (Script*)m_pkNext;
        m_pkNext = 0;
    }
}

struct FUN_0067da80_shell : public PackageEventActionData
{
    void FUN_0067da80();
};

struct DummyVtable
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~DummyVtable();
};

// @fnv 0x0067da80
void FUN_0067da80_shell::FUN_0067da80()
{
    *(int*)this = 0;
    *((int*)this + 2) = 0;
    delete *((DummyVtable**)this + 1);
}

extern "C" void FUN_004856d0(int);
extern "C" void FUN_00485910(int, int);
struct FUN_005abe00
{
    void ProcessHeader();
};
struct FUN_0067dc80
{
    TESForm* m_pIdleForm;
    FUN_005abe00* m_pScript;
    TESForm* pTopic;
    void Save(int aeChunk);
};
// @fnv 0x0067dc80
void FUN_0067dc80::Save(int aeChunk)
{
    FUN_004856d0(aeChunk);
    unsigned int iid = m_pIdleForm ? m_pIdleForm->GetFormID() : 0;
    FUN_00485910(0x4d414e49, iid);
    iid = pTopic ? pTopic->GetFormID() : 0;
    if (m_pScript)
        m_pScript->ProcessHeader();
    FUN_00485910(0x4d414e54, iid);
}

struct QuantityData
{
    void SetQuantity(unsigned int);
};

struct MagicCaster
{
    void SetSelectedMagicItem(int);
};

struct TESObjectREFR
{
    void SetFlags(unsigned int);
};

struct ArrSI
{
    unsigned int GetFlags();
};

struct GO
{
    operator unsigned int() const;
};

struct FUN_0067dad0_shell
{
    void* m_pIdleForm;
    Script* m_pScript;

    void FUN_0067dad0(PackageEventActionData* apCopy);
};

void* __cdecl operator new(unsigned int);

// Copies quantity, flags and form ID from apCopy, then clones or clears the script pointer depending on whether apCopy has one.
// @fnv 0x0067dad0
void FUN_0067dad0_shell::FUN_0067dad0(PackageEventActionData* apCopy)
{
    reinterpret_cast<QuantityData*>(this)->SetQuantity(reinterpret_cast<GO*>(apCopy)->operator unsigned int());

    reinterpret_cast<TESObjectREFR*>(this)->SetFlags(reinterpret_cast<ArrSI*>(apCopy)->GetFlags());

    reinterpret_cast<MagicCaster*>(this)->SetSelectedMagicItem(reinterpret_cast<TESForm*>(apCopy)->GetFormID());

    if (reinterpret_cast<FUN_0067dad0_shell*>(apCopy)->m_pScript)
    {
        if (!m_pScript)
        {
            m_pScript = new Script;
            m_pScript->NotifySaveLoadGameOfFormChange();
        }
        m_pScript->CopyScriptContents(reinterpret_cast<FUN_0067dad0_shell*>(apCopy)->m_pScript);
    }
    else
    {
        delete m_pScript;
        m_pScript = 0;
    }
}

struct TESObjectREFR_GetFlags_caller
{
    unsigned int CallGetFlags();
    operator const char*() const;
};

struct FUN_00726070_shell
{
    void* FUN_00726070();
};

struct FUN_005ab240_shell
{
    bool IsDifferentFrom(void*);
};

struct FUN_0067dbf0_shell
{
    int unk00;
    int unk04;
    int unk08;
    bool FUN_0067dbf0(TESObjectREFR_GetFlags_caller* apParam);
};

// @fnv 0x0067dbf0
bool FUN_0067dbf0_shell::FUN_0067dbf0(TESObjectREFR_GetFlags_caller* apParam)
{
    if (unk00 != (int)(void*)apParam->operator const char*())
        return true;
    if (unk08 != apParam->CallGetFlags())
        return true;
    if ((void*)unk04 || ((FUN_00726070_shell*)apParam)->FUN_00726070())
    {
        if (!(void*)unk04 || !((FUN_00726070_shell*)apParam)->FUN_00726070())
            return true;
        if (((FUN_005ab240_shell*)unk04)->IsDifferentFrom(((FUN_00726070_shell*)apParam)->FUN_00726070()))
            return true;
    }
    return false;
}
