#ifndef NIPARTICLESYSTEM_MATCH_H
#define NIPARTICLESYSTEM_MATCH_H

struct NiPSysModifier
{
    char padding[8];
    const char* name;
};
struct NiParticleModifierPointer
{
    NiPSysModifier* value;
    operator NiPSysModifier*() const
    {
        return value;
    }
};
struct NiParticleModifierNode
{
    NiParticleModifierNode* next;
    NiParticleModifierNode* previous;
    NiParticleModifierPointer modifier;
};
struct NiParticleModifierOwner
{
    char padding[0xc8];
    NiParticleModifierNode* head;
};
inline const NiParticleModifierPointer& NiParticleGetNext(NiParticleModifierNode*& position)
{
    const NiParticleModifierPointer* value = &position->modifier;
    position = position->next;
    return *value;
}
class NiParticleSystem
{
  public:
    char padding[0x2c];
    NiParticleModifierOwner* owner;
    char padding30[8];
    const char* name;
    NiPSysModifier* result;
    void FindModifier();
};
#endif
