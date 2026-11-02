// include/havok/hkpLinearParametricCurve.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPLINEARPARAMETRICCURVE_H
#define FNV_HAVOK_HKPLINEARPARAMETRICCURVE_H

#include "hkBase.h"
#include "hkpParametricCurve.h"
#pragma pack(push, 1)
class hkpLinearParametricCurve : public hkpParametricCurve
{
  public:
    hkReal m_fSmoothingValue;  // +0x8
    hkBool m_bClosedLoop;      // +0xC
    char padD[0x3];
    hkVector4 m_kVector4;                            // +0x10
    hkArray<hkVector4> m_kPoints;                    // +0x20
    hkArray<hkReal> m_fClosestPointDistanceSquared;  // +0x2C
    char pad38[0x8];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpLinearParametricCurve[(sizeof(hkpLinearParametricCurve) == 0x40) ? 1 : -1];
#endif
