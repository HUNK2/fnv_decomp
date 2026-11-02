// Source layout: NiObjectNET. PC corrections are in generate_headers.py.
#ifndef FNV_NIBLENDTRANSFORMINTERPOLATOR_PRIVATE_FNV_NIOBJECTNET_H
#define FNV_NIBLENDTRANSFORMINTERPOLATOR_PRIVATE_FNV_NIOBJECTNET_H

#include "niblendtransforminterpolator_layout_support.h"
#include "niblendtransforminterpolator_NiFixedString.h"
#include "niblendtransforminterpolator_NiObject.h"
class NiObjectNET : public NiObject
{
  public:
    NiFixedString m_kName;                       // +0x8
    NiPointer<NiTimeController> m_pControllers;  // +0xC
    NiExtraData** m_ppExtraData;                 // +0x10
    unsigned short m_usExtraDataCount;           // +0x14
    unsigned short m_usMaxSize;                  // +0x16
};
FNV_STATIC_ASSERT(sizeof(NiObjectNET) == 0x18);
FNV_STATIC_ASSERT(offsetof(NiObjectNET, m_kName) == 0x8);
FNV_STATIC_ASSERT(offsetof(NiObjectNET, m_pControllers) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiObjectNET, m_ppExtraData) == 0x10);
FNV_STATIC_ASSERT(offsetof(NiObjectNET, m_usExtraDataCount) == 0x14);
FNV_STATIC_ASSERT(offsetof(NiObjectNET, m_usMaxSize) == 0x16);
#endif
