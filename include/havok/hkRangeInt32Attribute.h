// include/havok/hkRangeInt32Attribute.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKRANGEINT32ATTRIBUTE_H
#define FNV_HAVOK_HKRANGEINT32ATTRIBUTE_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkRangeInt32Attribute
{
  public:
    hkInt32 m_iFirstRangeValue;   // +0x0
    hkInt32 m_iSecondRangeValue;  // +0x4
    hkInt32 m_iThirdValue;        // +0x8
    hkInt32 m_iFourthRangeValue;  // +0xC
};
#pragma pack(pop)
typedef char fnv_hk_size_hkRangeInt32Attribute[(sizeof(hkRangeInt32Attribute) == 0x10) ? 1 : -1];
#endif
