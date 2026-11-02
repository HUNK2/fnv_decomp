// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESOBJECTTREE_DECLS_H
#define FNV_TESOBJECTTREE_DECLS_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESTexture.h"
#include "layout_support.h"
class BGSDestructibleObjectForm;
class BSFileEntry;
class CollisionComponent;
class ShortPoint3;
class NiPoint2;
class NiTPrimitiveArray_unsigned_int_;
class TreeRecordData;
class TESBoundObject__BOUND_DATA;
class TESBoundTreeObject;
class TESIconTree;
class TESModel;
class TESModelTree;
class TESFormList;
class TESObjectTREE;
class TESTexture1024;
class FileEntryList;
class TESObject : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
    // TESObject
    // void __cdecl TESObject::*()
    // NiAVObject* __cdecl TESObject::*()
    // unsigned int __cdecl TESObject::*()
    // TESFormList* __cdecl TESObject::*()
    // unsigned int __cdecl TESObject::*()
    // bool __cdecl TESObject::*()
    // char* __cdecl TESObject::*()
    // void __cdecl TESObject::*(TESFormList*)
    // void __cdecl TESObject::*(TESObject*)
    // void __cdecl TESObject::*(TESObject*)
    // TESObject* __cdecl TESObject::*()
    // TESObject* __cdecl TESObject::*()
    // NiAVObject* __cdecl TESObject::*(NiAVObject*, const char*)
    // const char* __cdecl TESObject::*(TESObjectREFR*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // void __cdecl TESObject::*(TESObjectREFR*, char*)
    // TESObject& __cdecl TESObject::*(const TESObject&)
    // void __cdecl TESObject::*()
};
FNV_STATIC_ASSERT(sizeof(TESObject) == 36);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pOwningList) == 24);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pPreviousObject) == 28);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pNextObject) == 32);
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
    // ShortPoint3
    // short& __cdecl ShortPoint3::*(int)
    // operator=
    // operator==
    // operator!=
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&)
    // operator-
    // operator*
    // ShortPoint3 __cdecl ShortPoint3::*(float)
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&, const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3& __cdecl ShortPoint3::*(float)
    // ShortPoint3& __cdecl ShortPoint3::*(float)
    // float __cdecl ShortPoint3::*()
    // short __cdecl ShortPoint3::*()
    // short __cdecl ShortPoint3::*(const ShortPoint3&)
    // ShortPoint3 __cdecl ShortPoint3::*(const ShortPoint3&)
    // float __cdecl ShortPoint3::*()
    // float __cdecl ShortPoint3::*()
    // float __cdecl ShortPoint3::*()
    // void __cdecl ShortPoint3::*(float)
    // void __cdecl ShortPoint3::*(float)
    // void __cdecl ShortPoint3::*(float)
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // const ShortPoint3& __cdecl ShortPoint3::*()
    // void __cdecl ShortPoint3::*(NiStream&)
    // void __cdecl ShortPoint3::*(NiStream&)
    // char* __cdecl ShortPoint3::*(const char*)
};
FNV_STATIC_ASSERT(sizeof(ShortPoint3) == 6);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, y) == 2);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, z) == 4);
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
FNV_STATIC_ASSERT(sizeof(TESBoundObject__BOUND_DATA) == 12);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMax) == 6);
class TESBoundObject : public TESObject
{
  public:
    // base TESObject at +0x0, size 36
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
    // TESBoundObject
    // void __cdecl TESBoundObject::*()
    // bool __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*(NiAVObject*)
    // void __cdecl TESBoundObject::*(TESBoundObject*)
    // NiPoint3 __cdecl TESBoundObject::*()
    // NiPoint3 __cdecl TESBoundObject::*()
    // float __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*()
    // void __cdecl TESBoundObject::*(TESFile*)
    // bool __cdecl TESBoundObject::*(TESObjectREFR*, TESObjectREFR*, bool, TESBoundObject*, int)
    // bool __cdecl TESBoundObject::*(bool)
    // TESBoundObject& __cdecl TESBoundObject::*(const TESBoundObject&)
    // void __cdecl TESBoundObject::*()
};
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 48);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, TESBoundObjectBounds) == 36);
class TESBoundTreeObject : public TESBoundObject
{
  public:
    // base TESBoundObject at +0x0, size 48
    // TESBoundTreeObject
    // void __cdecl TESBoundTreeObject::*()
    // bool __cdecl TESBoundTreeObject::*()
    // bool __cdecl TESBoundTreeObject::*()
    // NiAVObject* __cdecl TESBoundTreeObject::*(TESObjectREFR*)
    // NiAVObject* __cdecl TESBoundTreeObject::*(TESObjectREFR*, bool)
    // void __cdecl TESBoundTreeObject::*(TESObjectREFR*)
    // TESBoundTreeObject& __cdecl TESBoundTreeObject::*(const TESBoundTreeObject&)
    // void __cdecl TESBoundTreeObject::*()
};
FNV_STATIC_ASSERT(sizeof(TESBoundTreeObject) == 48);
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
    // void __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*()
    // bool __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*(CHUNK_ID, const char*)
    // void __cdecl FileEntryList::*(TESFile*, TESForm*, const char*)
    // void __cdecl FileEntryList::*(FileEntryList*)
    // unsigned char __cdecl FileEntryList::*()
    // BSFileEntry** __cdecl FileEntryList::*()
    // void* __cdecl FileEntryList::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
class TESModel : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    static void LoadModelData(TESModel* model, TESFile* file);
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    // TESModel
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*(CHUNK_ID, CHUNK_ID)
    // void __cdecl TESModel::*(BaseFormComponent*)
    // bool __cdecl TESModel::*(BaseFormComponent*)
    // void __cdecl TESModel::*(CHUNK_ID)
    // GetModelLength
    // bool __cdecl TESModel::*(CHUNK_ID)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // bool __cdecl TESModel::*()
    // char __cdecl TESModel::*()
    // void __cdecl TESModel::*(char)
    // bool __cdecl TESModel::*()
    // void __cdecl TESModel::*(bool)
    // unsigned int __cdecl TESModel::*()
    // void __cdecl TESModel::*(unsigned int)
    // bool __cdecl TESModel::*()
    // FileEntryList* __cdecl TESModel::*()
    // TESModel& __cdecl TESModel::*(const TESModel&)
    // void __cdecl TESModel::*()
};
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
class TESModelTree : public TESModel
{
  public:
    // base TESModel at +0x0, size 24
    // void __cdecl TESModelTree::*(const char*)
    // TESModelTree
    // void __cdecl TESModelTree::*()
    // TESModelTree& __cdecl TESModelTree::*(const TESModelTree&)
    // void __cdecl TESModelTree::*()
};
FNV_STATIC_ASSERT(sizeof(TESModelTree) == 24);
class TESTexture1024 : public TESTexture
{
  public:
    // base TESTexture at +0x0, size 12
    // unsigned int __cdecl TESTexture1024::*()
    // TESTexture1024
    // void __cdecl TESTexture1024::*()
    // TESTexture1024& __cdecl TESTexture1024::*(const TESTexture1024&)
    // void* __cdecl TESTexture1024::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(TESTexture1024) == 12);
class TESIconTree : public TESTexture1024
{
  public:
    // base TESTexture1024 at +0x0, size 12
    // char* __cdecl TESIconTree::*()
    // TESIconTree
    // void __cdecl TESIconTree::*()
    // TESIconTree& __cdecl TESIconTree::*(const TESIconTree&)
    // void* __cdecl TESIconTree::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(TESIconTree) == 12);
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    CollisionComponent* pData;  // +0x4, 4 bytes
    void InitItem(TESForm* form);
    static void LoadDestructibleData(BGSDestructibleObjectForm* destructible, TESFile* file);
    // BGSDestructibleObjectForm
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(BGSDestructibleObjectForm*, TESFile*)
    // void __cdecl BGSDestructibleObjectForm::*(BaseFormComponent*)
    // bool __cdecl BGSDestructibleObjectForm::*(BaseFormComponent*)
    // void __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // CollisionComponent* __cdecl BGSDestructibleObjectForm::*()
    // unsigned char __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(unsigned int)
    // bool __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // BGSDestructibleObjectForm* __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // int __cdecl BGSDestructibleObjectForm::*(TESForm*, TESModel*)
    // TESModel* __cdecl BGSDestructibleObjectForm::*(TESForm*, int)
    // bool __cdecl BGSDestructibleObjectForm::*()
    // bool __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(bool)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, float, bool)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BGSExplosion*, unsigned int, TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BGSDebris*, unsigned int, TESObjectREFR*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, unsigned int, BSSimpleArray<NiNode *,1024>&)
    // bool __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, bool)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(NiAVObject*, BSSimpleArray<NiNode *,1024>&)
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // bool __cdecl BGSDestructibleObjectForm::*(NiAVObject*)
    // void __cdecl BGSDestructibleObjectForm::*(TESBoundObject*, IO_TASK_PRIORITY, QueuedFile*)
    // void __cdecl BGSDestructibleObjectForm::*(TESBoundObject*)
    // void __cdecl BGSDestructibleObjectForm::*()
    // bool __cdecl BGSDestructibleObjectForm::*(TESForm*)
    // CalculateDangerousExplosionHealth
    // float __cdecl BGSDestructibleObjectForm::*(unsigned char, float, float, BGSExplosion**)
    // void __cdecl BGSDestructibleObjectForm::*(IDebugText*, TESObjectREFR*)
    // void __cdecl BGSDestructibleObjectForm::*(IDebugText*, TESObjectREFR*)
    // unsigned int __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, float)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*, unsigned int)
    // void __cdecl BGSDestructibleObjectForm::*(TESObjectREFR*)
    // NiTMap<TESObjectREFR *,unsigned int>* __cdecl BGSDestructibleObjectForm::*()
    // float __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*(float)
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // void __cdecl BGSDestructibleObjectForm::*()
    // BGSDestructibleObjectForm& __cdecl BGSDestructibleObjectForm::*(const BGSDestructibleObjectForm&)
    // void* __cdecl BGSDestructibleObjectForm::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 8);
FNV_STATIC_ASSERT(offsetof(BGSDestructibleObjectForm, pData) == 4);
class NiTPrimitiveArray_unsigned_int_ : public NiTArray<unsigned int, NiTMallocInterface<unsigned int> >
{
  public:
    void RemoveAll();
    unsigned int AddFirstEmpty(const unsigned int& seed);
    // base NiTArray<unsigned int,NiTMallocInterface<unsigned int> > at +0x0, size 16
    // NiTPrimitiveArray<unsigned int>
    // void __cdecl NiTPrimitiveArray<unsigned int>::*()
    // NiTPrimitiveArray<unsigned int>& __cdecl NiTPrimitiveArray<unsigned int>::*(const NiTPrimitiveArray<unsigned int>&)
    // void __cdecl NiTPrimitiveArray<unsigned int>::*()
    // void __cdecl NiTPrimitiveArray<unsigned int>::*()
};
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray_unsigned_int_) == 16);
class TreeRecordData
{
  public:
    void Endian();
    float m_fFirstRecordValue;    // +0x0, 4 bytes
    float FiveFloatEndianRecord;  // +0x4, 4 bytes
    float ShadowParameters;       // +0x8, 4 bytes
    float m_fFourthShadowValue;   // +0xC, 4 bytes
    float TreeVisualSettings;     // +0x10, 4 bytes
    int m_iShadowRadius;          // +0x14, 4 bytes
    float m_fRustleMagnitude;     // +0x18, 4 bytes
    float m_fRustleSpeed;         // +0x1C, 4 bytes
    // void __cdecl TreeRecordData::*()
};
FNV_STATIC_ASSERT(sizeof(TreeRecordData) == 32);
FNV_STATIC_ASSERT(offsetof(TreeRecordData, m_fFirstRecordValue) == 0);
FNV_STATIC_ASSERT(offsetof(TreeRecordData, FiveFloatEndianRecord) == 4);
FNV_STATIC_ASSERT(offsetof(TreeRecordData, ShadowParameters) == 8);
FNV_STATIC_ASSERT(offsetof(TreeRecordData, m_fFourthShadowValue) == 12);
FNV_STATIC_ASSERT(offsetof(TreeRecordData, TreeVisualSettings) == 16);
FNV_STATIC_ASSERT(offsetof(TreeRecordData, m_iShadowRadius) == 20);
FNV_STATIC_ASSERT(offsetof(TreeRecordData, m_fRustleMagnitude) == 24);
FNV_STATIC_ASSERT(offsetof(TreeRecordData, m_fRustleSpeed) == 28);
class NiPoint2
{
  public:
    float x;  // +0x0, 4 bytes
    float y;  // +0x4, 4 bytes
    // NiPoint2
    // operator[]
    // bool __cdecl NiPoint2::*(const NiPoint2&)
    // bool __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2 __cdecl NiPoint2::*(const NiPoint2&)
    // operator-
    // operator*
    // NiPoint2 __cdecl NiPoint2::*(float)
    // NiPoint2 __cdecl NiPoint2::*(const NiPoint2&, const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(float)
    // NiPoint2& __cdecl NiPoint2::*(float)
    // float __cdecl NiPoint2::*()
    // float __cdecl NiPoint2::*()
    // float __cdecl NiPoint2::*(const NiPoint2&)
    // float __cdecl NiPoint2::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiPoint2::*(const char*)
};
FNV_STATIC_ASSERT(sizeof(NiPoint2) == 8);
FNV_STATIC_ASSERT(offsetof(NiPoint2, x) == 0);
FNV_STATIC_ASSERT(offsetof(NiPoint2, y) == 4);
class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};

class TESObjectTREE : public TESBoundTreeObject,
                      public TESModelTree,
                      public TESIconTree,
                      public BGSDestructibleObjectForm
{
  public:
    // base TESBoundTreeObject at +0x0, size 48
    // base TESModelTree at +0x30, size 24
    // base TESIconTree at +0x48, size 12
    // base BGSDestructibleObjectForm at +0x54, size 8
    NiTPrimitiveArray_unsigned_int_ m_kSeedArray;  // +0x5C, 16 bytes
    TreeRecordData Data;                           // +0x6C, 32 bytes
    NiPoint2 m_kBillboardDimensions;               // +0x8C, 8 bytes
    TreeRecordData* GetData();
    void UpdateRustleSpeed(const float speed);
    virtual void InitItem();
    bool Load(TESFile* file);
    // TESObjectTREE
    // void __cdecl TESObjectTREE::*()
    // const NiPoint2& __cdecl TESObjectTREE::*()
    // bool __cdecl TESObjectTREE::*()
    // bool __cdecl TESObjectTREE::*(TESFile*)
    // void __cdecl TESObjectTREE::*()
    // void __cdecl TESObjectTREE::*()
    // void __cdecl TESObjectTREE::*(TESForm*)
    // bool __cdecl TESObjectTREE::*(TESForm*)
    // NiNode* __cdecl TESObjectTREE::*(bool)
    // void __cdecl TESObjectTREE::*(char*)
    // void __cdecl TESObjectTREE::*(bool, NiPointer<NiTriShapeData>&)
    // TESObjectTREE& __cdecl TESObjectTREE::*(const TESObjectTREE&)
    // void __cdecl TESObjectTREE::*()
};
FNV_STATIC_ASSERT(sizeof(TESObjectTREE) == 148);
FNV_STATIC_ASSERT(offsetof(TESObjectTREE, m_kSeedArray) == 92);
FNV_STATIC_ASSERT(offsetof(TESObjectTREE, Data) == 108);
FNV_STATIC_ASSERT(offsetof(TESObjectTREE, m_kBillboardDimensions) == 140);
#endif
