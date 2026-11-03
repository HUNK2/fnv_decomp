// fallout_shared/bgsopencloseform.cpp: BGSOpenCloseForm, AIThreadManager (8 functions)

#include "bgsopencloseform_packet_decls.h"

// @fnv 0x0047a490
bool BGSOpenCloseForm::HasOpenCloseComponent(TESForm* apForm)
{
    bool bResult = false;
    bool bIsActivatorForm = false;
    if (apForm)
    {
        switch (apForm->GetFormType())
        {
        case ENUM_FORM_ID_ACTI_ID:
        case ENUM_FORM_ID_TERM_ID:
        case ENUM_FORM_ID_CONT_ID:
        case ENUM_FORM_ID_DOOR_ID:
            bResult = true;
            break;
        case ENUM_FORM_ID_TACT_ID:
        case ENUM_FORM_ID_FLOR_ID:
        case ENUM_FORM_ID_FURN_ID:
            bIsActivatorForm = true;
            break;
        default:
            break;
        }
    }
    return bResult;
}

// @fnv 0x0047b250
BGSOpenCloseForm::OPEN_STATE BGSOpenCloseForm::GetOpenState(TESObjectREFR* ref)
{
    // Local names preserve MSVC9 stack allocation order.
    OPEN_STATE eState = CLOSED_UNKNOWN;
    if (ref && HasOpenCloseComponent(ref->GetObjectReference()))
    {
        bool pManager = ref->GetAction(ACTION_OPEN);  // Saved open action flag.
        if (pManager)
            eState = OPEN;
        else
            eState = CLOSED;
        NiNode* pController = ref->GetNiNode_v();                                   // Reference scene node.
        NiTimeController* pNode = pController ? pController->GetControllers() : 0;  // Controller chain.
        // Runtime RTTI cast to the controller manager.
        NiControllerManager* bOpen = (NiControllerManager*)FUN_00653270(&DAT_011f36ac, (NiProperty*)pNode);
        if (bOpen)
        {
            NiControllerSequence* pOpenSequence = bOpen->FindSequenceByName(*TESObjectDOOR::GetOpenSequenceName());
            NiControllerSequence* pCloseSequence =
                bOpen->FindSequenceByName(*NiControllerManager::FindSequenceByName());
            if (pOpenSequence && pCloseSequence)
            {
                if (((LowProcess*)pOpenSequence)->GetActiveCombatTarget() == (TESObjectREFR*)1)
                    eState = OPENING;
                else if (((LowProcess*)pCloseSequence)->GetActiveCombatTarget() == (TESObjectREFR*)1)
                    eState = CLOSING;
            }
        }
    }
    return eState;
}

// @fnv 0x0047aec0
bool BGSOpenCloseForm::SetOpenState(TESObjectREFR* ref, bool open, bool immediate)
{
    bool result = false;
    if (ref && HasOpenCloseComponent(ref->GetObjectReference()))
    {
        if (IsConditionMet() && ref != AIThreadManager::IsConditionMet())
        {
            TaskQueueInterface::GetSingleton()->FUN_0087b600(ref, open, immediate);
            return true;
        }
        if (open)
            ref->PerformAction(ACTION_OPEN);
        else
            ref->CloseReference(ACTION_OPEN);
        NiNode* node = ref->GetNiNode_v();
        NiTimeController* manager = node ? node->GetControllers() : 0;  // Controller chain.
        // Runtime RTTI cast to the controller manager.
        NiControllerManager* controller = (NiControllerManager*)FUN_00653270(&DAT_011f36ac, (NiProperty*)manager);
        if (controller)
        {
            NiControllerSequence* active = 0;
            NiControllerSequence* inactive = 0;
            NiControllerSequence* opening = controller->FindSequenceByName(*TESObjectDOOR::GetOpenSequenceName());
            NiControllerSequence* closing = controller->FindSequenceByName(*NiControllerManager::FindSequenceByName());
            if (opening && closing)
            {
                if (open)
                {
                    active = opening;
                    inactive = closing;
                }
                else
                {
                    active = closing;
                    inactive = opening;
                }
                controller->FUN_0047aa40(true);
                if (immediate)
                {
                    ref->GetExtraData()->CallExtraDataListMethod36(0);
                    controller->StopSequence(active, 0.0f);
                    controller->ActivateControllerSequence(inactive, 0, false, 1.0f, 0.0f, 0);
                    inactive->FUN_0098adb0(-DAT_0101ab70);
                    NiUpdateData data(inactive->FUN_00759450(), true, false);
                    ref->GetNiNode_v()->Update(data);
                    controller->StopSequence(inactive, 0.0f);
                    ref->TESObjectREFR_SetLastFinishedSequence(active->GetName());
                    FUN_00c6bd00(ref->GetNiNode_v(), true);
                }
                else
                {
                    controller->StopSequence(inactive, 0.0f);
                    controller->ActivateControllerSequence(active, 0, false, 1.0f, 0.0f, 0);
                    active->FUN_0098adb0(-DAT_0101ab70);
                    NiUpdateData data(active->FUN_00759450(), true, false);
                    ref->GetNiNode_v()->Update(data);
                }
                result = true;
            }
        }
        else
        {
            if (open)
                ref->TESObjectREFR_SetLastFinishedSequence(DAT_01011f30);
            else
                ref->TESObjectREFR_SetLastFinishedSequence(g_011d22b0_arg1);
        }
        if (immediate && *((ProcessLists*)&g_011d7188)->GetLifeStateControlFlag() &&
            ref->GetObjectReference()->GetFormType() == ENUM_FORM_ID_DOOR_ID && ref->GetNiNode_v() &&
            !ref->GetExtraRadioData())
        {
            if (open)
                NavMeshObstacleManager::GetSingleton()->RemoveObstacleReference(ref);
            else
                NavMeshObstacleManager::GetSingleton()->AddObstacleReference(ref);
        }
    }
    return result;
}

struct FUN_00759450_shell : public NiControllerSequence
{
    float FUN_00759450();
};

// @fnv 0x00759450
float FUN_00759450_shell::FUN_00759450()
{
    return *(float*)((char*)this + 0x2c);
}

struct FUN_0098adb0_shell : public NiControllerSequence
{
    void FUN_0098adb0(float);
};

// @fnv 0x0098adb0
void FUN_0098adb0_shell::FUN_0098adb0(float afValue)
{
    *(float*)((char*)this + 0x48) = afValue;
}

extern NiFixedString* DAT_011c61c4;

// @fnv 0x005c1490
NiFixedString* __cdecl FUN_005c1490()
{
    return DAT_011c61c4;
}

class TESObjectACTI
{
};
class TESObjectCONT
{
};

// @fnv 0x0047a3a0
BGSOpenCloseForm* GetOpenCloseForm(TESForm* apForm)
{
    BGSOpenCloseForm* pOpenCloseForm = 0;

    if (apForm && BGSOpenCloseForm::HasOpenCloseComponent(apForm))
    {
        switch (apForm->GetFormType())
        {
        case 0x15:
        case 0x17: {
            TESObjectACTI* pObject = reinterpret_cast<TESObjectACTI*>(apForm);
            pOpenCloseForm = pObject ? reinterpret_cast<BGSOpenCloseForm*>(reinterpret_cast<char*>(pObject) + 0x70) : 0;
            break;
        }

        case 0x1c: {
            TESObjectDOOR* pObject = reinterpret_cast<TESObjectDOOR*>(apForm);
            pOpenCloseForm = pObject ? reinterpret_cast<BGSOpenCloseForm*>(reinterpret_cast<char*>(pObject) + 0x70) : 0;
            break;
        }

        case 0x1b: {
            TESObjectCONT* pObject = reinterpret_cast<TESObjectCONT*>(apForm);
            pOpenCloseForm = pObject ? reinterpret_cast<BGSOpenCloseForm*>(reinterpret_cast<char*>(pObject) + 0x84) : 0;
            break;
        }
        }
    }

    return pOpenCloseForm;
}

struct EventString
{
    operator const char*() const;
};
struct SequenceEvent
{
    EventString& GetName();
};
struct Ref;
struct EventExtra
{
    Ref* GetTarget();
    void ResetTargetPointer(Ref*);
};
struct BaseForm
{
    unsigned int FormType();
};
struct Ref
{
    EventExtra* Extra();
    BaseForm* Base();
    void Reset(bool);
};
struct OpenCloseHandler
{
    virtual void Open(Ref*, Ref*);
    virtual void Close(Ref*, Ref*);
    virtual bool IsSpecial();
};
struct EventSetting
{
    unsigned char* Bool();
};
struct EventQueue
{
    void Open(Ref*);
    void Close(Ref*);
};
struct ObstacleManager
{
    static ObstacleManager* GetSingleton();
    void Open(Ref*);
    void Close(Ref*);
};
extern Ref* player;
extern EventSetting setting;
bool ProcessEvent(Ref*, SequenceEvent*);
int CompareEvent(const char*, const char*);
void SetEventFlags(Ref*, EventExtra*, unsigned int);
OpenCloseHandler* GetHandler(BaseForm*);
bool ShouldQueue();
EventQueue* GetQueue();
// @fnv 0x0047ac70
void __cdecl ProcessOpenCloseEvent(Ref* ref, SequenceEvent* sequence)
{
    bool handled = false;
    if (ref && sequence)
    {
        handled = ProcessEvent(ref, sequence);
        if (!CompareEvent(sequence->GetName(), "Open"))
        {
            handled = true;
            SetEventFlags(ref, ref->Extra(), 0x10000);
            Ref* openTarget = ref->Extra()->GetTarget();
            if (openTarget)
            {
                OpenCloseHandler* openHandler = GetHandler(ref->Base());
                if (openHandler)
                    openHandler->Open(ref, openTarget);
                ref->Extra()->ResetTargetPointer(0);
                if (openTarget == player && openHandler && openHandler->IsSpecial())
                    player->Reset(false);
            }
            if (*setting.Bool() && ref->Base()->FormType() == 28)
            {
                if (ShouldQueue())
                    GetQueue()->Open(ref);
                else
                    ObstacleManager::GetSingleton()->Open(ref);
            }
        }
        else if (!CompareEvent(sequence->GetName(), "Close"))
        {
            handled = true;
            SetEventFlags(ref, ref->Extra(), 0x20000);
            Ref* closeTarget = ref->Extra()->GetTarget();
            if (closeTarget)
            {
                OpenCloseHandler* closeHandler = GetHandler(ref->Base());
                if (closeHandler)
                    closeHandler->Close(ref, closeTarget);
                ref->Extra()->ResetTargetPointer(0);
            }
            if (*setting.Bool() && ref->Base()->FormType() == 28)
            {
                if (ShouldQueue())
                    GetQueue()->Close(ref);
                else
                    ObstacleManager::GetSingleton()->Close(ref);
            }
        }
    }
}
