
// src/fallout_shared/tesconditionfunctions_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesconditionfunctions.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "tesconditionfunctions_conditionfn_MobileObject.h"
#include "tesconditionfunctions_conditionfn_low_Script.h"
#include "tesconditionfunctions_conditionfn_class_faction.h"
#include "tesconditionfunctions_conditionfn_dep_TESQuest.h"
#include "tesconditionfunctions_conditionfn_BGSQuestObjective.h"
#include "tesconditionfunctions_packet.h"
#include "tesconditionfunctions_conditionfn_dep_TESObjectREFR.h"
class PlayerCharacter;
extern PlayerCharacter* g_thePlayer;
struct PlayerCharacterMovingStateView
{
    unsigned char padding[0x20c];
    unsigned char movingIntoNewSpace;
};
class Actor
{
  public:
    bool IsEssentialActor();
    unsigned int GetActorStateFlags() const;
    BooleanFloatQuery* RefreshActorRuntimeData();
};
bool __cdecl GetEssentialConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result);
bool __cdecl IsPlayerEnteringSpaceConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result);
bool GetLastHitLocationConditionFunction(TESObjectREFR* reference, void* arg1, void* arg2, double& result);
