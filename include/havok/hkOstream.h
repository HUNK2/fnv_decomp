// include/havok/hkOstream.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKOSTREAM_H
#define FNV_HAVOK_HKOSTREAM_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkStreamWriter;
#pragma pack(push, 1)
class hkOstream : public hkReferencedObject
{
  public:
    hkStreamWriter* m_pStreamWriter;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkOstream[(sizeof(hkOstream) == 0xC) ? 1 : -1];
#endif
