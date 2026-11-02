// include/havok/hkpShapePhantom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x160.
#ifndef FNV_HAVOK_HKPSHAPEPHANTOM_H
#define FNV_HAVOK_HKPSHAPEPHANTOM_H

#include "hkBase.h"
#include "hkMotionState.h"
#include "hkpPhantom.h"
#pragma pack(push, 1)
class hkpShapePhantom : public hkpPhantom
{
  public:
    char padA4[0xC];
    hkMotionState m_kMotionState;  // +0xB0
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpShapePhantom[(sizeof(hkpShapePhantom) == 0x160) ? 1 : -1];
#endif
