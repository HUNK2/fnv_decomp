// include/havok/hkpUnaryAction.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x1C.
#ifndef FNV_HAVOK_HKPUNARYACTION_H
#define FNV_HAVOK_HKPUNARYACTION_H

#include "hkBase.h"
#include "hkpAction.h"
class hkpEntity;
#pragma pack(push, 1)
class hkpUnaryAction : public hkpAction
{
  public:
    hkpEntity* m_pEntity;  // +0x18
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpUnaryAction[(sizeof(hkpUnaryAction) == 0x1C) ? 1 : -1];
#endif
