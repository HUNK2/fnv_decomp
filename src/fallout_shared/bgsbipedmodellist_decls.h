// fallout_shared/bgsbipedmodellist_decls.h: declares TESForm, BGSCameraPath, BGSListForm, TESBipedModelForm, BGSBipedModelList and more
#ifndef BGSBIPEDMODELLIST_DECLS_H
#define BGSBIPEDMODELLIST_DECLS_H

enum ENUM_FORM_ID
{
    kArmor = 24,
    kNPC = 40
};
class TESFile;
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
    virtual const char* GetName();
    ENUM_FORM_ID GetFormType() const;
    TESFile* GetFile(int);
    unsigned int GetFormID();
    static TESForm* GetFormByID(unsigned int);
    static void RemapFormIDForFile(unsigned int&, TESFile*);
};
class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList<T>* GetNext();
};
class BGSCameraShot;
template <> class BSSimpleList<BGSCameraShot*>
{
  public:
    bool IsEmpty();
};
class PerkEntryConditionSet;
class BGSCameraPath
{
  public:
    int HasNameForWarning();
    PerkEntryConditionSet* GetConditions();
};
class BGSListForm : public TESForm
{
};
class TESBipedModelForm
{
  public:
    static TESBipedModelForm* GetFormAsBipedModel(TESForm*);
    void FUN_00480d50(bool);
};
int Warning(const char*, ...);
extern char DAT_0101a5f0[], DAT_0101a5a0[], DAT_0101a558[], DAT_0101a4d8[];

class BGSBipedModelList
{
  public:
    void* vf;
    BGSListForm* list;
    void InitItem(TESForm*);
    static BGSBipedModelList* GetBipedModelList(TESForm*);
};
class TESNPC : public TESForm
{
    char pad[0xe0 - sizeof(TESForm)];

  public:
    BGSBipedModelList biped;
};
class TESObjectARMO : public TESForm
{
    char pad[0x164 - sizeof(TESForm)];

  public:
    BGSBipedModelList biped;
};
#endif
