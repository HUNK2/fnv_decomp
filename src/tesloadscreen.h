// tesloadscreen.h: declares WorldCellRecord, BaseFormComponent, TESForm, TESTexture, TESDescription and more
#ifndef LOADSCREEN_MATCH_H
#define LOADSCREEN_MATCH_H

#include <stddef.h>
#define FNV_JOIN2(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN2(a, b)
#define FNV_STATIC_ASSERT(e) typedef char FNV_JOIN(fnv_check_, __LINE__)[(e) ? 1 : -1]
class TESFile;
class TESLoadScreenType;
enum ENUM_FORM_ID
{
    FORM_ID_CELL = 57,
    FORM_ID_REFR = 58,
    FORM_ID_ACHR = 59,
    FORM_ID_ACRE = 60,
    FORM_ID_PMIS = 61,
    FORM_ID_PGRE = 62,
    FORM_ID_PBEA = 63,
    FORM_ID_PFLA = 64,
    FORM_ID_WRLD = 65,
    FORM_ID_LSCR = 75,
    FORM_ID_PBAR = 105
};
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    ~BSSimpleList();
    void AddHead(T& item);
    bool IsEmpty();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    void RemoveAll();
};
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT();
    ~BSStringT();
    bool Set(const T*, unsigned int);
};
// Community LoadForm fields (JohnnyGuitar TESLoadScreen.hpp), matching PC record offsets.
class WorldCellRecord
{
  public:
    unsigned int auiFormId;
    unsigned int uiWorldID;
    unsigned int uiCellKey;
};
FNV_STATIC_ASSERT(sizeof(WorldCellRecord) == 12);
FNV_STATIC_ASSERT(offsetof(WorldCellRecord, auiFormId) == 0);
FNV_STATIC_ASSERT(offsetof(WorldCellRecord, uiWorldID) == 4);
FNV_STATIC_ASSERT(offsetof(WorldCellRecord, uiCellKey) == 8);
// Source layout: BaseFormComponent. PC corrections are in generate_headers.py.
class BaseFormComponent
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    virtual bool CompareWithBase(BaseFormComponent* component);
};
FNV_STATIC_ASSERT(sizeof(BaseFormComponent) == 0x4);

// Source layout: TESForm. PC corrections are in generate_headers.py.
class TESForm : public BaseFormComponent
{
  public:
    unsigned char m_ucFormType;             // +0x4
    unsigned int m_uiFormFlags;             // +0x8
    unsigned int iFormID;                   // +0xC
    BSSimpleList<TESFile*> m_kSourceFiles;  // +0x10
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07(void);
    virtual bool LoadForm(TESFile* modInfo);
    virtual bool Unk_09(void* arg);
    virtual bool AppendForm(TESFile* modInfo);
    virtual void SaveForm(void);
    virtual bool LoadForm2(TESFile* modInfo);
    virtual void WriteFormInfo(TESFile* modInfo);
    virtual bool Unk_0E(void* arg);
    virtual bool Sort(TESForm* form);
    virtual TESForm* CreateForm(void* arg0, void* mapToAddTo);
    virtual void Unk_11(void* arg);
    virtual void MarkAsModified(unsigned int changedFlags);
    virtual void MarkAsUnmodified(unsigned int changedFlags);
    virtual unsigned int GetSaveSize(unsigned int changedFlags);
    virtual void Unk_15(void* arg);
    virtual void SaveGame(unsigned int changedFlags);
    virtual void LoadGame(void* arg);
    virtual void LoadGame2(unsigned int changedFlags);
    virtual void Unk_19(void* arg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* arg0, void* arg1);
    virtual void Revert(unsigned int changedFlags);
    virtual void Unk_1D(void* arg);
    virtual void Unk_1E(void* arg);
    virtual bool Unk_1F(void* arg);
    virtual void Unk_20(void* arg);
    virtual void Unk_21(void* arg);
    virtual void InitItem(void);
    virtual unsigned int GetTypeID(void);
    virtual void GetDebugName(BSStringT<char>* dst);
    virtual bool IsQuestItem(void);
    virtual bool Unk_26(void);
    virtual bool Unk_27(void);
    virtual bool Unk_28(void);
    virtual bool Unk_29(bool set);
    virtual bool Unk_2A(bool set);
    virtual bool Unk_2B(void);
    virtual bool Unk_2C(void);
    virtual bool Unk_2D(void);
    virtual bool Unk_2E(void);
    virtual void Unk_2F(bool set);
    virtual bool Unk_30(void);
    virtual void MarkForDeletion(bool set);
    virtual void SetAltered(bool set);
    virtual void SetQuestItem(bool set);
    virtual void Unk_34(bool set);
    virtual void Unk_35(bool set);
    virtual void Unk_36(bool set);
    virtual void Unk_37(void);
    virtual void readOBNDSubRecord(TESFile* modInfo);
    virtual bool IsActor_InEditor(void);
    virtual bool IsBoundObject(void);
    virtual bool Unk_3B(void);
    virtual bool GetIsReference() const;
    virtual bool Unk_3D(void);
    virtual bool Unk_3E(void);
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41(void);
    virtual void CopyFrom(const TESForm* form);
    virtual bool Compare(TESForm* form);
    virtual bool CheckFormGRUP(void* arg);
    virtual void InitFormGRUP(void* dst, void* arg1);
    virtual bool Unk_46(void);
    virtual bool Unk_47(void);
    virtual bool Unk_48(unsigned int formType);
    virtual bool Unk_49(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4);
    virtual void SetRefID(unsigned int refID, bool generateID);
    virtual char* GetName2(void);
    virtual char* GetName(void) const;
    virtual bool SetEditorID_AtRuntime(const char* edid);
    bool IsFormInitialized() const;
    ENUM_FORM_ID GetFormType() const;
    TESForm();
    TESFile* GetFile(int fileIndex);
    BSSimpleList<TESFile*>* GetSourceFiles();
    bool IsDeleted() const;
    unsigned int GetFormID();
    bool IsTemporary() const;
    void NotifySaveLoadGameOfFormChange();
    void SetInitializationState(bool initialized);
    void SetFormType(ENUM_FORM_ID type);
    void LoadRecordHeader(TESFile* file);
    static void RemapFormIDForFile(unsigned int& formID, TESFile* file);
};
FNV_STATIC_ASSERT(sizeof(TESForm) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESForm, m_ucFormType) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESForm, m_uiFormFlags) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESForm, iFormID) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESForm, m_kSourceFiles) == 0x10);

// Source layout: TESTexture. PC corrections are in generate_headers.py.
class TESTexture : public BaseFormComponent
{
  public:
    TESTexture();
    ~TESTexture();
    static void ReadTextureData(TESTexture*, TESFile*);
    BSStringT<char> FullNameComponent;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESTexture) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESTexture, FullNameComponent) == 0x4);

// Source layout: TESDescription. PC corrections are in generate_headers.py.
class TESDescription : public BaseFormComponent
{
  public:
    TESDescription();
    unsigned long m_uiDescriptionFileOffset;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESDescription) == 0x8);
FNV_STATIC_ASSERT(offsetof(TESDescription, m_uiDescriptionFileOffset) == 0x4);

// Names of nested/template specializations use the canonical generator identifier mapping.
// Community LoadForm fields (JohnnyGuitar TESLoadScreen.hpp), matching PC record offsets.
class WorldCellRecord;
class TESLoadScreen;
class TESLoadScreenType;
class TESLoadScreen : public TESForm, public TESTexture, public TESDescription
{
  public:
    // base TESForm at +0x0, size 24
    // base TESTexture at +0x18, size 12
    // base TESDescription at +0x24, size 8
    BSSimpleList<WorldCellRecord*> m_kWorldCellRecordList;  // +0x2C, 8 bytes
    TESLoadScreenType* m_pLoadScreenType;                   // +0x34, 4 bytes
    BSStringT<char> m_kLoadScreenText;                      // +0x38, 8 bytes
    TESLoadScreen();
    virtual ~TESLoadScreen();
    virtual void ClearData();
    virtual bool Load(TESFile* file);
    virtual void InitItem();
    void ClearLoadScreenData();
    bool MatchesFormLocation(TESForm* form);
    // TESLoadScreen
    // void __cdecl TESLoadScreen::*()
    // void __cdecl TESLoadScreen::*()
    // void __cdecl TESLoadScreen::*()
    // bool __cdecl TESLoadScreen::*(TESFile*)
    // void __cdecl TESLoadScreen::*()
    // void __cdecl TESLoadScreen::*(TESForm*)
    // bool __cdecl TESLoadScreen::*(TESForm*)
    // char* __cdecl TESLoadScreen::*()
    // const char* __cdecl TESLoadScreen::*(TESForm*, CHUNK_ID)
    // void __cdecl TESLoadScreen::*()
    // bool __cdecl TESLoadScreen::*(TESForm*)
    // bool __cdecl TESLoadScreen::*()
    // bool __cdecl TESLoadScreen::*(TESForm*)
    // bool __cdecl TESLoadScreen::*()
    // void __cdecl TESLoadScreen::*(bool)
    // bool __cdecl TESLoadScreen::*()
    // void __cdecl TESLoadScreen::*(bool)
    // TESLoadScreenType* __cdecl TESLoadScreen::*()
    // LOAD_SCREEN_DATA_TYPE __cdecl TESLoadScreen::*()
    // void __cdecl TESLoadScreen::*(TESLoadScreenType*)
    // TESLoadScreen& __cdecl TESLoadScreen::*(const TESLoadScreen&)
    // void __cdecl TESLoadScreen::*()
};
FNV_STATIC_ASSERT(sizeof(TESLoadScreen) == 64);
FNV_STATIC_ASSERT(offsetof(TESLoadScreen, m_kWorldCellRecordList) == 44);
FNV_STATIC_ASSERT(offsetof(TESLoadScreen, m_pLoadScreenType) == 52);
FNV_STATIC_ASSERT(offsetof(TESLoadScreen, m_kLoadScreenText) == 56);

class TESDataHandler
{
  public:
    TESLoadScreenType* GetLoadScreenType(unsigned int);
};
extern TESDataHandler* g_dataHandler;
class TESObjectREFR;
class TESObjectCELL;
class ExtraDataList;
class NiNode;
class AnimData;
class ValidBip01Names;
class NiPoint3
{
  public:
    float x, y, z;
};
class TESWorldSpace : public TESForm
{
  public:
    static int BuildCellKey(short x, short y);
    static int GetKeyForWorldCoord(const NiPoint3& point);
};
class TESObjectCELL : public TESForm
{
  public:
    bool IsCellInterior() const;
    TESWorldSpace* GetParentWorldSpace();
    int GetCellGridX();
    int GetCellGridY();
};
class TESObjectREFR : public TESForm
{
  public:
    virtual void Unk_4E(void);
    virtual void Unk_4F(void);
    virtual void Unk_50(void);
    virtual void Unk_51(void);
    virtual bool CastShadows(void);
    virtual void Unk_53(void);
    virtual void Unk_54(void);
    virtual void Unk_55(void);
    virtual void Unk_56(void);
    virtual void Unk_57(void);
    virtual void Unk_58(void);
    virtual void Unk_59(void);
    virtual void Unk_5A(void);
    virtual void Unk_5B(void);
    virtual void Unk_5C(void);
    virtual void Unk_5D(void);
    virtual void Unk_5E(void);
    virtual TESObjectREFR* RemoveItem(TESForm* toRemove, ExtraDataList* extraList, unsigned int count,
                                      unsigned int unk3, unsigned int unk4, TESObjectREFR* destRef, unsigned int unk6,
                                      unsigned int unk7, unsigned int unk8, unsigned char unk9);
    virtual void Unk_60(void);
    virtual void Unk_61(void);
    virtual void Unk_62(void);
    virtual void Unk_63(void);
    virtual void AddItem(TESForm* item, ExtraDataList* xDataList, unsigned int Quantity);
    virtual void Unk_65(void);
    virtual void Unk_66(void);
    virtual void Unk_67(void);
    virtual bool GetIsChildSize(bool checkHeight);
    virtual unsigned int GetActorUnk0148(void);
    virtual void SetActorUnk0148(unsigned int arg0);
    virtual void Unk_6B(void);
    virtual void Unk_6C(void);
    virtual void Unk_6D(void);
    virtual void Unk_6E(void);
    virtual void Unk_6F(void);
    virtual void Unk_70(void);
    virtual void AnimateNiNode(void);
    virtual void GenerateNiNode(bool arg0);
    virtual void Set3D(NiNode* niNode, bool unloadArt);
    virtual NiNode* GetNiNode(void);
    virtual void Unk_75(void);
    virtual void Unk_76(void);
    virtual void Unk_77(void);
    virtual void Unk_78(void);
    virtual AnimData* GetAnimData(void);
    virtual ValidBip01Names* GetValidBip01Names(void);
    virtual ValidBip01Names* CallGetValidBip01Names(void);
    virtual void SetValidBip01Names(ValidBip01Names validBip01Names);
    virtual NiPoint3* GetPos(void) const;
    TESObjectCELL* GetParentCell() const;
    TESWorldSpace* GetParentWorldSpace();
};
class TESFile
{
  public:
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData(unsigned int*);
    bool NextChunk();
    bool IsEndianConversionRequired();
    const char* GetFilename();
};
extern "C" void* __cdecl _alloca(unsigned int);
int __cdecl Warning(const char*, ...);
#endif
