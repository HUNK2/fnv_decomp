// include/havok/hkpRagdollConstraintDataAtoms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x130.
#ifndef FNV_HAVOK_HKPRAGDOLLCONSTRAINTDATAATOMS_H
#define FNV_HAVOK_HKPRAGDOLLCONSTRAINTDATAATOMS_H

#include "hkBase.h"
#include "hkpAngFrictionConstraintAtom.h"
#include "hkpBallSocketConstraintAtom.h"
#include "hkpConeLimitConstraintAtom.h"
#include "hkpRagdollMotorConstraintAtom.h"
#include "hkpSetLocalTransformsConstraintAtom.h"
#include "hkpTwistLimitConstraintAtom.h"
#pragma pack(push, 1)
class hkpRagdollConstraintDataAtoms
{
  public:
    enum Axis
    {
        AXIS_TWIST = 0,
        AXIS_PLANES = 1,
        AXIS_CROSS_PRODUCT = 2
    };
    hkpSetLocalTransformsConstraintAtom m_kTransforms;  // +0x0
    hkpRagdollMotorConstraintAtom m_kMotor;             // +0x90
    hkpAngFrictionConstraintAtom m_kFriction;           // +0xE0
    hkpTwistLimitConstraintAtom m_kTwistLimit;          // +0xEC
    hkpConeLimitConstraintAtom m_kConeLimit;            // +0x100
    hkpConeLimitConstraintAtom m_kPlaneLimit;           // +0x114
    hkpBallSocketConstraintAtom m_kBallSocket;          // +0x128
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpRagdollConstraintDataAtoms[(sizeof(hkpRagdollConstraintDataAtoms) == 0x130) ? 1 : -1];
#endif
