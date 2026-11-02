// bsaudio/bsgamesound_decls.h: declares MersenneTwister, BSGameSound, BSAudioManager, BSAudio
#ifndef FNV_BSGAMESOUND_DECLS_H
#define FNV_BSGAMESOUND_DECLS_H


class MersenneTwister
{
  public:
    MersenneTwister();
    unsigned int GetRandomUInt(unsigned int);
    static __forceinline MersenneTwister& GetRandomGenerator()
    {
        static MersenneTwister random;
        return random;
    }
};
class BSGameSound
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void Seek(unsigned int);
    unsigned int m_uiSoundResourceID;
    unsigned int m_uiSoundFlags;
    unsigned int m_uiSoundParameter11;
    unsigned int uiSoundFlags;
    int m_iSoundType;
    unsigned short m_uiSoundParameterA;
    unsigned short m_uiReverbAttenuation;
    unsigned short m_uiSoundParameterB;
    unsigned short m_uiSoundParameter6;
    unsigned short m_uiSoundParameter5;
    float m_fRolloff;
    float m_fMinimumDistance;
    float m_fMaximumDistance;
    unsigned int m_uiSoundCategory;
    unsigned short m_uiSoundParameter4;
    char pFilename[262];
    float afValueAfterThirdFloat;
    float afThirdFloatArgument;
    unsigned int m_uiSoundParameter12;
    unsigned int m_uiSoundParameter3;
    unsigned int m_uiSoundParameter13;
    float m_uiSoundParameter1;
    unsigned int m_uiSoundParameter7;
    unsigned char m_uiSoundParameter8;
    unsigned short m_uiSoundParameter10;
    unsigned int m_uiPlaybackId;
    unsigned int m_uiSoundParameter2;
    void(__cdecl* m_pfnBooleanCallback)(void*, bool);
    void(__cdecl* m_pfnIntegerCallback)(void*, int);
    void* m_pAudioSource;
    void* m_pAudioData;
    unsigned int m_uiSoundParameter9;
    unsigned int m_uiTrailingValue2;
    struct
    {
        float x, y, z;
    } m_kLocation;
    unsigned int iPriority;
    unsigned int m_kMessageList[3];

    void Copy(BSGameSound*, bool);
    bool Prepare();
    bool HasSoundFlagTwo();
    bool LoadFromFilename(bool);
    bool CanStartPlayback();
    bool HasMaster(const char*, bool);
    static unsigned int ComputeSoundNameHash(const char* pName);
};

class BSAudioManager
{
  public:
    char padding[0x180];
    unsigned int nextID;
    __forceinline unsigned int GetNextID()
    {
        return nextID++;
    }
    static BSAudioManager& GetRandomGenerator();
};
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
class BSAudio;
extern BSAudio* DAT_011f6d98;
class BSAudio
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    static inline BSAudio& GetRandomGenerator()
    {
        return *DAT_011f6d98;
    }
    virtual void vfn_18(char*);
    char padding[0x24];
    void(__cdecl* callback)(char*);
    inline void(__cdecl* GetCallback())(char*)
    {
        return callback;
    }
};
#endif
