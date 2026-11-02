#include "character_packet.h"

// @fnv 0x008d1ed0
bool Character::GetActorGuard()
{
    return m_bActorGuard;
}

// @fnv 0x008d83c0
float MiddleHighProcess::GetVisibilityAlpha()
{
    return m_fAnimationSpeed;
}

// @fnv 0x008d1ef0
void Character::SetActorGuardState(bool guard)
{
    m_bActorGuard = guard;
}
