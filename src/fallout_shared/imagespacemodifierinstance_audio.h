// fallout_shared/imagespacemodifierinstance_audio.h: declares NiPoint3, BSAudioManager, DialogMenuAudioCalls
#ifndef FNV_IMAGESPACEMODIFIERINSTANCE_AUDIO_H
#define FNV_IMAGESPACEMODIFIERINSTANCE_AUDIO_H

class NiPoint3
{
  public:
    float x, y, z;
    static const NiPoint3 ZERO;
};
FNV_STATIC_ASSERT(sizeof(NiPoint3) == 12);
enum SOUND_MSG
{
    SOUND_MSG_ENTER_DIALOGUE = 13
};
class BSAudioManager
{
  public:
    static BSAudioManager& GetRandomGenerator();
    void SendSoundMessage(SOUND_MSG, unsigned int, int, void*, NiPointer<NiAVObject>, NiPoint3);
};
class DialogMenuAudioCalls
{
  public:
    void EnableAudio();
};
#endif
