// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef NIBLENDTRANSFORMINTERPOLATOR_H
#define NIBLENDTRANSFORMINTERPOLATOR_H

#include "niblendtransforminterpolator_layout_support.h"
#include "niblendtransforminterpolator_NiObject.h"
class NiBlendInterpolator;
class NiBlendInterpolator__InterpArrayItem;
class NiBlendTransformInterpolator;
class NiInterpolator;
class NiObjectNET;
class RgbaColor;
class NiPoint3;
class NiQuatTransform;
class NiQuaternion;
class NiBoolInterpolator;
class NiInterpolator : public NiObject
{
  public:
    virtual bool Update(float afTime, NiObjectNET* apTarget, NiQuatTransform& arValue);
    virtual bool UpdateColorA(float afTime, NiObjectNET* apTarget, RgbaColor& arValue);
    virtual bool UpdatePoint3(float afTime, NiObjectNET* apTarget, NiPoint3& arValue);
    virtual bool UpdateQuaternion(float afTime, NiObjectNET* apTarget, NiQuaternion& arValue);
    virtual bool UpdateFloat(float afTime, NiObjectNET* apTarget, float& arValue);
    virtual bool UpdateBool(float afTime, NiObjectNET* apTarget, bool& arValue);
    virtual bool IsBoolValueSupported() const;
    virtual bool IsFloatValueSupported() const;
    virtual bool IsQuaternionValueSupported() const;
    virtual bool IsPoint3ValueSupported() const;
    virtual bool IsColorAValueSupported() const;
    virtual bool IsTransformValueSupported() const;
    virtual void Collapse();
    virtual void GetInterpolatorTimeRange(float& arBeginKeyTime, float& arEndKeyTime) const;
    virtual void SetActiveTimeRange(float afStartTime, float afEndTime);
    virtual NiInterpolator* CloneForTimeRange(float afStartTime, float afEndTime);
    virtual bool IsPoseValue();
    virtual bool IsTimeVarying();
    virtual bool AlwaysUpdate() const;
    virtual NiBoolInterpolator* IsNiBoolInterpolator() const;
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
FNV_STATIC_ASSERT(sizeof(NiInterpolator) == 12);
FNV_STATIC_ASSERT(offsetof(NiInterpolator, m_fLastTime) == 8);
class NiBlendInterpolator : public NiInterpolator
{
  public:
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    void NormalizeWeights();
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
class NiBlendTransformInterpolator : public NiBlendInterpolator
{
  public:
    virtual bool Update(float fTime, NiObjectNET* pkObject, NiQuatTransform& kTransform);

  protected:
    bool UpdateAccumulatedTransform(float fTime, NiObjectNET* pkObject, NiQuatTransform& kTransform);
    bool UpdateSingleInterpolator(float fTime, NiObjectNET* pkObject, NiQuatTransform& kTransform);

  public:
    // base NiBlendInterpolator at +0x0, size 48
    // const NiRTTI* __cdecl NiBlendTransformInterpolator::*()
    // void __cdecl NiBlendTransformInterpolator::*(NiStream&)
    // void __cdecl NiBlendTransformInterpolator::*(NiStream&)
    // bool __cdecl NiBlendTransformInterpolator::*(NiStream&)
    // void __cdecl NiBlendTransformInterpolator::*(NiStream&)
    // bool __cdecl NiBlendTransformInterpolator::*(NiObject*)
    // NiObject* __cdecl NiBlendTransformInterpolator::*()
    // void __cdecl NiBlendTransformInterpolator::*(NiTPrimitiveArray<char *>*)
    // NiBlendTransformInterpolator
    // bool __cdecl NiBlendTransformInterpolator::*(float, NiObjectNET*, NiQuatTransform&)
    // bool __cdecl NiBlendTransformInterpolator::*()
    // void __cdecl NiBlendTransformInterpolator::*(bool)
    // bool __cdecl NiBlendTransformInterpolator::*()
    // bool __cdecl NiBlendTransformInterpolator::*(NiInterpolator*)
    // bool __cdecl NiBlendTransformInterpolator::*(float, NiObjectNET*, NiQuatTransform&)
    // bool __cdecl NiBlendTransformInterpolator::*(float, NiObjectNET*, NiQuatTransform&)
    // void __cdecl NiBlendTransformInterpolator::*()
    // NiBlendTransformInterpolator& __cdecl NiBlendTransformInterpolator::*(const NiBlendTransformInterpolator&)
    // void __cdecl NiBlendTransformInterpolator::*()
};
FNV_STATIC_ASSERT(sizeof(NiBlendTransformInterpolator) == 48);
#endif
