// fallout_shared/tesobjectmisc_decls.h: declares CombatProcedure, TESFileFormVersion, TESFile, BaseFormComponent, TESForm and more
#ifndef TESOBJECTMISC_DECLS_H
#define TESOBJECTMISC_DECLS_H


class CombatController;
class CombatProcedure
{
  public:
    void Initialize(CombatController*);
};
class TESFile;
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESFile : public TESFileFormVersion
{
  public:
    unsigned int GetChunkID();
    bool NextChunk();
    unsigned int GetChunkSize();
    bool GetChunkData(unsigned int* value);
    bool GetChunkData(void* buffer, unsigned int size);
};
enum ENUM_FORM_ID
{
    kFormIDCaravanMoney = 0x74
};

class BaseFormComponent
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};

class TESForm
{
  public:
    virtual void VSlot00();
    virtual void VSlot01();
    virtual void VSlot02();
    virtual void VSlot03();
    virtual void VSlot04();
    virtual void VSlot05();
    virtual void VSlot06();
    virtual void VSlot07();
    virtual void VSlot08();
    virtual void VSlot09();
    virtual void VSlot10();
    virtual void VSlot11();
    virtual void VSlot12();
    virtual void VSlot13();
    virtual void VSlot14();
    virtual void VSlot15();
    virtual void VSlot16();
    virtual void VSlot17();
    virtual void VSlot18();
    virtual void VSlot19();
    virtual void VSlot20();
    virtual void VSlot21();
    virtual void VSlot22();
    virtual void VSlot23();
    virtual void VSlot24();
    virtual void VSlot25();
    virtual void VSlot26();
    virtual void VSlot27();
    virtual void VSlot28();
    virtual void VSlot29();
    virtual void VSlot30();
    virtual void VSlot31();
    virtual void VSlot32();
    virtual void VSlot33();
    virtual void VSlot34();
    virtual void VSlot35();
    virtual void VSlot36();
    virtual void VSlot37();
    virtual void VSlot38();
    virtual void VSlot39();
    virtual void VSlot40();
    virtual void VSlot41();
    virtual void VSlot42();
    virtual void VSlot43();
    virtual void VSlot44();
    virtual void VSlot45();
    virtual void VSlot46();
    virtual void VSlot47();
    virtual void VSlot48();
    virtual void VSlot49();
    virtual void VSlot50();
    virtual void VSlot51();
    virtual void VSlot52();
    virtual void VSlot53();
    virtual void VSlot54();
    virtual void VSlot55();
    virtual void readOBNDSubRecord(TESFile* file);
    virtual void VSlot57();
    virtual void VSlot58();
    virtual void VSlot59();
    virtual void VSlot60();
    virtual void VSlot61();
    virtual void VSlot62();
    virtual void VSlot63();
    virtual void VSlot64();
    virtual void VSlot65();
    virtual void VSlot66();
    virtual void VSlot67();
    virtual void VSlot68();
    virtual void VSlot69();
    virtual void VSlot70();
    virtual void VSlot71();
    virtual void VSlot72();
    virtual void VSlot73();
    virtual void VSlot74();
    virtual void VSlot75();
    virtual const char* GetEditorID();
    virtual bool SetEditorID(const char* editorID);
    unsigned char formData[20];
    bool GetInitialized() const;
    void LoadRecordHeader(TESFile* file);
    TESFile* GetFile(int fileIndex);
    unsigned int GetFormID();
    void SetInitializationState(bool initialized);
    void SetFormType(ENUM_FORM_ID type);
    static void RemapFormIDForFile(unsigned int& formID, TESFile* file);
};

class TESSound : public TESForm
{
};
class Script;
class TESScriptableForm : public BaseFormComponent
{
  public:
    unsigned char data[8];
    void SetScript(Script* script);
    void InitItem(TESForm* form);
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    unsigned char data[4];
    void InitItem(TESForm* form);
    static void LoadDestructibleData(BGSDestructibleObjectForm* form, TESFile* file);
};
class TESModel : public BaseFormComponent
{
  public:
    unsigned char data[20];
    static void LoadModelData(TESModel* model, TESFile* file);
};
class TESModelTextureSwap : public TESModel
{
  public:
    unsigned char data[8];
    TESModelTextureSwap();
    ~TESModelTextureSwap();
    void InitItem(TESForm* form);
    bool ParseTextureSwapData(void* data, unsigned int size, unsigned int version);
};
class TESTexture : public BaseFormComponent
{
  public:
    unsigned char data[8];
};
class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon()
    {}
};
class TESFullName : public BaseFormComponent
{
  public:
    unsigned char data[8];
    TESFullName();
    ~TESFullName()
    {}
};
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* fullName, TESFile* file);
};
class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture* texture, TESFile* file);
};
class BGSMessageIcon : public BaseFormComponent
{
  public:
    unsigned char data[12];
    BGSMessageIcon();
    ~BGSMessageIcon();
    static void LoadMessageIconChunk(BGSMessageIcon* icon, TESFile* file);
};
class TESWeightForm : public BaseFormComponent
{
  public:
    unsigned char data[4];
};
class TESValueForm : public BaseFormComponent
{
  public:
    unsigned char data[4];
    TESValueForm();
    ~TESValueForm();
};
class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    unsigned char data[8];
    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();
    void InitItem(TESForm* form);
    void SetPickupSound(TESSound* sound);
};
class TESBoundObject : public TESForm
{
  public:
    unsigned char data[24];
    TESBoundObject();
    ~TESBoundObject();
};
class TESCaravanMoney : public TESBoundObject,
                        public TESFullName,
                        public TESModelTextureSwap,
                        public TESIcon,
                        public BGSMessageIcon,
                        public TESValueForm,
                        public BGSPickupPutdownSounds
{
  public:
    TESModelTextureSwap m_kModelTextureSwaps[2];
    TESCaravanMoney();
    virtual void Init();
    virtual void VSlot00();
    void ResetFormData();
};
class BGSImpactData
{
  public:
    void ReadTypedData(TESFile* file, void* data, unsigned short version);
    char _pdbpad_1[47];
    char Data_pad2f_pad2f_pad2f[24];
    void* m_pDecalTextureSet;
    void* m_pPrimaryImpactSound;
    void* m_pSecondaryImpactSound;
    char ImpactDecalInfo[36];
};
class TESLandTexture;
class TESRegionGrassObject
{
  public:
    void AssignLandTexture(TESLandTexture* texture);
};

class TESObjectMISC : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public BGSDestructibleObjectForm,
                      public BGSMessageIcon,
                      public BGSPickupPutdownSounds
{
  public:
    TESSound* pLoopingSound;
    void ResetFormData();
    void InitItem();
    bool Load(TESFile* file);
    void FUN_009db930(unsigned int value);
};

#endif
