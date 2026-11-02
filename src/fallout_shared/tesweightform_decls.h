// fallout_shared/tesweightform_decls.h: declares TESForm, TESBoundObject, TESWeightForm
#ifndef FNV_TESWEIGHTFORM_DECLS_H
#define FNV_TESWEIGHTFORM_DECLS_H


enum ENUM_FORM_ID
{
    ENUM_FORM_ID_Unknown = 0
};

class TESForm
{
  public:
    float GetFieldB8Float();
};

class TESBoundObject
{
  public:
    int GetFormType() const;
};
class ActiveEffect
{
  public:
    float GetAge();
};

class TESWeightForm
{
  public:
    float GetWeightForForm() const;
    static float GetWeightForForm(TESForm* form, bool useFormWeight);
};

#endif
