
// src/fallout/ai/combat/combatgoal_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x009843b0: the skeleton of src/fallout/ai/combat/combatgoal.cpp
// with declarations corrected to what the original code does (combatgoal.h: CombatGoal += bool FUN_009843b0(class CombatStateValues* values); BSSimpleList<UnsignedIdHandle*>* FUN_00717e50();; layout_support.h: void Sort(int (FNV_CDECL *compare)(T, T)); }; -> void Sort(int (FNV_CDECL *compare)(T, T)); BSSimpl). Move the function to its real unit once
// that unit declares it this way.

#include "combatgoal_decl_combatgoal.h"

class UnsignedIdHandle
{
  public:
    int type;
    int value;
    int FUN_00559450();
    int FUN_00726070();
};
class CombatStateValues
{
  public:
    unsigned int GetCombatGoal(int);
    bool FUN_009aadc0(int, int);
};
// @fnv 0x009843b0
bool CombatGoal::FUN_009843b0(CombatStateValues* values)
{
    BSSimpleList<UnsignedIdHandle*>* current = FUN_00717e50();
    UnsignedIdHandle* value;
    int state;
    int type;
    while (current && current->GetItem())
    {
        value = current->GetItem();
        state = value->FUN_00559450();
        type = value->FUN_00726070();
        if (state == 21)
        {
            if (values->GetCombatGoal(type))
                return false;
        }
        else if (state == 22)
        {
            if (!values->GetCombatGoal(type))
                return false;
        }
        else
        {
            if (!values->FUN_009aadc0(state, type))
                return false;
        }
        current = current->FUN_0062d990();
    }
    return true;
}
