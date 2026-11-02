#include "bsaudio_player_decls.h"
// @fnv 0x0093a5f0
void PlayerCharacter::SetUnderAIControl(bool enabled)
{
    underAIControl = enabled;
    if (GetUnderAIControl())
        vfn_258(false);
    else
        vfn_258(true);
}
// @fnv 0x00950290
void PlayerCharacter::UpdateCameraMode()
{
    bool changed = thirdPerson != previousThirdPerson;
    if (!changed)
        return;
    if (DAT_011e07dc > DAT_0101db88)
        return;
    previousThirdPerson = thirdPerson;
    if (!DAT_011e07b8 && firstPersonNode.operator->() && !previousThirdPerson)
        Show1stPerson(!previousThirdPerson);
}
