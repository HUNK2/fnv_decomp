// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIMULTITARGETTRANSFORMCONTROLLER_H
#define FNV_NIMULTITARGETTRANSFORMCONTROLLER_H

#include "layout_support.h"
#include "NiObject.h"
#include "NiObjectNET.h"
#include "layout_support.h"
class NiAVObject;
class NiBlendTransformInterpolator;
class NiInterpController;
class NiMultiTargetTransformController;
class NiInterpolator;
#pragma pack(push, 4)
class NiTimeController : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    unsigned short m_uiObjectFlags;  // +0x8, 2 bytes
    unsigned char layoutPaddingA[2];
    float m_fFrequency;                              // +0xC, 4 bytes
    float m_fPhase;                                  // +0x10, 4 bytes
    float m_fLoKeyTime;                              // +0x14, 4 bytes
    float m_fHiKeyTime;                              // +0x18, 4 bytes
    float m_fStartTime;                              // +0x1C, 4 bytes
    float m_fLastTime;                               // +0x20, 4 bytes
    float m_fWeightAdjustedLastTime;                 // +0x24, 4 bytes
    float m_fControllerTime;                         // +0x28, 4 bytes
    NiObjectNET* m_pkTarget;                         // +0x2C, 4 bytes
    NiPointer<NiTimeController> m_spNextController;  // +0x30, 4 bytes
    // const NiRTTI* __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiStream&)
    // void __cdecl NiTimeController::*(NiStream&)
    // bool __cdecl NiTimeController::*(NiStream&)
    // void __cdecl NiTimeController::*(NiStream&)
    // bool __cdecl NiTimeController::*(NiObject*)
    // void __cdecl NiTimeController::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiTimeController::*(unsigned short, unsigned short, unsigned short)
    // unsigned short __cdecl NiTimeController::*(unsigned short, unsigned short)
    // void __cdecl NiTimeController::*(bool, unsigned short)
    // bool __cdecl NiTimeController::*(unsigned short)
    // NiTimeController
    // void __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController::AnimType)
    // NiTimeController::AnimType __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController::CycleType)
    // NiTimeController::CycleType __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // NiObjectNET* __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiObjectNET*)
    // unsigned int __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController*)
    // NiTimeController* __cdecl NiTimeController::*()
    // float __cdecl NiTimeController::*()
    // bool __cdecl NiTimeController::*(float)
    // float __cdecl NiTimeController::*()
    // float __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(NiTimeController*)
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // void __cdecl NiTimeController::*(bool)
    // bool __cdecl NiTimeController::*()
    // NiTimeController& __cdecl NiTimeController::*(const NiTimeController&)
    // void __cdecl NiTimeController::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTimeController) == 52);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_uiObjectFlags) == 8);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fFrequency) == 12);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fPhase) == 16);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fLoKeyTime) == 20);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fHiKeyTime) == 24);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fStartTime) == 28);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fLastTime) == 32);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fWeightAdjustedLastTime) == 36);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fControllerTime) == 40);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_pkTarget) == 44);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_spNextController) == 48);
#pragma pack(push, 4)
class NiInterpController : public NiTimeController
{
  public:
    // base NiTimeController at +0x0, size 52
    // const NiRTTI* __cdecl NiInterpController::*()
    // void __cdecl NiInterpController::*(NiStream&)
    // void __cdecl NiInterpController::*(NiStream&)
    // bool __cdecl NiInterpController::*(NiStream&)
    // void __cdecl NiInterpController::*(NiStream&)
    // bool __cdecl NiInterpController::*(NiObject*)
    // void __cdecl NiInterpController::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiInterpController::*(NiUpdateData&)
    // bool __cdecl NiInterpController::*()
    // void __cdecl NiInterpController::*(bool)
    // NiInterpController
    // void __cdecl NiInterpController::*()
    // NiInterpController& __cdecl NiInterpController::*(const NiInterpController&)
    // void __cdecl NiInterpController::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiInterpController) == 52);
#pragma pack(push, 4)
class NiMultiTargetTransformController : public NiInterpController
{
  public:
    virtual NiInterpolator* GetInterpolatorAtIndex(unsigned short);
    // base NiInterpController at +0x0, size 52
    NiBlendTransformInterpolator* m_pkBlendInterpolators;  // +0x34, 4 bytes
    NiAVObject** m_ppTargetObjects;                        // +0x38, 4 bytes
    unsigned short m_usNumInterps;                         // +0x3C, 2 bytes
    unsigned char layoutPadding3E[2];
    // const NiRTTI* __cdecl NiMultiTargetTransformController::*()
    // void __cdecl NiMultiTargetTransformController::*(NiStream&)
    // void __cdecl NiMultiTargetTransformController::*(NiStream&)
    // bool __cdecl NiMultiTargetTransformController::*(NiStream&)
    // void __cdecl NiMultiTargetTransformController::*(NiStream&)
    // bool __cdecl NiMultiTargetTransformController::*(NiObject*)
    // NiObject* __cdecl NiMultiTargetTransformController::*()
    // void __cdecl NiMultiTargetTransformController::*(NiTPrimitiveArray<char *>*)
    // NiMultiTargetTransformController
    // void __cdecl NiMultiTargetTransformController::*()
    // void __cdecl NiMultiTargetTransformController::*(NiUpdateData&)
    // unsigned short __cdecl NiMultiTargetTransformController::*()
    // NiBlendTransformInterpolator* __cdecl NiMultiTargetTransformController::*(unsigned short)
    // NiAVObject* __cdecl NiMultiTargetTransformController::*(unsigned short)
    // void __cdecl NiMultiTargetTransformController::*(unsigned short, NiAVObject*)
    // unsigned short __cdecl NiMultiTargetTransformController::*(NiAVObject*)
    // unsigned short __cdecl NiMultiTargetTransformController::*(NiAVObject*)
    // unsigned short __cdecl NiMultiTargetTransformController::*()
    // const char* __cdecl NiMultiTargetTransformController::*(unsigned short)
    // unsigned short __cdecl NiMultiTargetTransformController::*(const char*)
    // unsigned short __cdecl NiMultiTargetTransformController::*(const NiFixedString&)
    // NiInterpolator* __cdecl NiMultiTargetTransformController::*(unsigned short)
    // void __cdecl NiMultiTargetTransformController::*(NiInterpolator*, unsigned short)
    // void __cdecl NiMultiTargetTransformController::*()
    // void __cdecl NiMultiTargetTransformController::*()
    // bool __cdecl NiMultiTargetTransformController::*()
    // void __cdecl NiMultiTargetTransformController::*(bool)
    // NiInterpolator* __cdecl NiMultiTargetTransformController::*(unsigned short)
    // void __cdecl NiMultiTargetTransformController::*(NiInterpolator*, unsigned short)
    // NiBlendInterpolator* __cdecl NiMultiTargetTransformController::*(unsigned short, bool, bool, float, unsigned char)
    // void __cdecl NiMultiTargetTransformController::*(float, float)
    // bool __cdecl NiMultiTargetTransformController::*()
    // void __cdecl NiMultiTargetTransformController::*(unsigned short)
    // bool __cdecl NiMultiTargetTransformController::*(NiInterpolator*, unsigned short)
    // void __cdecl NiMultiTargetTransformController::*(unsigned short)
    // NiMultiTargetTransformController& __cdecl NiMultiTargetTransformController::*(const NiMultiTargetTransformController&)
    // void __cdecl NiMultiTargetTransformController::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiMultiTargetTransformController) == 64);
FNV_STATIC_ASSERT(offsetof(NiMultiTargetTransformController, m_pkBlendInterpolators) == 52);
FNV_STATIC_ASSERT(offsetof(NiMultiTargetTransformController, m_ppTargetObjects) == 56);
FNV_STATIC_ASSERT(offsetof(NiMultiTargetTransformController, m_usNumInterps) == 60);
#endif
