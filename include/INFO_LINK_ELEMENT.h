// Source layout: INFO_LINK_ELEMENT. PC corrections are in generate_headers.py.
#ifndef FNV_INFO_LINK_ELEMENT_H
#define FNV_INFO_LINK_ELEMENT_H

#include "layout_support.h"
#pragma pack(push, 4)
class INFO_LINK_ELEMENT
{
  public:
    unsigned int nID;     // +0x0
    TESTopicInfo* pInfo;  // +0x4
    int m_iIndex;         // +0x8
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(INFO_LINK_ELEMENT) == 0xC);
FNV_STATIC_ASSERT(offsetof(INFO_LINK_ELEMENT, nID) == 0x0);
FNV_STATIC_ASSERT(offsetof(INFO_LINK_ELEMENT, pInfo) == 0x4);
FNV_STATIC_ASSERT(offsetof(INFO_LINK_ELEMENT, m_iIndex) == 0x8);
#endif
