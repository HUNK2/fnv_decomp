#ifndef FNV_ASTRA_NIREF_ARRAY_INL
#define FNV_ASTRA_NIREF_ARRAY_INL
#include "nirefobject_types.h"

// @fnv 0x004b0310
template<>
void NiTArray<NiPointer<NiAVObject>,NiTNewInterface<NiPointer<NiAVObject> > >::SetAt(
    unsigned int index,const NiPointer<NiAVObject>& element)
{
    static const NiPointer<NiAVObject> kNull(0);
    if (index >= m_usSize)
    {
        m_usSize = static_cast<unsigned short>(index+1);
        if (element != kNull)
            m_usESize++;
    }
    else if (element != kNull)
    {
        if (m_pBase[index] == kNull)
            m_usESize++;
    }
    else if (m_pBase[index] != kNull)
        m_usESize--;
    m_pBase[index] = element;
}
#endif
