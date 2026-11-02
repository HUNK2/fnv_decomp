// include/havok/hkpPointToPathConstraintData.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xB0.
#ifndef FNV_HAVOK_HKPPOINTTOPATHCONSTRAINTDATA_H
#define FNV_HAVOK_HKPPOINTTOPATHCONSTRAINTDATA_H

#include "hkBase.h"
#include "hkpBridgeAtoms.h"
#include "hkpConstraintData.h"
class hkpParametricCurve;
#pragma pack(push, 1)
class hkpPointToPathConstraintData : public hkpConstraintData
{
  public:
    enum OrientationConstraintType
    {
        CONSTRAIN_ORIENTATION_INVALID = 0,
        CONSTRAIN_ORIENTATION_NONE = 1,
        CONSTRAIN_ORIENTATION_ALLOW_SPIN = 2,
        CONSTRAIN_ORIENTATION_TO_PATH = 3,
        CONSTRAIN_ORIENTATION_MAX_ID = 4
    };
    hkpBridgeAtoms m_kBridgeAtoms;        // +0xC
    hkpParametricCurve* m_path;           // +0x18
    hkReal m_fFriction;                   // +0x1C
    hkInt8 m_cOrientationConstraintType;  // +0x20 (OrientationConstraintType)
    char pad21[0xF];
    hkTransform m_kLocalTransforms[2];  // +0x30
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPointToPathConstraintData[(sizeof(hkpPointToPathConstraintData) == 0xB0) ? 1 : -1];
#endif
