// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITEXTURETRANSFORMCONTROLLER_H
#define FNV_NITEXTURETRANSFORMCONTROLLER_H

#include "layout_support.h"
#include "NiObject.h"
#include "NiObjectNET.h"
#include "layout_support.h"
class NiFloatInterpController;
class NiInterpController;
class NiInterpolator;
class NiSingleInterpController;
class NiTextureTransformController;
class NiTexturingProperty;
class NiTexturingProperty__Map;
class NiUpdateData;
enum NiTextureTransformController__TransformMember
{
    NiTextureTransformController__TransformMember_TT_TRANSLATE_U = 0,
    NiTextureTransformController__TransformMember_TT_TRANSLATE_V = 1,
    NiTextureTransformController__TransformMember_TT_ROTATE = 2,
    NiTextureTransformController__TransformMember_TT_SCALE_U = 3,
    NiTextureTransformController__TransformMember_TT_SCALE_V = 4
};
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
    virtual void SetTarget(NiObjectNET* target);
    bool AdvanceController(float time);
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
class NiSingleInterpController : public NiInterpController
{
  public:
    // base NiInterpController at +0x0, size 52
    NiPointer<NiInterpolator> m_spControllerInterpolator;  // +0x34, 4 bytes
    // const NiRTTI* __cdecl NiSingleInterpController::*()
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
class NiFloatInterpController : public NiSingleInterpController
{
  public:
    // base NiSingleInterpController at +0x0, size 56
    NiFloatInterpController() throw();
    // const NiRTTI* __cdecl NiFloatInterpController::*()
    // void __cdecl NiFloatInterpController::*(NiStream&)
    // void __cdecl NiFloatInterpController::*(NiStream&)
    // bool __cdecl NiFloatInterpController::*(NiStream&)
    // void __cdecl NiFloatInterpController::*(NiStream&)
    // bool __cdecl NiFloatInterpController::*(NiObject*)
    // void __cdecl NiFloatInterpController::*(NiTPrimitiveArray<char *>*)
    // NiInterpolator* __cdecl NiFloatInterpController::*(unsigned short)
    // void __cdecl NiFloatInterpController::*(NiInterpolator*, unsigned short)
    // NiBlendInterpolator* __cdecl NiFloatInterpController::*(unsigned short, bool, bool, float, unsigned char)
    // NiFloatInterpController
    // bool __cdecl NiFloatInterpController::*(NiInterpolator*, unsigned short)
    // void __cdecl NiFloatInterpController::*()
    // NiFloatInterpController& __cdecl NiFloatInterpController::*(const NiFloatInterpController&)
    // void __cdecl NiFloatInterpController::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiFloatInterpController) == 56);
#pragma pack(push, 4)
class NiTextureTransformController : public NiFloatInterpController
{
  public:
    // base NiFloatInterpController at +0x0, size 56
    unsigned int m_uiLastKeyIndex;         // +0x38, 4 bytes
    NiTexturingProperty__Map* m_pTaskMap;  // +0x3C, 4 bytes
    bool m_bIsBumpMap;                     // +0x40, 1 bytes
    unsigned char layoutPadding41[3];
    unsigned int m_uiTextureMapIndex;                                  // +0x44, 4 bytes
    NiTextureTransformController__TransformMember m_eTransformMember;  // +0x48, 4 bytes
    char* m_pCachedControllerID;                                       // +0x4C, 4 bytes
    const char* GetControllerID();
    virtual void Update(NiUpdateData* data) throw();
    bool IsTextureMapValid();
    NiTextureTransformController(NiObjectNET* property, NiTexturingProperty__Map* map,
                                 NiTextureTransformController__TransformMember member) throw();
    // const NiRTTI* __cdecl NiTextureTransformController::*()
    // void __cdecl NiTextureTransformController::*(NiStream&)
    // void __cdecl NiTextureTransformController::*(NiStream&)
    // bool __cdecl NiTextureTransformController::*(NiStream&)
    // void __cdecl NiTextureTransformController::*(NiStream&)
    // bool __cdecl NiTextureTransformController::*(NiObject*)
    // NiObject* __cdecl NiTextureTransformController::*()
    // void __cdecl NiTextureTransformController::*(NiTPrimitiveArray<char *>*)
    // NiTextureTransformController
    // void __cdecl NiTextureTransformController::*()
    // void __cdecl NiTextureTransformController::*(NiUpdateData&)
    // NiTexturingProperty::Map* __cdecl NiTextureTransformController::*()
    // bool __cdecl NiTextureTransformController::*(NiTexturingProperty::Map*, NiTexturingProperty*)
    // NiTextureTransformController::TransformMember __cdecl NiTextureTransformController::*()
    // void __cdecl NiTextureTransformController::*(NiTextureTransformController::TransformMember)
    // void __cdecl NiTextureTransformController::*(NiObjectNET*)
    // const char* __cdecl NiTextureTransformController::*()
    // bool __cdecl NiTextureTransformController::*()
    // bool __cdecl NiTextureTransformController::*(NiObjectNET*)
    // void __cdecl NiTextureTransformController::*(float&)
    // void __cdecl NiTextureTransformController::*()
    // NiTextureTransformController& __cdecl NiTextureTransformController::*(const NiTextureTransformController&)
    // void __cdecl NiTextureTransformController::*()
    // void __cdecl NiTextureTransformController::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTextureTransformController) == 80);
FNV_STATIC_ASSERT(offsetof(NiTextureTransformController, m_uiLastKeyIndex) == 56);
FNV_STATIC_ASSERT(offsetof(NiTextureTransformController, m_pTaskMap) == 60);
FNV_STATIC_ASSERT(offsetof(NiTextureTransformController, m_bIsBumpMap) == 64);
FNV_STATIC_ASSERT(offsetof(NiTextureTransformController, m_uiTextureMapIndex) == 68);
FNV_STATIC_ASSERT(offsetof(NiTextureTransformController, m_eTransformMember) == 72);
FNV_STATIC_ASSERT(offsetof(NiTextureTransformController, m_pCachedControllerID) == 76);
#endif
