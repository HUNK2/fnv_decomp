#ifndef FNV_BSSOUNDHANDLE_H
#define FNV_BSSOUNDHANDLE_H

#include "layout_support.h"
class NiAVObject;
#pragma pack(push, 4)
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;                // +0x0
    bool m_bLooping;                      // +0x4
    BSSoundHandle__ASSUMED_STATE eState;  // +0x8
    SoundPlaybackHandle();
    SoundPlaybackHandle(const SoundPlaybackHandle& other);
    ~SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle& other);
    bool SetPosition(float x, float y, float z);
    void SetObjectToFollow(NiAVObject* object);
    bool SetVolume(float volume);
    bool Play(bool loop);
    bool Stop();
    bool IsSoundPlaying();
    bool PausePlayback();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SoundPlaybackHandle) == 0xC);
FNV_STATIC_ASSERT(offsetof(SoundPlaybackHandle, m_uiSoundResourceID) == 0x0);
FNV_STATIC_ASSERT(offsetof(SoundPlaybackHandle, m_bLooping) == 0x4);
FNV_STATIC_ASSERT(offsetof(SoundPlaybackHandle, eState) == 0x8);
#endif
