// bssystemutilities/bsdiscbootsystemutility_local.h: declares BSDiscBootSystemUtility
#ifndef FNV_BSDISCBOOTSYSTEMUTILITY_LOCAL_H
#define FNV_BSDISCBOOTSYSTEMUTILITY_LOCAL_H


#define FNV_BSDISCBOOTSYSTEMUTILITY_H
#include "layout_support.h"

#pragma pack(push, 4)
class BSDiscBootSystemUtility
{
  public:
    void** m_ppVirtualMethodTable;                 // +0x0
    char m_acTitleID[64];            // +0x4
    unsigned int m_uiParentalLevel;  // +0x44
    bool m_bNotificationActive;      // +0x48
    unsigned char layoutPadding49[3];
    void* m_pNotificationCallback;  // +0x4C

    void Destroy();
    void Initialize(const char* titleID, unsigned int parentalLevel);
};
#pragma pack(pop)

FNV_STATIC_ASSERT(sizeof(BSDiscBootSystemUtility) == 0x50);
FNV_STATIC_ASSERT(offsetof(BSDiscBootSystemUtility, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(BSDiscBootSystemUtility, m_acTitleID) == 0x4);
FNV_STATIC_ASSERT(offsetof(BSDiscBootSystemUtility, m_uiParentalLevel) == 0x44);
FNV_STATIC_ASSERT(offsetof(BSDiscBootSystemUtility, m_bNotificationActive) == 0x48);
FNV_STATIC_ASSERT(offsetof(BSDiscBootSystemUtility, m_pNotificationCallback) == 0x4C);

#endif
