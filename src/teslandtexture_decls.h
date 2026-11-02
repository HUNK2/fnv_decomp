// teslandtexture_decls.h: declares BaseFormComponent, TESForm, TextureParameterBlock, TESLandTexture, NiRefObject and more
#ifndef LANDTEXTURE_MATCH_H
#define LANDTEXTURE_MATCH_H

#include <stddef.h>
#define FNV_JOIN2(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN2(a, b)
#define FNV_STATIC_ASSERT(e) typedef char FNV_JOIN(fnv_check_, __LINE__)[(e) ? 1 : -1]
class TESFile;
class TESGrass;
class BGSTextureSet;
template <class T> class BSStringT;
enum ENUM_FORM_ID
{
    FORM_ID_LTEX = 18
};
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    ~BSSimpleList();
    void AddTail(const T& item);
    bool IsEmpty();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    void Remove(const T& item);
    void RemoveHead();
    void SetItem(const T& item);
};
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
    bool GetInitialized() const;
    static TESForm* GetFormByID(unsigned int formID);
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

// Names of nested/template specializations use the canonical generator identifier mapping.
class BGSTextureSet;
class TextureParameterBlock;
class TextureParameterBlock
{
  public:
    unsigned char m_ucParameter1;  // +0x0, 1 bytes
    unsigned char m_ucParameter2;  // +0x1, 1 bytes
    unsigned char m_ucParameter3;  // +0x2, 1 bytes
    // void __cdecl TextureParameterBlock::*()
};
FNV_STATIC_ASSERT(sizeof(TextureParameterBlock) == 3);
FNV_STATIC_ASSERT(offsetof(TextureParameterBlock, m_ucParameter1) == 0);
FNV_STATIC_ASSERT(offsetof(TextureParameterBlock, m_ucParameter2) == 1);
FNV_STATIC_ASSERT(offsetof(TextureParameterBlock, m_ucParameter3) == 2);
class TESLandTexture : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    BGSTextureSet* m_pTextureSet;                 // +0x18, 4 bytes
    TextureParameterBlock LandTextureParameters;  // +0x1C, 3 bytes
    unsigned char m_ucTextureTiling;              // +0x1F, 1 bytes
    BSSimpleList<TESGrass*> m_kGrassList;         // +0x20, 8 bytes
    TESLandTexture();
    virtual void ResetFormData();
    virtual bool Load(TESFile* file);
    virtual void InitItem();
    BSSimpleList<TESGrass*>* GetGrassList();
    // TESLandTexture
    // void __cdecl TESLandTexture::*()
    // void __cdecl TESLandTexture::*()
    // void __cdecl TESLandTexture::*()
    // bool __cdecl TESLandTexture::*(TESFile*)
    // void __cdecl TESLandTexture::*()
    // void __cdecl TESLandTexture::*(TESForm*)
    // bool __cdecl TESLandTexture::*(TESForm*)
    // void __cdecl TESLandTexture::*()
    // void __cdecl TESLandTexture::*(IO_TASK_PRIORITY, QueuedFile*)
    // BSSimpleList<TESGrass *>* __cdecl TESLandTexture::*()
    // void __cdecl TESLandTexture::*(TESGrass*)
    // void __cdecl TESLandTexture::*(TESGrass*)
    // BGSTextureSet* __cdecl TESLandTexture::*()
    // void __cdecl TESLandTexture::*(BGSTextureSet*)
    // void __cdecl TESLandTexture::*(NiPointer<NiTexture>&)
    // MATERIAL_TYPE __cdecl TESLandTexture::*()
    // float __cdecl TESLandTexture::*()
    // float __cdecl TESLandTexture::*()
    // unsigned char __cdecl TESLandTexture::*()
    // void __cdecl TESLandTexture::*(unsigned char)
    // TESLandTexture& __cdecl TESLandTexture::*(const TESLandTexture&)
    // void __cdecl TESLandTexture::*()
};
FNV_STATIC_ASSERT(sizeof(TESLandTexture) == 40);
FNV_STATIC_ASSERT(offsetof(TESLandTexture, m_pTextureSet) == 24);
FNV_STATIC_ASSERT(offsetof(TESLandTexture, LandTextureParameters) == 28);
FNV_STATIC_ASSERT(offsetof(TESLandTexture, m_ucTextureTiling) == 31);
FNV_STATIC_ASSERT(offsetof(TESLandTexture, m_kGrassList) == 32);

// Vtable declarations only, using public JohnnyGuitarNVSE NiObject.hpp names.
class bhkBlendCollisionObject;
class bhkNiCollisionObject;
class bhkLimitedHingeConstraint;
class bhkRigidBody;
class BSFadeNode;
class BSMultiBoundNode;
class BSResizableTriShape;
class BSSegmentedTriShape;
class CloningProcess;
class NiGeometry;
class NiLines;
class NiNode;
class NiParticles;
class NiStream;
class NiTriBasedGeom;
class NiTriShape;
class NiTriStrips;
class NiControllerManager;
class NiObjectGroup;
class NiBound;
class NiRTTI;
class NiViewerStringsArray;
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
};
class NiObject : public NiRefObject
{
  public:
    virtual ~NiObject();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* IsSceneNode() const;
    virtual BSFadeNode* IsFadeNode() const;
    virtual BSMultiBoundNode* IsMultiBoundNode() const;
    virtual NiGeometry* IsGeometry() const;
    virtual NiTriBasedGeom* IsTriBasedGeometry() const;
    virtual NiTriStrips* IsTriStrips() const;
    virtual NiTriShape* IsTriShape() const;
    virtual BSSegmentedTriShape* IsSegmentedTriShape() const;
    virtual BSResizableTriShape* IsResizableTriShape() const;
    virtual NiParticles* IsParticlesGeom() const;
    virtual NiLines* IsLineGeometry() const;
    virtual bhkNiCollisionObject* IsBhkNiCollisionObject() const;
    virtual bhkBlendCollisionObject* IsBhkBlendCollisionObject() const;
    virtual bhkRigidBody* IsBhkRigidBody() const;
    virtual bhkLimitedHingeConstraint* IsBhkLimitedHingeConstraint() const;
    virtual NiObject* MakeClone(CloningProcess& arCloning);
    virtual void LoadBinary(NiStream& arStream);
    virtual void LinkObject(NiStream& arStream);
    virtual void RegisterStreamables(NiStream& arStream);
    virtual void SaveBinary(NiStream& arStream);
    virtual bool IsEqual(NiObject* apObject) const;
    virtual void GetViewerStrings(NiViewerStringsArray* apStrings);
    virtual void AddViewerStrings(NiViewerStringsArray* apStrings);
    virtual void ProcessClone(CloningProcess& arCloning);
    virtual void PostLinkObject(NiStream& arStream);
    virtual bool StreamCanSkip();
    virtual const NiRTTI* GetStreamableRTTI();
    virtual void SetObjectBound(NiBound* apNewBound);
    virtual void GetBlockAllocationSize();
    virtual NiObjectGroup* GetGroup();
    virtual void SetGroup(NiObjectGroup* apGroup);
    virtual NiControllerManager* IsControllerManager() const;
};
FNV_STATIC_ASSERT(sizeof(NiObject) == 8);
class BSShaderProperty
{
  public:
    enum TextureTypeEnum
    {
        BASE = 0,
        NORMAL = 1
    };
};
class BSTextureSet : public NiObject
{
  public:
    virtual const char* GetTexturePath(BSShaderProperty::TextureTypeEnum texture) const;
};
FNV_STATIC_ASSERT(sizeof(BSTextureSet) == 8);
class TESFormList;
class TESObject : public TESForm
{
  public:
    TESFormList* m_pOwningList;
    TESObject* m_pPreviousObject;
    TESObject* m_pNextObject;
};
class ShortPoint3
{
  public:
    short x, y, z;
};
class TESBoundObject : public TESObject
{
  public:
    struct ValuePair
    {
        ShortPoint3 m_kBoundMin;
        ShortPoint3 m_kBoundMax;
    } TESBoundObjectBounds;
};
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 0x30);
class BGSTextureSet : public TESBoundObject, public BSTextureSet
{
  public:
    unsigned char textureData[0x4C];
    unsigned short textureFlags;  // +0x84
    void SetHasSpecular(bool hasSpecular);
};
class TESGrass : public TESBoundObject
{
};

class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData(unsigned int*);
    bool NextChunk();
};
extern "C" void* __cdecl _alloca(unsigned int);
int __cdecl Warning(const char*, ...);
#endif
