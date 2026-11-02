// fallout_shared/tesleveledlist_decls.h: declares BSFile, BaseProcess, HighProcess, bhkLiquidAction, TESFile and more
#ifndef FNV_TESLEVELEDLIST_WORKER_DECLS_H
#define FNV_TESLEVELEDLIST_WORKER_DECLS_H


class BSFile
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14(unsigned int, unsigned int);
};
class BaseProcess
{
  public:
    enum POSTANIM_ACTION
    {
        POSTANIM_NONE
    };
};
class HighProcess
{
  public:
    BaseProcess::POSTANIM_ACTION GetPostAnimationAction();
};
class bhkLiquidAction
{
  public:
    unsigned int GetInstanceSize();
};
extern unsigned int DAT_010a2480;
class TESFile
{
  public:
    unsigned char prefix[0x10];
    BSFile* m_pFile;
    unsigned char layoutToCurrentForm[0x22c];
    struct FormRecord
    {
        unsigned int form, length, flags, id, version, control;
    } m_kRecordInfo;
    unsigned int m_eChunkID;
    unsigned int m_uiChunkSize;
    unsigned int m_uiChunkOffset;
    unsigned int m_uiRecordSize;
    unsigned int m_uiRecordOffset;
    unsigned int m_uiCurrentOffset;
    bool NextChunk();
    bool IsCurrentFormCompressed();
    void FUN_004720d0();
    unsigned int GetChunkID();
};
class TESForm
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
    virtual bool Unk_39();
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
    virtual const char* GetEditorID();
    TESFile* GetFile(int);
    unsigned int GetFormID();
    static TESForm* GetFormByID(unsigned int);
    static void RemapFormIDForFile(unsigned int&, TESFile*);
};
class ContainerItemExtra
{
  public:
    unsigned int data[3];
    ContainerItemExtra();
    void FUN_0040eb90(float);
    void InitItem(TESForm*);
};
class TESContainer;
class LeveledObject;

class ExtraDataList
{
  public:
    void GetLeveledItemData(float& multiplier, int& count);
};

class TESObjectREFR
{
  public:
    ExtraDataList* GetExtraData();
    unsigned int GetReferenceLevel(bool allowShift);
};

class FormChangeMask
{
  public:
    unsigned int raw;
    operator bool() const;
};

class BGSLoadFormBuffer
{
  public:
    virtual void vfn_0();
    virtual TESForm* GetForm();
    FormChangeMask GetChangeFlags(unsigned int);
    int ReadElementCount();
    void ReadTypedData(void*, unsigned int);
    FormChangeMask GetOldChangeFlags(unsigned int flags);
};

class TESGlobalValueReader
{
  public:
    float GetValue();
};

class PerkEntryConditionSet;
class PlayerQuestData
{
  public:
    PerkEntryConditionSet* GetConditions();
};
class BGSPerkEntry
{
  public:
    TESForm* form;
    unsigned short count, level;
    ContainerItemExtra* extra;
    void* Destroy(unsigned int);
};
class BGSCameraShot;
class ActorCause;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    void RemoveHead();
    void RemoveAll();
};
class TESContainer
{
  public:
    unsigned int data[3];
    TESContainer();
    ~TESContainer();
    void AddObject(TESForm*, int, ContainerItemExtra*);
    void MergeContainer(TESContainer*);
    void ScaleEntryCounts(int);
};
class MersenneTwister
{
  public:
    static MersenneTwister* GetRandomGenerator();
    unsigned int GetRandomUInt();
};
unsigned int DialogueRandom();

class BGSLoadGameBuffer
{
  public:
    unsigned int ReadFormIdentifier();
};
class FileEntryList
{
  public:
    void Copy(TESForm*, unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
};
void* operator new(unsigned int) throw();
class TESGlobal : public TESForm
{
};
class BGSCameraPath
{
  public:
    int HasNameForWarning();
};
int Warning(const char*, ...);
class TESLeveledList
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual unsigned char vfn_10();
    unsigned char GetChanceNone();
    virtual bool vfn_14();
    bool UsesAllEntries();
    virtual int vfn_18();
    bool FUN_004877e0();
    bool GetAllBelow();
    bool FUN_004878a0();
    bool GetUseAll();
    static TESLeveledList* GetFormAsLeveledList(TESForm*);
    unsigned long leveledList[2];
    unsigned char m_pChanceGlobal;
    unsigned char m_ucChanceNone;
    unsigned char padding[2];
    TESGlobal* m_pLevelGlobal;
    unsigned long m_kLeveledObjects[2];

    LeveledObject* CreateLeveledObject(unsigned short level, unsigned short count, TESForm* form,
                                       ContainerItemExtra* extra);
    void InitializeComponent();
    void ClearComponent();
    void InitializeLeveledList();
    void ClearScriptAddedLeveledObjects();
    void SelectLeveledObject(unsigned short level, TESForm*& form, unsigned short& count, ContainerItemExtra*& extra,
                             bool recurse, int mode);
    void PopulateContainerWithLeveledItems(unsigned short level, unsigned short count, TESContainer* container,
                                           int mode);
    void PopulateContainerFromReference(TESObjectREFR* reference, TESContainer* container);
    void InitItem(TESForm* form);
    void LoadGame(BGSLoadFormBuffer* buffer);
    void Revert(BGSLoadFormBuffer* buffer);
};

#endif
