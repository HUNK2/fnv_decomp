// include/havok/hkpLimitedHingeConstraintDataAtoms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xD0.
#ifndef FNV_HAVOK_HKPLIMITEDHINGECONSTRAINTDATAATOMS_H
#define FNV_HAVOK_HKPLIMITEDHINGECONSTRAINTDATAATOMS_H
#include "hkBase.h"
#pragma pack(push, 1)
class hkpLimitedHingeConstraintDataAtoms
{
  public:
    enum Axis
    {
        AXIS_AXLE = 0,
        AXIS_PERP_TO_AXLE_1 = 1,
        AXIS_PERP_TO_AXLE_2 = 2
    };
    char pad0[0xD0];
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpLimitedHingeConstraintDataAtoms[(sizeof(hkpLimitedHingeConstraintDataAtoms) == 0xD0) ? 1 : -1];
#endif
