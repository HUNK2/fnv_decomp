
#include "nipsysboundupdatemodifier_decls.h"

// @fnv 0x00c2d720
void NiPSysBoundUpdateModifier::SetUpdateSkipCounter(int iUpdateSkip)
{
    m_usUpdateSkip = (short)iUpdateSkip;
    g_memoryManager.Deallocate(m_pkBounds);
    int iSkip = (short)iUpdateSkip;
    short sNumBounds = iSkip > 1 ? iSkip : 1;
    m_pkBounds = new NiBound[sNumBounds];
    for (int i = 0; i < sNumBounds; ++i) {
        m_pkBounds[i].SetCenterAndRadius(NiPoint3_ZERO, 0.0f);
    }
}
