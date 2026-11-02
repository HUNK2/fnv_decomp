// include/havok/hkpSetLocalTransformsConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x90.
#ifndef FNV_HAVOK_HKPSETLOCALTRANSFORMSCONSTRAINTATOM_H
#define FNV_HAVOK_HKPSETLOCALTRANSFORMSCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpSetLocalTransformsConstraintAtom : public hkpConstraintAtom
{
  public:
    char pad2[0xE];
    hkTransform m_kBodyALocalFrame;  // +0x10
    hkTransform m_kBodyBLocalFrame;  // +0x50
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpSetLocalTransformsConstraintAtom[(sizeof(hkpSetLocalTransformsConstraintAtom) == 0x90) ? 1 : -1];
#endif
