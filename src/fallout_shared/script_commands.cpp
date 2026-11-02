// fallout_shared/script_commands.cpp: free functions (1 function)

#include "PlayerCharacter.h"
#include "Script.h"
#include "original_script.h"
extern PlayerCharacter* g_thePlayer;
// Extracts an experience argument and grants it to the player via GrantExperience, returning success.
// @fnv 0x005d5140
bool Cmd_RewardXP_Execute(const ScriptParameter* paramInfo, const char* scriptData, TESObjectREFR* thisObject,
                          TESObjectREFR* containingObject, Script* script, ScriptLocals* locals, double* result,
                          unsigned int* opcodeOffset)
{
    int experience = 0;
    if (!ExtractArgs(paramInfo, scriptData, opcodeOffset, thisObject, containingObject, script, locals, &experience))
    {
        return false;
    }
    g_thePlayer->GrantExperience(experience);
    return true;
}
