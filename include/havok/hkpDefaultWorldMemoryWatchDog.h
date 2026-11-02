// include/havok/hkpDefaultWorldMemoryWatchDog.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKPDEFAULTWORLDMEMORYWATCHDOG_H
#define FNV_HAVOK_HKPDEFAULTWORLDMEMORYWATCHDOG_H

#include "hkBase.h"
#include "hkWorldMemoryAvailableWatchDog.h"
#pragma pack(push, 1)
class hkpDefaultWorldMemoryWatchDog : public hkWorldMemoryAvailableWatchDog
{
  public:
    hkInt32 m_iMemoryLimit;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpDefaultWorldMemoryWatchDog[(sizeof(hkpDefaultWorldMemoryWatchDog) == 0xC) ? 1 : -1];
#endif
