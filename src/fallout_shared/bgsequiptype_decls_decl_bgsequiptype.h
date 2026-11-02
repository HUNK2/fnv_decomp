// fallout_shared/bgsequiptype_decls_decl_bgsequiptype.h: declares TESForm, BGSEquipType
#ifndef BGSEQUIPTYPE_DECLS_H
#define BGSEQUIPTYPE_DECLS_H

enum ENUM_FORM_ID
{
    FORM_NONE = 0
};
class TESForm
{
  public:
    unsigned char m_ucFormType;
    unsigned char cFormPad05[3];
    unsigned int m_uiFormFlags;
    unsigned int iFormID;
    void* m_kSourceFiles[2];  // declared for the original code (decl_variants.py)

  public:
    virtual ~TESForm();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    ENUM_FORM_ID GetFormType() const;
};
class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    BSSimpleList<T>* GetNext();
};
class BGSEquipType
{
  public:
    enum EQUIP_TYPE
    {
        ET_NONE = -1
    };
    static EQUIP_TYPE GetEquipType(TESForm* form);
};
#endif
