// include/havok/hkaBone.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKABONE_H
#define FNV_HAVOK_HKABONE_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkaBone
{
  public:
    hkStringPtr m_name;         // +0x0
    hkBool m_bLockTranslation;  // +0x4
    char pad5[0x3];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkaBone[(sizeof(hkaBone) == 0x8) ? 1 : -1];
#endif
