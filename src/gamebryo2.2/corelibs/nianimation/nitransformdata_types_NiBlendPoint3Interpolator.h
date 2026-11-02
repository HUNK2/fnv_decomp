// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITRANSFORMDATA_FNV_NIBLENDPOINT3INTERPOLATOR_H
#define FNV_NITRANSFORMDATA_FNV_NIBLENDPOINT3INTERPOLATOR_H

#include "nitransformdata_layout_support.h"
#include "nitransformdata_NiObject.h"
#include "nitransformdata_NiPoint3.h"
class NiBlendInterpolator;
class NiBlendInterpolator__InterpArrayItem;
class NiBlendPoint3Interpolator;
class NiInterpolator;
#include "nitransformdata_types_NiInterpolator.h"
class NiBlendInterpolator : public NiInterpolator
{
  public:
    // base NiInterpolator at +0x0, size 12
    unsigned char m_uiObjectFlags;         // +0xC, 1 bytes
    unsigned char m_ucArraySize;    // +0xD, 1 bytes
    unsigned char m_ucInterpCount;  // +0xE, 1 bytes
    unsigned char m_ucSingleIdx;    // +0xF, 1 bytes
    char m_cHighPriority;           // +0x10, 1 bytes
    char m_cNextHighPriority;       // +0x11, 1 bytes
    unsigned char layoutPadding12[2];
    NiBlendInterpolator__InterpArrayItem* m_pInterpArray;  // +0x14, 4 bytes
    NiInterpolator* m_pSingleInterpolator;                 // +0x18, 4 bytes
    float m_fWeightThreshold;                              // +0x1C, 4 bytes
    float m_fSingleInterpolatorTime;                       // +0x20, 4 bytes
    float m_fHighSumOfWeights;                             // +0x24, 4 bytes
    float m_fNextHighSumOfWeights;                         // +0x28, 4 bytes
    float m_fTrailingValue;                                // +0x2C, 4 bytes
    // const NiRTTI* __cdecl NiBlendInterpolator::*()
    // void __cdecl NiBlendInterpolator::*(NiStream&)
    // void __cdecl NiBlendInterpolator::*(NiStream&)
    // bool __cdecl NiBlendInterpolator::*(NiStream&)
    // void __cdecl NiBlendInterpolator::*(NiStream&)
    // bool __cdecl NiBlendInterpolator::*(NiObject*)
    // void __cdecl NiBlendInterpolator::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiBlendInterpolator::*(unsigned char, unsigned char, unsigned char)
    // unsigned char __cdecl NiBlendInterpolator::*(unsigned char, unsigned char)
    // void __cdecl NiBlendInterpolator::*(bool, unsigned char)
    // bool __cdecl NiBlendInterpolator::*(unsigned char)
    // void __cdecl NiBlendInterpolator::*()
    // unsigned char __cdecl NiBlendInterpolator::*()
    // unsigned char __cdecl NiBlendInterpolator::*()
    // void __cdecl NiBlendInterpolator::*(unsigned char)
    // NiInterpolator* __cdecl NiBlendInterpolator::*(unsigned char)
    // void __cdecl NiBlendInterpolator::*(NiInterpolator*, unsigned char)
    // float __cdecl NiBlendInterpolator::*(unsigned char)
    // void __cdecl NiBlendInterpolator::*(float, unsigned char)
    // char __cdecl NiBlendInterpolator::*(unsigned char)
    // void __cdecl NiBlendInterpolator::*(char, unsigned char)
    // int __cdecl NiBlendInterpolator::*()
    // float __cdecl NiBlendInterpolator::*(unsigned char)
    // void __cdecl NiBlendInterpolator::*(float, float, float, unsigned char)
    // float __cdecl NiBlendInterpolator::*(unsigned char)
    // void __cdecl NiBlendInterpolator::*(float, unsigned char)
    // bool __cdecl NiBlendInterpolator::*()
    // void __cdecl NiBlendInterpolator::*(bool)
    // float __cdecl NiBlendInterpolator::*()
    // void __cdecl NiBlendInterpolator::*(float)
    // void __cdecl NiBlendInterpolator::*()
    // bool __cdecl NiBlendInterpolator::*()
    // void __cdecl NiBlendInterpolator::*(bool)
    // void __cdecl NiBlendInterpolator::*()
    // float __cdecl NiBlendInterpolator::*(unsigned char)
    // unsigned char __cdecl NiBlendInterpolator::*()
    // void __cdecl NiBlendInterpolator::*(float, float)
    // NiBlendInterpolator
    // void __cdecl NiBlendInterpolator::*()
    // void __cdecl NiBlendInterpolator::*()
    // bool __cdecl NiBlendInterpolator::*()
    // void __cdecl NiBlendInterpolator::*(bool)
    // bool __cdecl NiBlendInterpolator::*(float&)
    // bool __cdecl NiBlendInterpolator::*(float&, NiBlendInterpolator::InterpArrayItem&)
    // NiBlendInterpolator& __cdecl NiBlendInterpolator::*(const NiBlendInterpolator&)
    // void __cdecl NiBlendInterpolator::*()
};
FNV_STATIC_ASSERT(sizeof(NiBlendInterpolator) == 48);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_uiObjectFlags) == 12);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_ucArraySize) == 13);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_ucInterpCount) == 14);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_ucSingleIdx) == 15);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_cHighPriority) == 16);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_cNextHighPriority) == 17);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_pInterpArray) == 20);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_pSingleInterpolator) == 24);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_fWeightThreshold) == 28);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_fSingleInterpolatorTime) == 32);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_fHighSumOfWeights) == 36);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_fNextHighSumOfWeights) == 40);
FNV_STATIC_ASSERT(offsetof(NiBlendInterpolator, m_fTrailingValue) == 44);
class NiBlendPoint3Interpolator : public NiBlendInterpolator
{
  public:
    NiBlendPoint3Interpolator(bool managerControlled, float weightThreshold, unsigned char arraySize);
    // base NiBlendInterpolator at +0x0, size 48
    NiPoint3 m_kPoint3Value;  // +0x30, 12 bytes
    bool m_bValueValid;       // +0x3C, 1 bytes
    unsigned char layoutPadding3D[3];
    // const NiRTTI* __cdecl NiBlendPoint3Interpolator::*()
    // void __cdecl NiBlendPoint3Interpolator::*(NiStream&)
    // void __cdecl NiBlendPoint3Interpolator::*(NiStream&)
    // bool __cdecl NiBlendPoint3Interpolator::*(NiStream&)
    // void __cdecl NiBlendPoint3Interpolator::*(NiStream&)
    // bool __cdecl NiBlendPoint3Interpolator::*(NiObject*)
    // NiObject* __cdecl NiBlendPoint3Interpolator::*()
    // void __cdecl NiBlendPoint3Interpolator::*(NiTPrimitiveArray<char *>*)
    // NiBlendPoint3Interpolator
    // bool __cdecl NiBlendPoint3Interpolator::*(float, NiObjectNET*, NiPoint3&)
    // bool __cdecl NiBlendPoint3Interpolator::*()
    // bool __cdecl NiBlendPoint3Interpolator::*(NiInterpolator*)
    // bool __cdecl NiBlendPoint3Interpolator::*(float, NiObjectNET*, NiPoint3&)
    // bool __cdecl NiBlendPoint3Interpolator::*(float, NiObjectNET*, NiPoint3&)
    // void __cdecl NiBlendPoint3Interpolator::*()
    // NiBlendPoint3Interpolator& __cdecl NiBlendPoint3Interpolator::*(const NiBlendPoint3Interpolator&)
    // void __cdecl NiBlendPoint3Interpolator::*()
};
FNV_STATIC_ASSERT(sizeof(NiBlendPoint3Interpolator) == 64);
FNV_STATIC_ASSERT(offsetof(NiBlendPoint3Interpolator, m_kPoint3Value) == 48);
FNV_STATIC_ASSERT(offsetof(NiBlendPoint3Interpolator, m_bValueValid) == 60);
#endif
