// Source layout: BSCacheDriveSystemUtility. PC corrections are in generate_headers.py.
#ifndef FNV_BSCACHEDRIVESYSTEMUTILITY_H
#define FNV_BSCACHEDRIVESYSTEMUTILITY_H

#include "layout_support.h"
#pragma pack(push, 4)
class BSCacheDriveSystemUtility
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0
    bool bIsActive;   // +0x4
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    CACHEDRIVE_STATUS m_eDriveStatus;  // +0x8
    char m_acDrivePath[1055];          // +0xC
    unsigned char layoutPadding42B;
    void Destroy();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSCacheDriveSystemUtility) == 0x42C);
FNV_STATIC_ASSERT(offsetof(BSCacheDriveSystemUtility, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(BSCacheDriveSystemUtility, bIsActive) == 0x4);
FNV_STATIC_ASSERT(offsetof(BSCacheDriveSystemUtility, m_eDriveStatus) == 0x8);
FNV_STATIC_ASSERT(offsetof(BSCacheDriveSystemUtility, m_acDrivePath) == 0xC);
#endif
