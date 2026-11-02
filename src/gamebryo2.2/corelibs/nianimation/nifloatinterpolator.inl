
#include "nifloatinterpolator_decls.h"
// @fnv 0x0052ce40
void NiFloatInterpolator::SetAnimationKeys(TimedAnimationKey* keys, unsigned int count, AnimationKey::KeyType type)
{
    if (count > 0) {
        if (!m_spFloatData.operator->())
            m_spFloatData = new NiFloatData;
        m_spFloatData->SetColorKeys(keys, count, type);
        m_uiLastKeyIndex = 0;
    } else {
        if (m_spFloatData.operator->())
            m_spFloatData->SetColorKeys(0, 0, AnimationKey::NOINTERP);
    }
}
