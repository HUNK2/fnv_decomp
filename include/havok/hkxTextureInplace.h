// include/havok/hkxTextureInplace.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKXTEXTUREINPLACE_H
#define FNV_HAVOK_HKXTEXTUREINPLACE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxTextureInplace : public hkReferencedObject
{
  public:
    char m_acLeadingBytes[4];  // +0x8
    hkArray<hkUint8> m_data;   // +0xC
    hkStringPtr m_name;        // +0x18
    hkStringPtr m_mimeType;    // +0x1C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxTextureInplace[(sizeof(hkxTextureInplace) == 0x20) ? 1 : -1];
#endif
