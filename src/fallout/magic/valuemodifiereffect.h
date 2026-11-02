// fallout/magic/valuemodifiereffect.h: declares ValueModifierEffect

#define ValueModifierEffect ValueModifierEffect_decl
#include "valuemodifiereffect_decls.h"
#undef ValueModifierEffect

class ValueModifierEffect
{
  public:
    unsigned char activeEffectData[0x48];
    ActorValue::Index m_eActorValue;
    ActorValue::Index GetActorValue();
    void SetActorValue(ActorValue::Index value);
};

// @fnv 0x006733e0
ActorValue::Index ValueModifierEffect::GetActorValue()
{
    return m_eActorValue;
}

// @fnv 0x00673400
void ValueModifierEffect::SetActorValue(ActorValue::Index value)
{
    m_eActorValue = value;
}
