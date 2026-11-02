#ifndef FNV_UNIT_TESFORM_FORM_H
#define FNV_UNIT_TESFORM_FORM_H

#include "tesform_layout_support.h"
class FormRecordHeader
{
  public:
    unsigned int form;                    // +0x0
    unsigned int length;                  // +0x4
    unsigned int flags;                   // +0x8
    unsigned int iFormID;                 // +0xC
    unsigned int m_uiVersionControlInfo;  // +0x10
    unsigned short m_usFormVersion;       // +0x14
    unsigned short m_usHeaderUnknown;     // +0x16
};
FNV_STATIC_ASSERT(sizeof(FormRecordHeader) == 0x18);
FNV_STATIC_ASSERT(offsetof(FormRecordHeader, form) == 0x0);
FNV_STATIC_ASSERT(offsetof(FormRecordHeader, length) == 0x4);
FNV_STATIC_ASSERT(offsetof(FormRecordHeader, flags) == 0x8);
FNV_STATIC_ASSERT(offsetof(FormRecordHeader, iFormID) == 0xC);
FNV_STATIC_ASSERT(offsetof(FormRecordHeader, m_uiVersionControlInfo) == 0x10);
FNV_STATIC_ASSERT(offsetof(FormRecordHeader, m_usFormVersion) == 0x14);
FNV_STATIC_ASSERT(offsetof(FormRecordHeader, m_usHeaderUnknown) == 0x16);
#endif
