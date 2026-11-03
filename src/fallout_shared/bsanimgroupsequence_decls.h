// fallout_shared/bsanimgroupsequence_decls.h: declares NiFixedString, NiPoint3, NiRTTI, BGSCameraPath, AnimationInterpolatorNode and more
#ifndef BSANIMGROUPSEQUENCE_DECLS_H
#define BSANIMGROUPSEQUENCE_DECLS_H

class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
    operator const char*() const;
};
class NiPoint3
{
  public:
    float x, y, z;
    static const NiPoint3 ZERO;
};
class NiRTTI
{
  public:
    const char* name;
    const NiRTTI* parent;
};
class GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_012031b8;
extern const NiRTTI DAT_011f36bc;
class BGSCameraPath
{
  public:
    BGSCameraPath* GetPrevPath();
};
class AnimationInterpolatorNode
{
  public:
    void UpdateInterpolatorsAtTime(float, bool);
};
class NiTimeController;
class NiAVObject
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
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual NiAVObject* GetObjectByName(const NiFixedString&);
    const NiPoint3& FUN_0045bb80() const;
    void FUN_004ef970(bool);
    NiTimeController* GetController(const NiRTTI*);
    class NiNode* GetParent();
};
class NiNode : public NiAVObject
{
};
class TESObjectREFR
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiNode* GetNiNode_v();
    float GetScale();
};
class PlayerCharacter : public TESObjectREFR
{
  public:
    void ApplyHitShaderToReference(TESObjectREFR*);
};
extern PlayerCharacter* g_thePlayer;
class TESForm
{
  public:
    unsigned int GetFormID();
};
class TESSound : public TESForm
{
  public:
    struct SoundPlaybackParameters
    {
        unsigned char iMin, iMax;
        signed char m_cPitchAdjustment;
        unsigned char m_ucUnused;
        unsigned int iFlags;
        unsigned short m_uiFrequency;
        unsigned char m_aucAttenuationBytes[2];
        unsigned short m_auiAttenuationCurve[5];
        unsigned short m_uiReverbAttenuation;
        unsigned int iPriority, m_uiTrailingValue1, m_uiTrailingValue2;
    };
    SoundPlaybackParameters CopyBig();
    static unsigned int GetPlaybackFlags(unsigned int);
};
class TESDataHandler
{
  public:
    TESSound* GetSoundByEditorID(const char*);
};
extern TESDataHandler* g_dataHandler;
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle&);
    bool SetObjectToFollow(NiAVObject*);
    bool SetPosition(float, float, float);
    bool Play(bool);
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    SoundPlaybackHandle GetSoundHandleByFormID(unsigned int, unsigned int);
    void FUN_00ad8570(NiAVObject*, float, unsigned int);
};
class SoundPlaybackManager
{
  public:
    static bool CanPlaySoundAt(TESSound*, NiPoint3, float);
};
class TimedTextEntry
{
  public:
    float m_fTime;
    NiFixedString m_kText;
};
class NiTextKeyExtraData
{
  public:
    TimedTextEntry* FUN_00495f30(unsigned int*);
};
class LowProcess
{
  public:
    TESObjectREFR* GetActiveCombatTarget();
};
class ActorMover
{
  public:
    unsigned int GetCurrentMoveModeType();
};
class PerkEntryConditionSet;
class TESTopic;
class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
};
class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*>* GetLinkToList();
};
class PlayerQuestData
{
  public:
    PerkEntryConditionSet* GetConditions();
};
class RegionPoint
{
  public:
    float GetX();
};
class NiControllerSequence
{
  public:
    struct InterpArrayItem
    {
        char fields[13];
        unsigned char m_ucArrayItemID;
        char trailing[2];
    };
    struct IDTag
    {
        char fields[20];
    };
    char objectHeader[8];
    NiFixedString m_kName;
    unsigned int m_uiNumControlledBlocks, m_uiNumIDTags;
    InterpArrayItem* m_pInterpArray;
    IDTag* m_pkIDTags;
    float m_fWeight;
    void* m_spTextKeyData;
    int m_eAnimationCycleType;
    float m_fFrequency, m_fFirstKeyTime, m_fLastKeyTime;
    float m_fLastTime, m_fWeightAdjustedLastTime, m_fScaledLastTime;
    void* m_pkOwnerManager;
    int m_eAnimationState;
    float m_fSequenceOffset, m_fStartTime, m_fEndTime, m_fDestinationFrame;
    NiControllerSequence* m_pkTimeSyncSequence;
    NiFixedString m_kAccumulationRootName;
    NiAVObject* m_pkAccumulationRoot;
    void* m_spStringPalette;
    short m_sAnimNotesExtraDataIndex;
    void* m_pkAnimNotes;
    unsigned short m_usNumAnimNotes;
    bool m_bHasAnimNotes;
    float GetField4C();
    float FUN_00508100();
    float NiControllerSequence_GetOffset();
    NiTextKeyExtraData* FUN_00700300();
    bool Deactivate(float, bool);
};
class TESAnimGroup
{
  public:
    unsigned int GetType();
};
template <class T> class NiPointer
{
  public:
    T* p;
    T* operator->() const;
};
class BSAnimGroupSequence : public NiControllerSequence
{
  public:
    NiPointer<NiNode> m_spAnimGroup;
    static bool PlayAnimSounds(NiControllerSequence*, TESObjectREFR*);
    unsigned char GetPriority(const char*, unsigned int*);
    bool Deactivate(float, bool);
};
extern const float DAT_01023850;
const NiFixedString& FUN_004ef990();
extern "C" int _strnicmp(const char*, const char*, unsigned int);
int FUN_00404dc0(const char*, const char*);
extern "C" char* strchr(const char*, int);
extern "C" char* __insecure_strcpy(char*, const char*);
int Warning(const char*, ...);
#endif
