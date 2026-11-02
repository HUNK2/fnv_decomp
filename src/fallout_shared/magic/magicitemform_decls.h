// fallout_shared/magic/magicitemform_decls.h: declares TESForm, MagicItemForm, MagicItem, TESFile, TESModel and more
#ifndef LUNA_MAGICITEMFORM_TASK_H
#define LUNA_MAGICITEMFORM_TASK_H


class TESFile;
class TESForm;
class EffectSetting;
class TESFullName;

class TESForm
{
  public:
    virtual void ComponentInit();                                // 0x000
    virtual void ComponentFree();                                // 0x004
    virtual void CopyFromBase(TESForm* form);                    // 0x008
    virtual bool CompareWithBase(TESForm* form);                 // 0x00C
    virtual ~TESForm();                                          // 0x010
    virtual void InitializeComponent();                          // 0x014
    virtual void ClearData();                                    // 0x018
    virtual bool Unk_07();                                       // 0x01C
    virtual bool Load(TESFile* file);                            // 0x020
    virtual bool Unk_09(void* arg);                              // 0x024
    virtual bool AppendForm(TESFile* file);                      // 0x028
    virtual void SaveForm();                                     // 0x02C
    virtual bool LoadForm2(TESFile* file);                       // 0x030
    virtual void WriteFormInfo(TESFile* file);                   // 0x034
    virtual bool Unk_0E(void* arg);                              // 0x038
    virtual bool Sort(TESForm* form);                            // 0x03C
    virtual TESForm* CreateForm(void* arg0, void* arg1);         // 0x040
    virtual void Unk_11(void* arg);                              // 0x044
    virtual void MarkAsModified(unsigned int flags);             // 0x048
    virtual void MarkAsUnmodified(unsigned int flags);           // 0x04C
    virtual unsigned int GetSaveSize(unsigned int flags);        // 0x050
    virtual void Unk_15(void* arg);                              // 0x054
    virtual void SaveGame(unsigned int flags);                   // 0x058
    virtual void LoadGame(void* arg);                            // 0x05C
    virtual void LoadGame2(unsigned int flags);                  // 0x060
    virtual void Unk_19(void* arg);                              // 0x064
    virtual void Unk_1A();                                       // 0x068
    virtual void Unk_1B(void* arg0, void* arg1);                 // 0x06C
    virtual void Revert(unsigned int flags);                     // 0x070
    virtual void Unk_1D(void* arg);                              // 0x074
    virtual void Unk_1E(void* arg);                              // 0x078
    virtual bool Unk_1F(void* arg);                              // 0x07C
    virtual void Unk_20(void* arg);                              // 0x080
    virtual void Unk_21(void* arg);                              // 0x084
    virtual void InitItem();                                     // 0x088
    virtual unsigned int GetTypeID();                            // 0x08C
    virtual void GetDebugName(void* dst);                        // 0x090
    virtual bool IsQuestItem();                                  // 0x094
    virtual bool Unk_26();                                       // 0x098
    virtual bool Unk_27();                                       // 0x09C
    virtual bool Unk_28();                                       // 0x0A0
    virtual bool Unk_29(bool set);                               // 0x0A4
    virtual bool Unk_2A(bool set);                               // 0x0A8
    virtual bool Unk_2B();                                       // 0x0AC
    virtual bool Unk_2C();                                       // 0x0B0
    virtual bool Unk_2D();                                       // 0x0B4
    virtual bool Unk_2E();                                       // 0x0B8
    virtual void Unk_2F(bool set);                               // 0x0BC
    virtual bool Unk_30();                                       // 0x0C0
    virtual void MarkForDeletion(bool set);                      // 0x0C4
    virtual void SetAltered(bool set);                           // 0x0C8
    virtual void SetQuestItem(bool set);                         // 0x0CC
    virtual void Unk_34(bool set);                               // 0x0D0
    virtual void Unk_35(bool set);                               // 0x0D4
    virtual void Unk_36(bool set);                               // 0x0D8
    virtual void Unk_37();                                       // 0x0DC
    virtual void readOBNDSubRecord(TESFile* file);               // 0x0E0
    virtual bool IsActor_InEditor();                             // 0x0E4
    virtual bool IsBoundObject();                                // 0x0E8
    virtual bool Unk_3B();                                       // 0x0EC
    virtual bool GetIsReference() const;                         // 0x0F0
    virtual bool Unk_3D();                                       // 0x0F4
    virtual bool Unk_3E();                                       // 0x0F8
    virtual bool IsMobileObject() const;                         // 0x0FC
    virtual bool IsActor();                                      // 0x100
    virtual unsigned int Unk_41();                               // 0x104
    virtual void CopyFrom(const TESForm* form);                  // 0x108
    virtual bool Compare(TESForm* form);                         // 0x10C
    virtual bool CheckFormGRUP(void* arg);                       // 0x110
    virtual void InitFormGRUP(void* dst, void* arg);             // 0x114
    virtual bool Unk_46();                                       // 0x118
    virtual bool Unk_47();                                       // 0x11C
    virtual bool Unk_48(unsigned int formType);                  // 0x120
    virtual bool Unk_49(void*, void*, void*, void*, void*);      // 0x124
    virtual void SetRefID(unsigned int refID, bool generateID);  // 0x128
    virtual char* GetName2();                                    // 0x12C
    virtual char* GetName() const;                               // 0x130
    virtual bool SetEditorID_AtRuntime(const char* editorID);    // 0x134

    bool GetInitialized() const;
    void SetInitializationState(bool initialized);
    unsigned int GetFormID();
    void LoadRecordHeader(TESFile* file);
};

class MagicItemForm : public TESForm
{
  public:
    virtual bool Load(TESFile* file);
    virtual void InitItem();
    virtual void Endian();
};

class MagicItem
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual unsigned int GetTypeSignature();
    virtual void* GetData();
    virtual unsigned int GetDataSize();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void LoadMagicItemChunk(TESFile* file, unsigned int chunkID);
    void LoadEffectsFromForm(TESForm* form);
};

class TESFile
{
  public:
    bool IsEndianConversionRequired();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void* data, unsigned int size);
    bool NextChunk();
};

class TESModel
{
  public:
    const char* GetModelFilePath();
};

class EffectItemList
{
  public:
    void Load(TESFile* file, const char* modelName);
};

class TESFullName
{
  public:
    const char* GetFullName();
};

class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* fullName, TESFile* file);
};

template <class T> class BSSimpleList
{
  public:
    unsigned int ItemsInList();
};

int Warning(const char* format, ...);
extern const char DAT_0101361c[];

#endif
