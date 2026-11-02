// fallout_shared/tesraceform.cpp: TESRaceForm, TESNPC, ActorValue, TESActorBase (5 functions)

#include "tesraceform_decls.h"

// Resolves the stored race form ID against the owner's file, looks up the TESRace, and warns if the race cannot be found.
// @fnv 0x0048b920
void TESRaceForm::InitItem(TESForm* owner)
{
    if (m_pRace)
    {
        unsigned int formID = reinterpret_cast<unsigned int>(m_pRace);
        TESForm::RemapFormIDForFile(formID, owner->GetFile(-1));
        m_pRace = dynamic_cast<TESRace*>(GetFormByID(formID));
        if (!m_pRace)
        {
            if (owner)
            {
                if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                    Warning("MASTERFILE: Unable to find race (%08X) on owner object \"%s\".", formID, owner->GetName());
                else
                    Warning("MASTERFILE: Unable to find race (%08X) on owner object (%08X).", formID,
                            owner->GetFormID());
            }
            else
            {
                Warning("MASTERFILE: Unable to find race (%08X) on unknown owner.", formID);
            }
        }
    }
}

// Returns a skill value from kData arrays (plus offset unless Unk_51), otherwise delegates to ActorValueOwner::GetActorValue.
// @fnv 0x00607850
int TESNPC::GetActorValue(ActorValue::Index actorValue)
{
    int value = 0;
    if (ActorValue::IsSkill(actorValue))
    {
        int skillIndex = static_cast<signed char>(ActorValue::ToArrayIndex(2, actorValue));
        value = kData.ucSkillValues[skillIndex];
        if (!Unk_51())
            value += kData.ucSkillOffsets[skillIndex];
    }
    else
    {
        value = ActorValueOwner::GetActorValue(actorValue);
    }
    return value;
}

// Casts component to TESRaceForm and, if successful, sets this form's race to the component's race.
// @fnv 0x0048b870
void TESRaceForm::BaseFormRecord(BaseFormComponent* component)
{
    TESRaceForm* raceForm = dynamic_cast<TESRaceForm*>(component);
    if (!raceForm)
        return;
    SetFormRace(raceForm->GetFormRace());
}

// Returns the actor value for the given ActorValue::Index converted to float.
// @fnv 0x005f7480
float TESActorBase::GetCurrentActorValue(ActorValue::Index actorValue)
{
    return static_cast<float>(GetActorValue(actorValue));
}

struct FUN_0048b8c0_shell : TESRaceForm
{
    bool IsEqualToBase(BaseFormComponent* apCompareFC);
};

// Returns true if apCompareFC is not a TESRaceForm or its race differs from this form's race; otherwise false.
// @fnv 0x0048b8c0
bool FUN_0048b8c0_shell::IsEqualToBase(BaseFormComponent* apCompareFC)
{
    TESRaceForm* pcompare = dynamic_cast<TESRaceForm*>(apCompareFC);
    if (!pcompare)
        return true;
    if (this->GetFormRace() != pcompare->GetFormRace())
        return true;
    return false;
}
