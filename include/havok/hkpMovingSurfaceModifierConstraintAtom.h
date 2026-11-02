// include/havok/hkpMovingSurfaceModifierConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPMOVINGSURFACEMODIFIERCONSTRAINTATOM_H
#define FNV_HAVOK_HKPMOVINGSURFACEMODIFIERCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpModifierConstraintAtom.h"
#pragma pack(push, 1)
class hkpMovingSurfaceModifierConstraintAtom : public hkpModifierConstraintAtom
{
  public:
    hkVector4 m_fVelocity;  // +0x20
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpMovingSurfaceModifierConstraintAtom[(sizeof(hkpMovingSurfaceModifierConstraintAtom) == 0x30)
                                                                    ? 1
                                                                    : -1];
#endif
