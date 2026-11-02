// fallout_shared/magic/MagicItemFormTask.h: declares TESForm, MagicItemForm, MagicItem
#ifndef LUNA_MAGICITEMFORM_TASK_H
#define LUNA_MAGICITEMFORM_TASK_H

class TESForm
{
  public:
    virtual void InitItem();
    bool IsFormInitialized() const;
    void SetInitializationState(bool initialized);
};
class MagicItemForm : public TESForm
{
  public:
    virtual void InitItem();
};
class MagicItem
{
  public:
    void LoadEffectsFromForm(TESForm* form);
};
#endif
