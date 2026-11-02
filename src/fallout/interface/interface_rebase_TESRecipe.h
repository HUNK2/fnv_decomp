// fallout/interface/interface_rebase_TESRecipe.h: declares TESRecipe
#ifndef FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_TESRECIPE_DECLARATION_H
#define FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_TESRECIPE_DECLARATION_H
#include "interface_rebase_TESForm.h"
#include "interface_rebase_TESFullName.h"
#include "interface_rebase_TESCondition.h"
class TESRecipeCategory;
class QuantityData;
class TESRecipe : public TESForm, public TESFullName
{
  public:
    TESRecipe();
    ~TESRecipe();
    struct Data
    {
        ActorValue::Index eReqSkill;
        int iReqSkillLevel;
        unsigned int uiCategoryID;
        unsigned int uiSubCategoryID;
    };
    Data kData;
    PerkEntryConditionSet kConditions;
    BSSimpleList<QuantityData*> kIngredients;
    BSSimpleList<QuantityData*> kOutputs;
    BSSimpleList<QuantityData*> kGarbageCollection;
    TESRecipeCategory* pCategory;
    TESRecipeCategory* pSubCategory;
    void SetRequiredSkill(ActorValue::Index);
};
FNV_STATIC_ASSERT(sizeof(TESRecipe::Data) == 0x10);
FNV_STATIC_ASSERT(offsetof(TESRecipe::Data, eReqSkill) == 0);
FNV_STATIC_ASSERT(offsetof(TESRecipe::Data, iReqSkillLevel) == 4);
FNV_STATIC_ASSERT(offsetof(TESRecipe::Data, uiCategoryID) == 8);
FNV_STATIC_ASSERT(offsetof(TESRecipe::Data, uiSubCategoryID) == 12);
FNV_STATIC_ASSERT(sizeof(TESRecipe) == 0x5C);
FNV_STATIC_ASSERT(offsetof(TESRecipe, kData) == 0x24);
FNV_STATIC_ASSERT(offsetof(TESRecipe, kConditions) == 0x34);
FNV_STATIC_ASSERT(offsetof(TESRecipe, kIngredients) == 0x3C);
FNV_STATIC_ASSERT(offsetof(TESRecipe, kOutputs) == 0x44);
FNV_STATIC_ASSERT(offsetof(TESRecipe, kGarbageCollection) == 0x4C);
FNV_STATIC_ASSERT(offsetof(TESRecipe, pCategory) == 0x54);
FNV_STATIC_ASSERT(offsetof(TESRecipe, pSubCategory) == 0x58);
#endif
