#ifndef FNV_BGSRECONSTRUCTFORMSINALLFILESMAP_DECLS_H
#define FNV_BGSRECONSTRUCTFORMSINALLFILESMAP_DECLS_H


class TESBoundObject;
class BGSReconstructFormsInFileMap;
class FormChangeMap;
struct ChangedFormRecord;

class BGSSaveLoadChangesMapBase
{
  public:
    virtual ~BGSSaveLoadChangesMapBase();
};

class BGSSaveLoadChangesMap : public BGSSaveLoadChangesMapBase
{
  public:
    void Clear();
    virtual ~BGSSaveLoadChangesMap();
};

class BGSReconstructFormsInAllFilesMapBase
{
  public:
    BGSReconstructFormsInAllFilesMapBase(unsigned int capacity);
    virtual ~BGSReconstructFormsInAllFilesMapBase();
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
};

class TESFile
{
  public:
    TESFile* GetParentTESFile();
};

class TESForm
{
  public:
#define FNV_VIRTUAL_SLOT(n) virtual void vfn_##n();
    FNV_VIRTUAL_SLOT(00)
    FNV_VIRTUAL_SLOT(01)
    FNV_VIRTUAL_SLOT(02) FNV_VIRTUAL_SLOT(03) FNV_VIRTUAL_SLOT(04) FNV_VIRTUAL_SLOT(05) FNV_VIRTUAL_SLOT(06)
        FNV_VIRTUAL_SLOT(07) FNV_VIRTUAL_SLOT(08) FNV_VIRTUAL_SLOT(09) FNV_VIRTUAL_SLOT(10) FNV_VIRTUAL_SLOT(11)
            FNV_VIRTUAL_SLOT(12) FNV_VIRTUAL_SLOT(13) FNV_VIRTUAL_SLOT(14) FNV_VIRTUAL_SLOT(15) FNV_VIRTUAL_SLOT(16)
                FNV_VIRTUAL_SLOT(17) FNV_VIRTUAL_SLOT(18) FNV_VIRTUAL_SLOT(19) FNV_VIRTUAL_SLOT(20) FNV_VIRTUAL_SLOT(21)
                    FNV_VIRTUAL_SLOT(22) FNV_VIRTUAL_SLOT(23) FNV_VIRTUAL_SLOT(24) FNV_VIRTUAL_SLOT(25)
                        FNV_VIRTUAL_SLOT(26) FNV_VIRTUAL_SLOT(27) FNV_VIRTUAL_SLOT(28) FNV_VIRTUAL_SLOT(29)
                            FNV_VIRTUAL_SLOT(30) FNV_VIRTUAL_SLOT(31) FNV_VIRTUAL_SLOT(32) FNV_VIRTUAL_SLOT(33)
#undef FNV_VIRTUAL_SLOT
                                virtual void InitItem();
#define FNV_VIRTUAL_SLOT(n) virtual void vfn_##n();
    FNV_VIRTUAL_SLOT(35)
    FNV_VIRTUAL_SLOT(36)
    FNV_VIRTUAL_SLOT(37) FNV_VIRTUAL_SLOT(38) FNV_VIRTUAL_SLOT(39) FNV_VIRTUAL_SLOT(40) FNV_VIRTUAL_SLOT(41)
        FNV_VIRTUAL_SLOT(42) FNV_VIRTUAL_SLOT(43) FNV_VIRTUAL_SLOT(44) FNV_VIRTUAL_SLOT(45) FNV_VIRTUAL_SLOT(46)
            FNV_VIRTUAL_SLOT(47) FNV_VIRTUAL_SLOT(48) FNV_VIRTUAL_SLOT(49) FNV_VIRTUAL_SLOT(50) FNV_VIRTUAL_SLOT(51)
                FNV_VIRTUAL_SLOT(52) FNV_VIRTUAL_SLOT(53) FNV_VIRTUAL_SLOT(54) FNV_VIRTUAL_SLOT(55) FNV_VIRTUAL_SLOT(56)
                    FNV_VIRTUAL_SLOT(57) FNV_VIRTUAL_SLOT(58) FNV_VIRTUAL_SLOT(59)
#undef FNV_VIRTUAL_SLOT
                        virtual bool GetIsReference() const;
};

class TESObjectREFR
{
  public:
    TESBoundObject* GetObjectReference();
};

struct ChangedFormRecord
{
    TESForm* pForm;
    unsigned int iFlags;
};

template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    virtual ~BSSimpleArray();
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
};

class FormChangeMap
{
  public:
    BSSimpleArray<ChangedFormRecord, 1024> m_kOrdinaryFormChanges;
    BSSimpleArray<ChangedFormRecord, 1024> m_kSpecialFormChanges;
    FormChangeMap();
    ~FormChangeMap();
    void FUN_00843240();
    void FUN_00843be0(unsigned int count);
    unsigned int GetCombinedFlags();
    ChangedFormRecord* FUN_008432e0(unsigned int index);
    bool RemoveForm(unsigned int index);
};

class BGSReconstructFormsInFileMap
{
  public:
    virtual ~BGSReconstructFormsInFileMap();
    void BuildMap(TESFile* file, FormChangeMap* forms);
};

template <class T_Key, class T_Data> class NiTPointerMap
{
  public:
    void* GetFirstPos();
    void GetNext(void*& position, T_Key& key, T_Data& data);
    void RemoveAll();
};

class BGSReconstructFormsInAllFilesMap : public BGSReconstructFormsInAllFilesMapBase
{
  public:
    FormChangeMap m_kFormChangeMap;
    unsigned int iCount;
    void* GetFirstPos();
    void GetNext(void*& position, TESFile*& file, BGSReconstructFormsInFileMap*& map);
    void Clear();
    void BuildMap();
    void AddFormFlagEntry(ChangedFormRecord* data);
    BGSReconstructFormsInAllFilesMap();
    virtual ~BGSReconstructFormsInAllFilesMap();
};

class BGSSaveLoadGame
{
  public:
    void SetFlag4(bool enable);
};

class TESDataHandler
{
  public:
    bool FUN_004516b0();
    void SetBoolAt61a(bool enable);
};

class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern TESDataHandler* g_dataHandler;

#endif
