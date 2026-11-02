// fallout_shared/bgsequiptype_decls.h: declares TESForm, BGSEquipType
#ifndef BGSEQUIPTYPE_DECLS_H
#define BGSEQUIPTYPE_DECLS_H
enum ENUM_FORM_ID
{
    FORM_NONE = 0
};
class TESForm
{
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
