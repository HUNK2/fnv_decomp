// Authored research header for fallout/misc/saveload/bgssaveloadinitialdata.cpp.
// only real member-function declarations were added (they do not affect layout).
// TESForm::GetFormType is absent from the canonical include/TESForm.h;
// (precedent: fallout_shared/bgsopencloseform.h).
// 0x0084e730 (called by DetermineInitialDataType) takes (formID, formType, flags)
// and returns INITIAL_DATA_TYPE values; it is declared here as the 3-argument
// 0x00406d90 is a float-to-int (fistp) helper used to derive cell coordinates;
// no canonical name is available yet, so it is declared as TruncateFloatToInt.
#ifndef FNV_SRC_BGSSAVELOADINITIALDATA_H
#define FNV_SRC_BGSSAVELOADINITIALDATA_H

#define TESObjectCELL BGSSaveLoadPacketUnusedCell
#define TESDataHandler BGSSaveLoadPacketUnusedHandler
#include "layout_support.h"
#undef TESObjectCELL
#undef TESDataHandler
class TESObjectCELL;
class BGSLoadFormBuffer;
#ifndef FNV_NIPOINT3_H
#define FNV_NIPOINT3_H
class NiPoint3
{
  public:
    NiPoint3();
    float x, y, z;
};
#endif

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_INITIAL_DATA_TYPE_H
#define FNV_INITIAL_DATA_TYPE_H
#include "layout_support.h"
enum INITIAL_DATA_TYPE
{
    INITIAL_DATA_TYPE_INITIAL_DATA_NONE = 0,
    INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_CHAR = 1,
    INITIAL_DATA_TYPE_INITIAL_DATA_EXTERIOR_CELL_SHORT = 2,
    INITIAL_DATA_TYPE_INITIAL_DATA_INTERIOR_CELL = 3,
    INITIAL_DATA_TYPE_INITIAL_DATA_REFERENCE_LOCATION = 4,
    INITIAL_DATA_TYPE_INITIAL_DATA_CREATED_REFERENCE = 5,
    INITIAL_DATA_TYPE_INITIAL_DATA_MOVED_REFERENCE = 6,
    INITIAL_DATA_TYPE_INITIAL_DATA_TYPE_COUNT = 7
};
#endif

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSCHANGEFLAGS_H
#define FNV_BGSCHANGEFLAGS_H
#include "layout_support.h"
class FormChangeMask;
#pragma pack(push, 4)
class FormChangeMask
{
  public:
    bool ContainsAnyFlags(int);
    int iFlags;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FormChangeMask) == 4);
FNV_STATIC_ASSERT(offsetof(FormChangeMask, iFlags) == 0);
#endif

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_REFERENCEINITIALDATA_H
#define FNV_REFERENCEINITIALDATA_H
#include "layout_support.h"
#include "NiPoint3.h"
class ReferencePlacementData;
#pragma pack(push, 1)
class ReferencePlacementData
{
  public:
    ReferencePlacementData();
    unsigned int m_uiLocationFormID;      // +0x0, 4 bytes
    unsigned int m_uiBaseFormID;          // +0x4, 4 bytes
    unsigned int m_uiOriginalBaseFormID;  // +0x8, 4 bytes
    int m_iCellX;                         // +0xC, 4 bytes
    int m_iCellY;                         // +0x10, 4 bytes
    NiPoint3 Location;                    // +0x14, 12 bytes
    NiPoint3 Angle;                       // +0x20, 12 bytes
    unsigned char m_ucFlags;              // +0x2C, 1 bytes
    bool GetCellAndWorld(TESObjectCELL*& apCell, TESWorldSpace*& apWorld);
};
#pragma pack(pop)
// is already naturally aligned, so all offsets are unchanged, and only packing
FNV_STATIC_ASSERT(sizeof(ReferencePlacementData) == 45);
FNV_STATIC_ASSERT(offsetof(ReferencePlacementData, m_uiLocationFormID) == 0);
FNV_STATIC_ASSERT(offsetof(ReferencePlacementData, m_uiBaseFormID) == 4);
FNV_STATIC_ASSERT(offsetof(ReferencePlacementData, m_uiOriginalBaseFormID) == 8);
FNV_STATIC_ASSERT(offsetof(ReferencePlacementData, m_iCellX) == 12);
FNV_STATIC_ASSERT(offsetof(ReferencePlacementData, m_iCellY) == 16);
FNV_STATIC_ASSERT(offsetof(ReferencePlacementData, Location) == 20);
FNV_STATIC_ASSERT(offsetof(ReferencePlacementData, Angle) == 32);
FNV_STATIC_ASSERT(offsetof(ReferencePlacementData, m_ucFlags) == 44);
#endif

class TESForm
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual bool IsActor();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* GetName();
    const char* FUN_00440e30();
    ENUM_FORM_ID GetFormType() const;
    unsigned int GetFormID();
    static TESForm* GetFormByID(unsigned int auiFormID);
};

class TESWorldSpace : public TESForm
{
  public:
    TESObjectCELL* GetInteriorCell();
    TESObjectCELL* GetCellAtGridPosition(int m_iGridPositionX, int m_iGridCoordinateY);
};

class BGSSaveLoadInitialDataPacket
{
  public:
    static INITIAL_DATA_TYPE LoadInitialDataForForm(BGSLoadFormBuffer*, TESForm*, FormChangeMask);
    static INITIAL_DATA_TYPE DetermineInitialDataType(TESForm* apForm, FormChangeMask eChangeFlags);
    static INITIAL_DATA_TYPE DetermineInitialDataType(unsigned int auiFormId, ENUM_FORM_ID m_eReferenceTypeInfo,
                                                      FormChangeMask eChangeFlags);
};

bool GetCellAndWorldspaceForForm(TESForm* apForm, TESObjectCELL*& apCell, TESWorldSpace*& apWorld);
int TruncateFloatToInt(float afValue);

class TESBoundObject : public TESForm
{
};
class TESObjectCELL : public TESForm
{
  public:
    bool IsCellInterior() const;
    void SetDetachTime(unsigned int, bool);
};
class ExtraDataList
{
  public:
    void CallExtraDataListMethod35(TESObjectCELL*);
};
class TESObjectREFR : public TESForm
{
  public:
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc(int, int);
    virtual void* vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228(TESObjectCELL*);
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual bool vfn_290();
    void SetLocationOnReference(const NiPoint3&);
    void SetReferencePosition(NiPoint3);
    ExtraDataList* GetExtraData();
    void TESForm_SetStillLoading(int);
    void PostLoad();
    TESObjectCELL* GetParentCell();
    bool GetReferencePersistence();
    void FUN_0084f8c0(TESForm*);
    static void SetParentCellAndWorldspace(TESObjectREFR*, TESObjectCELL*, TESWorldSpace*);
};
class PlayerCharacter : public TESObjectREFR
{
};
class BGSSaveLoadGame
{
  public:
    bool FUN_0063ef00();
    void RemoveActorFromMap(TESObjectREFR*);
    void FUN_0084a810(int, BGSLoadFormBuffer*, int);
    void DeleteForm(TESForm*);
};
class BGSLoadFormBuffer
{
  public:
    void SetFlag10(int);
};
class TESRecipe
{
  public:
    void SetSkill(int);
};
class TES
{
  public:
    bool IsCellBuffered(TESObjectCELL*, bool);
};
class BGSPrimitive;
class TESDataHandler
{
  public:
    TESObjectREFR* PlaceReferenceAtLocation(TESBoundObject*, const NiPoint3&, const NiPoint3&, TESObjectCELL*,
                                            TESWorldSpace*, TESObjectREFR*, BGSPrimitive*, void*);
};
extern TESDataHandler* g_dataHandler;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern TES* g_TES;
extern PlayerCharacter* g_thePlayer;
extern const char DAT_01015890[];
extern const char DAT_0107f86c[];
extern const char DAT_0107f894[];
extern const char DAT_0107f8d0[];
extern const char DAT_0107f938[];
void LogWarning(const char*, ...);
bool FUN_0084f860(INITIAL_DATA_TYPE);
bool FUN_0084f840(INITIAL_DATA_TYPE);
unsigned int LoadFormData(BGSLoadFormBuffer*, INITIAL_DATA_TYPE, void*);
struct CellDetachTimeData
{
    unsigned int a, b, c, m_uiDetachTime;
};

#endif
