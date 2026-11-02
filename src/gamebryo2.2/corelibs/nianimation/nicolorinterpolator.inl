
#include "nicolorinterpolator_decls.h"
// @fnv 0x0052cff0
void NiColorInterpolator::SetAnimationKeys(ColorAnimationKey* keys, unsigned int count, AnimationKey::KeyType type)
{
    if (count > 0)
    {
        if (!m_spColorData.operator->())
            m_spColorData = new NiColorData;
        m_spColorData->SetColorKeys(keys, count, type);
        m_uiLastKeyIndex = 0;
    }
    else if (m_spColorData.operator->())
        m_spColorData->SetColorKeys(0, 0, AnimationKey::NOINTERP);
}
