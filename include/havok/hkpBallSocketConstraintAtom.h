// include/havok/hkpBallSocketConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKPBALLSOCKETCONSTRAINTATOM_H
#define FNV_HAVOK_HKPBALLSOCKETCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpBallSocketConstraintAtom : public hkpConstraintAtom
{
  public:
    hkUint8 m_ucBodiesToNotify;  // +0x2
    hkUint8 m_solvingMethod;     // +0x3
    hkReal m_usFlags;            // +0x4
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpBallSocketConstraintAtom[(sizeof(hkpBallSocketConstraintAtom) == 0x8) ? 1 : -1];
#endif
