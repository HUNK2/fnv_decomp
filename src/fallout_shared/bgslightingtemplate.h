// Unit-local PC header for fallout_shared/bgslightingtemplate.cpp.
// member declarations the codegen calls added: the default constructor
// (0x00526640) and Endian (0x00526790), matching the accepted
// TESSound__SOUND_DATA::Endian pattern in decomp/src/fallout_shared/tessound.h.
// TESFileFormInt is the unit-local GetTESForm shim copied from tessound.h:
// the 2008 Load compares the GetTESForm result with cmp eax,imm and no movzx,
// which the closure's unsigned char declaration cannot reproduce.
// ReadTypedData is the canonical TESForm::ReadTypedData(TESFile*, void*, unsigned short)
// chunk reader; it is declared on BGSLightingTemplate because the closure
// TESForm.h does not declare it.
#ifndef FNV_BGSLIGHTINGTEMPLATE_UNIT_H
#define FNV_BGSLIGHTINGTEMPLATE_UNIT_H

#include "layout_support.h"
#include "TESForm.h"
#include "TESFile.h"

// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_INTERIOR_DATA_H
#define FNV_INTERIOR_DATA_H
class InteriorData;
#pragma pack(push, 4)
class InteriorData
{
  public:
    unsigned int m_uiAmbientColor;           // +0x0, 4 bytes
    unsigned int m_uiDirectionalColor;       // +0x4, 4 bytes
    unsigned int m_uiFogColor;               // +0x8, 4 bytes
    float m_fFogNear;                        // +0xC, 4 bytes
    float m_fFogFar;                         // +0x10, 4 bytes
    unsigned int m_uiDirectionalRotationXY;  // +0x14, 4 bytes
    unsigned int m_uiDirectionalRotationZ;   // +0x18, 4 bytes
    float m_fDirectionalFade;                // +0x1C, 4 bytes
    float m_fFogClipDistance;                // +0x20, 4 bytes
    float m_fFogPower;                       // +0x24, 4 bytes
    unsigned int m_uiTrailingValue;          // +0x28, 4 bytes
    InteriorData();
    void Endian();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(InteriorData) == 44);
FNV_STATIC_ASSERT(offsetof(InteriorData, m_uiAmbientColor) == 0);
FNV_STATIC_ASSERT(offsetof(InteriorData, m_uiDirectionalColor) == 4);
FNV_STATIC_ASSERT(offsetof(InteriorData, m_uiFogColor) == 8);
FNV_STATIC_ASSERT(offsetof(InteriorData, m_fFogNear) == 12);
FNV_STATIC_ASSERT(offsetof(InteriorData, m_fFogFar) == 16);
FNV_STATIC_ASSERT(offsetof(InteriorData, m_uiDirectionalRotationXY) == 20);
FNV_STATIC_ASSERT(offsetof(InteriorData, m_uiDirectionalRotationZ) == 24);
FNV_STATIC_ASSERT(offsetof(InteriorData, m_fDirectionalFade) == 28);
FNV_STATIC_ASSERT(offsetof(InteriorData, m_fFogClipDistance) == 32);
FNV_STATIC_ASSERT(offsetof(InteriorData, m_fFogPower) == 36);
FNV_STATIC_ASSERT(offsetof(InteriorData, m_uiTrailingValue) == 40);
#endif
// The 2008 BGSLightingTemplate.cpp saw a 32-bit TESFile::GetTESForm: the Load
// form check compares the call result with cmp eax,imm and no movzx, which is
// unreproducible through the closure's unsigned char declaration (any use of
// a uchar call result in a 32-bit compare extends it). The shim below recovers
// the original static type; it binds the real GetTESForm target.
struct TESFileFormInt : public TESFile
{
    int GetTESForm();
};
#pragma pack(push, 4)
class BGSLightingTemplate : public TESForm
{
  public:
    InteriorData Data;  // +0x18, 44 bytes
    BGSLightingTemplate();
    void ResetFormData();
    bool Load(TESFile* file);
    void ReadTypedData(TESFile* file, void* buffer, unsigned short size);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSLightingTemplate) == 68);
FNV_STATIC_ASSERT(offsetof(BGSLightingTemplate, Data) == 24);
#endif
