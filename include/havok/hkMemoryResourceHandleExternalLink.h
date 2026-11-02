// include/havok/hkMemoryResourceHandleExternalLink.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x8.
#ifndef FNV_HAVOK_HKMEMORYRESOURCEHANDLEEXTERNALLINK_H
#define FNV_HAVOK_HKMEMORYRESOURCEHANDLEEXTERNALLINK_H

#include "hkBase.h"
#pragma pack(push, 1)
class hkMemoryResourceHandleExternalLink
{
  public:
    hkStringPtr m_kLinkName;   // +0x0
    hkStringPtr m_kClassName;  // +0x4
};
#pragma pack(pop)
typedef char
    fnv_hk_size_hkMemoryResourceHandleExternalLink[(sizeof(hkMemoryResourceHandleExternalLink) == 0x8) ? 1 : -1];
#endif
