// include/havok/hkpBinaryAction.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPBINARYACTION_H
#define FNV_HAVOK_HKPBINARYACTION_H
#include "hkBase.h"
#include "hkpAction.h"
class hkpEntity;
#pragma pack(push, 1)
class hkpBinaryAction : public hkpAction
{
  public:
    hkpEntity* m_pEntityA;  // +0x18
    hkpEntity* m_pEntityB;  // +0x1C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpBinaryAction[(sizeof(hkpBinaryAction) == 0x20) ? 1 : -1];
#endif
