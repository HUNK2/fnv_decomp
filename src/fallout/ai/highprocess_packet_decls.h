
union SETTING_VALUE
{
    float f;
};
class GameSettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting244;
enum ACTOR_SOUND_HANDLE
{
    ActorSoundVoice = 0
};
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;
    SoundPlaybackHandle(const SoundPlaybackHandle& other);
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle&);
    ~SoundPlaybackHandle();
};
