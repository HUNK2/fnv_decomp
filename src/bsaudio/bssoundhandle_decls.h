// bsaudio/bssoundhandle_decls.h: declares BSAudio, BSAudioManager, SystemColorManager, SystemColor, HUDMainMenu
#ifndef FNV_BSSOUNDHANDLE_WORKER_DECLS_H
#define FNV_BSSOUNDHANDLE_WORKER_DECLS_H


typedef void(__cdecl* BSSoundCompletionCallback)(void*, bool);

class BSAudio;
extern BSAudio* DAT_011f6d98;

class BSAudio
{
  public:
    void** m_ppVirtualMethodTable;
    bool m_bAudioEnabled;

    __forceinline static BSAudio* GetRandomGenerator()
    {
        return DAT_011f6d98;
    }
    __forceinline bool IsAudioEnabled() const
    {
        return m_bAudioEnabled;
    }
};

class BSAudioManager
{
  public:
    static BSAudioManager& GetRandomGenerator();
    void FUN_00adbfd0(unsigned int, BSSoundCompletionCallback, void*);
    bool IsPlaying(unsigned int);
    bool FUN_00adb4e0(unsigned int, unsigned int, int);
    void SetPlaybackTime(unsigned int, unsigned int, unsigned int);
    bool SetPlaybackFrequency(unsigned int, float);
    bool IsSoundPlaying(unsigned int);
};

class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char layoutPadding5[3];
    enum ASSUMED_STATE
    {
        ASSUMED_STATE_INITIALIZED,
        ASSUMED_STATE_PLAYING,
        ASSUMED_STATE_STOPPED,
        ASSUMED_STATE_PAUSED
    } eState;

    void SetCompletionCallback(BSSoundCompletionCallback, void*);
    bool IsPlaying() const;
    bool SchedulePlayback(unsigned int, int);
    bool StopWithFade(unsigned int);
    bool SetPlaybackFrequency(float);
    bool IsValid() const;
};

class NiColor;

class SystemColorManager
{
  public:
    class SystemColor
    {
      public:
        void FUN_007193b0(NiColor&);
    };

    SystemColor* Find(int);
    bool GetColor(int, NiColor&);
};

class TESObjectREFR;

class HUDMainMenu
{
  public:
    char layoutPadding0_pad0[40];
    char m_pTiles[348];
    void* m_pAdditionalHudTile;
    float m_fMessageDisplayTimer;
    char m_kMessageList[8];
    unsigned int m_uiMessageCount;
    char m_kSubtitleArray[16];
    void* m_pCurrentSubtitle;
    char m_kTargetDisplayData[12];
    TESObjectREFR* m_pCrosshairReference;

    static HUDMainMenu* g_pHudMainMenuInstance;
    static bool UpdateTargetReference(TESObjectREFR*, bool, bool);
    static void RefreshTargetDisplay();
    int m_iHudValueFirstBeforeMode;
    int m_iHudValueSecondBeforeMode;
    int m_eHudMenuMode;
    char m_kMenuData[52];
    bool m_bHudModeActive;
    char _pdbpad_1fd[3];
    void* m_pHudAnimationSequence;
    bool m_bSequenceActive;
    bool m_bHudAnimationActive;
    char _pdbpad_206[2];
    unsigned int m_uiHudAnimationCounter;
    void* m_pRegionObjectListObj;
    int m_iHudValueFirstAfterUpdateList;
    int m_iHudValueSecondAfterUpdateList;
    int m_iHudValueThirdAfterUpdateList;
    void* m_pTargetActor;
    bool m_bTargetActorVisible;
    char _pdbpad_221[3];
    char m_cBuffer[32];
    unsigned int m_uiHudValueFirstAfterActor;
    unsigned int m_uiHudValueSecondAfterActor;
    int m_iHudValueFirstAfterUnsignedValues;
    int m_iHudValueSecondAfterUnsignedValues;
    bool m_bQuestObjectiveUpdatesEnabled;
    char _pdbpad_255[3];
    char m_kQuestObjectives[8];
    bool m_bQuestObjectiveUpdatePending;
    bool m_bXPUpdatePending;
    char _pdbpad_262[2];
    char m_kXPUpdates[8];
    char m_kRadiationUpdates[8];
    float m_fRadiationUpdateTimer;
};

#endif
