// include/havok/hkpEntityExtendedListeners.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKPENTITYEXTENDEDLISTENERS_H
#define FNV_HAVOK_HKPENTITYEXTENDEDLISTENERS_H

#include "hkBase.h"
#include "hkpEntitySmallArraySerializeOverrideType.h"
#pragma pack(push, 1)
class hkpEntityExtendedListeners
{
  public:
    hkpEntitySmallArraySerializeOverrideType m_kContactListenerArray;  // +0x0
    hkpEntitySmallArraySerializeOverrideType m_kEntityListenerArray;   // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpEntityExtendedListeners[(sizeof(hkpEntityExtendedListeners) == 0x10) ? 1 : -1];
#endif
