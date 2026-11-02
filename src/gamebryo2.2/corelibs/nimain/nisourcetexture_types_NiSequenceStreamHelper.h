// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NISEQUENCESTREAMHELPER_H
#define FNV_NISEQUENCESTREAMHELPER_H

#include "layout_support.h"
#include "NiObjectNET.h"
class NiSequenceStreamHelper;
#pragma pack(push, 4)
class NiSequenceStreamHelper : public NiObjectNET
{
  public:
    // base NiObjectNET at +0x0, size 24
    void LinkObject(NiStream&);
    // const NiRTTI* __cdecl NiSequenceStreamHelper::*()
    // void __cdecl NiSequenceStreamHelper::*(NiStream&)
    // void __cdecl NiSequenceStreamHelper::*(NiStream&)
    // bool __cdecl NiSequenceStreamHelper::*(NiStream&)
    // void __cdecl NiSequenceStreamHelper::*(NiStream&)
    // bool __cdecl NiSequenceStreamHelper::*(NiObject*)
    // NiObject* __cdecl NiSequenceStreamHelper::*()
    // NiSequenceStreamHelper
    // void __cdecl NiSequenceStreamHelper::*()
    // NiSequenceStreamHelper& __cdecl NiSequenceStreamHelper::*(const NiSequenceStreamHelper&)
    // void __cdecl NiSequenceStreamHelper::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiSequenceStreamHelper) == 24);
#endif
