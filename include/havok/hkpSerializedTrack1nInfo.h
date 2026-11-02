// include/havok/hkpSerializedTrack1nInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKPSERIALIZEDTRACK1NINFO_H
#define FNV_HAVOK_HKPSERIALIZEDTRACK1NINFO_H

#include "hkBase.h"
class hkpAgent1nSector;
class hkpSerializedSubTrack1nInfo;
#pragma pack(push, 1)
class hkpSerializedTrack1nInfo
{
  public:
    hkArray<hkpAgent1nSector*> m_kSectors;               // +0x0
    hkArray<hkpSerializedSubTrack1nInfo*> m_kSubTracks;  // +0xC
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpSerializedTrack1nInfo[(sizeof(hkpSerializedTrack1nInfo) == 0x18) ? 1 : -1];
#endif
