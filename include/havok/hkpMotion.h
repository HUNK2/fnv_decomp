// include/havok/hkpMotion.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x120.
#ifndef FNV_HAVOK_HKPMOTION_H
#define FNV_HAVOK_HKPMOTION_H

#include "hkBase.h"
#include "hkMotionState.h"
#include "hkReferencedObject.h"
class hkpMaxSizeMotion;
#pragma pack(push, 1)
class hkpMotion : public hkReferencedObject
{
  public:
    enum MotionType
    {
        MOTION_INVALID = 0,
        MOTION_DYNAMIC = 1,
        MOTION_SPHERE_INERTIA = 2,
        MOTION_BOX_INERTIA = 3,
        MOTION_KEYFRAMED = 4,
        MOTION_FIXED = 5,
        MOTION_THIN_BOX_INERTIA = 6,
        MOTION_CHARACTER = 7,
        MOTION_MAX_ID = 8
    };
    hkUint8 m_type;                                  // +0x8 (MotionType)
    hkUint8 m_ucDeactivationIntegrateCounter;        // +0x9
    hkUint16 m_ausDeactivationNumInactiveFrames[2];  // +0xA
    char padE[0x2];
    hkMotionState m_kMotionState;                        // +0x10
    hkVector4 m_kInertiaAndMassInv;                      // +0xC0
    hkVector4 m_kTranslationalVelocity;                  // +0xD0
    hkVector4 m_kAngularVelocity;                        // +0xE0
    hkVector4 m_akDeactivationReferencePositions[2];     // +0xF0
    hkUint32 m_auiDeactivationReferenceOrientations[2];  // +0x110
    hkpMaxSizeMotion* m_pSavedMotion;                    // +0x118
    hkUint16 m_savedMotionSize;                          // +0x11C
    hkHalf m_fGravityFactor;                             // +0x11E
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpMotion[(sizeof(hkpMotion) == 0x120) ? 1 : -1];
#endif
