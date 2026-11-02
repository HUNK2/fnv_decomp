// fallout/ai/combat/projectile_decls.h: declares PlayerCharacter, TESObjectREFR_LoadProxy, TESForm, TESChildCell, MobileObject and more
#ifndef PROJECTILE_DECLS_H
#define PROJECTILE_DECLS_H


class TESFile;

class PlayerCharacter
{
  public:
    bool IsSleepingOrResting();
};

class TESObjectREFR_LoadProxy
{
  public:
    bool Load(TESFile* file);
};

class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char padding[3];
    int eState;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
};

class TESForm
{
  public:
    virtual void Primary();
    char primaryData[0x14];
    void SetInitializationState(bool);
};
class TESChildCell
{
  public:
    virtual void Secondary();
};
class MobileObject : public TESForm, public TESChildCell
{
  public:
    MobileObject();
    ~MobileObject();
    char mobilePad[0x4c];
    unsigned int word68;
    char mobileTail[0x1c];
};
class InventoryStackRecord;
template <class T> class BSSimpleList
{
  public:
    BSSimpleList();
    ~BSSimpleList();
    unsigned int items[2];
};
class NiTransform
{
  public:
    NiTransform();
    void ResetToIdentity();
    char storage[0x34];
};
class NiPoint2
{
  public:
    NiPoint2();
    unsigned int data[2];
};
class NiPoint3
{
  public:
    static const NiPoint3 ZERO;
    unsigned int data[3];
};
class NiAVObject;
template <class T> class NiPointer
{
  public:
    NiPointer(T*);
    ~NiPointer();
    NiPointer& operator=(T*);
    T* value;
};
class ActorCause;
extern float DAT_01016970;
extern float DAT_01022958;
class Projectile : public MobileObject
{
  public:
    Projectile(bool);
    bool Load(TESFile*);
    bool IsProximityDetonationTriggered();
    virtual void Primary();
    virtual void Secondary();
    BSSimpleList<InventoryStackRecord*> list;
    unsigned char byte90;
    char pad91[3];
    NiTransform transform;
    unsigned int wordC8;
    float floatCC, floatD0, floatD4, floatD8, floatDC, floatE0;
    float floatE4, floatE8, floatEC, floatF0, floatF4;
    unsigned int wordF8, wordFC, word100;
    NiPoint2 position;
    float positionZ;
    float float110;
    NiPointer<NiAVObject> visualA;
    unsigned char byte118;
    char pad119[3];
    NiPointer<NiAVObject> visualB;
    NiPointer<ActorCause> cause;
    float float124;
    SoundPlaybackHandle soundA, soundB;
    unsigned int word140, word144;
    unsigned char byte148;
    char pad149[3];
    float float14C;
};
class FlameProjectile : public Projectile
{
  public:
    bool IsProximityDetonationTriggered();
};

class BSAudioManager
{
  public:
    static BSAudioManager& GetRandomGenerator();
    SoundPlaybackHandle FindSoundHandleByPath(const char* path, unsigned int flags, void* sound);
    SoundPlaybackHandle GetSoundHandleByFilePath(const char* path, unsigned int flags, void* sound);
};

#endif
