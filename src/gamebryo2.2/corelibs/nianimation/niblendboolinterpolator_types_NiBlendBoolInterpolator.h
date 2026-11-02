// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIBLENDBOOLINTERPOLATOR_H
#define FNV_NIBLENDBOOLINTERPOLATOR_H

#include "layout_support.h"
#include "NiObject.h"
class NiBlendBoolInterpolator;
class NiBlendInterpolator;
class NiBlendInterpolator__InterpArrayItem;
class NiInterpolator;
class NiObjectNET;
class NiStream;
#pragma pack(push, 4)
class NiInterpolator : public NiObject
{
  public:
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
    NiBlendInterpolator(bool, float, unsigned char);
    virtual void LoadBinary(NiStream&);
    bool IsEqual(NiObject*);
    void NormalizeWeights();
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
class NiBlendBoolInterpolator : public NiBlendInterpolator
{
  public:
    // base NiBlendInterpolator at +0x0, size 48
    unsigned char m_bBoolValue;  // +0x30, 1 bytes
    unsigned char layoutPadding31[3];
    // const NiRTTI* __cdecl NiBlendBoolInterpolator::*()
    // void __cdecl NiBlendBoolInterpolator::*(NiStream&)
    // void __cdecl NiBlendBoolInterpolator::*(NiStream&)
    // bool __cdecl NiBlendBoolInterpolator::*(NiStream&)
    // void __cdecl NiBlendBoolInterpolator::*(NiStream&)
    // bool __cdecl NiBlendBoolInterpolator::*(NiObject*)
    // NiObject* __cdecl NiBlendBoolInterpolator::*()
    // void __cdecl NiBlendBoolInterpolator::*(NiTPrimitiveArray<char *>*)
    // NiBlendBoolInterpolator
    // bool __cdecl NiBlendBoolInterpolator::*(float, NiObjectNET*, bool&)
    // bool __cdecl NiBlendBoolInterpolator::*()
    // bool __cdecl NiBlendBoolInterpolator::*(NiInterpolator*)
    // bool __cdecl NiBlendBoolInterpolator::*(float, NiObjectNET*, bool&)
    // bool __cdecl NiBlendBoolInterpolator::*(float, NiObjectNET*, bool&)
    // void __cdecl NiBlendBoolInterpolator::*()
    // NiBlendBoolInterpolator& __cdecl NiBlendBoolInterpolator::*(const NiBlendBoolInterpolator&)
    // void __cdecl NiBlendBoolInterpolator::*()
    NiBlendBoolInterpolator(bool, float, unsigned char);
    virtual void LoadBinary(NiStream&);
    virtual bool Update(float, NiObjectNET*, bool&);
    bool UpdateAccumulatedTransform(float, NiObjectNET*, bool&);
    bool UpdateSingleInterpolator(float, NiObjectNET*, bool&);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBlendBoolInterpolator) == 52);
FNV_STATIC_ASSERT(offsetof(NiBlendBoolInterpolator, m_bBoolValue) == 48);
#endif
