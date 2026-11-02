// fallout_shared/magic/effectarchetype.cpp: free functions (1 function)

#include "effectarchetype_decls.h"
// Looks up the effect archetype's factory by the effect's archetype and creates an ActiveEffect via it, then passes source to the created effect.
// @fnv 0x00403ab0
ActiveEffect* MagicEffectSystem::Activate(MagicCaster* caster, MagicItem* item, EffectItem* effect,
                                          TESBoundObject* source)
{
    ActiveEffect* pCreateEffect = 0;
    EffectSetting* m_pLinkedEffect = effect ? (EffectSetting*)((AnimIdle*)effect)->GetSection() : 0;
    int m_eEffectTypeItem = m_pLinkedEffect->GetArchetype();
    EffectFactory pFactory = DAT_01183324[m_eEffectTypeItem].factory;
    if (pFactory)
        pCreateEffect = pFactory(caster, item, effect);
    if (pCreateEffect)
        pCreateEffect->InitFromSource(source);
    return pCreateEffect;
}
