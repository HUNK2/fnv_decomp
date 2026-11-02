// fallout_shared/tesmodeltextureswap_decls.h: declares TESAIForm, TESForm, BGSTextureSet, DistantTreeTextureInfo, PackageList and more
#ifndef TESMODELTEXTURESWAP_WORKER_DECLS_H
#define TESMODELTEXTURESWAP_WORKER_DECLS_H


class PerkButtonEntry;
class BGSPerkEntry;
class DistantTreeTextureInfo;
class TESForm;
class TESFile;
class BGSTextureSet;
class PackageList;
class TESGrass;

template <class T> class BSSimpleList
{
  public:
    void* pFirst;
    void* pLast;
    bool IsEmpty();
    T& GetItem();
    void AddHead(T& item);
    void RemoveHead();
    void Remove(const T& item);
    BSSimpleList<T>* GetNext();
};

class TESAIForm
{
  public:
    PackageList* GetPackageList();
};

class TESForm
{
  public:
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07();
    virtual bool LoadForm(TESFile*);
    virtual bool Unk_09(void*);
    virtual bool AppendForm(TESFile*);
    virtual void SaveForm();
    virtual bool LoadForm2(TESFile*);
    virtual void WriteFormInfo(TESFile*);
    virtual bool Unk_0E(void*);
    virtual bool Sort(TESForm*);
    virtual TESForm* CreateForm(void*, void*);
    virtual void Unk_11(void*);
    virtual void MarkAsModified(unsigned int);
    virtual void MarkAsUnmodified(unsigned int);
    virtual unsigned int GetSaveSize(unsigned int);
    virtual void Unk_15(void*);
    virtual void SaveGame(unsigned int);
    virtual void LoadGame(void*);
    virtual void LoadGame2(unsigned int);
    virtual void Unk_19(void*);
    virtual void Unk_1A();
    virtual void Unk_1B(void*, void*);
    virtual void Revert(unsigned int);
    virtual void Unk_1D(void*);
    virtual void Unk_1E(void*);
    virtual bool Unk_1F(void*);
    virtual void Unk_20(void*);
    virtual void Unk_21(void*);
    virtual void InitItem();
    virtual unsigned int GetTypeID();
    virtual void GetDebugName(void*);
    virtual bool IsQuestItem();
    virtual bool Unk_26();
    virtual bool Unk_27();
    virtual bool Unk_28();
    virtual bool Unk_29(bool);
    virtual bool Unk_2A(bool);
    virtual bool Unk_2B();
    virtual bool Unk_2C();
    virtual bool Unk_2D();
    virtual bool Unk_2E();
    virtual void Unk_2F(bool);
    virtual bool Unk_30();
    virtual void MarkForDeletion(bool);
    virtual void SetAltered(bool);
    virtual void SetQuestItem(bool);
    virtual void Unk_34(bool);
    virtual void Unk_35(bool);
    virtual void Unk_36(bool);
    virtual void Unk_37();
    virtual void readOBNDSubRecord(TESFile*);
    virtual bool IsActor_InEditor();
    virtual bool IsBoundObject();
    virtual bool Unk_3B();
    virtual bool GetIsReference() const;
    virtual bool Unk_3D();
    virtual bool Unk_3E();
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41();
    virtual void CopyFrom(const TESForm*);
    virtual bool Compare(TESForm*);
    virtual bool CheckFormGRUP(void*);
    virtual void InitFormGRUP(void*, void*);
    virtual bool Unk_46();
    virtual bool Unk_47();
    virtual bool Unk_48(unsigned int);
    virtual bool Unk_49(void*, void*, void*, void*, void*);
    virtual void SetRefID(unsigned int, bool);
    virtual char* GetName2();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual char* GetName() const;

    unsigned int GetFormID();
    TESFile* GetFile(int);
    static void RemapFormIDForFile(unsigned int&, TESFile*);
    static TESForm* GetFormByID(unsigned int);
};

class BSShaderTextureSet;
class BGSTextureSet : public TESForm
{
  public:
    static BGSTextureSet* GetEmptyTextureSet();
    BSShaderTextureSet* BuildShaderTextureSet();
};

class DistantTreeTextureInfo
{
  public:
    unsigned int formID;
    int index;
    char objectName[128];
    DistantTreeTextureInfo();
};

class PackageList
{
};

const char kModelTextureSwapInitWarning[] =
    "MASTERFILE: Failed to find texture set (%08X) in model texture swap init for form '%s' (%08X).";

int __cdecl Warning(const char* format, ...);
void __cdecl operator delete(void* pointer);

class NiAVObject;
class NiNode;
class NiProperty;
class NiGeometry;
class NiAVObject
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual NiNode* IsSceneNode();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual NiGeometry* IsGeometry();
    NiProperty* GetProperty(unsigned int);
};
class NiNode : public NiAVObject
{
  public:
    unsigned int FUN_0043b480();
    NiAVObject* GetAt(unsigned int);
};
class NiGeometry : public NiAVObject
{
  public:
    void SetAppCulled(bool);
};
class BGSDehydrationStage
{
  public:
    unsigned int FUN_00441110();
};
class NiProperty
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
};
class BSShaderPPLightingProperty : public NiProperty
{
  public:
    void SetTextureSet(BSShaderTextureSet*);
    void BuildShaderTextureSet(int, int);
};
class TESObjectREFR;
template <class K, class V> class NiTPointerMap
{
  public:
    bool GetAt(K, V&) const;
};
class CombatThreatRecord;
template <class K, class V> class NiTMapItem
{
};
template <class T> class DFALL
{
};
template <class A, class K, class V> class NiTMapBase
{
  public:
    bool RemoveAt(K);
};
template <class K, class V> class BSMapBase
{
  public:
    unsigned int hashSize;
    void* hashTable;
    unsigned int count;
    BSMapBase(unsigned int);
    virtual ~BSMapBase();
    void SetAt(K, V);
};
template <class K, class V> class BSMap : public BSMapBase<K, V>
{
  public:
};

class TESFile
{
  public:
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
};
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESModel
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual const char* GetModelFilePath();
    virtual void SetModelFilePath(const char*);
    void FUN_004893c0(unsigned char);
    static void LoadModelData(TESModel*, TESFile*);
    static void LoadTextureSwapData(TESModel*, TESFile*);
};
bool FUN_00489280(int);
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)

class TESModelTextureSwap
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual const char* GetModelFilePath();
    unsigned char base[0x14];
    BSSimpleList<PerkButtonEntry*> TextureSwapNodeAccessor;
    DistantTreeTextureInfo* GetTexSwap(int);
    void AddTexSwap(const char*, int, BGSTextureSet*);
    void ClearTextureSwaps();
    void InitItem(TESForm* form);
    void ApplyTextureSwaps(NiAVObject*);
    bool ParseTextureSwapData(void*, unsigned int, unsigned int);
    static void ReadTextureSwapChunk(TESModelTextureSwap*, TESFile*);
    static bool ApplyTextureSwapToNode(NiAVObject*, BSMap<int, DistantTreeTextureInfo*>*, int&);
};

class BGSDistantTreeBlock
{
  public:
    class InstanceData;
};
int Warning();
unsigned int SetWarningState(bool);

class SpellItem;
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
void* __cdecl operator new(unsigned int);
class NiFixedString
{
  public:
    const char* data;
    NiFixedString(const NiFixedString&);
    int IsNotEmpty() const;
};
extern NiFixedString EmptyFS;
void FUN_0043ba60(const NiFixedString&);
#endif
