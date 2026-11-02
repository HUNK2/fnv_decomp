// include/havok/hkPackfileSectionHeader.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKPACKFILESECTIONHEADER_H
#define FNV_HAVOK_HKPACKFILESECTIONHEADER_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkPackfileSectionHeader
{
  public:
    char m_acSectionTag[19];         // +0x0
    char m_cNullByte;                // +0x13
    hkInt32 m_iAbsoluteDataStart;    // +0x14
    hkInt32 m_iLocalFixupsOffset;    // +0x18
    hkInt32 m_iGlobalFixupsOffset;   // +0x1C
    hkInt32 m_iVirtualFixupsOffset;  // +0x20
    hkInt32 m_iExportsOffset;        // +0x24
    hkInt32 m_iImportsOffset;        // +0x28
    hkInt32 m_iEndOffset;            // +0x2C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkPackfileSectionHeader[(sizeof(hkPackfileSectionHeader) == 0x30) ? 1 : -1];
#endif
