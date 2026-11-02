// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BSMATRIX_H
#define FNV_BSMATRIX_H

#include "layout_support.h"
class SwizzledMatrix;
class FourByFourMatrix;
class FourComponentNumericValue;
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
class FourByFourMatrix
{
  public:
    union
    {                                    // overlapping CodeView storage
        FourComponentNumericValue r[4];  // +0x0, 64 bytes
        struct
        {
            float _11;  // +0x0, 4 bytes
            float _12;  // +0x4, 4 bytes
            float _13;  // +0x8, 4 bytes
            float _14;  // +0xC, 4 bytes
            float _21;  // +0x10, 4 bytes
            float _22;  // +0x14, 4 bytes
            float _23;  // +0x18, 4 bytes
            float _24;  // +0x1C, 4 bytes
            float _31;  // +0x20, 4 bytes
            float _32;  // +0x24, 4 bytes
            float _33;  // +0x28, 4 bytes
            float _34;  // +0x2C, 4 bytes
            float _41;  // +0x30, 4 bytes
            float _42;  // +0x34, 4 bytes
            float _43;  // +0x38, 4 bytes
            float _44;  // +0x3C, 4 bytes
        };
        float m[4][4];  // +0x0, 64 bytes
    };
    // FourByFourMatrix
    // operator()
    // FourByFourMatrix& __cdecl FourByFourMatrix::*(const FourByFourMatrix&)
    // FourByFourMatrix& __cdecl FourByFourMatrix::*(const FourByFourMatrix&)
    // FourByFourMatrix __cdecl FourByFourMatrix::*(const FourByFourMatrix&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FourByFourMatrix) == 64);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, r) == 0);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _11) == 0);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _12) == 4);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _13) == 8);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _14) == 12);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _21) == 16);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _22) == 20);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _23) == 24);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _24) == 28);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _31) == 32);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _32) == 36);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _33) == 40);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _34) == 44);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _41) == 48);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _42) == 52);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _43) == 56);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, _44) == 60);
FNV_STATIC_ASSERT(offsetof(FourByFourMatrix, m) == 0);
#pragma pack(push, 4)
class SwizzledMatrix : public FourByFourMatrix
{
  public:
    // base FourByFourMatrix at +0x0, size 64
    // SwizzledMatrix
    // SwizzledMatrix __cdecl SwizzledMatrix::*(const SwizzledMatrix&)
    // SwizzledMatrix& __cdecl SwizzledMatrix::*(const SwizzledMatrix&)
    // SwizzledMatrix& __cdecl SwizzledMatrix::*(const SwizzledMatrix&)
    // SetUnswizzled
    // void __cdecl SwizzledMatrix::*(const SwizzledMatrix&)
    // void __cdecl SwizzledMatrix::*(const SwizzledMatrix&)
    // void __cdecl SwizzledMatrix::*(SwizzledMatrix&)
    // void __cdecl SwizzledMatrix::*(SwizzledMatrix&)
    // void __cdecl SwizzledMatrix::*(SwizzledMatrix&)
    // void __cdecl SwizzledMatrix::*(SwizzledMatrix&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SwizzledMatrix) == 64);
#endif
