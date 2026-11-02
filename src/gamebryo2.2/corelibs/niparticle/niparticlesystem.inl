
#include "niparticlesystem_match.h"
inline NiPSysModifier* NiParticleFindModifier(NiParticleModifierOwner* owner, const char* const& name)
{
    NiParticleModifierNode* position = owner->head;
    while (position) {
        NiPSysModifier* modifier = NiParticleGetNext(position);
        if (modifier && modifier->name == name)
            return modifier;
    }
    return 0;
}
// @fnv 0x00C31400
void NiParticleSystem::FindModifier()
{
    result = NiParticleFindModifier(owner, name);
}
