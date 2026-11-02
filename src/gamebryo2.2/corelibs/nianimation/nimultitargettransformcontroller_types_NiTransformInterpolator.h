// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITRANSFORMINTERPOLATOR_H
#define FNV_NITRANSFORMINTERPOLATOR_H

#include "layout_support.h"
#include "NiObject.h"
#include "NiPoint3.h"
#include "layout_support.h"
class ThreeByThreeMatrix;
class NiInterpolator;
class NiKeyBasedInterpolator;
class NiQuatTransform;
class NiQuaternion;
class NiTransformData;
class NiTransformInterpolator;
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
class NiKeyBasedInterpolator : public NiInterpolator
{
  public:
    // base NiInterpolator at +0x0, size 12
    // const NiRTTI* __cdecl NiKeyBasedInterpolator::*()
    // void __cdecl NiKeyBasedInterpolator::*(NiStream&)
    // void __cdecl NiKeyBasedInterpolator::*(NiStream&)
    // bool __cdecl NiKeyBasedInterpolator::*(NiStream&)
    // void __cdecl NiKeyBasedInterpolator::*(NiStream&)
    // bool __cdecl NiKeyBasedInterpolator::*(NiObject*)
    // void __cdecl NiKeyBasedInterpolator::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiKeyBasedInterpolator::*()
    // unsigned int __cdecl NiKeyBasedInterpolator::*(unsigned short)
    // void __cdecl NiKeyBasedInterpolator::*(unsigned short)
    // void __cdecl NiKeyBasedInterpolator::*(float&, float&)
    // NiKeyBasedInterpolator
    // NiKeyBasedInterpolator& __cdecl NiKeyBasedInterpolator::*(const NiKeyBasedInterpolator&)
    // void __cdecl NiKeyBasedInterpolator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiKeyBasedInterpolator) == 12);
#pragma pack(push, 4)
class NiQuaternion
{
  public:
    void FromRotationMatrix(const ThreeByThreeMatrix&);
    float m_fVectorX;     // +0x0, 4 bytes
    float m_fVectorY;     // +0x4, 4 bytes
    float m_fVectorZ;     // +0x8, 4 bytes
    float m_fScalarPart;  // +0xC, 4 bytes
    // NiQuaternion
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // float __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*()
    // void __cdecl NiQuaternion::*(float, float, float, float)
    // void __cdecl NiQuaternion::*(float&, float&, float&, float&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // operator-
    // operator*
    // operator*=
    // bool __cdecl NiQuaternion::*(const NiQuaternion&)
    // bool __cdecl NiQuaternion::*(const NiQuaternion&)
    // float __cdecl NiQuaternion::*(const NiQuaternion&, const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&)
    // void __cdecl NiQuaternion::*(float, const NiQuaternion&, const NiQuaternion&)
    // NiQuaternion __cdecl NiQuaternion::*(const NiQuaternion&, const NiQuaternion&, const NiQuaternion&)
    // void __cdecl NiQuaternion::*(float, const NiQuaternion&, const NiQuaternion&, const NiQuaternion&, const NiQuaternion&)
    // void __cdecl NiQuaternion::*(float&, NiPoint3&)
    // void __cdecl NiQuaternion::*(float, const NiPoint3&)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float)
    // void __cdecl NiQuaternion::*(float, float, float)
    // void __cdecl NiQuaternion::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiQuaternion::*(const char*)
    // void __cdecl NiQuaternion::*()
    // void __cdecl NiQuaternion::*()
    // float __cdecl NiQuaternion::*(float)
    // float __cdecl NiQuaternion::*(float, float, float)
    // float __cdecl NiQuaternion::*(float, float)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiQuaternion) == 16);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorX) == 0);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorY) == 4);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fVectorZ) == 8);
FNV_STATIC_ASSERT(offsetof(NiQuaternion, m_fScalarPart) == 12);
#pragma pack(push, 4)
class NiQuatTransform
{
  public:
    NiPoint3 m_kTranslate;   // +0x0, 12 bytes
    NiQuaternion m_kRotate;  // +0xC, 16 bytes
    float m_fScale;          // +0x1C, 4 bytes
    // NiQuatTransform
    // const NiPoint3& __cdecl NiQuatTransform::*()
    // void __cdecl NiQuatTransform::*(const NiPoint3&)
    // const NiQuaternion& __cdecl NiQuatTransform::*()
    // float __cdecl NiQuatTransform::*()
    // void __cdecl NiQuatTransform::*(float)
    // bool __cdecl NiQuatTransform::*()
    // bool __cdecl NiQuatTransform::*()
    // bool __cdecl NiQuatTransform::*()
    // bool __cdecl NiQuatTransform::*()
    // bool __cdecl NiQuatTransform::*(const NiQuatTransform&)
    // bool __cdecl NiQuatTransform::*(const NiQuatTransform&)
    // NiQuatTransform __cdecl NiQuatTransform::*(const NiQuatTransform&)
    // void __cdecl NiQuatTransform::*(NiQuatTransform&)
    // void __cdecl NiQuatTransform::*(NiQuatTransform&)
    // NiQuatTransform __cdecl NiQuatTransform::*(const NiQuatTransform&)
    // void __cdecl NiQuatTransform::*()
    // void __cdecl NiQuatTransform::*(NiStream&)
    // void __cdecl NiQuatTransform::*(NiStream&)
    // void __cdecl NiQuatTransform::*(NiTPrimitiveArray<char *>*)
    // void __cdecl NiQuatTransform::*(bool)
    // void __cdecl NiQuatTransform::*(bool)
    // void __cdecl NiQuatTransform::*(bool)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiQuatTransform) == 32);
FNV_STATIC_ASSERT(offsetof(NiQuatTransform, m_kTranslate) == 0);
FNV_STATIC_ASSERT(offsetof(NiQuatTransform, m_kRotate) == 12);
FNV_STATIC_ASSERT(offsetof(NiQuatTransform, m_fScale) == 28);
#pragma pack(push, 4)
class NiTransformInterpolator : public NiKeyBasedInterpolator
{
  public:
    NiTransformInterpolator(NiQuatTransform);
    // base NiKeyBasedInterpolator at +0x0, size 12
    NiQuatTransform m_kDefaultTransform;           // +0xC, 32 bytes
    NiPointer<NiTransformData> m_spTransformData;  // +0x2C, 4 bytes
    unsigned short m_usLastRotationKeyIndex;       // +0x30, 2 bytes
    unsigned short m_usLastPositionKeyIndex;       // +0x32, 2 bytes
    unsigned short m_usLastScaleKeyIndex;          // +0x34, 2 bytes
    unsigned char layoutPadding36[2];
    NiPoint3 m_kDefaultTranslation;  // +0x38, 12 bytes
    bool m_bPoseValid;               // +0x44, 1 bytes
    unsigned char layoutPadding45[3];
    // const NiRTTI* __cdecl NiTransformInterpolator::*()
    // void __cdecl NiTransformInterpolator::*(NiStream&)
    // void __cdecl NiTransformInterpolator::*(NiStream&)
    // bool __cdecl NiTransformInterpolator::*(NiStream&)
    // void __cdecl NiTransformInterpolator::*(NiStream&)
    // bool __cdecl NiTransformInterpolator::*(NiObject*)
    // NiObject* __cdecl NiTransformInterpolator::*()
    // void __cdecl NiTransformInterpolator::*(NiTPrimitiveArray<char *>*)
    // NiTransformInterpolator
    // bool __cdecl NiTransformInterpolator::*(float, NiObjectNET*, NiQuatTransform&)
    // bool __cdecl NiTransformInterpolator::*()
    // NiTransformData* __cdecl NiTransformInterpolator::*()
    // void __cdecl NiTransformInterpolator::*(NiTransformData*)
    // unsigned int __cdecl NiTransformInterpolator::*()
    // void __cdecl NiTransformInterpolator::*(NiPoint3)
    // unsigned int __cdecl NiTransformInterpolator::*()
    // void __cdecl NiTransformInterpolator::*(NiQuaternion)
    // unsigned int __cdecl NiTransformInterpolator::*()
    // void __cdecl NiTransformInterpolator::*(float)
    // void __cdecl NiTransformInterpolator::*(NiQuatTransform)
    // unsigned short __cdecl NiTransformInterpolator::*()
    // unsigned int __cdecl NiTransformInterpolator::*(unsigned short)
    // unsigned char __cdecl NiTransformInterpolator::*(unsigned short)
    // bool __cdecl NiTransformInterpolator::*(unsigned short)
    // void __cdecl NiTransformInterpolator::*()
    // void __cdecl NiTransformInterpolator::*(float&, float&)
    // void __cdecl NiTransformInterpolator::*(float, float)
    // NiInterpolator* __cdecl NiTransformInterpolator::*(float, float)
    // void __cdecl NiTransformInterpolator::*()
    // NiTransformInterpolator& __cdecl NiTransformInterpolator::*(const NiTransformInterpolator&)
    // void __cdecl NiTransformInterpolator::*()
    // void __cdecl NiTransformInterpolator::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTransformInterpolator) == 72);
FNV_STATIC_ASSERT(offsetof(NiTransformInterpolator, m_kDefaultTransform) == 12);
FNV_STATIC_ASSERT(offsetof(NiTransformInterpolator, m_spTransformData) == 44);
FNV_STATIC_ASSERT(offsetof(NiTransformInterpolator, m_usLastRotationKeyIndex) == 48);
FNV_STATIC_ASSERT(offsetof(NiTransformInterpolator, m_usLastPositionKeyIndex) == 50);
FNV_STATIC_ASSERT(offsetof(NiTransformInterpolator, m_usLastScaleKeyIndex) == 52);
FNV_STATIC_ASSERT(offsetof(NiTransformInterpolator, m_kDefaultTranslation) == 56);
FNV_STATIC_ASSERT(offsetof(NiTransformInterpolator, m_bPoseValid) == 68);
#endif
