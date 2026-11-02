// fallout_shared/bgsbodypart_decls.h: declares TESFileFormVersion, TESFile, TESForm, BGSExplosion, BGSDebris and more
#ifndef FNV_BGSBODYPART_DECLS_H
#define FNV_BGSBODYPART_DECLS_H


extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)
int Warning(const char*, ...);
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESFile
{
  public:
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool NextChunk();
    bool GetChunkData(void*, unsigned int);
    bool IsEndianConversionRequired();
};
class TESFile;
class TESForm
{
  public:
    virtual ~TESForm();
    bool GetInitialized() const;
    TESFile* GetFile(int);
    static void RemapFormIDForFile(unsigned int&, TESFile*);
    static TESForm* GetFormByID(unsigned int);
};
class BGSExplosion : public TESForm
{
};
class BGSDebris : public TESForm
{
};
class BGSImpactDataSet : public TESForm
{
};
class TESObjectREFR;
class DialogueItem
{
  public:
    TESObjectREFR* SelectDefaultResponseList();
};
class BaseProcess;
class Actor
{
  public:
    BaseProcess* GetProcess();
};
class TESSound;
class TESEffectShader;
class EffectSetting
{
  public:
    TESSound* GetCastSound();
    TESEffectShader* GetEnchantEffectShader();
};
class Tile;
class InterfaceManager
{
  public:
    Tile* FUN_004fd400();
    void FUN_00500a20(Tile*);
};
enum IO_TASK_PRIORITY
{
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_CRITICAL = 0,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_VERY_HIGH = 1,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_HIGH = 2,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_MID = 3,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_LOW = 4,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_VERY_LOW = 5,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_COUNT = 6,
    IO_TASK_PRIORITY_IO_TASK_PRIORITY_INVALID = 7
};

class QueuedFile;
class NiPoint3
{
  public:
    float x;
    float y;
    float z;
};
extern "C" NiPoint3 NiPoint3_ZERO;

class BodyPartInfo
{
  public:
    BodyPartInfo();
    void SwapEndianFields();
    float m_fDamageMultiplier;
    unsigned char cFlags;
    unsigned char cType;
    unsigned char m_ucPartID;
    char m_cActorValue;
    unsigned char m_ucHealthPercent;
    unsigned char m_ucHitChance;
    unsigned char m_ucLimbReplacementType;
    unsigned char layoutPaddingB;
    void* m_pExplosion;
    void* m_pDebrisObject;
    float m_fExplosionChance;
    float m_fDebrisScale;
    unsigned char m_ucSeverable;
    unsigned char layoutPadding1D[3];
    void* m_pRelatedObject1;
    void* m_pRelatedObject2;
    float m_fValue3;
    NiPoint3 m_kPoint1;
    NiPoint3 m_kPoint2;
    void* m_pRelatedObject3;
    void* m_pRelatedObject4;
    unsigned char m_ucByte1;
    unsigned char m_ucByte2;
    unsigned char layoutPadding4E[2];
    float m_fValue4;

    void Initialize();
};

class TESModel
{
  public:
    unsigned char storage[20];
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18(const char*);
    static void LoadModelData(TESModel*, TESFile*);
    static void LoadTextureSwapData(TESModel*, TESFile*);
    TESModel();
    ~TESModel();
    unsigned int GetModelLength() const;
};

class ModelLoader
{
  public:
    void ProcessModelRequest(TESModel*, int, QueuedFile*, bool, bool, bool, bool);
};
extern ModelLoader* g_modelLoader;

template <class T> class BSStringT
{
  public:
    T* data;
    unsigned short length, capacity;
    BSStringT();
    ~BSStringT();
    bool Set(const T*, unsigned int);
};
class FUN_005e3be0
{
  public:
    unsigned char storage[24];
    FUN_005e3be0();
    ~FUN_005e3be0();
};
extern "C" void* memset(void*, int, unsigned int);

class BGSBodyPart
{
  public:
    BSStringT<char> NodeName;
    BSStringT<char> TargetName;
    BSStringT<char> m_kVATSNodeName;
    BSStringT<char> m_kPartName;
    BSStringT<char> m_kGoreName;
    TESModel m_kModel;
    FUN_005e3be0 m_kRagdollModel;
    BodyPartInfo Data;

    BGSBodyPart();
    void InitItem(TESForm*);
    bool Load(TESFile*);
    unsigned int FUN_005e3fc0();
    void FUN_00994ef0(BGSImpactDataSet*);
    void FUN_005e3d20();
    virtual void vfn_00();
    void QueueResourceLoad(IO_TASK_PRIORITY, QueuedFile*);
};

class Queueable18
{
  public:
    virtual void Slot0() = 0;
    virtual void Slot1() = 0;
    virtual void Slot2() = 0;
    virtual void Slot3() = 0;
    virtual void QueueResourceLoad(IO_TASK_PRIORITY, QueuedFile*) = 0;
};

#endif
