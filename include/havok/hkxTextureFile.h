// include/havok/hkxTextureFile.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKXTEXTUREFILE_H
#define FNV_HAVOK_HKXTEXTUREFILE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkxTextureFile : public hkReferencedObject
{
  public:
    hkStringPtr m_pcFileName;  // +0x8
    hkStringPtr m_name;        // +0xC
    hkStringPtr m_mimeType;    // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkxTextureFile[(sizeof(hkxTextureFile) == 0x14) ? 1 : -1];
#endif
