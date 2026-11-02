// fallout/audio/falloutaudiomedia_decls.h: declares BGSMusicType, StartMenu, FORenderedMenu, TESLandTexture, FalloutAudioMedia and more
#ifndef FALLOUTAUDIOMEDIA_DECLS_H
#define FALLOUTAUDIOMEDIA_DECLS_H


class BGSMusicType
{
  public:
    bool FUN_00830050();
    float FUN_00830080();
    const char* GetRandomEntry();
};

enum MEDIATYPE
{
    kMediaType_Music = 6,
    kMediaType_Radio = 7
};

class StartMenu
{
  public:
    static void UpdateMedia();
};

class FORenderedMenu
{
  public:
    unsigned int GetCurrentTimeMilliseconds();
    char _pdbpad_1[3];
    char spScreenTriShape_pad3_pad3[4];
    char spScreenParent_pad7_pad7[4];
    char spPartialScreenGeometry_padb_padb[4];
    char spDefaultTex_padf_padf[4];
    char spMenuRoot_pad13_pad13[4];
    void* m_pFourthMenuObject;
    char m_pMenuLight[4];
    void* m_pSecondaryMenuObject;
    char m_pMenuLightParameters[4];
    bool bInitialized;
    bool m_bUseMenuImageSpaceEffects;
    bool m_bEnableFlicker;
    char _pdbpad_2b[1];
    char m_kScreenLightColor[12];
    float fScreenLightBaseIntensity;
    float m_fFlicker;
    float fBlurRadius;
    float fBlurIntensity;
    float m_fScanlineScale;
    bool m_bDoScanlines;
    bool m_bBurstActive;
    char _pdbpad_4e[2];
    float m_fBurstElapsedTime;
    float fBurstDuration;
    float m_fBurstIntensity;
    float m_fBurstSoundChance;
    bool m_bBurstSoundPlayed;
    char _pdbpad_61[3];
    float m_fShudderIntensity;
    float m_fShudderDuration;
    float m_fShudderFrequency;
    float m_fVerticalHoldDuration;
    bool m_bVerticalHoldActive;
    char _pdbpad_75[3];
    float m_fVerticalHoldSpeed;
    float m_fVerticalHoldRate;
    float m_fVerticalHoldChance;
    float m_fShudderChance;
    float m_fPulseRadiusIntensity;
    float m_fPulseBrightenIntensity;
    float m_fPulseRate;
    bool m_bPulseActive;
    bool m_bShudderActive;
    char _pdbpad_96[2];
    float m_fDistortHorizontalScale;
    float m_fDistortVerticalScale;
    float fDistortDuration;
    float m_fDistortTimeRemaining;
    char BackgroundColor[16];
    bool m_bMenuLightEnabled;
    bool m_bMenuLightCreated;
    char _pdbpad_ba[2];
    char m_pMenuLightShadowNode[4];
    char m_kMenuLightColor[16];
    bool m_bMenuLightVisible;
    bool m_bMenuLightShadowed;
    bool m_bMenuLightAttached;
    char _pdbpad_d3[1];
    char m_pMenuLightNode[4];
};

class TESLandTexture
{
  public:
    static void* GetSoundSystem();
};

unsigned long GetCurrentThreadId();
void FUN_00830490();

extern char DAT_011dd310;
extern char DAT_011dd311;
extern unsigned char DAT_011dd313;
extern unsigned long DAT_011dd314;
extern unsigned long DAT_011dd334;
extern unsigned long DAT_011dd348;
extern unsigned long DAT_011dd368;
extern float DAT_011dd300;
extern float DAT_011dd304;
extern float DAT_011dd308;
extern unsigned long DAT_011dd328;
extern unsigned long DAT_011dd32c;
extern float DAT_011dd338;
extern float DAT_011dd33c;
extern float DAT_011dd340;
extern unsigned long DAT_011dd35c;
extern unsigned long DAT_011dd360;
class FalloutAudioMedia
{
  public:
    static void BeginMediaUpdate();
    static void EndMediaUpdate();
    static void FadeOutMedia(int, MEDIATYPE);
    static void PlayMedia(BGSMusicType*);
    static void PlayMedia(MEDIATYPE, const char*, unsigned int, bool, bool, float, unsigned int);
    static char IsRadioPlaying();
    static bool IsMediaPlaying(MEDIATYPE, bool);
    static void Startup();
    static void Update();
};

namespace fnv_anon_falloutaudiomedia {}
using namespace fnv_anon_falloutaudiomedia;
namespace fnv_anon_falloutaudiomedia {
class FAMThread
{
  public:
    char inheritedPadding[0x34];
    unsigned int threadID;
    unsigned int parentID;
    unsigned int state;
    void* event;

    void WaitForThread();
    unsigned int ThreadProc();
};
}

void EnsureArenaAllocated(void*);
void RunAudioChannel(void*);
void FUN_00c80240(void*);

#endif
