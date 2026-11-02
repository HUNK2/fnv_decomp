// Layout asserts are preserved; the member declarations used by
// fallout_shared/tescaravan.cpp are added below each class.
#ifndef FNV_TASK_TESCARAVAN_COPY_H
#define FNV_TASK_TESCARAVAN_COPY_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "TESIcon.h"
#include "TESTexture.h"

class TESFormList;
class TESSound;
class Script;
class DistantTreeTextureInfo;
class BSFileEntry;
class TESCaravanCard;
class TESCaravanMoney;

#pragma pack(push, 4)
class TESObject : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObject) == 36);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pOwningList) == 24);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pPreviousObject) == 28);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pNextObject) == 32);

#pragma pack(push, 4)
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ShortPoint3) == 6);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, y) == 2);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, z) == 4);

#pragma pack(push, 4)
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject__BOUND_DATA) == 12);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMax) == 6);

#pragma pack(push, 4)
class TESBoundObject : public TESObject
{
  public:
    // base TESObject at +0x0, size 36
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 48);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, TESBoundObjectBounds) == 36);

#pragma pack(push, 4)
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);

#pragma pack(push, 4)
class TESModel : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);

#pragma pack(push, 4)
class TESModelTextureSwap : public TESModel
{
  public:
    // base TESModel at +0x0, size 24
    BSSimpleList<DistantTreeTextureInfo*> TextureSwapNodeAccessor;  // +0x18, 8 bytes
    void InitItem(TESForm* form);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModelTextureSwap) == 32);
FNV_STATIC_ASSERT(offsetof(TESModelTextureSwap, TextureSwapNodeAccessor) == 24);

#pragma pack(push, 4)
class BGSMessageIcon : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    TESIcon Icon;  // +0x4, 12 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSMessageIcon) == 16);
FNV_STATIC_ASSERT(offsetof(BGSMessageIcon, Icon) == 4);

#pragma pack(push, 4)
class TESValueForm : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    unsigned int iValue;  // +0x4, 4 bytes
    ~TESValueForm();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESValueForm) == 8);
FNV_STATIC_ASSERT(offsetof(TESValueForm, iValue) == 4);

#pragma pack(push, 4)
class TESScriptableForm : public BaseFormComponent
{
  public:
    Script* m_pFormScript;  // +0x4
    bool m_bHasScript;      // +0x8
    unsigned char layoutPadding9[3];
    void InitItem(TESForm* form);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESScriptableForm) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESScriptableForm, m_pFormScript) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESScriptableForm, m_bHasScript) == 0x8);

#pragma pack(push, 4)
class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    TESSound* m_pPickupSound;   // +0x4, 4 bytes
    TESSound* m_pPutdownSound;  // +0x8, 4 bytes
    ~BGSPickupPutdownSounds();
    void InitItem(TESForm* form);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSPickupPutdownSounds) == 12);
FNV_STATIC_ASSERT(offsetof(BGSPickupPutdownSounds, m_pPickupSound) == 4);
FNV_STATIC_ASSERT(offsetof(BGSPickupPutdownSounds, m_pPutdownSound) == 8);

#pragma pack(push, 4)
class UnsignedValuePair
{
  public:
    unsigned int m_uiFirstValue;   // +0x0, 4 bytes
    unsigned int m_uiSecondValue;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(UnsignedValuePair) == 8);
FNV_STATIC_ASSERT(offsetof(UnsignedValuePair, m_uiFirstValue) == 0);
FNV_STATIC_ASSERT(offsetof(UnsignedValuePair, m_uiSecondValue) == 4);

#pragma pack(push, 4)
class TESCaravanCard : public TESBoundObject,
                       public TESFullName,
                       public TESModelTextureSwap,
                       public TESIcon,
                       public BGSMessageIcon,
                       public TESValueForm,
                       public TESScriptableForm,
                       public BGSPickupPutdownSounds
{
  public:
    // base TESBoundObject at +0x0, size 48
    // base TESFullName at +0x30, size 12
    // base TESModelTextureSwap at +0x3C, size 32
    // base TESIcon at +0x5C, size 12
    // base BGSMessageIcon at +0x68, size 16
    // base TESValueForm at +0x78, size 8
    // base TESScriptableForm at +0x80, size 12
    // base BGSPickupPutdownSounds at +0x8C, size 12
    bool bIsActive;  // +0x98, 1 bytes
    unsigned char layoutPadding99[3];
    TESTexture m_kFrontTexture;  // +0x9C, 12 bytes
    TESTexture m_kBackTexture;   // +0xA8, 12 bytes
    UnsignedValuePair data;      // +0xB4, 8 bytes
    TESCaravanCard();
    void ResetFormData();
    void InitItem();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESCaravanCard) == 188);
FNV_STATIC_ASSERT(offsetof(TESCaravanCard, bIsActive) == 152);
FNV_STATIC_ASSERT(offsetof(TESCaravanCard, m_kFrontTexture) == 156);
FNV_STATIC_ASSERT(offsetof(TESCaravanCard, m_kBackTexture) == 168);
FNV_STATIC_ASSERT(offsetof(TESCaravanCard, data) == 180);

#pragma pack(push, 4)
class TESCaravanMoney : public TESBoundObject,
                        public TESFullName,
                        public TESModelTextureSwap,
                        public TESIcon,
                        public BGSMessageIcon,
                        public TESValueForm,
                        public BGSPickupPutdownSounds
{
  public:
    // base TESBoundObject at +0x0, size 48
    // base TESFullName at +0x30, size 12
    // base TESModelTextureSwap at +0x3C, size 32
    // base TESIcon at +0x5C, size 12
    // base BGSMessageIcon at +0x68, size 16
    // base TESValueForm at +0x78, size 8
    // base BGSPickupPutdownSounds at +0x80, size 12
    TESModelTextureSwap m_kModelTextureSwaps[2];  // +0x8C, 64 bytes
    void ResetFormData();
    void InitItem();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESCaravanMoney) == 204);
FNV_STATIC_ASSERT(offsetof(TESCaravanMoney, m_kModelTextureSwaps) == 140);

// Unit-local shim: TESFormInitFlag declares IsFormInitialized used by InitItem.
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
};

#pragma pack(push, 4)
class CaravanDeckData
{
  public:
    int m_iValue;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CaravanDeckData) == 4);
FNV_STATIC_ASSERT(offsetof(CaravanDeckData, m_iValue) == 0);

#pragma pack(push, 4)
class TESCaravanDeck : public TESForm, public TESFullName
{
  public:
    // base TESForm at +0x0, size 24
    // base TESFullName at +0x18, size 12
    BSSimpleList<TESCaravanCard*>* m_pCardListHeadCur;  // +0x24, 4 bytes
    CaravanDeckData data;                  // +0x28, 4 bytes
    TESCaravanDeck();
    void ResetFormData();
    virtual bool Load(TESFile* file);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESCaravanDeck) == 44);
FNV_STATIC_ASSERT(offsetof(TESCaravanDeck, m_pCardListHeadCur) == 36);
FNV_STATIC_ASSERT(offsetof(TESCaravanDeck, data) == 40);
#endif
