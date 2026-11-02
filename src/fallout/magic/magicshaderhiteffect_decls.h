// fallout/magic/magicshaderhiteffect_decls.h: declares NiPoint3, NiBound, NiUpdateData, NiFixedString, CloningProcess and more
#ifndef MAGICSHADERHITEFFECT_DECLS_H
#define MAGICSHADERHITEFFECT_DECLS_H

class NiNode;
class NiAVObject;
class ActiveEffect;
class TESBoundObject;
class BaseProcess;
class MagicShaderHitEffect;
class BipedAnim;
class NiSourceTexture;
class NiTimeController;
class BGSDebris;
class BSShaderPPLightingProperty;
struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
    float ComputeMagnitude();
};
struct NiBound
{
    NiPoint3 center;
    float radius;
    NiPoint3& GetNavMeshData();
    float FUN_0084d030();
};
struct NiUpdateData
{
    float time;
    unsigned int flags;
    unsigned int unused;
    NiUpdateData(float, bool, bool);
};
template <class T> class NiPointer
{
  public:
    T* object;
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
    bool operator==(T*) const;
};
template <class T, int N = 1024> class BSSimpleArray
{
  public:
    unsigned int data[4];
    unsigned int GetSize();
    T& GetAt(int);
    void FUN_006c61b0(const T&);
    void RemoveAll(bool);
};
template <class T> class NiTArray
{
  public:
    unsigned int GetSize();
    T& GetAt(unsigned int);
};
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList* GetNext();
    bool IsEmpty();
};
class NiFixedString
{
    const char* str;

  public:
    NiFixedString(const char*);
    ~NiFixedString();
};
class CloningProcess
{
  public:
    unsigned int data[7];
    CloningProcess(float);
    ~CloningProcess();
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
class NiObjectNET : public NiMemObject
{
  public:
    virtual void vfn_0();
    NiTimeController* GetControllers() const;
    void SetName(const NiFixedString&);
};
class NiAVObject : public NiObjectNET
{
  public:
    virtual void vfn_4();
    virtual void vfn_8();
    virtual NiNode* IsSceneNode();
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
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void AddObject(NiAVObject*, bool);
    unsigned char layout[0xa8];
    NiNode* GetParent();
    bool FUN_00456610();
    void FUN_0043fa80(const void*);
    void FUN_00440490(float);
    void AssignParent(NiNode*);
    NiAVObject* CloneObject(CloningProcess&);
    NiBound& GetBoundingVolume();
    const NiPoint3& FUN_0045bb80();
    void Update(NiUpdateData&);
};
class NiNode : public NiAVObject
{
  public:
    NiNode(unsigned short);
};
class NiTimeController : public NiAVObject
{
  public:
    static void UpdateControllersForTarget(NiObjectNET*);
};
class TESForm
{
  public:
    virtual void vfn_0();
    unsigned int GetFormID();
};
class TESBoundObject : public TESForm
{
};
class TESObjectACTI : public TESBoundObject
{
};
class TESObjectWEAP : public TESBoundObject
{
};
class TESObjectREFR
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual bool IsActor();
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
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual BipedAnim* GetBipedAnim();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual const NiPoint3& GetPos();
    TESBoundObject* GetObjectReference();
};
class BaseProcess
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
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
    virtual bool vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void vfn_428();
    virtual void vfn_42c();
    virtual void vfn_430();
    virtual void vfn_434();
    virtual void vfn_438();
    virtual void vfn_43c();
    virtual void vfn_440();
    virtual void vfn_444();
    virtual void vfn_448();
    virtual void vfn_44c();
    virtual void vfn_450();
    virtual bool vfn_454();
};
class Actor : public TESObjectREFR
{
  public:
    BaseProcess* GetProcess();
    float FUN_008c4850();
    void GetLightIntensity(float);
    void UpdateActorPresentation();
};
class PlayerCharacter : public Actor
{
  public:
    int FUN_00490f80();
    MagicShaderHitEffect* GetField6A4();
    NiNode* GetNode(bool);
    BipedAnim* GetBipedAnimation(bool);
};
struct BipedObject
{
    unsigned int unknown[2];
    NiAVObject* object;
};
class BipedAnim
{
  public:
    BipedObject* FindEntry(TESBoundObject*);
};
class EffectSetting
{
  public:
    bool FUN_00403e60(unsigned int);
};
class ActiveEffect
{
  public:
    virtual void vfn_0();
    EffectSetting* GetEffectSetting();
    bool HasFlag(unsigned int);
    float GetAge();
};
class InventoryItem
{
  public:
    TESBoundObject* GetObject();
};
class DisintegrateArmorEffect : public ActiveEffect
{
  public:
    InventoryItem* GetItem();
};
class BGSTESTexture
{
  public:
    const char* GetTextureResourceName();
    unsigned int GetModelLength() const;
};
class ParticleShaderProperty
{
  public:
    NiTArray<NiPointer<NiAVObject> >& GetFieldAt11C();
    void FUN_00820b70(float);
    void SetByteAtOffset6C(int);
    void ClearField64();
    void FUN_00820b90();
    void DispatchRefOp(NiAVObject*);
    void SetParticleTime(float);
    void UpdateParticlesAtTime(float, bool, bool);
};
class ParticleShader
{
  public:
    static unsigned int GetShaderParticleCount();
};
class BSShaderPPLightingProperty
{
  public:
    class TextureEffectData
    {
      public:
        unsigned char data[0x6c];
        NiPointer<NiSourceTexture> spTexture;
    };
};
class TESEffectShader : public TESForm
{
  public:
    bool FUN_00507040(unsigned int);
    BGSTESTexture* GetFieldAt14C();
    BGSTESTexture* GetFieldAt158();
    BGSTESTexture* GetFieldAt164();
    float FUN_008d01e0();
    float FUN_00644930();
    float FUN_00567470();
    ParticleShaderProperty* CreateParticleShaderProperty(NiAVObject*, NiAVObject*, NiSourceTexture*, float);
    void FUN_00507810(NiAVObject*, ParticleShaderProperty*);
    BSShaderPPLightingProperty::TextureEffectData* CreateEffectData(NiAVObject*, NiSourceTexture*, NiSourceTexture*);
    void ApplyShaderToTree(NiAVObject*, BSShaderPPLightingProperty::TextureEffectData*);
    BGSDebris* GetAddonModels();
    char _pdbpad_4[20];
    char Data[308];
    char m_kFillTexture[12];
    char m_kParticleShaderTexture[12];
    char m_kHolesTexture[12];
};
struct DebrisModelEntry
{
    signed char chance;
    const char* filename;
};
class BGSDebris
{
  public:
    BSSimpleList<DebrisModelEntry*>* GetData();
};
template <class T> class WeightedResultList
{
  public:
    unsigned int data[9];
    WeightedResultList();
    ~WeightedResultList();
    void AddWeightedItem(T, unsigned int);
    T FindFirstItemExceedingRemaining();
};
class Model : public NiObjectNET
{
};
class ModelLoader
{
  public:
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
    void LoadModel(const char*, NiPointer<Model>&);
};
class TES
{
  public:
    void CreateTextureImage(const char*, NiPointer<NiSourceTexture>&, bool, bool);
};
class SoundPlaybackHandle
{
  public:
    unsigned int id;
    bool assumeSuccess;
    unsigned int state;
    ~SoundPlaybackHandle();
    bool SetPosition(float, float, float);
    bool SetVolume(float);
    bool Play(bool);
    void SetObjectToFollow(NiAVObject*);
};
class BSAudio
{
  public:
    static BSAudio* GetSingleton();
    SoundPlaybackHandle GetSoundHandleByEditorID(const char*, unsigned int);
};
class TaskQueueInterface
{
  public:
    static TaskQueueInterface* GetSingleton();
    void QueueTaskWithTwoObjects(NiAVObject*, NiNode*, bool, bool);
};
bool IsConditionMet();
float FUN_00404010(float, float);
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
extern PlayerCharacter* g_thePlayer;
extern ModelLoader* g_modelLoader;
extern TES* g_TES;
extern unsigned char DAT_011a9448;
class MagicShaderHitEffect
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    unsigned int refCount;
    float m_fParticleParameter5;
    void* pCell;
    float tempAge;
    bool bInitialized;
    ActiveEffect* pEffect;
    TESObjectREFR* pTarget;
    float m_fFirstFloatValue;
    bool bWasPlaying;
    unsigned char layoutPadding25[3];
    bool m_bUseActorParticleEffects;
    TESBoundObject* m_pAffectedArmorObject;
    TESEffectShader* m_pEffectShader;
    float m_fEffectShaderScale;
    BSSimpleArray<NiPointer<ParticleShaderProperty> > m_kParticleShaderProperties;
    NiPointer<NiNode> m_pParticleShaderNode;
    bool b3rdPerson;
    BSSimpleArray<NiPointer<NiAVObject> > m_kAddonModelObjects;
    float m_fAddonModelTimer;
    float m_fAddonModelScale;
    NiPointer<BSShaderPPLightingProperty::TextureEffectData> spTexEffectData;
    ActiveEffect* GetEffect();
    bool Init();
    void GetSceneGraphData(bool&, bool&, float&, NiAVObject*&, NiAVObject*&);
};
#endif
