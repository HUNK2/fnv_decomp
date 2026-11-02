// include/havok/hkpProperty.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKPPROPERTY_H
#define FNV_HAVOK_HKPPROPERTY_H

#include "hkBase.h"
#include "hkpPropertyValue.h"
#pragma pack(push, 1)
class hkpProperty
{
  public:
    hkUint32 m_key;                    // +0x0
    hkUint32 m_uiAlignmentPadding;     // +0x4
    hkpPropertyValue m_uiFilterValue;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpProperty[(sizeof(hkpProperty) == 0x10) ? 1 : -1];
#endif
