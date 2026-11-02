// include/havok/hkpCollidable.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPCOLLIDABLE_H
#define FNV_HAVOK_HKPCOLLIDABLE_H

#include "hkBase.h"
#include "hkpCdBody.h"
#include "hkpCollidableBoundingVolumeData.h"
#include "hkpTypedBroadPhaseHandle.h"
#pragma pack(push, 1)
class hkpCollidable : public hkpCdBody
{
  public:
    enum ForceCollideOntoPpuReasons
    {
        FORCE_PPU_USER_REQUEST = 1,
        FORCE_PPU_SHAPE_REQUEST = 2,
        FORCE_PPU_MODIFIER_REQUEST = 4
    };
    hkInt8 m_iOwnerOffset;                                  // +0x10
    hkUint8 m_uiForceCollideOntoPpu;                        // +0x11
    hkUint16 m_uiShapeSizeOnSpu;                            // +0x12
    hkpTypedBroadPhaseHandle m_kBroadPhaseHandle;           // +0x14
    hkpCollidableBoundingVolumeData m_kBoundingVolumeData;  // +0x20
    hkReal m_fAllowedPenetrationDepth;                      // +0x4C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpCollidable[(sizeof(hkpCollidable) == 0x50) ? 1 : -1];
#endif
