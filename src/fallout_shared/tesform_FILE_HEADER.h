#ifndef FNV_UNIT_TESFORM_FILE_HEADER_H
#define FNV_UNIT_TESFORM_FILE_HEADER_H

#include "tesform_layout_support.h"
class TESFileHeader
{
  public:
    float m_fRecordValue;                 // +0x0
    unsigned int m_uiFileRecordTotal;     // +0x4
    unsigned int m_uiThirdUnsignedValue;  // +0x8
};
FNV_STATIC_ASSERT(sizeof(TESFileHeader) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESFileHeader, m_fRecordValue) == 0x0);
FNV_STATIC_ASSERT(offsetof(TESFileHeader, m_uiFileRecordTotal) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESFileHeader, m_uiThirdUnsignedValue) == 0x8);
#endif
