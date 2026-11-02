// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITRANSFORMCONTROLLER_H
#define FNV_NITRANSFORMCONTROLLER_H

#include "layout_support.h"
#include "NiObject.h"
#include "NiObjectNET.h"
#include "layout_support.h"
class NiInterpController;
class NiInterpolator;
class NiSingleInterpController;
class NiTransformController;
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
    // void __cdecl NiTimeController::*(NiTimeController*, CloningProcess&)
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
    // void __cdecl NiTimeController::*(CloningProcess&)
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
    // void __cdecl NiInterpController::*(NiInterpController*, CloningProcess&)
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
class NiSingleInterpController : public NiInterpController
{
  public:
    // base NiInterpController at +0x0, size 52
    NiPointer<NiInterpolator> m_spControllerInterpolator;  // +0x34, 4 bytes
    // const NiRTTI* __cdecl NiSingleInterpController::*()
    // void __cdecl NiSingleInterpController::*(NiSingleInterpController*, CloningProcess&)
    // void __cdecl NiSingleInterpController::*(NiStream&)
    // void __cdecl NiSingleInterpController::*(NiStream&)
    // bool __cdecl NiSingleInterpController::*(NiStream&)
    // void __cdecl NiSingleInterpController::*(NiStream&)
    // bool __cdecl NiSingleInterpController::*(NiObject*)
    // void __cdecl NiSingleInterpController::*(NiTPrimitiveArray<char *>*)
    // unsigned short __cdecl NiSingleInterpController::*()
    // const char* __cdecl NiSingleInterpController::*(unsigned short)
    // unsigned short __cdecl NiSingleInterpController::*(const char*)
    // unsigned short __cdecl NiSingleInterpController::*(const NiFixedString&)
    // NiInterpolator* __cdecl NiSingleInterpController::*(unsigned short)
    // void __cdecl NiSingleInterpController::*(NiInterpolator*, unsigned short)
    // void __cdecl NiSingleInterpController::*()
    // void __cdecl NiSingleInterpController::*(float, float)
    // void __cdecl NiSingleInterpController::*(CloningProcess&)
    // NiSingleInterpController
    // bool __cdecl NiSingleInterpController::*()
    // void __cdecl NiSingleInterpController::*()
    // NiSingleInterpController& __cdecl NiSingleInterpController::*(const NiSingleInterpController&)
    // void __cdecl NiSingleInterpController::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiSingleInterpController) == 56);
FNV_STATIC_ASSERT(offsetof(NiSingleInterpController, m_spControllerInterpolator) == 52);
#pragma pack(push, 4)
class NiTransformController : public NiSingleInterpController
{
  public:
    void CopyMemberData(NiTransformController*, CloningProcess&);
    void FUN_00a2f8a0(NiTransformController*, CloningProcess&);
    NiTransformController* FUN_00a5d3f0(NiTransformController*);
    // base NiSingleInterpController at +0x0, size 56
    // const NiRTTI* __cdecl NiTransformController::*()
    // NiObject* __cdecl NiTransformController::*(CloningProcess&)
    // void __cdecl NiTransformController::*(NiTransformController*, CloningProcess&)
    // void __cdecl NiTransformController::*(NiStream&)
    // void __cdecl NiTransformController::*(NiStream&)
    // bool __cdecl NiTransformController::*(NiStream&)
    // void __cdecl NiTransformController::*(NiStream&)
    // bool __cdecl NiTransformController::*(NiObject*)
    // NiObject* __cdecl NiTransformController::*()
    // void __cdecl NiTransformController::*(NiTPrimitiveArray<char *>*)
    // NiTransformController
    // void __cdecl NiTransformController::*(NiUpdateData&)
    // bool __cdecl NiTransformController::*()
    // NiInterpolator* __cdecl NiTransformController::*(unsigned short)
    // void __cdecl NiTransformController::*(NiInterpolator*, unsigned short)
    // NiBlendInterpolator* __cdecl NiTransformController::*(unsigned short, bool, bool, float, unsigned char)
    // bool __cdecl NiTransformController::*(NiObjectNET*)
    // bool __cdecl NiTransformController::*(NiInterpolator*, unsigned short)
    // void __cdecl NiTransformController::*()
    // NiTransformController& __cdecl NiTransformController::*(const NiTransformController&)
    // void __cdecl NiTransformController::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTransformController) == 56);
#endif
