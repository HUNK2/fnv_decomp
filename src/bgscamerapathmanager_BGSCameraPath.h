// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSCAMERAPATH_H
#define FNV_BGSCAMERAPATH_H

#include "bgscamerapathmanager_layout_support.h"
#include "PerkEntryConditionSet.h"
#include "bgscamerapathmanager_TESForm.h"
#include "bgscamerapathmanager_layout_support.h"
class BGSCameraPath;
class BGSCameraShot;
class NiFormArray;
class CameraShotData;
class CameraShotData
{
  public:
    unsigned char cFlags;  // +0x0, 1 bytes
    // void __cdecl CameraShotData::*()
};
FNV_STATIC_ASSERT(sizeof(CameraShotData) == 1);
FNV_STATIC_ASSERT(offsetof(CameraShotData, cFlags) == 0);
class BGSCameraPath : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    PerkEntryConditionSet Conditions;                         // +0x18, 8 bytes
    BSSimpleList<BGSCameraShot*> m_kCameraShotList;  // +0x20, 8 bytes
    CameraShotData data;                             // +0x28, 1 bytes
    unsigned char layoutPadding29[3];
    NiFormArray* m_pPathArray;           // +0x2C, 4 bytes
    BGSCameraPath* m_pFirstCameraPath;   // +0x30, 4 bytes
    BGSCameraPath* m_pSecondCameraPath;  // +0x34, 4 bytes
    BGSCameraPath();
    bool HasMissingPathArray();
    // BGSCameraPath
    // void __cdecl BGSCameraPath::*()
    // void __cdecl BGSCameraPath::*()
    // void __cdecl BGSCameraPath::*()
    // void __cdecl BGSCameraPath::*(TESForm*)
    // bool __cdecl BGSCameraPath::*(TESForm*)
    // TESForm* __cdecl BGSCameraPath::*(bool, NiTPointerMap<TESForm *,TESForm *>*)
    // bool __cdecl BGSCameraPath::*(TESFile*)
    // void __cdecl BGSCameraPath::*()
    // void __cdecl BGSCameraPath::*()
    // bool __cdecl BGSCameraPath::*()
    // void __cdecl BGSCameraPath::*(NiFormArray*)
    // bool __cdecl BGSCameraPath::*(NiFormArray*)
    // BGSCameraPath* __cdecl BGSCameraPath::*()
    // void __cdecl BGSCameraPath::*(BGSCameraPath*)
    // BGSCameraPath* __cdecl BGSCameraPath::*()
    // void __cdecl BGSCameraPath::*(BGSCameraPath*)
    // NiFormArray* __cdecl BGSCameraPath::*()
    // NiFormArray* __cdecl BGSCameraPath::*()
    // BSSimpleList<BGSCameraShot *>* __cdecl BGSCameraPath::*()
    // bool __cdecl BGSCameraPath::*()
    // void __cdecl BGSCameraPath::*(bool)
    // bool __cdecl BGSCameraPath::*()
    // void __cdecl BGSCameraPath::*()
    // bool __cdecl BGSCameraPath::*()
    // void __cdecl BGSCameraPath::*()
    // bool __cdecl BGSCameraPath::*()
    // void __cdecl BGSCameraPath::*()
    // BGSCameraPath* __cdecl BGSCameraPath::*(TESObjectREFR*, TESObjectREFR*)
    // unsigned int __cdecl BGSCameraPath::*()
    // BGSCameraPath* __cdecl BGSCameraPath::*(unsigned int)
    // unsigned int __cdecl BGSCameraPath::*(BGSCameraPath*)
    // void __cdecl BGSCameraPath::*(unsigned int, BGSCameraPath*)
    // void __cdecl BGSCameraPath::*(BGSCameraPath*, BGSCameraPath*)
    // void __cdecl BGSCameraPath::*(unsigned int)
    // void __cdecl BGSCameraPath::*(BGSCameraPath*)
    // bool __cdecl BGSCameraPath::*(BGSCameraPath*)
    // void __cdecl BGSCameraPath::*()
    // void __cdecl BGSCameraPath::*(BGSCameraShot*, BGSCameraShot*)
    // void __cdecl BGSCameraPath::*(BGSCameraShot*, bool)
    // NiFormArray* __cdecl BGSCameraPath::*()
    // BGSCameraPath& __cdecl BGSCameraPath::*(const BGSCameraPath&)
    // void __cdecl BGSCameraPath::*()
};
FNV_STATIC_ASSERT(sizeof(BGSCameraPath) == 56);
FNV_STATIC_ASSERT(offsetof(BGSCameraPath, Conditions) == 24);
FNV_STATIC_ASSERT(offsetof(BGSCameraPath, m_kCameraShotList) == 32);
FNV_STATIC_ASSERT(offsetof(BGSCameraPath, data) == 40);
FNV_STATIC_ASSERT(offsetof(BGSCameraPath, m_pPathArray) == 44);
FNV_STATIC_ASSERT(offsetof(BGSCameraPath, m_pFirstCameraPath) == 48);
FNV_STATIC_ASSERT(offsetof(BGSCameraPath, m_pSecondCameraPath) == 52);
#endif
