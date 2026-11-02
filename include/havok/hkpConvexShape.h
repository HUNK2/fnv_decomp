// include/havok/hkpConvexShape.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x14.
#ifndef FNV_HAVOK_HKPCONVEXSHAPE_H
#define FNV_HAVOK_HKPCONVEXSHAPE_H

#include "hkBase.h"
#include "hkpSphereRepShape.h"
#pragma pack(push, 1)
class hkpConvexShape : public hkpSphereRepShape
{
  public:
    enum WeldResult
    {
        WELD_RESULT_REJECT_CONTACT_POINT = 0,
        WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED = 1,
        WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED = 2
    };
    hkReal m_fSphereRadius;  // +0x10
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConvexShape[(sizeof(hkpConvexShape) == 0x14) ? 1 : -1];
#endif
