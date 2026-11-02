// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIBLENDFLOATINTERPOLATOR_H
#define FNV_NIBLENDFLOATINTERPOLATOR_H

#include "layout_support.h"
#include "NiObject.h"
class NiBlendFloatInterpolator;
class NiBlendInterpolator;
class NiBlendInterpolator__InterpArrayItem;
class NiInterpolator;
#pragma pack(push, 4)
class NiInterpolator : public NiObject
{
  public:
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual bool vfn_09c(float time, NiObjectNET* target, float& value);
    // base NiObject at +0x0, size 8
    float m_fLastTime;  // +0x8, 4 bytes
    // const NiRTTI* __cdecl NiInterpolator::*()
    // void __cdecl NiInterpolator::*(NiStream&)
    // void __cdecl NiInterpolator::*(NiStream&)
    // bool __cdecl NiInterpolator::*(NiStream&)
    // void __cdecl NiInterpolator::*(NiStream&)
    // bool __cdecl NiInterpolator::*(NiObject*)
    // void __cdecl NiInterpolator::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiInterpolator::*()
    // Update
    // void __cdecl NiInterpolator::*()
    // NiInterpolator
    // bool __cdecl NiInterpolator::*(float)
    // NiInterpolator& __cdecl NiInterpolator::*(const NiInterpolator&)
    // void __cdecl NiInterpolator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiInterpolator) == 12);
FNV_STATIC_ASSERT(offsetof(NiInterpolator, m_fLastTime) == 8);
#pragma pack(push, 4)
class NiBlendInterpolator__InterpArrayItem
{
  public:
    NiInterpolator* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    char m_cPriority;
    unsigned char layoutPaddingD[3];
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBlendInterpolator__InterpArrayItem) == 24);
#pragma pack(push, 4)
class NiBlendInterpolator : public NiInterpolator
{
  public:
    NiBlendInterpolator(bool onlyUseHighestWeight, float weightThreshold, unsigned char arraySize);
    virtual void LoadBinary(NiStream& stream);
    void NormalizeWeights();
    __forceinline bool GetBlendUpdateTime(float&, NiBlendInterpolator__InterpArrayItem&);
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
#pragma pack(pop)
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
#pragma pack(push, 4)
class NiBlendFloatInterpolator : public NiBlendInterpolator
{
  public:
    NiBlendFloatInterpolator(bool onlyUseHighestWeight, float weightThreshold, unsigned char arraySize);
    virtual bool UpdateAccumulatedTransform(float time, NiObjectNET* target, float& value);
    virtual bool UpdateSingleInterpolator(float time, NiObjectNET* target, float& value);
    virtual bool Update(float time, NiObjectNET* target, float& value);
    virtual void LoadBinary(NiStream& stream);
    // base NiBlendInterpolator at +0x0, size 48
    float m_fFloatValue;  // +0x30, 4 bytes
    // const NiRTTI* __cdecl NiBlendFloatInterpolator::*()
    // void __cdecl NiBlendFloatInterpolator::*(NiStream&)
    // void __cdecl NiBlendFloatInterpolator::*(NiStream&)
    // bool __cdecl NiBlendFloatInterpolator::*(NiStream&)
    // void __cdecl NiBlendFloatInterpolator::*(NiStream&)
    // bool __cdecl NiBlendFloatInterpolator::*(NiObject*)
    // NiObject* __cdecl NiBlendFloatInterpolator::*()
    // void __cdecl NiBlendFloatInterpolator::*(NiTPrimitiveArray<char *>*)
    // NiBlendFloatInterpolator
    // bool __cdecl NiBlendFloatInterpolator::*(float, NiObjectNET*, float&)
    // bool __cdecl NiBlendFloatInterpolator::*()
    // float __cdecl NiBlendFloatInterpolator::*()
    // bool __cdecl NiBlendFloatInterpolator::*(NiInterpolator*)
    // bool __cdecl NiBlendFloatInterpolator::*(float, NiObjectNET*, float&)
    // bool __cdecl NiBlendFloatInterpolator::*(float, NiObjectNET*, float&)
    // void __cdecl NiBlendFloatInterpolator::*()
    // NiBlendFloatInterpolator& __cdecl NiBlendFloatInterpolator::*(const NiBlendFloatInterpolator&)
    // void __cdecl NiBlendFloatInterpolator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBlendFloatInterpolator) == 52);
FNV_STATIC_ASSERT(offsetof(NiBlendFloatInterpolator, m_fFloatValue) == 48);
#endif
