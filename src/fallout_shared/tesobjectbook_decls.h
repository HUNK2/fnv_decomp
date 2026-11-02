// fallout_shared/tesobjectbook_decls.h: declares TESFormInitFlag, TESForm, TESBoundObject, BaseFormComponent, BookString and more
#ifndef FNV_TESOBJECTBOOK_DECLS_H
#define FNV_TESOBJECTBOOK_DECLS_H

#include <malloc.h>
enum ENUM_FORM_ID
{
    FORM_MISC = 0x1f
};
class TESFile;
class TESForm;
class MagicItem;
class Script;
class EnchantmentItem;
class TESSound;
class TESFormList;
class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};
class TESForm
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual ~TESForm();
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
    virtual void readOBNDSubRecord(TESFile* file);
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
    virtual bool LoadEditorID(const char* editorID);
    unsigned char m_eReferenceTypeInfo;
    unsigned char formPadding[3];
    unsigned int formFlags;
    unsigned int formID;
    void* mods[2];
    void SetInitializationState(bool initialized);
    void SetFormType(enum ENUM_FORM_ID type);
    void LoadRecordHeader(TESFile* file);
    void ReadTypedData(TESFile* file, void* data, unsigned short size);
};
class TESBoundObject : public TESForm
{
  public:
    TESBoundObject();
    ~TESBoundObject();
    TESFormList* parentList;
    TESBoundObject* previous;
    TESBoundObject* next;
    short bounds[6];
};
class BaseFormComponent
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* source);
    virtual bool CompareWithBase(BaseFormComponent* source);
};
struct BookString
{
    char* text;
    unsigned short length;
    unsigned short capacity;
};
class TESFullName : public BaseFormComponent
{
  public:
    TESFullName();
    ~TESFullName();
    BookString name;
};
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName*, TESFile*);
};
class TESModel : public BaseFormComponent
{
  public:
    BookString modelName;
    float boundSize;
    void* textureHashes;
    unsigned char flags;
    static void LoadModelData(TESModel*, TESFile*);
};
class TESModelTextureSwap : public TESModel
{
  public:
    TESModelTextureSwap();
    ~TESModelTextureSwap();
    void* textureSwapList[2];
    void InitItem(TESForm* form);
    bool ParseTextureSwapData(void*, unsigned int, unsigned int);
};
class TESTexture : public BaseFormComponent
{
  public:
    BookString textureName;
    static void ReadTextureData(TESTexture*, TESFile*);
};
class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};
class TESScriptableForm : public BaseFormComponent
{
  public:
    TESScriptableForm();
    Script* script;
    bool resolved;
    void InitItem(TESForm* form);
    void SetScript(Script* script);
};
class TESEnchantableForm : public BaseFormComponent
{
  public:
    EnchantmentItem* enchantment;
    unsigned short enchantmentAmount;
    unsigned int castingType;
    void InitItem(TESForm* form);
    void SetFormEnchanting(EnchantmentItem*);
    void SetFormEnchantmentAmount(unsigned short);
};
class TESValueForm : public BaseFormComponent
{
  public:
    TESValueForm();
    ~TESValueForm();
    unsigned int value;
};
class TESWeightForm : public BaseFormComponent
{
  public:
    TESWeightForm();
    ~TESWeightForm();
    float weight;
};
class TESDescription : public BaseFormComponent
{
  public:
    unsigned int fileOffset;
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();
    void* destructionData;
    void InitItem(TESForm* form);
    static void LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
};
class BGSMessageIcon : public BaseFormComponent
{
  public:
    BGSMessageIcon();
    ~BGSMessageIcon();
    TESIcon icon;
    static void LoadMessageIconChunk(BGSMessageIcon*, TESFile*);
};
class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();
    TESSound* pickupSound;
    TESSound* putdownSound;
    void InitItem(TESForm* form);
    void SetPickupSound(TESSound*);
    void SetPutdownSound(TESSound*);
};
class MagicCaster
{
  public:
    void SetSelectedMagicItem(MagicItem* spell);
};
namespace ActorValue {
enum Index
{
    kIndexPlaceholder = 0
};
enum Section
{
    kSectionBook = 2
};
Index __cdecl GetActorValueForSectionIndex(Section section, unsigned char index);
}
extern "C" void* __cdecl memset(void*, int, unsigned int);
class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool NextChunk();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData(unsigned int*);
};
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESFileChunkData16
{
  public:
    bool GetChunkData(unsigned short*);
};
struct BookData
{
    unsigned char flags;
    signed char teaches;
};
class TESObjectBOOK : public TESBoundObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESIcon,
                      public TESScriptableForm,
                      public TESEnchantableForm,
                      public TESValueForm,
                      public TESWeightForm,
                      public TESDescription,
                      public BGSDestructibleObjectForm,
                      public BGSMessageIcon,
                      public BGSPickupPutdownSounds
{
  public:
    BookData Data;
    void ResetFormData();
    void InitItem();
    bool Load(TESFile*);
};
// This covered constructor span has MISC bases, vtables and form type.
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
    TESSound* loopingSound;
    TESObjectMISC();
    void ResetFormData();
};
#endif
