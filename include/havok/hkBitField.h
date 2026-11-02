// include/havok/hkBitField.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x10.
#ifndef FNV_HAVOK_HKBITFIELD_H
#define FNV_HAVOK_HKBITFIELD_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkBitField
{
  public:
    hkArray<hkUint32> m_auiBitFieldWords;  // +0x0
    hkInt32 m_iNumBits;                    // +0xC
};
#pragma pack(pop)
typedef char fnv_hk_size_hkBitField[(sizeof(hkBitField) == 0x10) ? 1 : -1];
#endif
