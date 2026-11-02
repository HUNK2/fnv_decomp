// Authored research header for fallout_shared/magic/magicitem.cpp.
//   TESForm 0x18, TESBoundObject 0x30, TESFullName 0xC,
//   EffectItemList 0x10 (vftable + BSSimpleList<EffectItem*> base at +4,
//   hostile count at +0xC), MagicItem 0x1C (TESFullName + EffectItemList).
// MagicItemForm carries MagicItem as second base at +0x18;
// MagicItemObject carries it as second base at +0x30.
#ifndef FNV_MAGICITEM_DECLS_H
#define FNV_MAGICITEM_DECLS_H

#include "layout_support.h"

struct MagicSystem
{
    enum Range
    {
        SELF = 0,
        TOUCH = 1,
        TARGET = 2,
        RANGE_COUNT = 3
    };
};

class TESForm
{
  public:
    virtual ~TESForm();
    unsigned char formPad[20];
    static TESForm* GetFormByID(unsigned int auiFormID);
};
FNV_STATIC_ASSERT(sizeof(TESForm) == 0x18);

class TESBoundObject : public TESForm
{
  public:
    virtual ~TESBoundObject();
    unsigned char boundPad[24];
};
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 0x30);

class TESFullName
{
  public:
    virtual ~TESFullName();
    unsigned char namePad[8];
};
FNV_STATIC_ASSERT(sizeof(TESFullName) == 0xC);

// in EffectSetting. The unused tail of TESModel is retained at its real size.
class TESModel
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(TESModel* component);
    virtual bool CompareWithBase(TESModel* component);
    BSStringT<char> m_kModelFilePath;
    unsigned char modelTail[12];
    virtual void vfn_10();
    virtual const char* GetModelFilePath();
    unsigned int GetModelLength() const;
};
FNV_STATIC_ASSERT(sizeof(TESModel) == 0x18);

class EffectSetting : public TESForm, public TESModel
{
  public:
    bool FUN_00403e60(unsigned int);
    int FUN_004087e0();
    int FUN_004089c0();
    TESForm* FUN_005f5f80();
    void FUN_004088c0();
    void UpdateCounter();
    bool IsAssociatedFormUsed();
    bool HasEffectID();
    bool UsesAssociatedActorValue();
    bool IsModelLoaded();
    bool HasNoAssociatedActorValue();
};

class EffectItem
{
  public:
    void InitItem(TESForm* apForm);
    bool IsHostile();
    float GetCost(Actor* pActor);
    bool IsDetrimental();
    MagicSystem::Range GetRange();
    EffectSetting* GetEffectSetting();
};

class EffectItemList : public BSSimpleList<EffectItem*>
{
  public:
    virtual ~EffectItemList();
    int m_iEffectCount;
};
FNV_STATIC_ASSERT(sizeof(EffectItemList) == 0x10);

class MagicItem : public TESFullName, public EffectItemList
{
  public:
    virtual ~MagicItem();
    static MagicItem* GetMagicItemByID(unsigned int auiID);
    EffectSetting* GetEffectSettingForRange(MagicSystem::Range aeRange);
    void ClearEffectList();
    void Preload(bool);
    void Unload(bool);
    bool IsLoaded();
    bool IsLoading();

  protected:
    void LoadEffectsFromForm(TESForm* apForm);
};
FNV_STATIC_ASSERT(sizeof(MagicItem) == 0x1C);

class MagicItemForm : public TESForm, public MagicItem
{
  public:
    virtual ~MagicItemForm();
};

class MagicItemObject : public TESBoundObject, public MagicItem
{
  public:
    virtual ~MagicItemObject();
};

// PC component offsets used by associated weapon, armor, and creature loads.
class TESObjectWEAP : public TESBoundObject
{
  public:
    unsigned char fullName[12];
    TESModel model;
};
class TESBipedModelForm
{
  public:
    const char* GetBipedModel(int);
};
class TESObjectARMO : public TESBoundObject
{
  public:
    unsigned char components[0x40];
    TESBipedModelForm biped;
};
class TESNPC : public TESForm
{
  public:
    BSSimpleList<const char*>* GetModelFiles(bool, bool);
};
class TESAnimation
{
  public:
    unsigned char data[0x18];
    bool HasSpecialAnimations();
    BSSimpleList<const char*>* FUN_00717e50();
};
class TESModelList
{
  public:
    BSSimpleList<const char*>* FUN_00717e50();
};
class TESCreature : public TESForm
{
  public:
    unsigned char actorComponents[0xAC];
    TESAnimation animation;
    TESModel model;
    unsigned char creatureComponents[0x20];
    TESModelList modelList;
};
class Model
{
  public:
    void SetManualRefCount(int);
    void FUN_0092c870();
    const char* FUN_00559450();
};
template <class T> class NiPointer
{
    T* object;

  public:
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
};
class KFModel;
class ModelLoader
{
  public:
    void QueueMagicEffectModel(MagicItem*, EffectSetting*, int);
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
    bool FUN_004472a0(const char*, NiPointer<Model>&);
    KFModel* LoadKF(const char*);
    BSSimpleList<const char*>* GetModelFileList(const char*, bool, bool, int);
};
void FUN_0040ab50();
extern ModelLoader* g_modelLoader;
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
int strcat_s(char*, unsigned int, const char*);
char* FUN_0040ab30(char*, int);
extern "C" const char* strrchr(const char*, int);
extern "C" int _strnicmp(const char*, const char*, unsigned int);
extern "C" void FormHeapFreeAndLog(const void*);
#endif
