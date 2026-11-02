// include/havok/hkpSetLocalTranslationsConstraintAtom.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPSETLOCALTRANSLATIONSCONSTRAINTATOM_H
#define FNV_HAVOK_HKPSETLOCALTRANSLATIONSCONSTRAINTATOM_H

#include "hkBase.h"
#include "hkpConstraintAtom.h"
#pragma pack(push, 1)
class hkpSetLocalTranslationsConstraintAtom : public hkpConstraintAtom
{
  public:
    char pad2[0xE];
    hkVector4 m_kTranslationA;  // +0x10
    hkVector4 m_kTranslationB;  // +0x20
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkpSetLocalTranslationsConstraintAtom[(sizeof(hkpSetLocalTranslationsConstraintAtom) == 0x30) ? 1 : -1];
#endif
