#ifndef FNV_BSSOUNDHANDLE_H
#define FNV_BSSOUNDHANDLE_H

#include "statsmenu_layout_support.h"
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;  // +0x0
    bool m_bLooping;        // +0x4
    unsigned char layoutPadding5[3];
    BSSoundHandle__ASSUMED_STATE eState;  // +0x8
};
FNV_STATIC_ASSERT(sizeof(SoundPlaybackHandle) == 0xC);
FNV_STATIC_ASSERT(offsetof(SoundPlaybackHandle, m_uiSoundResourceID) == 0x0);
FNV_STATIC_ASSERT(offsetof(SoundPlaybackHandle, m_bLooping) == 0x4);
FNV_STATIC_ASSERT(offsetof(SoundPlaybackHandle, eState) == 0x8);
#endif
