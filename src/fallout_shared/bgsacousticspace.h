// Unit-local PC header for fallout_shared/bgsacousticspace.cpp.
//   TESBoundObject base (48 bytes), m_bIsInterior +0x30,
//   pDawnSound +0x34, pNoonSound +0x38, pDuskSound +0x3C,
//   pNightSound +0x40, pWallaSound +0x44, pRegion +0x48,
//   m_eCellEnvironmentType +0x4C, m_iFlags +0x50 (84 bytes total).
// only sizes and polymorphism matter for this unit's codegen.
// TESSound/TESRegion are minimal polymorphic derivations sufficient for the
// InitItem dynamic_casts; their real definitions live in other units.
#ifndef FNV_BGSACOUSTICSPACE_UNIT_H
#define FNV_BGSACOUSTICSPACE_UNIT_H

#include "layout_support.h"
#include "TESForm.h"

// with BGSDefaultObjectManager::IsFormInitialized (0x004013e0) through
// identical-COMDAT folding. The canonical TESForm.h does not declare it yet,
// so it is declared on this shim, following the accepted TESFileFormInt
// precedent in tessound.cpp.
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int auiFormID);
};

#pragma pack(push, 4)
class TESObject : public TESForm
{
  public:
    unsigned char layoutPadding18[0xC];  // +0x18 parent list, prev, next
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObject) == 0x24);

#pragma pack(push, 4)
class TESBoundObject : public TESObject
{
  public:
    unsigned char layoutPadding24[0xC];  // +0x24 bound min/max
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 0x30);

class TESSound : public TESBoundObject
{
};

class TESRegion : public TESForm
{
    void* m_pRegionDataList;
    void* pRegionPointList;
    void* m_pContainingWorldspace;
    void* m_pRegionWeather;
    float fWeatherChance;
    char m_kDiffuseColor[12];
};

enum CELL_ENVIRO_TYPE
{
    CELL_ENVIRO_TYPE_CET_NONE = 0,
    CELL_ENVIRO_TYPE_CET_DEFAULT = 1,
    CELL_ENVIRO_TYPE_CET_GENERIC = 2,
    CELL_ENVIRO_TYPE_CET_PADDEDCELL = 3,
    CELL_ENVIRO_TYPE_CET_ROOM = 4,
    CELL_ENVIRO_TYPE_CET_BATHROOM = 5,
    CELL_ENVIRO_TYPE_CET_LIVINGROOM = 6,
    CELL_ENVIRO_TYPE_CET_STONEROOM = 7,
    CELL_ENVIRO_TYPE_CET_AUDITORIUM = 8,
    CELL_ENVIRO_TYPE_CET_CONCERTHALL = 9,
    CELL_ENVIRO_TYPE_CET_CAVE = 10,
    CELL_ENVIRO_TYPE_CET_ARENA = 11,
    CELL_ENVIRO_TYPE_CET_HANGAR = 12,
    CELL_ENVIRO_TYPE_CET_CARPETEDHALLWAY = 13,
    CELL_ENVIRO_TYPE_CET_HALLWAY = 14,
    CELL_ENVIRO_TYPE_CET_STONECORRIDOR = 15,
    CELL_ENVIRO_TYPE_CET_ALLEY = 16,
    CELL_ENVIRO_TYPE_CET_FOREST = 17,
    CELL_ENVIRO_TYPE_CET_CITY = 18,
    CELL_ENVIRO_TYPE_CET_MOUNTAINS = 19,
    CELL_ENVIRO_TYPE_CET_QUARRY = 20,
    CELL_ENVIRO_TYPE_CET_PLAIN = 21,
    CELL_ENVIRO_TYPE_CET_PARKINGLOT = 22,
    CELL_ENVIRO_TYPE_CET_SEWERPIPE = 23,
    CELL_ENVIRO_TYPE_CET_UNDERWATER = 24,
    CELL_ENVIRO_TYPE_CET_SMALLROOM = 25,
    CELL_ENVIRO_TYPE_CET_MEDIUMROOM = 26,
    CELL_ENVIRO_TYPE_CET_LARGEROOM = 27,
    CELL_ENVIRO_TYPE_CET_MEDIUMHALL = 28,
    CELL_ENVIRO_TYPE_CET_LARGEHALL = 29,
    CELL_ENVIRO_TYPE_CET_PLATE = 30,
    CELL_ENVIRO_TYPE_CET_COUNT = 31
};

int Warning(const char* apFormat, ...);

#pragma pack(push, 4)
class BGSAcousticSpace : public TESBoundObject
{
  public:
    bool m_bIsInterior;  // +0x30
    unsigned char layoutPadding31[3];
    TESSound* pDawnSound;                     // +0x34
    TESSound* pNoonSound;                     // +0x38
    TESSound* pDuskSound;                     // +0x3C
    TESSound* pNightSound;                    // +0x40
    TESSound* pWallaSound;                    // +0x44
    TESRegion* pRegion;                       // +0x48
    CELL_ENVIRO_TYPE m_eCellEnvironmentType;  // +0x4C
    int m_iFlags;                             // +0x50
    virtual void ResetFormData();
    virtual void InitItem();
    virtual bool Load(TESFile* file);
    void SetDawnSound(TESSound* apSound);
    void SetNoonSound(TESSound* apSound);
    void SetDuskSound(TESSound* apSound);
    void SetNightSound(TESSound* apSound);
    void SetWallaSound(TESSound* apSound);
    void SetRegion(TESRegion* apRegion);
    void SetListenerID(CELL_ENVIRO_TYPE aeType);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSAcousticSpace) == 84);
FNV_STATIC_ASSERT(offsetof(BGSAcousticSpace, m_bIsInterior) == 48);
FNV_STATIC_ASSERT(offsetof(BGSAcousticSpace, pDawnSound) == 52);
FNV_STATIC_ASSERT(offsetof(BGSAcousticSpace, pNoonSound) == 56);
FNV_STATIC_ASSERT(offsetof(BGSAcousticSpace, pDuskSound) == 60);
FNV_STATIC_ASSERT(offsetof(BGSAcousticSpace, pNightSound) == 64);
FNV_STATIC_ASSERT(offsetof(BGSAcousticSpace, pWallaSound) == 68);
FNV_STATIC_ASSERT(offsetof(BGSAcousticSpace, pRegion) == 72);
FNV_STATIC_ASSERT(offsetof(BGSAcousticSpace, m_eCellEnvironmentType) == 76);
FNV_STATIC_ASSERT(offsetof(BGSAcousticSpace, m_iFlags) == 80);
#endif
