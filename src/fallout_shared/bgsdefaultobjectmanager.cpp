// fallout_shared/bgsdefaultobjectmanager.cpp: BGSDefaultObjectManager, NavMesh (11 functions)

#include "bgsdefaultobjectmanager_form.h"
#include "bgsdefaultobjectmanager.h"
#include <string.h>

// Zeroes the default object array with memset.
// @fnv 0x0058d840
void BGSDefaultObjectManager::ResetFormData()
{
    memset(m_apDefaultObjects, 0, sizeof(m_apDefaultObjects));
}

// @fnv 0x0058db10
TESForm* BGSDefaultObjectManager::GetDefaultObjectByIndex(DEFAULT_OBJECT index)
{
    if (!Instance()->IsFormInitialized())
        return 0;
    return Instance()->m_apDefaultObjects[index];
}

// Returns the singleton BGSDefaultObjectManager, allocating it with new if it has not been created yet.
// @fnv 0x0058d680
BGSDefaultObjectManager* BGSDefaultObjectManager::Instance()
{
    if (!ms_pSystemUtility)
        ms_pSystemUtility = new BGSDefaultObjectManager;
    return ms_pSystemUtility;
}

#include "bgsdefaultobjectmanager_endian.h"

// Reads a TESFile record of form type 100, loads the DATA chunk into the default object array and byte-swaps it when endian conversion is required.
// @fnv 0x0058d920
bool BGSDefaultObjectManager::Load(TESFile* file)
{
    unsigned char form = file->GetTESForm();
    if (form != 100)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    while (unsigned int chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 0x41544144:
            file->GetChunkData(m_apDefaultObjects, sizeof(m_apDefaultObjects));
            if (file->IsEndianConversionRequired())
            {
                for (int i = 0; i < DEFAULT_OBJECT_DO_COUNT; ++i)
                    BSEndian((unsigned int*)&m_apDefaultObjects[i], EndianSizeTag<4>());
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    SetInitializationState(false);
    return true;
}

#include "bgsdefaultobjectmanager_decls.h"
// If not yet initialized, resolves each of the 34 default object IDs to a form, clears mismatched types, warns on failures, then marks the manager initialized.
// @fnv 0x0058da10
void BGSDefaultObjectManager::InitItem()
{
    if (GetInitialized())
        return;
    for (int i = 0; i < 34; ++i)
    {
        unsigned int uiFormId = (unsigned int)m_apDefaultObjects[i];
        if (uiFormId)
        {
            TESForm::RemapFormIDForFile(uiFormId, GetFile(-1));
            m_apDefaultObjects[i] = TESForm::GetFormByID(uiFormId);
            if (m_apDefaultObjects[i] && m_apDefaultObjects[i]->GetFormType() != DAT_0118c360[i].type)
                m_apDefaultObjects[i] = 0;
            if (!m_apDefaultObjects[i])
                Warning("Unable to find valid '%s' default object for ID (%08X).", DAT_0118c360[i].name, uiFormId);
        }
    }
    SetInitializationState(true);
}

#include "bgsdefaultobjectmanager_nav.h"
// @fnv 0x0068eb80
NavMesh::NavMesh() : POVPointerArray(37)
{
    SetFormType(ENUM_FORM_ID_NAVM_ID);
    m_pOwningCell = 0;
    m_pNavigationMesh = 0;
    pTriangleToObstacleMap = new NiTMap_unsigned_short_NiPointer_ObstacleData___(37);
}

// Deletes the BGSDefaultObjectManager singleton instance and clears its pointer if it is set.
// @fnv 0x0058d710
void DestroyDefaultObjectManager()
{
    if (BGSDefaultObjectManager::ms_pSystemUtility)
    {
        delete BGSDefaultObjectManager::ms_pSystemUtility;
        BGSDefaultObjectManager::ms_pSystemUtility = 0;
    }
}

struct ActorValueInfo
{
    void SetScriptName(char const*);
};

struct FUN_0058d760 : public TESForm
{
    FUN_0058d760();
    virtual ~FUN_0058d760();
};

// @fnv 0x0058d760
FUN_0058d760::FUN_0058d760() : TESForm()
{
    SetFormType((ENUM_FORM_ID)100);
    SetRefID(0x31, 1);
    ((ActorValueInfo*)this)->SetScriptName("DefaultObjectManager");
    ((BGSDefaultObjectManager*)this)->ResetFormData();
}

void _Deallocate(void*);
struct S_0058d7f0
{
    void InitializeVTable();
    void* FUN_0058d7f0(unsigned int);
};
// Calls InitializeVTable, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0058d7f0
void* S_0058d7f0::FUN_0058d7f0(unsigned int flags)
{
    InitializeVTable();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct TESForm_StartForm
{
    void M();
};
struct TESForm_CloseForm
{
    void M();
};
void __cdecl FUN_00485710(unsigned int, unsigned int*, unsigned int);
struct FUN_0058d870_shell
{
    void BGSDefaultObjectManager_SaveForm();
};
// @fnv 0x0058d870
void FUN_0058d870_shell::BGSDefaultObjectManager_SaveForm()
{
    unsigned int pidarray4[34];
    int i;
    ((TESForm_StartForm*)this)->M();
    for (i = 0; i < 34; ++i)
    {
        if (*(void**)((char*)this + 0x18 + i * 4))
            pidarray4[i] = ((TESForm*)*(void**)((char*)this + 0x18 + i * 4))->GetFormID();
        else
            pidarray4[i] = 0;
    }
    FUN_00485710(0x41544144, pidarray4, 34);
    ((TESForm_CloseForm*)this)->M();
}

// InitializeVTable: constructor-like member that installs the class vtable
// pointer into *this and then calls a base routine with this as `this`.
extern int DAT_01032dc4;

struct FUN_0058d820_cls
{
    void* m_pVTable;
    void FUN_00483630();
    void InitializeVTable();
};

// @fnv 0x0058d820
void FUN_0058d820_cls::InitializeVTable()
{
    m_pVTable = (void*)&DAT_01032dc4;
    FUN_00483630();
}
