// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef NIBLENDINTERPOLATOR_INTERPITEM_H
#define NIBLENDINTERPOLATOR_INTERPITEM_H

#include "niblendinterpolator_layout_support.h"
#include "niblendinterpolator_layout_support.h"
class NiBlendInterpolator__InterpArrayItem;
class NiInterpolator;
class NiBlendInterpolator__InterpArrayItem
{
  public:
    NiPointer<NiInterpolator> m_spControllerInterpolator;  // +0x0, 4 bytes
    float m_fWeight;                                       // +0x4, 4 bytes
    float m_fNormalizedWeight;                             // +0x8, 4 bytes
    char m_cPriority;                                      // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
    float m_fEaseSpinner;         // +0x10, 4 bytes
    float m_fLastEvaluationTime;  // +0x14, 4 bytes
    NiBlendInterpolator__InterpArrayItem& operator=(const NiBlendInterpolator__InterpArrayItem& source);
    // InterpArrayItem
    // void __cdecl NiBlendInterpolator::InterpArrayItem::*()
    // void __cdecl NiBlendInterpolator::InterpArrayItem::*(NiStream&)
    // void __cdecl NiBlendInterpolator::InterpArrayItem::*(NiStream&)
    // void __cdecl NiBlendInterpolator::InterpArrayItem::*(NiStream&)
    // bool __cdecl NiBlendInterpolator::InterpArrayItem::*(NiBlendInterpolator::InterpArrayItem&)
    // void __cdecl NiBlendInterpolator::InterpArrayItem::*()
    // NiBlendInterpolator::InterpArrayItem& __cdecl NiBlendInterpolator::InterpArrayItem::*(const NiBlendInterpolator::InterpArrayItem&)
    // void* __cdecl NiBlendInterpolator::InterpArrayItem::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(NiBlendInterpolator__InterpArrayItem) == 24);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator__InterpArrayItem, m_spControllerInterpolator) == 0);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator__InterpArrayItem, m_fWeight) == 4);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator__InterpArrayItem, m_fNormalizedWeight) == 8);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator__InterpArrayItem, m_cPriority) == 12);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator__InterpArrayItem, m_fEaseSpinner) == 16);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator__InterpArrayItem, m_fLastEvaluationTime) == 20);
#endif
