// Authored declarations for the form component classes used as the dynamic_cast
//
// Descriptors (bound to its canonical .data address by the unit manifest), and
// BaseFormComponent* and receives the cast results. Only the RTTI identity of
// each target is needed by this unit, so no member layout is declared; the
// virtual destructor makes each class polymorphic for dynamic_cast.
#ifndef FNV_FORMCOMPONENTS_H
#define FNV_FORMCOMPONENTS_H
#include "BaseFormComponent.h"
class TESAIForm : public BaseFormComponent
{
  public:
    virtual ~TESAIForm();
};
class TESActorBaseData : public BaseFormComponent
{
  public:
    virtual ~TESActorBaseData();
};
class TESAttackDamageForm : public BaseFormComponent
{
  public:
    virtual ~TESAttackDamageForm();
};
class TESAttributes : public BaseFormComponent
{
  public:
    virtual ~TESAttributes();
};
class TESBipedModelForm : public BaseFormComponent
{
  public:
    virtual ~TESBipedModelForm();
};
class TESContainer : public BaseFormComponent
{
  public:
    virtual ~TESContainer();
};
class TESDescription : public BaseFormComponent
{
  public:
    virtual ~TESDescription();
};
class TESEnchantableForm : public BaseFormComponent
{
  public:
    virtual ~TESEnchantableForm();
};
class TESFullName : public BaseFormComponent
{
  public:
    virtual ~TESFullName();
};
class TESHealthForm : public BaseFormComponent
{
  public:
    virtual ~TESHealthForm();
};
class TESTexture : public BaseFormComponent
{
  public:
    virtual ~TESTexture();
};
class TESLeveledList : public BaseFormComponent
{
  public:
    virtual ~TESLeveledList();
};
class TESModel : public BaseFormComponent
{
  public:
    virtual ~TESModel();
};
class TESProduceForm : public BaseFormComponent
{
  public:
    virtual ~TESProduceForm();
};
class TESQualityForm : public BaseFormComponent
{
  public:
    virtual ~TESQualityForm();
};
class TESRaceForm : public BaseFormComponent
{
  public:
    virtual ~TESRaceForm();
};
class TESScriptableForm : public BaseFormComponent
{
  public:
    virtual ~TESScriptableForm();
};
class TESSpellList : public BaseFormComponent
{
  public:
    virtual ~TESSpellList();
};
class TESUsesForm : public BaseFormComponent
{
  public:
    virtual ~TESUsesForm();
};
class TESValueForm : public BaseFormComponent
{
  public:
    virtual ~TESValueForm();
};
class TESWeightForm : public BaseFormComponent
{
  public:
    virtual ~TESWeightForm();
};
class TESSoundFile : public BaseFormComponent
{
  public:
    virtual ~TESSoundFile();
};
class TESReactionForm : public BaseFormComponent
{
  public:
    virtual ~TESReactionForm();
};
class TESAnimation : public BaseFormComponent
{
  public:
    virtual ~TESAnimation();
};
class TESModelList : public BaseFormComponent
{
  public:
    virtual ~TESModelList();
};
class BGSClipRoundsForm : public BaseFormComponent
{
  public:
    virtual ~BGSClipRoundsForm();
};
class BGSAmmoForm : public BaseFormComponent
{
  public:
    virtual ~BGSAmmoForm();
};
class BGSIdleCollection : public BaseFormComponent
{
  public:
    virtual ~BGSIdleCollection();
};
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    virtual ~BGSDestructibleObjectForm();
};
class BGSRepairItemList : public BaseFormComponent
{
  public:
    virtual ~BGSRepairItemList();
};
class BGSEquipType : public BaseFormComponent
{
  public:
    virtual ~BGSEquipType();
};
class BGSBipedModelList : public BaseFormComponent
{
  public:
    virtual ~BGSBipedModelList();
};
class TESImageSpaceModifiableForm : public BaseFormComponent
{
  public:
    virtual ~TESImageSpaceModifiableForm();
};
template <int Count> class TESImageSpaceModifiableCountForm : public BaseFormComponent
{
  public:
    virtual ~TESImageSpaceModifiableCountForm();
};
class BGSMessageIcon : public BaseFormComponent
{
  public:
    virtual ~BGSMessageIcon();
};
class BGSTouchSpellForm : public BaseFormComponent
{
  public:
    virtual ~BGSTouchSpellForm();
};
class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    virtual ~BGSPickupPutdownSounds();
};
#endif
