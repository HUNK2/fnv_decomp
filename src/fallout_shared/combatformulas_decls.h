// fallout_shared/combatformulas_decls.h: declares TESObjectARMO, CombatDamageCalculator

#include "combatformulas_form.h"
#include "combatformulas_item.h"
#include "combatformulas_health.h"
class TESObjectARMO : public TESForm
{
  public:
    float GetDamageThreshold();
};
class CombatDamageCalculator
{
  public:
    static float CalculateWeaponDamage(ActorValueOwner*, TESObjectWEAP*, float, bool, InventoryStackRecord*, bool, bool, int,
                                       float, float, bool, bool, TESAmmo*);
    static float CalculateWeaponDamageForActor(TESObjectREFR*, TESObjectWEAP*, bool, InventoryStackRecord*);
    static float GetWeaponConditionDamageMultiplier(int);
    static float GetActorValueMultiplier(ActorValueOwner*, ActorValue::Index, bool);
    static float GetDamageMultiplier(float, float);
    static float CalculateArmorDamageThreshold(unsigned short rating, float condition);
};
