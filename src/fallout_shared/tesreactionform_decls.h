// fallout_shared/tesreactionform_decls.h: declares BaseProcess, TESReactionForm, TESReactionMapStorage, FormChangeMask, BGSLoadFormBuffer and more
#ifndef FNV_TESREACTIONFORM_PRIVATE_DECLS_H
#define FNV_TESREACTIONFORM_PRIVATE_DECLS_H


#include "BaseFormComponent.h"

class ReactionInfo
{
  public:
    unsigned int formID;
};
class BGSLoadFormBuffer;
class TESForm;
class ActorPackageContext;
class InventoryStackRecord;

class BaseProcess
{
  public:
    ActorPackageContext* GetCurrentProcessData();
};

// This private declaration preserves the canonical class layout while exposing
// members needed by the functions matched in this translation unit.
#ifndef FNV_TESREACTIONFORM_H
#define FNV_TESREACTIONFORM_H
#endif

#pragma pack(push, 4)
class TESReactionForm : public BaseFormComponent
{
  public:
    BSSimpleList<ReactionInfo*> m_kReactionList;
    unsigned char m_ucReactionFlags;
    unsigned char layoutPaddingD[3];

    void InitializeComponent();
    void ClearComponent();
    void ClearReactionList();
    void InitLoadGame(BGSLoadFormBuffer* buffer);
    void InitItem(TESForm* form);
};
#pragma pack(pop)

FNV_STATIC_ASSERT(sizeof(TESReactionForm) == 0x10);
FNV_STATIC_ASSERT(offsetof(TESReactionForm, m_kReactionList) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESReactionForm, m_ucReactionFlags) == 0xC);

#endif

class DistantTreeTextureInfo;
// Storage constructor at 0x0048b3e0; its original class identity is unresolved.
class TESReactionMapStorage
{
  public:
    TESReactionMapStorage(unsigned int);
    virtual void mapSlot();
};
template <class K, class V> class BSMapBase : public TESReactionMapStorage
{
  public:
    BSMapBase(unsigned int);
    virtual void mapSlot();
};

class FormChangeMask
{
  public:
    int flags;
    operator bool() const;
};
class BGSLoadFormBuffer
{
  public:
    FormChangeMask GetChangeFlags(unsigned int);
};
class BGSCameraShot;
template <> class BSSimpleList<BGSCameraShot*>
{
  public:
    BGSCameraShot* item;
    BSSimpleList* next;
    bool IsEmpty();
    BGSCameraShot*& GetItem();
    BSSimpleList* GetNext();
    void Remove(BGSCameraShot* const&);
    void RemoveHead();
};

#ifndef FNV_TESFORM_H
#define FNV_TESFORM_H
class TESForm
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
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
#endif
int Warning(const char*, ...);
