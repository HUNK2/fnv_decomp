// fallout/misc/saveload/types_TESForm_GetFormType.h: declares TESForm
#ifndef FNV_TESFORM_GETFORMTYPE_H
#define FNV_TESFORM_GETFORMTYPE_H


enum ENUM_FORM_ID
{
    ENUM_FORM_ID_Unknown = 0
};
class TESForm
{
  public:
    ENUM_FORM_ID GetFormType() const;
};

#endif
