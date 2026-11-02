// include/havok/hkpSerializedSubTrack1nInfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPSERIALIZEDSUBTRACK1NINFO_H
#define FNV_HAVOK_HKPSERIALIZEDSUBTRACK1NINFO_H

#include "hkBase.h"
#include "hkpSerializedTrack1nInfo.h"
#pragma pack(push, 1)
class hkpSerializedSubTrack1nInfo : public hkpSerializedTrack1nInfo
{
  public:
    hkInt32 m_iTrackId;     // +0x18
    hkInt32 m_iSubTrackId;  // +0x1C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpSerializedSubTrack1nInfo[(sizeof(hkpSerializedSubTrack1nInfo) == 0x20) ? 1 : -1];
#endif
