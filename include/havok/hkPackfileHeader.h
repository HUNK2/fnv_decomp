// include/havok/hkPackfileHeader.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x40.
#ifndef FNV_HAVOK_HKPACKFILEHEADER_H
#define FNV_HAVOK_HKPACKFILEHEADER_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkPackfileHeader
{
  public:
    hkInt32 m_kMagic[2];                        // +0x0
    hkInt32 m_uiUserTag;                        // +0x8
    hkInt32 m_iFileVersion;                     // +0xC
    hkUint8 m_aucLayoutRules[4];                // +0x10
    hkInt32 m_iNumSections;                     // +0x14
    hkInt32 m_iContentsSectionIndex;            // +0x18
    hkInt32 m_iContentsSectionOffset;           // +0x1C
    hkInt32 m_iContentsClassNameSectionIndex;   // +0x20
    hkInt32 m_iContentsClassNameSectionOffset;  // +0x24
    char m_acContentsVersion[16];               // +0x28
    hkInt32 m_auiShapeKeys[2];                           // +0x38
};
#pragma pack(pop)
typedef char fnv_hk_size_hkPackfileHeader[(sizeof(hkPackfileHeader) == 0x40) ? 1 : -1];
#endif
