// include/havok/hkpTypedBroadPhaseHandle.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xC.
#ifndef FNV_HAVOK_HKPTYPEDBROADPHASEHANDLE_H
#define FNV_HAVOK_HKPTYPEDBROADPHASEHANDLE_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkpTypedBroadPhaseHandle
{
  public:
    char pad0[0x4];
    hkInt8 m_type;                 // +0x4
    hkInt8 m_iOwnerOffset;         // +0x5
    hkInt8 m_ucObjectQualityType;  // +0x6
    char pad7[0x1];
    hkUint32 m_uiCollisionFilterData;  // +0x8
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpTypedBroadPhaseHandle[(sizeof(hkpTypedBroadPhaseHandle) == 0xC) ? 1 : -1];
#endif
