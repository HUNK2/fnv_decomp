// include/havok/hkpWheelConstraintDataAtoms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x130.
#ifndef FNV_HAVOK_HKPWHEELCONSTRAINTDATAATOMS_H
#define FNV_HAVOK_HKPWHEELCONSTRAINTDATAATOMS_H
#include "hkBase.h"
#pragma pack(push, 1)
class hkpWheelConstraintDataAtoms
{
  public:
    enum Axis
    {
        AXIS_SUSPENSION = 0,
        AXIS_PERP_SUSPENSION = 1,
        AXIS_AXLE = 0,
        AXIS_STEERING = 1
    };
    char pad0[0x130];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpWheelConstraintDataAtoms[(sizeof(hkpWheelConstraintDataAtoms) == 0x130) ? 1 : -1];
#endif
