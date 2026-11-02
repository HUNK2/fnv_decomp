// fallout/audio/falloutradio_private_decls.h: declares TESForm, TESObjectREFR, BGSLoadGameBuffer, FalloutRadio, RadioReceiver and more
#ifndef FALLOUTRADIO_PRIVATE_DECLS_H
#define FALLOUTRADIO_PRIVATE_DECLS_H


class DialoguePackage;
class DialogueItem;
class BGSPerkEntry;
class TESGrass;
class MediaSet;
class PerkButtonEntry;
class PlayerCharacter;
class TESSound;
class BGSTalkingActivator;

class TESForm
{
  public:
    virtual void FNV_type_anchor();
    static TESForm* GetFormByID(unsigned int);
};

class TESObjectREFR : public TESForm
{
};

class BGSLoadGameBuffer
{
  public:
    virtual unsigned char vfn_0();
};

union SETTING_VALUE
{
    unsigned int value;
};

enum MEDIATYPE
{
    MEDIATYPE_RADIO = 7
};

class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char padding[3];
    unsigned int eState;
    bool Stop();
    bool Release();
};

template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    bool IsEmpty();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsInList(T&);
    void Remove(const T&);
    void RemoveHead();
    void SetItem(const T&);
};

class FalloutRadio
{
  public:
    class RadioReceiver
    {
      public:
        void* form;
        SoundPlaybackHandle sound;
        char padding[12];
        unsigned char active;
        void* FUN_00832190(bool);
        void InitLoadGame(BGSLoadGameBuffer*);
    };

    class RadioConversation;

    class RadioStationState
    {
      public:
        void* form;
        char padding[24];
        BSSimpleList<RadioReceiver*> receivers;
        void InitLoadGame(BGSLoadGameBuffer*);
        void* FUN_00832160(bool);
    };

    static bool SetRadioEnabled(bool);
    static void RefreshRadioReceivers(bool);
    static bool Update(bool);
    static void UpdateRadioConversations(bool);
    static void InitLoadGame(BGSLoadGameBuffer*);
    static RadioConversation* GetRadioConversation(BGSTalkingActivator*);
    static void RadioSynchUnPaused();

  protected:
    static unsigned int ms_uiRadioSyncFlags;
};

class TeleportableReference
{
  public:
    void InitLoadGame(BGSLoadGameBuffer*);
};

class FalloutAudioMedia
{
  public:
    static void PlayMedia(MEDIATYPE, const char*, unsigned int, bool, bool, float, unsigned int);
    static void BeginMediaUpdate();
    static void EndMediaUpdate();
    static bool IsRadioPlaying();
};

class Interface
{
  public:
    static bool IsGamePaused();
};

class TimeGlobal
{
  public:
    unsigned int GetTimeStamp();
};

class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Int();
};

class LowProcess
{
  public:
    TESObjectREFR* GetTarget();
};

class TESObjectCELL
{
  public:
    bool IsCellInterior() const;
};

class TESDataHandler
{
  public:
    TESSound* GetSoundByEditorID(const char*);
};

extern unsigned int DAT_011dd42c;
extern bool DAT_011dd434;
extern unsigned char DAT_011dd436;
extern unsigned char DAT_011dd437;
extern SoundPlaybackHandle DAT_011dd5bc;
extern SoundPlaybackHandle DAT_011dd638;
extern BSSimpleList<FalloutRadio::RadioReceiver*> DAT_011dd58c;
extern BSSimpleList<FalloutRadio::RadioStationState*> DAT_011dd554;
extern BSSimpleList<unsigned int> DAT_011dd59c;
extern unsigned int DAT_011dd424;
extern unsigned char DAT_011dd435;
extern unsigned int DAT_011dd438;
extern unsigned int DAT_011dd43c;
extern unsigned int DAT_011dd430;
extern TESSound* DAT_011dd440;
extern SettingT_GameSettingCollection_ DAT_011dd5cc;
extern TimeGlobal g_timeGlobal;
extern PlayerCharacter* g_thePlayer;
extern TESDataHandler* g_dataHandler;
extern const char DAT_0107ce14[];

void FUN_008325a0(bool);

#endif
