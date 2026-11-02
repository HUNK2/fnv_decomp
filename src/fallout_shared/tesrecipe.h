// Unit-local header for fallout_shared/tesrecipe.cpp.
// TESRecipe, TESRecipeCategory, RecipeCraftingInfo, ByteFlags and
#ifndef FNV_TESRECIPE_UNIT_H
#define FNV_TESRECIPE_UNIT_H

#include "layout_support.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESFile.h"
class
    TESConditionItem;  // 1 Nov: the folder-local layout_support.h subset (it wins the shared guard) does not declare it
#include "PerkEntryConditionSet.h"

// with BGSDefaultObjectManager::IsFormInitialized (0x004013e0) through
// identical-COMDAT folding. The canonical TESForm.h does not declare it yet,
// so it is declared on this shim, following the accepted TESFileFormInt
// precedent in tessound.cpp.
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int auiFormID);
};

// declared here on a shim following the TESFormInitFlag precedent.
struct TESConditionInit : public PerkEntryConditionSet
{
    void InitItem(TESForm* apForm);
};

// TESFullName::LoadFullNameChunk is not declared in the bundled TESFullName.h;
// declared here on a shim following the TESFormInitFlag precedent.
// 1 Nov: TESFullNameLoader is declared by the folder-local layout_support.h (a second definition here was C2011)

int Warning(const char* apFormat, ...);

#pragma pack(push, 4)
class ByteFlags
{
  public:
    unsigned char flags;  // +0x0, 1 bytes
    void Endian();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ByteFlags) == 1);
FNV_STATIC_ASSERT(offsetof(ByteFlags, flags) == 0);

#pragma pack(push, 4)
class RecipeCraftingInfo
{
  public:
    int m_iRequiredLevel;  // +0x0, 4 bytes
    int m_iSkill;          // +0x4, 4 bytes
    int CategoryID;        // +0x8, 4 bytes
    int SubCategoryID;     // +0xC, 4 bytes
    void Endian();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RecipeCraftingInfo) == 16);
FNV_STATIC_ASSERT(offsetof(RecipeCraftingInfo, m_iRequiredLevel) == 0);
FNV_STATIC_ASSERT(offsetof(RecipeCraftingInfo, m_iSkill) == 4);
FNV_STATIC_ASSERT(offsetof(RecipeCraftingInfo, CategoryID) == 8);
FNV_STATIC_ASSERT(offsetof(RecipeCraftingInfo, SubCategoryID) == 12);

#pragma pack(push, 4)
class TESRecipeCategory : public TESForm, public TESFullName
{
  public:
    // base TESForm at +0x0, size 24
    // base TESFullName at +0x18, size 12
    ByteFlags data;  // +0x24, 1 bytes
    unsigned char layoutPadding25[3];
    virtual bool Load(TESFile* file);
    void ReadTypedData(TESFile* apFile, void* apData, unsigned short ausSize);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESRecipeCategory) == 40);
FNV_STATIC_ASSERT(offsetof(TESRecipeCategory, data) == 36);

#pragma pack(push, 4)
class QuantityData
{
  public:
    unsigned int Quantity;  // +0x0, 4 bytes
    TESForm* m_pItemForm;   // +0x4, 4 bytes
    QuantityData();
    unsigned int GetQuantity();
    void SetQuantity(unsigned int auiQuantity);
    TESForm* GetItem();
    void SetItem(TESForm* apItem);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(QuantityData) == 8);
FNV_STATIC_ASSERT(offsetof(QuantityData, Quantity) == 0);
FNV_STATIC_ASSERT(offsetof(QuantityData, m_pItemForm) == 4);

#pragma pack(push, 4)
class TESRecipe : public TESForm, public TESFullName
{
  public:
    // base TESForm at +0x0, size 24
    // base TESFullName at +0x18, size 12
    RecipeCraftingInfo data;                         // +0x24, 16 bytes
    PerkEntryConditionSet RecipeItemProcessor;                // +0x34, 8 bytes
    BSSimpleList<QuantityData*> m_kIngredientList;   // +0x3C, 8 bytes
    BSSimpleList<QuantityData*> m_kSecondEntryList;  // +0x44, 8 bytes
    BSSimpleList<QuantityData*> RecipeCollection;    // +0x4C, 8 bytes
    TESRecipeCategory* pRecipeCat;                   // +0x54, 4 bytes
    TESRecipeCategory* m_pSubCategory;               // +0x58, 4 bytes
    virtual void ClearData();
    virtual void InitItem();
    virtual bool Load(TESFile* file);
    RecipeCraftingInfo* GetData();
    PerkEntryConditionSet* GetConditions();
    BSSimpleList<QuantityData*>* GetIngredientList();
    BSSimpleList<QuantityData*>* GetOutputList();
    BSSimpleList<QuantityData*>* GetGarbageList();
    void SetSkill(int aiSkill);
    void SetSkillLevel(int aiLevel);
    void SetCategory(TESRecipeCategory* apCategory);
    void SetSubCategory(TESRecipeCategory* apSubCategory);
    void ReadTypedData(TESFile* apFile, void* apData, unsigned short ausSize);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESRecipe) == 92);
FNV_STATIC_ASSERT(offsetof(TESRecipe, data) == 36);
FNV_STATIC_ASSERT(offsetof(TESRecipe, RecipeItemProcessor) == 52);
FNV_STATIC_ASSERT(offsetof(TESRecipe, m_kIngredientList) == 60);
FNV_STATIC_ASSERT(offsetof(TESRecipe, m_kSecondEntryList) == 68);
FNV_STATIC_ASSERT(offsetof(TESRecipe, RecipeCollection) == 76);
FNV_STATIC_ASSERT(offsetof(TESRecipe, pRecipeCat) == 84);
FNV_STATIC_ASSERT(offsetof(TESRecipe, m_pSubCategory) == 88);
#endif
