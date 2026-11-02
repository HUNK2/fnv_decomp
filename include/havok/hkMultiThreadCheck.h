// include/havok/hkMultiThreadCheck.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKMULTITHREADCHECK_H
#define FNV_HAVOK_HKMULTITHREADCHECK_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkMultiThreadCheck
{
  public:
    enum AccessType
    {
        HK_ACCESS_IGNORE = 0,
        HK_ACCESS_RO = 1,
        HK_ACCESS_RW = 2
    };
    enum ReadMode
    {
        THIS_OBJECT_ONLY = 0,
        RECURSIVE = 1
    };
    hkUint32 m_uiThreadId;        // +0x0
    hkUint16 m_usMarkedForWrite;  // +0x4
    hkUint16 m_usMarkCount;       // +0x6
};
#pragma pack(pop)
typedef char fnv_hk_size_hkMultiThreadCheck[(sizeof(hkMultiThreadCheck) == 0x8) ? 1 : -1];
#endif
