// Unit-local PC header for fallout_shared/tesfurniture.cpp.
// inheritance this-adjustments match the game layout:
//   TESObjectACTI (144 bytes): +0x00 TESBoundAnimObject (48), +0x30 TESFullName
//   (12), +0x3C TESModelTextureSwap (32), +0x5C TESScriptableForm (12),
//   +0x68 BGSDestructibleObjectForm (8), +0x70 BGSOpenCloseForm (4),
//   members at +0x74..0x8F.
//   TESFurniture adds int m_iMarkerCount at +0x90 (148 bytes total).
#ifndef FNV_TESFURNITURE_UNIT_H
#define FNV_TESFURNITURE_UNIT_H

#include "layout_support.h"
#include "TESForm.h"
#include "TESFile.h"
#include "TESFullName.h"
#include "TESScriptableForm.h"
#include "BaseFormComponent.h"
#include "NiPoint3.h"
class NiAVObject;

// with BGSDefaultObjectManager::IsFormInitialized (0x004013e0) through
// identical-COMDAT folding. The canonical TESForm.h does not declare it yet,
// so it is declared on this shim, following the accepted TESFileFormInt
// precedent in tessound.cpp.
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
};

#pragma pack(push, 4)
// TESObject/TESBoundObject/TESBoundAnimObject chain flattened to its 48-byte
// PC size; the vtable pointer is inherited from TESForm.
class TESBoundAnimObject : public TESForm
{
  public:
    unsigned char layoutPadding18[0x18];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundAnimObject) == 0x30);
// TESModel (24 bytes) plus the texture-swap list (8 bytes).
#pragma pack(push, 4)
class TESModelTextureSwap : public BaseFormComponent
{
  public:
    unsigned char layoutPadding04[0x1C];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModelTextureSwap) == 0x20);
class CollisionComponent;
#pragma pack(push, 4)
class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    CollisionComponent* pData;  // +0x4
    void InitItem(TESForm* form);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSDestructibleObjectForm) == 0x8);
FNV_STATIC_ASSERT(offsetof(BGSDestructibleObjectForm, pData) == 0x4);
#pragma pack(push, 4)
class BGSOpenCloseForm
{
  public:
    void* m_ppVirtualMethodTable;  // +0x0
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSOpenCloseForm) == 0x4);
FNV_STATIC_ASSERT(offsetof(BGSOpenCloseForm, m_ppVirtualMethodTable) == 0x0);
#pragma pack(push, 4)
class TESObjectACTI : public TESBoundAnimObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESScriptableForm,
                      public BGSDestructibleObjectForm,
                      public BGSOpenCloseForm
{
  public:
    unsigned char layoutPadding74[0x1C];  // sounds, water, radio, override text
    void ResetFormData();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObjectACTI) == 0x90);
#pragma pack(push, 4)
class TESFurniture : public TESObjectACTI
{
  public:
    int m_iMarkerCount;  // +0x90
    TESFurniture();
    void ResetFormData();
    void InitItem();
    bool Load(TESFile* file);
    bool GetCanSitOn();
    void SetCanSitOn(bool bSit);
    bool GetCanSleepOn();
    void SetCanSleepOn(bool bSleep);
    bool IsMarkerEnabled(unsigned int aiMarker);
    void SetMarkerEnabled(unsigned int aiMarker, bool bEnabled);
    void UpdateSitSleepFlags(NiAVObject* apMarker);
    static unsigned int GetMarkerCount(NiAVObject* apMarker);
    static unsigned int GetMarkerNumber(NiAVObject* apMarker, unsigned int auMarker);
    static bool IsFurnitureSitMarker(unsigned int auMarker);
    static bool IsFurnitureSleepMarker(unsigned int auMarker);
    void InitializeMarkerFlags();
    NiPoint3 GetMarkerOffset(unsigned int auMarker, float afScale);
    float GetMarkerRotation(unsigned int auMarker);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESFurniture) == 0x94);
FNV_STATIC_ASSERT(offsetof(TESFurniture, m_iMarkerCount) == 0x90);
#endif
