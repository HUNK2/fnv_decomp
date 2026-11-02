#ifndef FNV_BSAUDIOSYNCHTIMER_H
#define FNV_BSAUDIOSYNCHTIMER_H

#include "layout_support.h"
#pragma pack(push, 4)
class BSAudioSyncTimer
{
  public:
    unsigned int m_uiValueAt00;  // +0x0
    unsigned int m_uiValueAt04;  // +0x4
    unsigned int iFlags;         // +0x8
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSAudioSyncTimer) == 0xC);
FNV_STATIC_ASSERT(offsetof(BSAudioSyncTimer, m_uiValueAt00) == 0x0);
FNV_STATIC_ASSERT(offsetof(BSAudioSyncTimer, m_uiValueAt04) == 0x4);
FNV_STATIC_ASSERT(offsetof(BSAudioSyncTimer, iFlags) == 0x8);
#endif
