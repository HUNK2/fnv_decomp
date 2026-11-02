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

#include "layout_support.h"
#include "NiPoint3.h"

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
    ENUM_FORM_ID GetFormType() const;
    unsigned int GetFormID();
    static TESForm* GetFormByID(unsigned int auiFormID);
};

class TESWorldSpace
{
  public:
    TESObjectCELL* GetCellAtGridPosition(int m_iGridPositionX, int m_iGridCoordinateY);
};

class BGSSaveLoadInitialDataPacket
{
  public:
    static INITIAL_DATA_TYPE DetermineInitialDataType(TESForm* apForm, FormChangeMask eChangeFlags);
    static INITIAL_DATA_TYPE DetermineInitialDataType(unsigned int auiFormId, ENUM_FORM_ID m_eReferenceTypeInfo,
                                                      FormChangeMask eChangeFlags);
};

bool GetCellAndWorldspaceForForm(TESForm* apForm, TESObjectCELL*& apCell, TESWorldSpace*& apWorld);
int TruncateFloatToInt(float afValue);
#endif
