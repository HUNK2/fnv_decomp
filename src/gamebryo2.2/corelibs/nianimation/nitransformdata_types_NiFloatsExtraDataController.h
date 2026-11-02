// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITRANSFORMDATA_FNV_NIFLOATSEXTRADATACONTROLLER_H
#define FNV_NITRANSFORMDATA_FNV_NIFLOATSEXTRADATACONTROLLER_H

#include "nitransformdata_layout_support.h"
#include "nitransformdata_NiFixedString.h"
#include "nitransformdata_NiObject.h"
#include "nitransformdata_NiObjectNET.h"
#include "nitransformdata_layout_support.h"
class NiExtraDataController;
class NiFloatsExtraDataController;
class NiInterpController;
class NiInterpolator;
class NiSingleInterpController;
#include "nitransformdata_types_NiFloatsExtraDataPoint3Controller.h"
class NiFloatsExtraDataController : public NiExtraDataController
{
  public:
    virtual bool IsEqual(NiObject* object) const;
    // base NiExtraDataController at +0x0, size 64
    int m_iFloatsExtraDataIndex;  // +0x40, 4 bytes
    NiFixedString m_kCtlrID;      // +0x44, 4 bytes
    // const NiRTTI* __cdecl NiFloatsExtraDataController::*()
    // void __cdecl NiFloatsExtraDataController::*(NiStream&)
    // void __cdecl NiFloatsExtraDataController::*(NiStream&)
    // bool __cdecl NiFloatsExtraDataController::*(NiStream&)
    // void __cdecl NiFloatsExtraDataController::*(NiStream&)
    // bool __cdecl NiFloatsExtraDataController::*(NiObject*)
    // NiObject* __cdecl NiFloatsExtraDataController::*()
    // void __cdecl NiFloatsExtraDataController::*(NiTPrimitiveArray<char *>*)
    // NiFloatsExtraDataController
    // void __cdecl NiFloatsExtraDataController::*()
    // void __cdecl NiFloatsExtraDataController::*(NiUpdateData&)
    // int __cdecl NiFloatsExtraDataController::*()
    // void __cdecl NiFloatsExtraDataController::*(int)
    // NiInterpolator* __cdecl NiFloatsExtraDataController::*(unsigned short)
    // void __cdecl NiFloatsExtraDataController::*(NiInterpolator*, unsigned short)
    // NiBlendInterpolator* __cdecl NiFloatsExtraDataController::*(unsigned short, bool, bool, float, unsigned char)
    // const char* __cdecl NiFloatsExtraDataController::*()
    // bool __cdecl NiFloatsExtraDataController::*(NiInterpolator*, unsigned short)
    // NiFloatsExtraDataController& __cdecl NiFloatsExtraDataController::*(const NiFloatsExtraDataController&)
    // void __cdecl NiFloatsExtraDataController::*()
};
FNV_STATIC_ASSERT(sizeof(NiFloatsExtraDataController) == 72);
FNV_STATIC_ASSERT(offsetof(NiFloatsExtraDataController, m_iFloatsExtraDataIndex) == 64);
FNV_STATIC_ASSERT(offsetof(NiFloatsExtraDataController, m_kCtlrID) == 68);
#endif
