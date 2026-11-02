// include/havok/hkpPhantom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xA4.
#ifndef FNV_HAVOK_HKPPHANTOM_H
#define FNV_HAVOK_HKPPHANTOM_H

#include "hkBase.h"
#include "hkpWorldObject.h"
#pragma pack(push, 1)
class hkpPhantom : public hkpWorldObject
{
  public:
    hkArray<void*> m_kPhantomOverlapListeners;  // +0x8C
    hkArray<void*> m_kPhantomListeners;         // +0x98
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPhantom[(sizeof(hkpPhantom) == 0xA4) ? 1 : -1];
#endif
