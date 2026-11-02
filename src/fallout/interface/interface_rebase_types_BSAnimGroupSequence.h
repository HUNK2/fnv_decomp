// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_INTERFACE_REBASE_FNV_BSANIMGROUPSEQUENCE_H
#define FNV_INTERFACE_REBASE_FNV_BSANIMGROUPSEQUENCE_H
#include "interface_rebase_layout_support.h"
#include "interface_rebase_NiFixedString.h"
#include "interface_rebase_NiObject.h"
#include "interface_rebase_layout_support.h"
class BSAnimGroupSequence;
class BSAnimNote;
class NiAVObject;
class NiControllerManager;
class NiControllerSequence__IDTag;
class NiControllerSequence__InterpArrayItem;
class NiStringPalette;
class NiTextKeyExtraData;
class TESAnimGroup;
enum NiTimeController__CycleType
{
    NiTimeController__CycleType_LOOP = 0,
    NiTimeController__CycleType_REVERSE = 1,
    NiTimeController__CycleType_CLAMP = 2,
    NiTimeController__CycleType_MAX_CYCLE_TYPES = 3
};
enum NiControllerSequence__AnimState
{
    NiControllerSequence__AnimState_INACTIVE = 0,
    NiControllerSequence__AnimState_ANIMATING = 1,
    NiControllerSequence__AnimState_EASEIN = 2,
    NiControllerSequence__AnimState_EASEOUT = 3,
    NiControllerSequence__AnimState_TRANSSOURCE = 4,
    NiControllerSequence__AnimState_TRANSDEST = 5,
    NiControllerSequence__AnimState_MORPHSOURCE = 6
};
class NiControllerSequence : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    NiFixedString m_kName;                                  // +0x8, 4 bytes
    unsigned int m_uiNumControlledBlocks;                   // +0xC, 4 bytes
    unsigned int m_uiNumIDTags;                             // +0x10, 4 bytes
    NiControllerSequence__InterpArrayItem* m_pInterpArray;  // +0x14, 4 bytes
    NiControllerSequence__IDTag* m_pkIDTags;                // +0x18, 4 bytes
    float m_fWeight;                                        // +0x1C, 4 bytes
    NiPointer<NiTextKeyExtraData> m_spTextKeyData;          // +0x20, 4 bytes
    NiTimeController__CycleType m_eAnimationCycleType;      // +0x24, 4 bytes
    float m_fFrequency;                                     // +0x28, 4 bytes
    float m_fFirstKeyTime;                                  // +0x2C, 4 bytes
    float m_fLastKeyTime;                                   // +0x30, 4 bytes
    float m_fLastTime;                                      // +0x34, 4 bytes
    float m_fWeightAdjustedLastTime;                        // +0x38, 4 bytes
    float m_fScaledLastTime;                                // +0x3C, 4 bytes
    NiControllerManager* m_pkOwnerManager;                  // +0x40, 4 bytes
    NiControllerSequence__AnimState m_eAnimationState;      // +0x44, 4 bytes
    float m_fSequenceOffset;                                // +0x48, 4 bytes
    float m_fStartTime;                                     // +0x4C, 4 bytes
    float m_fEndTime;                                       // +0x50, 4 bytes
    float m_fDestinationFrame;                              // +0x54, 4 bytes
    NiControllerSequence* m_pkTimeSyncSequence;             // +0x58, 4 bytes
    NiFixedString m_kAccumulationRootName;                  // +0x5C, 4 bytes
    NiAVObject* m_pkAccumulationRoot;                       // +0x60, 4 bytes
    NiPointer<NiStringPalette> m_spStringPalette;           // +0x64, 4 bytes
    short m_sAnimNotesExtraDataIndex;                       // +0x68, 2 bytes
    unsigned char layoutPadding6A[2];
    NiPointer<BSAnimNote>* m_pkAnimNotes;  // +0x6C, 4 bytes
    unsigned short m_usNumAnimNotes;       // +0x70, 2 bytes
    bool m_bHasAnimNotes;                  // +0x72, 1 bytes
    unsigned char layoutPadding73[1];
    // const NiRTTI* __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(NiStream&)
    // void __cdecl NiControllerSequence::*(NiStream&)
    // bool __cdecl NiControllerSequence::*(NiStream&)
    // void __cdecl NiControllerSequence::*(NiStream&)
    // bool __cdecl NiControllerSequence::*(NiObject*)
    // NiObject* __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(NiTPrimitiveArray<char *>*)
    // NiControllerSequence
    // void __cdecl NiControllerSequence::*()
    // CreateSequenceFromFile
    // CreateAllSequencesFromFile
    // void __cdecl NiControllerSequence::*(NiSequence*, NiPointer<NiControllerSequence>&)
    // const NiFixedString& __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(const NiFixedString&)
    // NiTextKeyExtraData* __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(NiTextKeyExtraData*)
    // void __cdecl NiControllerSequence::*()
    // NiControllerSequence::AnimState __cdecl NiControllerSequence::*()
    // float __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(float)
    // float __cdecl NiControllerSequence::*()
    // float __cdecl NiControllerSequence::*()
    // float __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(float, bool)
    // AddInterpolator
    // void __cdecl NiControllerSequence::*()
    // unsigned int __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(unsigned int)
    // unsigned int __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(unsigned int)
    // NiInterpolator* __cdecl NiControllerSequence::*(unsigned int)
    // void __cdecl NiControllerSequence::*(unsigned int, const char*&, const char*&, const char*&, const char*&, const char*&)
    // NiInterpController* __cdecl NiControllerSequence::*(unsigned int)
    // NiObjectNET* __cdecl NiControllerSequence::*(unsigned int)
    // NiBlendInterpolator* __cdecl NiControllerSequence::*(unsigned int)
    // unsigned char __cdecl NiControllerSequence::*(unsigned int)
    // float __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(float)
    // GetTimeAt
    // GetKeyTimeAt
    // float __cdecl NiControllerSequence::*(const NiFixedString&)
    // float __cdecl NiControllerSequence::*()
    // float __cdecl NiControllerSequence::*()
    // float __cdecl NiControllerSequence::*(float)
    // float __cdecl NiControllerSequence::*(float)
    // NiTimeController::CycleType __cdecl NiControllerSequence::*()
    // bool __cdecl NiControllerSequence::*(NiTimeController::CycleType)
    // float __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(float)
    // void __cdecl NiControllerSequence::*(float)
    // void __cdecl NiControllerSequence::*(float)
    // float __cdecl NiControllerSequence::*()
    // float __cdecl NiControllerSequence::*()
    // float __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(unsigned int, char*)
    // bool __cdecl NiControllerSequence::*(const char*, NiTimeController*)
    // void __cdecl NiControllerSequence::*(unsigned int)
    // unsigned int __cdecl NiControllerSequence::*()
    // NiControllerSequence::IDTag* __cdecl NiControllerSequence::*(unsigned int)
    // void __cdecl NiControllerSequence::*(float, bool)
    // NiControllerManager* __cdecl NiControllerSequence::*()
    // bool __cdecl NiControllerSequence::*(NiControllerManager*)
    // bool __cdecl NiControllerSequence::*(NiAVObject*)
    // void __cdecl NiControllerSequence::*()
    // bool __cdecl NiControllerSequence::*(char, bool, float, float, NiControllerSequence*, bool)
    // bool __cdecl NiControllerSequence::*(NiControllerSequence*, float, int, float, float)
    // void __cdecl NiControllerSequence::*(NiControllerSequence*, unsigned int, NiControllerSequence*, bool)
    // void __cdecl NiControllerSequence::*(const NiFixedString&)
    // const NiFixedString& __cdecl NiControllerSequence::*()
    // NiAVObject* __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(NiInterpController*, unsigned int)
    // void __cdecl NiControllerSequence::*(NiInterpolator*, unsigned int)
    // bool __cdecl NiControllerSequence::*(NiControllerSequence*)
    // float __cdecl NiControllerSequence::*(NiControllerSequence*, float)
    // float __cdecl NiControllerSequence::*(float, bool)
    // float __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(NiStream&)
    // void __cdecl NiControllerSequence::*(NiAVObject*)
    // char* __cdecl NiControllerSequence::*(const char*, NiControllerSequence::AnimState)
    // float __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(char*)
    // NiControllerSequence* __cdecl NiControllerSequence::*()
    // SetPriority
    // unsigned char __cdecl NiControllerSequence::*(unsigned int)
    // void __cdecl NiControllerSequence::*(NiPointer<BSAnimNote>*)
    // void __cdecl NiControllerSequence::*(unsigned short)
    // bool __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*()
    // void __cdecl NiControllerSequence::*(char)
    // void __cdecl NiControllerSequence::*()
    // bool __cdecl NiControllerSequence::*(const char*, NiInterpController*)
    // void __cdecl NiControllerSequence::*(float, float, float)
    // bool __cdecl NiControllerSequence::*(NiControllerSequence*)
    // bool __cdecl NiControllerSequence::*(NiControllerSequence*)
    // bool __cdecl NiControllerSequence::*()
    // bool __cdecl NiControllerSequence::*(NiAVObject*, NiAVObjectPalette*, unsigned int)
    // void __cdecl NiControllerSequence::*(NiControllerSequence::AnimState)
    // NiControllerSequence& __cdecl NiControllerSequence::*(const NiControllerSequence&)
    // void __cdecl NiControllerSequence::*()
};
FNV_STATIC_ASSERT(sizeof(NiControllerSequence) == 116);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_kName) == 8);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_uiNumControlledBlocks) == 12);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_uiNumIDTags) == 16);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_pInterpArray) == 20);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_pkIDTags) == 24);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_fWeight) == 28);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_spTextKeyData) == 32);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_eAnimationCycleType) == 36);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_fFrequency) == 40);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_fFirstKeyTime) == 44);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_fLastKeyTime) == 48);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_fLastTime) == 52);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_fWeightAdjustedLastTime) == 56);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_fScaledLastTime) == 60);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_pkOwnerManager) == 64);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_eAnimationState) == 68);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_fSequenceOffset) == 72);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_fStartTime) == 76);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_fEndTime) == 80);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_fDestinationFrame) == 84);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_pkTimeSyncSequence) == 88);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_kAccumulationRootName) == 92);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_pkAccumulationRoot) == 96);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_spStringPalette) == 100);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_sAnimNotesExtraDataIndex) == 104);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_pkAnimNotes) == 108);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_usNumAnimNotes) == 112);
FNV_STATIC_ASSERT(offsetof(NiControllerSequence, m_bHasAnimNotes) == 114);
class BSAnimGroupSequence : public NiControllerSequence
{
  public:
    static bool PlayAnimSounds(NiControllerSequence*, TESObjectREFR*);
    // base NiControllerSequence at +0x0, size 116
    NiPointer<TESAnimGroup> m_spAnimGroup;  // +0x74, 4 bytes
    // const NiRTTI* __cdecl BSAnimGroupSequence::*()
    // void __cdecl BSAnimGroupSequence::*(NiTPrimitiveArray<char *>*)
    // BSAnimGroupSequence
    // void __cdecl BSAnimGroupSequence::*()
    // void __cdecl BSAnimGroupSequence::*(const NiStream&, unsigned int, NiPointer<NiControllerSequence>&)
    // void __cdecl BSAnimGroupSequence::*(TESAnimGroup*)
    // TESAnimGroup* __cdecl BSAnimGroupSequence::*()
    // float __cdecl BSAnimGroupSequence::*(float)
    // void __cdecl BSAnimGroupSequence::*()
    // void __cdecl BSAnimGroupSequence::*()
    // bool __cdecl BSAnimGroupSequence::*(NiAVObject*, unsigned int)
    // bool __cdecl BSAnimGroupSequence::*(NiControllerSequence*, TESObjectREFR*)
    // unsigned char __cdecl BSAnimGroupSequence::*(const char*, unsigned int*)
    // bool __cdecl BSAnimGroupSequence::*(NiTimeController*)
    // void __cdecl BSAnimGroupSequence::*()
    // bool __cdecl BSAnimGroupSequence::*(float, bool)
    // void __cdecl BSAnimGroupSequence::*(float)
    // unsigned short __cdecl BSAnimGroupSequence::*()
    // unsigned short __cdecl BSAnimGroupSequence::*()
    // SaveGame
    // LoadGame
    // BSAnimGroupSequence& __cdecl BSAnimGroupSequence::*(const BSAnimGroupSequence&)
    // void __cdecl BSAnimGroupSequence::*()
};
FNV_STATIC_ASSERT(sizeof(BSAnimGroupSequence) == 120);
FNV_STATIC_ASSERT(offsetof(BSAnimGroupSequence, m_spAnimGroup) == 116);
#endif
