// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NITEXTURETRANSFORM_H
#define FNV_NITEXTURETRANSFORM_H

#include "layout_support.h"
class ThreeByThreeMatrix;
class NiPoint2;
class NiPoint4;
class TextureMapTransform;
class FourComponentNumericValue;
enum NiTextureTransform__TransformMethod
{
    NiTextureTransform__TransformMethod_MAYA_DEPRECATED_TRANSFORM = 0,
    NiTextureTransform__TransformMethod_MAX_TRANSFORM = 1,
    NiTextureTransform__TransformMethod_MAYA_TRANSFORM = 2
};
#pragma pack(push, 4)
class NiPoint2
{
  public:
    float x;  // +0x0, 4 bytes
    float y;  // +0x4, 4 bytes
    // NiPoint2
    // operator[]
    // bool __cdecl NiPoint2::*(const NiPoint2&)
    // bool __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2 __cdecl NiPoint2::*(const NiPoint2&)
    // operator-
    // operator*
    // NiPoint2 __cdecl NiPoint2::*(float)
    // NiPoint2 __cdecl NiPoint2::*(const NiPoint2&, const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(const NiPoint2&)
    // NiPoint2& __cdecl NiPoint2::*(float)
    // NiPoint2& __cdecl NiPoint2::*(float)
    // float __cdecl NiPoint2::*()
    // float __cdecl NiPoint2::*()
    // float __cdecl NiPoint2::*(const NiPoint2&)
    // float __cdecl NiPoint2::*()
    // LoadBinary
    // SaveBinary
    // char* __cdecl NiPoint2::*(const char*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint2) == 8);
FNV_STATIC_ASSERT(offsetof(NiPoint2, x) == 0);
FNV_STATIC_ASSERT(offsetof(NiPoint2, y) == 4);
#pragma pack(push, 4)
class FourComponentNumericValue
{
  public:
    union
    {                                     // overlapping CodeView storage
        float m_afComponents[4];          // +0x0, 16 bytes
        unsigned int m_auiComponents[4];  // +0x0, 16 bytes
        struct
        {
            float x;  // +0x0, 4 bytes
            float y;  // +0x4, 4 bytes
            float z;  // +0x8, 4 bytes
            float w;  // +0xC, 4 bytes
        };
        float v[4];         // +0x0, 16 bytes
        unsigned int u[4];  // +0x0, 16 bytes
    };
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FourComponentNumericValue) == 16);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, m_afComponents) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, m_auiComponents) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, x) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, y) == 4);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, z) == 8);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, w) == 12);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, v) == 0);
FNV_STATIC_ASSERT(offsetof(FourComponentNumericValue, u) == 0);
#pragma pack(push, 4)
class NiPoint4
{
  public:
    union
    {                                             // overlapping CodeView storage
        FourComponentNumericValue m_kComponents;  // +0x0, 16 bytes
        float m_afExtents[4];                     // +0x0, 16 bytes
    };
    // NiPoint4
    // bool __cdecl NiPoint4::*(const NiPoint4&)
    // void __cdecl NiPoint4::*()
    // Set
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(float)
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // float __cdecl NiPoint4::*()
    // NiPoint4 __cdecl NiPoint4::*(const NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(const NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(float)
    // NiPoint4 __cdecl NiPoint4::*(NiPoint4&)
    // NiPoint4 __cdecl NiPoint4::*(float)
    // void __cdecl NiPoint4::*(NiPoint4*, unsigned int, NiPoint3*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint4) == 16);
FNV_STATIC_ASSERT(offsetof(NiPoint4, m_kComponents) == 0);
FNV_STATIC_ASSERT(offsetof(NiPoint4, m_afExtents) == 0);
#pragma pack(push, 4)
class ThreeByThreeMatrix
{
  public:
    NiPoint4 m_afEntries[3];  // +0x0, 48 bytes
    // GetRow
    // SetRow
    // GetCol
    // SetCol
    // operator*
    // Inverse
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ThreeByThreeMatrix) == 48);
FNV_STATIC_ASSERT(offsetof(ThreeByThreeMatrix, m_afEntries) == 0);
#pragma pack(push, 4)
class TextureMapTransform
{
  public:
    NiPoint2 m_kTranslate;     // +0x0, 8 bytes
    float m_fRotation;         // +0x8, 4 bytes
    NiPoint2 m_kScaleFactors;  // +0xC, 8 bytes
    NiPoint2 m_kCenter;        // +0x14, 8 bytes
    bool m_bTransform;         // +0x1C, 1 bytes
    unsigned char layoutPadding1D[3];
    ThreeByThreeMatrix m_kTransformMatrix;                            // +0x20, 48 bytes
    NiTextureTransform__TransformMethod m_eTransformMethod;  // +0x50, 4 bytes
    unsigned char layoutPadding54[12];
    TextureMapTransform(const NiPoint2& translate, const NiPoint2& rotate, const NiPoint2& scale, const NiPoint2& center,
                       NiTextureTransform__TransformMethod method) throw();
    void UpdateFromPair(const NiPoint2& value);
    void SetValue(float value);
    void FUN_00a462b0(const NiPoint2& value);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TextureMapTransform) == 96);
FNV_STATIC_ASSERT(offsetof(TextureMapTransform, m_kTranslate) == 0);
FNV_STATIC_ASSERT(offsetof(TextureMapTransform, m_fRotation) == 8);
FNV_STATIC_ASSERT(offsetof(TextureMapTransform, m_kScaleFactors) == 12);
FNV_STATIC_ASSERT(offsetof(TextureMapTransform, m_kCenter) == 20);
FNV_STATIC_ASSERT(offsetof(TextureMapTransform, m_bTransform) == 28);
FNV_STATIC_ASSERT(offsetof(TextureMapTransform, m_kTransformMatrix) == 32);
FNV_STATIC_ASSERT(offsetof(TextureMapTransform, m_eTransformMethod) == 80);
#endif
