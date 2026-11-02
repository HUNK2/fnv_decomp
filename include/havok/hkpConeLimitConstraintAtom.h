// include/havok/hkpConeLimitConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKPCONELIMITCONSTRAINTATOM_H
#define FNV_HAVOK_HKPCONELIMITCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpConeLimitConstraintAtom : public hkpConstraintAtom
{
  public:
    enum MeasurementMode
    {
        ZERO_WHEN_VECTORS_ALIGNED = 0,
        ZERO_WHEN_VECTORS_PERPENDICULAR = 1
    };
    hkUint8 m_bLimitEnabled;                     // +0x2
    hkUint8 m_ucMemOffsetToAngleOffset;          // +0x3
    hkUint8 m_ucMemOffsetToOldAngleOffset;       // +0x4
    hkUint8 m_ucMemOffsetToFirstConstrainedDof;  // +0x5 (MeasurementMode)
    hkUint8 m_ucAngleMeasurementMode;            // +0x6
    char pad7[0x1];
    hkReal m_fMinAngle;                // +0x8
    hkReal m_fMaxAngle;                // +0xC
    hkReal m_fAngularLimitsTauFactor;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConeLimitConstraintAtom[(sizeof(hkpConeLimitConstraintAtom) == 0x14) ? 1 : -1];
#endif
