// include/havok/hkpHingeLimitsDataAtoms.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x90.
#ifndef FNV_HAVOK_HKPHINGELIMITSDATAATOMS_H
#define FNV_HAVOK_HKPHINGELIMITSDATAATOMS_H
#include "hkBase.h"
#pragma pack(push, 1)
class hkpHingeLimitsDataAtoms
{
  public:
    enum Axis
    {
        AXIS_AXLE = 0,
        AXIS_PERP_TO_AXLE_1 = 1,
        AXIS_PERP_TO_AXLE_2 = 2
    };
    char pad0[0x90];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpHingeLimitsDataAtoms[(sizeof(hkpHingeLimitsDataAtoms) == 0x90) ? 1 : -1];
#endif
